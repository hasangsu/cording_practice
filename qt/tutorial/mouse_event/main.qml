import QtQuick 2.13
import QtQuick.Window 2.13

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML Mouse Event")



    Rectangle {
        // set rectangle width.
        width: parent.width

        // set rectangle height.
        height: parent.height

        // set rectangle color.
        color: "#B7D6BE"

        // set key press event.
        focus: true
        Keys.onPressed: {
            if (event.key == Qt.Key_R)
            {
                // rest text display text.
                id_text.text = qsTr("QML Mouse Event")
            }
        }

        // append text.
        Text {
            // set text id.
            id: id_text

            // set text default display text.
            text: qsTr("QML Mouse Event")

            // set text horizontal position.
            anchors.horizontalCenter: parent.horizontalCenter

            // set text vertical position.
            anchors.verticalCenter: parent.verticalCenter

            // set text font size.
            font.pixelSize: 48

            // append mouse area.
            MouseArea {
                // set mouse area id.
                id: id_mouse_area

                // set mouse area position.
                anchors.fill: parent

                // mouse area mouse press event.
                onPressed: {
                    id_text.text = qsTr("QML Mouse Pressed")
                }
                // mouse area mouse release event.
                onReleased: {
                    id_text.text = qsTr("QML Mouse Release")
                }
                // mouse area mouse wheel event.
                onWheel: {
                    id_text.text = qsTr("QML Mouse Wheel")
                }

            }
        }
    }
}
