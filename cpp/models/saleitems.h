#ifndef SALEITEMS_H
#define SALEITEMS_H

#include <QObject>

class SaleItems : public QObject
{
    Q_OBJECT

public:
    explicit SaleItems(QObject *parent = nullptr);

    SaleItems(const QString &saleBarcode, const QString &saleItemName, const QString &saleUnit, const QString &saleId, const int &saleBp, const int &saleSp, const int &saleQty, const int &costCash, const int &costMpesa, const int &costCheque, const int &costCredit, const QString &saleDate, QObject *parent = nullptr);

    Q_PROPERTY(QString saleBarcode READ saleBarcode WRITE setSaleBarcode NOTIFY saleBarcodeChanged)
    Q_PROPERTY(QString saleItemName READ saleItemName WRITE setSaleItemName NOTIFY saleItemNameChanged)
    Q_PROPERTY(QString saleUnit READ saleUnit WRITE setSaleUnit NOTIFY saleUnitChanged)
    Q_PROPERTY(QString saleId READ saleId WRITE setSaleId NOTIFY saleIdChanged)
    Q_PROPERTY(int saleBp READ saleBp WRITE setSaleBp NOTIFY saleBpChanged)
    Q_PROPERTY(int saleSp READ saleSp WRITE setSaleSp NOTIFY saleSpChanged)
    Q_PROPERTY(int saleQty READ saleQty WRITE setSaleQty NOTIFY saleQtyChanged)
    Q_PROPERTY(int costCash READ costCash WRITE setCostCash NOTIFY costCashChanged)
    Q_PROPERTY(int costMpesa READ costMpesa WRITE setCostMpesa NOTIFY costMpesaChanged)
    Q_PROPERTY(int costCheque READ costCheque WRITE setCostCheque NOTIFY costChequeChanged)
    Q_PROPERTY(int costCredit READ costCredit WRITE setCostCredit NOTIFY costCreditChanged)
    Q_PROPERTY(QString saleDate READ saleDate WRITE setSaleDate NOTIFY saleDateChanged)

    QString saleBarcode() const;

    QString saleUnit() const;

    QString saleItemName() const;

    QString saleId() const;

    int saleBp() const;

    int saleSp() const;

    int saleQty() const;

    QString saleDate() const;

    int costCash() const;

    int costMpesa() const;

    int costCheque() const;

    int costCredit() const;

    // Setters
    void setSaleBarcode(QString saleBarcode);

    void setSaleUnit(QString saleUnit);

    void setSaleItemName(QString saleItemName);

    void setSaleId(QString saleId);

    void setSaleBp(int saleBp);

    void setSaleSp(int saleSp);

    void setSaleQty(int saleQty);

    void setSaleDate(QString saleDate);

    void setCostCash(int costCash);

    void setCostMpesa(int costMpesa);

    void setCostCheque(int costCheque);

    void setCostCredit(int costCredit);

signals:

    void saleBarcodeChanged(QString saleBarcode);
    void saleUnitChanged(QString saleUnit);
    void saleItemNameChanged(QString saleItemName);
    void saleIdChanged(QString saleId);
    void saleBpChanged(int saleBp);
    void saleSpChanged(int saleSp);
    void saleQtyChanged(int saleQty);
    void saleDateChanged(QString saleDate);
    void costCashChanged(int costCash);
    void costMpesaChanged(int costMpesa);
    void costChequeChanged(int costCheque);
    void costCreditChanged(int costCredit);

private:
    QString m_saleBarcode, m_saleUnit, m_saleItemName, m_saleId, m_saleDate;

    int m_saleBp, m_saleSp, m_saleQty, m_costCash, m_costMpesa, m_costCheque, m_costCredit;
};

#endif // SALEITEMS_H
