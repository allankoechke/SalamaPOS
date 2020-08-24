import QtQuick 2.0
import QtQuick.Layouts 1.3

import "../components"

Rectangle
{
    id: root

    Layout.fillHeight: true
    Layout.preferredWidth: 160

    color: menuColor
    radius: 5

    property string label: ""
    property string _icon

    signal buttonClicked()

    RowLayout
    {
        anchors.fill: parent
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        spacing: 5

        AppText
        {
            color: "white"
            size: 18
            text: label

            Layout.alignment: Qt.AlignVCenter
        }

        AppIcon
        {
            size: 30
            color: "white"
            icon: _icon
            Layout.alignment: Qt.AlignVCenter
        }
    }

    MouseArea
    {
        anchors.fill: parent
        onClicked: root.buttonClicked()
    }
}
