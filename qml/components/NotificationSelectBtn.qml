import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

import "../components"

Rectangle
{
    id: root

    Layout.fillWidth: true
    Layout.fillHeight: true
    Layout.bottomMargin: 10
    
    radius: 4
    color: menuColor

    property bool isSelected: false
    property string label
    property string _icon
    property int count

    signal clicked()
    
    Rectangle
    {
        visible: isSelected

        color: "green"
        width: parent.width
        height: 4
        radius: height/2
        
        anchors.bottom: parent.bottom
        anchors.bottomMargin: -7
    }

    RowLayout
    {
        anchors.fill: parent
        spacing: 10

        Item
        {
            Layout.fillHeight: true
            Layout.preferredWidth: 50

            AppIcon
            {
                icon: _icon
                color: "white"
                size: 15

                anchors.centerIn: parent
            }
        }

        Item
        {
            Layout.fillWidth: true
            Layout.fillHeight: true

            AppText
            {
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                size: 12
                color: "white"

                text: label
            }
        }

        Item
        {
            Layout.preferredWidth: 50
            Layout.fillHeight: true

            Rectangle
            {
                anchors.centerIn: parent

                height: 30; width: 30; radius: height/2
                color: "green"

                AppText
                {
                    anchors.centerIn: parent
                    size: 12
                    color: "white"

                    text: count.toString()
                }
            }
        }
    }

    MouseArea
    {
        anchors.fill: parent
        onClicked: root.clicked()
    }
}
