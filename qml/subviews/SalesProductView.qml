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
    color: QmlInterface.isDarkTheme? "#29292d":"white"

    Layout.fillWidth: true
    Layout.fillHeight: true

    ColumnLayout
    {
        anchors.fill: parent
        anchors.margins: 0
        spacing: 0

        SalesTableHeader {}

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
                id: list
                anchors.fill: parent
                spacing: 0

                model: ProductSalesModel

                delegate: Component {
                    id: productViewDelegate

                    SalesViewDelegate
                    {
                        width: scroll.width

                        _index: model.index
                        itemName: p_name
                        barCode: p_barcode
                        unit: p_unit
                        qty: p_qty
                        bp: p_bp
                        sp: p_sp
                        company: "---"
                        sub_totals: p_sp*p_qty
                        profit: (p_sp-p_bp) * p_qty
                    }
                }
            }

        }
    }
}
