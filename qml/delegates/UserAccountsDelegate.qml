import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4

import "../components"

Rectangle {
    id: root
    height: 55
    color: ((_index+1)%2)===0? "#eeeeee":"white"

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

    Component.onCompleted: {
        priviledges += canCreateUser? "Can create accounts, ":""
        priviledges += canDeleteUser? "Can delete accounts, ":""
        priviledges += canCreateItems? "Can add products, ":""
        priviledges += canDeleteItems? "Can delete products, ":""
        priviledges += canAddStock? "Can add stock, ":""
        priviledges += canDeleteStock? "Can delete stock, ":""
        priviledges += canDeleteSales? "Can delete sales, ":""
        priviledges += canBackupDb? "Can backup database": ""
    }

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
            color: "black"
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
            color: "black"
            text: phoneNo
            horizontalAlignment: AppText.AlignHCenter

            Layout.alignment: Qt.AlignVCenter|Qt.AlignHCenter
            Layout.preferredWidth: 150
        }

        AppText
        {
            color: "black"
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
                color: "black"
                text: priviledges
                wrapMode: AppText.WordWrap

                anchors.centerIn: parent
            }
        }


        Item{
            Layout.preferredWidth: 100
            Layout.fillHeight: true

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
                    color: "black"
                    text: qsTr("Edit")

                    Layout.alignment: Qt.AlignVCenter
                }
            }

            MouseArea
            {
                anchors.fill: parent
                onClicked: root.editedChanged();
            }
        }
    }
}
