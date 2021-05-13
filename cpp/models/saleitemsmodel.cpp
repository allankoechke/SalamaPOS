#include "saleitemsmodel.h"

saleItemsModel::saleItemsModel(QObject *parent) : QAbstractListModel(parent)
{
    m_dateTime = new DateTime();
}

int saleItemsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return m_saleItems.size();
}

QVariant saleItemsModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() > m_saleItems.count())
        return QVariant();

    SaleItems * sales = m_saleItems.at(index.row());

    if(role == SaleBarcodeRole)
        return sales->saleBarcode();

    if(role == SaleItemNameRole)
        return sales->saleItemName();

    if(role == SaleUnitRole)
        return sales->saleUnit();

    if(role == SaleIdRole)
        return sales->saleId();

    if(role == SaleBpRole)
        return sales->saleBp();

    if(role == SaleSpRole)
        return sales->saleSp();

    if(role == SaleQtyRole)
        return sales->saleQty();

    if(role == CostCashRole)
        return sales->costCash();

    if(role == CostMpesaRole)
        return sales->costMpesa();

    if(role == CostChequeRole)
        return sales->costCheque();

    if(role == CostCreditRole)
        return sales->costCredit();

    if(role == SaleDateRole)
        return sales->saleDate();


    else return QVariant();
}

