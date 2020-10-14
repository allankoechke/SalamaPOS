#include "qmlinterface.h"

QmlInterface::QmlInterface(QObject *parent) : QObject(parent)
{
    // QVariantMap configurations=QJsonDocument::fromJson(file.readAll()).toVariant().toMap();

    qApp->setApplicationName("Salama P.O.S.");
    qApp->setApplicationVersion("1.0.1");
    qApp->setApplicationDisplayName("Salama P.O.S.");
    qApp->setOrganizationName("lalanke");
    qApp->setWindowIcon(QIcon(":/assets/images/6.png"));
    qApp->setOrganizationDomain("lalanke.com");

    m_settings = new QSettings(qApp->organizationName(),qApp->applicationDisplayName());

    setIsDarkTheme(m_settings->value("Theme/isDarkTheme", false).toBool());

    m_databaseInterface = new DatabaseInterface(parent);
    m_dateTime = new DateTime();

    bool status = m_databaseInterface->initializeDatabase();

    if(status)
    {
        emit databaseReadyChanged();
    }

    // Set default max
    setPlotYmax(10);
}

QJsonObject QmlInterface::getScreenSize()
{
    QJsonDocument doc = QJsonDocument::fromVariant("{ \"width\":0, \"height\":0}");
    QJsonObject size = doc.object();

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int height = screenGeometry.height();
    int width = screenGeometry.width();

    size["width"] = width;
    size["height"] = height;

    return size;
}

void QmlInterface::fetchSavedSettings()
{
    setIsDarkTheme(m_settings->value("Theme/isDarkTheme", false).toBool());

    setTablesCreated(m_settings->value("Config/isTablesCreated", false).toBool());
    setProductsAdded(m_settings->value("Config/isProductsAdded", false).toBool());
    setProductTypeAdded(m_settings->value("Config/isProductTypeAdded", false).toBool());
    setProductStockAdded(m_settings->value("Config/isProductStockAdded", false).toBool());
}

void QmlInterface::getSalesStatisticsForDashboard()
{
    // Get the sales quantities and cost for the day!
    QSqlDatabase db = QSqlDatabase::database();

    if(db.isOpen())
    {
        QSqlQuery query;
        auto dateToday = m_dateTime->getTimestamp("today");
        QString sql = "SELECT product_sp,sale_qty from sales WHERE sales_date > '" +dateToday.at(0)+ "' AND sales_date < '" + dateToday.at(1) + "'";

        int counter = 0, totals = 0;

        if(query.exec(sql))
        {
            while(query.next())
            {
                int sp = query.value(0).toInt();
                int qty = query.value(1).toInt();

                totals += sp * qty;
                counter += qty;
            }

            setSalesCost(totals);
            setSalesNumbers(counter);
        }

        else
        {
            qDebug() << "Error fetchin data from the database: [" << query.executedQuery() << "] -> " << query.lastError().text();
        }
    }
}

void QmlInterface::getMessagesStatisticsForDashboard(const QString &uname)
{
    // Get messages (sent, received, pending) for the current logged user
    QSqlDatabase db = QSqlDatabase::database();

    if(db.isOpen())
    {
        QSqlQuery query;
        auto dateToday = m_dateTime->getTimestamp("today");
        QString sql = "SELECT has_read from messages WHERE receiver = '" + uname + "';";
        QString sql2 = "SELECT * from messages WHERE sender = '" + uname + "';";

        int sent = 0, received = 0, pending = 0;

        if(query.exec(sql))
        {
            while(query.next())
            {
                int hasRead = query.value(0).toBool();

                if(!hasRead)
                    pending += 1;

                received += 1;
            }

            setReceivedMessages(received);
            setUnreadMessages(pending);

            if(query.exec(sql2))
            {
                while(query.next())
                {
                    sent += 1;
                }

                setSentMessages(sent);
            }

            else
            {
                qDebug() << "Error fetchin data from the database: [" << query.executedQuery() << "] -> " << query.lastError().text();
            }
        }

        else
        {
            qDebug() << "Error fetchin data from the database: [" << query.executedQuery() << "] -> " << query.lastError().text();
        }
    }

}

