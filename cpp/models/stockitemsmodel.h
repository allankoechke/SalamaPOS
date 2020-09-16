#ifndef STOCKITEMSMODEL_H
#define STOCKITEMSMODEL_H

#include <QObject>
#include <QDebug>
#include <QAbstractListModel>
#include "stockitems.h"
#include "../databaseinterface.h"

class StockItemsModel : public QAbstractListModel
{
    Q_OBJECT

    enum StockItemRoles{
        BarcodeRole = Qt::UserRole+1,
        ItemNameRole,
        ItemUnitRole,
        ItemBpRole,
        ItemSpRole,
        ItemQtyRole,
        ItemCompanyRole,
        ItemLastUpdateRole,
        ItemCategoryRole
    };

public:
    explicit StockItemsModel(QObject *parent = nullptr);

    // QAbstractListModel overrides
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Qt::ItemFlags flags(const QModelIndex &index) const;

    QHash<int, QByteArray> roleNames() const;

    // Additional Invokable functions from QML
    Q_INVOKABLE void addNewItem(const QVariant &barcode, const QVariant &name, const QVariant &unit, const QVariant &bp, const QVariant &sp, const QVariant &qty, const QVariant &company, const QVariant &date, const QVariant &category);

    Q_INVOKABLE void updateItem(const QVariant &barcode, const QVariant &name, const QVariant &unit, const QVariant &bp, const QVariant &sp, const QVariant &company, const QVariant &category, const QVariant &orig_barcode, const QVariant &index);

    Q_INVOKABLE void updateStock(const QVariant &barcode, const QVariant &qty, const QVariant &date, const QVariant &index);

    Q_INVOKABLE void updateStockOnSale(const QVariant &bcode, const int &qty);

    Q_INVOKABLE void initializeStockFromDb();

    Q_INVOKABLE int getItemStock(const QVariant &barcode);

    Q_INVOKABLE QJsonObject getItemData(const QString &barcode);

    // Internal functions
    bool addNewItem(StockItems * stockItem);

    int getItemIndex(const QVariant &bcode);

    void removeItem(int index);

signals:
    void itemUpdatedChanged(bool state);

    void itemAddedChanged(bool state);

    void itemStockChanged(bool state);

    void itemStockAfterSaleChanged(bool state);

    void itemAddingChanged(bool state);

    void itemDataChanged(bool status, QJsonObject json); // Notify if fetching data from bcode was successful

    void itemStockWarningChanged(); // Notify if stock qty is less that qty needed to sell


private slots:
    void onDatabaseReady();

private:
    QList<StockItems *> m_stockItems;

    // DatabaseInterface * m_databaseInterface;
    QJsonObject m_itemDetails;
};

#endif // STOCKITEMSMODEL_H
