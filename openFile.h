#ifndef OPENFILE_H
#define OPENFILE_H
#include <QObject>
#include "dataPlot.h"

class OpenFile : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString fileName READ fileName WRITE setFileName)
public:
    OpenFile(QObject *parent = 0);
    ~OpenFile();

    QString fileName() const { return _fileName; }
    void setFileName(const QString& fileName);
    void setFilePath(const QString& filePath);

public slots:
    void ProduceRange();
    void ReadFile();
    void writeXML();
private:
    QString _fileName;
    QString _filePath;
};

#endif // OPENFILE_H
