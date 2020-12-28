#include <QApplication>
#include <QQmlContext>
#include <QQuickStyle>
#include <QQmlApplicationEngine>
#include <QFont>
#include <QFontDatabase>

#define DEBUG_MODE // 1

// To add a console when running on windows
#ifdef Q_OS_WINDOWS
#ifdef DEBUG_MODE

#include <windows.h>
#include <stdio.h>

#endif
#endif

#include "qmlinterface.h"
#include "models/stockitemsmodel.h"
#include "models/checkoutitemsmodel.h"
#include "models/useraccountsmodel.h"
#include "models/completermodel.h"
#include "models/saleitemsmodel.h"
#include "models/productsalesmodel.h"
#include "models/crediteeaccountsmodel.h"
#include "models/alarmsmodel.h"

int main(int argc, char *argv[])
{
#ifdef Q_OS_WINDOWS
#ifdef DEBUG_MODE
    // detach from the current console window
    // if launched from a console window, that will still run waiting for the new console (below) to close
    // it is useful to detach from Qt Creator's <Application output> panel
    FreeConsole();

    // create a separate new console window
    AllocConsole();

    // attach the new console to this application's process
    AttachConsole(GetCurrentProcessId());

    // reopen the std I/O streams to redirect I/O to the new console
    freopen("CON", "w", stdout);
    freopen("CON", "w", stderr);
    freopen("CON", "r", stdin);

#endif
#endif

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QQuickStyle::setStyle(QStringLiteral("Material"));
    QApplication app(argc, argv);
    QFontDatabase fontDb;
    int status = fontDb.addApplicationFont(":/assets/fonts/montserrat/Montserrat-Regular.ttf");

    if(status != -1)
    {
        app.setFont(QFont(QFontDatabase::applicationFontFamilies(status).at(0)));
    }

    else
    {
        qDebug() << "Could not load the specified font!";
    }

    QQmlApplicationEngine engine;

    // Singletons
    QmlInterface qmlInterface;
    StockItemsModel m_stockModel;
    CheckoutItemsModel m_checkoutItems;
    UserAccountsModel m_userAccounts;
    CompleterModel m_completer;
    saleItemsModel m_saleItem;
    ProductSalesModel m_pSale;
    CrediteeAccountsModel creditee;
    AlarmsModel m_alarmModel;

    engine.rootContext()->setContextProperty("QmlInterface", &qmlInterface);
    engine.rootContext()->setContextProperty("StockItemModel", &m_stockModel);
    engine.rootContext()->setContextProperty("CheckoutModel", &m_checkoutItems);
    engine.rootContext()->setContextProperty("AccountsModel", &m_userAccounts);
    engine.rootContext()->setContextProperty("CompleterModel", &m_completer);
    engine.rootContext()->setContextProperty("SalesModel", &m_saleItem);
    engine.rootContext()->setContextProperty("ProductSalesModel", &m_pSale);
    engine.rootContext()->setContextProperty("CrediteeModel", &creditee);
    engine.rootContext()->setContextProperty("AlarmsModel", &m_alarmModel);

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
