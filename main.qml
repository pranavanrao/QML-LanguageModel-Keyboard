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

            onActivated: {
                console.log("Selected language:", languageComboBox.currentText)
            }
        }

        ComboBox {
            id: keyboardComboBox
            width: parent.width
            model: keyboard.parseKeyboardLayers()

            onActivated: {
                console.log("Selected layers:", keyboardComboBox.currentText)
            }
        }
    }
}
