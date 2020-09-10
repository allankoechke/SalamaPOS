import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

import "../components"
import "../subviews"
// import "../models"
import "../delegates"

Item {
    id: root

    Layout.fillHeight: true
    Layout.fillWidth: true
    Layout.margins: 50

    Component.onCompleted: CheckoutModel.sellTotals = 0;

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

                            MouseArea
                            {
                                anchors.fill: parent
                                onClicked: {
                                    CheckoutModel.addSellItem("FA76286428", "Milking Salve", "1kg", 175, 234, 2);
                                    CheckoutModel.addSellItem("FA76286348", "Macklick Super", "2kg", 115, 140, 1);
                                    CheckoutModel.addSellItem("FA00286428", "Kaolin", "100gms", 78, 100, 1);
                                }
                            }
                        }
                    }
                }

                HorizontalSpacer{}

                AppText{
                    Layout.fillHeight: true
                    size: 70*0.6
                    color: "black"
                    text: qsTr("Sales: Ksh. ") + (sellListView.model.count === 0? "0":parseInt(CheckoutModel.sellTotals).toString())

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
            border.width: 1
            border.color: "grey"

            // Table Header
            ColumnLayout
            {
                anchors.fill: parent
                anchors.margins: 0
                spacing: 0

                CheckoutTableHeader
                {
                }

                Controls2.ScrollView
                {
                    id: scroll
                    Layout.fillHeight: true
                    Layout.fillWidth: true
                    Layout.margins: 1
                    clip: true

                    ListView
                    {
                        id: sellListView
                        anchors.fill: parent
                        spacing: 0

                        model: CheckoutModel
                        delegate: Component {
                            id: checkoutViewDelegate

                            CheckoutViewDelegate
                            {
                                width: scroll.width
                                anchors.leftMargin: 1

                                _index: model.index
                                itemName: sell_name
                                unit: sell_unit
                                qty: sell_qty
                                sp: sell_sp

                                onDeleted: {
                                    console.log(">> Deleted At: " , index)
                                    CheckoutModel.removeSellItem(index);
                                }

                                onEdited: {
                                    console.log(">> Edited At: " , index)
                                    // Launch popup
                                }
                            }
                        }
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
                    // opacity: checkoutModel.count === 0? 0.6:1

                    onButtonClicked: CheckoutModel.startANewSell();
                }

                TextIconButton
                {
                    label: qsTr("CHECKOUT")
                    _icon: "\uf07a"
                    enabled: sellListView.model.count !== 0
                    opacity: enabled? 1:0.2

                    onButtonClicked: checkoutPopup.open();
                }
            }
        }
    }
}