bool saleItemsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    SaleItems * sales = m_saleItems.at(index.row());
    bool changed = false;

    switch (role)
    {
    case SaleBarcodeRole:
    {
        if( sales->saleBarcode() != value.toString())
        {
            sales->setSaleBarcode(value.toString());
            changed = true;
        }

        break;
    }

    case SaleItemNameRole:
    {
        if( sales->saleItemName() != value.toString())
        {
            sales->setSaleItemName(value.toString());
            changed = true;
        }

        break;
    }

    case SaleUnitRole:
    {
        if( sales->saleUnit() != value.toString())
        {
            sales->setSaleUnit(value.toString());
            changed = true;
        }

        break;
    }

    case SaleIdRole:
    {
        if( sales->saleId() != value.toString())
        {
            sales->setSaleId(value.toString());
            changed = true;
        }

        break;
    }

    case SaleDateRole:
    {
        if( sales->saleDate() != value.toString())
        {
            sales->setSaleDate(value.toString());
            changed = true;
        }

        break;
    }

    case SaleBpRole:
    {
        if( sales->saleBp() != value.toString().toInt())
        {
            sales->setSaleBp(value.toString().toInt());
            changed = true;
        }

        break;
    }

    case SaleSpRole:
    {
        if( sales->saleSp() != value.toString().toInt())
        {
            sales->setSaleSp(value.toString().toInt());
            changed = true;
        }

        break;
    }

    case SaleQtyRole:
    {
        if( sales->saleQty() != value.toString().toInt())
        {
            sales->setSaleQty(value.toString().toInt());
            changed = true;
        }

        break;
    }

    case CostCashRole:
    {
        if( sales->costCash() != value.toString().toInt())
        {
            sales->setCostCash(value.toString().toInt());
            changed = true;
        }

        break;
    }

    case CostMpesaRole:
    {
        if( sales->costMpesa() != value.toString().toInt())
        {
            sales->setCostMpesa(value.toString().toInt());
            changed = true;
        }

        break;
    }

    case CostChequeRole:
    {
        if( sales->costCheque() != value.toString().toInt())
        {
            sales->setCostCheque(value.toString().toInt());
            changed = true;
        }

        break;
    }

    case CostCreditRole:
    {
        if( sales->costCredit() != value.toString().toInt())
        {
            sales->setCostCredit(value.toString().toInt());
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

Qt::ItemFlags saleItemsModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> saleItemsModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[SaleBarcodeRole] = "sale_barcode";
    roles[SaleItemNameRole] = "sale_name";
    roles[SaleUnitRole] = "sale_unit";
    roles[SaleIdRole] = "sale_id";
    roles[SaleBpRole] = "sale_bp";
    roles[SaleSpRole] = "sale_sp";
    roles[SaleQtyRole] = "sale_qty";
    roles[CostCashRole] = "sale_cash";
    roles[CostMpesaRole] = "sale_mpesa";
    roles[CostChequeRole] = "sale_cheque";
    roles[CostCreditRole] = "sale_credit";
    roles[SaleDateRole] = "sale_date";

    return roles;
}

void saleItemsModel::addSaleItem(const QVariant &barcode, const int &qty, const QVariant &uname, const QVariant &saleid, const QVariant &dt)
{
    emit logDataChanged("INFO", "Starting saleItemsModel::addSaleItem()");

    Q_UNUSED(dt)

    QString dateToday = m_dateTime->getTimestamp("now").at(0);
    QSqlDatabase m_db = QSqlDatabase::database();

    if(m_db.isOpen())
    {
        QSqlQuery fetchItem;
        fetchItem.prepare("SELECT product.product_unit,product_bp,product_sp,stock_qty FROM product INNER JOIN stock ON product.barcode = stock.barcode WHERE product.barcode = :bCode");
        fetchItem.bindValue(":bCode", barcode.toString());

        if(fetchItem.exec())
        {
            while (fetchItem.next()) {
                // QString unit = fetchItem.value(0).toString();
                float bp = fetchItem.value(1).toFloat();
                float sp = fetchItem.value(2).toFloat();
                int currentStock = fetchItem.value(3).toInt();

                if(currentStock >= qty)
                {
                    QSqlQuery writeSales;
                    //writeSales.prepare("INSERT INTO sales(sales_id,barcode,sales_date,product_bp,product_sp,sale_qty,username) VALUES(:id"+saleid.toString()+",:barcode,:date,:bp,:sp,:qty,:uname)");
                    writeSales.prepare("INSERT INTO sales(sales_id,barcode,sales_date,product_bp,product_sp,sale_qty,username) VALUES('"+saleid.toString()+"','" +barcode.toString()+ "','"+ dateToday +"',:bp,:sp,:qty,'"+uname.toString()+"')");
                    writeSales.bindValue(":bp", QString::number(bp));
                    writeSales.bindValue(":sp", QString::number(sp));
                    writeSales.bindValue(":qty", QString::number(qty));

                    if(writeSales.exec())
                    {
                        // qDebug() << "Success writing Sale to db";

                        int c_qty = currentStock - qty;

                        QSqlQuery stock_query;
                        stock_query.prepare("UPDATE \"stock\" SET stock_qty=:stock_qty WHERE barcode=:barcode");
                        stock_query.bindValue(":barcode", barcode.toString());
                        stock_query.bindValue(":stock_qty", c_qty);

                        if(stock_query.exec())
                        {
                            // TODO: check on this
                            emit updateStockChanged(barcode.toString(), c_qty);

                            emit updateSalesModelChanged(barcode.toString(), qty);

                            m_db.commit();
                        }

                        else
                        {
                            m_db.rollback();

                            emit logDataChanged("CRITICAL", "Updating Stock after sale -> " + stock_query.lastError().text());
                        }

                        emit saleItemAddedChanged(true);
                    }

                    else
                    {
                        m_db.rollback();

                        emit saleItemAddedChanged(false);

                        emit logDataChanged("CRITICAL", "ERROR executing SQL: [" + writeSales.executedQuery() + "] ->" + writeSales.lastError().text());
                    }
                }
            }
        }
    }

    else
        emit logDataChanged("FATAL", "Database not open");

    emit logDataChanged("INFO", "Ending saleItemsModel::addSaleItem()");
}

void saleItemsModel::addMpesaSale(const QVariant &mpesaId, const QVariant &salesId)
{
    emit logDataChanged("INFO", "Starting saleItemsModel::addMpesaSale()");

    QSqlDatabase m_db = QSqlDatabase::database();

    QSqlQuery writeMpesa;
    writeMpesa.prepare("INSERT INTO mpesa(mpesa_id,sales_id) VALUES(:mpesa,:id)");
    writeMpesa.bindValue(":mpesa", mpesaId.toString());
    writeMpesa.bindValue(":id", salesId.toString());

    if(writeMpesa.exec())
    {
        m_db.commit();

        emit logDataChanged("INFO", "Success writing sales info to mpesa!");
    }

    else
    {
        m_db.rollback();

        emit logDataChanged("CRITICAL", "Error writing sale info to mpesa: " + writeMpesa.lastError().text());
    }

    emit logDataChanged("INFO", "Ending saleItemsModel::addMpesaSale()");
}

void saleItemsModel::addCreditSale(const QVariant &crediteeId, const QVariant &dueDate, const QVariant &salesId, const int &amount)
{
    emit logDataChanged("INFO", "Starting saleItemsModel::addCreditSale()");

    QSqlDatabase m_db = QSqlDatabase::database();
    // qDebug() << "Creditee ID: " << crediteeId << " : " << crediteeId.toString().toInt();
    QSqlQuery writeCredit, getCreditBal, setCreditBal;

    QString credBal = "SELECT amount_due FROM creditee WHERE national_id = "+crediteeId.toString()+";";

    if(getCreditBal.exec(credBal))
    {
        int bal = 0;

        while(getCreditBal.next())
        {
            bal = getCreditBal.value(0).toInt();
            break;
        }

        int newBal = bal + amount;
        setCreditBal.prepare("UPDATE creditee SET amount_due = :due WHERE national_id=:nat");
        setCreditBal.bindValue(":due", newBal);
        setCreditBal.bindValue(":nat", crediteeId.toString());

        // qDebug() << "Balance : " << bal << " --> " << newBal;

        if(setCreditBal.exec())
        {
            writeCredit.prepare("INSERT INTO credit(creditee_id,due_date,sales_id) VALUES(:creditee,:date,:id)");
            writeCredit.bindValue(":creditee", crediteeId.toString());
            writeCredit.bindValue(":date", dueDate.toString());
            writeCredit.bindValue(":id", salesId.toString());

            if(writeCredit.exec())
            {
                emit addCrediteePaymentChanged(true);

                emit logDataChanged("INFO", "Creditee Balance Updated after sale!");

                m_db.commit();
            }

            else
            {
                m_db.rollback();

                emit addCrediteePaymentChanged(false);

                emit logDataChanged("CRITICAL", "Error writing to Credit ==> " + writeCredit.lastError().text());
            }
        }

        else
        {
            m_db.rollback();

            emit logDataChanged("CRITICAL", "Failed to update Creditee Balance: " + setCreditBal.lastError().text());
        }
    }

    else
    {
        emit logDataChanged("CRITICAL", "Error fetching Creditee Balance: " + getCreditBal.lastError().text());
    }

    emit addCrediteePaymentChanged(false);

    emit logDataChanged("INFO", "Ending saleItemsModel::addCreditSale()");
}

void saleItemsModel::addPaymentSaleDetails(const QVariant &saleId, const QJsonObject &json)
{
    emit logDataChanged("INFO", "Starting saleItemsModel::addPaymentSaleDetails()");

    QSqlDatabase m_db = QSqlDatabase::database();

    // qDebug() << ">> Adding Payment Data:: > " << QJsonDocument(json);

    QSqlQuery writePayment;
    writePayment.prepare("INSERT INTO payment(cash,mpesa,cheque,credit,sales_id) VALUES(:cash,:mpesa,:cheque,:credit,:id)");
    writePayment.bindValue(":cash", json.value("cash").toDouble());
    writePayment.bindValue(":mpesa", json.value("mpesa").toString());
    writePayment.bindValue(":cheque", json.value("cheque").toString());
    writePayment.bindValue(":credit", json.value("credit").toString());
    writePayment.bindValue(":id", saleId.toString());

    // qDebug() << ">> " << json.value("cash").toDouble() << ", " << json.value("mpesa").toString() << ", " << json.value("cheque").toString() << ", " << json.value("credit").toString();

    if(writePayment.exec())
    {
        m_db.commit();

        emit logDataChanged("INFO", ">> Sucess Adding to sale payments");

        emit paymentItemAdded(true);
    }

    else
    {
        m_db.rollback();

        emit paymentItemAdded(false);

        emit logDataChanged("CRITICAL", "Error executing SQL: " + writePayment.lastError().text());
    }

    emit logDataChanged("INFO", "Ending saleItemsModel::addPaymentSaleDetails()");
}

QString saleItemsModel::getUniqueSaleId()
{
    QString salesid = "AS" + QString::number(QDateTime::currentMSecsSinceEpoch());
    return salesid;
}

QString saleItemsModel::getCurrentTimeString()
{
    return QString::number(QDateTime::currentMSecsSinceEpoch());
}

QString saleItemsModel::getDayFromToday(const int &i)
{
    return m_dateTime->getDayFromToday(i);
}

QString saleItemsModel::generateMpesaId()
{
    return "MP"+QString::number(QDateTime::currentDateTime().toMSecsSinceEpoch());
}

QVariantMap saleItemsModel::getItemSalesDetails(const QString &barcode, const QString &date)
{
    emit logDataChanged("INFO", "Starting saleItemsModel::getItemSalesDetails()");

    QSqlDatabase m_db = QSqlDatabase::database();

    QString upper = date + " 23:59:59+03";
    QString lower = date + " 00:00:00+03";

    QJsonArray arr;


    QSqlQuery query;
    QString sql = "SELECT sales_id,product_sp,sale_qty FROM \"sales\" WHERE barcode='"+barcode+"' AND sales_date > '"+lower+"' AND sales_date < '"+upper+"'";

    if(query.exec(sql))
    {
        while(query.next())
        {
            QString salesId = query.value(0).toString();
            float sp = query.value(1).toInt();
            int qty = query.value(2).toInt();

            if( arr.size() == 0 )
            {
                QJsonObject obj;
                obj.insert("salesId", salesId);
                obj.insert("sp", sp);
                obj.insert("qty", qty);

                arr.append(obj);
            }

            else
            {
                bool found = false;

                for(int i=0; i<arr.size();i++)
                {
                    if(salesId == arr[i].toObject().value("salesId").toString())
                    {
                        QJsonObject _obj = arr[i].toObject();
                        float _sp = _obj.value("sp").toInt();
                        int _qty = _obj.value("qty").toInt();

                        found = true;

                        if(_sp == sp)
                        {
                            int nInt = _qty + qty;
                            _obj["qty"] = nInt;
                            arr[i] = _obj;
                        }

                        else
                        {
                            QJsonObject obj;
                            obj.insert("salesId", salesId);
                            obj.insert("sp", sp);
                            obj.insert("qty", qty);

                            arr.append(obj);
                        }
                    }

                    else
                    {
                        continue;
                    }
                }

                if( !found )
                {
                    QJsonObject obj;
                    obj.insert("salesId", salesId);
                    obj.insert("sp", sp);
                    obj.insert("qty", qty);

                    arr.append(obj);
                }
            }

        }

        emit logDataChanged("INFO", ">> Sucess fetching sales data");
    }

    else
    {
        emit logDataChanged("CRITICAL", "Error executing SQL: " + query.lastError().text());
    }

    emit logDataChanged("INFO", "Ending saleItemsModel::getItemSalesDetails()");

    QJsonObject json;
    json.insert("data", arr);
    return json.toVariantMap();
}
