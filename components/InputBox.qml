import QtQuick 2.15

Item {
    id: inputComp
    property string inputText

    Row {
        spacing: 2
        anchors.fill: parent
        anchors.margins: parent.height*0.1

        Text {
            id: inputTitle
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
            text: inputText
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
