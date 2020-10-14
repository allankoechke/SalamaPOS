import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

import "../components"

Rectangle {
    id: root

    width: 300
    height: 50
    color: category==="error"? "red":category==="info"? "green":"yellow"
    radius: 5

    property string alarmId
    property alias content: txt.text
    property string category

    Timer
    {
        id: alarmTimer
        repeat: false
        interval: category==="error"? 5000:category==="info"? 3500:3500
        running: true

        onTriggered: AlarmsModel.removeAlarmItem(alarmId)
    }

    RowLayout
    {
        anchors.fill: parent
        spacing: 0

        AppIcon
        {
            Layout.fillHeight: true
            Layout.preferredWidth: 40
            verticalAlignment: AppIcon.AlignVCenter
            horizontalAlignment: AppIcon.AlignHCenter

            color: "white"
            icon: category==="\uf071"? "red":category==="info"? "\uf05a":"\uf06a"
            size: 30
        }

        Rectangle
        {
            height: root.height-20
            Layout.preferredWidth: 1

            color: "silver"
            Layout.alignment: Qt.AlignVCenter
        }

        Item{
            Layout.fillWidth: true
            Layout.fillHeight: true

            AppText
            {
                id: txt
                width: parent.width-20
                color: "white"
                wrapMode: AppText.WordWrap
                elide: AppText.ElideRight

                anchors.verticalCenter: parent.verticalCenter
            }

        }

        Rectangle
        {
            height: root.height-10
            Layout.preferredWidth: 1

            color: "silver"
            Layout.alignment: Qt.AlignVCenter
        }

        Item{
            Layout.fillHeight: true
            Layout.preferredWidth: 30

            AppIcon
            {
                color: "white"
                size: 15
                icon: "\uf00d"

                anchors.centerIn: parent
            }

            MouseArea
            {
                anchors.fill: parent
                onClicked: {
                    if (alarmTimer.running === true)
                        alarmTimer.running = false

                    AlarmsModel.removeAlarmItem(alarmId)
                }

            }

        }
    }
}
