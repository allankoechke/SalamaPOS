import QtQuick 2.0
import QtQuick.Controls 2.4

import "../delegates"
import "../models"

Popup
{
    id: root
    modal: false
    closePolicy: "NoAutoClose"
    x: mainApp.width - width - 20
    y: mainApp.height - height - 20
    width: 300
    height: AlarmsModel.size===0? 0:AlarmsModel.size * 53

    property alias alarmsListView: alarmsListView

    onOpened: {
        console.log("Popup created")
    }

    onClosed: {
        console.log("Popup closing")
    }

    background: Rectangle
    {
        id: bg
        width: root.width
        height: root.height
        visible: mainAppView.navBarIndex !== 7 && mainAppView !== 8
        color: bgColor

        ListView
        {
            id: alarmsListView
            anchors.fill: parent
            width: parent.width
            height: parent.height
            spacing: 5

            model: AlarmsModel
            delegate: AlarmsWidgetDelegate
            {
                alarmId: alarm_id
                category: alarm_type
                content: alarm_text
            }
        }
    }
}
