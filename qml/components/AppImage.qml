import QtQuick 2.0
import QtQuick.Layouts 1.3
import "../components"

Item {
    id: root
    Layout.fillHeight: true

    property string statusIcon
    property string statusLabel
    property int statusCount: 0

    signal clicked()

    Layout.preferredWidth: statusCount===0? 20+_three.width:24+_two.width+_three.width

    RowLayout
    {
        //anchors.fill: parent
        //anchors.margins: 2

        AppIcon
        {
            id: _one
            icon: statusIcon
            color: "grey"
            size: 15
            Layout.alignment: Qt.AlignVCenter|Qt.AlignLeft
        }

        AppText
        {
            id: _two
            visible: statusCount !== 0
            font.pixelSize: 15
            color: "grey"
            text: "(" + statusCount.toString() + ")"
            Layout.alignment: Qt.AlignVCenter|Qt.AlignLeft

        }

        AppText
        {
            id: _three
            font.pixelSize: 15
            color: "grey"
            text: statusLabel
            Layout.alignment: Qt.AlignVCenter|Qt.AlignLeft

        }
    }

    MouseArea
    {
        anchors.fill: parent
        onClicked: root.clicked()
    }
}
