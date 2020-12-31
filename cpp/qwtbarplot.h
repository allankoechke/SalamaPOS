#ifndef QWTBARPLOT_H
#define QWTBARPLOT_H

#include <QtQuick>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>

class QwtBarPlot : public QQuickPaintedItem
{
    Q_OBJECT

public:
    QwtBarPlot(QQuickItem* parent = nullptr);
    virtual ~QwtBarPlot();

    void paint(QPainter* painter);

    Q_INVOKABLE void initQwtPlot();

    Q_PROPERTY(QString backgroundColor MEMBER m_backgroundColor NOTIFY backgroundColorChanged)
    Q_PROPERTY(QString foregroundColor MEMBER m_foregroundColor NOTIFY foregroundColorChanged)

signals:
    void backgroundColorChanged(QString backgroundColor);
    void foregroundColorChanged(QString foregroundColor);

protected:
    void routeMouseEvents(QMouseEvent* event);
    void routeWheelEvents(QWheelEvent* event);

    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseDoubleClickEvent(QMouseEvent* event);
    virtual void wheelEvent(QWheelEvent *event);

    virtual void timerEvent(QTimerEvent *event);

private slots:
    void updatePlotSize();

private:
    QwtPlot*         m_qwtPlot;
    QwtPlotCurve*    m_curve1;
    QVector<QPointF> m_curve1_data;
    int              m_timerId;

    void replotAndUpdate();

    QString m_backgroundColor, m_foregroundColor;
};

#endif // QWTBARPLOT_H
