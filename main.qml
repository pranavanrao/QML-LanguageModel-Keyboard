import QtQuick 2.15
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import VirtualKeyboard 1.0

Window {
    width: 800
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

        Column {
            id: keyboardColumn
            spacing: 10

            anchors.horizontalCenter: parent.horizontalCenter

            // First Row
            Row {
                id: firstRow
                spacing: 5
                anchors.horizontalCenter: parent.horizontalCenter
                Repeater {
                    id: firstRowModel
                    model: keyboard.parseKeyboardKeysRow1()  // Access the first row's keys
                    delegate: Key {}
                }
            }

            // Second Row
            Row {
                id: secondRow
                spacing: 5
                anchors.horizontalCenter: parent.horizontalCenter
                Repeater {
                    id: secondRowModel
                    model: keyboard.parseKeyboardKeysRow2() // Access the second row's keys
                    delegate: Key {}
                }
            }

            // Third Row
            Row {
                id: thirdRow
                spacing: 5
                anchors.horizontalCenter: parent.horizontalCenter
                Repeater {
                    id: thirdRowModel
                    model: keyboard.parseKeyboardKeysRow3() // Access the third row's keys
                    delegate: Key {}
                }
            }

            // Fourth Row (if any)
            Row {
                id: fourthRow
                spacing: 5
                anchors.horizontalCenter: parent.horizontalCenter
                Repeater {
                    id: fourthRowModel
                    model: keyboard.parseKeyboardKeysRow4() // Access the fourth row's keys, if available
                    delegate: Key {}
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
                keyboardComboBox.currentIndex = 0;
                firstRowModel.model = keyboard.parseKeyboardKeysRow1()
                secondRowModel.model = keyboard.parseKeyboardKeysRow2()
                thirdRowModel.model = keyboard.parseKeyboardKeysRow3()
                fourthRowModel.model = keyboard.parseKeyboardKeysRow4()
            }
        }

        ComboBox {
            id: keyboardComboBox
            model: keyboard.parseKeyboardLayers()

            anchors.horizontalCenter: parent.horizontalCenter

            onActivated: {
                console.log("Selected layers:", keyboardComboBox.currentText)
                keyboard.setLayer(keyboardComboBox.currentText)
                firstRowModel.model = keyboard.parseKeyboardKeysRow1()
                secondRowModel.model = keyboard.parseKeyboardKeysRow2()
                thirdRowModel.model = keyboard.parseKeyboardKeysRow3()
                fourthRowModel.model = keyboard.parseKeyboardKeysRow4()
            }
        }
    }

    Component.onCompleted: {
        console.log("Key Data | First Row : ", keyboard.parseKeyboardKeysRow1());
        console.log("Key Data | Second Row : ", keyboard.parseKeyboardKeysRow2());
        console.log("Key Data | Third Row : ", keyboard.parseKeyboardKeysRow3());
        console.log("Key Data | Fourth Row : ", keyboard.parseKeyboardKeysRow4());
        keyboard.setLanguage(languageComboBox.currentText)
        keyboardComboBox.model = keyboard.parseKeyboardLayers()
        firstRowModel.model = keyboard.parseKeyboardKeysRow1()
        secondRowModel.model = keyboard.parseKeyboardKeysRow2()
        thirdRowModel.model = keyboard.parseKeyboardKeysRow3()
        fourthRowModel.model = keyboard.parseKeyboardKeysRow4()
    }
}
