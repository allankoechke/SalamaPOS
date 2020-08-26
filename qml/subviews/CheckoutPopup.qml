import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

import "../components"

Controls2.Drawer {
    id: root

    width: 400
    height: mainApp.height
    edge: Qt.RightEdge
    closePolicy: Controls2.Drawer.NoAutoClose

    contentItem: Rectangle
    {
        color: bgColor
        anchors.fill: parent

        ColumnLayout
        {
            anchors.fill: parent
            spacing: 20

            Item
            {
                height: 80
                Layout.fillWidth: true

                AppText
                {
                    color: "#535353"
                    size: 18
                    text: qsTr("Complete transaction")

                    anchors.centerIn: parent
                }

                Item
                {
                    height: 40
                    width: 40

                    anchors.right: parent.right
                    anchors.rightMargin: 20
                    anchors.verticalCenter: parent.verticalCenter

                    AppIcon
                    {
                        icon: "\uf057"
                        size: 30
                        color: "red"

                        anchors.centerIn: parent
                    }

                    MouseArea
                    {
                        anchors.fill: parent
                        onClicked: root.close();
                    }
                }

                Rectangle
                {
                    width: parent.width
                    height: 3
                    color: "black"
                    opacity: 0.078

                    anchors.bottom: parent.bottom
                }
            }

            Item {
                id: _x
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.margins: 20

                Controls2.ScrollView
                {
                    anchors.fill: parent
                    width: _x.width-40
                    clip: true
                    Controls2.ScrollBar.vertical.policy: Controls2.ScrollBar.AlwaysOn

                    ColumnLayout
                    {
                        anchors.fill: parent
                        width: _x.width-40
                        spacing: 20

                        AppText
                        {
                            color: "#555555"
                            size: 40
                            text: qsTr("Sales: Ksh. 0.00")

                            Layout.alignment: Qt.AlignHCenter
                        }

                        CheckoutPaymentItem
                        {
                            // Cash payment

                            Layout.preferredWidth: _x.width-20

                            _icon: "\uf555"
                            label: qsTr("Cash Payment")
                        }

                        CheckoutPaymentItem
                        {
                            // M-Pesa Payment
                            Layout.preferredWidth: _x.width-20

                            _icon: "\uf3ce"
                            label: qsTr("M~Pesa Payment")
                        }

                        CheckoutPaymentItem
                        {
                            // Cheque Payment
                            Layout.preferredWidth: _x.width-20

                            _icon: "\uf53d"
                            label: qsTr("Cheque Payment")
                        }

                        CheckoutPaymentItem
                        {
                            // Credit Payment
                            Layout.preferredWidth: _x.width-20

                            _icon: "\uf09d"
                            label: qsTr("Credit Payment")
                        }

                        Rectangle
                        {
                            color: "#0091d9"
                            radius: 10

                            Layout.fillWidth: true
                            Layout.preferredHeight: 60
                            Layout.margins: 20

                            AppText
                            {
                                color: "white"
                                size: 20
                                text: qsTr("SUBMIT")

                                anchors.centerIn: parent
                            }
                        }
                    }
                }
            }
        }
    }
}
