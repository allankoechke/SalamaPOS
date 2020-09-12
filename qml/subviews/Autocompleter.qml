import QtQuick 2.0
import QtQuick.Controls 2.4 as Controls2
import QtQuick.Layouts 1.3

import "../components"

Controls2.Popup {
    width: 200
    height: 100


    contentItem: Rectangle
    {
        color: "white"
        anchors.fill: parent


        border.width: 1
        border.color: "#1e1e1e"

        Controls2.ScrollView
        {
            id: scroll
            anchors.fill: parent
            spacing: 1
            clip: true

            ListView
            {
                anchors.fill: parent
                spacing: 1

                model: ListModel{}
                delegate: Component{
                    id: completerDelegate

                    Rectangle
                    {
                        color: "white"
                        width: scroll.width
                        height: 35

                        AppText
                        {
                            color: "#2e2e2e"
                            size: 16

                            anchors.left: parent.left
                            anchors.leftMargin: 15
                            anchors.verticalCenter: parent.verticalCenter
                        }
                    }
                }
            }
        }
    }
}
