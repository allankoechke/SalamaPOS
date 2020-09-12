import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

Item
{
    Layout.fillWidth: true
    Layout.preferredHeight: 30

    property string label
    property alias toggleSwitch: toggleSwitch
    property real prefWidth: 0
    property bool isChecked: false

    RowLayout
    {
        anchors.fill: parent
        spacing: 10

        Item
        {
            Layout.fillHeight: true
            Layout.fillWidth: true

            AppText
            {
                id: textLabel
                color: "#555555"
                size: 15
                text: label

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
            }
        }

        Item
        {
            Layout.fillHeight: true
            Layout.preferredWidth: toggleSwitch.width + 20

            Controls2.Switch
            {
                id: toggleSwitch
                Layout.fillWidth: true
                Layout.fillHeight: true
                checked: isChecked
                font.pixelSize: 15
                font.family: montserratFontLoader.name

                anchors.centerIn: parent
            }
        }
    }
}
