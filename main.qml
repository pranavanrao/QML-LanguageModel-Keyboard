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

        InputBox {
            id: inputMain
            width: parent.width
            height: parent.height*0.2
        }

        KeyBoard {
            width: parent.width
            height: parent.height*0.78

            onKeyPressed: {
                inputMain.inputText += key
            }
        }
    }
}
