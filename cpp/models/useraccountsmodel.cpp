#include "useraccountsmodel.h"

UserAccountsModel::UserAccountsModel(QObject *parent) : QAbstractListModel(parent)
{

    QFile file(":/json/logged_user.json");
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QString jsonString = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8());
    m_loggedInUser = doc.object();
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
    if(getUserIndex(userUsername.toString()) != -1)
    {
        emit usernameExistsChanged(true);
        qDebug() << ">> Duplicate username ...";
    }

    else
    {
        QSqlDatabase m_db = QSqlDatabase::database();

        QString txt = userDateAdded.toString();
        QDateTime dt = QDateTime::fromMSecsSinceEpoch(txt.toLong(), Qt::OffsetFromUTC);
        QString item =  dt.toString(Qt::ISODateWithMs);

        QString password = hashPassword(userPassword.toString());

        if(m_db.isOpen())
        {
            QSqlQuery query;
            query.prepare("INSERT INTO \"users\"(firstname,lastname,username,password,phone_no,date_added) VALUES (:firstname,:lastname,:username,:password,:phone_no,:date_added)");
            query.bindValue(":firstname", userFirstname.toString());
            query.bindValue(":lastname", userLastname.toString());
            query.bindValue(":username", userUsername.toString());
            query.bindValue(":password", password);
            query.bindValue(":phone_no", userPhoneNo.toString());
            query.bindValue(":date_added", item);

            QSqlQuery priviledges_query;
            priviledges_query.prepare("INSERT INTO \"priviledges\"(username) VALUES (:username)");
            priviledges_query.bindValue(":username", userUsername.toString());

            if(query.exec() && priviledges_query.exec())
            {
                m_db.commit();
                qDebug() << ">> New User Added";

                addNewUserAccount(new UserAccounts(userFirstname.toString(), userLastname.toString(), userUsername.toString(), userPhoneNo.toString(), password, item, true, false, true, false, true, false, false, false, false));

                emit userAddedChanged(true);

            }

            else
            {
                m_db.rollback();

                emit userAddedChanged(false);

                qDebug() << "Error executing SQL: " << query.lastError().text() << " :: " << priviledges_query.lastError().text();
            }
        }
    }
}

void UserAccountsModel::updatePassword(const QVariant &userUsername, const QVariant &userPassword)
{
    QSqlDatabase m_db = QSqlDatabase::database();

    QString password = hashPassword(userPassword.toString());

    int index = getUserIndex(userUsername.toString());

    if(index != -1)
    {
        if(m_db.isOpen())
        {
            QSqlQuery query;
            query.prepare("UPDATE \"users\" set password=:password WHERE username=:username");
            query.bindValue(":password", password);
            query.bindValue(":username", userUsername.toString());

            if(query.exec())
            {
                m_db.commit();
                qDebug() << ">> User Updated";

                setData(this->index(index), QVariant::fromValue(password), UserPasswordRole);

                emit userPasswordChanged(true);
            }

            else
            {
                m_db.rollback();

                emit userPasswordChanged(false);

                qDebug() << "Error executing SQL: " << query.lastError().text();
            }
        }
    }

    else
        qDebug() << ">> User index could not be found ...";
}

void UserAccountsModel::removeUserAccount(const QVariant &userUsername, QVariant index)
{
    QSqlDatabase m_db = QSqlDatabase::database();

    if(m_db.isOpen())
    {
        QSqlQuery query;
        query.prepare("DELETE FROM \"users\" WHERE username=:username");
        query.bindValue(":username", userUsername.toString());

        if(query.exec())
        {
            m_db.commit();
            qDebug() << ">> New User Deleted";

            removeUserAccount(index.toString().toInt());

            emit userRemovedChanged(true);

        }

        else
        {
            m_db.rollback();

            emit userRemovedChanged(false);

            qDebug() << "Error executing SQL: " << query.lastError().text();
        }
    }
}

