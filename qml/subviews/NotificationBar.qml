import QtQuick 2.0
import QtQuick.Layouts 1.3

import "../components"

Rectangle {
    Layout.fillWidth: true
    Layout.preferredHeight: 80

    id: root
    color: QmlInterface.isDarkTheme? "#161719":"#fafdff"

    Rectangle
    {
        width: parent.width; height: 2; color: "black"; opacity: 0.08
        anchors.top: parent.bottom
    }

    RowLayout
    {
        anchors.fill: parent
        spacing: 10

        AppText
        {
            text: viewText
            size: 20
            color: QmlInterface.isDarkTheme? "white":"black"

            Layout.alignment: Qt.AlignVCenter|Qt.AlignLeft
            Layout.leftMargin: 50
        }

        HorizontalSpacer {}

        Item
        {
            Layout.fillHeight: true
            Layout.preferredWidth: t_state.width+60
            Layout.rightMargin: 5

            Row{
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                height: 50
                spacing: 10

                AppIcon
                {
                    icon: QmlInterface.isInternetConnected? "\uf1eb":"\uf6ac"
                    size: 40
                    color: QmlInterface.isInternetConnected? "green":"red"

                    //anchors.verticalCenter: parent.verticalCenter
                }

                Column
                {
                    anchors.verticalCenter: parent.verticalCenter
                    //anchors.left: parent.left
                    spacing: 5

                    AppText
                    {
                        id: t_state
                        text: "Internet Connection"
                        size: 11
                        color: QmlInterface.isDarkTheme? "white":"black"

                        //Layout.alignment: Qt.AlignVCenter|Qt.AlignLeft
                        //Layout.leftMargin: 50
                    }

                    AppText
                    {
                        text: QmlInterface.isInternetConnected? "ONLINE":"OFFLINE"
                        size: 12
                        font.bold: true
                        color: QmlInterface.isDarkTheme? "white":"black"

                        //Layout.alignment: Qt.AlignVCenter|Qt.AlignLeft
                        //Layout.leftMargin: 50
                    }
                }
            }
        }

        Rectangle
        {
            width: 1
            Layout.fillHeight: true
            color: QmlInterface.isDarkTheme? Qt.lighter("#161719", 1.8):Qt.darker("#fafdff", 1.5)
        }

        UserIcon
        {
            Layout.rightMargin: 20

            onClicked: {
                if (userMenuPopup.isOpen)
                    userMenuPopup.close()

                else
                    userMenuPopup.open();
            }
        }
    }
}
