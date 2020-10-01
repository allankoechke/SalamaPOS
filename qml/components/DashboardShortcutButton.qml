import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

import "../components"

Rectangle
{
    id: root
    Layout.fillWidth: true
    Layout.preferredHeight: 35

    radius: height/2
    color: Qt.lighter(menuColor, 1.7)

    property alias icon: ico.icon
    property alias label: lbl.text

    signal clicked()

    RowLayout
    {
        anchors.fill: parent
        spacing: 5

        Rectangle
        {
            Layout.fillHeight: true
            Layout.preferredWidth: height

            radius: height/2
            color: Qt.darker(root.color, 1.2)

            AppIcon
            {
                id: ico
                anchors.centerIn: parent

                size: 18
                color: "white"
            }
        }


        AppText
        {
            id: lbl
            Layout.fillHeight: true
            Layout.fillWidth: true
            horizontalAlignment: AppIcon.AlignLeft
            verticalAlignment: AppIcon.AlignVCenter

            color: "white"
            size: 18
        }

        AppIcon
        {
            Layout.fillHeight: true
            Layout.preferredWidth: height
            horizontalAlignment: AppIcon.AlignHCenter
            verticalAlignment: AppIcon.AlignVCenter

            size: 25
            icon: "\uf105"
            color: "white"
        }
    }

    MouseArea
    {
        anchors.fill: parent
        onClicked: root.clicked()
    }
}

