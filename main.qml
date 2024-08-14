import QtQuick 2.15
import QtQuick.Window 2.12

import "./components"

Window {
    width: 600
    height: 300
    visible: true
    title: qsTr("Virtual Keyboard")

    color: "#000000"

    KeyBoard {}
}
