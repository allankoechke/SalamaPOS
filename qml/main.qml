import QtQuick 2.14
import QtQuick.Window 2.14

import "./views"

Window {
    id: mainApp
    visible: true
    width: 1020
    height: 720
    title: qsTr("MySale App")

    property alias montserratFontLoader: montserratFontLoader
    property alias fontAwesomeFontLoader: fontAwesomeFontLoader

    property string bgColor: "#f4f9fa"
    property string menuColor: "#12679a"
    property string tableHeaderColor: "#5f00ff"

    Component.onCompleted: mainApp.showMaximized();

    MainAppView
    {
        id: mainAppView
    }

    FontLoader
    {
        id: fontAwesomeFontLoader
        source: "qrc:/assets/fonts/fontawesome.otf"
    }

    FontLoader
    {
        id: montserratFontLoader
        source: "qrc:/assets/fonts/montserrat/Montserrat-Regular.ttf"
    }
}
