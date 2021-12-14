import QtQuick 2.13
import QtQuick.Window 2.13

Window {
    // set window id.
    id: id_window

    // set window size.
    width: 640
    height: 480

    // set window is visible.
    visible: true

    // set window title.
    title: qsTr("Wheel Animation")

    // set window color.
    color: "#9cffe0"

    // set property.
    property int rotationStep: 45

    // append wheel image.
    Image {
        // set image id.
        id: id_wheel

        // set image pos.
//        anchors.centerIn: parent
        x:0
        y:10

        // set image source.
        source: "/images/wheel.png"

        // set image behavior.
        Behavior on rotation {
            NumberAnimation {
                // 1 behavior = 250 ms
                duration: 250
            }
        }
    }

    // append mouseArea.
    MouseArea {
        anchors.fill: parent
        onPressed: {
            // get mouse press pos x & y.
            var posX = mouseX
            var posY = mouseY

            console.log(posX)
            console.log(posY)

            // why dont move ...?.
            id_wheel.x = posX - id_wheel.width / 2.0
            id_wheel.y = posY - id_wheel.height / 2.0
        }
    }

    // append item.
    Item {
        // set item pos.
        anchors.fill: parent

        // set item is focus.
        focus: true

        // set item left key presse event.
        Keys.onLeftPressed: {
            id_wheel.rotation -= rotationStep
        }
        // set item right key presse event.
        Keys.onRightPressed: {
            id_wheel.rotation += rotationStep
        }
    }
}
