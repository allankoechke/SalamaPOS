import QtQuick 2.14
import QtQuick.Window 2.14

import "./views"

Window {
    id: mainApp
    visible: true
    width: 400
    height: 600
    title: qsTr("MySale App")

    property alias montserratFontLoader: montserratFontLoader
    property alias fontAwesomeFontLoader: fontAwesomeFontLoader
    property alias popupTimer: popupTimer

    property string bgColor: "#f4f9fa"
    property string menuColor: "#12679a"
    property string tableHeaderColor: "#5f00ff"
    property bool isDialogClosedAfterEachAdd: false

    property string fullname: ""
    property string username: ""

    Component.onCompleted: {
        popupTimer.start();
        timer1.start();
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

        onTriggered: mainAppView.navBarIndex = 8
    }

    MainAppView
    {
        id: mainAppView
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

        function onDatabaseReadyChanged()
        {
            console.log(">> Database Ready Signal in QML!")
        }
    }

    Connections
    {
        target: AccountsModel

        function onUserAccountsLoaded(status)
        {
            if(status)
                console.log(">> User Accounts have been loaded");

            else
                console.log(">> Error loading user accounts");
        }

        function onLoggedInUserChanged()
        {
            console.log(">> Logged in user changed ...")
            fullname = AccountsModel.loggedInUser["firstname"] + " " + AccountsModel.loggedInUser["lastname"]
            username =  AccountsModel.loggedInUser["username"]
        }
    }
}
