#ifndef QMLINTERFACE_H
#define QMLINTERFACE_H

#include <QObject>
#include <QDebug>
#include <QSqlDatabase>
#include <QJsonObject>
#include <QRect>
#include <QIcon>
#include <QScreen>
#include <QJsonDocument>
#include <QJsonObject>
#include <QGuiApplication>
#include <QSettings>

#include "databaseinterface.h"
#include "serialportinterface.h"
#include "webapiinterface.h"
#include "websocketsinterface.h"
#include "datetime.h"

class QmlInterface : public QObject
{
    Q_OBJECT

public:
    explicit QmlInterface(QObject *parent = nullptr);

    Q_PROPERTY(bool isDarkTheme READ isDarkTheme WRITE setIsDarkTheme NOTIFY isDarkThemeChanged)
    Q_PROPERTY(bool isFirstTimeUse READ isFirstTimeUse WRITE setIsFirstTimeUse NOTIFY isFirstTimeUseChanged)
    Q_PROPERTY(int dueSoonReminders READ dueSoonReminders WRITE setDueSoonReminders NOTIFY dueSoonRemindersChanged)
    Q_PROPERTY(int overdueReminders READ overdueReminders WRITE setOverdueReminders NOTIFY overdueRemindersChanged)
    Q_PROPERTY(int solvedReminders READ solvedReminders WRITE setSolvedReminders NOTIFY solvedRemindersChanged)
    Q_PROPERTY(int salesNumbers READ salesNumbers WRITE setSalesNumbers NOTIFY salesNumbersChanged)
    Q_PROPERTY(int salesCost READ salesCost WRITE setSalesCost NOTIFY salesCostChanged)
    Q_PROPERTY(int sentMessages READ sentMessages WRITE setSentMessages NOTIFY sentMessagesChanged)
    Q_PROPERTY(int receivedMessages READ receivedMessages WRITE setReceivedMessages NOTIFY receivedMessagesChanged)
    Q_PROPERTY(int unreadMessages READ unreadMessages WRITE setUnreadMessages NOTIFY unreadMessagesChanged)
    Q_PROPERTY(QStringList plotXAxis READ plotXAxis WRITE setPlotXAxis NOTIFY plotXAxisChanged)
    Q_PROPERTY(QList<int> cashYAxis READ cashYAxis WRITE setCashYAxis NOTIFY cashYAxisChanged)
    Q_PROPERTY(QList<int> mpesaYAxis READ mpesaYAxis WRITE setMpesaYAxis NOTIFY mpesaYAxisChanged)
    Q_PROPERTY(QList<int> creditYAxis READ creditYAxis WRITE setCreditYAxis NOTIFY creditYAxisChanged)
    Q_PROPERTY(QList<int> chequeYAxis READ chequeYAxis WRITE setChequeYAxis NOTIFY chequeYAxisChanged)
    Q_PROPERTY(int plotYmax READ plotYmax WRITE setPlotYmax NOTIFY plotYmaxChanged)

    // Configuration properties
    Q_PROPERTY(bool tablesCreated READ tablesCreated WRITE setTablesCreated NOTIFY tablesCreatedChanged)
    Q_PROPERTY(bool productsAdded READ productsAdded WRITE setProductsAdded NOTIFY productsAddedChanged)
    Q_PROPERTY(bool productTypeAdded READ productTypeAdded WRITE setProductTypeAdded NOTIFY productTypeAddedChanged)
    Q_PROPERTY(bool productStockAdded READ productStockAdded WRITE setProductStockAdded NOTIFY productStockAddedChanged)


    Q_INVOKABLE QJsonObject getScreenSize();
    Q_INVOKABLE void fetchSavedSettings();
    Q_INVOKABLE void getSalesStatisticsForDashboard();
    Q_INVOKABLE void getMessagesStatisticsForDashboard(const QString &uname);
    Q_INVOKABLE void getRemindersStatisticsForDashboard();
    Q_INVOKABLE void getDashboardTableData();
    // Q_INVOKABLE QVariantList getCreditees();

