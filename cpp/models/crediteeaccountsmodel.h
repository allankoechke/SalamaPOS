#ifndef CREDITEEACCOUNTSMODEL_H
#define CREDITEEACCOUNTSMODEL_H

#include <QObject>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QAbstractListModel>

#include "src/crediteeaccount.h"
#include "../datetime.h"

class CrediteeAccountsModel : public QAbstractListModel
{
    Q_OBJECT

    enum CrediteeAccountsRoles {
        FirstNameRole = Qt::UserRole + 1,
        LastNameRole,
        MobileNoRole,
        IdNoRole,
        DebtAmountRole
    };

public:
    explicit CrediteeAccountsModel(QObject *parent = nullptr);

    // QAbstractListModel overrides
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Qt::ItemFlags flags(const QModelIndex &index) const;

    QHash<int, QByteArray> roleNames() const;

    // Q_INVOKABLEs
    Q_INVOKABLE void addNewCreditee(const QString &fname, const QString &lname, const QString &mobile, const QString &idNo);
    Q_INVOKABLE void updateCreditee(const QString &fname, const QString &lname, const QString &mobile, const QString &idNo, const QString &orig_id);
    Q_INVOKABLE void loadCrediteeAccounts();
    Q_INVOKABLE void getPaymentHistory(const QString &idNo);
    Q_INVOKABLE bool repayDebt(const QString &crediteeId, const int &debt, const int &debtPaid);

    // Internals
    void addNewCreditee(CrediteeAccount * creditee);
    void removeCreditee(int index);
    int getIndex(QVariant id);


signals:
    void crediteeAdded(bool status);
    void crediteeUpdated(bool status);
    void idExists();
    void paymentReceived(QString date, int paid, int due);
    void giveBalanceChanged(int bal);
    void logDataChanged(QString level, QString info);
    void debRepaymentChanged(bool state);

private:
    QList<CrediteeAccount *> m_crediteeAccount;
    DateTime * dateTime;
};

#endif // CREDITEEACCOUNTSMODEL_H
