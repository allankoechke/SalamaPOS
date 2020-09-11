#include "useraccountsmodel.h"

UserAccountsModel::UserAccountsModel(QObject *parent) : QAbstractListModel(parent)
{

}

int UserAccountsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)

    return mUserAccounts.size();
}

QVariant UserAccountsModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() > mUserAccounts.count())
        return QVariant();

    UserAccounts * accounts = mUserAccounts.at(index.row());

    if(role == UserFirstnameRole)
        return accounts->userFirstname();

    if(role == UserLastnameRole)
        return accounts->userLastname();

    if(role == UserUsernameRole)
        return accounts->userUsername();

    if(role == UserPhoneNoRole)
        return accounts->userPhoneNo();

    if(role == UserPasswordRole)
        return accounts->userPassword();

    if(role == UserDateAddedRole)
        return accounts->userDateAdded();

    if(role == CanAddUsersRole)
        return accounts->canAddUsers();

    if(role == CanRemoveUsersRole)
        return accounts->canRemoveUsers();

    if(role == CanAddItemsRole)
        return accounts->canAddItems();

    if(role == CanRemoveItemsRole)
        return accounts->canRemoveItems();

    if(role == CanAddStockRole)
        return accounts->canAddStock();

    if(role == CanRemoveStockRole)
        return accounts->canRemoveStock();

    if(role == CanUndoSalesRole)
        return accounts->canUndoSales();

    if(role == CanBackupDbRole)
        return accounts->canBackupDb();

    if(role == ChangePasswordRole)
        return accounts->changePassword();

    else return QVariant();
}

bool UserAccountsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    UserAccounts * accounts = mUserAccounts.at(index.row());
    bool changed = false;

    switch (role)
    {
    case UserFirstnameRole:
    {
        if( accounts->userFirstname() != value.toString())
        {
            accounts->setUserFirstname(value.toString());
            changed = true;
        }

        break;
    }

    case UserLastnameRole:
    {
        if( accounts->userLastname() != value.toString())
        {
            accounts->setUserLastname(value.toString());
            changed = true;
        }

        break;
    }

    case UserUsernameRole:
    {
        if( accounts->userUsername() != value.toString())
        {
            accounts->setUserUsername(value.toString());
            changed = true;
        }

        break;
    }

    case UserPhoneNoRole:
    {
        if( accounts->userPhoneNo() != value.toString())
        {
            accounts->setUserPhoneNo(value.toString());
            changed = true;
        }

        break;
    }

    case UserPasswordRole:
    {
        if( accounts->userPassword() != value.toString())
        {
            accounts->setUserPassword(value.toString());
            changed = true;
        }

        break;
    }


    case UserDateAddedRole:
    {
        if( accounts->userDateAdded() != value.toString())
        {
            accounts->setUserDateAdded(value.toString());
            changed = true;
        }

        break;
    }

    case CanAddUsersRole:
    {
        if( accounts->canAddUsers() != value.toBool())
        {
            accounts->setCanAddUsers(value.toBool());
            changed = true;
        }

        break;
    }

    case CanRemoveUsersRole:
    {
        if( accounts->canRemoveUsers() != value.toBool())
        {
            accounts->setCanRemoveUsers(value.toBool());
            changed = true;
        }

        break;
    }

    case CanAddItemsRole:
    {
        if( accounts->canAddItems() != value.toBool())
        {
            accounts->setCanAddItems(value.toBool());
            changed = true;
        }

        break;
    }

    case CanRemoveItemsRole:
    {
        if( accounts->canRemoveItems() != value.toBool())
        {
            accounts->setCanRemoveItems(value.toBool());
            changed = true;
        }

        break;
    }

    case CanAddStockRole:
    {
        if( accounts->canAddStock() != value.toBool())
        {
            accounts->setCanAddStock(value.toBool());
            changed = true;
        }

        break;
    }

    case CanRemoveStockRole:
    {
        if( accounts->canRemoveStock() != value.toBool())
        {
            accounts->setCanRemoveStock(value.toBool());
            changed = true;
        }

        break;
    }

    case CanUndoSalesRole:
    {
        if( accounts->canUndoSales() != value.toBool())
        {
            accounts->setCanUndoSales(value.toBool());
            changed = true;
        }

        break;
    }

    case CanBackupDbRole:
    {
        if( accounts->canBackupDb() != value.toBool())
        {
            accounts->setCanBackupDb(value.toBool());
            changed = true;
        }

        break;
    }

    case ChangePasswordRole:
    {
        if( accounts->changePassword() != value.toBool())
        {
            accounts->setChangePassword(value.toBool());
            changed = true;
        }

        break;
    }

    }

    if(changed)
    {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }

    return false;
}

Qt::ItemFlags UserAccountsModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> UserAccountsModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[UserFirstnameRole] = "user_fname";
    roles[UserLastnameRole] = "user_lname";
    roles[UserUsernameRole] = "user_username";
    roles[UserPhoneNoRole] = "user_phoneNo";
    roles[UserPasswordRole] = "user_password";
    roles[UserDateAddedRole] = "date_added";
    roles[CanAddUsersRole] = "can_addUsers";
    roles[CanRemoveUsersRole] = "can_removeUsers";
    roles[CanAddItemsRole] = "can_addProducts";
    roles[CanRemoveItemsRole] = "can_removeProducts";
    roles[CanAddStockRole] = "can_addStock";
    roles[CanRemoveStockRole] = "can_removeStock";
    roles[CanUndoSalesRole] = "can_undoSales";
    roles[CanBackupDbRole] = "can_backup";
    roles[ChangePasswordRole] = "to_changePassword";

    return roles;
}

void UserAccountsModel::addNewUserAccount(const QVariant &userFirstname, const QVariant &userLastname, const QVariant &userUsername, const QVariant &userPassword, const QVariant &userPhoneNo, const QVariant &userDateAdded)
{
    QSqlDatabase m_db = QSqlDatabase::database();
}

void UserAccountsModel::updatePassword(const QVariant &userUsername, const QVariant &userPassword)
{

}

void UserAccountsModel::removeUserAccount(QVariant index)
{

}

void UserAccountsModel::updateUserAccount(const QVariant &userFirstname, const QVariant &userLastname, const QVariant &userUsername, const QVariant &userPhoneNo, const QVariant &userDateAdded)
{

}

void UserAccountsModel::addNewUserAccount(UserAccounts *user)
{
    const int index = mUserAccounts.size();

    beginInsertRows(QModelIndex(), index, index);
    mUserAccounts.append(user);
    endInsertRows();
}

void UserAccountsModel::removeUserAccount(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    mUserAccounts.removeAt(index);
    endRemoveRows();
}
