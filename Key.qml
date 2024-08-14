import QtQuick 2.15

Rectangle {
    width: modelData.width
    height: modelData.height
    color: modelData.color
    radius: 5

    Text {
        anchors.centerIn: parent
        text: modelData.text
        font.pixelSize: 24
        color: "white"
    }

    MouseArea {
        anchors.fill: parent
        onClicked: console.log("Key Text : ", modelData.text)
    }
}
