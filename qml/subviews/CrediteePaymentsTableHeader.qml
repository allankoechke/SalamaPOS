import QtQuick 2.0
import QtQuick.Layouts 1.3

import "../components"

Rectangle {
    id: root

    Layout.fillWidth: true
    Layout.preferredHeight: 40

    radius: 0
    color:menuColor

    RowLayout
    {
        anchors.fill: parent
        spacing: 0

        AppText
        {
            color: "#f4f4f4"
            size: 18
            font.bold: true
            text: qsTr("No.")

            Layout.preferredWidth: 50
            Layout.fillHeight: true
            verticalAlignment: AppText.AlignVCenter
            horizontalAlignment: AppText.AlignHCenter
        }

        VSeparator{}

        // Full names
        Item{
            Layout.fillWidth: true
            Layout.fillHeight: true

            AppText
            {
                color: "#f4f4f4"
                size: 18
                font.bold: true
                text: qsTr("Payment Date")
                width: parent.width
                elide: AppText.ElideRight


                horizontalAlignment: AppText.AlignHCenter
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        VSeparator{}

        // ID number
        Item{
            Layout.preferredWidth: 200
            Layout.fillHeight: true

            AppText
            {
                color: "#f4f4f4"
                size: 18
                font.bold: true
                text: qsTr("Amount Paid (Ksh.)")
                width: parent.width
                elide: AppText.ElideRight


                horizontalAlignment: AppText.AlignHCenter
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        VSeparator{}

        // Mobile no
        Item{
            Layout.preferredWidth: 200
            Layout.fillHeight: true

            AppText
            {
                color: "#f4f4f4"
                size: 18
                font.bold: true
                text: qsTr("Amount Due (Ksh.)")
                width: parent.width
                elide: AppText.ElideRight


                horizontalAlignment: AppText.AlignHCenter
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        VSeparator{}

        Item{
            Layout.preferredWidth: 100
            Layout.fillHeight: true
            Layout.rightMargin: 15

            AppText
            {
                color: "#f4f4f4"
                size: 18
                font.bold: true
                text: qsTr("Action")
                width: parent.width
                elide: AppText.ElideRight


                horizontalAlignment: AppText.AlignHCenter
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
}
