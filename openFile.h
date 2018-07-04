#ifndef OPENFILE_H
#define OPENFILE_H
#include <QObject>
#include "dataPlot.h"

class OpenFile : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName)
    Q_PROPERTY(int sumNum READ sumNum)
    Q_PROPERTY(float avgNum READ avgNum)
    Q_PROPERTY(int maxNum READ maxNum)
    Q_PROPERTY(int minNum READ minNum)
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
};

#endif // OPENFILE_H
