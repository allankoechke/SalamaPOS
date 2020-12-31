import QtQuick 2.12
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

// import "../components"

Popup {
    id: root
    modal: true
    width: 250; height: 150
    closePolicy: Popup.NoAutoClose

    x: (mainApp.width-width)/2
    y: (mainApp.height-height)/2

    property alias text: txt.text

    signal accepted();
    signal declined();

    contentItem: Rectangle
    {
        anchors.fill: parent
        color: bgColor
        border.width: 1
        border.color: "silver"

        ColumnLayout
        {
            anchors.fill: parent
            spacing: 0

            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.margins: 20

                AppText
                {
                    id: txt
                    width: parent.width
                    anchors.verticalCenter: parent.verticalCenter
                    wrapMode: AppText.WordWrap
                    elide: AppText.ElideRight
                    color: QmlInterface.isDarkTheme? "white":"black"
                }
            }

            Rectangle
            {
                Layout.fillWidth: true
                Layout.preferredHeight: 2
                color: "silver"
                opacity: 0.4
            }

            Item{
                Layout.fillWidth: true
                Layout.preferredHeight: 40

                RowLayout
                {
                    anchors.fill: parent
                    spacing: 0

                    Rectangle
                    {
                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        color: "#fe7a17"

                        AppText
                        {
                            color: "white"
                            size: 16
                            font.bold: true
                            text: qsTr("CANCEL")

                            anchors.centerIn: parent
                        }

                        MouseArea
                        {
                            anchors.fill: parent
                            onClicked: {
                                root.accepted()
                                root.close();
                            }
                        }
                    }

                    Rectangle
                    {
                        Layout.fillHeight: true
                        Layout.preferredWidth: 2
                        color: "silver"
                        opacity: 0.4
                    }

                    Rectangle
                    {
                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        color: "green"

                        AppText
                        {
                            color: "white"
                            size: 16
                            font.bold: true
                            text: qsTr("OK")

                            anchors.centerIn: parent
                        }

                        MouseArea
                        {
                            anchors.fill: parent
                            onClicked: root.accepted()
                        }
                    }
                }
            }
        }
    }
}
