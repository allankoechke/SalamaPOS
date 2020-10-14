import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

import "../components"

Drawer {
    id: root

    width: 300
    height: 50
    edge: Qt.RightEdge
    interactive: false
    closePolicy: Drawer.NoAutoClose

    property string alarmId
    property alias content: txt.text
    property string category

    contentItem: Rectangle
    {
        color: bgColor
        radius: 5
        anchors.fill: parent

        RowLayout
        {
            anchors.fill: parent
            spacing: 5

            AppIcon
            {
                Layout.fillHeight: true
                Layout.preferredWidth: 40
            }

            Item{
                Layout.fillWidth: true
                Layout.fillHeight: true

                AppText
                {
                    id: txt
                    width: parent.width-20
                    color: "white"
                    wrapMode: AppText.WordWrap
                    elide: AppText.ElideRight
                }

            }

            Rectangle
            {
                color: bgColor

            }
        }
    }
}
