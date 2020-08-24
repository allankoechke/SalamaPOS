import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

import "../components"

Item {
    id: root

    Layout.fillHeight: true
    Layout.fillWidth: true
    Layout.margins: 50

    property bool isSendingMail: false

    onIsSendingMailChanged: {
        if(!isSendingMail)
        {
            sendIcon.rotation = 0;
        }
    }

    RotationAnimation
    {
        target: sendIcon
        from: 0; to: 360
        duration: 2500
        loops: RotationAnimation.Infinite
        running: isSendingMail
    }

    RowLayout
    {
        anchors.fill: parent
        anchors.leftMargin: 50
        anchors.rightMargin: 50
        anchors.topMargin: 30
        anchors.bottomMargin: 30

        Item
        {
            Layout.fillWidth: true
            Layout.fillHeight: true

            ColumnLayout
            {
                spacing: 20
                anchors.fill: parent

                Item
                {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 70

                    RowLayout
                    {
                        anchors.fill: parent
                        anchors.margins: 20
                        spacing: 10

                        Rectangle
                        {
                            Layout.fillWidth: true
                            Layout.fillHeight: true

                            color: menuColor
                        }

                        Rectangle
                        {
                            Layout.fillWidth: true
                            Layout.fillHeight: true

                            color: menuColor
                        }
                    }
                }

                ListView
                {
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    visible: listModel.count !== 0
                    spacing: 5
                    model: ListModel {id: listModel }
                    delegate: Component { Item {} }
                }

                Item
                {
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    visible: listModel.count === 0

                    ColumnLayout
                    {
                        anchors.centerIn: parent
                        spacing: 10

                        AppIcon
                        {
                            icon: "\uf49e"
                            color: "grey"
                            size: 70
                            Layout.alignment: Qt.AlignHCenter
                        }

                        AppText
                        {
                            text: qsTr("Nothing Here Yet!")
                            color: "grey"
                            size: 30

                            Layout.alignment: Qt.AlignHCenter
                        }
                    }
                }
            }
        }

        Item
        {
            Layout.fillWidth: true
            Layout.fillHeight: true

            ColumnLayout
            {
                anchors.fill: parent

                VericalSpacer{}

                AppText
                {
                    text: qsTr("Send message to Admin")
                    size: 18
                    color: "#555555"

                    Layout.alignment: Qt.AlignLeft
                }

                Rectangle
                {
                    Layout.fillWidth: true
                    Layout.minimumHeight: 300

                    color: "white"
                    radius: 5
                    border.color: "grey"
                    border.width: 1

                    TextInput
                    {
                        anchors.fill: parent
                        anchors.margins: 20
                        font.pixelSize: 15
                        font.family: montserratFontLoader.name
                        readOnly: isSendingMail

                        Text{
                            font.family: parent.font.family
                            font.pixelSize: parent.font.pixelSize
                            color: "grey"
                            text: qsTr("Compose message ...")
                            visible: parent.text===""

                            anchors.top: parent.top
                            anchors.left: parent.left
                        }
                    }
                }

                Item
                {
                    Layout.fillWidth: true
                    Layout.preferredHeight: 60

                    Rectangle
                    {
                        anchors.right: parent.right
                        anchors.rightMargin: 20
                        anchors.verticalCenter: parent.verticalCenter

                        color: "#12679a"
                        width: txt_send.width+40; height: 40; radius: 4

                        RowLayout
                        {
                            anchors.centerIn: parent
                            spacing: 10

                            AppText
                            {
                                id: txt_send
                                color: "white"
                                size: 17
                                text: isSendingMail? qsTr("Sending"):qsTr("Send")

                                Layout.alignment: Qt.AlignVCenter
                            }

                            AppIcon
                            {
                                id: sendIcon
                                color: "white"
                                size: 15
                                icon: isSendingMail? "\uf3f4":"\uf1d8"

                                Layout.alignment: Qt.AlignVCenter
                            }
                        }

                        MouseArea
                        {
                            anchors.fill: parent
                            onClicked: isSendingMail = !isSendingMail
                        }
                    }
                }

                VericalSpacer{}
            }
        }

    }
}
