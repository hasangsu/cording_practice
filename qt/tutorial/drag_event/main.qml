import QtQuick 2.13
import QtQuick.Window 2.13

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Drag Event")

    // append rectangle.
    Rectangle {
        // set rectangle id.
        id: id_rectangle

        // set rectangle pos.
        x: 0
        y: 0

        // set rectangle size.
        width: 50
        height: 50

        // set rectangle color.
        color : "#B7D6BE"

        // set rectangle drag event.
        Drag.active: id_mouseArea.drag.active

        // append text.
        Text {
            // set text id.
            id: id_text

            // set text display text.
            text: qsTr(parent.x + "x" + parent.y)

            // set text pos.
            anchors.centerIn: parent
        }

        // set mouse area.
        MouseArea {
            // set mouse area id.
            id: id_mouseArea

            // set mouse area size.
            anchors.fill: parent

            // set mouse area drag target.
            drag.target: parent
        }
    }
}
