import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    id: root
    enabled: !busy

    property string backgroundColor: menuColor
    property string foregroundColor: "#fff"
    property alias textIcon: ico
    property bool busy: false
    property alias radius: bg.radius
    property alias bgRect: bg

    background: Rectangle {
        id: bg
        color: backgroundColor
        opacity: root.enabled ? root.down ? 0.5 : root.hovered ? 0.8 : 1 : 0.3
    }

    contentItem: Item {
        BusyIndicator {
            visible: busy
            running: busy
            height: 32
            width: 32
            anchors.centerIn: parent
        }

        Row {
            spacing: 8
            anchors.centerIn: parent

            AppIcon
            {
                id: ico
                visible: icon !==""
                color: foregroundColor
                size: 15
                anchors.verticalCenter: parent.verticalCenter
            }

            AppText
            {
                visible: !busy
                color: foregroundColor
                size: 15
                text: root.text
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
}
