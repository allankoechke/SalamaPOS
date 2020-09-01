import QtQuick 2.0
import QtQuick.Layouts 1.3

import "../components"

Rectangle {
    id: root
    color: isCurrentSelected? "#266995":"#f1f3f5"

    property bool isCurrentSelected: false
    property string buttonLabel: ""
    property string buttonIcon: ""

    signal clicked()

    Layout.fillWidth: true
    Layout.preferredHeight: 40

    RowLayout
    {
        anchors.fill: parent
        spacing: 5

        Item
        {
            Layout.fillHeight: true
            Layout.preferredWidth: height

            AppIcon
            {
                anchors.centerIn: parent

                color: isCurrentSelected? "white":"#102d3f"
                size: 15
                icon: buttonIcon
            }
        }

        AppText
        {
            color: isCurrentSelected? "white":"#102d3f"
            text: buttonLabel

            Layout.fillWidth: true
            Layout.alignment: Qt.AlignVCenter
            horizontalAlignment: AppText.AlignLeft
        }
    }

    MouseArea
    {
        anchors.fill: parent
        onClicked: root.clicked();
    }
}
