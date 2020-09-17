import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4

import "../components"

Rectangle {
    id: root
    height: 45
    color: ((_index+1)%2)===0? "#eeeeee":"white"

    property int _index: ind
    property alias itemName: itemName.text
    property string barCode
    property alias unit: unit.text
    property int bp
    property alias sp: sp.text
    property alias qty: qty.text
    property string company
    property alias profit: pr.text
    property alias sub_totals: ttals.text

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
            id: itemName
            color: "black"
            horizontalAlignment: AppText.AlignLeft

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.leftMargin: 5
            Layout.fillWidth: true
            Layout.minimumWidth: 150
        }

        AppText
        {
            color: "black"
            id: unit
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 100
        }

        AppText
        {
            color: "black"
            id: qty
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 100
        }

        AppText
        {
            color: "black"
            id: sp
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 150
        }

        AppText
        {
            id: ttals
            color: "black"
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 150
        }

        AppText
        {
            id: pr
            color: "black"
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.minimumWidth: 150
            Layout.maximumWidth: 300
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
                    text: qsTr("Edit")

                    Layout.alignment: Qt.AlignVCenter
                }
            }
        }
    }
}
