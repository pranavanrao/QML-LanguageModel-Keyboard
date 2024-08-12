import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import VirtualKeyboard 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Virtual Keyboard")

    LanguageData {
        id: languages
    }

    KeyboardData {
        id: keyboard
    }

    Column {
        spacing: 2
        anchors.fill: parent

        ComboBox {
            id: languageComboBox
            width: parent.width
            model: languages.parseKeyboards()
            currentIndex: 1

            onActivated: {
                console.log("Selected language:", languageComboBox.currentText)
                keyboard.setLanguage(languageComboBox.currentText)
                keyboardComboBox.model = keyboard.parseKeyboardLayers()
                keyGridRepeater.model = keyboard.parseKeyboardKeys()
            }
        }

        ComboBox {
            id: keyboardComboBox
            width: parent.width
            model: keyboard.parseKeyboardLayers()

            onActivated: {
                console.log("Selected layers:", keyboardComboBox.currentText)
                keyboard.setLayer(keyboardComboBox.currentText)
                keyGridRepeater.model = keyboard.parseKeyboardKeys();
            }
        }

        Grid {
            id: keyGrid
            width: parent.width
            rows: 4
            spacing: 5

            Repeater {
                id: keyGridRepeater
                model: keyboard.parseKeyboardKeys()

                delegate: Rectangle {
                    width: 60
                    height: 60
                    color: "lightgray"
                    border.color: "black"
                    radius: 5

                    Text {
                        anchors.centerIn: parent
                        text: modelData
                        font.pixelSize: 20
                    }
                }
            }
        }
    }

    Component.onCompleted: {
        keyboard.setLanguage(languageComboBox.currentText)
        keyboardComboBox.model = keyboard.parseKeyboardLayers()
        keyGrid.model = keyboard.parseKeyboardKeys()
    }
}
