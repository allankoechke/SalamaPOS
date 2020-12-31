#include "lineserieschartplotdata.h"

LineSeriesChartPlotData::LineSeriesChartPlotData(const QVector<QPointF> *container) :
    _container(container)
{
}

size_t LineSeriesChartPlotData::size() const
{
    return static_cast<size_t>(_container->size());
}

QPointF LineSeriesChartPlotData::sample(size_t i) const
{
    return _container->at(static_cast<int>(i));
}

QRectF LineSeriesChartPlotData::boundingRect() const
{
    return qwtBoundingRect(*this);
}

