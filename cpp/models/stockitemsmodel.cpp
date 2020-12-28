#include "stockitemsmodel.h"

StockItemsModel::StockItemsModel(QObject *parent) : QAbstractListModel(parent)
{
    QFile file(":/json/sale_item.json");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QString jsonString = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
    m_itemDetails = doc.object();

    m_dateTime = new DateTime();
}

int StockItemsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return m_stockItems.size();
}

QVariant StockItemsModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() > m_stockItems.count())
        return QVariant();

    StockItems * stock = m_stockItems[index.row()];
    if(role == BarcodeRole)
        return stock->barCode();
    if(role == ItemNameRole)
        return stock->itemName();
    if(role == ItemUnitRole)
        return stock->itemUnit();
    if(role == ItemBpRole)
        return stock->itemBp();
    if(role == ItemSpRole)
        return stock->itemSp();
    if(role == ItemQtyRole)
        return stock->itemQty();
    if(role == ItemCompanyRole)
        return stock->itemCompany();
    if(role == ItemLastUpdateRole)
        return stock->lastUpdate();
    if(role == ItemCategoryRole)
        return stock->itemCategory();

    else return QVariant();
}

bool StockItemsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    StockItems * stock = m_stockItems[index.row()];

    bool changed = false;

    switch (role)
    {
    case BarcodeRole:
    {
        if( stock->barCode() != value.toString())
        {
            stock->setBarCode(value.toString());
            changed = true;
        }

        break;
    }

    case ItemNameRole:
    {
        if( stock->itemName() != value.toString())
        {
            stock->setItemName(value.toString());
            changed = true;
        }

        break;
    }

    case ItemUnitRole:
    {
        if( stock->itemUnit() != value.toString())
        {
            stock->setItemUnit(value.toString());
            changed = true;
        }

        break;
    }

    case ItemBpRole:
    {
        if( static_cast<int>(stock->itemBp()) != value.toString().toInt())
        {
            stock->setItemBp(value.toString().toFloat());
            changed = true;
        }

        break;
    }

    case ItemSpRole:
    {
        if( static_cast<int>(stock->itemSp()) != value.toString().toInt())
        {
            stock->setItemSp(value.toString().toFloat());
            changed = true;
        }

        break;
    }

    case ItemQtyRole:
    {
        if( stock->itemQty() != value.toString().toInt())
        {
            stock->setItemQty(value.toString().toInt());
            changed = true;
        }

        break;
    }

    case ItemCompanyRole:
    {
        if( stock->itemCompany() != value.toString())
        {
            stock->setItemCompany(value.toString());
            changed = true;
        }

        break;
    }

    case ItemLastUpdateRole:
    {
        if( stock->lastUpdate() != value.toString())
        {
            stock->setLastUpdate(value.toString());
            changed = true;
        }

        break;
    }

    case ItemCategoryRole:
    {
        if( stock->itemCategory() != value.toString())
        {
            stock->setItemCategory(value.toString());
            changed = true;
        }

        break;
    }

    }

    if(changed)
    {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }

    return false;
}

Qt::ItemFlags StockItemsModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> StockItemsModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[BarcodeRole] = "barcode";
    roles[ItemNameRole] = "name";
    roles[ItemUnitRole] = "unit";
    roles[ItemBpRole] = "_bp";
    roles[ItemSpRole] = "_sp";
    roles[ItemQtyRole] = "quantity";
    roles[ItemCompanyRole] = "_company";
    roles[ItemLastUpdateRole] = "date";
    roles[ItemCategoryRole] = "category";

    return roles;
}

