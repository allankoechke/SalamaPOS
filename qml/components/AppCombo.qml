import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

Item
{
    Layout.fillWidth: true
    Layout.preferredHeight: 50

    property alias currentIndex: combo.currentIndex
    property alias label: textLabel.text
    property alias model: combo.model

    RowLayout
    {
        anchors.fill: parent
        spacing: 10

        Item
        {
            Layout.fillHeight: true
            Layout.preferredWidth: 150

            AppText
            {
                id: textLabel
                color: QmlInterface.isDarkTheme? "#f4f4f4":"#555555"
                size: 15

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
            }
        }

        Controls2.ComboBox
        {
            id: combo
            Layout.minimumHeight: 45
            Layout.fillWidth: true
            Layout.fillHeight: true

            font.pixelSize: 15
            font.family: montserratFontLoader.name
        }

        Rectangle
        {
            Layout.fillHeight: true
            Layout.preferredWidth: height
            radius: height/2
            color: menuColor

            AppIcon
            {
                color: "white"
                size: 15
                icon: "\uf067"

                anchors.centerIn: parent
            }
        }
    }
}
