import QtQuick 2.0
import QtQuick.Layouts 1.3

import "../components"

Rectangle {
    id: root

    clip: true
    color: isMenuCurrentlyActive? "#1477b0":"transparent"

    Layout.fillWidth: true
    Layout.preferredHeight: 50

    property bool isMenuCurrentlyActive: false
    property string menuLabel: ""
    property string menuIcon

    signal menuClicked()

    Rectangle
    {
        visible: isMenuCurrentlyActive
        width: 50; height: 50
        color: QmlInterface.isDarkTheme? "#1e2027":"#f4f9fa"
        rotation: 45

        x: 70
    }

    ColumnLayout
    {
        anchors.fill: parent
        spacing: 5

        AppIcon
        {
            Layout.alignment: Qt.AlignHCenter

            size: 20
            color: "white"
            icon: menuIcon
        }

        AppText
        {
            Layout.alignment: Qt.AlignHCenter
            color: "white"
            size: 10
            text: menuLabel
        }
    }

    MouseArea
    {
        anchors.fill: parent
        onClicked: root.menuClicked();
    }
}
