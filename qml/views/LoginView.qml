import QtQuick 2.3
import QtQuick.Layouts 1.3
import "../components"

Item {
    id: root
    Layout.fillWidth: true
    Layout.fillHeight: true

    property bool isError: false
    property string errorString: ""

    function clearFields()
    {
        _uname.text = "";
        _pswd.text = "";
        errorString = "";
    }

    Item {
        id: _root
        width: 400
        height: 450

        anchors.centerIn: parent

        ColumnLayout
        {
            anchors.fill: parent
            anchors.margins: 20

            Item {
                Layout.fillWidth: true
                Layout.preferredHeight: 60

                ColumnLayout
                {
                    anchors.centerIn: parent
                    spacing: 5

                    Item
                    {
                        Layout.fillWidth: true
                        Layout.preferredHeight: 30

                        RowLayout
                        {
                            anchors.centerIn: parent
                            spacing: 10

                            Image
                            {
                                visible: false
                                source: "qrc:/assets/images/6.png"
                                height: 30
                                fillMode: Image.PreserveAspectCrop

                                Layout.alignment: Qt.AlignVCenter|Qt.AlignLeft
                            }

                            AppText
                            {
                                color: "#ff8900"
                                text: qsTr("Salama P.O.S.")
                                font.pixelSize: 35

                                Layout.fillWidth: true
                                horizontalAlignment: AppText.AlignLeft
                            }
                        }
                    }

                    AppText
                    {
                        color: "#00a4c7"
                        text: qsTr("Point of sale technology")
                        font.pixelSize: 20
                        font.italic: true

                        Layout.fillWidth: true
                        horizontalAlignment: AppText.AlignHCenter
                    }
                }
            }

            Rectangle
            {
                color: QmlInterface.isDarkTheme? "#29292d":"white"
                radius: 5

                border.width: 1
                border.color: "silver"

                Layout.preferredWidth: _root.width*0.9
                Layout.preferredHeight: 200
                Layout.alignment: Qt.AlignHCenter

                ColumnLayout
                {
                    anchors.fill: parent
                    anchors.margins: 10
                    spacing: 5

                    LoginInputField
                    {
                        id: _uname
                        icon: "\uf007"
                        hintText: qsTr("Enter Username")
                        isCorrect: false
                    }

                    LoginInputField
                    {
                        id: _pswd
                        icon: "\uf084"
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
                                if(QmlInterface.databaseLoaded)
                                {
                                    var uname = _uname.text
                                    var pswd = _pswd.text

                                    // console.log("Accounts: ", AccountsModel.rowCount())
                                    if(uname !== "" && pswd !== "")
                                    {
                                        AccountsModel.loginUser(uname, pswd);
                                    }

                                    else
                                    {
                                        isError = true;
                                        errorString = qsTr("Required field is short")
                                        AlarmsModel.addAlarmItem("error", "Empty or short Fields!")
                                    }
                                }

                                else
                                    AlarmsModel.addAlarmItem("error", QmlInterface.databaseConnectionErrorString)

                            }
                        }
                    }

                    AppText
                    {
                        text: qsTr("Don't have an account? Create One")
                        size: 13
                        visible: false
                        color: QmlInterface.isDarkTheme? "grey":"#535353"

                        Layout.alignment: Qt.AlignHCenter
                        Layout.bottomMargin: 5

                        MouseArea
                        {
                            anchors.fill: parent
                            onClicked: {
                                if(QmlInterface.databaseLoaded)
                                    userAccountPopup.open()

                                else
                                    AlarmsModel.addAlarmItem("error", QmlInterface.databaseConnectionErrorString)
                            }
                        }
                    }
                }
            }

            AppText
            {
                color: isError? "red":"transparent"
                text: errorString
                visible: errorString!==""

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
                    AlarmsModel.addAlarmItem("error", "Invalid login credentials")
                }
            }

            function onLoggingInPasswordStatus(status)
            {
                // console.log("Status: ", status)

                if(!status)
                {
                    isError = true
                    errorString = qsTr("Invalid login details")
                    console.log(" [ERROR] Wrong Password")
                    AlarmsModel.addAlarmItem("error", "Invalid password")
                }

                else
                {
                    console.log(" [INFO] Correct Password")
                    startApp(true);
                    notificationBar.visible = true;
                    navBar.visible = true
                    navBarIndex = 0;

                    // Load the days sales
                    ProductSalesModel.showTodaysSales();

                    // Load Creditee Accounts
                    CrediteeModel.loadCrediteeAccounts();
                    QmlInterface.check4Update();

                    AlarmsModel.addAlarmItem("info", "Login successful!")
                }
            }

        }
    }
}
