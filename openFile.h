#ifndef OPENFILE_H
#define OPENFILE_H
#include <QObject>
#include "dataPlot.h"
#include <QAbstractAxis>
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

public slots:
    void ProduceRange();
    void ReadFile();
    void writeXML();

    void calculateSumNum();
    void calculateAvgNum();
    void calculateMaxNum();
    void calculateMinNum();
private:
    QString _fileName;
    QString _filePath;
    int _sumNum;
    float _avgNum;
    int _maxNum;
    int _minNum;

    QAbstractAxis*   _axisX;
    QAbstractAxis*   _axisY;
};

#endif // OPENFILE_H
