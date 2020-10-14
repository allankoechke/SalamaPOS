import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

import "../components"
import "../subviews"

Item {
    id: root

    Layout.fillHeight: true
    Layout.fillWidth: true
    Layout.margins: 50

    property var currentScreen: 0


    ColumnLayout
    {
        anchors.fill: parent
        anchors.leftMargin: 40
        anchors.rightMargin: 40
        anchors.bottomMargin: 30
        spacing: 10

        Item
        {
            Layout.fillWidth: true
            Layout.preferredHeight: 70

            Rectangle
            {
                width: parent.width
                height: 3
                color: "#d3e5ff"

                anchors.bottom: parent.bottom
                anchors.bottomMargin: 3
            }

            RowLayout
            {
                anchors.fill: parent
                spacing: 1

                StockViewSelectBtn
                {

                    buttonIcon: ""
                    buttonLabel: qsTr("Products")
                    isCurrentlySelected: currentScreen === 0

                    onClicked: currentScreen=0;
                }

                StockViewSelectBtn
                {
                    buttonIcon: ""
                    buttonLabel: qsTr("Stock")
                    isCurrentlySelected: currentScreen === 1

                    onClicked: currentScreen=1;
                }

                StockViewSelectBtn
                {
                    visible: false
                    buttonIcon: ""
                    buttonLabel: qsTr("Products")
                    isCurrentlySelected: currentScreen === 2

                    onClicked: currentScreen=2;
                }

                HorizontalSpacer {}

                Rectangle
                {
                    visible: currentScreen===0 //&& loggedUser_canAddItems
                    Layout.preferredHeight: 45
                    Layout.preferredWidth: 120
                    Layout.alignment: Qt.AlignVCenter
                    Layout.rightMargin: 20

                    color: menuColor
                    radius: 3

                    RowLayout
                    {
                        anchors.centerIn: parent

                        spacing: 7

                        AppIcon
                        {
                            color: "white"
                            size: 15
                            icon: "\uf067"
                        }

                        AppText
                        {
                            color: "white"
                            size: 15
                            text: qsTr("Add Item")
                        }
                    }

                    MouseArea
                    {
                        anchors.fill: parent
                        onClicked: {

                            if(loggedUser_canAddItems)
                            {
                                newItemPopup.open()
                                newItemPopup.barCode = new Date().getTime().toString();
                                newItemPopup.itemName = "";
                                newItemPopup.itemUnit = "";
                                newItemPopup.itemBp = "";
                                newItemPopup.itemSp = "";
                                newItemPopup.itemQty = "";
                                newItemPopup.itemCompany = "";

                                newItemPopup.isNewItemMode = true;
                            }

                            else
                            {
                                AlarmsModel.addAlarmItem("error", "User has no rights to add items")
                                console.log(" [ERROR] User has no rights to add item")
                            }
                        }
                    }
                }

                Rectangle
                {
                    visible: false
                    Layout.fillHeight: true
                    Layout.preferredWidth: 150

                    color: menuColor
                    radius: 3

                    RowLayout
                    {
                        anchors.centerIn: parent

                        spacing: 10

                        AppIcon
                        {
                            color: "white"
                            size: 15
                            icon: "\uf067"
                        }

                        AppText
                        {
                            color: "white"
                            size: 15
                            text: qsTr("Add Stock")
                        }
                    }
                }

                Rectangle
                {
                    Layout.preferredHeight: 45
                    Layout.fillWidth: true
                    Layout.minimumWidth: 100
                    Layout.maximumWidth: 300

                    color: "white"
                    border.width: 1
                    border.color: "grey"
                    radius: 3

                    RowLayout
                    {
                        anchors.fill: parent
                        spacing: 0

                        TextInput
                        {
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            verticalAlignment: TextInput.AlignVCenter
                            horizontalAlignment: TextInput.AlignLeft
                            Layout.leftMargin: 5
                            color: "black"
                            font.pixelSize: 17
                            font.family: montserratFontLoader.name
                            selectByMouse: true

                            AppText{
                                size: parent.font.pixelSize-3
                                color: "grey"
                                text: qsTr("Filter items")
                                visible: parent.text===""

                                anchors.left: parent.left
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }

                        Rectangle
                        {
                            Layout.fillHeight: true
                            width: 50
                            Layout.margins: 1

                            color: menuColor

                            AppIcon
                            {
                                anchors.centerIn: parent
                                size: 16
                                color: "white"
                                icon: "\uf002"
                            }
                        }
                    }
                }
            }
        }

        Item
        {
            Layout.fillHeight: true
            Layout.fillWidth: true

            StackLayout
            {
                anchors.fill: parent
                currentIndex: currentScreen

                StockProductView
                { }

                StockItemStockView
                { }


            }
        }
    }
}
