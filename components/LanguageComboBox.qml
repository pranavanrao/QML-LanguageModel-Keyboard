import QtQuick 2.15
import QtQuick.Controls 2.12

ComboBox {
    id: control
    model: languages.parseKeyboards()
    currentIndex: 1

    property string filename: "component/LanguageComboBox.qml"

    delegate: ItemDelegate {
        width: control.width
        contentItem: Text {
            text: modelData
            color: "#FFFFFF"
            font.pixelSize: keyText.font.pixelSize * 0.7
            elide: Text.ElideRight
            verticalAlignment: Text.AlignVCenter
        }

        background: Rectangle {
            color: control.highlightedIndex === index ? "#007ACC" : "transparent"
            radius: 10
        }

        highlighted: control.highlightedIndex === index
    }

    popup: Popup {
        // y: control.height - 1
        width: control.width
        height: root.height * 0.9
        implicitHeight: contentItem.implicitHeight
        padding: 1

        contentItem: ListView {
            clip: true
            implicitHeight: contentHeight
            model: control.popup.visible ? control.delegateModel : null
            currentIndex: control.highlightedIndex

            ScrollIndicator.vertical: ScrollIndicator { }
        }

        background: Rectangle {
            color: "#444444"
            radius: 10
        }
    }

    onActivated: {
        inputMain.inputText = "";
        console.log(filename, " Selected language:", control.currentText)
        keyboard.setLanguage(control.currentText)
        loadAllRows();
    }
}
