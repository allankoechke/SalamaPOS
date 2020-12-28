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
            text: qsTr("")
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 55
        }

        VSeparator {}

        AppText
        {
            color: "white"
            text: qsTr("Full Name")
            font.bold: true
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.minimumWidth: 150
            Layout.maximumWidth: 300
        }

        VSeparator {}

        AppText
        {
            color: "white"
            text: qsTr("Phone Number")
            font.bold: true
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 150
        }

        VSeparator {}

        AppText
        {
            color: "white"
            text: qsTr("Date Added")
            font.bold: true
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 150
        }

        VSeparator {}

        AppText
        {
            color: "white"
            text: qsTr("Account Priviledges")
            font.bold: true
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.fillWidth: true
        }

        VSeparator {}

        AppText
        {
            color: "white"
            text: qsTr("Action")
            font.bold: true
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 100
        }
    }
}
