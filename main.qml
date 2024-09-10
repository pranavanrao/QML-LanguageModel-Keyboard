import QtQuick 2.15
import QtQuick.Window 2.12

import "./components"

Window {
    width: 600
    height: 300
    visible: true
    title: qsTr("Virtual Keyboard")

    color: "#000000"

    InputBox {
        id: inputMain
        width: parent.width
        height: parent.height * 0.15
    }

    KeyBoard {
        width: parent.width
        anchors.bottom: parent.bottom

        onKeyPressed: {
            inputMain.inputText += key
        }
    }
}
