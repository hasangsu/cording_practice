import QtQuick 2.13
import QtQuick.Window 2.13

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Loader")

    // append rectangle.
    Rectangle {
        // set rectangle id.
        id: id_rectangle1

        // set rectangle size.
        width: parent.width / 2
        height: parent.height / 2

        // set rectangle position.
        anchors.top: parent

        // set rectangle color.
        color: "blue"

        // append text.
        Text {
            // set text id.
            id: id_text1

            // set text display text.
            text: qsTr("Button 1")

            // set text font information.
            font.bold: true
            font.pixelSize: 48

            // set text position.
            anchors.centerIn: id_rectangle1
        }

        // append mouse area.
        MouseArea {
            // set mouse area id.
            id: id_mouseArea1

            // set mouse area size.
            anchors.fill: id_rectangle1

            onClicked: {
                id_loader.source = "/load1.qml"
            }
        }
    }

    // append rectangle.
    Rectangle {
        // set rectangle id.
        id: id_rectangle2

        // set rectangle size.
        width: parent.width / 2
        height: parent.height / 2

        // set rectangle position.
        anchors.top: id_rectangle1.bottom

        // set rectangle color.
        color: "yellow"

        // append text.
        Text {
            // set text id.
            id: id_text2

            // set text display text.
            text: qsTr("Button 2")

            // set text font information.
            font.bold: true
            font.pixelSize: 48

            // set text position.
            anchors.centerIn: id_rectangle2
        }

        // append mouse area.
        MouseArea {
            // set mouse area id.
            id: id_mouseArea2

            // set mouse area size.
            anchors.fill: id_rectangle2

            onClicked: {
                id_loader.source = "/load2.qml"
            }
        }
    }

    Rectangle {
        // append loader rectangle.
        id: id_loader_rectangle

        // set loader rectangle position.
        anchors.left: id_rectangle1.right

        // set loader rectangle size.
        width: parent.width / 2
        height: parent.height

        // append loader.
        Loader {
            // set loader id.
            id: id_loader

            // set loader position.
            anchors.fill: id_loader_rectangle
        }
    }
}
