import QtQuick 2.13
import QtQuick.Window 2.13

// provides a QML type for generating user interfaces (buttons, etc.).
import QtQuick.Controls 2.13

// provides a QML type for generating user interfaces (layouts.).
import QtQuick.Layouts 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    // append row layout (row = 1, column = widget count).
    RowLayout
    {
        // row layout's display options.
        anchors.fill: parent

        // append button.
        Button {

            // set button widget id.
            id : ok_button

            // set button widget display text.
            text : "Ok"

            // set button align.
            Layout.alignment: Qt.AlignCenter

            // set button click event.
            onClicked: {

                // if button click is quit.
                Qt.quit()
            }
        }
        Button {
            id : cancel_button
            Layout.alignment: Qt.AlignCenter
            text : "Cancel"
        }
    }
}
