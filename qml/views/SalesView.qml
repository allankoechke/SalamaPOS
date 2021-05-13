import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4 as Controls2

import "../components"
import "../subviews"

Item {
    id: root

    Layout.fillHeight: true
    Layout.fillWidth: true
    Layout.margins: 50

    property var currentScreen: 0
    property alias currentIndex: cb.currentIndex

    ColumnLayout
    {
        anchors.fill: parent
        anchors.leftMargin: 40
        anchors.rightMargin: 40
        anchors.bottomMargin: 30
        spacing: 10

        Item
        {
            Layout.fillWidth: true
            Layout.preferredHeight: 70

            Rectangle
            {
                width: parent.width
                height: 3
                color: "#d3e5ff"

                anchors.bottom: parent.bottom
                anchors.bottomMargin: 3
            }

            RowLayout
            {
                anchors.fill: parent
                spacing: 1

                AppText
                {
                    color: QmlInterface.isDarkTheme? "grey":"black"
                    size: 17
                    text: qsTr("Showing Sales for : ") /// + ["Today", "Yesterday", "This Week", "This Month", "This Year", "All Time", "Custom"][cb.currentIndex]

                    Layout.alignment: Qt.AlignVCenter
                }

                Controls2.ComboBox
                {
                    id: cb
                    height: 45
                    Layout.minimumWidth: 220
                    currentIndex: 0

                    editable: false
                    // enabled: isAdmin
                    model: isAdmin? ["Today", "Yesterday", "This Week", "This Month", "This Year", "All Time", "Custom"]:["Today", "Yesterday"]

                    Layout.rightMargin: 10

                    onCurrentIndexChanged: {
                        if(currentIndex === 0)
                            ProductSalesModel.showTodaysSales();

                        else if(currentIndex === 1)
                            ProductSalesModel.showYesterdaysSales();

                        else if(currentIndex === 2)
                            ProductSalesModel.showThisWeeksSales();

                        else if(currentIndex === 3)
                            ProductSalesModel.showThisMonthsSales();

                        else if(currentIndex === 4)
                            ProductSalesModel.showThisYearsSales();

                        else
                            ProductSalesModel.loadSalesData();
                    }
                }

                HorizontalSpacer {}

                CustomButton
                {
                    Layout.preferredHeight: 45
                    Layout.preferredWidth: 200
                    Layout.margins: 1

                    color: menuColor
                    radius: 5

                    RowLayout
                    {
                        anchors.fill: parent
                        spacing: 1

                        AppIcon
                        {
                            Layout.fillHeight: true
                            Layout.preferredWidth: height
                            horizontalAlignment: AppIcon.AlignHCenter
                            verticalAlignment: AppIcon.AlignVCenter

                            size: 16
                            color: "white"
                            icon: "\uf7d9"
                        }

                        AppText
                        {
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            horizontalAlignment: AppIcon.AlignLeft
                            verticalAlignment: AppIcon.AlignVCenter

                            color: "#f4f4f4"
                            size: 15
                            text: qsTr("Admin Options")
                        }
                    }

                    onClicked: adminSalesWindow.show()
                }

                CustomButton
                {
                    Layout.preferredHeight: 45
                    Layout.preferredWidth: 200
                    Layout.margins: 1

                    color: menuColor
                    radius: 5

                    RowLayout
                    {
                        anchors.fill: parent
                        spacing: 1

                        AppIcon
                        {
                            Layout.fillHeight: true
                            Layout.preferredWidth: height
                            horizontalAlignment: AppIcon.AlignHCenter
                            verticalAlignment: AppIcon.AlignVCenter

                            size: 16
                            color: "white"
                            icon: "\uf81d"
                        }

                        AppText
                        {
                            Layout.fillHeight: true
                            Layout.fillWidth: true
                            horizontalAlignment: AppIcon.AlignLeft
                            verticalAlignment: AppIcon.AlignVCenter

                            color: "#f4f4f4"
                            size: 15
                            text: qsTr("Credits & Debts")
                        }
                    }

                    onClicked: creditNdebtpopup.open()
                }
            }
        }

        SalesProductView
        {
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
