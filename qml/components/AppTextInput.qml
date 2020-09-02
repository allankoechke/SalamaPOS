import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

Item
{
    Layout.fillWidth: true
    Layout.preferredHeight: 30

    property string label
    property alias textInput: textInput

    RowLayout
    {
        anchors.fill: parent
        spacing: 10

        AppText
        {
            color: "#555555"
            size: 15
            text: label
        }

        Controls2.TextField
        {
            id: textInput
            Layout.fillWidth: true
            Layout.fillHeight: true
            verticalAlignment: Controls2.TextField.AlignVCenter
            horizontalAlignment: Controls2.TextField.AlignLeft

            color: "#535353"
            font.pixelSize: 15
            font.family: montserratFontLoader.name

        }
    }
}
