#include <QApplication>
#include <QQmlContext>
#include <QQuickStyle>
#include <QQmlApplicationEngine>

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
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QQuickStyle::setStyle(QStringLiteral("Material"));
    QApplication app(argc, argv);
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
