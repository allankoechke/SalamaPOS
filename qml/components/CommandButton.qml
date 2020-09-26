import QtQuick 2.0
import QtQuick.Layouts 1.2
import QtQuick.Controls.Material 2.2

import "../components"

Item {
    property alias background: btn.color
    property alias text: txt.text
    property real depth: 10
    property alias icon: ico.icon
    property alias forecolor: txt.color

    Rectangle
    {
        id: btn
        radius: 1
        anchors.fill: parent
        Material.elevation: depth

        RowLayout
        {
            anchors.fill: parent
            spacing: 1

            AppIcon
            {
                id: ico
                color: txt.color
                size: 15
                horizontalAlignment: AppIcon.AlignHCenter
                verticalAlignment: AppIcon.AlignVCenter

                Layout.fillHeight: true
                Layout.preferredWidth: height
                Layout.alignment: Qt.AlignVCenter
            }

            AppText
            {
                id: txt
                color: "white"
                Layout.fillWidth: true
                Layout.fillHeight: true

                Layout.alignment: Qt.AlignVCenter | Qt.AlignLeft
                horizontalAlignment: AppText.AlignLeft
                verticalAlignment: AppText.AlignVCenter
            }
        }
    }
}
