import QtQuick 2.7
import QtQuick.Window 2.2
import Models 1.0
import Controler 1.0

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    WormModel {
        id: wormModel
    }

    WormControler {
        id: wormCtrl
        model: wormModel;
    }

    Item {
        id: controler
        focus: true

        property int pos: 700

        Keys.onPressed: {
            wormCtrl.keyPressed(event.key);
        }
    }

    // Wurm
    Repeater {
        id: worm
        model: wormModel

        Rectangle {
            x: pointX
            y: pointY
            width: 10
            height: 10
            radius: 5
            color: "orange"
            border.color: "red"
        }
    }

}
