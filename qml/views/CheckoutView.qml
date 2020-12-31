import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2
import QtQuick.Controls.Material 2.2

import "../components"
import "../subviews"
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

                Item
                {
                    id: textField
                    Layout.preferredWidth: _text.width + 20
                    Layout.fillHeight: true

                    AppText{
                        id: _text
                        size: 15
                        color: QmlInterface.isDarkTheme? "grey":"#2e2e2e"
                        text: qsTr("Scan Barcode to add items or Use the search button")

                        anchors.left: parent.left
                        anchors.leftMargin: 5
                        anchors.verticalCenter: parent.verticalCenter
                    }

                }

                Rectangle
                {
                    Layout.preferredHeight: 50
                    Layout.preferredWidth: 150
                    Layout.margins: 1

                    color: menuColor
                    radius: 5

                    RowLayout
                    {
                        anchors.centerIn: parent
                        spacing: 10

                        AppIcon
                        {
                            size: 18
                            color: "white"
                            icon: "\uf002"

                            Layout.alignment: Qt.AlignVCenter
                        }

                        AppText{
                            size: 20
                            color: "white"
                            font.bold: true
                            text: qsTr("Search")


                            Layout.alignment: Qt.AlignVCenter
                        }
                    }

                    MouseArea
                    {
                        anchors.fill: parent
                        onClicked: {
                            addItemDialog.show();
                        }
                    }
                }

                HorizontalSpacer{}

                AppText{
                    Layout.fillHeight: true
                    size: 70*0.6
                    color: QmlInterface.isDarkTheme? "white":"black"
                    text: qsTr("Sales: Ksh. ") + (sellListView.model === null? "0":sellListView.model.count === 0? "0":parseInt(CheckoutModel.sellTotals).toString())

                    verticalAlignment: AppText.AlignVCenter
                }
            }
        }

        Rectangle
        {
            color: QmlInterface.isDarkTheme? "white":"black"; Layout.fillWidth: true; height: 2; opacity: 0.078; Layout.leftMargin: 50; Layout.rightMargin: 50;
        }

        Rectangle
        {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.leftMargin: 50
            Layout.rightMargin: 50

            color: QmlInterface.isDarkTheme? "#29292d":"white"
            Material.elevation: 6
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
                                _barcode: sell_barcode

                                onDeleted: {
                                    CheckoutModel.removeSellItem(index);
                                }

                                onEdited: {
                                    checkoutQtyPopup.open();
                                    checkoutQtyPopup.to = StockItemModel.getItemStock(_barcode)===-1? qty:StockItemModel.getItemStock(_barcode)
                                    checkoutQtyPopup.value = qty;
                                    checkoutQtyPopup.from = 1;
                                    checkoutQtyPopup.barcode = _barcode;
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

                HorizontalSpacer {}

                TextIconButton
                {
                    label: qsTr("CANCEL")
                    _icon: "\uf056"
                    enabled: CheckoutModel.checkoutModelSize===0? false:true
                    opacity: CheckoutModel.checkoutModelSize===0? 0.4:1

                    onButtonClicked: CheckoutModel.startANewSell();
                }

                TextIconButton
                {
                    label: qsTr("CHECKOUT")
                    _icon: "\uf07a"
                    enabled: CheckoutModel.checkoutModelSize===0? false:true
                    opacity: CheckoutModel.checkoutModelSize===0? 0.4:1

                    onButtonClicked: checkoutPopup.open();
                }

                HorizontalSpacer {}
            }
        }
    }

    function positionDialog()
    {
        var globalCoordinares = textField.mapToItem(mainAppViewRoot , 0, 0)
        addItemDialog.x = globalCoordinares.x
        addItemDialog.y = globalCoordinares.y + height + 70
    }
}
