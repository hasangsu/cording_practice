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
    GridLayout
    {
        // row layout's display options.
        anchors.fill: parent
        columns: 2
        rows: 2

        // append text (QLineEdit).
        TextInput {
            id: textInput
            text : "af"

            // set text layout options.
            Layout.alignment: Qt.AlignCenter
            Layout.column: 0
            Layout.row: 0
            Layout.columnSpan: 2
        }
        // append button.
        Button {

            // set button widget id.
            id : ok_button

            // set button widget display text.
            text : "Ok"

            // set button options.
            Layout.alignment: Qt.AlignCenter
            Layout.column: 0
            Layout.row: 1;

            // set button click event.
            onClicked: {

                // if button click is quit.
                Qt.quit()
            }
        }
        Button {
            id : cancel_button
            text : "Cancel"

            Layout.alignment: Qt.AlignCenter
            Layout.column: 1
            Layout.row: 1;
        }
    }
}
