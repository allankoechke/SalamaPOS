import QtQuick 2.2
import QtQuick.Controls 2.4 as Controls2
import QtQuick.Layouts 1.3

import "../components"
import "../delegates"

Item
{
    id: root
    Layout.fillWidth: true
    Layout.fillHeight: true

    signal switchToStackTwo()

    ColumnLayout
    {
        anchors.fill: parent
        spacing: 5

        Item{
            Layout.fillWidth: true
            Layout.preferredHeight: 40
            visible: isAdmin

            RowLayout
            {
                anchors.fill: parent
                spacing: 10

                HorizontalSpacer{}

                Rectangle
                {
                    color: menuColor
                    radius: 4
                    width: 150

                    Layout.fillHeight: true

                    RowLayout
                    {
                        anchors.centerIn: parent
                        spacing: 10

                        AppIcon
                        {
                            color: "#f4f4f4"
                            size: 20
                            icon: "\uf067"

                            Layout.alignment: Qt.AlignVCenter
                        }

                        AppText
                        {
                            color: "#f4f4f4"
                            text: qsTr("New Creditee")


                            Layout.alignment: Qt.AlignVCenter
                        }
                    }

                    MouseArea
                    {
                        anchors.fill: parent
                        onClicked: newCrediteePopup.open()
                    }
                }
            }
        }

        Rectangle
        {
            border.width: 1
            border.color: "grey"
            color: QmlInterface.isDarkTheme? "#29292d":"white"

            Layout.fillWidth: true
            Layout.fillHeight: true

            ColumnLayout
            {
                anchors.fill: parent
                anchors.margins: 1
                spacing: 0

                CrediteeTableHeader
                {}

                Controls2.ScrollView
                {
                    id: scroll
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    clip: true
                    Controls2.ScrollBar.vertical.policy: Controls2.ScrollBar.AlwaysOn

                    ListView
                    {
                        anchors.fill: parent

                        model: CrediteeModel
                        delegate: Component
                        {
                            id: _delegate

                            CrediteeTableDelegate
                            {
                                width: scroll.width - 15
                                no: model.index
                                fullname: c_fname + " " + c_lname
                                mobile: "0" + c_mobile
                                idNo: c_idNo
                                debt: c_debt

                                onActionClicked: {
                                    root.switchToStackTwo()
                                    crediteeUserView.idNo = idNo;
                                    crediteeUserView.mobile = mobile;
                                    crediteeUserView.debt = debt;
                                    crediteeUserView.fname = fullname.split(" ")[0];
                                    crediteeUserView.lname = fullname.split(" ")[1];
                                    crediteeUserView.loadPaymentHistory();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

