import QtQuick 2.0
import QtQuick.Window 2.3
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2

import "../delegates"
import "../components"

Window {
    id: myWindow

    property alias x: myWindow.x
    property alias y: myWindow.y
    // property alias searchText: textField.text
    // property alias currentIndex: completions.currentIndex

    flags:  Qt.Dialog // | Qt.WindowCloseButtonHint
    modality: Qt.ApplicationModal
    color: bgColor
    width: 500
    height: 470

    onClosing: {
        close.accepted = false
        // CompleterModel.addCompleterItems("")
        // textField.text = ""
        close.accepted = true
    }


    ColumnLayout
    {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 10

        Item{
            Layout.fillWidth: true
            Layout.preferredHeight: 45

            RowLayout{
                anchors.fill: parent
                spacing: 5

                AppText
                {
                    Layout.alignment: Qt.AlignVCenter
                    horizontalAlignment: AppText.AlignLeft

                    text: qsTr("Sales Summary for: ")
                    color: QmlInterface.isDarkTheme? "#F5F5F5":"#2e2e2e"
                }

                ComboBox
                {
                    id: cb
                    height: 45
                    Layout.minimumWidth: 220
                    currentIndex: 0

                    editable: false
                    enabled: isAdmin
                    model: ["Today", "Yesterday", "This Week", "This Month", "This Year", "All Time", "Custom"]

                    Layout.rightMargin: 10

                    onCurrentIndexChanged: {
                        /* if(currentIndex === 0)
                            ProductSalesModel.showTodaysSales();

                        else if(currentIndex === 1)
                            ProductSalesModel.showYesterdaysSales();

                        else if(currentIndex === 2)
                            ProductSalesModel.showThisWeeksSales();

                        else if(currentIndex === 3)
                            ProductSalesModel.showThisMonthsSales();

                        else if(currentIndex === 4)
                            ProductSalesModel.showThisYearsSales();

                        else
                            ProductSalesModel.loadSalesData();*/
                    }
                }
            }
        }

        Item{
            Layout.fillHeight: true
            Layout.fillWidth: true

            RowLayout
            {
                anchors.fill: parent
                spacing: 5

                Item{
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    ColumnLayout
                    {
                        anchors.fill: parent
                        spacing: 10
                        anchors.margins: 10

                        SaleSummaryCostWidget
                        {
                            icon: "\uf3d1"
                            text: qsTr("Sales Cash:")
                            cost: qsTr("Ksh. 37264")
                        }

                        SaleSummaryCostWidget
                        {
                            icon: "\uf3ce"
                            text: qsTr("Sales M-Pesa:")
                            cost: qsTr("Ksh. 37264")
                        }

                        SaleSummaryCostWidget
                        {
                            icon: "\uf09d"
                            text: qsTr("Sales Credit:")
                            cost: qsTr("Ksh. 37264")
                        }

                        SaleSummaryCostWidget
                        {
                            icon: "\uf53d"
                            text: qsTr("Sales Cheque:")
                            cost: qsTr("Ksh. 37264")
                        }

                        SaleSummaryCostWidget
                        {
                            icon: "\uf4c4"
                            text: qsTr("Debt Re-Paid:")
                            cost: qsTr("Ksh. 37264")
                        }

                        Rectangle
                        {
                            Layout.fillWidth: true
                            Layout.preferredHeight: 1
                            color: "silver"
                            opacity: 0.4
                        }

                        SaleSummaryCostWidget
                        {
                            icon: "\uf52c"
                            text: qsTr("Totals less Debt:")
                            cost: qsTr("Ksh. 37264")
                        }
                    }
                }

                Rectangle
                {
                    Layout.fillHeight: true
                    Layout.preferredWidth: 1
                    color: "silver"
                }

                Item {
                    Layout.fillHeight: true
                    Layout.preferredWidth: 70

                    ColumnLayout
                    {
                        anchors.fill: parent
                        spacing: 5

                        Rectangle
                        {
                            id: close_btn
                            Layout.preferredWidth: 60
                            Layout.preferredHeight: 60

                            color: Qt.darker(menuColor, 1.6)
                            radius: height/2

                            ColumnLayout
                            {
                                anchors.centerIn: parent
                                spacing: 5

                                AppIcon
                                {
                                    size: 18
                                    color: "white"
                                    icon: "\uf02f"

                                    Layout.alignment: Qt.AlignHCenter
                                }

                                AppText
                                {
                                    text: qsTr("PRINT")
                                    color: "white"
                                    font.bold: true
                                    size: 13

                                    Layout.alignment: Qt.AlignHCenter
                                }
                            }


                            MouseArea
                            {
                                anchors.fill: parent
                                onClicked: {
                                    // searchText = "";
                                    // myWindow.close();
                                }
                            }
                        }

                        Rectangle
                        {
                            Layout.preferredWidth: 60
                            Layout.preferredHeight: 60

                            color: Qt.lighter("#FF605C", 1.2)
                            radius: height/2

                            ColumnLayout
                            {
                                anchors.centerIn: parent
                                spacing: 5

                                AppIcon
                                {
                                    size: 18
                                    color: "white"
                                    icon: "\uf1c1"

                                    Layout.alignment: Qt.AlignHCenter
                                }

                                AppText
                                {
                                    text: qsTr("PDF")
                                    color: "white"
                                    font.bold: true
                                    size: 13

                                    Layout.alignment: Qt.AlignHCenter
                                }
                            }



                            MouseArea
                            {
                                anchors.fill: parent
                                onClicked: {
                                    // searchText = "";
                                    myWindow.close();
                                }
                            }
                        }


                        Rectangle
                        {
                            Layout.preferredWidth: 60
                            Layout.preferredHeight: 60

                            color: "orange"
                            radius: height/2

                            ColumnLayout
                            {
                                anchors.centerIn: parent
                                spacing: 5

                                AppIcon
                                {
                                    size: 18
                                    color: "white"
                                    icon: "\uf021"

                                    Layout.alignment: Qt.AlignHCenter
                                }

                                AppText
                                {
                                    text: qsTr("SYNC")
                                    color: "white"
                                    font.bold: true
                                    size: 13

                                    Layout.alignment: Qt.AlignHCenter
                                }
                            }


                            MouseArea
                            {
                                anchors.fill: parent
                                onClicked: {
                                    // searchText = "";
                                    // myWindow.close();
                                }
                            }
                        }

                        Item {
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                        }

                        Rectangle
                        {
                            Layout.preferredWidth: 60
                            Layout.preferredHeight: 60

                            color: "#FF605C"
                            radius: height/2

                            ColumnLayout
                            {
                                anchors.centerIn: parent
                                spacing: 5

                                AppIcon
                                {
                                    size: 18
                                    color: "white"
                                    icon: "\uf00d"

                                    Layout.alignment: Qt.AlignHCenter
                                }

                                AppText
                                {
                                    text: qsTr("CLOSE")
                                    color: "white"
                                    font.bold: true
                                    size: 13

                                    Layout.alignment: Qt.AlignHCenter
                                }
                            }


                            MouseArea
                            {
                                anchors.fill: parent
                                onClicked: {
                                    // searchText = "";
                                    myWindow.close();
                                }
                            }
                        }

                    }
                }
            }
        }

    }

    /*
    Connections
    {
        target: StockItemModel

        function onItemStockWarningChanged()
        {
            console.log(">> Stock is less to complete this add!")
            AlarmsModel.addAlarmItem("error", "Stock is less to add to Checkout")
        }

        function onItemDataChanged(status, jsonObj)
        {
            if(status)
            {
                console.log(">> Item Added to Checkout Model!")
                CheckoutModel.addSellItem(jsonObj["sellBarcode"], jsonObj["sellItemName"], jsonObj["sellItemUnit"], jsonObj["buyingPrice"], jsonObj["sellingPrice"], 1);

                searchText = "";
                currentIndex = -1;
                CompleterModel.addCompleterItems("");

                if(isDialogClosedAfterEachAdd)
                    myWindow.close()
            }

            else
            {
                console.log(">> Failed to Add Item to Checkout Model!")
                AlarmsModel.addAlarmItem("error", "Failed to Add Item to Checkout Model")
            }
        }


    }
    */
}
