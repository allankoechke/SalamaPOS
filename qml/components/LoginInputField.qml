import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4
import "../components"

Item{
    Layout.fillWidth: true
    Layout.preferredHeight: 40

    property alias hintText: txt.placeholderText
    property alias text: txt.text
    property alias icon: ico.icon
    property alias textInput: txt
    property bool isCorrect: false
    property bool isPassword: false

    RowLayout
    {
        anchors.fill: parent
        spacing: 20

        AppIcon
        {
            id: ico
            color: menuColor
            size: 25

            Layout.alignment: Qt.AlignVCenter
        }

        TextField
        {
            id: txt
            text: ""
            color: "black"
            font.pixelSize: text===""? 13:15
            placeholderText: hintText
            echoMode: isPassword? TextInput.Password:TextInput.Normal

            Layout.fillWidth: true
            Layout.leftMargin: 5
            Layout.preferredHeight: 30
            verticalAlignment: TextInput.AlignVCenter
            horizontalAlignment: AppText.AlignLeft

            background: Rectangle
            {
                color: "transparent"
                border.width: 0
            }

            Rectangle
            {
                color: "silver"
                height: 1
                width: parent.width + 10

                anchors.bottom: parent.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottomMargin: -5
            }
        }

        AppIcon
        {
            color: "green"
            size: 16
            icon: isCorrect? "\uf00c":""

            Layout.alignment: Qt.AlignVCenter
        }
    }
}
