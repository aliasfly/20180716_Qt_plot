#ifndef DATASTORE_H
#define DATASTORE_H
#include <QObject>
#include <QAbstractSeries>
#include <QAbstractAxis>
#include <QXYSeries>
#include <QChart>
#include "dataPlot.h"
QT_CHARTS_USE_NAMESPACE
class DataStore  : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int str READ str WRITE setStr NOTIFY strChanged)
    Q_PROPERTY(int str2 READ str2 WRITE setStr2 NOTIFY str2Changed)
    Q_PROPERTY(int str3 READ str3 WRITE setStr3 NOTIFY str3Changed)

    Q_PROPERTY(double xMaxValue READ xMaxValue CONSTANT)
    Q_PROPERTY(double xMinValue READ xMinValue CONSTANT)
    Q_PROPERTY(double yMaxValue READ yMaxValue CONSTANT)
    Q_PROPERTY(double yMinValue READ yMinValue CONSTANT)
public:
    DataStore(QObject *parent = 0);
    ~DataStore();



    double xMaxValue() const { return (double)_xMaxValue; }
    double xMinValue() const { return (double)_xMinValue; }
    double yMaxValue() const { return _yMaxValue; }
    double yMinValue() const { return _yMinValue; }

    int str() const;
    void setStr(const int &str);

    int str2() const;
    void setStr2(const int &str);

    int str3() const;
    void setStr3(const int &str);

signals:
    void strChanged(const int &str);
    void str2Changed(const int &str2);
    void str3Changed(const int &str3);
public slots:
    void getstr(int);
    void seriesAdded();
private:
    static double _xMaxValue;
    static double _xMinValue;
    static double _yMaxValue;
    static double _yMinValue;
    int AAA_currentstr;
    int BBB_currentstr;
    int CCC_currentstr;

};

#endif //DATASTORE_H
