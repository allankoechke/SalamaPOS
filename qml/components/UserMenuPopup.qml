import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

import "../components"

Popup {
    width: 250
    height: 300
    modal: !true

    x: mainApp.width - width -20
    y: 77

    Rectangle
    {
        color: bgColor
        width: 30
        height: 30
        rotation: 45
        border.width: 1
        border.color: Qt.darker(color)

        anchors.top: parent.top
        anchors.right: parent.right
        anchors.topMargin: -14
        anchors.rightMargin: 6.5
    }

    contentItem: Rectangle
    {
        color: bgColor
        anchors.fill: parent
        border{
            color: Qt.darker(color)
            width: 1
        }
    }

    Rectangle
    {
        anchors.fill: parent
        color: bgColor
        anchors.margins: 1

        ColumnLayout
        {
            anchors.fill: parent
            anchors.topMargin: 5
            anchors.bottomMargin: 5


        }
    }
}
