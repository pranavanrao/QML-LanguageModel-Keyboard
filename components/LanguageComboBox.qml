import QtQuick 2.15
import QtQuick.Controls 2.15

ComboBox {
    id: languageComboBox
    model: languages.parseKeyboards()
    currentIndex: 1

    anchors.bottom: parent.bottom
    anchors.horizontalCenter: parent.horizontalCenter

    onActivated: {
        console.log("Selected language:", languageComboBox.currentText)
        keyboard.setLanguage(languageComboBox.currentText)
        firstRowModel.model = keyboard.parseKeyboardKeysRow1()
        secondRowModel.model = keyboard.parseKeyboardKeysRow2()
        thirdRowModel.model = keyboard.parseKeyboardKeysRow3()
        fourthRowModel.model = keyboard.parseKeyboardKeysRow4()
    }
}
