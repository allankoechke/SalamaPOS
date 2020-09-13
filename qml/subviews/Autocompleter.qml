import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.2
import QtQml 2.12

import "../components"
import "../delegates"

FocusScope {
    id: autocomplete

    Layout.preferredHeight: field.height
    height: field.height

    // property alias model: completions.model
    property string input
    property alias text: field.text
    property alias itemHeight: field.height
    property alias placeholderText: field.placeholderText
    property alias completionsVisible: completionsBox.visible

    signal accepted()
    signal edited()

    onInputChanged: {
        console.log("AutoComplete: autocomplete: 'inputChanged()' signal received")
        text = input
    }

    // The text field where a user enters to-be-completed text.
    TextField {
        id: field
        focus: true
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        inputMethodHints: Qt.ImhSensitiveData
        selectByMouse: true //!Kirigami.Settings.isMobile
        Component.onCompleted: forceActiveFocus() //if (!Kirigami.Settings.isMobile) forceActiveFocus()

        onTextEdited: {
            autocomplete.edited();
            autocomplete.input = text
            completions.currentIndex = -1
            completionsVisible = CompleterModel.size() > 0 ? true : false;
            console.log("-> ", CompleterModel.size())
        }

        onAccepted: {
            autocomplete.focus = false
            autocomplete.completionsVisible = false
            completions.currentIndex = -1
            var searchTerm = normalize(text)
            autocomplete.input = searchTerm
            autocomplete.accepted()
        }

        onActiveFocusChanged: {
            if (activeFocus && CompleterModel.size() > 0)
                completionsVisible = (text === "" || text.match("^[0-9 ]+$")) ? false : true

            else
                completionsVisible = false
        }

        Keys.onPressed: {
            if (completionsVisible) {
                switch (event.key) {

                case Qt.Key_Escape:
                    completionsVisible = false
                    completions.currentIndex = -1
                    event.accepted = true
                    break

                case Qt.Key_Up:
                    completions.currentIndex--

                    // When moving prior the first item, cycle through completions from the end again.
                    if (completions.currentIndex < 0)
                        completions.currentIndex = CompleterModel.size() - 1

                    console.log(
                                "completions.model[" + completions.currentIndex + "]: " +
                                JSON.stringify(completions.model[completions.currentIndex])
                                )

                    field.text = completions.model[completions.currentIndex]
                    event.accepted = true
                    break

                case Qt.Key_Down:
                    completions.currentIndex++

                    // When moving past the last item, cycle through completions from the start again.
                    if (completions.currentIndex > CompleterModel.size() - 1)
                        completions.currentIndex = 0

                    field.text = completions.model[completions.currentIndex]
                    event.accepted = true
                    break

                case Qt.Key_Return:
                    field.accepted()
                    event.accepted = true;
                    break
                }
            }
            else {
                switch (event.key) {

                case Qt.Key_Escape:
                    autocomplete.focus = false
                    event.accepted = true
                    break

                case Qt.Key_Down:
                    completionsVisible = CompleterModel.size() > 0 ? true : false

                    event.accepted = true
                    break
                }
            }
        }

        Rectangle {
            id: completionsBox

            visible: false
            anchors.top: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            height: (completions.model===null || completions.model===undefined)? 50:CompleterModel.size()<10? 32*CompleterModel.size():320

            color: "white"
            border.width: 1
            border.color: "silver"

            ScrollView
            {
                width: completionsBox.width
                height: completionsBox.height
                anchors.centerIn: parent

                clip: true
                spacing: 1

                ListView
                {
                    id: completions
                    width: parent.width - 5
                    height: parent.height
                    anchors.top: parent.top
                    anchors.left: parent.left
                    currentIndex: -1

                    model: CompleterModel
                    delegate: Component
                    {
                        AutocompleteDelegate
                        {
                            label: name
                            isHighlighted: index === completions.currentIndex

                            onClicked: completions.currentIndex = index
                        }
                    }
                }
            }

        }
    }
}
