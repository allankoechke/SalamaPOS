import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

import "../components"
import "../subviews"

Item {
    id: root

    Layout.fillHeight: true
    Layout.fillWidth: true
    Layout.margins: 50

    ColumnLayout
    {
        anchors.fill: parent
        spacing: 10

        Item
        {
            Layout.fillWidth: true
            Layout.leftMargin: 40
            Layout.rightMargin: 40
            height: 90

            RowLayout
            {
                anchors.fill: parent
                anchors.margins: 10
                spacing: 10

                Rectangle
                {
                    Layout.preferredHeight: 50
                    Layout.fillWidth: true
                    Layout.minimumWidth: 300

                    color: "white"
                    border.width: 1
                    border.color: "grey"
                    radius: 3

                    RowLayout
                    {
                        anchors.fill: parent
                        spacing: 0

                        TextInput
                        {
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            verticalAlignment: TextInput.AlignVCenter
                            horizontalAlignment: TextInput.AlignLeft
                            Layout.leftMargin: 5
                            color: "black"
                            font.pixelSize: 17
                            font.family: montserratFontLoader.name
                            selectByMouse: true

                            AppText{
                                size: parent.font.pixelSize-3
                                color: "grey"
                                text: qsTr("Search by Item name or Scan Barcode")
                                visible: parent.text===""

                                anchors.left: parent.left
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }

                        Rectangle
                        {
                            Layout.fillHeight: true
                            width: 50
                            Layout.margins: 1

                            color: menuColor

                            AppIcon
                            {
                                anchors.centerIn: parent
                                size: 16
                                color: "white"
                                icon: "\uf002"
                            }
                        }
                    }
                }

                HorizontalSpacer{}

                AppText{
                    Layout.fillHeight: true
                    size: 70*0.6
                    color: "black"
                    text: qsTr("Sales: Ksh. 0.00")

                    verticalAlignment: AppText.AlignVCenter
                }
            }
        }

        Rectangle
        {
            color: "black"; Layout.fillWidth: true; height: 2; opacity: 0.078; Layout.leftMargin: 50; Layout.rightMargin: 50;
        }

        Rectangle
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.leftMargin: 50
            Layout.rightMargin: 50

            color: "white"
            radius: 4

            // Table Header
            ColumnLayout
            {
                anchors.fill: parent
                anchors.margins: 5
                spacing: 3

                TableHeader
                {

                }

                Controls2.ScrollView
                {
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    spacing: 5

                    ListView
                    {
                        anchors.fill: parent
                        spacing: 1

                        model: ListModel { id: checkoutModel }
                    }
                }

            }
        }

        Item
        {
            Layout.fillWidth: true
            Layout.preferredHeight: 60
            Layout.leftMargin: 50
            Layout.rightMargin: 50
            Layout.bottomMargin: 20

            RowLayout
            {
                anchors.fill: parent
                spacing: 20

                HorizontalSpacer
                {

                }
                TextIconButton
                {
                    label: qsTr("CANCEL")
                    _icon: "\uf056"
                    opacity: checkoutModel.count === 0? 0.6:1
                }

                TextIconButton
                {
                    label: qsTr("CHECKOUT")
                    _icon: "\uf07a"
                    //opacity: checkoutModel.count === 0? 0.6:1

                    onButtonClicked: checkoutPopup.open();
                }
            }
        }
    }
}
