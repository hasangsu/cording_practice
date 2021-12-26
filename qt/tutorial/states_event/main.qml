import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 1.4

Window {
    id: id_window
    width: 640
    height: 480
    visible: true
    title: qsTr("States Event")

    property int halfWidth: width / 2.0;
    property int quaterHeight: height / 4.0;
    property int rotationStep: 10
    property int durationStep: 250

    function getDurationStep(value)
    {
        if (value <= 0)
            return 0
        else if (value == 100)
            return 1
        else
        {
            var tempDuration = (100 - value) * 10
            return tempDuration
        }

        return 0
    }

    function initSlider(value)
    {
        id_slider.value = value
    }

    // append rectangle.
    Rectangle {
        // set rectangle id.
        id: id_background

        // set rectangle size.
        width : parent.width
        height: quaterHeight * 3;

        // set rectangle color.
        color: "black"

        // append image.
        Image {
            // set image id.
            id: id_image_wheel

            // set immage source.
            source: "/images/wheel"

            // set image position.
            anchors.centerIn: id_background

            // set image behavior.
            Behavior on rotation {
                NumberAnimation {
                    id : id_image_number_animation

                    // 1 behavior = 250 ms
                    duration: durationStep
                }
            }
        }

        // append slider.
        Slider {
            // set slider id.
            id: id_slider

            // set slider size.
            width : id_background.width / 6.0
            height : id_background.height / 2

            // set slider position.
            anchors.verticalCenter: id_background.verticalCenter

            // set slider min & max.
            value: 0
            minimumValue: 0
            maximumValue: 100
            stepSize: 1

            // set slider orientation.
            orientation: Qt.Vertical

            onValueChanged: {
                // chagne image duration.
                durationStep = getDurationStep(id_slider.value)
                if (durationStep <= 0)
                {
                    id_state.state = "off"
                    return
                }

                id_state.state = "on"
            }
        }
    }

    // append rectangle.
    Rectangle {
        // set rectangle id.
        id: id_on

        // set rectangle size.
        width : halfWidth
        height: quaterHeight

        // set rectangle position.
        anchors.top: id_background.bottom
        anchors.bottom: parent

        // set rectangle color.
        color: "yellow"

        // append text.
        Text {
            // set text id.
            id: id_on_text

            // set text display text.
            text: qsTr("On")
            font.bold: true
            font.pixelSize: 48

            // set text position.
            anchors.centerIn: id_on
        }

        // append mouse area.
        MouseArea {
            // set mouse area id.
            id: id_on_mousearea

            // set mouse area size.
            anchors.fill: id_on

            // set mouse area click event.
            onClicked: {
                if (id_slider.value <= 0)
                {
                    // set init slider.
                    initSlider(75)
                }
                else
                    initSlider(id_slider.value)
            }
        }
    }

    // append rectangle.
    Rectangle {
        // set rectangle id.
        id: id_off

        // set rectangle size.
        width : halfWidth
        height: quaterHeight

        // set rectangle position.
        anchors.top: id_background.bottom
        anchors.left: id_on.right

        // set rectangle color.
        color: "red"

        // append text.
        Text {
            // set text id.
            id: id_off_text

            // set text display text.
            text: qsTr("Off")
            font.bold: true
            font.pixelSize: 48

            // set text position.
            anchors.centerIn: id_off
        }

        // append mouse area.
        MouseArea {
            // set mouse area id.
            id: id_off_mousearea

            // set mouse area size.
            anchors.fill: id_off

            // set mouse area click event.
            // set mouse area click event.
            onClicked: {
                // set init slider.
                initSlider(0)
            }
        }
    }

    // append rectangle.
    Rectangle {
        // set rectange id.
        id: id_state

        // append states.
        states: [
            State {
                name: "on"
                PropertyChanges {
                    target: id_image_number_animation
                    duration: durationStep
                }
                PropertyChanges {
                    target: id_image_wheel
                    rotation: rotation + rotationStep
                }
            },
            State {
                name: "off"
                PropertyChanges {
                    target: id_image_number_animation
                    duration: 0
                }
                PropertyChanges {
                    target: id_image_wheel
                    rotation: id_image_wheel.rotation
                }
            },
            State {
                name: "none"
            }
        ]

        state: "none"
    }


}
