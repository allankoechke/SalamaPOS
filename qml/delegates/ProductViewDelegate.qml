import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4

import "../components"

Rectangle {
    id: root
    height: 45
    color: QmlInterface.isDarkTheme? (((_index+1)%2)===0? Qt.lighter("#29292d", 1.3):Qt.lighter("#29292d", 1.5)):(((_index+1)%2)===0? "#eeeeee":"white")

    property int _index
    property string itemName
    property string barCode
    property string _unit
    property int bp
    property int sp
    property int qty
    property string company

    signal clicked()

    RowLayout
    {
        anchors.fill: parent
        spacing: 1

        Item
        {
            Layout.preferredWidth: 50
            Layout.fillHeight: true

            AppText
            {
                color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
                width: parent.width
                text: (_index+1).toString()+"."
                horizontalAlignment: AppText.AlignHCenter
                elide: AppText.ElideRight

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
            }
        }

        Rectangle
        {
            color: "transparent"
            width: 2
            Layout.fillHeight: true
            opacity: 0.1
        }

        Item
        {
            Layout.fillWidth: true
            Layout.minimumWidth: 150
            Layout.fillHeight: true

            AppText
            {
                color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
                text: itemName
                width: parent.width
                elide: AppText.ElideRight
                horizontalAlignment: AppText.AlignLeft

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
            }
        }

        Rectangle
        {
            color: "transparent"
            width: 2
            Layout.fillHeight: true
            opacity: 0.1
        }


        Item
        {
            Layout.preferredWidth: 150
            Layout.fillHeight: true

            AppText
            {
                color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
                text: barCode
                width: parent.width
                elide: AppText.ElideRight
                horizontalAlignment: AppText.AlignLeft

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
            }
        }

        Rectangle
        {
            color: "transparent"
            width: 2
            Layout.fillHeight: true
            opacity: 0.1
        }


        Item
        {
            Layout.preferredWidth: 100
            Layout.fillHeight: true

            AppText
            {
                color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
                text: _unit
                width: parent.width-10
                elide: AppText.ElideRight
                horizontalAlignment: AppText.AlignLeft

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 10
            }
        }

        Rectangle
        {
            color: "transparent"
            width: 2
            Layout.fillHeight: true
            opacity: 0.1
        }


       Item
        {
            Layout.preferredWidth: 150
            Layout.fillHeight: true

            AppText
            {
                color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
                text: bp.toString()
                width: parent.width
                elide: AppText.ElideRight
                horizontalAlignment: AppText.AlignHCenter

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
            }
        }

        Rectangle
        {
            color: "transparent"
            width: 2
            Layout.fillHeight: true
            opacity: 0.1
        }


        Item
        {
            Layout.preferredWidth: 150
            Layout.fillHeight: true

            AppText
            {
                color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
                text: sp.toString()
                width: parent.width
                elide: AppText.ElideRight
                horizontalAlignment: AppText.AlignHCenter

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
            }
        }

        Rectangle
        {
            color: "transparent"
            width: 2
            Layout.fillHeight: true
            opacity: 0.1
        }


        Item
        {
            Layout.fillHeight: true
            Layout.preferredWidth: 100

            AppText
            {
                color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
                text: qty.toString()
                width: parent.width
                elide: AppText.ElideRight
                horizontalAlignment: AppText.AlignHCenter

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
            }
        }

        Rectangle
        {
            color: "transparent"
            width: 2
            Layout.fillHeight: true
            opacity: 0.1
        }


        Item
        {
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.minimumWidth: 150
            Layout.maximumWidth: 300
            Layout.leftMargin: 10

            AppText
            {
                color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
                text: company
                width: parent.width
                elide: AppText.ElideRight
                horizontalAlignment: AppText.AlignLeft

                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
            }
        }

        Rectangle
        {
            color: "transparent"
            width: 2
            Layout.fillHeight: true
            opacity: 0.1
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
                    color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
                    text: qsTr("Edit")

                    Layout.alignment: Qt.AlignVCenter
                }
            }

            MouseArea
            {
                anchors.fill: parent
                onClicked: root.clicked()
            }
        }
    }
}
