import QtQuick 2.0
import QtCharts 2.3

Item {
    anchors.fill: parent
    anchors.margins: 5

    Component.onCompleted: {
        var date = new Date()
    }

    ChartView {
         title: "Spline"
         anchors.fill: parent
         antialiasing: true

         ValueAxis
         {
             id: yAxis
             tickCount: 31
             min: 0
             max: 200
         }

         SplineSeries {
             name: "SplineSeries"
             XYPoint { x: 0; y: 34 }
             XYPoint { x: 1; y: 77 }
             XYPoint { x: 2; y: 42 }
             XYPoint { x: 3; y: 2 }
             XYPoint { x: 4; y: 100 }
             XYPoint { x: 5; y: 23 }
             XYPoint { x: 6; y: 55 }
             XYPoint { x: 7; y: 34 }
             XYPoint { x: 8; y: 32 }
             XYPoint { x: 9; y: 67 }
             XYPoint { x: 10; y: 77}

             XYPoint { x: 11; y: 77 }
             XYPoint { x: 12; y: 42 }
             XYPoint { x: 13; y: 29 }
             XYPoint { x: 14; y: 93 }
             XYPoint { x: 15; y: 0 }
             XYPoint { x: 16; y: 55 }
             XYPoint { x: 17; y: 34 }
             XYPoint { x: 18; y: 32 }
             XYPoint { x: 19; y: 67 }
             XYPoint { x: 20; y: 35}

             XYPoint { x: 21; y: 77 }
             XYPoint { x: 22; y: 42 }
             XYPoint { x: 23; y: 2 }
             XYPoint { x: 24; y: 0 }
             XYPoint { x: 25; y: 23 }
             XYPoint { x: 26; y: 55 }
             XYPoint { x: 27; y: 10 }
             XYPoint { x: 28; y: 32 }
             XYPoint { x: 29; y: 67 }
             XYPoint { x: 30; y: 77}
         }
     }
}
