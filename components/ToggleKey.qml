import QtQuick 2.15
import QtQuick.Controls 2.15

ComboBox {
    id: togglebtn
    z: 1000
    anchors.bottom: keyRect.top

    Row {
        Repeater {
            model: keyboard.parseKeyboardKeysRow1()

            delegate: Rectangle {
                width: eval(modelData.width)/1.2
                height: eval(modelData.height)/1.2
                color: modelData.pressedColor
                Text {
                    anchors.centerIn: parent
                    text: modelData.text
                    color: "white"
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: togglebtn.visible = false;
                }
            }
        }
    }
}
