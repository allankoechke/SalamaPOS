import QtQuick 2.0
import QtQuick.Layouts 1.3
import "../components"

Item {
    id: root

    Layout.fillHeight: true
    Layout.preferredWidth: 70+usr_name.width

    signal clicked()

    RowLayout
    {
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.left: parent.left
        spacing: 10

        Item
        {
            Layout.fillHeight: true
            Layout.fillWidth: true

            ColumnLayout
            {
                Layout.fillWidth: true
                spacing: 2
                anchors.verticalCenter: parent.verticalCenter

                AppText
                {
                    id: usr_name
                    text: loggedUser_fullname
                    color: "grey"
                    size: 14

                    Layout.fillWidth: true
                    horizontalAlignment: AppText.AlignRight
                }

                AppText
                {
                    text: loggedUser_username
                    color: "grey"
                    size: 10

                    Layout.fillWidth: true
                    horizontalAlignment: AppText.AlignRight
                }
            }
        }

        Item
        {
            id: userIcon
            Layout.minimumHeight: 50
            Layout.fillHeight: true
            Layout.preferredWidth: 60
            //clip: true

            signal btnClicked()

            AppIcon
            {
                icon: "\uf2bd"
                color: Qt.lighter(menuColor)
                size: 45

                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }

            AppIcon
            {
                icon: "\uf0dd"
                color: "#535353"
                size: 20

                anchors.bottom: parent.bottom
                anchors.right: parent.right
                anchors.bottomMargin: 5
                anchors.rightMargin: 5
            }

            MouseArea
            {
                anchors.fill: parent
                onClicked: {
                    root.clicked();
                }
            }

        }
    }
}
