import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

import "../components"

Rectangle
{
    id: root

    property alias _index: _id.text
    property alias name: name.text
    property alias id_no: idno.text
    property bool isSelected: false

    height: 35
    color: isSelected? Qt.lighter(menuColor, 1.3):QmlInterface.isDarkTheme? ((_index%2)===0? Qt.lighter("#29292d", 1.3):Qt.lighter("#29292d", 1.5)):((_index%2)===0? "#eeeeee":"white")
    signal selected()

    RowLayout
    {
        anchors.fill: parent
        spacing: 1


        AppText
        {
            id: _id
            size: 17
            color: isSelected? "white":QmlInterface.isDarkTheme? "white":"#555555"
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 50
        }

        VSeparator{}

        AppText
        {
            id: name
            size: 15
            color: isSelected? "white":QmlInterface.isDarkTheme? "white":"#555555"
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.fillWidth: true
        }

        VSeparator{}

        AppText
        {
            id: idno
            size: 15
            color: isSelected? "white":QmlInterface.isDarkTheme? "white":"#555555"
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 120
        }
    }

    MouseArea
    {
        anchors.fill: parent
        onClicked: root.selected()
    }
}
