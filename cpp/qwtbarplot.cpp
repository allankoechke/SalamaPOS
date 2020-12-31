#include "qwtbarplotdata.h"
#include "qwtbarplot.h"

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_renderer.h>

#include <QDebug>

QwtBarPlot::QwtBarPlot(QQuickItem* parent) : QQuickPaintedItem(parent)
    , m_qwtPlot(nullptr), m_timerId(0)
{
    setFlag(QQuickItem::ItemHasContents, true);
    setAcceptedMouseButtons(Qt::AllButtons);

    connect(this, &QQuickPaintedItem::widthChanged, this, &QwtBarPlot::updatePlotSize);
    connect(this, &QQuickPaintedItem::heightChanged, this, &QwtBarPlot::updatePlotSize);
}

QwtBarPlot::~QwtBarPlot()
{
    delete m_qwtPlot;
    m_qwtPlot = nullptr;
    delete m_curve1;

    if (m_timerId != 0) {
        killTimer(m_timerId);
    }
}

void QwtBarPlot::replotAndUpdate()
{
    m_qwtPlot->replot();
    update();
}

void QwtBarPlot::initQwtPlot()
{
    m_qwtPlot = new QwtPlot();
    // after replot() we need to call update() - so disable auto replot
    m_qwtPlot->setAutoReplot(false);
    QString _style = "background: \""+m_backgroundColor+"\"; color: \""+m_foregroundColor+"\"";
    m_qwtPlot->setStyleSheet(_style);

    updatePlotSize();

    m_curve1 = new QwtPlotCurve("Curve 1");

    m_curve1->setPen(QPen(Qt::red));
    m_curve1->setStyle(QwtPlotCurve::Lines);
    m_curve1->setRenderHint(QwtPlotItem::RenderAntialiased);

    m_curve1->setData(new QwtBarPlotData(&m_curve1_data));

    m_qwtPlot->setAxisTitle(m_qwtPlot->xBottom, tr("t"));
    m_qwtPlot->setAxisTitle(m_qwtPlot->yLeft, tr("S"));

    m_curve1->attach(m_qwtPlot);

    startTimer(500);

    replotAndUpdate();
}


void QwtBarPlot::paint(QPainter* painter)
{
    if (m_qwtPlot) {
        QPixmap picture(boundingRect().size().toSize());

        QwtPlotRenderer renderer;
        renderer.renderTo(m_qwtPlot, picture);

        painter->drawPixmap(QPoint(), picture);
    }
}

void QwtBarPlot::mousePressEvent(QMouseEvent* event)
{
    qDebug() << Q_FUNC_INFO;
    routeMouseEvents(event);
}

void QwtBarPlot::mouseReleaseEvent(QMouseEvent* event)
{
    qDebug() << Q_FUNC_INFO;
    routeMouseEvents(event);
}

void QwtBarPlot::mouseMoveEvent(QMouseEvent* event)
{
    routeMouseEvents(event);
}

void QwtBarPlot::mouseDoubleClickEvent(QMouseEvent* event)
{
    qDebug() << Q_FUNC_INFO;
    routeMouseEvents(event);
}

void QwtBarPlot::wheelEvent(QWheelEvent* event)
{
    routeWheelEvents(event);
}

void QwtBarPlot::timerEvent(QTimerEvent* /*event*/)
{
    static double t, U;
    U = (static_cast<double>(qrand()) / RAND_MAX) * 5;

    m_curve1_data.append(QPointF(t, U));

    // qDebug() << Q_FUNC_INFO << QString("Adding dot t = %1, S = %2").arg(t).arg(U);
    t++;
    replotAndUpdate();
}

void QwtBarPlot::routeMouseEvents(QMouseEvent* event)
{
    if (m_qwtPlot) {
        QMouseEvent* newEvent = new QMouseEvent(event->type(), event->localPos(),
                                                event->button(), event->buttons(),
                                                event->modifiers());
        QCoreApplication::postEvent(m_qwtPlot, newEvent);
    }
}

void QwtBarPlot::routeWheelEvents(QWheelEvent* event)
{
    if (m_qwtPlot) {
        QWheelEvent* newEvent = new QWheelEvent(event->pos(), event->delta(),
                                                event->buttons(), event->modifiers(),
                                                event->orientation());
        QCoreApplication::postEvent(m_qwtPlot, newEvent);
    }
}

void QwtBarPlot::updatePlotSize()
{
    if (m_qwtPlot) {
        m_qwtPlot->setGeometry(0, 0, static_cast<int>(width()), static_cast<int>(height()));
    }
}
