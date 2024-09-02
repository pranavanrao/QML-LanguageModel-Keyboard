import QtQuick 2.15
import QtQuick.Controls 2.15

Popup {
    id: togglebtn
    z: 1000

    property string filename: "components/ToggleKey.qml"

    Row {
        anchors.fill: parent
        spacing: 2
        Repeater {
            model: keyboard.parseAltKeyForKey(currentText)

            delegate: Rectangle {
                width: 50
                height: 50
                color: "grey"
                Text {
                    anchors.centerIn: parent
                    text: modelData.alternativeKeys.toString()
                    color: "white"
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        root.keyPressed(modelData.alternativeKeys)
                        togglebtn.visible = false;
                    }
                    onEntered: console.log(filename, " Alt keys : ", modelData.alternativeKeys)
                }
            }
        }
    }
}
