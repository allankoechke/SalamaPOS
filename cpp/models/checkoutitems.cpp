#include "checkoutitems.h"

CheckoutItems::CheckoutItems(QObject *parent) : QObject(parent)
{

}

CheckoutItems::CheckoutItems(const QString sellBarcode, const QString sellItemName, const QString sellItemUnit, const float buyingPrice, const float sellingPrice, const int sellQty, QObject *parent)
    :QObject(parent),m_sellBarcode(sellBarcode),m_sellItemName(sellItemName),m_sellItemUnit(sellItemUnit),m_buyingPrice(buyingPrice),m_sellingPrice(sellingPrice),m_sellQty(sellQty)
{

}

QString CheckoutItems::sellBarcode() const
{
    return m_sellBarcode;
}

QString CheckoutItems::sellItemName() const
{
    return m_sellItemName;
}

QString CheckoutItems::sellItemUnit() const
{
    return m_sellItemUnit;
}

float CheckoutItems::sellingPrice() const
{
    return m_sellingPrice;
}

float CheckoutItems::buyingPrice() const
{
    return m_buyingPrice;
}

int CheckoutItems::sellQty() const
{
    return m_sellQty;
}

void CheckoutItems::setSellBarcode(QString sellBarcode)
{
    if (m_sellBarcode == sellBarcode)
        return;

    m_sellBarcode = sellBarcode;
    emit sellBarcodeChanged(m_sellBarcode);
}

void CheckoutItems::setSellItemName(QString sellItemName)
{
    if (m_sellItemName == sellItemName)
        return;

    m_sellItemName = sellItemName;
    emit sellItemNameChanged(m_sellItemName);
}

void CheckoutItems::setSellItemUnit(QString sellItemUnit)
{
    if (m_sellItemUnit == sellItemUnit)
        return;

    m_sellItemUnit = sellItemUnit;
    emit sellItemUnitChanged(m_sellItemUnit);
}

void CheckoutItems::setSellingPrice(float sellingPrice)
{
    // qWarning("Floating point comparison needs context sanity check");
    if (static_cast<int>(m_sellingPrice) == static_cast<int>(sellingPrice))
        return;

    m_sellingPrice = sellingPrice;
    emit sellingPriceChanged(m_sellingPrice);
}

void CheckoutItems::setBuyingPrice(float buyingPrice)
{
    // qWarning("Floating point comparison needs context sanity check");
    if (static_cast<int>(m_buyingPrice) == static_cast<int>(buyingPrice))
        return;

    m_buyingPrice = buyingPrice;
    emit buyingPriceChanged(m_buyingPrice);
}

void CheckoutItems::setSellQty(int sellQty)
{
    if (m_sellQty == sellQty)
        return;

    m_sellQty = sellQty;
    emit sellQtyChanged(m_sellQty);
}
