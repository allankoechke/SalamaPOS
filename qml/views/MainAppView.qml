import QtQuick 2.0
import QtQuick.Layouts 1.3

import "../components"
import "../subviews"
import "../delegates"

Rectangle {
    id: mainAppViewRoot
    anchors.fill: parent
    color: bgColor // QmlInterface.isDarkTheme? "#1e2027":"#f4f9fa"//"#f4f9fa"

    property int navBarIndex: 7
    property string viewText: qsTr("Home")

    property alias checkoutPopup: checkoutPopup
    property alias userMenuPopup: userMenuPopup
    property alias stockPopup: stockPopup
    property alias checkoutQtyPopup: checkoutQtyPopup
    property alias userAccountPopup: userAccountPopup
    property alias accountsPopup: accountsPopup
    property alias selectCrediteeOnSale: selectCrediteeOnSale
    property alias salesSummaryDialog: salesSummaryDialog

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
            visible: navBarIndex!==8 && navBarIndex!==7
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
                    id: notificationBar
                    visible: navBarIndex!==8 && navBarIndex!==7
                }

                Item{
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    StackLayout
                    {
                        anchors.fill: parent
                        currentIndex: navBarIndex

                        DashboardView {}

                        CheckoutView {}

                        StockView { id: stackStockView }

                        SalesView { id: salesView }

                        MessagesView {}

                        SettingsView {}

                        AccountsView {}

                        SplashView {}

                        LoginView { id: loginView }
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

    StockPopup
    {
        id: stockPopup
    }

    CheckoutQtyEditPopup
    {
        id: checkoutQtyPopup
    }

    UserAccountPopup
    {
        id: userAccountPopup
    }

    AccountsPopup
    {
        id: accountsPopup
    }

    AddItemDialog
    {
        id: addItemDialog
    }

    CreditsAndDebtsDrawer
    {
        id: creditNdebtpopup
    }

    NewCrediteePopup
    {
        id: newCrediteePopup
    }

    CreditRepaymentPopup
    {
        id: creditRepayDialog
    }

    SelectCrediteeOnSale
    {
        id: selectCrediteeOnSale
    }

    SalesSummaryDialog
    {
        id: salesSummaryDialog
    }

    function startApp(state)
    {
        if(state)
        {
            navBarIndex = 8
            mainApp.showMaximized();
        }

        else
        {
            navBarIndex = 7
            notificationBar.visible = !true;
            navBar.visible = !true
            mainApp.width = 600;
            mainApp.height = 500;
        }
    }
}
