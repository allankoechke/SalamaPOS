import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

import "../components"

Popup {
    id: root

    width: 250
    height: 200
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
            }

            CommandButton
            {
                Layout.fillWidth: true
                Layout.preferredHeight: 40
                background: Qt.lighter(menuColor, 1.6)
                text: qsTr("View My Account")
                forecolor: "white"
                icon: "\uf007"

                onClicked: {
                    userAccountPopup.open()
                    userAccountPopup.isNewUserAccount = false;
                    userAccountPopup.editable = false
                    userAccountPopup.ufname = loggedUser_fullname.split(" ")[0]
                    userAccountPopup.ulname = loggedUser_fullname.split(" ")[1]
                    userAccountPopup.u_name = loggedUser_username
                    userAccountPopup.uphone = loggedUser_mobile
                    userAccountPopup.height = 400
                    root.close()
                }
            }

            CommandButton
            {
                Layout.fillWidth: true
                Layout.preferredHeight: 40
                background: Qt.lighter(menuColor, 1.6)
                text: qsTr("Edit My Account")
                forecolor: "white"
                icon: "\uf4ff"

                onClicked: {
                    userAccountPopup.open();
                    userAccountPopup.editable = true;
                    userAccountPopup.isNewUserAccount = false;
                    userAccountPopup.ufname = loggedUser_fullname.split(" ")[0]
                    userAccountPopup.ulname = loggedUser_fullname.split(" ")[1]
                    userAccountPopup.u_name = loggedUser_username
                    userAccountPopup.uphone = loggedUser_mobile
                    userAccountPopup.height = 400
                    root.close()
                }
            }

            CommandButton
            {
                Layout.fillWidth: true
                Layout.preferredHeight: 40
                background: Qt.lighter(menuColor, 1.6)
                text: qsTr("Change password")
                forecolor: "white"
                icon: "\uf084"

                onClicked: root.close()
            }

            CommandButton
            {
                Layout.fillWidth: true
                Layout.preferredHeight: 40
                background: Qt.lighter(menuColor, 1.4)
                text: qsTr("Sign Out")
                forecolor: "white"
                icon: "\uf2f5"

                onClicked: {
                    navBarIndex = 8;
                    loginView.clearFields();
                    navBar.visible = false;
                    notificationBar.visible = false;
                    root.close()
                }
            }

            Item{
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
        }
    }
}
