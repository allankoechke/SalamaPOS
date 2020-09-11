#ifndef SALEITEM_H
#define SALEITEM_H

#include <QObject>

class SaleItem : public QObject
{
    Q_OBJECT

public:
    explicit SaleItem(QObject *parent = nullptr);

    SaleItem(const QString &saleBarcode, const QString &saleDate, const float &saleBp, const float &saleSp, const int &saleQty, const QString &saleUser, const float &costCash, const float &costMpesa, const float &costCheque, const float &costCredit, const int &saleId, QObject *parent = nullptr);

    // Properties
    Q_PROPERTY(QString saleBarcode READ saleBarcode WRITE setSaleBarcode NOTIFY saleBarcodeChanged)
    Q_PROPERTY(QString saleDate READ saleDate WRITE setSaleDate NOTIFY saleDateChanged)
    Q_PROPERTY(float saleBp READ saleBp WRITE setSaleBp NOTIFY saleBpChanged)
    Q_PROPERTY(float saleSp READ saleSp WRITE setSaleSp NOTIFY saleSpChanged)
    Q_PROPERTY(int saleQty READ saleQty WRITE setSaleQty NOTIFY saleQtyChanged)
    Q_PROPERTY(QString saleUser READ saleUser WRITE setSaleUser NOTIFY saleUserChanged)
    Q_PROPERTY(float costCash READ costCash WRITE setCostCash NOTIFY costCashChanged)
    Q_PROPERTY(float costMpesa READ costMpesa WRITE setCostMpesa NOTIFY costMpesaChanged)
    Q_PROPERTY(float costCheque READ costCheque WRITE setCostCheque NOTIFY costChequeChanged)
    Q_PROPERTY(float costCredit READ costCredit WRITE setCostCredit NOTIFY costCreditChanged)
    Q_PROPERTY(int saleId READ saleId WRITE setSaleId NOTIFY saleIdChanged)


    // Getters
    QString saleBarcode() const;

    QString saleDate() const;

    float saleBp() const;

    float saleSp() const;

    int saleQty() const;

    QString saleUser() const;

    float costCash() const;

    float costMpesa() const;

    float costCheque() const;

    float costCredit() const;

    int saleId() const;

    // Setters
    void setSaleBarcode(QString saleBarcode);

    void setSaleDate(QString saleDate);

    void setSaleBp(float saleBp);

    void setSaleSp(float saleSp);

    void setSaleQty(int saleQty);

    void setSaleUser(QString saleUser);

    void setCostCash(float costCash);

    void setCostMpesa(float costMpesa);

    void setCostCheque(float costCheque);

    void setCostCredit(float costCredit);

    void setSaleId(int saleId);

signals:
    void saleBarcodeChanged(QString saleBarcode);
    void saleDateChanged(QString saleDate);
    void saleBpChanged(float saleBp);
    void saleSpChanged(float saleSp);
    void saleQtyChanged(int saleQty);
    void saleUserChanged(QString saleUser);
    void costCashChanged(float costCash);
    void costMpesaChanged(float costMpesa);
    void costChequeChanged(float costCheque);
    void costCreditChanged(float costCredit);
    void saleIdChanged(int saleId);

private:
    QString m_saleBarcode, m_saleDate, m_saleUser;

    float m_saleBp, m_saleSp, m_saleQty, m_costCash, m_costMpesa, m_costCheque, m_costCredit;

    int m_saleId;
};

#endif // SALEITEM_H
