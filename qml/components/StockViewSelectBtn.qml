import QtQuick 2.0
import QtQuick.Layouts 1.3

import "../components"

Rectangle {
    id: root

    Layout.preferredHeight: 25
    Layout.preferredWidth: isCurrentlySelected? _icon.width+_txt.width+40:_icon.width+_txt.width+30

    property bool isCurrentlySelected: false
    property string buttonLabel: ""
    property string buttonIcon: ""

    signal clicked

    color: isCurrentlySelected? "#d3e5ff":"transparent" // isCurrentlySelected? "#595a6e":"#d3e5ff"
    radius: 5

    Rectangle
    {
        visible: isCurrentlySelected
        color: "#366dff"
        width: parent.width
        height: 5
        radius: height/2

        anchors.bottom: parent.bottom
        anchors.bottomMargin: -10
    }

    RowLayout
    {
        anchors.centerIn: parent

        spacing: 10

        AppIcon
        {
            id: _icon
            size: 18
            color: isCurrentlySelected? "#2e2e2e":"#595a6e"
            icon: buttonIcon

            Layout.alignment: Qt.AlignVCenter
        }

        AppText
        {
            id: _txt
            font.pixelSize: 18
            color: isCurrentlySelected? "#2e2e2e":"#595a6e"
            text: buttonLabel

            Layout.alignment: Qt.AlignVCenter
        }
    }

    MouseArea
    {
        anchors.fill: parent
        onClicked: root.clicked();
    }
}
