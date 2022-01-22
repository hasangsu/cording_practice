import QtQuick 2.0
import QtQuick.Shapes 1.0

Rectangle {
    id: id_rectangle

    Shape {
        id: id_shape

        anchors.fill: parent

        ShapePath {
            id: id_shape_path
            strokeColor: "blue"

            property real xr: 10
            property real yr: 10
            startX: id_shape.width / 2
            startY: id_shape.height / 4
            PathArc {
                x: id_shape_path.startX
                y: id_shape_path.startY -100
                radiusX: 10; radiusY: 1
                useLargeArc: true
            }

        }
    }
}
