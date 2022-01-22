import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: id_rectangle

    property string m_ButtonDisplayText: "Default Text"
    property int m_topMargin: 10
    property int m_leftMargin: 10
    property int m_rightMargin: 10
    property int m_minTemperature: 0
    property int m_maxTemperature: 0

    BaseButton {
        id: id_baseButton

        // set text rectangle position.
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

        // set text rectangle size.
        width: parent.width
        height: parent.height / 6.0

        m_displayText: m_ButtonDisplayText
    }

    Rectangle {
        id: id_insideRectangle

        // set rectangle color.
        border.color: "black"

        // set rectangle position.
        anchors.top: id_baseButton.bottom
        anchors.bottom: parent.bottom

        // set rectangle size.
        width: parent.width
        height: id_baseButton.height * 5

        Rectangle {
            id: id_top
            color: "transparent"
            border.color: "transparent"
            width: id_insideRectangle.width / 6
            height: id_insideRectangle.height / 5
            Text {
                id: id_text_top
                text: qsTr("강")
                font.bold: true

                anchors.centerIn: parent
            }

            anchors.top: id_insideRectangle.top
        }

        Rectangle {
            id: id_middle
            color: "transparent"
            border.color: "transparent"
            width: id_insideRectangle.width / 6
            height: id_insideRectangle.height / 5
            Text {
                id: id_text_middle
                text: qsTr("중")
                font.bold: true

                anchors.centerIn: parent
            }

            anchors.verticalCenter: id_insideRectangle.verticalCenter
        }

        Rectangle {
            id: id_bottom
            color: "transparent"
            border.color: "transparent"
            width: id_insideRectangle.width / 6
            height: id_insideRectangle.height / 5
            Text {
                id: id_text_bottom
                text: qsTr("약")
                font.bold: true

                anchors.centerIn: parent
            }

            anchors.bottom: id_insideRectangle.bottom
        }

        Slider {
            // set slider id.
            id: id_slider

            // set slider min value.
            from: m_minTemperature

            // set slider max value.
            to: m_maxTemperature

            // set slider step value.
            stepSize: 1

            // set slider default value.
            value: 0

            // set slider orientation.
            orientation: Qt.Vertical

            // set slider size.
            width: id_insideRectangle.width / 5
            height: parent.height - 20

            // set slider position.
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.left: id_top.right

            // set slider value changed event.
            onValueChanged: {
                var middle_temperature = (m_maxTemperature - m_minTemperature) / 2;
                var max_2_middle_middle_temperature = (m_maxTemperature - middle_temperature) / 2;

                if (m_maxTemperature <= m_minTemperature)
                {
                    if (middle_temperature + max_2_middle_middle_temperature <= value)
                    {
                        // set power temperature.
                        id_ice_image.visible = false
                    }
                    else
                        id_ice_image.visible = true
                }
                else
                {
                    if (middle_temperature + max_2_middle_middle_temperature <= value)
                    {
                        // set power temperature.
                        id_ice_image.visible = true
                    }
                    else
                        id_ice_image.visible = false
                }


            }
        }

        Rectangle {
            id: id_ice_button
            color: "transparent"
            border.color: "transparent"

            anchors.leftMargin: m_leftMargin
            anchors.rightMargin: m_rightMargin
            anchors.topMargin: m_topMargin
            anchors.left: id_slider.right
            anchors.top: id_insideRectangle.top

            width: id_insideRectangle.width - id_top.width - id_slider.width - m_leftMargin - m_rightMargin
            height: (id_insideRectangle.height / 5) - (anchors.topMargin * 2)

            Image {
                id: id_ice_image

                // set image path.
                source: "qrc:/image/ice.png"

                // set image size.
                width: parent.width
                height: parent.height

                // set image position.
                anchors.centerIn: parent

                // set image visible.
                visible: false
            }
        }

        Rectangle {
            id: id_temperature
            border.color: "transparent"

            anchors.leftMargin: m_leftMargin
            anchors.rightMargin: m_rightMargin
            anchors.topMargin: m_topMargin
            anchors.left: id_slider.right
            anchors.top: id_ice_button.bottom

            width: id_ice_button.width
            height: (id_insideRectangle.height - m_topMargin * 2) - m_topMargin - id_ice_button.height

            Text {
                id: id_temperature_text
                text: qsTr(id_slider.value + " °C")

                anchors.centerIn: parent
            }
        }
    }
}


