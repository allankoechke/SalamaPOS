import QtQuick 2.0
import QtQuick.Layouts 1.3

import "../components"
import "../subviews"

Rectangle {
    anchors.fill: parent
    color: "#f4f9fa"

    property int navBarIndex: 0
    property string viewText: qsTr("Home")

    property alias checkoutPopup: checkoutPopup
    property alias userMenuPopup: userMenuPopup

    onNavBarIndexChanged: {
        switch(navBarIndex)
        {
        case 0:
            viewText = qsTr("Home")
            break;
        case 1:
            viewText = qsTr("Product Checkout")
            break;
        case 2:
            viewText = qsTr("Product & Stock")
            break;
        case 3:
            viewText = qsTr("Sales")
            break;
        case 4:
            viewText = qsTr("Messages & Notifications")
            break;
        case 5:
            viewText = qsTr("App & System Settings")
            break;
        case 6:
            viewText = qsTr("Users & Accounts")
            break;
        }
    }

    RowLayout
    {
        anchors.fill: parent
        spacing: 0

        NavigationBar
        {
            id: navBar
        }

        Item
        {
            Layout.fillWidth: true
            Layout.fillHeight: true

            ColumnLayout
            {
                anchors.fill: parent
                spacing: 0

                NotificationBar
                {

                }

                Item{
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    StackLayout
                    {
                        anchors.fill: parent
                        currentIndex: navBarIndex

                        DashboardView
                        {

                        }

                        CheckoutView
                        {

                        }

                        StockView
                        {

                        }

                        SalesView
                        {

                        }

                        MessagesView
                        {

                        }

                        SettingsView
                        {

                        }
                    }
                }
            }
        }
    }

    CheckoutPopup
    {
        id: checkoutPopup
    }

    UserMenuPopup
    {
        id: userMenuPopup
        // onOpened: console.log("Opened")
    }

    NewItemPopup
    {
        id: newItemPopup
    }
}
