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
    property bool isError: false
    property string errorText: ""

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

                    AppText
                    {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 25
                        horizontalAlignment: AppText.AlignHCenter
                        verticalAlignment: AppText.AlignVCenter
                        color: isError? "red":"transparent"
                        text: errorText
                    }

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

                                        console.log(">> ", _fname, " : ", _lname, " : ", _uname, " : ", _phoneNo, " : ", _pswd, " : ", _cpswd)

                                        if(_fname!=="" && _lname!=="" && _uname!=="" && _phoneNo!=="" && _pswd !=="" && cpswd!=="")
                                        {
                                            if(_pswd === _cpswd)
                                            {
                                                var tmspt = new Date().getTime();
                                                AccountsModel.addNewUserAccount(_fname, _lname,_uname,_pswd,_phoneNo, tmspt);
                                                // isError = false;
                                            }

                                            else
                                            {
                                                isError = true;
                                                errorText = qsTr("Passwords do not match")
                                                console.log("Passwords do not match")
                                            }
                                        }

                                        else
                                        {
                                            isError = true;
                                            errorText = qsTr("Some required fields are short!")
                                        }
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

        function onUserAddedChanged(status)
        {
            if(status)
            {
                console.log(">> User Added Successfuly!");
                root.close();
            }

            else
                console.log(">> Error Adding User");
        }

        function onUserUpdatedChanged(status)
        {
            if(status)
            {
                console.log(">> User Details updated Successfuly!");
                resetFields();
                root.close();
            }

            else
                console.log(">> Error Updating User");
        }

        function onUsernameExistsChanged(status)
        {
            console.log(">> QML: Username taken")
            isError = true;
            errorText = qsTr("The username is already taken!")
        }
    }

    function resetFields()
    {
        fname.textInput.text = ""
        lname.textInput.text = ""
        uname.textInput.text = ""
        phoneNo.textInput.text = ""
        pswd.textInput.text = ""
        cpswd.textInput.text = ""
    }
}
