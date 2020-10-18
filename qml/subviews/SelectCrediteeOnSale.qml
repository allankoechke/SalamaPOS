import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

import "../components"
import "../delegates"

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

    property var selectedCreditee: ""

    signal accepted()

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
                    color: QmlInterface.isDarkTheme? "grey":"black"
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

                        RowLayout
                        {
                            anchors.fill: parent
                            spacing: 1


                            AppText
                            {
                                size: 17
                                color: "white"
                                text: qsTr("No.")
                                font.bold: true
                                horizontalAlignment: AppText.AlignHCenter

                                Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
                                Layout.preferredWidth: 50
                            }

                            VSeparator{}

                            AppText
                            {
                                size: 17
                                color: "white"
                                text: qsTr("Name")
                                font.bold: true
                                horizontalAlignment: AppText.AlignHCenter

                                Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
                                Layout.fillWidth: true
                            }

                            VSeparator{}

                            AppText
                            {
                                size: 17
                                color: "white"
                                text: qsTr("ID No.")
                                font.bold: true
                                horizontalAlignment: AppText.AlignHCenter

                                Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
                                Layout.preferredWidth: 120
                            }
                        }
                    }

                    Controls2.ScrollView
                    {
                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        ListView
                        {
                            id: lv_crediteelist
                            width: parent.width
                            height: parent.height
                            anchors.left: parent.left

                            spacing: 0
                            currentIndex: -1
                            model: CrediteeModel
                            delegate: CrediteeOnSaleDelegate
                            {
                                width: lv_crediteelist.width
                                _index: (index + 1).toString()+"."
                                name: c_fname + " " + c_lname
                                id_no: c_idNo
                                isSelected: _index === (lv_crediteelist.currentIndex + 1).toString()+"."

                                onSelected: {
                                    lv_crediteelist.currentIndex = index
                                    selectedCreditee = id_no
                                }
                            }
                        }
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
                                root.accepted()
                                root.close()
                            }
                        }
                    }
                }
            }
        }
    }
}
