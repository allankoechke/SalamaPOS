#include "saleitems.h"

SaleItems::SaleItems(QObject *parent) : QObject(parent)
{

}

SaleItems::SaleItems(const QString &saleBarcode, const QString &saleItemName, const QString &saleUnit, const QString &saleId, const int &saleBp, const int &saleSp, const int &saleQty,
                     const int &costCash, const int &costMpesa, const int &costCheque,
                     const int &costCredit, const QString &saleDate, QObject *parent)
    : QObject(parent), m_saleBarcode(saleBarcode), m_saleItemName(saleItemName),
      m_saleUnit(saleUnit), m_saleId(saleId), m_saleBp(saleBp), m_saleSp(saleSp),
      m_saleQty(saleQty), m_costCash(costCash), m_costMpesa(costMpesa), m_costCheque(costCheque),
      m_saleDate(saleDate), m_costCredit(costCredit)
{

}

QString SaleItems::saleBarcode() const
{
    return m_saleBarcode;
}

QString SaleItems::saleUnit() const
{
    return m_saleUnit;
}

QString SaleItems::saleItemName() const
{
    return m_saleItemName;
}

QString SaleItems::saleId() const
{
    return m_saleId;
}

int SaleItems::saleBp() const
{
    return m_saleBp;
}

int SaleItems::saleSp() const
{
    return m_saleSp;
}

int SaleItems::saleQty() const
{
    return m_saleQty;
}

QString SaleItems::saleDate() const
{
    return m_saleDate;
}

int SaleItems::costCash() const
{
    return m_costCash;
}

int SaleItems::costMpesa() const
{
    return m_costMpesa;
}

int SaleItems::costCheque() const
{
    return m_costCheque;
}

int SaleItems::costCredit() const
{
    return m_costCredit;
}

void SaleItems::setSaleBarcode(QString saleBarcode)
{
    if (m_saleBarcode == saleBarcode)
        return;

    m_saleBarcode = saleBarcode;
    emit saleBarcodeChanged(m_saleBarcode);
}

void SaleItems::setSaleUnit(QString saleUnit)
{
    if (m_saleUnit == saleUnit)
        return;

    m_saleUnit = saleUnit;
    emit saleUnitChanged(m_saleUnit);
}

void SaleItems::setSaleItemName(QString saleItemName)
{
    if (m_saleItemName == saleItemName)
        return;

    m_saleItemName = saleItemName;
    emit saleItemNameChanged(m_saleItemName);
}

void SaleItems::setSaleId(QString saleId)
{
    if (m_saleId == saleId)
        return;

    m_saleId = saleId;
    emit saleIdChanged(m_saleId);
}

void SaleItems::setSaleBp(int saleBp)
{
    if (m_saleBp == saleBp)
        return;

    m_saleBp = saleBp;
    emit saleBpChanged(m_saleBp);
}

void SaleItems::setSaleSp(int saleSp)
{
    if (m_saleSp == saleSp)
        return;

    m_saleSp = saleSp;
    emit saleSpChanged(m_saleSp);
}

void SaleItems::setSaleQty(int saleQty)
{
    if (m_saleQty == saleQty)
        return;

    m_saleQty = saleQty;
    emit saleQtyChanged(m_saleQty);
}

void SaleItems::setSaleDate(QString saleDate)
{
    if (m_saleDate == saleDate)
        return;

    m_saleDate = saleDate;
    emit saleDateChanged(m_saleDate);
}

void SaleItems::setCostCash(int costCash)
{
    if (m_costCash == costCash)
        return;

    m_costCash = costCash;
    emit costCashChanged(m_costCash);
}

void SaleItems::setCostMpesa(int costMpesa)
{
    if (m_costMpesa == costMpesa)
        return;

    m_costMpesa = costMpesa;
    emit costMpesaChanged(m_costMpesa);
}

void SaleItems::setCostCheque(int costCheque)
{
    if (m_costCheque == costCheque)
        return;

    m_costCheque = costCheque;
    emit costChequeChanged(m_costCheque);
}

void SaleItems::setCostCredit(int costCredit)
{
    if (m_costCredit == costCredit)
        return;

    m_costCredit = costCredit;
    emit costCreditChanged(m_costCredit);
}
