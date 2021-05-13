import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4

import "../components"

Rectangle {
    id: root
    height: 45
    color: QmlInterface.isDarkTheme? (((index_no+1)%2)===0? Qt.lighter("#29292d", 1.3):Qt.lighter("#29292d", 1.5)):(((index_no+1)%2)===0? "#eeeeee":"white")

    property int index_no
    property int initialQty: 0
    property int diffQty: 0
    property int newQty: 0
    property bool isAdding: true
    property string dayUpdated

    RowLayout
    {
        anchors.fill: parent
        spacing: 1

        AppText
        {
            color: QmlInterface.isDarkTheme? "#999fa6":"black"
            text: (index_no+1).toString()+"."
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 60
        }

        AppText
        {
            color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
            text: initialQty.toString()
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 100
            Layout.leftMargin: 5
        }

        Item{
            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 150
            Layout.leftMargin: 5

            Row{
                spacing: 10
                width: 100
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                AppIcon
                {
                    icon: isAdding?  "\uf176":"\uf175" // '\uf067':'\uf068'
                    color: isAdding? 'green':'red'
                    size: 15
                    anchors.verticalCenter: parent.verticalCenter
                }

                AppText
                {
                    color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
                    text: diffQty.toString()
                    horizontalAlignment: AppText.AlignHCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
        }


        AppText
        {
            color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
            text: newQty.toString()
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 100
            Layout.leftMargin: 5
        }

        Item{
            Layout.fillWidth: true
            Layout.minimumWidth: 150
            Layout.maximumWidth: 300
            Layout.leftMargin: 5

            AppText
            {
                color: QmlInterface.isDarkTheme? "#f4f4f4":"black"
                text: dayUpdated
                width: parent.width * 0.9
                elide: AppText.ElideRight
                horizontalAlignment: AppText.AlignLeft

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
}
