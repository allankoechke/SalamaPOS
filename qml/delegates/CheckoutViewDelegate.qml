import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4

import "../components"

Rectangle {
    id: root
    height: 45
    color: QmlInterface.isDarkTheme? (((_index+1)%2)===0? Qt.lighter("#29292d", 1.3):Qt.lighter("#29292d", 1.5)):(((_index+1)%2)===0? "#eeeeee":"white")

    property int _index
    property string itemName
    property string unit
    property int qty
    property int sp
    property string _barcode

    signal deleted()
    signal edited()

    RowLayout
    {
        anchors.fill: parent
        spacing: 1

        AppText
        {
            color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
            text: (_index+1).toString()+"."
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 50
        }

        AppText
        {
            color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
            text: " " + unit + "  " + itemName
            horizontalAlignment: AppText.AlignLeft

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.minimumWidth: 150
            Layout.maximumWidth: 450
        }

        AppText
        {
            color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
            text: qty.toString()
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 100
        }

        AppText
        {
            color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
            text: sp.toString()
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 200
        }

        AppText
        {
            color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
            text: (qty*sp).toString()
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 200
        }

        Item{
            Layout.preferredWidth: 100
            Layout.fillHeight: true

            RowLayout
            {
                anchors.centerIn: parent

                AppIcon
                {
                    size: 15
                    color: menuColor
                    icon: "\uf5a1"

                    Layout.alignment: Qt.AlignVCenter
                }

                AppText
                {
                    color: "black"
                    text: qsTr("Change")

                    Layout.alignment: Qt.AlignVCenter
                }
            }

            MouseArea
            {
                anchors.fill: parent
                onClicked: root.edited();
            }
        }

        Item{
            Layout.fillHeight: true
            Layout.preferredWidth: 30
            Layout.leftMargin: 5
            Layout.rightMargin: 5

            AppIcon
            {
                size: 15
                color: "red"
                icon: "\uf1f8"

                anchors.centerIn: parent
            }

            MouseArea
            {
                anchors.fill: parent
                onClicked: root.deleted()
            }
        }
    }
}
