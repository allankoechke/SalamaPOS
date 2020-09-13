import QtQuick 2.0
import QtQuick.Layouts 1.3

import "../components"

Rectangle {
    id: root
    property bool isHighlighted: false
    property string label: ""
    property int labelIndex: -1

    signal clicked()

    height: 40
    color: isHighlighted? Qt.lighter(menuColor):"#eeeeee"

    RowLayout
    {
        anchors.fill: parent
        spacing: 5

        AppText
        {
            Layout.alignment: Qt.AlignVCenter
            Layout.leftMargin: 5
            Layout.preferredWidth: 30
            horizontalAlignment: AppText.AlignLeft

            text: (labelIndex+1).toString()+". "
            color: isHighlighted? "white":"black"
        }

        Item{
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true

            AppText
            {
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 15

                text: label
                color: isHighlighted? "white":"black"
            }
        }
    }

    MouseArea
    {
        anchors.fill: parent
        onClicked: root.clicked()
    }
}