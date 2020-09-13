import QtQuick 2.3
import QtQuick.Layouts 1.3
import "../components"

Item {
    id: root
    Layout.fillWidth: true
    Layout.fillHeight: true

    property bool isError: false
    property string errorString: ""

    Item {
        id: _root
        width: 400
        height: 600

        anchors.centerIn: parent

        ColumnLayout
        {
            anchors.fill: parent
            anchors.margins: 20

            Item
            {
                Layout.fillWidth: true
                Layout.preferredHeight: 50

                RowLayout
                {
                    anchors.fill: parent
                    spacing: 10

                    AppIcon
                    {
                        color: menuColor
                        size: 30
                        icon: "\uf78a"

                        Layout.alignment: Qt.AlignVCenter|Qt.AlignLeft
                    }

                    AppText
                    {
                        color: menuColor
                        text: qsTr("MySale Pro")
                        font.pixelSize: 25

                        Layout.fillWidth: true
                        horizontalAlignment: AppText.AlignLeft
                    }
                }
            }

            Rectangle
            {
                color: "white"
                radius: 5

                border.width: 1
                border.color: "silver"

                Layout.preferredWidth: _root.width*0.8
                Layout.preferredHeight: 230
                Layout.alignment: Qt.AlignHCenter

                ColumnLayout
                {
                    anchors.fill: parent
                    anchors.margins: 10
                    spacing: 5

                    LoginInputField
                    {
                        id: _uname
                        ico: "\uf007"
                        hintText: qsTr("Enter Username")
                        isCorrect: false
                    }

                    LoginInputField
                    {
                        id: _pswd
                        ico: "\uf084"
                        hintText: qsTr("Enter Password")
                        isCorrect: false
                        isPassword: true
                    }

                    Rectangle
                    {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 35
                        Layout.rightMargin: 20
                        Layout.leftMargin: 20

                        color: menuColor
                        radius: height/2

                        AppText
                        {
                            color: "white"
                            text: qsTr("Sign in")
                            font.pixelSize: 17

                            anchors.centerIn: parent
                        }

                        MouseArea
                        {
                            anchors.fill: parent
                            onClicked: {
                                var uname = _uname.textInput.text
                                var pswd = _pswd.textInput.text

                                if(uname !== "" && pswd !== "")
                                {
                                    AccountsModel.loginUser(uname, pswd);
                                }

                                else
                                {
                                    isError = true;
                                    errorString = qsTr("Required field is short")
                                }
                            }
                        }
                    }
                }
            }

            AppText
            {
                color: isError? "red":"transparent"
                text: errorString

                Layout.alignment: Qt.AlignHCenter

            }
        }

        Connections
        {
            target: AccountsModel
            function onLoggingInUsernameStatus(status)
            {
                if(!status)
                {
                    isError = true
                    errorString = qsTr("Invalid login details")
                    console.log("Username doesnt exist")
                }
            }

            function onLoggingInPasswordStatus(status)
            {
                if(!status)
                {
                    isError = true
                    errorString = qsTr("Invalid login details")
                    console.log("Wrong Password")
                }

                else
                    startApp(true);
            }

        }
    }
}
