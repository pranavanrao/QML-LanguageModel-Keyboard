import QtQuick 2.15
import QtQuick.Window 2.12

import "./components"

Window {
    width: 600
    height: 300
    visible: true
    title: qsTr("Virtual Keyboard")

    color: "#000000"

    Column {
        anchors.fill: parent
        spacing: 2

        Rectangle {
            width: parent.width
            height: parent.height*0.2
            color: "#00000000"

            Row {
                spacing: 2
                anchors.fill: parent
                anchors.margins: parent.height*0.1

                Text {
                    id: inputText
                    text: "SSID : "
                    color: "#FFFFFF"
                    font.pixelSize: parent.height*0.6
                }

                TextInput {
                    id: inputField
                    width: parent.width*0.8
                    height: parent.height
                    color: "#FFFFFF"
                    focus: true
                    font.pixelSize: inputField.height*0.6
                    font.weight: Font.DemiBold
                    horizontalAlignment: Text.AlignRight
                    inputMethodHints: Qt.ImhRightToLeft
                }
            }

            Rectangle {
                width: parent.width
                height: 2
                color: "#FFFFFF"
                anchors.bottom: parent.bottom
                anchors.left: parent.left
            }
        }

        KeyBoard {
            width: parent.width
            height: parent.height*0.78

            onKeyPressed: {
                inputField.text += key
            }
        }
    }
}
