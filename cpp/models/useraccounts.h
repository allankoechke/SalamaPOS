#ifndef USERACCOUNTS_H
#define USERACCOUNTS_H

#include <QObject>

class UserAccounts : public QObject
{
    Q_OBJECT

public:
    explicit UserAccounts(QObject *parent = nullptr);
    UserAccounts(const QString &userFirstname, const QString &userLastname, const QString &userUsername, const QString &userPhoneNo, const QString &userPassword,const QString &userDateAdded, const bool &canAddUsers, const bool &canRemoveUsers, const bool &canAddItems, const bool &canRemoveItems, const bool &canAddStock, const bool &canRemoveStock, const bool &canUndoSales, const bool &canBackupDb, const bool &changePassword, QObject *parent = nullptr);

    // Properties
    Q_PROPERTY(QString userFirstname READ userFirstname WRITE setUserFirstname NOTIFY userFirstnameChanged)
    Q_PROPERTY(QString userLastname READ userLastname WRITE setUserLastname NOTIFY userLastnameChanged)
    Q_PROPERTY(QString userUsername READ userUsername WRITE setUserUsername NOTIFY userUsernameChanged)
    Q_PROPERTY(QString userPhoneNo READ userPhoneNo WRITE setUserPhoneNo NOTIFY userPhoneNoChanged)
    Q_PROPERTY(QString userPassword READ userPassword WRITE setUserPassword NOTIFY userPasswordChanged)
    Q_PROPERTY(QString userDateAdded READ userDateAdded WRITE setUserDateAdded NOTIFY userDateAddedChanged)
    Q_PROPERTY(bool canAddUsers READ canAddUsers WRITE setCanAddUsers NOTIFY canAddUsersChanged)
    Q_PROPERTY(bool canRemoveUsers READ canRemoveUsers WRITE setCanRemoveUsers NOTIFY canRemoveUsersChanged)
    Q_PROPERTY(bool canAddItems READ canAddItems WRITE setCanAddItems NOTIFY canAddItemsChanged)
    Q_PROPERTY(bool canRemoveItems READ canRemoveItems WRITE setCanRemoveItems NOTIFY canRemoveItemsChanged)
    Q_PROPERTY(bool canAddStock READ canAddStock WRITE setCanAddStock NOTIFY canAddStockChanged)
    Q_PROPERTY(bool canRemoveStock READ canRemoveStock WRITE setCanRemoveStock NOTIFY canRemoveStockChanged)
    Q_PROPERTY(bool canUndoSales READ canUndoSales WRITE setCanUndoSales NOTIFY canUndoSalesChanged)
    Q_PROPERTY(bool canBackupDb READ canBackupDb WRITE setCanBackupDb NOTIFY canBackupDbChanged)
    Q_PROPERTY(bool changePassword READ changePassword WRITE setChangePassword NOTIFY changePasswordChanged)

    // Getters
    QString userFirstname() const;

    QString userLastname() const;

    QString userUsername() const;

    QString userPhoneNo() const;

    QString userPassword() const;

    QString userDateAdded() const;

    bool canAddUsers() const;

    bool canRemoveUsers() const;

    bool canAddItems() const;

    bool canRemoveItems() const;

    bool canAddStock() const;

    bool canRemoveStock() const;

    bool canUndoSales() const;

    bool canBackupDb() const;

    bool changePassword() const;

    // Setters
    void setUserFirstname(QString userFirstname);

    void setUserLastname(QString userLastname);

    void setUserUsername(QString userUsername);

    void setUserPhoneNo(QString userPhoneNo);

    void setUserPassword(QString userPassword);

    void setUserDateAdded(QString userDateAdded);

    void setCanAddUsers(bool canAddUsers);

    void setCanRemoveUsers(bool canRemoveUsers);

    void setCanAddItems(bool canAddItems);

    void setCanRemoveItems(bool canRemoveItems);

    void setCanAddStock(bool canAddStock);

    void setCanRemoveStock(bool canRemoveStock);

    void setCanUndoSales(bool canUndoSales);

    void setCanBackupDb(bool canBackupDb);

    void setChangePassword(bool changePassword);

signals:

    void userFirstnameChanged(QString userFirstname);
    void userLastnameChanged(QString userLastname);
    void userUsernameChanged(QString userUsername);
    void userPhoneNoChanged(QString userPhoneNo);
    void userPasswordChanged(QString userPassword);
    void userDateAddedChanged(QString userDateAdded);
    void canAddUsersChanged(bool canAddUsers);
    void canRemoveUsersChanged(bool canRemoveUsers);
    void canAddItemsChanged(bool canAddItems);
    void canRemoveItemsChanged(bool canRemoveItems);
    void canAddStockChanged(bool canAddStock);
    void canRemoveStockChanged(bool canRemoveStock);
    void canUndoSalesChanged(bool canUndoSales);
    void canBackupDbChanged(bool canBackupDb);

    void changePasswordChanged(bool changePassword);

private:
    QString m_userFirstname, m_userLastname, m_userUsername, m_userPhoneNo, m_userPassword, m_userDateAdded;

    bool m_canAddUsers, m_canRemoveUsers, m_canAddItems, m_canRemoveItems, m_canAddStock, m_canRemoveStock, m_canUndoSales, m_canBackupDb, m_changePassword;
};

#endif // USERACCOUNTS_H
