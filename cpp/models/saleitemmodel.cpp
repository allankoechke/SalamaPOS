#include "saleitemmodel.h"

SaleItemModel::SaleItemModel(QObject *parent) : QAbstractListModel(parent)
{

}

int SaleItemModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return mSaleItems.size();
}

QVariant SaleItemModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() > mSaleItems.count())
        return QVariant();

    SaleItem * sales= mSaleItems.at(index.row());

    if(role == SaleBarcodeRole)
        return sales->saleBarcode();

    if(role == SaleDateRole)
        return sales->saleDate();

    if(role == SaleBpRole)
        return sales->saleBp();

    if(role == SaleSpRole)
        return sales->saleSp();

    if(role == SaleQtyRole)
        return sales->saleQty();

    if(role == SaleUserRole)
        return sales->saleUser();

    if(role == CostCashRole)
        return sales->costCash();

    if(role == CostMpesaRole)
        return sales->costMpesa();

    if(role == CostChequeRole)
        return sales->costCheque();

    if(role == CostCreditRole)
        return sales->costCredit();

    if(role == SaleIdRole)
        return sales->saleId();

    else return QVariant();
}

bool SaleItemModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    SaleItem * sales= mSaleItems[index.row()];

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
        if( static_cast<int>(sales->saleBp()) != value.toString().toInt())
        {
            sales->setSaleBp(value.toString().toFloat());
            changed = true;
        }

        break;
    }

    case SaleSpRole:
    {
        if( static_cast<int>(sales->saleSp()) != value.toString().toInt())
        {
            sales->setSaleSp(value.toString().toFloat());
            changed = true;
        }

        break;
    }

    case SaleQtyRole:
    {
        if( static_cast<int>(sales->saleSp()) != value.toString().toInt())
        {
            sales->setSaleSp(value.toString().toFloat());
            changed = true;
        }

        break;
    }

    case SaleUserRole:
    {
        if( sales->saleUser() != value.toString())
        {
            sales->setSaleUser(value.toString());
            changed = true;
        }

        break;
    }

    case CostCashRole:
    {
        if( static_cast<int>(sales->costCash()) != value.toString().toInt())
        {
            sales->setCostCash(value.toString().toFloat());
            changed = true;
        }

        break;
    }

    case CostMpesaRole:
    {
        if( static_cast<int>(sales->costMpesa()) != value.toString().toInt())
        {
            sales->setCostMpesa(value.toString().toFloat());
            changed = true;
        }

        break;
    }

    case CostChequeRole:
    {
        if( static_cast<int>(sales->costCheque()) != value.toString().toInt())
        {
            sales->setCostCheque(value.toString().toFloat());
            changed = true;
        }

        break;
    }

    case CostCreditRole:
    {
        if( static_cast<int>(sales->costCredit()) != value.toString().toInt())
        {
            sales->setCostCredit(value.toString().toFloat());
            changed = true;
        }

        break;
    }

    case SaleIdRole:
    {
        if( sales->saleId() != value.toString().toInt())
        {
            sales->setSaleId(value.toString().toInt());
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

Qt::ItemFlags SaleItemModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> SaleItemModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[SaleBarcodeRole] = "sale_barcode";
    roles[SaleDateRole] = "sale_date";
    roles[SaleBpRole] = "sale_bp";
    roles[SaleSpRole] = "sale_sp";
    roles[SaleQtyRole] = "sale_qty";
    roles[SaleUserRole] = "sale_user";
    roles[CostCashRole] = "sale_cash";
    roles[CostMpesaRole] = "sale_mpesa";
    roles[CostChequeRole] = "sale_cheque";
    roles[CostCreditRole] = "sale_credit";
    roles[SaleIdRole] = "sale_id";

    return roles;
}

void SaleItemModel::addSaleItems(const QVariant &start, const QVariant &end)
{

}

void SaleItemModel::addSaleItem(SaleItem * sale)
{
    const int index = mSaleItems.size();

    beginInsertRows(QModelIndex(), index, index);
    mSaleItems.append(sale);
    endInsertRows();

    findTotals();
}

void SaleItemModel::removeSaleItem(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    mSaleItems.removeAt(index);
    endRemoveRows();

    findTotals();
}

void SaleItemModel::clearSaleItems()
{
    qInfo() << ">> Clearing All Items ";

    for(int i=mSaleItems.size()-1; i>=0; i--)
    {
        removeSaleItem(i);
    }

    qInfo() << "End Remove Sale Items";
}

void SaleItemModel::findTotals()
{
    qInfo() << ">> Finding totals for all sales ";

    long totals = 0, cTotals = 0, mTotas = 0, chTotals = 0, crTotals = 0, profit = 0;

    for(int i=0; i<mSaleItems.size(); i++)
    {
        int bp = data(this->index(i), SaleBpRole).toString().toInt();
        int sp = data(this->index(i), SaleSpRole).toString().toInt();
        int qty = data(this->index(i), SaleQtyRole).toString().toInt();

        int cash = data(this->index(i), CostCashRole).toString().toInt();
        int mpesa = data(this->index(i), CostMpesaRole).toString().toInt();
        int cheque = data(this->index(i), CostChequeRole).toString().toInt();
        int credit = data(this->index(i), CostCreditRole).toString().toInt();

        cTotals += cash;
        mTotas += mpesa;
        chTotals += cheque;
        crTotals += credit;
        profit += (sp-bp) * qty;
        totals += qty * sp;
    }

    setSaleProfits(profit);
    setSaleTotals(totals);
    setSaleCashTotals(cTotals);
    setSaleMpesaTotals(mTotas);
    setSaleChequeTotals(chTotals);
    setSaleCreditTotals(crTotals);

}

long SaleItemModel::saleTotals() const
{
    return m_saleTotals;
}

long SaleItemModel::saleCashTotals() const
{
    return m_saleCashTotals;
}

long SaleItemModel::saleMpesaTotals() const
{
    return m_saleMpesaTotals;
}

long SaleItemModel::saleChequeTotals() const
{
    return m_saleChequeTotals;
}

long SaleItemModel::saleProfits() const
{
    return m_saleProfits;
}

long SaleItemModel::saleCreditTotals() const
{
    return m_saleCreditTotals;
}

void SaleItemModel::setSaleTotals(long saleTotals)
{
    if (m_saleTotals == saleTotals)
        return;

    m_saleTotals = saleTotals;
    emit saleTotalsChanged(m_saleTotals);
}

void SaleItemModel::setSaleCashTotals(long saleCashTotals)
{
    if (m_saleCashTotals == saleCashTotals)
        return;

    m_saleCashTotals = saleCashTotals;
    emit saleCashTotalsChanged(m_saleCashTotals);
}

void SaleItemModel::setSaleMpesaTotals(long saleMpesaTotals)
{
    if (m_saleMpesaTotals == saleMpesaTotals)
        return;

    m_saleMpesaTotals = saleMpesaTotals;
    emit saleMpesaTotalsChanged(m_saleMpesaTotals);
}

void SaleItemModel::setSaleChequeTotals(long saleChequeTotals)
{
    if (m_saleChequeTotals == saleChequeTotals)
        return;

    m_saleChequeTotals = saleChequeTotals;
    emit saleChequeTotalsChanged(m_saleChequeTotals);
}

void SaleItemModel::setSaleCreditTotals(long saleCreditTotals)
{
    if (m_saleCreditTotals == saleCreditTotals)
        return;

    m_saleCreditTotals = saleCreditTotals;
    emit saleCreditTotalsChanged(m_saleCreditTotals);
}

void SaleItemModel::setSaleProfits(long saleProfits)
{
    if (m_saleProfits == saleProfits)
        return;

    m_saleProfits = saleProfits;
    emit saleProfitsChanged(m_saleProfits);
}
