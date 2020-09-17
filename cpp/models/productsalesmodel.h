#ifndef PRODUCTSALESMODEL_H
#define PRODUCTSALESMODEL_H

#include <QObject>
#include <QDebug>
#include <QAbstractListModel>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include "productsales.h"

class ProductSalesModel : public QAbstractListModel
{
    Q_OBJECT

    enum ProductSalesRoles {
        ProductSaleIdRole = Qt::UserRole+1,
        ProductBarcodeRole,
        ProductNameRole,
        ProductUnitRole,
        ProductQtyRole,
        ProductBpRole,
        ProductSpRole,
        ProductPaymentRole
    };

public:
    explicit ProductSalesModel(QObject *parent = nullptr);

    // QAbstractListModel overrides
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Qt::ItemFlags flags(const QModelIndex &index) const;

    QHash<int, QByteArray> roleNames() const;

    // Q_INVOKABLES
    Q_INVOKABLE void loadSalesData();

    Q_INVOKABLE void addSalesData(const QVariant &barcode, const int &qty, const QJsonObject &cost);

    Q_INVOKABLE void addSalesData(const QVariant &barcode, const int &qty);

    Q_INVOKABLE void showTodaysSales();

    Q_INVOKABLE void showYesterdaysSales();

    Q_INVOKABLE void showThisWeeksSales();

    Q_INVOKABLE void showThisMonthsSales();

    Q_INVOKABLE void showThisYearsSales();


    // Internals
    void addSalesData(ProductSales *sales);

    int getSaleItemIndex(QString barcode);

    bool executeQuery(QSqlQuery query);

signals:

private:
    QList<ProductSales *> m_productSales;

    QJsonObject m_json;
};

#endif // PRODUCTSALESMODEL_H
