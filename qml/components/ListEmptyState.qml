import QtQuick 2.0
import QtQuick.Layouts 1.3

Item{
    Layout.fillWidth: true
    Layout.fillHeight: true

    property string emptyLabel: qsTr("Couldn't find any data for this item!")

    Column
    {
        anchors.centerIn: parent
        spacing: 10

        AppIcon
        {
            icon: '\uf5b4'
            color: QmlInterface.isDarkTheme? '#fefefe':'#444'
            size: 55
            anchors.horizontalCenter: parent.horizontalCenter
        }

        AppText
        {
            color: QmlInterface.isDarkTheme? "#fefefe":"#2e2e2e"
            text: qsTr("Oooh Snap!")
            font.bold: true
            size: 18
            anchors.horizontalCenter: parent.horizontalCenter
        }

        AppText
        {
            color: QmlInterface.isDarkTheme? "#fefefe":"#2e2e2e"
            text: emptyLabel
            anchors.horizontalCenter: parent.horizontalCenter
            size: 15
        }
    }
}

