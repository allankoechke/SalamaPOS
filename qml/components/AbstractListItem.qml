import QtQuick 2.1
import QtQuick.Layouts 1.0
import QtQuick.Templates 2.0 as T2
import QtQuick.Templates 2.4 as QQC2

T2.ItemDelegate {
    id: listItem

    property bool supportsMouseEvents: hoverEnabled

    property alias containsMouse: listItem.hovered

    property bool alternatingBackground: false

    property bool sectionDelegate: false

    property bool separatorVisible: true

    property color textColor: "#2e2e2e"// Theme.textColor

    property color backgroundColor: "transparent"

    property color alternateBackgroundColor: Qt.lighter("grey") // Theme.alternateBackgroundColor

    property color activeTextColor: menuColor //Theme.highlightedTextColor

    property color activeBackgroundColor: "yellow" //Theme.highlightColor

    default property alias _default: listItem.contentItem

    // Overrides action property of newer import versions which we can't use
    property QQC2.Action action

    activeFocusOnTab: ListView.view ? false : true

    text: action ? action.text : undefined
    checked: action ? action.checked : false
    checkable: action ? action.checkable : false
    onClicked: {
        if (ListView.view && typeof index !== "undefined") {
            ListView.view.currentIndex = index;
        }
        if (!action) {
            return;
        }

        action.trigger();
        checked = Qt.binding(function() { return action.checked });
    }
    //Theme.inherit: false
    //Theme.colorSet: Theme.View

    padding:  Units.smallSpacing //Settings.tabletMode ? Units.largeSpacing : Units.smallSpacing

    leftPadding: padding*2
    topPadding: padding

    rightPadding: padding*2
    bottomPadding: padding

    implicitWidth: contentItem ? contentItem.implicitWidth + leftPadding + rightPadding : 200 //Units.gridUnit * 12

    implicitHeight: contentItem.implicitHeight + topPadding + bottomPadding

    width: parent && parent.width > 0 ? parent.width : implicitWidth
    Layout.fillWidth: true

    opacity: enabled ? 1 : 0.6

    height: visible ? implicitHeight : 0

    hoverEnabled: true

    QtObject {
        id: internal
        property Flickable view: listItem.ListView.view || (listItem.parent ? listItem.parent.ListView.view : null)
        property bool indicateActiveFocus: listItem.pressed /*|| Settings.tabletMode */|| listItem.activeFocus || (view ? view.activeFocus : false)
    }

    Accessible.role: Accessible.ListItem
    highlighted: focus && ListView.isCurrentItem && ListView.view && ListView.view.keyNavigationEnabled
}