void UserAccountsModel::updateUserAccount(const QVariant &userFirstname, const QVariant &userLastname, const QVariant &userUsername, const QVariant &userPhoneNo, const QVariant &orig_username)
{
    if(userUsername != orig_username && getUserIndex(userUsername.toString()) != -1)
        emit usernameExistsChanged(true);

    else
    {
        QSqlDatabase m_db = QSqlDatabase::database();

        int index_ = getUserIndex(userUsername.toString());

        if(index_ != -1)
            if(m_db.isOpen())
            {
                QSqlQuery query;
                query.prepare("UPDATE \"users\" SET firstname=:firstname,lastname=:lastname,username=:username,phone_no=:phone_no WHERE username=:orig_username");
                query.bindValue(":firstname", userFirstname.toString());
                query.bindValue(":lastname", userLastname.toString());
                query.bindValue(":username", userUsername.toString());
                query.bindValue(":phone_no", userPhoneNo.toString());
                query.bindValue(":orig_username", orig_username.toString());

                if(query.exec())
                {
                    m_db.commit();
                    qDebug() << ">> User Details updated";

                    setData(this->index(index_), userFirstname, UserFirstnameRole);
                    setData(this->index(index_), userLastname, UserLastnameRole);
                    setData(this->index(index_), userUsername, UserUsernameRole);
                    setData(this->index(index_), userPhoneNo, UserPhoneNoRole);

                    emit userUpdatedChanged(true);

                    if(m_loggedInUser.value("username").toString() == orig_username.toString())
                    {
                        m_loggedInUser["firstname"] = data(this->index(index_), UserFirstnameRole).toString();
                        m_loggedInUser["lastname"] = data(this->index(index_), UserLastnameRole).toString();
                        m_loggedInUser["username"] = data(this->index(index_), UserUsernameRole).toString();
                        m_loggedInUser["phone_no"] = data(this->index(index_), UserPhoneNoRole).toString();

                        emit loggedInUserChanged();
                    }

                }

                else
                {
                    m_db.rollback();

                    emit userUpdatedChanged(false);

                    qDebug() << "Error executing SQL: " << query.lastError().text();
                }
            }

            else
                qDebug() << "Index not found! ";

        else
            qDebug() << "Index not found! ";
    }
}

void UserAccountsModel::updateUserAccount(const QVariant &userUsername, const bool &canAddUsers, const bool &canRemoveUsers, const bool &canAddItems, const bool &canRemoveItems, const bool &canAddStock, const bool &canRemoveStock, const bool &canUndoSales, const bool &canBackupDb)
{
    int index_ = getUserIndex(userUsername.toString());

    if(index_ == -1)
        emit userPriviledgesChanged(false);

    else
    {
        QSqlDatabase m_db = QSqlDatabase::database();

        if(m_db.isOpen())
        {
            QSqlQuery query;
            query.prepare("UPDATE priviledge SET can_add_user=:can_add_user,can_remove_user=:can_remove_user,can_add_product=:can_add_product,can_remove_product=:can_remove_product, can_add_stock=:can_add_stock,can_remove_stock=:can_remove_stock,can_remove_sales=:can_remove_sales,can_backup=:can_backup WHERE username=:username");
            query.bindValue(":can_add_user", canAddUsers);
            query.bindValue(":can_remove_user", canRemoveUsers);
            query.bindValue(":can_add_product", canAddItems);
            query.bindValue(":can_remove_product", canRemoveItems);
            query.bindValue(":can_add_stock", canAddStock);
            query.bindValue(":can_remove_stock", canRemoveStock);
            query.bindValue(":can_remove_sales", canUndoSales);
            query.bindValue(":can_backup", canBackupDb);
            query.bindValue(":username", userUsername.toString());

            qDebug() << canAddItems;

            if(query.exec())
            {
                m_db.commit();
                qDebug() << ">> User Priviledges updated";

                setData(this->index(index_), canAddUsers, CanAddUsersRole);
                setData(this->index(index_), canRemoveUsers, CanRemoveUsersRole);
                setData(this->index(index_), canAddItems, CanAddItemsRole);
                setData(this->index(index_), canRemoveItems, CanRemoveItemsRole);
                setData(this->index(index_), canAddStock, CanAddStockRole);
                setData(this->index(index_), canRemoveStock, CanRemoveStockRole);
                setData(this->index(index_), canUndoSales, CanUndoSalesRole);
                setData(this->index(index_), canBackupDb, CanBackupDbRole);

                emit userPriviledgesChanged(true);

                if(m_loggedInUser.value("username").toString() == userUsername.toString())
                {
                    m_loggedInUser["canAddUser"] = data(this->index(index_), CanAddUsersRole).toString();
                    m_loggedInUser["canRemoveUsers"] = data(this->index(index_), CanRemoveUsersRole).toString();
                    m_loggedInUser["canAddItems"] = data(this->index(index_), CanAddItemsRole).toString();
                    m_loggedInUser["canRemoveItems"] = data(this->index(index_), CanRemoveItemsRole).toString();
                    m_loggedInUser["canAddStock"] = data(this->index(index_), CanAddStockRole).toString();
                    m_loggedInUser["canRemoveStock"] = data(this->index(index_), CanRemoveStockRole).toString();
                    m_loggedInUser["canUndoSales"] = data(this->index(index_), CanUndoSalesRole).toString();
                    m_loggedInUser["canBackupDb"] = data(this->index(index_), CanBackupDbRole).toString();

                    emit loggedInUserChanged();
                }
            }

            else
            {
                emit userPriviledgesChanged(false);

                qDebug() << "Error executing SQL: " << query.lastError().text() << " :: " << query.executedQuery();
            }
        }
    }
}

