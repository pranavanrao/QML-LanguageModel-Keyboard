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
        spacing: 10
        anchors.fill: parent
        anchors.margins: 50

        Grid {
            id: keyGrid
            rows: 4
            spacing: 5
            anchors.horizontalCenter: parent.horizontalCenter

            Repeater {
                id: keyGridRepeater
                model: keyboard.parseKeyboardKeys()

                delegate: Rectangle {
                    width: 60
                    height: 60
                    color: "#424949"
                    radius: 5

                    Text {
                        anchors.centerIn: parent
                        text: modelData
                        font.pixelSize: 24
                        color: "white"
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: console.log("Key Text : ", model.text)
                    }
                }
            }
        }

        ComboBox {
            id: languageComboBox
            model: languages.parseKeyboards()
            currentIndex: 1

            anchors.horizontalCenter: parent.horizontalCenter

            onActivated: {
                console.log("Selected language:", languageComboBox.currentText)
                keyboard.setLanguage(languageComboBox.currentText)
                keyboardComboBox.model = keyboard.parseKeyboardLayers()
                keyGridRepeater.model = keyboard.parseKeyboardKeys()
            }
        }

        ComboBox {
            id: keyboardComboBox
            model: keyboard.parseKeyboardLayers()

            anchors.horizontalCenter: parent.horizontalCenter

            onActivated: {
                console.log("Selected layers:", keyboardComboBox.currentText)
                keyboard.setLayer(keyboardComboBox.currentText)
                keyGridRepeater.model = keyboard.parseKeyboardKeys();
            }
        }
    }

    Component.onCompleted: {
        console.log("Key Data:", keyboard.parseKeyboardKeys());
        keyboard.setLanguage(languageComboBox.currentText)
        keyboardComboBox.model = keyboard.parseKeyboardLayers()
        keyGridRepeater.model = keyboard.parseKeyboardKeys()
    }
}
