import QtQuick 2.0
import QtQuick.Window 2.3
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Material 2.2

import "../delegates"
import "../components"

Window {
    id: myWindow

    property alias x: myWindow.x
    property alias y: myWindow.y

    flags:  Qt.Dialog | Qt.WindowCloseButtonHint
    modality: Qt.ApplicationModal
    color: bgColor
    width: 700
    height: 600

    onClosing: {
        close.accepted = false
        close.accepted = true
    }


    ColumnLayout
    {
        anchors.fill: parent
        anchors.margins: 30
        spacing: 1

        Item{
            Layout.fillWidth: true
            Layout.preferredHeight: 50
        }

        ListView
        {
            id: listView
            Layout.fillWidth: true
            Layout.fillHeight: true
            model: 16
            delegate: Item{
                height: 35
                width: listView.width

                Rectangle
                {
                    height: parent.height-2
                    width: parent.width-10
                    anchors.centerIn: parent
                    color: '#ddd'
                }
            }
        }
    }
}
