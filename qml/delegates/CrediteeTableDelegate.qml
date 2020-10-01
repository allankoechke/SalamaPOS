import QtQuick 2.0
import QtQuick.Layouts 1.3

import "../components"

Rectangle {
    id: root
    height: 40
    color: QmlInterface.isDarkTheme? (((no+1)%2)===0? Qt.lighter("#29292d", 1.3):Qt.lighter("#29292d", 1.5)):(((no+1)%2)===0? "#eeeeee":"white")


    property int no: 0
    property alias fullname: fname.text
    property alias mobile: mobile.text
    property alias idNo: idno.text
    property alias debt: debt.text

    signal actionClicked()

    RowLayout
    {
        anchors.fill: parent
        spacing: 0

        AppText
        {
            color: QmlInterface.isDarkTheme? "#f4f4f4":"#2e2e2e"
            size: 18
            text: (no + 1).toString() + "."

            Layout.preferredWidth: 50
            Layout.fillHeight: true
            verticalAlignment: AppText.AlignVCenter
            horizontalAlignment: AppText.AlignHCenter
        }

        // Full names
        Item{
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.leftMargin: 2

            AppText
            {
                id: fname
                color: QmlInterface.isDarkTheme? "#f4f4f4":"#2e2e2e"
                size: 15
                width: parent.width
                elide: AppText.ElideRight


                horizontalAlignment: AppText.AlignHCenter
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        // ID number
        Item{
            Layout.preferredWidth: 130
            Layout.fillHeight: true
            Layout.leftMargin: 2

            AppText
            {
                id: idno
                color: QmlInterface.isDarkTheme? "#f4f4f4":"#2e2e2e"
                size: 15
                width: parent.width
                elide: AppText.ElideRight


                horizontalAlignment: AppText.AlignHCenter
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        // Mobile no
        Item{
            Layout.preferredWidth: 150
            Layout.fillHeight: true
            Layout.leftMargin: 2

            AppText
            {
                id: mobile
                color: QmlInterface.isDarkTheme? "#f4f4f4":"#2e2e2e"
                size: 15
                width: parent.width
                elide: AppText.ElideRight


                horizontalAlignment: AppText.AlignHCenter
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        // Amount owed
        Item{
            Layout.preferredWidth: 100
            Layout.fillHeight: true
            Layout.leftMargin: 2

            AppText
            {
                id: debt
                color: QmlInterface.isDarkTheme? "#f4f4f4":"#2e2e2e"
                size: 15
                width: parent.width
                elide: AppText.ElideRight


                horizontalAlignment: AppText.AlignHCenter
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Item{
            Layout.preferredWidth: 100
            Layout.fillHeight: true
            Layout.leftMargin: 2

            RowLayout
            {
                anchors.centerIn: parent
                spacing: 10

                AppText
                {
                    size: 15
                    color: QmlInterface.isDarkTheme? "#f4f4f4":"#2e2e2e"
                    text: qsTr("View")

                    Layout.alignment: Qt.AlignVCenter
                }

                AppIcon
                {
                    icon: "\uf061"
                    size: 20
                    color: QmlInterface.isDarkTheme? "white":menuColor

                    Layout.alignment: Qt.AlignVCenter
                }
            }

            MouseArea
            {
                anchors.fill: parent
                onClicked: root.actionClicked()
            }
        }
    }
}
