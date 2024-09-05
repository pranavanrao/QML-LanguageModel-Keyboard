import QtQuick 2.15
import QtQuick.Controls 2.15

Popup {
    id: togglebtn
    width: contentWidth
    height: contentHeight

    y: -(keyRect.height*0.5)
    z: 1000

    property string filename: "components/ToggleKey.qml"
    property string toggleIndex: index
    property int modelSize: contentRowRepeater.count

    Rectangle {
        id: backgroundRect
        anchors.fill: parent
        color: "black"
        radius: 10
        border.color: "white"
        border.width: 2
    }

    Row {
        id: contentRow
        anchors.centerIn: parent
        width: contentWidth
        height: contentHeight
        spacing: 2
        Repeater {
            id: contentRowRepeater
            model: keyboard.parseAltKeyForKey(currentText)

            delegate: Rectangle {
                id: toggleRect
                width: keyRect.width * 0.8
                height: keyRect.height * 0.8
                color: modelData.pressedColor
                radius: 10
                Text {
                    anchors.centerIn: parent
                    text: modelData.alternativeKeys.toString()
                    color: "white"
                    font.pixelSize: 20
                }

                MouseArea {
                    anchors.fill: parent

                    onClicked: {
                        root.keyPressed(modelData.alternativeKeys)
                        togglebtn.visible = false;
                        console.log("Toggle Key Index : ", index);
                    }

                    onEntered: console.log(filename, " Alt keys : ", modelData.alternativeKeys)

                    onPressed: {
                        toggleRect.color = modelData.color;
                    }

                    onReleased: {
                        toggleRect.color = modelData.pressedColor;
                    }
                }
            }
        }
    }

    onVisibleChanged: {
        if (togglebtn.visible) {
            backgroundRect.color = "black"

            if (keyIndex > 6) {
                togglebtn.x = -(keyRect.height * (modelSize-1))
            }
        }
    }
}
