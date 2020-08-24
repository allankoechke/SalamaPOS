import QtQuick 2.0
import QtQuick.Layouts 1.3
import "../components"

Item {
    Layout.fillHeight: true
    Layout.preferredWidth: 70+usr_name.width

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
                    text: "My Name"
                    color: "grey"
                    size: 14

                    Layout.fillWidth: true
                    horizontalAlignment: AppText.AlignRight
                }

                AppText
                {
                    text: "Teller"
                    color: "grey"
                    size: 10

                    Layout.fillWidth: true
                    horizontalAlignment: AppText.AlignRight
                }
            }
        }

        Item
        {
            Layout.fillHeight: true
            Layout.preferredWidth: 60
            //clip: true

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
                anchors.bottomMargin: -20
                anchors.rightMargin: 5

            }
        }
    }
}
