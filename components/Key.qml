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

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log("Key Text : ", modelData.text)

            switch (modelData.text) {
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

            default:
                console.log("No action defined for key:", modelData.text);
                return; // Exit if no matching case
            }

            // Update rows after changing the layer
            firstRowModel.model = keyboard.parseKeyboardKeysRow1();
            secondRowModel.model = keyboard.parseKeyboardKeysRow2();
            thirdRowModel.model = keyboard.parseKeyboardKeysRow3();
            fourthRowModel.model = keyboard.parseKeyboardKeysRow4();
        }

        onPressed: {
            keyRect.color = modelData.pressedColor;
        }

        onReleased: {
            keyRect.color = modelData.color;
        }
    }
}
