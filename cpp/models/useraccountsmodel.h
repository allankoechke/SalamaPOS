#ifndef USERACCOUNTSMODEL_H
#define USERACCOUNTSMODEL_H

#include <QObject>
#include <QDebug>
#include <QSqlDatabase>
#include <QAbstractListModel>
#include "useraccounts.h"

class UserAccountsModel : public QAbstractListModel
{
    Q_OBJECT

    enum UserAccountsRoles {
        UserFirstnameRole = Qt::UserRole+1,
        UserLastnameRole,
        UserUsernameRole,
        UserPhoneNoRole,
        UserPasswordRole,
        UserDateAddedRole,
        CanAddUsersRole,
        CanRemoveUsersRole,
        CanAddItemsRole,
        CanRemoveItemsRole,
        CanAddStockRole,
        CanRemoveStockRole,
        CanUndoSalesRole,
        CanBackupDbRole,
        ChangePasswordRole
    };

public:
    explicit UserAccountsModel(QObject *parent = nullptr);

    // QAbstractListModel overrides
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Qt::ItemFlags flags(const QModelIndex &index) const;

    QHash<int, QByteArray> roleNames() const;

    // Q_INVOKABLES

    Q_INVOKABLE void addNewUserAccount(const QVariant &userFirstname, const QVariant &userLastname, const QVariant &userUsername, const QVariant &userPassword, const QVariant &userPhoneNo, const QVariant &userDateAdded);

    Q_INVOKABLE void updatePassword(const QVariant &userUsername, const QVariant &userPassword);

    Q_INVOKABLE void removeUserAccount(QVariant index);

    Q_INVOKABLE void updateUserAccount(const QVariant &userFirstname, const QVariant &userLastname, const QVariant &userUsername, const QVariant &userPhoneNo, const QVariant &userDateAdded);

    Q_INVOKABLE void markAccountForDeleting(const QVariant &userUsername);

    // Internals
    void addNewUserAccount(UserAccounts * user);

    void removeUserAccount(int index);

signals:

private:
    QList<UserAccounts *> mUserAccounts;
};

#endif // USERACCOUNTSMODEL_H