    void setTabularData();

    bool isDarkTheme() const;

    bool isFirstTimeUse() const;

    int dueSoonReminders() const;

    int overdueReminders() const;

    int solvedReminders() const;

    int salesNumbers() const;

    int salesCost() const;

    int sentMessages() const;

    int receivedMessages() const;

    int unreadMessages() const;

    QStringList plotXAxis() const;

    QList<int> cashYAxis() const;

    QList<int> mpesaYAxis() const;

    QList<int> creditYAxis() const;

    QList<int> chequeYAxis() const;

    int plotYmax() const;

    bool tablesCreated() const;

    bool productsAdded() const;

    bool productTypeAdded() const;

    bool productStockAdded() const;

public slots:
    void setIsDarkTheme(bool isDarkTheme);

    void setIsFirstTimeUse(bool isFirstTimeUse);

    void setDueSoonReminders(int dueSoonReminders);

    void setOverdueReminders(int overdueReminders);

    void setSolvedReminders(int solvedReminders);

    void setSalesNumbers(int salesNumbers);

    void setSalesCost(int salesCost);

    void setSentMessages(int setMessages);

    void setReceivedMessages(int receivedMessages);

    void setUnreadMessages(int unreadMessages);

    void setPlotXAxis(QStringList plotXAxis);

    void setCashYAxis(QList<int> cashYAxis);

    void setMpesaYAxis(QList<int> mpesaYAxis);

    void setCreditYAxis(QList<int> creditYAxis);

    void setChequeYAxis(QList<int> chequeYAxis);

    void setPlotYmax(int plotYmax);

    void setTablesCreated(bool tablesCreated);

    void setProductsAdded(bool productsAdded);

    void setProductTypeAdded(bool productTypeAdded);

    void setProductStockAdded(bool productStockAdded);

signals:
    void databaseReadyChanged();

    void isDarkThemeChanged(bool isDarkTheme);

    void isFirstTimeUseChanged(bool isFirstTimeUse);

    void dueSoonRemindersChanged(int dueSoonReminders);

    void overdueRemindersChanged(int overdueReminders);

    void solvedRemindersChanged(int solvedReminders);

    void salesNumbersChanged(int salesNumbers);

    void salesCostChanged(int salesCost);

    void sentMessagesChanged(int setMessages);

    void receivedMessagesChanged(int receivedMessages);

    void unreadMessagesChanged(int unreadMessages);

    void plotXAxisChanged(QStringList plotXAxis);

    void cashYAxisChanged(QList<int> cashYAxis);

    void mpesaYAxisChanged(QList<int> mpesaYAxis);

    void creditYAxisChanged(QList<int> creditYAxis);

    void chequeYAxisChanged(QList<int> chequeYAxis);

    void dataReadyForPlotting();

    void plotYmaxChanged(int plotYmax);

    void tablesCreatedChanged(bool tablesCreated);

    void productsAddedChanged(bool productsAdded);

    void productTypeAddedChanged(bool productTypeAdded);

    void productStockAddedChanged(bool productStockAdded);

private slots:

private:
    DatabaseInterface * m_databaseInterface;
    DateTime * m_dateTime;
    bool m_isDarkTheme, m_isFirstTimeUse;
    QSettings * m_settings;
    int m_dueSoonReminders, m_overdueReminders, m_solvedReminders, m_salesNumbers, m_salesCost, m_setMessages, m_receivedMessages, m_unreadMessages;
    QStringList m_plotXAxis;
    QList<int> m_cashYAxis;
    QList<int> m_mpesaYAxis;
    QList<int> m_creditYAxis;
    QList<int> m_chequeYAxis;
    int m_plotYmax;
    bool m_tablesCreated;
    bool m_productsAdded;
    bool m_productTypeAdded;
    bool m_productStockAdded;
};

#endif // QMLINTERFACE_H
