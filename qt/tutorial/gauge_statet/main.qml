import QtQuick 2.13
import QtQuick.Window 2.13

import QtQuick.Controls 1.4
import QtQuick.Extras 1.4

Window {
    width: 640
    height: 480
    visible: true

    // set window title.
    title: qsTr("Gauge State")

    // set window color.
    color: "black"

    // append gauge.
    Gauge {
        // set gauge id.
        id: id_gauge

        // set gauge init value.
        value: 0
        minimumValue: 0
        maximumValue: 100

        // set gauge size.
        height: parent.height

        // set gauge position.
        anchors.left: parent
        anchors.bottom: parent
    }

    // append rectangle.
    Rectangle {
        // set rectangle id.
        id: id_color_rectangle

        color: "black"

        // set rectangle size.
        width: parent.width - id_gauge.width
        height: parent.height * 0.7

        // set rectangle position.
        anchors.top: parent
        anchors.left: id_gauge.right
    }

    // append rectangle.
    Rectangle {
        // set rectange id.
        id: id_on_rectangle

        color: "blue"
        // set rectangle size.
        width: id_color_rectangle.width / 2.0
        height: parent.height - id_color_rectangle.height

        // set rectangle position.
        anchors.left: id_color_rectangle.left
        anchors.top: id_color_rectangle.bottom

        // append text.
        Text {
            // set text id.
            id: id_on_text

            // set text display text.
            text: qsTr("on")

            // set text font.
            font.bold: true
            font.pixelSize: 48

            // set text position.
            anchors.centerIn: parent
        }

        // append mouse area.
        MouseArea {
            // set mouse area position.
            anchors.fill: parent

            onClicked: {
                id_states_rectangle.state = "on"
            }
        }
    }

    // append rectangle.
    Rectangle {
        // set rectange id.
        id: id_off_rectangle

        color: "yellow"

        // set rectangle size.
        width: id_color_rectangle.width / 2.0
        height: parent.height - id_color_rectangle.height

        // set rectangle position.
        anchors.left: id_on_rectangle.right
        anchors.top: id_color_rectangle.bottom

        // append text.
        Text {
            // set text id.
            id: id_off_text

            // set text display text.
            text: qsTr("off")

            // set text font.
            font.bold: true
            font.pixelSize: 48

            // set text position.
            anchors.centerIn: parent
        }

        // append mouse area.
        MouseArea {
            // set mouse area position.
            anchors.fill: parent

            onClicked: {
                id_states_rectangle.state = "off"
            }
        }
    }

    // append rectangle.
    Rectangle {
        // set rectangle id.
        id: id_states_rectangle

        states: [
            State {
                name: "on"
                PropertyChanges {
                    target: id_color_rectangle
                    color: "red"
                }
                PropertyChanges {
                    target: id_gauge
                    value: 100
                }
            },
            State {
                name: "off"
                PropertyChanges {
                    target: id_color_rectangle
                    color: "black"
                }
                PropertyChanges {
                    target: id_gauge
                    value: 0
                }
            }
        ]

        state: "off"

        transitions: [
            Transition {
                from: "off"
                to: "on"
                PropertyAnimation {
                    target: id_color_rectangle
                    properties: "color"
                    duration: 10000 - (id_gauge.value * 100)
                }
                PropertyAnimation {
                    target: id_gauge
                    properties: "value"
                    duration: 10000 - (id_gauge.value * 100)
                }
            },
            Transition {
                from: "on"
                to: "off"
                PropertyAnimation {
                    target: id_color_rectangle
                    properties: "color"
                    duration: 10000 - ((100 - id_gauge.value) * 100)
                    }
                PropertyAnimation {
                    target: id_gauge
                    properties: "value"
                    duration: 10000 - ((100 - id_gauge.value) * 100)
                    }
            }
        ]
    }
}
