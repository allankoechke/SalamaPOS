import QtQuick 2.0
import QtCharts 2.3
// import QwtCharts 1.0

Item {
    id: root
    anchors.fill: parent
    anchors.margins: 1

    ChartView {
        id: chartV
        title: "Weekly Sales Summary"
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        antialiasing: true
        titleColor: QmlInterface.isDarkTheme? "#f4f4f4":"#535353"
        backgroundColor: QmlInterface.isDarkTheme? "#29292d":"white"
        legend.alignment: Qt.AlignBottom
        legend.color: QmlInterface.isDarkTheme? "#f4f4f4":"#535353"

        BarSeries {
            id: myBarSeries
            axisY: ValueAxis {
                min: 0; max: QmlInterface.plotYmax;
                labelsColor: QmlInterface.isDarkTheme? "#f4f4f4":"#535353"
                labelFormat: "%.0f"
                labelsFont:Qt.font({pixelSize: 10})
            }
            axisX: BarCategoryAxis {
                categories: QmlInterface.plotXAxis;
                labelsColor: QmlInterface.isDarkTheme? "#f4f4f4":"#535353"
                labelsFont:Qt.font({pixelSize: 11})
            }

            BarSet
            {
                id: cashBar
                label: "Cash";
                labelColor: QmlInterface.isDarkTheme? "#f4f4f4":"#535353";
                values: [];
                color: "#00bfff"
            }

            BarSet
            {
                label: "M-Pesa";
                labelColor: QmlInterface.isDarkTheme? "#f4f4f4":"#535353";
                values: [];
                color: "#a0522d"
            }

            BarSet
            {
                label: "Cheque";
                labelColor: QmlInterface.isDarkTheme? "#f4f4f4":"#535353";
                values: [];
                color: "#dc143c"
            }

            BarSet
            {
                label: "Credit";
                labelColor: QmlInterface.isDarkTheme? "#f4f4f4":"#535353";
                values: [];
                color: "#d2691e"
            }
        }

    }

    Connections
    {
        target: QmlInterface

        function onDataReadyForPlotting()
        {
            // console.log("New plot values");

            let csh = [], mpsa=[], cr=[], chq=[];

            for(var i=0; i<7; i++)
            {
                csh[i] = QmlInterface.cashYAxis[i]
                mpsa[i]= QmlInterface.mpesaYAxis[i]
                cr[i] = QmlInterface.creditYAxis[i]
                chq[i] = QmlInterface.chequeYAxis[i]
            }

            myBarSeries.clear();
            myBarSeries.append("Cash", csh)
            myBarSeries.append("M-Pesa", mpsa)
            myBarSeries.append("Credit", cr)
            myBarSeries.append("Cheque", chq)
        }

        function onCashYAxisChanged(cashYAxis)
        {
        }

        function onMpesaYAxisChanged(mpesaYAxis)
        {
        }

        function onCreditYAxisChanged(creditYAxis)
        {
        }

        function onChequeYAxisChanged(chequeYAxis)
        {
        }
    }
}