void QmlInterface::getRemindersStatisticsForDashboard()
{
    // Get reminder & notification numbers for the current logged in user
    QSqlDatabase db = QSqlDatabase::database();

    if(db.isOpen())
    {
        QSqlQuery query;
        auto dateToday = m_dateTime->getTimestamp("now");
        QString sql = "SELECT solved from notifications WHERE notify_date < '" + dateToday.at(0) + "';";
        QString sql2 = "SELECT * from notifications WHERE notify_date > '" + dateToday.at(0) + "';";

        int due = 0, overdue = 0, solved = 0;

        if(query.exec(sql))
        {
            while(query.next())
            {
                int isSolved = query.value(0).toBool();

                if(isSolved)
                    solved += 1;

                else
                    overdue += 1;
            }

            setOverdueReminders(overdue);
            setSolvedReminders(solved);


            if(query.exec(sql2))
            {
                while(query.next())
                {
                    due += 1;
                }

                setDueSoonReminders(due);

                // qDebug() << "Due: " << due << "\tOverdue: " << overdue << "\tSolved: " << solved;
            }

            else
            {
                qDebug() << "Error fetchin data from the database: [" << query.executedQuery() << "] -> " << query.lastError().text();
            }
        }

        else
        {
            qDebug() << "Error fetchin data from the database: [" << query.executedQuery() << "] -> " << query.lastError().text();
        }
    }
}

void QmlInterface::getDashboardTableData()
{
    QDateTime dt = QDateTime::currentDateTime();
    QStringList plot;

    // Setup graph XAxis
    for(int i=6; i>=0; i--)
    {
        if(i==1)
            plot.append("Yesterday");

        else if(i == 0)
            plot.append("Today");

        else
        {
            auto n_dt = dt.addDays(-i);
            QString dt_str = n_dt.toString("ddd MMM, yyyy");
            plot.append(dt_str);
        }
    }

    m_plotXAxis.clear();
    setPlotXAxis(plot);

    QSqlDatabase db = QSqlDatabase::database();

    if(db.isOpen())
    {
        QList<int> cash, mpesa, credit, cheque;

        for(int i=6; i>=0; i--)
        {
            int _cash = 0, _mpesa = 0, _cheque = 0, _credit = 0;

            auto n_dt = dt.addDays(-i);
            QString end = n_dt.toString("yyyy-MM-dd ") + "23:59:59+03";
            QString start = n_dt.toString("yyyy-MM-dd ") + "00:00:00+03";

            // qDebug() << "Start: " << start << "\tEnd: " << end;

            QString sql = "SELECT cash, mpesa, cheque, credit FROM payment INNER JOIN sales ON payment.sales_id=sales.sales_id WHERE sales_date > '"+start+"' AND sales_date < '"+end+"';";
            QSqlQuery query;

            if(query.exec(sql))
            {
                // qDebug() << ":- Loaded ";
                while(query.next())
                {
                    _cash += query.value(0).toInt();
                    _mpesa += query.value(1).toInt();
                    _cheque += query.value(2).toInt();
                    _credit += query.value(3).toInt();

                    // qDebug() << "Cash: " << _cash << "\tMpesa: " << _mpesa << "\tCheque: " << _cheque << "\tCredit: " << _credit;
                }
            } else {
                qDebug() << " [ERROR] Couldn't load data from db :" << query.lastError().text();
            }

            cash.append(_cash);
            mpesa.append(_mpesa);
            cheque.append(_cheque);
            credit.append(_credit);

        }

        m_cashYAxis.clear();
        m_mpesaYAxis.clear();
        m_creditYAxis.clear();
        m_chequeYAxis.clear();
        setPlotYmax(10);

        setCashYAxis(cash);
        setCreditYAxis(credit);
        setChequeYAxis(cheque);
        setMpesaYAxis(mpesa);

        std::sort(cash.begin(), cash.end());
        std::sort(mpesa.begin(), mpesa.end());
        std::sort(cheque.begin(), cheque.end());
        std::sort(credit.begin(), credit.end());

        if(cash.at(cash.size() - 1) > plotYmax())
            setPlotYmax(cash.at(cash.size() - 1) + 10);

        if(mpesa.at(mpesa.size() - 1) > plotYmax())
            setPlotYmax(mpesa.at(mpesa.size() - 1) + 10);

        if(cheque.at(cheque.size() - 1) > plotYmax())
            setPlotYmax(cheque.at(cheque.size() - 1) + 10);

        if(credit.at(credit.size() - 1) > plotYmax())
            setPlotYmax(credit.at(credit.size() - 1) + 10);

        emit dataReadyForPlotting();
    }
}

