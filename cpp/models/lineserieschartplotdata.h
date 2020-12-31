#ifndef LINESERIESCHARTPLOTDATA_H
#define LINESERIESCHARTPLOTDATA_H

#include <QPointF>
#include <QVector>
#include <qwt_series_data.h>

class LineSeriesChartPlotData : public QwtSeriesData<QPointF>
{
public:
    LineSeriesChartPlotData(const QVector<QPointF> *container);
private:
      const QVector<QPointF>* _container;
public:
      size_t size() const;
      QPointF sample(size_t i) const;
      QRectF boundingRect() const;
};

#endif // LINESERIESCHARTPLOTDATA_H
