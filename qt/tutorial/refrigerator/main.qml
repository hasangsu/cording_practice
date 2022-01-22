import QtQuick 2.13
import QtQuick.Window 2.13

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Sampel Refrigerator")

    property int frezzerWidth: width * 0.45
    property int statusWidth: width * 0.1

    LeftFreezerButton {
        width : frezzerWidth
        height: parent.height

        id: id_left_freezer_button
        m_ButtonDisplayText: "냉동실 온도"
        m_minTemperature: 0
        m_maxTemperature: -30
    }
    LeftFreezerButton {
        width : statusWidth
        height: parent.height

        anchors.left: id_left_freezer_button.right

        id: id_middle_status_button

        m_ButtonDisplayText: "NEO Fresh"
    }
    LeftFreezerButton {
        width : frezzerWidth
        height: parent.height

        anchors.left: id_middle_status_button.right

        id: id_right_freezer_button

        m_ButtonDisplayText: "냉장실 온도"

        m_minTemperature: 0
        m_maxTemperature: 5
    }
//    TouchPad {
//        width : frezzerWidth
//        height: parent.height

//        anchors.left: id_right_freezer_button.right
//    }
}
