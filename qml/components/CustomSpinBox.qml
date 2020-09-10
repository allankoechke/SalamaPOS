import QtQuick 2.0
import QtQuick.Controls 2.4 as Controls2
import QtQuick.Layouts 1.3

import "../components"

Item
{
    Layout.fillWidth: true
    Layout.fillHeight: true

    property real from: 0
    property real to: 1000000
    property real value: from

    RowLayout
    {
        anchors.fill: parent
        spacing: 1

        Rectangle
        {
            Layout.fillHeight: true
            Layout.preferredWidth: 40
            color: Qt.lighter(menuColor)
            enabled: value > from
            opacity: enabled? 1:0.3

            AppIcon
            {
                anchors.centerIn: parent

                size: 20
                color: "white"
                icon: "\uf068"
            }

            MouseArea
            {
                anchors.fill: parent
                onClicked: {
                    if(value > from)
                    {
                        value -= 1;
                    }
                }
            }
        }

        Controls2.TextField
        {
            id: textField
            font.pixelSize: 25
            font.family: montserratFontLoader.name
            color: "black"
            text: value.toString()
            readOnly: true

            Layout.fillWidth: true
            Layout.fillHeight: true
            horizontalAlignment: AppText.AlignHCenter
            Layout.alignment: Qt.AlignVCenter
        }

        Rectangle
        {
            Layout.fillHeight: true
            Layout.preferredWidth: 40
            color: Qt.lighter(menuColor)
            enabled: value<to
            opacity: enabled? 1:0.3

            AppIcon
            {
                anchors.centerIn: parent

                size: 20
                color: "white"
                icon: "\uf067"
            }

            MouseArea
            {
                anchors.fill: parent
                onClicked: {
                    if(value < to)
                    {
                        value += 1;
                    }
                }
            }
        }
    }
}
