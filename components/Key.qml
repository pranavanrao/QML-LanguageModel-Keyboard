import QtQuick 2.15

Rectangle {
    id: keyRect
    color: modelData.color
    radius: 10

    property string currentText;
    property int keyIndex: index;

    function switchLayer(layer) {
        keyboard.setLayer(layer);
        loadAllRows();
    }

    ToggleKey {
        id:togglebtn
        visible: false
    }

    Image {
        id: keyImage
        anchors.centerIn: parent
        source: modelData.image
        visible: modelData.image !== undefined
        width: keyRect.height * 0.6
        height: keyRect.height * 0.6
    }

    Text {
        id: keyText
        anchors.centerIn: parent
        text: {
            if (capsEnabled) {
                return modelData.alternativeUpperCaseKey ? modelData.alternativeUpperCaseKey : modelData.text.toUpperCase();
            } else {
                return modelData.text;
            }
        }
        visible: modelData.text !== undefined
        font.pixelSize: keyRect.height * 0.6
        font.weight: Font.DemiBold
        color: "white"
    }

    LanguageComboBox {
        id: langCombo
        width: parent.width
        visible: false
    }

    MouseArea {
        anchors.fill: parent
        onPressAndHold: {
            if (modelData.text === "space") {
                langCombo.popup.open();
            }

            if (modelData.key === "Qt.Key_Backspace") {
                console.log("Long press on back key!!!")
                inputMain.inputText = "";
            }
            currentText = modelData.text
            togglebtn.visible = true;
            console.log("Index of the key : ", keyIndex)
        }

        onClicked: {
            togglebtn.visible = false;
            console.log("Key Text : ", modelData.text || modelData.key);

            switch (modelData.text || modelData.key) {
            case "caps_toggle":
                capsEnabled = !capsEnabled;
                break;

            case "?123":
                switchLayer("layer2"); // Change to Layer 2
                break;

            case "#+=":
                switchLayer("layer3"); // Change to Layer 3
                break;

            case "abc":
                switchLayer("layer1"); // Change to Layer 1
                break;

            case "123":
                switchLayer("layer2"); // Change to Layer 2
                break;

            case "space":
                root.keyPressed(" ");
                break;

            case "Qt.Key_Backspace":
                if (inputMain.inputText.length > 0) {
                    inputMain.inputText = inputMain.inputText.substring(0, inputMain.inputText.length - 1);
                }
                break;

            default:
                if (capsEnabled) {
                    root.keyPressed(modelData.alternativeUpperCaseKey ? modelData.alternativeUpperCaseKey : modelData.text.toUpperCase());
                    capsEnabled = false;
                } else {
                    // Otherwise, send the regular key text
                    root.keyPressed(modelData.text);
                }
                return;
            }
        }

        onPressed: {
            keyRect.color = modelData.pressedColor;
        }

        onReleased: {
            keyRect.color = modelData.color;
        }
    }

    Component.onCompleted: {
        keyRect.color = modelData.color;
    }

    Component.onDestruction: {
        console.log("Key Component Destroyed:", modelData.text);
    }
}
