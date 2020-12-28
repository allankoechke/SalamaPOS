import QtQuick 2.0
import QtQuick.Controls 2.2 as QQC2
import QtQuick.Controls.Material 2.2

Item {
    property alias background: background
    property real depth: 6

    QQC2.Pane
    {
        height: parent.height
        width: parent.width
        Material.elevation: depth

        contentItem: Rectangle
        {
            id: background
            anchors.fill: parent
        }
    }
}