bool QmlInterface::isDarkTheme() const
{
    return m_isDarkTheme;
}

bool QmlInterface::isFirstTimeUse() const
{
    return m_isFirstTimeUse;
}

int QmlInterface::dueSoonReminders() const
{
    return m_dueSoonReminders;
}

int QmlInterface::overdueReminders() const
{
    return m_overdueReminders;
}

int QmlInterface::solvedReminders() const
{
    return m_solvedReminders;
}

int QmlInterface::salesNumbers() const
{
    return m_salesNumbers;
}

int QmlInterface::salesCost() const
{
    return m_salesCost;
}

int QmlInterface::sentMessages() const
{
    return m_setMessages;
}

int QmlInterface::receivedMessages() const
{
    return m_receivedMessages;
}

int QmlInterface::unreadMessages() const
{
    return m_unreadMessages;
}

QStringList QmlInterface::plotXAxis() const
{
    return m_plotXAxis;
}

QList<int> QmlInterface::cashYAxis() const
{
    return m_cashYAxis;
}

QList<int> QmlInterface::mpesaYAxis() const
{
    return m_mpesaYAxis;
}

QList<int> QmlInterface::creditYAxis() const
{
    return m_creditYAxis;
}

QList<int> QmlInterface::chequeYAxis() const
{
    return m_chequeYAxis;
}

int QmlInterface::plotYmax() const
{
    return m_plotYmax;
}

bool QmlInterface::tablesCreated() const
{
    return m_tablesCreated;
}

bool QmlInterface::productsAdded() const
{
    return m_productsAdded;
}

bool QmlInterface::productTypeAdded() const
{
    return m_productTypeAdded;
}

bool QmlInterface::productStockAdded() const
{
    return m_productStockAdded;
}

void QmlInterface::setIsDarkTheme(bool isDarkTheme)
{
    if (m_isDarkTheme == isDarkTheme)
        return;

    m_isDarkTheme = isDarkTheme;
    // qDebug() << "Before isDarkTheme? " << m_settings->value("Theme/isDarkTheme").toBool();
    m_settings->setValue("Theme/isDarkTheme", m_isDarkTheme); // Save the new state
    // qDebug() << "After isDarkTheme? " << m_settings->value("Theme/isDarkTheme").toBool();
    emit isDarkThemeChanged(m_isDarkTheme);
}

void QmlInterface::setIsFirstTimeUse(bool isFirstTimeUse)
{
    if (m_isFirstTimeUse == isFirstTimeUse)
        return;

    m_isFirstTimeUse = isFirstTimeUse;
    emit isFirstTimeUseChanged(m_isFirstTimeUse);
}

void QmlInterface::setDueSoonReminders(int dueSoonReminders)
{
    if (m_dueSoonReminders == dueSoonReminders)
        return;

    m_dueSoonReminders = dueSoonReminders;
    emit dueSoonRemindersChanged(m_dueSoonReminders);
}

void QmlInterface::setOverdueReminders(int overdueReminders)
{
    if (m_overdueReminders == overdueReminders)
        return;

    m_overdueReminders = overdueReminders;
    emit overdueRemindersChanged(m_overdueReminders);
}

