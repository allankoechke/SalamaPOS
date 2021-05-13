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
            font.bold: true
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 60
        }

        VSeparator{}

        AppText
        {
            color: "white"
            text: qsTr("Initial Stock")
            font.bold: true
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 100
        }

        VSeparator{}

        AppText
        {
            color: "white"
            text: qsTr("Added/Removed")
            font.bold: true
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 150
        }

        VSeparator{}

        AppText
        {
            color: "white"
            text: qsTr("New Stock")
            font.bold: true
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 100
        }

        VSeparator{}

        AppText
        {
            color: "white"
            text: qsTr("Date Updated")
            font.bold: true
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.minimumWidth: 150
            Layout.maximumWidth: 300
        }
    }
}
