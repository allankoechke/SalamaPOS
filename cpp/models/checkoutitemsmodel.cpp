#include "checkoutitemsmodel.h"

CheckoutItemsModel::CheckoutItemsModel(QObject *parent) : QAbstractListModel(parent)
{
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
        if( static_cast<int>(checkout->SellItemBp()) != value.toString().toInt())
        {
            stock->setItemBp(value.toString().toFloat());
            changed = true;
        }

        break;
    }

    case SellItemSpRole:
    {
        if( static_cast<int>(stock->itemSp()) != value.toString().toInt())
        {
            stock->setItemSp(value.toString().toFloat());
            changed = true;
        }

        break;
    }

    case SellQtyRole:
    {
        if( checkout->itemQty() != value.toString().toInt())
        {
            checkout->setItemQty(value.toString().toInt());
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
