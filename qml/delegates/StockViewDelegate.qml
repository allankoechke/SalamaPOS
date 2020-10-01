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
    property string barCode
    property string _unit
    property int qty
    property string lastUpdated

    signal clicked()

    RowLayout
    {
        anchors.fill: parent
        spacing: 1

        AppText
        {
            color: QmlInterface.isDarkTheme? "#999fa6":"black"
            text: (_index+1).toString()+"."
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 50
        }

        Item{
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.minimumWidth: 150
            Layout.leftMargin: 5

            AppText
            {
                color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
                text: " " + itemName
                width: parent.width
                elide: AppText.ElideRight
                horizontalAlignment: AppText.AlignLeft

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
            }
        }

        Item{
            Layout.fillHeight: true
            Layout.preferredWidth: 150
            Layout.leftMargin: 5

            AppText
            {
                color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
                text: barCode
                width: parent.width
                elide: AppText.ElideRight
                horizontalAlignment: AppText.AlignLeft

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
            }
        }

        Item{
            Layout.fillHeight: true
            Layout.preferredWidth: 100
            Layout.leftMargin: 5

            AppText
            {
                color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
                text: _unit
                width: parent.width
                elide: AppText.ElideRight
                horizontalAlignment: AppText.AlignLeft

                Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            }
        }

        AppText
        {
            color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
            text: qty.toString()
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 100
            Layout.leftMargin: 5
        }

        Item{
            Layout.preferredWidth: 150
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
                    color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
                    text: qsTr("Change")

                    Layout.alignment: Qt.AlignVCenter
                }
            }

            MouseArea
            {
                anchors.fill: parent
                onClicked: root.clicked()
            }
        }

        Item{
            Layout.fillWidth: true
            Layout.minimumWidth: 150
            Layout.maximumWidth: 300
            Layout.leftMargin: 5

            AppText
            {
                color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
                text: lastUpdated
                width: parent.width
                elide: AppText.ElideRight
                horizontalAlignment: AppText.AlignHCenter

                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
}
