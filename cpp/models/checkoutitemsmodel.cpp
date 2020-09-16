#include "checkoutitemsmodel.h"

CheckoutItemsModel::CheckoutItemsModel(QObject *parent) : QAbstractListModel(parent)
{
    setCheckoutModelSize(0);
}

int CheckoutItemsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return mCheckoutItem.size();
}

QVariant CheckoutItemsModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() > mCheckoutItem.count())
        return QVariant();

    CheckoutItems * checkout = mCheckoutItem[index.row()];

    if(role == SellBarcodeRole)
        return checkout->sellBarcode();

    if(role == SellItemNameRole)
        return checkout->sellItemName();

    if(role == SellItemUnitRole)
        return checkout->sellItemUnit();

    if(role == SellItemBpRole)
        return checkout->buyingPrice();

    if(role == SellItemSpRole)
        return checkout->sellingPrice();

    if(role == SellQtyRole)
        return checkout->sellQty();

    else return QVariant();
}

bool CheckoutItemsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    CheckoutItems * checkout = mCheckoutItem[index.row()];

    bool changed = false;

    switch (role)
    {
    case SellBarcodeRole:
    {
        if( checkout->sellBarcode() != value.toString())
        {
            checkout->setSellBarcode(value.toString());
            changed = true;
        }

        break;
    }

    case SellItemNameRole:
    {
        if( checkout->sellItemName() != value.toString())
        {
            checkout->setSellItemName(value.toString());
            changed = true;
        }

        break;
    }

    case SellItemUnitRole:
    {
        if( checkout->sellItemUnit() != value.toString())
        {
            checkout->setSellItemUnit(value.toString());
            changed = true;
        }

        break;
    }

    case SellItemBpRole:
    {
        if( static_cast<int>(checkout->buyingPrice()) != value.toString().toInt())
        {
            checkout->setBuyingPrice(value.toString().toFloat());
            changed = true;
        }

        break;
    }

    case SellItemSpRole:
    {
        if( static_cast<int>(checkout->sellingPrice()) != value.toString().toInt())
        {
            checkout->setSellingPrice(value.toString().toFloat());
            changed = true;
        }

        break;
    }

    case SellQtyRole:
    {
        if( checkout->sellQty() != value.toString().toInt())
        {
            checkout->setSellQty(value.toString().toInt());
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

Qt::ItemFlags CheckoutItemsModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> CheckoutItemsModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[SellBarcodeRole] = "sell_barcode";
    roles[SellItemNameRole] = "sell_name";
    roles[SellItemUnitRole] = "sell_unit";
    roles[SellItemBpRole] = "sell_bp";
    roles[SellItemSpRole] = "sell_sp";
    roles[SellQtyRole] = "sell_qty";

    return roles;
}

void CheckoutItemsModel::removeSellItem(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    mCheckoutItem.removeAt(index);
    endRemoveRows();

    findTotals();
}

void CheckoutItemsModel::addSellItem(const QVariant sellBarcode, const QVariant  sellItemName, const QVariant  sellItemUnit, const QVariant  buyingPrice, const QVariant  sellingPrice, const QVariant sellQty)
{
    int response = checkIfItemExistsInModel(sellBarcode.toString());

    if(response == -1)
        addItem(new CheckoutItems(sellBarcode.toString(), sellItemName.toString(), sellItemUnit.toString(), buyingPrice.toString().toFloat(), sellingPrice.toString().toFloat(), sellQty.toString().toInt()));

    else
        if(setData(this->index(response), sellQty.toString().toInt()+data(this->index(response), SellQtyRole).toString().toInt(), SellQtyRole))
            findTotals();
}

void CheckoutItemsModel::changeSellStock(const QVariant &qty, const QVariant &barcode)
{
    QString bCode = barcode.toString();

    int index = checkIfItemExistsInModel(bCode);

    if(index != -1)
    {
        setData(this->index(index), qty.toString().toInt(), SellQtyRole);

        saleQtyChanged(true);

        findTotals();
    }

    else
        saleQtyChanged(false);
}

void CheckoutItemsModel::startANewSell()
{
    for(int i=mCheckoutItem.size()-1; i >= 0; i--)
    {
        removeSellItem(i);
    }
}

void CheckoutItemsModel::findTotals()
{
    // Get current Qty
    setCheckoutModelSize(mCheckoutItem.size());

    // Calculates total sell in the model
    float totals = 0;

    for(int i=0; i<mCheckoutItem.size(); i++)
    {
        int _qty = data(this->index(i), SellQtyRole).toString().toInt();
        float _sp = data(this->index(i), SellItemSpRole).toString().toFloat();

        totals += _qty * _sp;
    }

    setSellTotals(totals);

    // qDebug() << "New Totals: " << sellTotals();
}

QString CheckoutItemsModel::getBarcodeAt(int index)
{
    if(index < mCheckoutItem.size())
    {
        return data(this->index(index), SellBarcodeRole).toString();
    }

    return "";
}

int CheckoutItemsModel::getSellQtyAt(int index)
{
    if(index < mCheckoutItem.size())
    {
        return data(this->index(index), SellQtyRole).toInt();
    }

    return -1;
}

int CheckoutItemsModel::checkoutModelSize() const
{
    return m_checkoutModelSize;
}

void CheckoutItemsModel::addItem(CheckoutItems *checkout)
{
    const int index = mCheckoutItem.size();
    beginInsertRows(QModelIndex(), index, index);
    mCheckoutItem.append(checkout);
    endInsertRows();

    findTotals();
}

int CheckoutItemsModel::sellTotals() const
{
    return m_sellTotals;
}

void CheckoutItemsModel::setSellTotals(int sellTotals)
{
    if (static_cast<int>(m_sellTotals) == static_cast<int>(sellTotals))
        return;

    m_sellTotals = sellTotals;
    emit sellTotalsChanged(m_sellTotals);
}

int CheckoutItemsModel::checkIfItemExistsInModel(const QString &barcode)
{
    for(int i=0; i<mCheckoutItem.size(); i++)
    {
        QString _barcode = data(this->index(i), SellBarcodeRole).toString();
        if(barcode == _barcode)
            return i;
    }

    return -1;
}

void CheckoutItemsModel::setCheckoutModelSize(int checkoutModelSize)
{
    if (m_checkoutModelSize == checkoutModelSize)
        return;

    m_checkoutModelSize = checkoutModelSize;
    emit checkoutModelSizeChanged(m_checkoutModelSize);
}
