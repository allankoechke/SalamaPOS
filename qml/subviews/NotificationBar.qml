import QtQuick 2.0
import QtQuick.Layouts 1.3

import "../components"

Rectangle {
    Layout.fillWidth: true
    Layout.preferredHeight: 80

    id: root
    color: "#fafdff"

    Rectangle
    {
        width: parent.width; height: 2; color: "black"; opacity: 0.08
        anchors.top: parent.bottom
    }

    RowLayout
    {
        anchors.fill: parent
        spacing: 10

        AppText
        {
            text: viewText
            size: 20

            Layout.alignment: Qt.AlignVCenter|Qt.AlignLeft
            Layout.leftMargin: 50
        }

        HorizontalSpacer {}

        UserIcon
        {

            Layout.rightMargin: 20
        }
    }
}
