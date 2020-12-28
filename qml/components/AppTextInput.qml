import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

Item
{
    Layout.fillWidth: true
    Layout.preferredHeight: 40

    property alias label: textLabel.text
    property alias readOnly: textInput.readOnly
    property real prefWidth: 0
    property alias text: textInput.text
    property alias validator: textInput.validator
    property alias hintText: textInput.placeholderText
    property alias echoMode: textInput.echoMode
    property alias labelSize: textLabel.size
    property alias inputSize: textInput.font.pixelSize

    RowLayout
    {
        anchors.fill: parent
        spacing: 10

        Item
        {
            Layout.fillHeight: true
            Layout.preferredWidth: prefWidth===0? textLabel.width:prefWidth

            AppText
            {
                id: textLabel
                color: QmlInterface.isDarkTheme? "#f4f4f4":"#555555"
                size: 15

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
            }
        }

        Controls2.TextField
        {
            id: textInput
            Layout.fillWidth: true
            Layout.fillHeight: true
            verticalAlignment: Controls2.TextField.AlignBottom
            horizontalAlignment: Controls2.TextField.AlignLeft

            color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
            selectByMouse: true
            font.pixelSize: 15
            font.family: montserratFontLoader.name
        }
    }
}
