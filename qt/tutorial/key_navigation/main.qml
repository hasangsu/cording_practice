import QtQuick 2.13
import QtQuick.Window 2.13

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Key Navigation")

    property int rectangleCount: 4
    property int rectangleWidth: width / rectangleCount

    // append rectangle.
    Rectangle {
        // set rectangle id.
        id: id_rectangle1

        // set rectangle size.
        width: rectangleWidth
        height: parent.height

        // set rectangle position.
        anchors.top: parent

        // set rectange focus.
        focus: true

        // set rectangle color.
        color : "#cc0000"

        // set key navigation.
        KeyNavigation.left: id_rectangle4
        KeyNavigation.right: id_rectangle2

        // set on focus change event.
        onFocusChanged: {
            if (focus)
                id_rectangle1.color = "#cc0000"
            else
                id_rectangle1.color = "#f4cccc"
        }
    }

    Rectangle {
        // set rectangle id.
        id: id_rectangle2

        // set rectangle size.
        width: rectangleWidth
        height: parent.height

        // set rectangle position.
        anchors.top: parent
        anchors.left: id_rectangle1.right

        // set rectange focus.
        focus: false

        // set rectangle color.
        color : "#cfe2f3"

        // set key navigation.
        KeyNavigation.left: id_rectangle1
        KeyNavigation.right: id_rectangle3

        // set on focus change event.
        onFocusChanged: {
            if (focus)
                id_rectangle2.color = "#3d85c6"
            else
                id_rectangle2.color = "#cfe2f3"
        }
    }

    Rectangle {
        // set rectangle id.
        id: id_rectangle3

        // set rectangle size.
        width: rectangleWidth
        height: parent.height

        // set rectangle position.
        anchors.top: parent
        anchors.left: id_rectangle2.right

        // set rectange focus.
        focus: false

        // set rectangle color.
        color : "#fff2cc"

        // set key navigation.
        KeyNavigation.left: id_rectangle2
        KeyNavigation.right: id_rectangle4

        // set on focus change event.
        onFocusChanged: {
            if (focus)
                id_rectangle3.color = "#f1c232"
            else
                id_rectangle3.color = "#fff2cc"
        }
    }

    Rectangle {
        // set rectangle id.
        id: id_rectangle4

        // set rectangle size.
        width: rectangleWidth
        height: parent.height

        // set rectangle position.
        anchors.top: parent
        anchors.left: id_rectangle3.right

        // set rectange focus.
        focus: false

        // set rectangle color.
        color : "#d9ead3"

        // set key navigation.
        KeyNavigation.left: id_rectangle3
        KeyNavigation.right: id_rectangle1

        // set on focus change event.
        onFocusChanged: {
            if (focus)
                id_rectangle4.color = "#6aa84f"
            else
                id_rectangle4.color = "#d9ead3"
        }
    }
}
