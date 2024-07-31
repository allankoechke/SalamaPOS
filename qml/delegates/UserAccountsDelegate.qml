import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4

import "../components"

Rectangle {
    id: root
    height: 55
    color: QmlInterface.isDarkTheme? (((_index+1)%2)===0? Qt.lighter("#29292d", 1.3):Qt.lighter("#29292d", 1.5)):(((_index+1)%2)===0? "#eeeeee":"white")

    property int _index
    property string fname: ""
    property string lname: ""
    property string uname: ""
    property string phoneNo: "0700XXXXXX"
    property string date: new Date()
    property string priviledges: ""
    property bool isAdmin: canCreateUser && canDeleteUser && canCreateItems && canDeleteItems && canAddStock && canDeleteStock && canDeleteSales && canBackupDb
    property bool canCreateUser: false
    property bool canDeleteUser: false
    property bool canCreateItems: false
    property bool canDeleteItems: false
    property bool canAddStock: false
    property bool canDeleteStock: false
    property bool canDeleteSales: false
    property bool canBackupDb: false

    signal editedChanged()

    RowLayout
    {
        anchors.fill: parent
        spacing: 1

        Item{
            Layout.fillHeight: true
            Layout.preferredWidth: height

            AppIcon
            {
                size: 20
                color: menuColor
                icon: isAdmin? "\uf505": "\uf406"

                anchors.centerIn: parent
            }
        }


        AppText
        {
            color: QmlInterface.isDarkTheme? "#999fa6":"black"
            text: fname + " " + lname
            wrapMode: AppText.WordWrap
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.fillWidth: true
            Layout.minimumWidth: 150
            Layout.maximumWidth: 300
        }

        AppText
        {
            color: QmlInterface.isDarkTheme? "#999fa6":"black"
            text: phoneNo
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 150
        }

        AppText
        {
            color: QmlInterface.isDarkTheme? "#999fa6":"black"
            text: Qt.formatDateTime(date, "dd MMM, yyyy")
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 150
        }

        Item{
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true

            AppText
            {
                color: QmlInterface.isDarkTheme? "#999fa6":"black"
                text: priviledges
                width: parent.width
                elide: AppText.ElideRight

                anchors.left: parent.left
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter
            }
        }


        Item{
            Layout.preferredWidth: 100
            Layout.fillHeight: true
            enabled: mainApp.isAdmin
            opacity: enabled ? 1 : 0.4

            RowLayout
            {
                anchors.centerIn: parent

                AppIcon
                {
                    size: 15
                    color: menuColor
                    icon: "\uf5a1"

                    Layout.alignment: Qt.AlignVCenter
                }

                AppText
                {
                    color: QmlInterface.isDarkTheme? "#999fa6":"black"
                    text: qsTr("Edit")

                    Layout.alignment: Qt.AlignVCenter
                }
            }

            MouseArea
            {
                anchors.fill: parent
                cursorShape: parent.enabled ? Qt.ArrowCursor : Qt.ForbiddenCursor
                onClicked: root.editedChanged();
            }
        }
    }
}
