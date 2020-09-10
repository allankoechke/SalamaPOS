import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

import "../components"
import "../delegates"
import "../models"

Rectangle {

    id: root
    radius: 2
    border.color: "grey"
    border.width: 1

    Layout.fillWidth: true
    Layout.fillHeight: true

    ColumnLayout
    {
        anchors.fill: parent
        anchors.margins: 0
        spacing: 0

        StockProductViewHeader {}

        Rectangle
        {
            Layout.fillWidth: true
            Layout.preferredHeight: 1
            color: "grey"
        }

        Controls2.ScrollView
        {
            id: scroll
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: 1
            clip: true

            ListView
            {
                anchors.fill: parent
                spacing: 0

                model: StockItemModel // ProductViewModel {}

                delegate: Component {
                    id: productViewDelegate

                    ProductViewDelegate
                    {
                        width: scroll.width

                        _index: model.index
                        itemName: name
                        barCode: barcode
                        _unit: unit
                        qty: quantity
                        bp: _bp
                        sp: _sp
                        company: _company===""? "---":_company

                        onClicked: {
                            newItemPopup.open();
                            newItemPopup.currentIndex = index
                            newItemPopup.barCode = barCode;
                            newItemPopup.itemName = itemName;
                            newItemPopup.itemUnit = unit;
                            newItemPopup.itemBp = bp;
                            newItemPopup.itemSp = sp;
                            newItemPopup.itemQty = qty;
                            newItemPopup.itemCompany = company;

                            newItemPopup.qty.textInput.readOnly = true;
                            newItemPopup.qty.textInput.enabled = false;
                            newItemPopup.isNewItemMode = false;
                        }
                    }
                }
            }

        }
    }
}
