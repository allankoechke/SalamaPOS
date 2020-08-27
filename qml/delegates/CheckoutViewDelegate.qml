import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4

import "../components"

Rectangle {
    id: root
    height: 45
    color: ((_index+1)%2)===0? "#eeeeee":"white"

    property int _index
    property string itemName
    property string unit
    property int qty
    property int sp

    RowLayout
    {
        anchors.fill: parent
        spacing: 1

        AppText
        {
            color: "black"
            text: (_index+1).toString()+"."
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 50
        }

        AppText
        {
            color: "black"
            text: unit + " " + itemName
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.minimumWidth: 150
            Layout.maximumWidth: 450
        }

        AppText
        {
            color: "black"
            text: qty.toString()
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 100
        }

        AppText
        {
            color: "black"
            text: sp.toString()
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 200
        }

        AppText
        {
            color: "black"
            text: (qty*sp).toString()
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 200
        }

        Item{
            Layout.preferredWidth: 100
            Layout.fillHeight: true

            RowLayout
            {
                anchors.centerIn: parent

                AppIcon
                {
                    size: 15
                    color: menuColor
                    icon: "\uf5a1"

                    Layout.alignment: Qt.AlignVCenter
                }

                AppText
                {
                    color: "black"
                    text: qsTr("Change")

                    Layout.alignment: Qt.AlignVCenter
                }
            }
        }
    }
}
