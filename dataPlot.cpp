#include "dataPlot.h"
#include <QDebug>

DataPlot::DataPlot(QObject *parent)
    :QObject(parent)
    ,_xvalue(0)
    ,_yvalue(0)
{

}

DataPlot::~DataPlot()
{

}

int DataPlot::xvalue() const
{
    return _xvalue;
}
void DataPlot::setXvalue(const int &xvalue)
{
        _xvalue=xvalue;
        emit xvalueChanged(_xvalue);
        qDebug()<<"_xvalue="<<_xvalue;
}

int DataPlot::yvalue() const
{
    return _yvalue;
}
void DataPlot::setYvalue(const int &yvalue)
{
    _yvalue=yvalue;
    emit yvalueChanged(_yvalue);
    qDebug()<<"_yvalue="<<_yvalue;
}



void DataPlot::produceXYvalue()
{
    for(int i=1;i<11;i++)
    {
        DataPlot::setXvalue(i);
        DataPlot::setYvalue(i*2);
    }
}
