#ifndef PRODUCTSALES_H
#define PRODUCTSALES_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>

class ProductSales : public QObject
{
    Q_OBJECT

public:
    explicit ProductSales(QObject *parent = nullptr);
    ProductSales(const QString &productSaleId, const QString &productBarcode, const QString &productName, const QString &productUnit, const int &productQty, const int &productBp, const int &productSp, const QJsonObject &productPayment, QObject *parent = nullptr);

    Q_PROPERTY(QString productSaleId READ productSaleId WRITE setProductSaleId NOTIFY productSaleIdChanged)
    Q_PROPERTY(QString productBarcode READ productBarcode WRITE setProductBarcode NOTIFY productBarcodeChanged)
    Q_PROPERTY(QString productName READ productName WRITE setProductName NOTIFY productNameChanged)
    Q_PROPERTY(QString productUnit READ productUnit WRITE setProductUnit NOTIFY productUnitChanged)
    Q_PROPERTY(int productQty READ productQty WRITE setProductQty NOTIFY productQtyChanged)
    Q_PROPERTY(int productBp READ productBp WRITE setProductBp NOTIFY productBpChanged)
    Q_PROPERTY(int productSp READ productSp WRITE setProductSp NOTIFY productSpChanged)
    Q_PROPERTY(QJsonObject productPayment READ productPayment WRITE setProductPayment NOTIFY productPaymentChanged)


    QString productSaleId() const;

    QString productBarcode() const;

    QString productName() const;

    QString productUnit() const;

    int productQty() const;

    int productBp() const;

    int productSp() const;

    QJsonObject productPayment() const;

    // Setters
    void setProductSaleId(QString productSaleId);

    void setProductBarcode(QString productBarcode);

    void setProductName(QString productName);

    void setProductUnit(QString productUnit);

    void setProductQty(int productQty);

    void setProductBp(int productBp);

    void setProductSp(int productSp);

    void setProductPayment(QJsonObject productPayment);

signals:

    void productSaleIdChanged(QString productSaleId);
    void productBarcodeChanged(QString productBarcode);
    void productNameChanged(QString productName);
    void productUnitChanged(QString productUnit);
    void productQtyChanged(int productQty);
    void productBpChanged(int productBp);
    void productSpChanged(int productSp);
    void productPaymentChanged(QJsonObject productPayment);

private:
    QString m_productSaleId, m_productBarcode, m_productName, m_productUnit;

    int m_productQty, m_productBp, m_productSp;

    QJsonObject m_productPayment;
};

#endif // PRODUCTSALES_H
