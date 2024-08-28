import QtQuick 2.15

Rectangle {
    id: keyRect
    color: modelData.color
    radius: 10

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
        text: modelData.text
        visible: modelData.text !== undefined
        font.pixelSize: keyRect.height * 0.6
        font.weight: Font.DemiBold
        color: "white"
    }

    LanguageComboBox {
        id: langCombo
        width: parent.width
        height: parent.height
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
        }

        onClicked: {
            console.log("Key Text : ", modelData.text || modelData.key);

            switch (modelData.text || modelData.image) {
            case "?123":
                keyboard.setLayer("layer2"); // Change to Layer 2
                break;

            case "#+=":
                keyboard.setLayer("layer3"); // Change to Layer 3
                break;

            case "abc":
                keyboard.setLayer("layer1"); // Change to Layer 1
                break;

            case "123":
                keyboard.setLayer("layer2"); // Change to Layer 2
                break;

            case "space":
                root.keyPressed(" ");
                break;

            case "qrc:/images/back.png":
                if (inputMain.inputText.length > 0) {
                    inputMain.inputText = inputMain.inputText.substring(0, inputMain.inputText.length - 1);
                }
                break;

            default:
                root.keyPressed(modelData.text);
                return;
            }

            // Update rows after changing the layer
            loadAllRows();
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
