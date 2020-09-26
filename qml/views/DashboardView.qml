import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

import "../components"

Item {
    id: root

    Layout.fillHeight: true
    Layout.fillWidth: true
    Layout.margins: 50

    GridLayout
    {
        id: grid
        anchors.fill: parent
        anchors.margins: 50
        columnSpacing: 10
        rowSpacing: 10

        columns: 5
        rows: 5

        Rectangle
        {
            color: "#266995"
            radius: 5
            Layout.minimumWidth: (grid.width-50)/5
            Layout.fillWidth: true
            Layout.preferredHeight: 70

            Layout.row: 0
            Layout.column: 0
        }

        Rectangle
        {
            color: "#266995"
            radius: 5
            Layout.fillWidth: true
            Layout.minimumWidth: (grid.width-50)/5
            Layout.preferredHeight: 70

            Layout.row: 0
            Layout.column: 1
        }

        Rectangle
        {
            color: "#266995"
            radius: 5
            Layout.minimumWidth: (grid.width-50)/5
            Layout.fillWidth: true
            Layout.preferredHeight: 70

            Layout.row: 0
            Layout.column: 2
        }

        Rectangle
        {
            color: "#266995"
            radius: 5
            Layout.minimumWidth: (grid.width-50)/5
            Layout.fillWidth: true
            Layout.preferredHeight: 70

            Layout.row: 0
            Layout.column: 3
        }

        Rectangle
        {
            color: "#266995"
            radius: 5

            Layout.minimumWidth: (grid.width-50)/5
            Layout.fillWidth: true
            Layout.preferredHeight: 70
            Layout.row: 0
            Layout.column: 4

            RowLayout
            {
                anchors.fill: parent
                anchors.margins: 10

                Item
                {
                    Layout.fillHeight: true
                    Layout.preferredWidth: height

                    AppIcon
                    {
                        anchors.centerIn: parent
                        color: "white"
                        size: parent.height*0.67
                        icon: "\uf233"
                    }
                }

                Item
                {
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    ColumnLayout
                    {
                        anchors.verticalCenter: parent.verticalCenter
                        width: parent.width

                        AppText
                        {
                            color: "white"
                            size: 18
                            text: qsTr("Server")

                            Layout.alignment: Qt.AlignLeft
                        }

                        Item
                        {
                            Layout.fillWidth: true
                            Layout.preferredHeight: 20

                            RowLayout
                            {
                                anchors.fill: parent
                                spacing: 5

                                Rectangle
                                {
                                    width: 15; height: 15; radius: height/2
                                    color: "white"

                                    Layout.alignment: Qt.AlignVCenter
                                }

                                AppText
                                {
                                    color: "white"
                                    size: 13
                                    text: qsTr("Online")

                                    Layout.alignment: Qt.AlignLeft|Qt.AlignVCenter
                                }

                                HorizontalSpacer {}
                            }
                        }
                    }
                }

                Item
                {
                    Layout.fillHeight: true
                    Layout.preferredWidth: height

                    AppIcon
                    {
                        anchors.centerIn: parent
                        color: "white"
                        size: parent.height*0.67
                        icon: "\uf0a9"
                    }
                }
            }
        }

        Rectangle
        {
            id: graph
            color: QmlInterface.isDarkTheme? "#29292d":"white"
            radius: 5

            Layout.minimumWidth: (grid.width-50)*0.8
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.row: 1
            Layout.column: 0
            Layout.rowSpan: 3
            Layout.columnSpan: 4

            DashboardGraphWidget
            {

            }
        }

        Rectangle
        {
            color: Qt.lighter("#266995")
            radius: 5
            Layout.fillHeight: true
            Layout.minimumWidth: (grid.width-50)/5

            Layout.row: 1
            Layout.column: 4
        }

        Rectangle
        {
            color: Qt.lighter("#266995")
            radius: 5
            Layout.fillHeight: true
            Layout.minimumWidth: (grid.width-50)/5


            Layout.row: 2
            Layout.column: 4
        }

        Rectangle
        {
            color: Qt.lighter("#266995")
            radius: 5
            Layout.fillHeight: true
            Layout.minimumWidth: (grid.width-50)/5

            Layout.row: 3
            Layout.column: 4
        }

        Rectangle
        {
            color: QmlInterface.isDarkTheme? "#29292d":"white"
            radius: 5
            Layout.fillWidth: true
            Layout.preferredHeight: 80

            Layout.row: 4
            Layout.column: 0
            Layout.columnSpan: 5
        }
    }

}
