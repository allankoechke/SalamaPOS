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

    property bool isNewCrediteeMode: true
    property int currentIndex: -1
    property string orig_id: ""

    property alias fname: _fname.text
    property alias lname: _lname.text
    property alias mobile: _mobile.text
    property alias idNo: idno.text

    contentItem: Rectangle
    {
        color: QmlInterface.isDarkTheme? "#1e2027":bgColor
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
                    color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
                    height: 3
                    width: parent.width
                    opacity: 0.08

                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 5
                }

                AppText
                {
                    color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
                    size: 17
                    text: isNewCrediteeMode? qsTr("New Creditee Window"):qsTr("Update Creditee")

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
                        id: _fname
                        prefWidth: 150
                        label: qsTr("Firstname")
                        hintText: qsTr("Creditee firstname")
                        validator: RegExpValidator {regExp: RegExp("[a-zA-Z]+")}
                    }

                    AppTextInput
                    {
                        id: _lname
                        prefWidth: 150
                        label: qsTr("Last Name")
                        hintText: qsTr("Creditee lastname")
                        validator: RegExpValidator {regExp: RegExp("[a-zA-Z]+")}
                    }

                    AppTextInput
                    {
                        id: _mobile
                        prefWidth: 150
                        label: qsTr("Mobile No.")
                        hintText: qsTr("Creditee Mobile No.")
                        validator: RegExpValidator {regExp: RegExp("[0-9]+")}
                    }

                    AppTextInput
                    {
                        id: idno
                        prefWidth: 150
                        label: qsTr("National ID")
                        hintText: qsTr("Creditee ID No.")
                        validator: RegExpValidator {regExp: RegExp("[0-9]+")}
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
                                    onClicked: {
                                        root.mobile = ""
                                        root.idNo = ""
                                        root.fname = ""
                                        root.lname = ""
                                        root.close()
                                    }
                                }
                            }

                            Rectangle
                            {
                                Layout.fillHeight: true
                                Layout.preferredWidth: 180

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
                                        text: isNewCrediteeMode? qsTr("Add Creditee"):qsTr("Update Creditee")
                                    }
                                }

                                MouseArea
                                {
                                    anchors.fill: parent
                                    onClicked: {

                                        if(fname!=="" && lname !== "" && mobile!=="" && idNo!=="")
                                        {
                                            if(isNewCrediteeMode)
                                                CrediteeModel.addNewCreditee(fname, lname, mobile, idNo);

                                            else
                                                CrediteeModel.updateCreditee(fname, lname, mobile, idNo, orig_id);

                                        }

                                        else
                                        {
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
        target: CrediteeModel

        function onCrediteeAdded(status)
        {
            if(status)
            {
                fname = "";
                lname = "";
                idNo = "";
                mobile = "";

                root.close();
            }

            else
            {

            }
        }

        function onCrediteeUpdated(status)
        {
            if(status)
            {
                fname = "";
                lname = "";
                idNo = "";
                mobile = "";

                root.close();
            }

            else
            {

            }
        }

        function onIdExists()
        {
            console.log(" [ERROR] Unique ID Constrain fails")
        }
    }
}
