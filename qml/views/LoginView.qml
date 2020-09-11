import QtQuick 2.3
import QtQuick.Layouts 1.3
import "../components"

Item {
    id: root
    Layout.fillWidth: true
    Layout.fillHeight: true

    property bool isAnimationRunning: !true

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

            Layout.preferredWidth: root.width*0.8
            Layout.preferredHeight: 230
            Layout.alignment: Qt.AlignHCenter

            ColumnLayout
            {
                anchors.fill: parent
                anchors.margins: 10
                spacing: 5

                LoginInputField
                {
                    ico: "\uf007"
                    hintText: qsTr("Enter Username")
                    isCorrect: false
                }

                LoginInputField
                {
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
                        onClicked: startApp(true);
                    }
                }
            }
        }
    }
}
