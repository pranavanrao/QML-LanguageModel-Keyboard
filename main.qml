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
            height: parent.height*0.18
            color: "#00000000"

            anchors.topMargin: 2

            TextInput {
                id: inputField
                width: parent.width
                height: parent.height
                color: "#FFFFFF"
                focus: true
                font.pixelSize: inputField.height*0.6
                font.weight: Font.DemiBold
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
            height: parent.height*0.8

            onKeyPressed: {
                inputField.text += key
            }
        }
    }
}
