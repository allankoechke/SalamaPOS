#ifndef SALEITEMMODEL_H
#define SALEITEMMODEL_H

#include <QObject>
#include <QDebug>
#include <QAbstractListModel>
#include "saleitem.h"

class SaleItemModel : public QAbstractListModel
{
    Q_OBJECT

    enum SaleItemModelRoles{
        SaleBarcodeRole = Qt::UserRole+1,
        SaleDateRole,
        SaleBpRole,
        SaleSpRole,
        SaleQtyRole,
        SaleUserRole,
        CostCashRole,
        CostMpesaRole,
        CostChequeRole,
        CostCreditRole,
        SaleIdRole,
    };

public:
    explicit SaleItemModel(QObject *parent = nullptr);

    // QAbstractListModel overrides
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Qt::ItemFlags flags(const QModelIndex &index) const;

    QHash<int, QByteArray> roleNames() const;

    // Invokables from QML
    //const QVariant &saleBarcode, const QVariant &saleDate, const QVariant &saleBp, const QVariant &saleSp, const QVariant &saleQty, const QVariant &saleUser, const QVariant &costCash, const QVariant &costMpesa, const QVariant &costCheque, const QVariant &costCredit, const QVariant &saleId);
    Q_INVOKABLE void addSaleItems(const QVariant &start, const QVariant &end);

    Q_INVOKABLE void removeSaleItem(int index);

    Q_INVOKABLE void clearSaleItems();

    Q_INVOKABLE void findTotals();

    // Properties
    Q_PROPERTY(long saleTotals READ saleTotals WRITE setSaleTotals NOTIFY saleTotalsChanged)
    Q_PROPERTY(long saleCashTotals READ saleCashTotals WRITE setSaleCashTotals NOTIFY saleCashTotalsChanged)
    Q_PROPERTY(long saleMpesaTotals READ saleMpesaTotals WRITE setSaleMpesaTotals NOTIFY saleMpesaTotalsChanged)
    Q_PROPERTY(long saleChequeTotals READ saleChequeTotals WRITE setSaleChequeTotals NOTIFY saleChequeTotalsChanged)
    Q_PROPERTY(long saleCreditTotals READ saleCreditTotals WRITE setSaleCreditTotals NOTIFY saleCreditTotalsChanged)
    Q_PROPERTY(long saleProfits READ saleProfits WRITE setSaleProfits NOTIFY saleProfitsChanged)

    // Getters
    long saleTotals() const;

    long saleCashTotals() const;

    long saleMpesaTotals() const;

    long saleChequeTotals() const;

    long saleCreditTotals() const;

    long saleProfits() const;

    // Setters
    void setSaleTotals(long saleTotals);

    void setSaleCashTotals(long saleCashTotals);

    void setSaleMpesaTotals(long saleMpesaTotals);

    void setSaleChequeTotals(long saleChequeTotals);

    void setSaleCreditTotals(long saleCreditTotals);

    void setSaleProfits(long saleProfits);

    // Internals
    void addSaleItem(SaleItem * sale);

signals:

    void saleTotalsChanged(long saleTotals);

    void saleCashTotalsChanged(long saleCashTotals);

    void saleMpesaTotalsChanged(long saleMpesaTotals);

    void saleChequeTotalsChanged(long saleChequeTotals);

    void saleCreditTotalsChanged(long saleCreditTotals);

    void saleProfitsChanged(long saleProfits);

private:
    QList<SaleItem *> mSaleItems;

    long m_saleTotals, m_saleCashTotals, m_saleMpesaTotals, m_saleChequeTotals, m_saleCreditTotals, m_saleProfits;
};

#endif // SALEITEMMODEL_H