void StockItemsModel::addNewItem(const QVariant &barcode, const QVariant &name, const QVariant &unit, const QVariant &bp, const QVariant &sp, const QVariant &qty, const QVariant &company, const QVariant &date, const QVariant &category)
{
    QSqlDatabase m_db = QSqlDatabase::database();
    Q_UNUSED(date)

    QString dateNow = m_dateTime->getTimestamp("now").at(0);

    if(m_db.isOpen())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO \"product\"(barcode,product_name,product_unit,product_bp,product_sp,product_company,type_id) VALUES (:barcode,:product_name,:product_unit,:product_bp,:product_sp,:product_company,:type_id)");
        query.bindValue(":barcode", barcode.toString());
        query.bindValue(":product_name", name.toString());
        query.bindValue(":product_unit", unit.toString());
        query.bindValue(":product_bp", bp.toString().toFloat());
        query.bindValue(":product_sp", sp.toString().toFloat());
        query.bindValue(":product_company", company.toString());
        query.bindValue(":type_id", "35702"); // category.toString());

        QSqlQuery stock_query;
        stock_query.prepare("INSERT INTO \"stock\"(barcode,stock_qty,last_update) VALUES (:barcode,:stock_qty,:last_update)");
        stock_query.bindValue(":barcode", barcode.toString());
        stock_query.bindValue(":stock_qty", qty.toString().toInt());
        stock_query.bindValue(":last_update", dateNow);

        if(query.exec() && stock_query.exec())
        {
            m_db.commit();
            // qDebug() << ">> New item Added";

            addNewItem(new StockItems(barcode.toString(), name.toString(), unit.toString(), bp.toString().toFloat(), sp.toString().toFloat(), company.toString(), qty.toInt(), dateNow, category.toString()));

            emit itemAddingChanged(true);

        }

        else
        {
            m_db.rollback();

            emit itemAddingChanged(false);

            qDebug() << "Error executing SQL: " << m_db.lastError().text() << " :: " << query.lastError().text() << " :: " << stock_query.lastError().text();
        }
    }
}

void StockItemsModel::updateItem(const QVariant &barcode, const QVariant &name, const QVariant &unit, const QVariant &bp, const QVariant &sp, const QVariant &company, const QVariant &category, const QVariant &orig_barcode, const QVariant &index)
{
    QSqlDatabase m_db = QSqlDatabase::database();

    qDebug() << "Category: " << category;

    if(m_db.isOpen())
    {
        QSqlQuery query;
        query.prepare("UPDATE \"product\" SET barcode=:barcode,product_name=:product_name,product_unit=:product_unit,product_bp=:product_bp,product_sp=:product_sp,type_id=:type_id,product_company=:product_company WHERE barcode=:orig_barcode");
        query.bindValue(":barcode", barcode.toString());
        query.bindValue(":product_name", name.toString());
        query.bindValue(":product_unit", unit.toString());
        query.bindValue(":product_bp", bp.toString().toFloat());
        query.bindValue(":product_sp", sp.toString().toFloat());
        query.bindValue(":type_id", "35702"); // category.toString().toInt());
        query.bindValue(":product_company", company.toString());
        query.bindValue(":orig_barcode", orig_barcode.toString());

        QSqlQuery stock_query;
        stock_query.prepare("UPDATE \"stock\" SET barcode=:barcode WHERE barcode=:orig_barcode");
        stock_query.bindValue(":barcode", barcode.toString());
        stock_query.bindValue(":orig_barcode", orig_barcode.toString());

        if(query.exec() && stock_query.exec())
        {
            // Reflect changes on the model
            setData(this->index(index.toString().toInt()), barcode, BarcodeRole);
            setData(this->index(index.toString().toInt()), name, ItemNameRole);
            setData(this->index(index.toString().toInt()), unit, ItemUnitRole);
            setData(this->index(index.toString().toInt()), bp, ItemBpRole);
            setData(this->index(index.toString().toInt()), sp, ItemSpRole);
            setData(this->index(index.toString().toInt()), company, ItemCompanyRole);
            setData(this->index(index.toString().toInt()), category, ItemCategoryRole);


            emit itemUpdatedChanged(true);
        }

        else
        {
            m_db.rollback();

            qDebug() << "Error executing SQL: " << query.lastError().text() << " :: " << stock_query.lastError().text();

            emit itemUpdatedChanged(false);
        }
    }
}

