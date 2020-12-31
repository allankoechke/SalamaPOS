import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Controls.Material 2.2
import QtQuick.Controls 2.4 as Controls2

import "./views"
import "./delegates"

Window {
    id: mainApp
    visible: true
    width: 600
    height: 500
    minimumHeight: 600
    maximumHeight: QmlInterface.getScreenSize()["height"]
    minimumWidth: 700
    maximumWidth: QmlInterface.getScreenSize()["width"]
    x: (QmlInterface.getScreenSize()["width"]-width)/2
    y: (QmlInterface.getScreenSize()["height"]-height)/2
    flags: mainAppView.navBarIndex===7? Qt.FramelessWindowHint:Qt.Window
    title: qsTr("MySale App")

    property alias montserratFontLoader: montserratFontLoader
    property alias fontAwesomeFontLoader: fontAwesomeFontLoader
    property alias popupTimer: popupTimer

    property bool isCrediteeSelected: false

    Material.theme: QmlInterface.isDarkTheme? Material.Dark: Material.Light

    //    Material.background: "#f4f9fa"
    //    dark-bg: #1e2027
    //    dark-pane: #29292d
    //    dark-menu: #161719
    //    Background Colors
    //    dark-fore-color: #f4f4f4
    //    dark-ico: #999fa6

    property string bgColor: QmlInterface.isDarkTheme? "#1e2027":"#f4f9fa"
    property string menuColor: "#12679a"
    property string tableHeaderColor: "#5f00ff"
    property bool isDialogClosedAfterEachAdd: false
    property alias alarmsListView: alarmsListView

    // Logged in user
    property string loggedUser_fullname: ""
    property string loggedUser_username: ""
    property string loggedUser_mobile: ""
    property bool loggedUser_canAddAccounts: false
    property bool loggedUser_canDeleteAccounts: false
    property bool loggedUser_canAddItems: false
    property bool loggedUser_canDeleteItems: false
    property bool loggedUser_canAddStock: false
    property bool loggedUser_canDeleteStock: false
    property bool loggedUser_canUndoSales: false
    property bool loggedUser_canBackupDb: false
    property bool isAdmin: false

    Component.onCompleted: {
        popupTimer.start();
        timer1.start();

        QmlInterface.fetchSavedSettings();
        QmlInterface.getDashboardTableData();
    }

    Timer
    {
        id: timer1
        repeat: false
        running: false
        interval: 2500

        onTriggered: {
            StockItemModel.initializeStockFromDb();
            AccountsModel.loadAllUserAccounts();
        }
    }

    Timer
    {
        id: popupTimer
        interval: 3000
        repeat: false
        running: false

        onTriggered: mainAppView.startApp(true);
    }


    MainAppView
    {
        id: mainAppView
    }

    Item
    {
        z: 0
        width: 300
        x: mainApp.width - (width+10)
        y: mainApp.height - (height + 10)
        height: AlarmsModel.size===0? 0:AlarmsModel.size * 53
        visible: mainAppView.navBarIndex !== 7 && mainAppView !== 8

        ListView
        {
            id: alarmsListView
            anchors.fill: parent
            width: parent.width
            height: parent.height
            spacing: 5

            model: AlarmsModel
            delegate: AlarmsWidgetDelegate
            {
                alarmId: alarm_id
                category: alarm_type
                content: alarm_text
            }
        }
    }

    FontLoader
    {
        id: fontAwesomeFontLoader
        source: "qrc:/assets/fonts/fontawesome.otf"
    }

    FontLoader
    {
        id: montserratFontLoader
        source: "qrc:/assets/fonts/montserrat/Montserrat-Regular.ttf"
    }

    Connections
    {
        target: QmlInterface

        function onDatabaseLoadedChanged(state)
        {
            console.log("database loaded? " , state)
        }

        function onDatabaseConnectionErrorStringChanged(err)
        {
            console.log("Error Str: ", err)
        }

        function onDatabaseReadyChanged(state, err)
        {
            console.log(">> Database Ready Signal in QML!")

            // databaseConnStatus = state
            // databaseConnStatusStr = state? "DB Connected":"DB Connection Error"
        }

        function onLogFileNameChanged(logFileName)
        {
            console.log(">> Log File Name Changed")
        }

        function onDatabaseConnectionChanged(state, msg)
        {
            console.log(">> Database Conn Changed")
        }
    }

    Connections
    {
        target: AccountsModel

        function onLogDataChanged(level, info)
        {
            QmlInterface.logToFile(level, info)
        }

        function onUserAccountsLoaded(status)
        {
            if(status)
                console.log(">> User Accounts have been loaded");

            else
                console.log(">> Error loading user accounts");
        }

        function onLogged_inUserChanged()
        {
            console.log(" [QML-INFO] Logged in user changed ...")
        }

        function onLoggedInUserChanged(json)
        {
            loggedUser_fullname = json["firstname"] + " " + json["lastname"]
            loggedUser_username =  json["username"]
            loggedUser_mobile =  json["phone_no"]
            loggedUser_canAddAccounts =  json["canAddUser"]
            loggedUser_canDeleteAccounts =  json["canRemoveUsers"]
            loggedUser_canAddItems =  json["canAddItems"]
            loggedUser_canDeleteItems =  json["canRemoveItems"]
            loggedUser_canAddStock =  json["canAddStock"]
            loggedUser_canDeleteStock =  json["canRemoveStock"]
            loggedUser_canUndoSales =  json["canUndoSales"]
            loggedUser_canBackupDb =  json["canBackupDb"]

            QmlInterface.getMessagesStatisticsForDashboard(loggedUser_username);
            QmlInterface.getRemindersStatisticsForDashboard();
            QmlInterface.getSalesStatisticsForDashboard();

            isAdmin = loggedUser_canAddAccounts && loggedUser_canDeleteAccounts && loggedUser_canAddItems && loggedUser_canDeleteItems && loggedUser_canAddStock && loggedUser_canDeleteStock && loggedUser_canUndoSales && loggedUser_canBackupDb

            QmlInterface.logToFile("INFO", "Logged In User: username="+loggedUser_username)
        }
    }

    Connections
    {
        target: CheckoutModel

        function onLogDataChanged(level, info)
        {
            QmlInterface.logToFile(level, info)
        }
    }

    Connections
    {
        target: CrediteeModel

        function onLogDataChanged(level, info)
        {
            QmlInterface.logToFile(level, info)
        }
    }

    Connections
    {
        target: ProductSalesModel

        function onLogDataChanged(level, info)
        {
            QmlInterface.logToFile(level, info)
        }
    }

    Connections
    {
        target: SalesModel

        function onLogDataChanged(level, info)
        {
            QmlInterface.logToFile(level, info)
        }
    }

    Connections
    {
        target: StockItemModel

        function onLogDataChanged(level, info)
        {
            QmlInterface.logToFile(level, info)
        }
    }
}
