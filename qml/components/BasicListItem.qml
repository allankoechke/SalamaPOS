import QtQuick 2.3
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.0 as QQC2

import "../components"

QQC2.Popup {
    id: listItem

    width: 200
    height: 100

    property alias label: listItem.text

    property alias subtitle: subtitleItem.text

    property bool bold: false

    property alias reserveSpaceForLabel: labelItem.visible

    default property alias _basicDefault: layout.data

    contentItem: RowLayout {
        id: layout
        spacing: LayoutMirroring.enabled ? listItem.rightPadding : listItem.leftPadding

        ColumnLayout {
            spacing: 0
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignVCenter

            QQC2.Label {
                id: labelItem
                text: listItem.text
                Layout.fillWidth: true
                color: (listItem.highlighted || listItem.checked || (listItem.pressed && listItem.supportsMouseEvents)) ? listItem.activeTextColor : listItem.textColor
                elide: Text.ElideRight
                font.weight: listItem.bold ? Font.Bold : Font.Normal
                opacity: 1
            }
            QQC2.Label {
                id: subtitleItem
                Layout.fillWidth: true
                color: (listItem.highlighted || listItem.checked || (listItem.pressed && listItem.supportsMouseEvents)) ? listItem.activeTextColor : listItem.textColor
                elide: Text.ElideRight
                font.pixelSize: 15 // Theme.smallFont
                opacity: listItem.bold ? 0.9 : 0.7
                visible: text.length > 0
            }
        }
    }
}
