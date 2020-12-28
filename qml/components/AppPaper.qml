import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Material.impl 2.12

Item {
    id: root
    property int radius: 2
    property real elevation: 6
    property string color

    Pane {
        id: control
        anchors.fill: parent
        anchors.margins: 2

        background: Rectangle {
            color: root.color
            radius: root.radius

            layer.enabled: true
            layer.effect: ElevationEffect {
                elevation: root.elevation
            }
        }
    }
}
