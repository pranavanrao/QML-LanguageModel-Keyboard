import QtQuick 2.15
import QtQuick.Controls 2.15

ComboBox {
    id: languageComboBox
    model: languages.parseKeyboards()
    currentIndex: 1

    z: 1000

    anchors.bottom: parent.bottom
    anchors.horizontalCenter: parent.horizontalCenter

    property string filename: "component/LanguageComboBox.qml"

    onActivated: {
        inputMain.inputText = "";
        console.log(filename, " Selected language:", languageComboBox.currentText)
        keyboard.setLanguage(languageComboBox.currentText)
        loadAllRows();
    }
}
