import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

import "../components"

Popup {
    width: 250
    height: 250
    modal: !true

    x: mainApp.width - width -20
    y: 77

    property bool isOpen: false

    onOpened: isOpen = true
    onClosed: isOpen = false

    Rectangle
    {
        color: bgColor
        width: 30
        height: 30
        rotation: 45
        border.width: 1
        border.color: Qt.darker(color)

        anchors.top: parent.top
        anchors.right: parent.right
        anchors.topMargin: -14
        anchors.rightMargin: 6.5
    }

    contentItem: Rectangle
    {
        color: bgColor
        anchors.fill: parent
        border.color: Qt.darker(color)
        border.width: 1
    }

    Rectangle
    {
        color: bgColor
        anchors.fill: parent
        border.color: Qt.darker(color)
        border.width: 1

        ColumnLayout
        {
            anchors.fill: parent
            anchors.margins: 2
            spacing: 1

            Item{
                Layout.fillWidth: true
                Layout.fillHeight: true

                Rectangle
                {
                    color: Qt.lighter(menuColor, 2)
                    height: parent.height
                    width: 1
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.leftMargin: 27
                }

                ColumnLayout
                {
                    anchors.fill: parent
                    spacing: 2
                    anchors.leftMargin: 30

                    AppText
                    {
                        color: "#535353"
                        text: "> " + loggedUser_fullname
                        size: 13
                    }

                    AppText
                    {
                        color: "#535353"
                        text: "> " + loggedUser_username
                        size: 12
                    }

                    AppText
                    {
                        color: "#535353"
                        text: "> " + Qt.formatDateTime(new Date(), "dd MMM, yyyy hh:mm AP")
                        size: 8
                    }
                }
            }

            CommandButton
            {
                Layout.fillWidth: true
                Layout.preferredHeight: 40
                background: Qt.lighter(menuColor, 1.6)
                text: qsTr("View My Account")
                forecolor: "white"
                icon: "\uf007"
            }

            CommandButton
            {
                Layout.fillWidth: true
                Layout.preferredHeight: 40
                background: Qt.lighter(menuColor, 1.6)
                text: qsTr("Edit My Account")
                forecolor: "white"
                icon: "\uf4ff"
            }

            CommandButton
            {
                Layout.fillWidth: true
                Layout.preferredHeight: 40
                background: Qt.lighter(menuColor, 1.6)
                text: qsTr("Change password")
                forecolor: "white"
                icon: "\uf084"
            }

            CommandButton
            {
                Layout.fillWidth: true
                Layout.preferredHeight: 40
                background: Qt.lighter(menuColor, 1.4)
                text: qsTr("Sign Out")
                forecolor: "white"
                icon: "\uf2f5"
            }
        }
    }
}
