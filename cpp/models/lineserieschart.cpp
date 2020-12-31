#include "lineserieschart.h"

LineSeriesChart::LineSeriesChart(QQuickItem *parent) : QQuickPaintedItem(parent)
{
    setFlag(QQuickItem::ItemHasContents, true);
    setAcceptedMouseButtons(Qt::AllButtons);

    connect(this, &QQuickPaintedItem::widthChanged, this, &LineSeriesChart::updatePlotSize);
    connect(this, &QQuickPaintedItem::heightChanged, this, &LineSeriesChart::updatePlotSize);
    connect(this,&LineSeriesChart::backgroundColorChanged,this,&LineSeriesChart::onBackgroundColorChanged);
    connect(this,&LineSeriesChart::colorChanged,this,&LineSeriesChart::onColorChanged);

    m_qwtPlot = new QwtPlot();

    m_curve = new QwtPlotCurve("Line");
}

void LineSeriesChart::paint(QPainter *painter)
{
    if(m_qwtPlot)
    {
        QPixmap picture(boundingRect().size().toSize());
        QwtPlotRenderer renderer;
        renderer.renderTo(m_qwtPlot, picture);
        painter->drawPixmap(QPoint(), picture);
    }
}

void LineSeriesChart::init(qreal min,qreal max,qreal step,QObject * qmlInterface)
{
    m_qmlInterface=qobject_cast<QmlInterface *>(qmlInterface);

    connect(m_qmlInterface->getSerialPortInterface(),&SerialPortInterface::chartDataRecieved,this,&LineSeriesChart::onChartDataRecieved);

    m_qwtPlot->plotLayout()->setAlignCanvasToScales( true );

    m_qwtPlot->setAutoReplot(false);

    m_qwtPlot->setStyleSheet("background: "+m_background_color);

    m_qwtPlot->enableAxis(QwtPlot::yLeft,true);

    m_qwtPlot->enableAxis(QwtPlot::xBottom,true);

    m_qwtPlot->setAxisScale(QwtPlot::yLeft,min,max,step);

    m_qwtPlot->setAxisScale(QwtPlot::xBottom,0,10,1);

    updatePlotSize();

    m_curve->setPen(QPen(QColor(m_color)));

    m_curve->setStyle(QwtPlotCurve::Lines);

    m_curve->setRenderHint(QwtPlotItem::RenderAntialiased);

    m_curve->setData(new LineSeriesChartPlotData(&m_points));

    m_qwtPlot->setAxisTitle(m_qwtPlot->xBottom,tr("Time (sec)"));

    m_qwtPlot->setAxisTitle(m_qwtPlot->yLeft,"");

    QwtScaleWidget * qwtsw = m_qwtPlot->axisWidget(QwtPlot::xBottom);


    QPalette palette = qwtsw->palette();

    palette.setColor( QPalette::WindowText, Qt::gray);

    palette.setColor( QPalette::Text, Qt::gray);

    qwtsw->setPalette(palette);

    qwtsw = m_qwtPlot->axisWidget(QwtPlot::yLeft);

    palette = qwtsw->palette();

    palette.setColor( QPalette::WindowText, Qt::gray);

    palette.setColor( QPalette::Text, Qt::gray);

    qwtsw->setPalette(palette);

    m_curve->attach(m_qwtPlot);

    replotAndUpdate();
}

void LineSeriesChart::updatePlotSize()
{
    if(m_qwtPlot)
    {
        m_qwtPlot->setGeometry(0, 0, static_cast<int>(width()), static_cast<int>(height()));
    }
}

void LineSeriesChart::onBackgroundColorChanged(const QString &backgroundColor)
{
    m_curve->setPen(QPen(QColor(m_color)));

    QwtScaleWidget * qwtsw = m_qwtPlot->axisWidget(QwtPlot::xBottom);

    QPalette palette = qwtsw->palette();

    palette.setColor( QPalette::WindowText, Qt::gray);

    palette.setColor( QPalette::Text, Qt::gray);

    qwtsw->setPalette(palette);

    qwtsw = m_qwtPlot->axisWidget(QwtPlot::yLeft);

    palette = qwtsw->palette();

    palette.setColor( QPalette::WindowText, Qt::gray);

    palette.setColor( QPalette::Text, Qt::gray);

    qwtsw->setPalette(palette);

    m_qwtPlot->setStyleSheet("background: "+backgroundColor);

    m_qwtPlot->replot();
}

void LineSeriesChart::onColorChanged(const QString & color)
{
    m_curve->setPen(QPen(QColor(color)));
}

void LineSeriesChart::onChartDataRecieved(QString type,QString data)
{
    if(m_qwtPlot && m_curve && (type==m_type))
    {
        qreal yPoint = data.toFloat();

        int count = m_points.count();

        double x=m_points.count();

        x/=10;

        if(count<101)
        {
            m_points.append(QPointF(x,yPoint));
        }
        else
        {
            m_points.clear();

            m_points.append(QPointF(0,yPoint));
        }

        replotAndUpdate();
    }
}

void LineSeriesChart::replotAndUpdate()
{
    if(m_qwtPlot)
    {
        m_qwtPlot->replot();

        update();
    }
}
