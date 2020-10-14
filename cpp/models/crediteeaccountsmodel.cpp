#include "crediteeaccountsmodel.h"

CrediteeAccountsModel::CrediteeAccountsModel(QObject *parent) : QAbstractListModel(parent)
{
    dateTime = new DateTime();
}

int CrediteeAccountsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_crediteeAccount.size();
}

QVariant CrediteeAccountsModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() > m_crediteeAccount.count())
        return QVariant();

    CrediteeAccount * creditee = m_crediteeAccount.at(index.row());

    if(role == FirstNameRole)
        return creditee->firstName();

    if(role == LastNameRole)
        return creditee->lastName();

    if(role == MobileNoRole)
        return creditee->mobileNo();

    if(role == IdNoRole)
        return creditee->idNo();

    if(role == DebtAmountRole)
        return creditee->debtAmount();

    else return QVariant();
}

bool CrediteeAccountsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    CrediteeAccount * creditee = m_crediteeAccount.at(index.row());
    bool changed = false;

    switch (role)
    {
    case FirstNameRole:
    {
        if( creditee->firstName() != value.toString())
        {
            creditee->setFirstName(value.toString());
            changed = true;
        }

        break;
    }

    case LastNameRole:
    {
        if( creditee->lastName() != value.toString())
        {
            creditee->setLastName(value.toString());
            changed = true;
        }

        break;
    }

    case IdNoRole:
    {
        if( creditee->idNo() != value.toString())
        {
            creditee->setIdNo(value.toString());
            changed = true;
        }

        break;
    }

    case MobileNoRole:
    {
        if( creditee->mobileNo() != value.toString())
        {
            creditee->setMobileNo(value.toString());
            changed = true;
        }

        break;
    }

    case DebtAmountRole:
    {
        if( creditee->debtAmount() != value.toString().toInt())
        {
            creditee->setDebtAmount(value.toString().toInt());
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

Qt::ItemFlags CrediteeAccountsModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> CrediteeAccountsModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[FirstNameRole] = "c_fname";
    roles[LastNameRole] = "c_lname";
    roles[MobileNoRole] = "c_mobile";
    roles[IdNoRole] = "c_idNo";
    roles[DebtAmountRole] = "c_debt";

    return roles;
}

void CrediteeAccountsModel::addNewCreditee(const QString &fname, const QString &lname, const QString &mobile, const QString &idNo)
{
    QSqlDatabase db = QSqlDatabase::database();

    if(getIndex(idNo) != -1)
        emit idExists();

    else
        if(db.isOpen())
        {
            QString dateToday = dateTime->getTimestamp("now").at(0);
            QString sql = "INSERT INTO creditee(firstname,lastname,national_id,phone_no,amount_due,date_added) VALUES('" + fname + "','" + lname + "','" + idNo + "','" + mobile + "','0','" + dateToday + "');";
            QSqlQuery query;

            if(query.exec(sql))
            {
                qDebug() << " [INFO] Creditee user added to database";

                addNewCreditee(new CrediteeAccount(fname, lname, mobile, idNo, 0));

                emit crediteeAdded(true);
            }

            else
            {
                qDebug() << " [ERROR] Could't execute SQL (" << query.executedQuery() << ") : " << query.lastError().text();
                crediteeAdded(false);
            }
        }

        else
        {
            qDebug() << " [ERROR] Database not open!";
            emit crediteeAdded(false);
        }
}

void CrediteeAccountsModel::updateCreditee(const QString &fname, const QString &lname, const QString &mobile, const QString &idNo, const QString &orig_id)
{
    QSqlDatabase db = QSqlDatabase::database();

    if(idNo != orig_id && getIndex(idNo) != -1)
        emit idExists();

    else
        if(db.isOpen())
        {
            QString sql = "UPDATE creditee set firstname='" + fname + "',lastname='" + lname + "',national_id='" + idNo + "',phone_no='" + mobile + "' WHERE national_id='" + orig_id + "';";
            QSqlQuery query;


            if(query.exec(sql))
            {
                qDebug() << " [INFO] Creditee user updated in the database";

                int index = getIndex(orig_id);

                setData(this->index(index), QVariant::fromValue(fname), FirstNameRole);
                setData(this->index(index), QVariant::fromValue(lname), LastNameRole);
                setData(this->index(index), QVariant::fromValue(mobile), MobileNoRole);
                setData(this->index(index), QVariant::fromValue(idNo), IdNoRole);

                emit crediteeUpdated(true);
            }

            else
            {
                qDebug() << " [ERROR] Could't execute SQL (" << query.executedQuery() << ") : " << query.lastError().text();
                crediteeUpdated(false);
            }
        }

        else
        {
            qDebug() << " [ERROR] Database not open!";
            emit crediteeUpdated(false);
        }
}

void CrediteeAccountsModel::loadCrediteeAccounts()
{
    QSqlDatabase db = QSqlDatabase::database();

    if(db.isOpen())
    {
        QString dateToday = dateTime->getTimestamp("now").at(0);
        QString sql = "SELECT firstname,lastname,national_id,phone_no,amount_due FROM creditee;";
        QSqlQuery query;

        if(query.exec(sql))
        {

            while (query.next()) {
                QString fname = query.value(0).toString();
                QString lname = query.value(1).toString();
                QString idNo = query.value(2).toString();
                QString mobile = query.value(3).toString();
                int due = query.value(4).toInt();

                addNewCreditee(new CrediteeAccount(fname, lname, mobile, idNo, due));
            }

            qDebug() << " [INFO] Creditee user Accounts loaded";
        }

        else
        {
            qDebug() << " [ERROR] Could't execute SQL (" << query.executedQuery() << ") : " << query.lastError().text();
        }
    }

    else
    {
        qDebug() << " [ERROR] Database not open!";
    }
}

void CrediteeAccountsModel::getPaymentHistory(const QString &idNo)
{
    QSqlDatabase db = QSqlDatabase::database();

    if(db.isOpen())
    {
        QString sql = "SELECT payment_timestamp,payment_amount ,payment_due FROM credit_payments WHERE creditee_id = '" + idNo + "';";
        QSqlQuery query;

        if(query.exec(sql))
        {

            while (query.next()) {
                QString date = query.value(0).toString();
                int paid = query.value(1).toInt();
                int due = query.value(2).toInt();

                emit paymentReceived(date, paid, due);
            }

            qDebug() << " [INFO] Creditee user Accounts loaded";
        }

        else
        {
            qDebug() << " [ERROR] Could't execute SQL (" << query.executedQuery() << ") : " << query.lastError().text();
        }
    }

    else
    {
        qDebug() << " [ERROR] Database not open!";
    }
}

bool CrediteeAccountsModel::repayDebt(const QString &crediteeId, const int &debt, const int &debtPaid)
{
    QSqlDatabase db = QSqlDatabase::database();

    int due = (debt-debtPaid <= 0)? 0:debt-debtPaid;
    int paid = debtPaid > debt ? debt:debtPaid;
    QString dateToday = dateTime->getTimestamp("now").at(0);

    if(db.isOpen())
    {
        QString sql = "UPDATE creditee "; //"SET amount_due = " + " WHERE national_id = '"+crediteeId+"';";
        QString sql2 = "INSERT INTO credit_payments(payment_timestamp,creditee_id,payment_amount,payment_due) VALUES ('"+dateToday+"','"+crediteeId+"','"+paid+"','"+due+"') ;";

        QSqlQuery query;

        if(query.exec(sql))
        {

            while (query.next()) {
                QString date = query.value(0).toString();
                int paid = query.value(1).toInt();
                int due = query.value(2).toInt();

                emit paymentReceived(date, paid, due);
            }

            qDebug() << " [INFO] Creditee user Accounts loaded";
        }

        else
        {
            qDebug() << " [ERROR] Could't execute SQL (" << query.executedQuery() << ") : " << query.lastError().text();
        }
    }

    else
    {
        qDebug() << " [ERROR] Database not open!";
    }
}

void CrediteeAccountsModel::addNewCreditee(CrediteeAccount *creditee)
{
    const int index = m_crediteeAccount.size();

    beginInsertRows(QModelIndex(), index, index);
    m_crediteeAccount.append(creditee);
    endInsertRows();
}

void CrediteeAccountsModel::removeCreditee(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_crediteeAccount.removeAt(index);
    endRemoveRows();
}

int CrediteeAccountsModel::getIndex(QVariant id)
{
    for(int i=0; i<m_crediteeAccount.size()-1; i++)
    {
        QVariant _id = data(this->index(i), IdNoRole);

        if(id == _id)
            return i;
    }

    return -1;
}
