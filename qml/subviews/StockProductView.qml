import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

import "../components"
import "../delegates"

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

        StockProductViewHeader
        {

        }

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

            ListView
            {
                anchors.fill: parent
                spacing: 0

                model: 5
                delegate: Component {
                    id: productViewDelegate

                    ProductViewDelegate
                    {
                        width: scroll.width
                        _index: model.index
                    }
                }
            }

        }
    }
}
