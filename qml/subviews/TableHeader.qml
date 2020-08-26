import QtQuick 2.0
import QtQuick.Layouts 1.3

import "../components"

Rectangle {
    Layout.fillWidth: true
    Layout.preferredHeight: 50

    color: "#efefef"

    RowLayout
    {
        anchors.fill: parent
        spacing: 1

        Item
        {
            Layout.fillHeight: true
            Layout.preferredWidth: 40

            AppText
            {
                size: 15
                color: "black"
                anchors.centerIn: parent
                text: qsTr("No.")
            }
        }

        Item
        {
            Layout.fillHeight: true
            Layout.fillWidth: true

            AppText
            {
                size: 15
                color: "black"
                anchors.centerIn: parent
                text: qsTr("Item Name")
            }
        }

        Item
        {
            Layout.fillHeight: true
            Layout.preferredWidth: 60

            AppText
            {
                size: 15
                color: "black"
                anchors.centerIn: parent
                text: qsTr("Qty.")
            }
        }

        Item
        {
            Layout.fillHeight: true
            Layout.preferredWidth: 200

            AppText
            {
                size: 15
                color: "black"
                anchors.centerIn: parent
                text: qsTr("Unit Price (Ksh.)")
            }
        }

        Item
        {
            Layout.fillHeight: true
            Layout.preferredWidth: 200

            AppText
            {
                size: 15
                color: "black"
                anchors.centerIn: parent
                text: qsTr("Subtotal")
            }
        }

        Item
        {
            Layout.fillHeight: true
            Layout.preferredWidth: 120

            AppText
            {
                size: 15
                color: "black"
                anchors.centerIn: parent
                text: qsTr("Action")
            }
        }
    }
}
