#include "productsales.h"
#include "productsales.h"

ProductSales::ProductSales(QObject *parent) : QObject(parent)
{

}

ProductSales::ProductSales(const QString &productSaleId, const QString &productBarcode, const QString &productName, const QString &productUnit, const int &productQty, const int &productBp, const int &productSp, const QJsonObject &productPayment, QObject *parent)
    : QObject(parent), m_productSaleId(productSaleId), m_productBarcode(productBarcode), m_productName(productName), m_productUnit(productUnit), m_productQty(productQty), m_productBp(productBp), m_productSp(productSp), m_productPayment(productPayment)
{

}

QString ProductSales::productSaleId() const
{
    return m_productSaleId;
}

QString ProductSales::productBarcode() const
{
    return m_productBarcode;
}

QString ProductSales::productName() const
{
    return m_productName;
}

QString ProductSales::productUnit() const
{
    return m_productUnit;
}

int ProductSales::productQty() const
{
    return m_productQty;
}

int ProductSales::productBp() const
{
    return m_productBp;
}

int ProductSales::productSp() const
{
    return m_productSp;
}

QJsonObject ProductSales::productPayment() const
{
    return m_productPayment;
}

void ProductSales::setProductSaleId(QString productSaleId)
{
    if (m_productSaleId == productSaleId)
        return;

    m_productSaleId = productSaleId;
    emit productSaleIdChanged(m_productSaleId);
}

void ProductSales::setProductBarcode(QString productBarcode)
{
    if (m_productBarcode == productBarcode)
        return;

    m_productBarcode = productBarcode;
    emit productBarcodeChanged(m_productBarcode);
}

void ProductSales::setProductName(QString productName)
{
    if (m_productName == productName)
        return;

    m_productName = productName;
    emit productNameChanged(m_productName);
}

void ProductSales::setProductUnit(QString productUnit)
{
    if (m_productUnit == productUnit)
        return;

    m_productUnit = productUnit;
    emit productUnitChanged(m_productUnit);
}

void ProductSales::setProductQty(int productQty)
{
    if (m_productQty == productQty)
        return;

    m_productQty = productQty;
    emit productQtyChanged(m_productQty);
}

void ProductSales::setProductBp(int productBp)
{
    if (m_productBp == productBp)
        return;

    m_productBp = productBp;
    emit productBpChanged(m_productBp);
}

void ProductSales::setProductSp(int productSp)
{
    if (m_productSp == productSp)
        return;

    m_productSp = productSp;
    emit productSpChanged(m_productSp);
}

void ProductSales::setProductPayment(QJsonObject productPayment)
{
    if (m_productPayment == productPayment)
        return;

    m_productPayment = productPayment;
    emit productPaymentChanged(m_productPayment);
}
