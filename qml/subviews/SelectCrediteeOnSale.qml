import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

import "../components"

Controls2.Popup
{
    id: root
    width: 450
    height: 350

    x: (mainApp.width - width)/2
    y: (mainApp.height - height)/2
    modal: true
    closePolicy: Controls2.Popup.NoAutoClose

    /*onClosed: {
        combo.currentIndex = 0;
        currentStock = 0;
        addStock.value = 1;
        reduceStock.value = 0;
    }*/

    property int currentIndex: -1

    property bool hasPermissions: true
    property bool isNewItemMode: true
    property int currentStock: 0
    //property string barcode: ""
    //property alias combo: combo
    property int valueQty: combo.currentIndex===0? addStock.value:reduceStock.value

    signal accepted()

    onOpened: {
        if(loggedUser_canAddItems)
        {

        }

        else
        {
        }



    }

    contentItem: Rectangle
    {
        color: bgColor
        anchors.fill: parent


        ColumnLayout
        {
            anchors.fill: parent
            anchors.margins: 30

            Item
            {
                Layout.fillWidth: true
                Layout.preferredHeight: 40

                Rectangle
                {
                    color: "black"
                    height: 3
                    width: parent.width
                    opacity: 0.08

                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 5
                }

                AppText
                {
                    color: "black"
                    size: 17
                    text: qsTr("Select Creditee")

                    anchors.centerIn: parent
                }
            }

            Rectangle
            {
                Layout.fillWidth: true
                Layout.fillHeight: true

                color: QmlInterface.isDarkTheme? "#29292d":bgColor

                ColumnLayout
                {
                    anchors.fill: parent
                    spacing: 0

                    Rectangle
                    {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 35

                        color: menuColor
                    }

                    Controls2.ScrollView
                    {
                        Layout.fillWidth: true
                        Layout.fillHeight: true
                    }

                }
            }


            Item
            {
                Layout.fillWidth: true
                Layout.preferredHeight: 35

                RowLayout
                {
                    anchors.fill: parent
                    spacing: 10

                    HorizontalSpacer {}

                    Rectangle
                    {
                        Layout.fillHeight: true
                        Layout.preferredWidth: 100

                        color: menuColor
                        radius: 3


                        AppText
                        {
                            color: "white"
                            size: 15
                            text: qsTr("Cancel")

                            anchors.centerIn: parent
                        }

                        MouseArea
                        {
                            anchors.fill: parent
                            onClicked: root.close()
                        }
                    }

                    Rectangle
                    {
                        Layout.fillHeight: true
                        Layout.preferredWidth: 120

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
                                text: qsTr("Select")
                            }
                        }

                        MouseArea
                        {
                            anchors.fill: parent
                            onClicked: {


                                root.close()
                            }
                        }
                    }
                }
            }
        }
    }

    Connections
    {
        target: StockItemModel

        function onItemStockChanged(state)
        {
            if(state)
            {
                console.log("Stock update successful!");
                root.close();
            }

            else
            {
                console.log("Stock update failed!");
            }
        }
    }
}
