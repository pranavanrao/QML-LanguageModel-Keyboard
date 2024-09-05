import QtQuick 2.15
import QtQuick.Controls 2.15

Popup {
    id: togglebtn
    width: contentWidth
    height: contentHeight

    z: 1000
    y: -60

    property string filename: "components/ToggleKey.qml"

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
        anchors.fill: parent
        spacing: 2
        Repeater {
            model: keyboard.parseAltKeyForKey(currentText)

            delegate: Rectangle {
                width: 50
                height: 50
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
                    cursorShape: Qt.PointingHandCursor
                    onClicked: {
                        root.keyPressed(modelData.alternativeKeys)
                        togglebtn.visible = false;
                    }
                    onEntered: console.log(filename, " Alt keys : ", modelData.alternativeKeys)
                }
            }
        }
    }

    onVisibleChanged: {
        if (togglebtn.visible) {
            backgroundRect.color = "black"

            if (keyIndex >= 4 && keyIndex <= 6) {
                togglebtn.x = -60
            }

            if (keyIndex > 6) {
                togglebtn.x = -180
            }
        }
    }
}
