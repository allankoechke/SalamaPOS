import QtQuick 2.0
import QtQuick.Controls 2.4

Button
{
    id: root

    property string color
    property string pressedColor: QmlInterface.isDarkTheme? Qt.lighter(normalColor, 1.5):Qt.darker(normalColor, 1.4)
    property string normalColor: color
    property alias border: bg.border
    property alias radius: bg.radius

    background: Rectangle
    {
        id: bg
        opacity: root.pressed? 0.7:1
        scale: root.pressed? 0.95:1
        color: root.pressed? 'grey':root.color

        Behavior on color{ NumberAnimation { duration: 300 }}
        NumberAnimation on opacity { duration: 300; to: root.pressed? 0.7:1  }
        NumberAnimation on scale { duration: 300; to: root.pressed? 0.95:1 }
    }
}
