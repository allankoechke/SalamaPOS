import QtQuick 2.0
import QtQuick.Layouts 1.3
import "../components"

Item{
    Layout.fillWidth: true
    Layout.preferredHeight: 40

    property string hintText: ""
    property string ico: ""
    //property alias text: txt.text
    property bool isCorrect: false
    property bool isPassword: false

    RowLayout
    {
        anchors.fill: parent
        spacing: 10

        AppIcon
        {
            color: menuColor
            size: 18
            icon: ico

            Layout.alignment: Qt.AlignVCenter
        }

        TextInput
        {
            id: txt
            text: ""
            color: menuColor
            font.pixelSize: 15
            echoMode: isPassword? TextInput.Password:TextInput.Normal

            Layout.fillWidth: true
            Layout.preferredHeight: 30
            verticalAlignment: TextInput.AlignVCenter
            horizontalAlignment: AppText.AlignLeft

            AppText
            {
                color: menuColor
                opacity: 0.5
                text: hintText
                font.pixelSize: 13
                visible: parent.text === ""
                height: parent.height
                verticalAlignment: AppText.AlignVCenter

                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }

            Rectangle
            {
                color: "black"
                height: 2
                width: parent.width
                opacity: 0.09

                anchors.bottom: parent.bottom
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
