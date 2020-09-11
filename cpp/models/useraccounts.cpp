#include "useraccounts.h"

UserAccounts::UserAccounts(QObject *parent) : QObject(parent)
{

}

UserAccounts::UserAccounts(const QString &userFirstname, const QString &userLastname, const QString &userUsername, const QString &userPhoneNo, const QString &userPassword, const QString &userDateAdded, const bool &canAddUsers, const bool &canRemoveUsers, const bool &canAddItems, const bool &canRemoveItems, const bool &canAddStock, const bool &canRemoveStock, const bool &canUndoSales, const bool &canBackupDb, const bool &changePassword, QObject *parent)
    :QObject(parent), m_userFirstname(userFirstname), m_userLastname(userLastname), m_userUsername(userUsername), m_userPhoneNo(userPhoneNo), m_userPassword(userPassword), m_userDateAdded(userDateAdded), m_canAddUsers(canAddUsers), m_canRemoveUsers(canRemoveUsers), m_canAddItems(canAddItems), m_canRemoveItems(canRemoveItems), m_canAddStock(canAddStock), m_canRemoveStock(canRemoveStock), m_canUndoSales(canUndoSales), m_canBackupDb(canBackupDb), m_changePassword(changePassword)
{

}

QString UserAccounts::userFirstname() const
{
    return m_userFirstname;
}

QString UserAccounts::userLastname() const
{
    return m_userLastname;
}

QString UserAccounts::userUsername() const
{
    return m_userUsername;
}

QString UserAccounts::userPhoneNo() const
{
    return m_userPhoneNo;
}

QString UserAccounts::userPassword() const
{
    return m_userPassword;
}

QString UserAccounts::userDateAdded() const
{
    return m_userDateAdded;
}

bool UserAccounts::canAddUsers() const
{
    return m_canAddUsers;
}

bool UserAccounts::canRemoveUsers() const
{
    return m_canRemoveUsers;
}

bool UserAccounts::canAddItems() const
{
    return m_canAddItems;
}

bool UserAccounts::canRemoveItems() const
{
    return m_canRemoveItems;
}

bool UserAccounts::canAddStock() const
{
    return m_canAddStock;
}

bool UserAccounts::canRemoveStock() const
{
    return m_canRemoveStock;
}

bool UserAccounts::canUndoSales() const
{
    return m_canUndoSales;
}

bool UserAccounts::canBackupDb() const
{
    return m_canBackupDb;
}

bool UserAccounts::changePassword() const
{
    return m_changePassword;
}

void UserAccounts::setUserFirstname(QString userFirstname)
{
    if (m_userFirstname == userFirstname)
        return;

    m_userFirstname = userFirstname;
    emit userFirstnameChanged(m_userFirstname);
}

void UserAccounts::setUserLastname(QString userLastname)
{
    if (m_userLastname == userLastname)
        return;

    m_userLastname = userLastname;
    emit userLastnameChanged(m_userLastname);
}

void UserAccounts::setUserUsername(QString userUsername)
{
    if (m_userUsername == userUsername)
        return;

    m_userUsername = userUsername;
    emit userUsernameChanged(m_userUsername);
}

void UserAccounts::setUserPhoneNo(QString userPhoneNo)
{
    if (m_userPhoneNo == userPhoneNo)
        return;

    m_userPhoneNo = userPhoneNo;
    emit userPhoneNoChanged(m_userPhoneNo);
}

void UserAccounts::setUserPassword(QString userPassword)
{
    if (m_userPassword == userPassword)
        return;

    m_userPassword = userPassword;
    emit userPasswordChanged(m_userPassword);
}

void UserAccounts::setUserDateAdded(QString userDateAdded)
{
    if (m_userDateAdded == userDateAdded)
        return;

    m_userDateAdded = userDateAdded;
    emit userDateAddedChanged(m_userDateAdded);
}

void UserAccounts::setCanAddUsers(bool canAddUsers)
{
    if (m_canAddUsers == canAddUsers)
        return;

    m_canAddUsers = canAddUsers;
    emit canAddUsersChanged(m_canAddUsers);
}

void UserAccounts::setCanRemoveUsers(bool canRemoveUsers)
{
    if (m_canRemoveUsers == canRemoveUsers)
        return;

    m_canRemoveUsers = canRemoveUsers;
    emit canRemoveUsersChanged(m_canRemoveUsers);
}

void UserAccounts::setCanAddItems(bool canAddItems)
{
    if (m_canAddItems == canAddItems)
        return;

    m_canAddItems = canAddItems;
    emit canAddItemsChanged(m_canAddItems);
}

void UserAccounts::setCanRemoveItems(bool canRemoveItems)
{
    if (m_canRemoveItems == canRemoveItems)
        return;

    m_canRemoveItems = canRemoveItems;
    emit canRemoveItemsChanged(m_canRemoveItems);
}

void UserAccounts::setCanAddStock(bool canAddStock)
{
    if (m_canAddStock == canAddStock)
        return;

    m_canAddStock = canAddStock;
    emit canAddStockChanged(m_canAddStock);
}

void UserAccounts::setCanRemoveStock(bool canRemoveStock)
{
    if (m_canRemoveStock == canRemoveStock)
        return;

    m_canRemoveStock = canRemoveStock;
    emit canRemoveStockChanged(m_canRemoveStock);
}

void UserAccounts::setCanUndoSales(bool canUndoSales)
{
    if (m_canUndoSales == canUndoSales)
        return;

    m_canUndoSales = canUndoSales;
    emit canUndoSalesChanged(m_canUndoSales);
}

void UserAccounts::setCanBackupDb(bool canBackupDb)
{
    if (m_canBackupDb == canBackupDb)
        return;

    m_canBackupDb = canBackupDb;
    emit canBackupDbChanged(m_canBackupDb);
}

void UserAccounts::setChangePassword(bool changePassword)
{
    if (m_changePassword == changePassword)
        return;

    m_changePassword = changePassword;
    emit changePasswordChanged(m_changePassword);
}
