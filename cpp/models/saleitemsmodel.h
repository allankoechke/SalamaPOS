#ifndef SALEITEMSMODEL_H
#define SALEITEMSMODEL_H

#include <QDebug>
#include <QObject>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QSqlDatabase>
#include <QAbstractListModel>

#include "src/saleitems.h"
#include "../datetime.h"

class saleItemsModel : public QAbstractListModel
{
    Q_OBJECT

    enum SaleItemModelRoles {
        SaleBarcodeRole = Qt::UserRole+1,
        SaleItemNameRole,
        SaleUnitRole,
        SaleIdRole,
        SaleBpRole,
        SaleSpRole,
        SaleQtyRole,
        CostCashRole,
        CostMpesaRole,
        CostChequeRole,
        CostCreditRole,
        SaleDateRole
    };

public:
    explicit saleItemsModel(QObject *parent = nullptr);

    // QAbstractListModel overrides
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QHash<int, QByteArray> roleNames() const;

    // Q_INVOKABLES
    Q_INVOKABLE void addSaleItem(const QVariant &barcode, const int &qty, const QVariant &uname, const QVariant &saleid, const QVariant &dt);
    Q_INVOKABLE void addMpesaSale(const QVariant &mpesaId, const QVariant &salesId);
    Q_INVOKABLE void addCreditSale(const QVariant &crediteeId, const QVariant &dueDate, const QVariant &salesId, const int &amount);
    Q_INVOKABLE void addPaymentSaleDetails(const QVariant &saleId, const QJsonObject &json);
    Q_INVOKABLE QString getUniqueSaleId();
    Q_INVOKABLE QString getCurrentTimeString();
    Q_INVOKABLE QString getDayFromToday(const int &i);
    Q_INVOKABLE QString generateMpesaId();
    Q_INVOKABLE QVariantMap getItemSalesDetails(const QString &barcode, const QString &date);
    Q_INVOKABLE bool undoSale(const QString &barcode, const QString &salesid, const int &qty);

signals:
    void saleItemAddedChanged(bool status);
    void paymentItemAdded(bool status);    
    void addCrediteePaymentChanged(bool status);
    void updateStockChanged(QString bcode, int qty);
    void updateSalesModelChanged(QString bcode, int qty);
    void addCrediteeChanged(QString idNo, int amount);
    void logDataChanged(QString level, QString info);
    void emitError(QString level, QString desc);

private:
    QList<SaleItems *> m_saleItems;
    DateTime * m_dateTime;

};

#endif // SALEITEMSMODEL_H
