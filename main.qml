import QtQuick 2.7
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Item {
        id: controler
        focus: true

        property int length: 20

        Keys.onPressed: {
            length += 10;
        }
    }

    // Wurm
    Repeater {
        id: worm
        model: controler.length

        Rectangle {
            x: 100 + index * 8
            y: 100
            width: 10
            height: 10
            radius: 5
            color: "orange"
            border.color: "red"
        }
    }
}
