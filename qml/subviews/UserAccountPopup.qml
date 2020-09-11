import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

import "../components"

Controls2.Popup
{
    id: root
    width: 500
    height: 600

    x: (mainApp.width - width)/2
    y: (mainApp.height - height)/2
    modal: true
    closePolicy: Controls2.Popup.NoAutoClose

    property bool isNewUserAccount: true

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
                    text: isNewUserAccount? qsTr("New User Account Window"):qsTr("Update My Account Details")

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

                    AppTextInput
                    {
                        id: fname
                        prefWidth: 150
                        label: qsTr("Firstname")
                        hintText: qsTr("Enter firstname")
                        //textInput.text: barCode===""? "":barCode
                    }

                    AppTextInput
                    {
                        id: lname
                        prefWidth: 150
                        label: qsTr("Lastname")
                        hintText: qsTr("Enter lastname")
                        //textInput.text: itemName===""? "":itemName
                    }

                    AppTextInput
                    {
                        id: uname
                        prefWidth: 150
                        label: qsTr("Username")
                        hintText: qsTr("Choose a username")
                        //textInput.text: itemUnit===""? "":itemUnit
                    }

                    AppTextInput
                    {
                        id: phoneNo
                        prefWidth: 150
                        label: qsTr("Mobile Phone")
                        hintText: qsTr("Enter phone number")
                        //textInput.text: itemBp===-1? "":itemBp
                    }

                    AppTextInput
                    {
                        id: pswd
                        prefWidth: 150
                        label: qsTr("Password")
                        hintText: qsTr("Pick a password")
                        //textInput.text: itemSp===-1? "":itemSp
                    }

                    AppTextInput
                    {
                        id: cpswd
                        prefWidth: 150
                        label: qsTr("Confirm password")
                        hintText: qsTr("Re-enter password")
                        //textInput.text: itemQty===-1? "":itemQty
                    }

                    // VerticalSpacer {}

                    Item
                    {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 30

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
                                        text: isNewUserAccount? qsTr("Add User"):qsTr("Update User")
                                    }
                                }

                                MouseArea
                                {
                                    anchors.fill: parent
                                    onClicked: {
                                        var _fname = fname.textInput.text
                                        var _lname = lname.textInput.text
                                        var _uname = uname.textInput.text
                                        var _phoneNo = phoneNo.textInput.text
                                        var _pswd = pswd.textInput.text
                                        var _cpswd = cpswd.textInput.text


                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    function addNewItemToDb(_barcode,_name,_unit,_bp,_sp,_qty,_company)
    {
        var tmspt = new Date().getTime();
        StockItemModel.addNewItem(_barcode,_name, _unit, _bp, _sp, parseInt(_qty), _company, tmspt, 1 /*category*/);
    }

    function updateItemInDb(_barcode,_name,_unit,_bp,_sp,_qty,_company)
    {
        StockItemModel.updateItem(_barcode, _name, _unit, _bp, _sp, _company, 1/*category*/, barCode, currentIndex);
    }

    Connections
    {
        target: StockItemModel

        function onItemUpdatedChanged(status)
        {
            if(status)
            {
                console.log(">> Item Updated Successfuly!");
                root.close();
            }

            else
                console.log(">> Error Updating item");
        }

        function onItemAddingChanged(status)
        {
            if(status)
            {
                console.log(">> Item Added Successfuly!");
                root.close();
            }

            else
                console.log(">> Error Adding item");
        }
    }
}