void UserAccountsModel::markAccountForDeleting(const QVariant &userUsername)
{
    QSqlDatabase m_db = QSqlDatabase::database();

    int index = getUserIndex(userUsername.toString());

    if(index != -1)
    {
        if(m_db.isOpen())
        {
            QSqlQuery query;
            query.prepare("UPDATE \"users\" set to_delete_account=:to_delete_account WHERE username=:username");
            query.bindValue(":to_delete_account", true);
            query.bindValue(":username", userUsername.toString());

            if(query.exec())
            {
                m_db.commit();

                qDebug() << ">> To delete Account Updated";

                removeUserAccount(index);

                emit toDeleteAccountChanged(true);
            }

            else
            {
                m_db.rollback();

                emit toDeleteAccountChanged(false);

                qDebug() << "Error executing SQL: " << query.lastError().text();
            }
        }
    }

    else
        qDebug() << ">> User index could not be found ...";
}

void UserAccountsModel::loadAllUserAccounts()
{
    QSqlDatabase m_db = QSqlDatabase::database();

    if(m_db.isOpen())
    {
        QSqlQuery query;
        const QString sql = "SELECT firstname,lastname,users.username,password,phone_no,date_added, can_add_user, can_remove_user, can_add_product,\
                can_remove_product, can_add_stock, can_remove_stock, can_remove_sales, can_backup, to_change_password FROM \"users\" INNER \
                JOIN \"priviledges\" ON users.username = priviledges.username";


        if(query.exec(sql))
        {
            while(query.next())
            {
                QString userFirstName = query.value(0).toString();
                QString userLastname = query.value(1).toString();
                QString userUsername = query.value(2).toString();
                QString password = query.value(3).toString();
                QString userPhoneNo = query.value(4).toString();
                QString userDateAdded = query.value(5).toString();
                bool canAddUsers = query.value(6).toBool();
                bool canRemoveUsers = query.value(7).toBool();
                bool canAddItems = query.value(8).toBool();
                bool canRemoveItems = query.value(9).toBool();
                bool canAddStock = query.value(10).toBool();
                bool canRemoveStock = query.value(11).toBool();
                bool canUndoSales = query.value(12).toBool();
                bool canBackupDb = query.value(13).toBool();
                bool changePassword = query.value(14).toBool();

                addNewUserAccount(new UserAccounts(userFirstName, userLastname, userUsername, userPhoneNo, password, userDateAdded, canAddUsers, canRemoveUsers, canAddItems, canRemoveItems, canAddStock, canRemoveStock, canUndoSales, canBackupDb,changePassword));

            }
            emit userAccountsLoaded(true);

        }

        else
        {
            emit userAccountsLoaded(false);

            qDebug() << "Error executing SQL: " << query.lastError().text();
        }
    }
}

