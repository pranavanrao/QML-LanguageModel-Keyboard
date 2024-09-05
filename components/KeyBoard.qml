import QtQuick 2.15
import QtQuick.Controls 2.15
import VirtualKeyboard 1.0

Item {
    id: root
    // anchors.fill: parent
    anchors.margins: 10

    property string filename: "components/KeyBoard.qml"
    signal keyPressed(string key);

    LanguageData {
        id: languages
    }

    KeyboardData {
        id: keyboard
    }

    function loadAllRows() {
        firstRowModel.model = keyboard.parseKeyboardKeysRow1();
        secondRowModel.model = keyboard.parseKeyboardKeysRow2();
        thirdRowModel.model = keyboard.parseKeyboardKeysRow3();
        fourthRowModel.model = keyboard.parseKeyboardKeysRow4();
    }

    Column {
        id: keyboardColumn
        width: parent.width
        height: parent.height
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
        console.log(filename, " Key Data | First Row : ", keyboard.parseKeyboardKeysRow1());
        console.log(filename, " Key Data | Second Row : ", keyboard.parseKeyboardKeysRow2());
        console.log(filename, " Key Data | Third Row : ", keyboard.parseKeyboardKeysRow3());
        console.log(filename, " Key Data | Fourth Row : ", keyboard.parseKeyboardKeysRow4());
        keyboard.setLanguage(languageComboBox.currentText);
        loadAllRows();
    }
}