void QmlInterface::setSolvedReminders(int solvedReminders)
{
    if (m_solvedReminders == solvedReminders)
        return;

    m_solvedReminders = solvedReminders;
    emit solvedRemindersChanged(m_solvedReminders);
}

void QmlInterface::setSalesNumbers(int salesNumbers)
{
    if (m_salesNumbers == salesNumbers)
        return;

    m_salesNumbers = salesNumbers;
    emit salesNumbersChanged(m_salesNumbers);
}

void QmlInterface::setSalesCost(int salesCost)
{
    if (m_salesCost == salesCost)
        return;

    m_salesCost = salesCost;
    emit salesCostChanged(m_salesCost);
}

void QmlInterface::setReceivedMessages(int receivedMessages)
{
    if (m_receivedMessages == receivedMessages)
        return;

    m_receivedMessages = receivedMessages;
    emit receivedMessagesChanged(m_receivedMessages);
}

void QmlInterface::setSentMessages(int setMessages)
{
    if (m_setMessages == setMessages)
        return;

    m_setMessages = setMessages;
    emit sentMessagesChanged(m_setMessages);
}

void QmlInterface::setUnreadMessages(int unreadMessages)
{
    if (m_unreadMessages == unreadMessages)
        return;

    m_unreadMessages = unreadMessages;
    emit unreadMessagesChanged(m_unreadMessages);
}

void QmlInterface::setPlotXAxis(QStringList plotXAxis)
{
    if (m_plotXAxis == plotXAxis)
        return;

    m_plotXAxis = plotXAxis;
    emit plotXAxisChanged(m_plotXAxis);
}

void QmlInterface::setCashYAxis(QList<int> cashYAxis)
{
    if (m_cashYAxis == cashYAxis)
        return;

    m_cashYAxis = cashYAxis;
    emit cashYAxisChanged(m_cashYAxis);
}

void QmlInterface::setMpesaYAxis(QList<int> mpesaYAxis)
{
    if (m_mpesaYAxis == mpesaYAxis)
        return;

    m_mpesaYAxis = mpesaYAxis;
    emit mpesaYAxisChanged(m_mpesaYAxis);
}

void QmlInterface::setCreditYAxis(QList<int> creditYAxis)
{
    if (m_creditYAxis == creditYAxis)
        return;

    m_creditYAxis = creditYAxis;
    emit creditYAxisChanged(m_creditYAxis);
}

void QmlInterface::setChequeYAxis(QList<int> chequeYAxis)
{
    if (m_chequeYAxis == chequeYAxis)
        return;

    m_chequeYAxis = chequeYAxis;
    emit chequeYAxisChanged(m_chequeYAxis);
}

void QmlInterface::setPlotYmax(int plotYmax)
{
    if (m_plotYmax == plotYmax)
        return;

    m_plotYmax = plotYmax;
    emit plotYmaxChanged(m_plotYmax);
}

void QmlInterface::setTablesCreated(bool tablesCreated)
{
    if (m_tablesCreated == tablesCreated)
        return;

    m_tablesCreated = tablesCreated;
    emit tablesCreatedChanged(m_tablesCreated);
}

void QmlInterface::setProductsAdded(bool productsAdded)
{
    if (m_productsAdded == productsAdded)
        return;

    m_productsAdded = productsAdded;
    emit productsAddedChanged(m_productsAdded);
}

void QmlInterface::setProductTypeAdded(bool productTypeAdded)
{
    if (m_productTypeAdded == productTypeAdded)
        return;

    m_productTypeAdded = productTypeAdded;
    emit productTypeAddedChanged(m_productTypeAdded);
}

void QmlInterface::setProductStockAdded(bool productStockAdded)
{
    if (m_productStockAdded == productStockAdded)
        return;

    m_productStockAdded = productStockAdded;
    emit productStockAddedChanged(m_productStockAdded);
}


