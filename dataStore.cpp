#include "dataStore.h"
#include <QDebug>

double DataStore::_xMinValue=0;
double DataStore::_xMaxValue=40;
double DataStore::_yMaxValue = 500;
double DataStore::_yMinValue = 0;

DataStore::DataStore(QObject *parent)
    :QObject(parent)
    ,AAA_currentstr(1)
    ,BBB_currentstr(2)
    ,CCC_currentstr(3)
{

}

DataStore::~DataStore()
{

}

void DataStore::getstr(int a)
{
    AAA_currentstr=a;
    qDebug()<<"AAA_currentstr="<<AAA_currentstr;
}

int DataStore::str() const
{
    return AAA_currentstr;
}
void DataStore::setStr(const int &str)
{
    AAA_currentstr=str;
    emit strChanged(AAA_currentstr);
}

int DataStore::str2() const
{
    return BBB_currentstr;
}
void DataStore::setStr2(const int &str2)
{
    BBB_currentstr=str2;
    emit str2Changed(BBB_currentstr);
}

int DataStore::str3() const
{
    return CCC_currentstr;
}
void DataStore::setStr3(const int &str3)
{
    CCC_currentstr=str3;
    emit str3Changed(CCC_currentstr);
}

void DataStore::seriesAdded()
{
    bool yrangeChange = false;
    DataPlot* dataPlot;
    if(dataPlot->minValue() < DataStore::_yMinValue) {
        DataStore::_yMinValue = dataPlot->minValue();
        yrangeChange = true;
    }
    if(dataPlot->maxValue() > DataStore::_yMaxValue) {
        DataStore::_yMaxValue = dataPlot->maxValue();
        yrangeChange = true;
    }
//    if(yrangeChange)
//        _axisY->setRange(DataStore::_yMinValue,DataStore::_yMaxValue);
}
