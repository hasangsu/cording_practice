import QtQuick 2.13
import QtQuick.Window 2.13

// import qt widgets lib.
import QtQuick.Controls 2.12

// import qt layouts lib.
import QtQuick.Layouts 1.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    RowLayout
    {
        ColumnLayout
        {
            // set id.
            id : id_editor_columLayout

            // set layout options.
//            anchors.fill : parent

            Button
            {
                // set id.
                id : id_input_editor

                // set text.
                text : "Input"

                // set on click event.
                onClicked:
                {
                    qml_reader.setSource("qProductInput.qml")
                }
            }

            Button
            {
                // set id.
                id : id_run_editor

                // set text.
                text : "Run"

                // set on click event.
                onClicked:
                {
                    qml_reader.setSource("qProductRun.qml")
                }
            }
        }

        ColumnLayout
        {
            // set id
            id : id_mainView_columnLayout

            Loader
            {
                id : qml_reader
                source : "QProductInput.qml"
            }
        }
    }
}
