import QtQuick 2.0
import QtCharts 2.3

Item {
    anchors.fill: parent
    anchors.margins: 1

    Component.onCompleted: {
        var date = new Date()
    }

    property var cash_x: [0,0,0,0,0,0,10]

    ChartView {
        title: "Weekly Sales Summary"
        anchors.fill: parent
        antialiasing: true
        titleColor: QmlInterface.isDarkTheme? "#f4f4f4":"#535353"
        backgroundColor: QmlInterface.isDarkTheme? "#29292d":"white"
        // legend.visible: false
        legend.alignment: Qt.AlignBottom

        BarSeries {
            id: myBarSeries
            axisY: ValueAxis {min: 0; max: QmlInterface.plotYmax }
            axisX: BarCategoryAxis { categories: QmlInterface.plotXAxis }

            BarSet { label: "Cash"; values: [] }
            BarSet { label: "M-Pesa"; values: [] }
            BarSet { label: "Cheque"; values: [] }
            BarSet { label: "Credit"; values: [] }
        }

    }

    Connections
    {
        target: QmlInterface

        function onCashYAxisChanged(cashYAxis)
        {
            for(var j=0; j<myBarSeries.count; j++)
            {
                // console.log("> ", myBarSeries.at(j).label)
                if(myBarSeries.at(j).label === "Cash")
                {
                    myBarSeries.remove(myBarSeries.at(j));
                    break;
                }
            }

            let arr = []

            for(var i=0; i<cashYAxis.length; i++)
                arr[i] = cashYAxis[i]

            myBarSeries.append("Cash", arr)

        }

        function onMpesaYAxisChanged(mpesaYAxis)
        {
            for(var j=0; j<myBarSeries.count; j++)
            {
                if(myBarSeries.at(j).label === "M-Pesa")
                {
                    myBarSeries.remove(myBarSeries.at(j));
                    break;
                }
            }

            let arr1 = []

            for(var i=0; i<mpesaYAxis.length; i++)
                arr1[i] = mpesaYAxis[i]

            myBarSeries.append("M-Pesa", arr1)
        }

        function onCreditYAxisChanged(creditYAxis)
        {
            for(var j=0; j<myBarSeries.count; j++)
            {
                if(myBarSeries.at(j).label === "Credit")
                {
                    myBarSeries.remove(myBarSeries.at(j));
                    break;
                }
            }

            let arr2 = []

            for(var i=0; i<7; i++)
                arr2[i] = creditYAxis[i]

            myBarSeries.append("Credit", arr2)
        }

        function onChequeYAxisChanged(chequeYAxis)
        {
            for(var j=0; j<myBarSeries.count; j++)
            {
                if(myBarSeries.at(j).label === "Credit")
                {
                    myBarSeries.remove(myBarSeries.at(j));
                    break;
                }
            }

            let arr3 = []

            for(var i=0; i<chequeYAxis.length; i++)
                arr3[i] = chequeYAxis[i]

            myBarSeries.append("Credit", arr3)
        }
    }
}
