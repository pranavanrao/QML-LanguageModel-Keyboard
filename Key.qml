import QtQuick 2.12

Rectangle {
    property string keyName

    width: 50
    height: 50
    color: "aqua"

    Text {
        id: key
        text: keyName
    }
}
