import QtQuick 2.13
import QtQuick.Window 2.13

// import qt widgets lib.
import QtQuick.Controls 2.12

// import qt layouts lib.
import QtQuick.Layouts 1.12

// import qt messagebox lib.
import QtQuick.Dialogs 1.1

Window {
    id: id_window
    width: 1280
    height: 720
    visible: true
    title: qsTr("Pos")

    // set font size.
    readonly property int fontSizeExtraSmall: Qt.application.font.pixelSize * 0.8
    readonly property int fontSizeMedium: Qt.application.font.pixelSize * 1.5
    readonly property int fontSizeLarge: Qt.application.font.pixelSize * 2
    readonly property int fontSizeExtraLarge: Qt.application.font.pixelSize * 5

    // append shortcut.
    Shortcut {
        sequence: "Ctrl+Q"
        onActivated: Qt.quit()
    }

    Frame {
        id: id_frame
        anchors.fill: parent
        anchors.margins: 90

        ColumnLayout {
            id : id_column_layout_1

            // append barcode label & text.
            RowLayout {
                id : id_row_layout_1

                Label {
                    id : id_product_barcode_label
                    text: qsTr("Barcode")
                }

                TextInput {
                    id : id_product_barcode_text
                }
            }

            // append name label & text.
            RowLayout {
                id : id_row_layout_2

                Label {
                    id : id_product_name_label
                    text: qsTr("Name")
                }

                TextInput {
                    id : id_product_name_text
                }
            }

            // append price label & text.
            RowLayout {
                id : id_row_layout_3

                Label {
                    id : id_product_price_label
                    text: qsTr("Price")
                }

                TextInput {
                    id : id_product_price_text
                    text : qsTr("0")
                    validator: RegExpValidator {regExp: /[0-9]+/}
                }
            }

            // append button container.
            Container {
                id : id_button_container_1

                Layout.fillWidth : false
                Layout.fillHeight : true

                ButtonGroup {
                    buttons : id_button_group_row_layout.children
                }

                contentItem: RowLayout {
                    id : id_button_group_row_layout
                    spacing : 3

                    Repeater {
                        model : id_button_container_1.contentModel
                    }
                }

                // append append button.
                Button {
                    id : id_append
                    text : qsTr("Append")
                    Layout.fillHeight : true

                    // set on click event.
                    onClicked :
                    {
                        var barcode = id_product_barcode_text.text
                        var name = id_product_name_text.text
                        var price = parseInt(id_product_price_text.text)

                        var result = productManager.appendProduct(barcode, name, price)
                        if (result)
                        {
                        }
                    }
                }

                // append reset button.
                Button {
                    id : id_reset
                    text : qsTr("Reset")
                    Layout.fillHeight : true

                    // set on click event.
                    onClicked :
                    {
                        // init text edit.
                        id_product_barcode_text.text = qsTr("")
                        id_product_name_text.text = qsTr("")
                        id_product_price_text.text = qsTr("")
                    }
                }
            }







            //                    Button {
            //                        id : id_run_editor
            //                        text: qsTr("Run Main")
            //                        checked: true
            //                        Layout.fillHeight: true

            //                        // set on click event.
            //                        onClicked:
            //                        {
            //                            id_qml_loader.setSource("qProductRun.qml")
            //                        }
            //                    }
            //                }
        }
    }
}