void UserAccountsModel::loginUser(const QVariant &uname, const QVariant &pswd)
{
    const int ind = getUserIndex(uname.toString());

    if(ind == -1)
    {
        loggingInUsernameStatus(false);

        qDebug() << ">> User not in the database";
    }

    else
    {
        loggingInUsernameStatus(true);

        QString savedP = data(this->index(ind), UserPasswordRole).toString();

        if(login(savedP, pswd.toString()))
        {
            emit loggingInPasswordStatus(true);

            m_loggedInUser["firstname"] = data(this->index(ind), UserFirstnameRole).toString();
            m_loggedInUser["lastname"] = data(this->index(ind), UserLastnameRole).toString();
            m_loggedInUser["username"] = data(this->index(ind), UserUsernameRole).toString();
            m_loggedInUser["phone_no"] = data(this->index(ind), UserPhoneNoRole).toString();
            m_loggedInUser["canAddUser"] = data(this->index(ind), CanAddUsersRole).toBool();
            m_loggedInUser["canRemoveUsers"] = data(this->index(ind), CanRemoveUsersRole).toBool();
            m_loggedInUser["canAddItems"] = data(this->index(ind), CanAddItemsRole).toBool();
            m_loggedInUser["canRemoveItems"] = data(this->index(ind), CanRemoveItemsRole).toBool();
            m_loggedInUser["canAddStock"] = data(this->index(ind), CanAddStockRole).toBool();
            m_loggedInUser["canRemoveStock"] = data(this->index(ind), CanRemoveStockRole).toBool();
            m_loggedInUser["canUndoSales"] = data(this->index(ind), CanUndoSalesRole).toBool();
            m_loggedInUser["canBackupDb"] = data(this->index(ind), CanBackupDbRole).toBool();

            QJsonDocument doc(m_loggedInUser);

            emit loggedInUserChanged();
        }

        else
        {
            emit loggingInPasswordStatus(false);

            qDebug() << ">> Wrong User password";
        }
    }
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

QString UserAccountsModel::hashPassword(const QString &pswd)
{
    QString salt = QString::number(QDateTime::currentSecsSinceEpoch());
    qDebug() << "Salt: " << salt << " :: " << salt.toUtf8();
    QCryptographicHash hash(QCryptographicHash::Sha3_256);
    hash.addData(pswd.toUtf8() + salt.toUtf8());
    return hash.result().toHex()+":"+salt;
}

bool UserAccountsModel::login(const QString &savedPswd, const QString &inputPswd)
{
    QString _pswd = savedPswd.split(":").at(0);
    QString _salt = savedPswd.split(":").at(1);

    QCryptographicHash hash(QCryptographicHash::Sha3_256);
    hash.addData(inputPswd.toUtf8() + _salt.toUtf8());

    if(hash.result().toHex() == _pswd)
        return true;

    else
        return false;
}

int UserAccountsModel::getUserIndex(const QString &username)
{
    QString _username;

    for(int i=0; i<mUserAccounts.size(); i++)
    {
        _username = data(this->index(i), UserUsernameRole).toString();

        if(username == _username)
            return i;
    }

    return -1;
}

QJsonObject UserAccountsModel::loggedInUser() const
{
    return m_loggedInUser;
}

void UserAccountsModel::setLoggedInUser(QJsonObject loggedInUser)
{
    if (m_loggedInUser == loggedInUser)
        return;

    m_loggedInUser = loggedInUser;
    emit loggedInUserChanged(m_loggedInUser);
}
