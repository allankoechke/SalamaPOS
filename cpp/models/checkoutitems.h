#ifndef CHECKOUTITEMS_H
#define CHECKOUTITEMS_H

#include <QObject>

class CheckoutItems : public QObject
{
    Q_OBJECT

public:
    explicit CheckoutItems(QObject *parent = nullptr);

    CheckoutItems(const QString sellBarcode, const QString sellItemName, const QString sellItemUnit, const float buyingPrice, const float sellingPrice, const int sellQty, QObject *parent = nullptr);

    // Properties
    Q_PROPERTY(QString sellBarcode READ sellBarcode WRITE setSellBarcode NOTIFY sellBarcodeChanged)
    Q_PROPERTY(QString sellItemName READ sellItemName WRITE setSellItemName NOTIFY sellItemNameChanged)
    Q_PROPERTY(QString sellItemUnit READ sellItemUnit WRITE setSellItemUnit NOTIFY sellItemUnitChanged)
    Q_PROPERTY(float buyingPrice READ buyingPrice WRITE setBuyingPrice NOTIFY buyingPriceChanged)
    Q_PROPERTY(float sellingPrice READ sellingPrice WRITE setSellingPrice NOTIFY sellingPriceChanged)
    Q_PROPERTY(int sellQty READ sellQty WRITE setSellQty NOTIFY sellQtyChanged)

    // Class getters
    QString sellBarcode() const;

    QString sellItemName() const;

    QString sellItemUnit() const;

    float sellingPrice() const;

    float buyingPrice() const;

    int sellQty() const;

    // Setters of the class
    void setSellBarcode(QString sellBarcode);

    void setSellItemName(QString sellItemName);

    void setSellItemUnit(QString sellItemUnit);

    void setSellingPrice(float sellingPrice);

    void setBuyingPrice(float buyingPrice);

    void setSellQty(int sellQty);

signals:
    void sellBarcodeChanged(QString sellBarcode);
    void sellItemNameChanged(QString sellItemName);
    void sellItemUnitChanged(QString sellItemUnit);
    void sellingPriceChanged(float sellingPrice);
    void buyingPriceChanged(float buyingPrice);
    void sellQtyChanged(int sellQty);


private:
    QString m_sellBarcode, m_sellItemName, m_sellItemUnit;

    float m_sellingPrice, m_buyingPrice;

    int m_sellQty;
};

#endif // CHECKOUTITEMS_H
