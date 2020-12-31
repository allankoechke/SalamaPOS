#include "qwtbarplotdata.h"

QwtBarPlotData::QwtBarPlotData(const QVector<QPointF> *container) :
    _container(container)
{
}

size_t QwtBarPlotData::size() const
{
    return static_cast<size_t>(_container->size());
}

QPointF QwtBarPlotData::sample(size_t i) const
{
    return _container->at(static_cast<int>(i));
}

QRectF QwtBarPlotData::boundingRect() const
{
    return qwtBoundingRect(*this);
}
