import QtQuick 2.12
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

Rectangle
{
    Layout.fillWidth: true
    Layout.preferredHeight: 45

    radius: 5
    color: menuColor

    property alias icon: ico.icon
    property alias text: txt.text
    property alias cost: cost.text

    RowLayout
    {
        anchors.fill: parent
        spacing: 3

        AppIcon
        {
            id: ico
            Layout.preferredHeight: 40
            Layout.preferredWidth: 35
            Layout.alignment: Qt.AlignVCenter

            horizontalAlignment: AppIcon.AlignHCenter
            verticalAlignment: AppIcon.AlignVCenter
            color: "white"
            size: 23
            icon: ""
        }

        Rectangle
        {
            Layout.fillHeight: true
            Layout.preferredWidth: 1
            color: "silver"
            opacity: 0.5
        }

        AppText
        {
            id: txt
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignVCenter

            size: 17
            color: "white"
            text: qsTr("Sales Cash : 37264")
        }

        AppText
        {
            id: cost
            Layout.preferredWidth: 150
            Layout.alignment: Qt.AlignVCenter

            font.bold: true
            size: 20
            color: "white"
            text: qsTr("Ksh. 37264")
        }
    }
}

