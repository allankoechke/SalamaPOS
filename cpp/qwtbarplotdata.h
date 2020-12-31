#ifndef QWTBARPLOTDATA_H
#define QWTBARPLOTDATA_H

#include <QPointF>
#include <QVector>

#include <qwt_series_data.h>


class QwtBarPlotData : public QwtSeriesData<QPointF>
{
public:
    QwtBarPlotData(const QVector<QPointF> *container);

private:
      const QVector<QPointF>* _container;

public:
      size_t size() const;
      QPointF sample(size_t i) const;
      QRectF boundingRect() const;
};

#endif // QWTBARPLOTDATA_H
