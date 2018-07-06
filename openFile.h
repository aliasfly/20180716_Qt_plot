#ifndef OPENFILE_H
#define OPENFILE_H
#include <QObject>
#include "dataPlot.h"
#include <QAbstractAxis>
#include <QScatterSeries>
#include <QXYSeries>
#include <QStringList>
QT_CHARTS_USE_NAMESPACE
class OpenFile : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName)
    Q_PROPERTY(int sumNum READ sumNum)
    Q_PROPERTY(float avgNum READ avgNum)
    Q_PROPERTY(int maxNum READ maxNum)
    Q_PROPERTY(int minNum READ minNum)

    Q_PROPERTY(QAbstractAxis* axisX READ axisX WRITE setAxisX)
    Q_PROPERTY(QAbstractAxis* axisY READ axisY WRITE setAxisY)

    Q_PROPERTY(int xMaxValue READ xMaxValue)
    Q_PROPERTY(int xMinValue READ xMinValue)
    Q_PROPERTY(int yMaxValue READ yMaxValue)
    Q_PROPERTY(int yMinValue READ yMinValue)

public:
    OpenFile(QObject *parent = 0);
    ~OpenFile();

    QString fileName() const { return _fileName; }
    void setFileName(const QString& fileName);
    void setFilePath(const QString& filePath);

    int sumNum() const {return _sumNum;}
    float avgNum() const {return _avgNum;}
    int maxNum() const {return _maxNum;}
    int minNum() const {return _minNum;}

    QAbstractAxis* axisX() const { return _axisX; }
    QAbstractAxis* axisY() const { return _axisY; }

    void setAxisX(QAbstractAxis* axisX);
    void setAxisY(QAbstractAxis* axisY);

    int xMaxValue() const { return _xMaxValue; }
    int xMinValue() const { return _xMinValue; }
    int yMaxValue() const { return _yMaxValue; }
    int yMinValue() const { return _yMinValue; }

    QVector<QPointF> getDataSource();

signals:
    void filechanged();

public slots:
    void ProduceRange();
    void ReadFile();
    void writeXML();
    void changefile();

    void calculateSumNum();
    void calculateAvgNum();
    void calculateMaxNum();
    void calculateMinNum();

    void seriesAdded(QAbstractSeries* series);
private:
    QString _fileName;
    QString _filePath;
    int _sumNum;
    float _avgNum;
    int _maxNum;
    int _minNum;

    QAbstractAxis*   _axisX;
    QAbstractAxis*   _axisY;
    static quint64 _xMaxValue;
    static quint64 _xMinValue;
    static double _yMaxValue;
    static double _yMinValue;
};

#endif // OPENFILE_H
