import QtQuick 2.2
import QtQuick.Controls 2.4 as Controls2
import QtQuick.Layouts 1.3

import "../components"
import "../delegates"

Controls2.Drawer {
    id: root

    width: 800
    height: mainApp.height
    modal: true
    edge: Qt.RightEdge
    interactive: false



    contentItem: Rectangle
    {
        color: QmlInterface.isDarkTheme? "#1e2027":bgColor
        anchors.fill: parent

        ColumnLayout
        {
            anchors.fill: parent
            anchors.margins: 10
            spacing: 5

            Item
            {
                Layout.fillWidth: true
                Layout.preferredHeight: 40

                AppText
                {
                    anchors.centerIn: parent

                    size: 18
                    color: QmlInterface.isDarkTheme? "#999fa6":"#555555"
                    text: qsTr("Creditee & Debts Information Panel")
                }

                AppIcon
                {
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.right: parent.right
                    horizontalAlignment: AppIcon.AlignHCenter
                    verticalAlignment: AppIcon.AlignVCenter

                    height: 35
                    width: 35
                    size: 25
                    color: "red"
                    icon: "\uf057"

                    MouseArea
                    {
                        anchors.fill: parent
                        onClicked: { stack.currentIndex = 0; root.close() }
                    }
                }
            }

            Rectangle
            {
                Layout.fillWidth: true
                Layout.preferredHeight: 1
                color: "silver"
            }

            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true

                StackLayout
                {
                    id: stack
                    anchors.fill: parent
                    currentIndex: 0

                    CrediteeTableView
                    {
                        onSwitchToStackTwo: stack.currentIndex = 1;
                    }

                    CrediteeUserView
                    {
                        id: crediteeUserView
                        onBackClicked: stack.currentIndex = 0;
                    }

                    CrediteeItemView {}
                }
            }
        }
    }
}
