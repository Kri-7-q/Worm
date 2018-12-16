import QtQuick 2.0

Component {
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
