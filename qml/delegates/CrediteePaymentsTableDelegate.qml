import QtQuick 2.0
import QtQuick.Layouts 1.3

import "../components"

Rectangle {
    id: root

    Layout.fillWidth: true
    Layout.preferredHeight: 40

    radius: 0
    color:menuColor

    property int no: 0
    property alias due: p_due.text
    property alias paid: p_amount.text
    property alias date: p_date.text

    RowLayout
    {
        anchors.fill: parent
        spacing: 0

        AppText
        {
            color: "#f4f4f4"
            size: 18
            font.bold: true
            text: (no + 1).toString() + "."

            Layout.preferredWidth: 50
            Layout.fillHeight: true
            verticalAlignment: AppText.AlignVCenter
            horizontalAlignment: AppText.AlignHCenter
        }

        VSeparator{}

        // Dates
        Item{
            Layout.fillWidth: true
            Layout.fillHeight: true

            AppText
            {
                id: p_date
                color: "#f4f4f4"
                size: 15
                width: parent.width
                elide: AppText.ElideRight


                horizontalAlignment: AppText.AlignHCenter
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        VSeparator{}

        // Amount
        Item{
            Layout.preferredWidth: 200
            Layout.fillHeight: true

            AppText
            {
                id: p_amount
                color: "#f4f4f4"
                size: 15
                width: parent.width
                elide: AppText.ElideRight


                horizontalAlignment: AppText.AlignHCenter
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        VSeparator{}

        // Due
        Item{
            Layout.preferredWidth: 200
            Layout.fillHeight: true

            AppText
            {
                id: p_due
                color: "#f4f4f4"
                size: 15
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
                text: qsTr("View")
                width: parent.width
                elide: AppText.ElideRight


                horizontalAlignment: AppText.AlignHCenter
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
}
