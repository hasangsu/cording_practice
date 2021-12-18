import QtQuick 2.0

Rectangle {
    // set rectangle id.
    id: id_rectangle

    // set rectangle color.
    color: "yellow"

    // append text.
    Text {
        // set text id.
        id: id_text

        // set text display text.
        text: qsTr("Loader Source Change\nload2 qml")

        // set text font information.
        font.bold: true
        font.pixelSize: 30

        // set text position.
        anchors.centerIn: id_rectangle
    }
}
