import QtQuick 2.0
import QtQuick.Layouts 1.3

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
            size: 17
            color: "white"
            text: qsTr("No.")
            font.bold: true
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 50
        }

        VSeparator{}

        AppText
        {
            size: 17
            color: "white"
            text: qsTr("Item Name")
            font.bold: true
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.minimumWidth: 150
            Layout.maximumWidth: 450
        }

        VSeparator{}

        AppText
        {
            size: 17
            color: "white"
            text: qsTr("Qty.")
            font.bold: true
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 100
        }

        VSeparator{}

        AppText
        {
            size: 17
            color: "white"
            text: qsTr("Unit Price (Ksh.)")
            font.bold: true
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 200
        }

        VSeparator{}

        AppText
        {
            size: 17
            color: "white"
            text: qsTr("Subtotal")
            font.bold: true
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 200
        }


        VSeparator{}

        AppText
        {
            size: 17
            color: "white"
            text: qsTr("Action")
            font.bold: true
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 100
        }


        VSeparator{}

        Item{
            Layout.fillHeight: true
            Layout.preferredWidth: 30
            Layout.leftMargin: 5
            Layout.rightMargin: 5

            AppIcon
            {
                size: 15
                color: "white"
                icon: "\uf057"

                anchors.centerIn: parent
            }
        }
    }
}
