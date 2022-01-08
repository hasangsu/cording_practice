import QtQuick 2.13
import QtQuick.Window 2.13

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Sampel Refrigerator")

    property int frezzerWidth: width * 0.3
    property int statusWidth: width * 0.1

    LeftFreezerButton {
        width : frezzerWidth
        height: parent.height

        id: id_left_freezer_button

        m_displayText: "냉동실 온도"
    }
    LeftFreezerButton {
        width : statusWidth
        height: parent.height

        anchors.left: id_left_freezer_button.right

        id: id_middle_status_button

        m_displayText: "NEO Fresh"
    }
    LeftFreezerButton {
        width : frezzerWidth
        height: parent.height

        anchors.left: id_middle_status_button.right

        id: id_right_freezer_button

        m_displayText: "냉장실 온도"
    }
    TouchPad {
        width : frezzerWidth
        height: parent.height

        anchors.left: id_right_freezer_button.right
    }
}
