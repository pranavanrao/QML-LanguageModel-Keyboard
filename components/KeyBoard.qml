import QtQuick 2.15
import QtQuick.Controls 2.15
import VirtualKeyboard 1.0

Item {
    id: root
    anchors.fill: parent
    anchors.margins: 10

    LanguageData {
        id: languages
    }

    KeyboardData {
        id: keyboard
    }

    Column {
        id: keyboardColumn
        width: parent.width
        height: parent.height*0.8
        spacing: keyboardColumn.height*0.03

        // First Row
        Row {
            id: firstRow
            spacing: parent.width * 0.011

            anchors.horizontalCenter: parent.horizontalCenter
            Repeater {
                id: firstRowModel
                model: keyboard.parseKeyboardKeysRow1()
                delegate: Key {
                    width: eval(modelData.width)
                    height: eval(modelData.height)
                }
            }
        }

        // Second Row
        Row {
            id: secondRow
            spacing: parent.width * 0.011

            anchors.horizontalCenter: parent.horizontalCenter
            Repeater {
                id: secondRowModel
                model: keyboard.parseKeyboardKeysRow2()
                delegate: Key {
                    width: eval(modelData.width)
                    height: eval(modelData.height)
                }
            }
        }

        // Third Row
        Row {
            id: thirdRow
            spacing: parent.width * 0.011
            anchors.horizontalCenter: parent.horizontalCenter
            Repeater {
                id: thirdRowModel
                model: keyboard.parseKeyboardKeysRow3()
                delegate: Key {
                    width: eval(modelData.width)
                    height: eval(modelData.height)
                }
            }
        }

        // Fourth Row
        Row {
            id: fourthRow
            spacing: parent.width * 0.011
            anchors.horizontalCenter: parent.horizontalCenter
            Repeater {
                id: fourthRowModel
                model: keyboard.parseKeyboardKeysRow4()
                delegate: Key {
                    width: eval(modelData.width)
                    height: eval(modelData.height)
                }
            }
        }
    }

    Component.onCompleted: {
        console.log("Key Data | First Row : ", keyboard.parseKeyboardKeysRow1());
        console.log("Key Data | Second Row : ", keyboard.parseKeyboardKeysRow2());
        console.log("Key Data | Third Row : ", keyboard.parseKeyboardKeysRow3());
        console.log("Key Data | Fourth Row : ", keyboard.parseKeyboardKeysRow4());
        keyboard.setLanguage(languageComboBox.currentText)
        firstRowModel.model = keyboard.parseKeyboardKeysRow1()
        secondRowModel.model = keyboard.parseKeyboardKeysRow2()
        thirdRowModel.model = keyboard.parseKeyboardKeysRow3()
        fourthRowModel.model = keyboard.parseKeyboardKeysRow4()
    }
}
