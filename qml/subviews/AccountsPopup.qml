import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

import "../components"

Controls2.Popup
{
    id: root
    width: 450
    height: 520

    x: (mainApp.width - width)/2
    y: (mainApp.height - height)/2
    modal: true
    closePolicy: Controls2.Popup.NoAutoClose

    property int currentIndex: -1
    property string currentUser: ""
    property bool canCreateUser: false
    property bool canDeleteUser: false
    property bool canCreateItems: false
    property bool canDeleteItems: false
    property bool canAddStock: false
    property bool canDeleteStock: false
    property bool canDeleteSales: false
    property bool canBackupDb: false

    onClosed:
    {
        currentIndex = -1
        currentUser = ""
        canCreateUser = false
        canDeleteUser = false
        canCreateItems = false
        canDeleteItems = false
        canAddStock = false
        canDeleteStock = false
        canDeleteSales = false
        canBackupDb = false
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
                    text: qsTr("Edit User Accounts")

                    anchors.centerIn: parent
                }
            }

            Item
            {
                Layout.fillWidth: true
                Layout.fillHeight: true

                ColumnLayout
                {
                    anchors.fill: parent
                    spacing: 10

                    AppToggle
                    {
                        id: addUsers
                        prefWidth: 150
                        label: qsTr("Can Add New User Accounts")
                        isChecked: canCreateUser
                    }

                    AppToggle
                    {
                        id: deleteUsers
                        prefWidth: 150
                        label: qsTr("Can Remove User Accounts")
                        isChecked: canDeleteUser
                    }

                    AppToggle
                    {
                        id: addProducts
                        prefWidth: 150
                        label: qsTr("Can Add New Products")
                        isChecked: canCreateItems
                    }

                    AppToggle
                    {
                        id: deleteProducts
                        prefWidth: 150
                        label: qsTr("Can Remove/Delete Products")
                        isChecked: canDeleteItems
                    }

                    AppToggle
                    {
                        id: addStock
                        prefWidth: 150
                        label: qsTr("Can Add Stock")
                        isChecked: canAddStock
                    }

                    AppToggle
                    {
                        id: deleteStock
                        prefWidth: 150
                        label: qsTr("Can Remove/Delete Stock")
                        isChecked: canDeleteStock

                    }

                    AppToggle
                    {
                        id: deleteSales
                        prefWidth: 150
                        label: qsTr("Can Undo/Delete Sales")
                        isChecked: canDeleteSales
                    }

                    AppToggle
                    {
                        id: backup
                        prefWidth: 150
                        label: qsTr("Can Backup the Database")
                        isChecked: canBackupDb
                    }

                    Item
                    {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 30

                        RowLayout
                        {
                            anchors.fill: parent
                            spacing: 10

                            Rectangle
                            {
                                Layout.fillHeight: true
                                Layout.preferredWidth: 100

                                color: "#b8352c"
                                radius: 3


                                AppText
                                {
                                    color: "white"
                                    size: 15
                                    text: qsTr("Delete User")

                                    anchors.centerIn: parent
                                }

                                MouseArea
                                {
                                    anchors.fill: parent
                                    onClicked: AccountsModel.removeUserAccount(currentUser, currentIndex);
                                }
                            }

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
                                        icon: "\uf560"
                                    }

                                    AppText
                                    {
                                        color: "white"
                                        size: 15
                                        text: qsTr("Update Roles")
                                    }
                                }

                                MouseArea
                                {
                                    anchors.fill: parent
                                    onClicked: {
                                        var _addUsers = addUsers.toggleSwitch.checked
                                        var _removeUsers = addUsers.toggleSwitch.checked
                                        var _addItems = addProducts.toggleSwitch.checked
                                        var _removeItems = deleteProducts.toggleSwitch.checked
                                        var _addStock = addStock.toggleSwitch.checked
                                        var _removeStock = deleteStock.toggleSwitch.checked
                                        var _undoSales = deleteSales.toggleSwitch.checked
                                        var _backupDb = backup.toggleSwitch.checked

                                        console.log(currentUser, " : ", _addUsers, " : ", _removeUsers, " : ", _addItems, " : ", _removeItems, " : ", _addStock, " : ", _removeStock, " : ", _undoSales, " : ", _backupDb)

                                        AccountsModel.updateUserAccount(currentUser, _addUsers, _removeUsers, _addItems, _removeItems, _addStock, _removeStock, _undoSales, _backupDb);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    Connections
    {
        target: AccountsModel

        function onUserRemovedChanged(status)
        {
            if(status)
            {
                console.log(">> User deleted successfully!");
                root.close();
            }

            else
                console.log(">> Error Deleting User");
        }

        function onUserPriviledgesChanged(status)
        {
            if(status)
            {
                console.log(">> User priviledges updated Successfuly!");
                root.close();
            }

            else
                console.log(">> Error Updating User Priviledges");
        }
    }
}
