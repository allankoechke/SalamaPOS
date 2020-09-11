#include "saleitem.h"

SaleItem::SaleItem(QObject *parent) : QObject(parent)
{

}

SaleItem::SaleItem(const QString &saleBarcode, const QString &saleDate, const float &saleBp, const float &saleSp, const int &saleQty, const QString &saleUser, const float &costCash, const float &costMpesa, const float &costCheque, const float &costCredit, const int &saleId, QObject *parent)
    :QObject(parent),m_saleBarcode(saleBarcode),m_saleDate(saleDate),m_saleBp(saleBp),m_saleSp(saleBp),m_saleQty(saleQty),m_saleUser(saleUser),m_costCash(costCash),m_costMpesa(costMpesa),m_costCheque(costCheque),m_costCredit(costCredit),m_saleId(saleId)
{

}

QString SaleItem::saleBarcode() const
{
    return m_saleBarcode;
}

QString SaleItem::saleDate() const
{
    return m_saleDate;
}

float SaleItem::saleBp() const
{
    return m_saleBp;
}

float SaleItem::saleSp() const
{
    return m_saleSp;
}

int SaleItem::saleQty() const
{
    return m_saleQty;
}

QString SaleItem::saleUser() const
{
    return m_saleUser;
}

float SaleItem::costCash() const
{
    return m_costCash;
}

float SaleItem::costMpesa() const
{
    return m_costMpesa;
}

float SaleItem::costCheque() const
{
    return m_costCheque;
}

float SaleItem::costCredit() const
{
    return m_costCredit;
}

int SaleItem::saleId() const
{
    return m_saleId;
}

void SaleItem::setSaleBarcode(QString saleBarcode)
{
    if (m_saleBarcode == saleBarcode)
        return;

    m_saleBarcode = saleBarcode;
    emit saleBarcodeChanged(m_saleBarcode);
}

void SaleItem::setSaleDate(QString saleDate)
{
    if (m_saleDate == saleDate)
        return;

    m_saleDate = saleDate;
    emit saleDateChanged(m_saleDate);
}

void SaleItem::setSaleBp(float saleBp)
{
    // qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_saleBp, saleBp))
        return;

    m_saleBp = saleBp;
    emit saleBpChanged(m_saleBp);
}

void SaleItem::setSaleSp(float saleSp)
{
    // qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_saleSp, saleSp))
        return;

    m_saleSp = saleSp;
    emit saleSpChanged(m_saleSp);
}

void SaleItem::setSaleQty(int saleQty)
{
    if (m_saleQty == saleQty)
        return;

    m_saleQty = saleQty;
    emit saleQtyChanged(m_saleQty);
}

void SaleItem::setSaleUser(QString saleUser)
{
    if (m_saleUser == saleUser)
        return;

    m_saleUser = saleUser;
    emit saleUserChanged(m_saleUser);
}

void SaleItem::setCostCash(float costCash)
{
    // qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_costCash, costCash))
        return;

    m_costCash = costCash;
    emit costCashChanged(m_costCash);
}

void SaleItem::setCostMpesa(float costMpesa)
{
    // qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_costMpesa, costMpesa))
        return;

    m_costMpesa = costMpesa;
    emit costMpesaChanged(m_costMpesa);
}

void SaleItem::setCostCheque(float costCheque)
{
    // qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_costCheque, costCheque))
        return;

    m_costCheque = costCheque;
    emit costChequeChanged(m_costCheque);
}

void SaleItem::setCostCredit(float costCredit)
{
    // qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_costCredit, costCredit))
        return;

    m_costCredit = costCredit;
    emit costCreditChanged(m_costCredit);
}

void SaleItem::setSaleId(int saleId)
{
    if (m_saleId == saleId)
        return;

    m_saleId = saleId;
    emit saleIdChanged(m_saleId);
}
