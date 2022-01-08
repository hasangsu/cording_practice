import QtQuick 2.0

Rectangle {
    id: id_rectangle



    Shape {
        width: 120
        height: 130
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        // multisample, decide based on your scene settings
        layer.enabled: true
        layer.samples: 4

        ShapePath {
            fillColor: "black"
            strokeColor: "darkBlue"
            strokeWidth: 20
            capStyle: ShapePath.FlatCap

            PathAngleArc {
                centerX: 65; centerY: 95
                radiusX: 45; radiusY: 45
                startAngle: -180
                sweepAngle: 180
            }
        }
    }

//    Canvas {
//        anchors.fill: parent
//        onPaint: {
//            var ctx = getContext("2d");
//            ctx.reset();

//            var centreX = width / 2;
//            var centreY = height / 2;

//            ctx.beginPath();
//            ctx.fillStyle = "black";
//            ctx.moveTo(centreX, centreY);
//            ctx.arc(centreX, centreY, width / 4, 0, Math.PI * 0.5, false);
//            ctx.lineTo(centreX, centreY);
//            ctx.fill();

//            ctx.beginPath();
//            ctx.fillStyle = "red";
//            ctx.moveTo(centreX, centreY);
//            ctx.arc(centreX, centreY, width / 4, Math.PI * 0.5, Math.PI * 2, false);
//            ctx.lineTo(centreX, centreY);
//            ctx.fill();
//        }
//    }
}