void StockItemsModel::updateStock(const QVariant &barcode, const QVariant &qty, const QVariant &date, const QVariant &index)
{
    QSqlDatabase m_db = QSqlDatabase::database();
    QString dateToday = date.toString();

    if(m_db.isOpen())
    {
        QSqlQuery stock_query;
        stock_query.prepare("UPDATE \"stock\" SET stock_qty=:stock_qty,last_update=:last_update WHERE barcode=:barcode");
        stock_query.bindValue(":barcode", barcode.toString());
        stock_query.bindValue(":stock_qty", qty.toString().toInt());
        stock_query.bindValue(":last_update", dateToday);

        if(stock_query.exec())
        {
            // Reflect changes on the model
            setData(this->index(index.toString().toInt()), qty, ItemQtyRole);
            setData(this->index(index.toString().toInt()), QVariant::fromValue(dateToday), ItemLastUpdateRole);

            emit itemStockChanged(true);
        }

        else
        {
            m_db.rollback();

            qDebug() << "Error executing SQL: " << m_db.lastError().text();

            emit itemStockChanged(false);
        }
    }
}

void StockItemsModel::updateStockHistory(const QString &barcode, const int &stock_qty_before, const int &stock_qty_added, const QString &date_updated, const QString &who_updated, const bool &is_adding)
{
    QSqlDatabase db = QSqlDatabase::database();

    if(db.isOpen())
    {
        QSqlQuery query;
        QString a,b;
        a = QString::number(stock_qty_before);
        b = QString::number(stock_qty_added);

        QString sql = "INSERT INTO stock_history(barcode, stock_qty_before, stock_qty_added, date_updated, who_updated, is_adding) VALUES (" +barcode+ ", "+a+", "+b+", '"+date_updated+"', '"+who_updated+"', '"+(is_adding? "True":"False")+"');";

        qDebug() << sql;

        if(query.exec(sql))
        {
            qDebug() << "Stock data added!";
        }

        else
        {
            qDebug() << "Error adding stock record: " << query.lastError().text();
        }
    }
}

void StockItemsModel::updateStockOnSale(const QVariant &bcode, const int &qty)
{
    QSqlDatabase m_db = QSqlDatabase::database();

    int ind = getItemIndex(bcode);

    if(ind != -1)
    {
        setData(this->index(ind), qty, ItemQtyRole);

        emit itemStockAfterSaleChanged(true);
    }

    else
        qDebug() << " [ERROR] Couldn't find index of item barcode: " <<bcode.toString();

}

bool StockItemsModel::addNewItem(StockItems *stockItem)
{
    const int index = m_stockItems.size();

    beginInsertRows(QModelIndex(), index, index);
    m_stockItems.append(stockItem);
    endInsertRows();

    return true;
}

int StockItemsModel::getItemIndex(const QVariant &bcode)
{
    if(bcode == "")
        return -1;

    for(int i=0; i<m_stockItems.size(); i++)
    {
        QVariant _bcode = data(this->index(i), BarcodeRole);

        if(_bcode == bcode)
        {
            return i;
        }
    }

    return -1;
}

void StockItemsModel::initializeStockFromDb()
{
    qInfo() << ">> Fetching Stock Item Data from Database";

    QSqlDatabase m_db = QSqlDatabase::database();

    getItemCategories();

    if(m_db.isOpen())
    {
        QSqlQuery query;
        QString sql = "SELECT product.barcode,product_name,product_unit,product_bp,product_sp,product_company,type_id,stock_qty,last_update FROM \"product\" INNER JOIN \"stock\" ON product.barcode=stock.barcode ORDER BY product_name ASC";

        if(query.exec(sql))
        {
            while(query.next())
            {
                QString barcode = query.value(0).toString();
                QString name = query.value(1).toString();
                QString unit = query.value(2).toString();
                float bp = query.value(3).toFloat();
                float sp = query.value(4).toFloat();
                QString company = query.value(5).toString();
                QString category = query.value(6).toString();
                int qty = query.value(7).toInt();
                QString item = query.value(8).toString();

                addNewItem(new StockItems(barcode, name, unit, bp, sp, company, qty, item, category));
            }
        }

        else
        {
            qDebug() << "Error executing SQL: " << m_db.lastError().text() << " :: " << query.lastError().text();
        }
    }
}

