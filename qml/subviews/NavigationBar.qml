import QtQuick 2.0
import QtQuick.Layouts 1.3

import "../components"

Rectangle {
    id: root

    Layout.fillHeight: true
    Layout.preferredWidth: 70

    color: "#12679a"

    ColumnLayout
    {
        width: parent.width
        height: parent.height
        anchors.top: parent.top
        anchors.left: parent.left
        spacing: 5

        Rectangle
        {
            color: Qt.darker(root.color)
            width: 50
            height: 50; radius: height/2

            Layout.alignment: Qt.AlignTop|Qt.AlignHCenter
            Layout.topMargin: 20

            AppIcon
            {
                size: 20
                color: "white"
                icon: "\uf78a"
                font.bold: true

                anchors.centerIn: parent
            }

            AppText
            {
                color: "white"
                // font.bold: true
                size: 12
                text: "<i>v</i><b>21.01.01</b>"
                textFormat: AppText.StyledText

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.bottom
                anchors.topMargin: 5
            }

        }

        NavButton
        {
            Layout.topMargin: 50

            menuIcon: "\uf80a"
            menuLabel: qsTr("Home")
            isMenuCurrentlyActive: navBarIndex === 0

            onMenuClicked: navBarIndex = 0;
        }

        NavButton
        {
            menuIcon: "\uf488"
            menuLabel: qsTr("Sell")
            isMenuCurrentlyActive: navBarIndex === 1

            onMenuClicked: navBarIndex = 1;
        }

        NavButton
        {
            menuIcon: "\uf1c0"
            menuLabel: qsTr("Stock")
            isMenuCurrentlyActive: navBarIndex === 2

            onMenuClicked: navBarIndex = 2;
        }

        NavButton
        {
            menuIcon: "\uf080"
            menuLabel: qsTr("Sales")
            isMenuCurrentlyActive: navBarIndex === 3

            onMenuClicked: navBarIndex = 3;
        }

        NavButton
        {
            menuIcon: "\uf27a"
            menuLabel: qsTr("Messages")
             visible: false
            isMenuCurrentlyActive: navBarIndex === 4

            onMenuClicked: navBarIndex = 4;
        }

        Item
        {
            Layout.fillHeight: true
            Layout.preferredWidth: 1
        }

        NavButton
        {
            menuIcon: "\uf0c0"
            menuLabel: qsTr("Accounts")
            isMenuCurrentlyActive: navBarIndex === 6

            onMenuClicked: navBarIndex = 6;
        }

        NavButton
        {
            Layout.bottomMargin: 20

            menuIcon: "\uf085"
            menuLabel: qsTr("Settings")
            isMenuCurrentlyActive: navBarIndex === 5

            onMenuClicked: navBarIndex = 5;
        }
    }
}
