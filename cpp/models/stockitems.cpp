#include "stockitems.h"

StockItems::StockItems(QObject *parent) : QObject(parent)
{
}

StockItems::StockItems(const QString barCode, const QString itemName, const QString itemUnit, const float itemBp, const float itemSp, const QString itemCompany, const int itemQty, const QString lastUpdate, const QString itemCategory, QObject *parent)
    :QObject(parent),m_barCode(barCode),m_itemName(itemName),m_itemUnit(itemUnit),m_itemCompany(itemCompany),m_itemQty(itemQty),m_itemBp(itemBp),m_itemSp(itemSp),m_lastUpdate(lastUpdate),m_itemCategory(itemCategory)
{
}

QString StockItems::barCode() const
{
    return m_barCode;
}

QString StockItems::itemName() const
{
    return m_itemName;
}

QString StockItems::itemUnit() const
{
    return m_itemUnit;
}

float StockItems::itemBp() const
{
    return m_itemBp;
}

float StockItems::itemSp() const
{
    return m_itemSp;
}

int StockItems::itemQty() const
{
    return m_itemQty;
}

QString StockItems::itemCompany() const
{
    return m_itemCompany;
}

QString StockItems::lastUpdate() const
{
    return m_lastUpdate;
}

void StockItems::setBarCode(QString barCode)
{
    if (m_barCode == barCode)
        return;

    m_barCode = barCode;
    emit barCodeChanged(m_barCode);
}

void StockItems::setItemName(QString itemName)
{
    if (m_itemName == itemName)
        return;

    m_itemName = itemName;
    emit itemNameChanged(m_itemName);
}

void StockItems::setItemUnit(QString itemUnit)
{
    if (m_itemUnit == itemUnit)
        return;

    m_itemUnit = itemUnit;
    emit itemUnitChanged(m_itemUnit);
}

void StockItems::setItemBp(float itemBp)
{
    if (QVariant::fromValue(m_itemBp).toInt() == QVariant::fromValue(itemBp))
        return;

    m_itemBp = itemBp;
    emit itemBpChanged(m_itemBp);
}

void StockItems::setItemSp(float itemSp)
{
    if (QVariant::fromValue(m_itemSp).toInt() == QVariant::fromValue(itemSp).toInt())
        return;

    m_itemSp = itemSp;
    emit itemSpChanged(m_itemSp);
}

void StockItems::setItemQty(int itemQty)
{
    if (m_itemQty == itemQty)
        return;

    m_itemQty = itemQty;
    emit itemQtyChanged(m_itemQty);
}

void StockItems::setItemCompany(QString itemCompany)
{
    if (m_itemCompany == itemCompany)
        return;

    m_itemCompany = itemCompany;
    emit itemCompanyChanged(m_itemCompany);
}

void StockItems::setLastUpdate(QString lastUpdate)
{
    if (m_lastUpdate == lastUpdate)
        return;

    m_lastUpdate = lastUpdate;
    emit lastUpdateChanged(m_lastUpdate);
}

QString StockItems::itemCategory() const
{
    return m_itemCategory;
}

void StockItems::setItemCategory(QString itemCategory)
{
    if (m_itemCategory == itemCategory)
        return;

    m_itemCategory = itemCategory;
    emit itemCategoryChanged(m_itemCategory);
}