int StockItemsModel::getItemStock(const QVariant &barcode)
{
    for(int i=0; i<m_stockItems.size(); i++)
    {
        QVariant bcode = data(this->index(i), BarcodeRole);

        if(bcode == barcode)
        {
            int qty = data(this->index(i), ItemQtyRole).toString().toInt();
            return qty;
        }
    }

    qDebug() << ">> This item was not found";

    return -1;
}

QJsonObject StockItemsModel::getItemData(const QString &barcode)
{
    const int index = getItemIndex(barcode);

    // qDebug() << "Index: " << index;

    if(index != -1)
    {
        int qty = data(this->index(index), ItemQtyRole).toString().toInt();

        if(qty > 0)
        {
            QString name = data(this->index(index), ItemNameRole).toString();
            QString unit = data(this->index(index), ItemUnitRole).toString();
            float bp = data(this->index(index), ItemBpRole).toString().toInt();
            float sp = data(this->index(index), ItemSpRole).toString().toInt();

            m_itemDetails["sellBarcode"] = barcode;
            m_itemDetails["sellItemName"] = name;
            m_itemDetails["sellItemUnit"] = unit;
            m_itemDetails["buyingPrice"] = bp;
            m_itemDetails["sellingPrice"] = sp;
            m_itemDetails["sellQty"] = qty;

            emit itemDataChanged(true, m_itemDetails);

            QJsonDocument doc(m_itemDetails);

            return m_itemDetails;
        }

        else
        {
            // qDebug() << ">> Low Stock on item .. ";

            emit itemStockWarningChanged();

            return m_itemDetails;
        }

    }

    else
        emit itemDataChanged(false, m_itemDetails);

    return m_itemDetails;
}

void StockItemsModel::getItemCategories()
{
    QSqlDatabase m_db = QSqlDatabase::database();

    QList<QString> l_id, l_name;
    m_categoryId.clear();
    m_categoryNames.clear();

    if(m_db.isOpen())
    {
        QString sql = "SELECT type_id,type_name FROM product_type;";
        QSqlQuery query;

        if(query.exec("SELECT type_id,type_name FROM product_type;"))
        {
            while(query.next())
            {
                QString id = query.value(0).toString();
                QString name = query.value(1).toString();

                l_id.append(id);
                l_name.append(name);
            }

            setCategoryId(l_id);
            setCategoryNames(l_name);

            emit categoryIdChanged(l_id);
            emit categoryNamesChanged(l_name);

        }

        else
        {
            qDebug() << "Error fetching item category :: [" <<query.executedQuery() << "]" << query.lastError().text();
        }
    }
}

void StockItemsModel::addItemCategory(const QString &category)
{
    QSqlDatabase m_db = QSqlDatabase::database();

    QString id = QString::number(QDateTime::currentSecsSinceEpoch());

    if(m_db.isOpen())
    {
        QString sql = "INSERT INTO product_type(type_id,type_name) VALUES ('" + id + "', '" + category + "');";
        QSqlQuery query;
        if(query.exec(sql))
        {
            qDebug() << "Item Category added!";
        }

        else
        {
            qDebug() << "Error adding item category :[" << query.executedQuery() << "]: " << query.lastError().text();
        }
    }
}

QList<QString> StockItemsModel::getCategryList()
{
    qDebug() << "Model Size: " << m_categoryNames.size();
    return m_categoryNames;
}

QString StockItemsModel::getCurrentTime()
{
    return m_dateTime->getTimestamp("now").at(0);
}

void StockItemsModel::removeItem(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_stockItems.removeAt(index);
    endRemoveRows();
}

QList<QString> StockItemsModel::categoryNames() const
{
    return m_categoryNames;
}

QList<QString> StockItemsModel::categoryId() const
{
    return m_categoryId;
}

void StockItemsModel::setCategoryNames(QList<QString> categoryNames)
{
    if (m_categoryNames == categoryNames)
        return;

    m_categoryNames = categoryNames;
    emit categoryNamesChanged(m_categoryNames);
}

void StockItemsModel::setCategoryId(QList<QString> categoryId)
{
    if (m_categoryId == categoryId)
        return;

    m_categoryId = categoryId;
    emit categoryIdChanged(m_categoryId);
}
