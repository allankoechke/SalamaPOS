#ifndef LINESERIESCHART_H
#define LINESERIESCHART_H

#include <QQuickPaintedItem>
#include <QObject>
#include <QQmlContext>
#include <QtDebug>

#include <qwt_plot.h>
#include <qwt_plot_renderer.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_layout.h>
#include <qwt_scale_widget.h>

#include "lineserieschartplotdata.h"
#include "qmlinterface.h"


class LineSeriesChart : public QQuickPaintedItem
{
    Q_OBJECT
public:
    explicit LineSeriesChart(QQuickItem *parent = nullptr);

    Q_PROPERTY(QString backgroundColor MEMBER m_background_color NOTIFY backgroundColorChanged)

    Q_PROPERTY(QString color MEMBER m_color NOTIFY colorChanged)

    Q_PROPERTY(QString type MEMBER m_type)

    void paint(QPainter* painter);

    Q_INVOKABLE void init(qreal min, qreal max, qreal step, QObject *qmlInterface);

signals:
    void backgroundColorChanged(const QString & backgroundColor);

    void colorChanged(const QString & color);

private slots:
    void updatePlotSize();

    void onBackgroundColorChanged(const QString & backgroundColor);

    void onColorChanged(const QString & backgroundColor);

    void onChartDataRecieved(QString type, QString data);

private:
    QwtPlot* m_qwtPlot;
    QwtPlotCurve* m_curve;
    QVector<QPointF> m_points;
    QString m_background_color,m_color,m_type;
    QmlInterface * m_qmlInterface;

    void replotAndUpdate();
};

#endif // LINESERIESCHART_H
