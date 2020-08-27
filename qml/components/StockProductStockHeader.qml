import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

import "../components"

Rectangle {
    Layout.fillWidth: true
    Layout.preferredHeight: 50

    color: menuColor

    RowLayout
    {
        anchors.fill: parent
        spacing: 1

        AppText
        {
            color: "white"
            text: qsTr("No.")
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 50
        }

        AppText
        {
            color: "white"
            text: qsTr("Item Name")
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.minimumWidth: 150
        }

        AppText
        {
            color: "white"
            text: qsTr("Bar Code")
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 150
        }

        AppText
        {
            color: "white"
            text: qsTr("Unit")
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 100
        }

        AppText
        {
            color: "white"
            text: qsTr("Qty.")
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 100
        }

        AppText
        {
            color: "white"
            text: qsTr("Action")
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 150
        }

        AppText
        {
            color: "white"
            text: qsTr("Last Updated")
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.minimumWidth: 150
            Layout.maximumWidth: 300
        }
    }
}
