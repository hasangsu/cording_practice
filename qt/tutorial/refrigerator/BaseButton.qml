import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.12

Rectangle {
    // member display text.
    property alias m_displayText: id_text.text

    // set rectangle id.
    id: id_rectangle

    // set rectangle color.
    border.color: "black"

    // append text rectangle.
    Rectangle {
        // set text rectangle id.
        id: id_text_rectangle

        // set text rectangle position.
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        // set text rectangle size.
        width: parent.width
        height: parent.height

        // set text rectangle color.
        border.color: "black"
        color: "yellow"

        // append text.
        Text {
            // set text id.
            id: id_text

            // set text display text.
            font.bold: true
            fontSizeMode: Text.Fit

            // set text color.
            color: "black"

            // set text position.
            anchors.centerIn: id_text_rectangle
        }
    }
}

