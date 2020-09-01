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

    property var currentScreen: 0

    ColumnLayout
    {
        anchors.fill: parent
        anchors.margins: 50
        spacing: 10

        Item
        {
            Layout.fillWidth: true
            Layout.preferredHeight: 70

            Rectangle
            {
                width: parent.width
                height: 3
                color: "#d3e5ff"

                anchors.bottom: parent.bottom
                anchors.bottomMargin: 3
            }

            RowLayout
            {
                anchors.fill: parent
                spacing: 1

                AppText
                {
                    color: "black"
                    size: 17
                    text: qsTr("Showing Sales for : ") + ["Today", "Yesterday", "This Week", "This Month", "This Year", "Custom"][cb.currentIndex]

                    Layout.alignment: Qt.AlignVCenter
                }

                HorizontalSpacer {}

                Controls2.ComboBox
                {
                    id: cb
                    height: 45
                    width: 140
                    currentIndex: 0

                    editable: false
                    model: ["Today", "Yesterday", "This Week", "This Month", "This Year", "Custom"]

                    Layout.rightMargin: 10
                }

                Rectangle
                {
                    Layout.preferredHeight: 45
                    Layout.fillWidth: true
                    Layout.minimumWidth: 100
                    Layout.maximumWidth: 300

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
                                text: qsTr("Filter items")
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
            }
        }

        SalesProductView
        {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
