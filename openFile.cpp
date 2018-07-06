#include "openFile.h"
#include <QFile>
#include <QDebug>
#include <QByteArray>

//**********************
#include <QString>
#include <QXmlStreamWriter>
//**********************

#include <iostream>
#include <stdlib.h>
//********************************************************************
int tempNum,i,buff[100];
//********************************************************************
quint64 OpenFile::_xMaxValue = 30;
quint64 OpenFile::_xMinValue = 0;
double OpenFile::_yMaxValue = 100;
double OpenFile::_yMinValue = 0;
//********************************************************************

OpenFile::OpenFile(QObject *parent)
    :QObject(parent)
{
    QObject::connect(this,SIGNAL(filechanged()),this,SLOT(changefile()));
}

OpenFile::~OpenFile()
{

}

void OpenFile::seriesAdded(QAbstractSeries* series)
{
    qDebug()<<"void OpenFile::seriesAdded(QAbstractSeries* series)   Called";
    bool xrangeChange = false;
    bool yrangeChange = false;
    QXYSeries *xySeries = static_cast<QXYSeries *>(series);
    qDebug()<<"print _minNum="<<_minNum<<"_xMinValue="<<_xMinValue;
    if(_minNum<_xMinValue)
    {
        _xMinValue=_minNum;
        xrangeChange = true;
    }
    qDebug()<<"print _maxNum="<<_maxNum<<"_xMaxValue="<<_xMaxValue;
    if(_xMaxValue<_maxNum)
    {
        _xMaxValue=_maxNum;
        xrangeChange = true;
    }
    qDebug()<<"print _minNum="<<_minNum<<"_yMinValue="<<_yMinValue;
    if(_minNum<_yMinValue)
    {
        _yMinValue=_minNum;
        yrangeChange = true;
    }
    qDebug()<<"print _maxNum="<<_maxNum<<"_yMaxValue="<<_yMaxValue;
    if(_yMaxValue<_maxNum)
    {
        _yMaxValue=_maxNum;
        yrangeChange = true;
    }
    if(xrangeChange)
    {
        if(_yMaxValue == _yMinValue)
        {
            _yMaxValue++;
        }
        qDebug()<<"xrangeChange==true";
    }
    if(yrangeChange)
    {
        qDebug()<<"yrangeChange==true";
    }
    xySeries->replace(getDataSource());
}
QVector<QPointF> OpenFile::getDataSource()
{
    qDebug()<<"QVector<QPointF> OpenFile::getDataSource()  Called~~~~~~~~~~~~~~~~~";
    _datasource.clear();
    qDebug()<<"1111111111111111";
    for(int k = 0; k < 1; k++)
    {
        QVector<QPointF> points;
        _datasource.append(points);
        qDebug()<<"QVector<QPointF> points;    Enter!!!";
    }
    qDebug()<<"i======"<<i;
    qDebug()<<"buff[i]======"<<buff[i-1];
    for(int k=0;k<i;k++)
    {

        qDebug()<<"22222222222222222222";
        qDebug()<<"k======"<<k;
        _datasource[0].append(QPointF(k,buff[k]));
        qDebug()<<"_datasource[0].append(QPointF(k,buff[k]));-----------Called OK~~"<<_datasource.at(0);
    }
//*******************************************************************************************
//        _datasource[0].append(QPointF(1,20));
//        _datasource[0].append(QPointF(20,43));
//        _datasource[0].append(QPointF(40,64));
//        _datasource[0].append(QPointF(60,16));
//        _datasource[0].append(QPointF(80,86));
//        _datasource[0].append(QPointF(100,25));
//        _datasource[0].append(QPointF(120,97));
//        _datasource[0].append(QPointF(140,38));
//        _datasource[0].append(QPointF(160,186));
//        _datasource[0].append(QPointF(180,6));
//*******************************************************************************************
    qDebug()<<"_datasource.at(0)======="<<_datasource.at(0);
    return _datasource.at(0);
}

void OpenFile::setAxisX(QAbstractAxis *axisX)
{
    qDebug()<<"void OpenFile::setAxisX   Called";
    _axisX = axisX;
    _axisX->setRange(OpenFile::_xMinValue,OpenFile::_xMaxValue);
}

void OpenFile::setAxisY(QAbstractAxis *axisY)
{
    qDebug()<<"void OpenFile::setAxisY   Called";
    _axisY = axisY;
    _axisY->setRange(OpenFile::_yMinValue,OpenFile::_yMaxValue);
}

void OpenFile::calculateSumNum()
{
    _sumNum=0;
    for(int j=0;j<=i;j++)
    {
        _sumNum=_sumNum+buff[j];
    }
    qDebug()<<"_sumNum="<<_sumNum;
}
void OpenFile::calculateAvgNum()
{
    int j=0;
    float tmp=0;_avgNum=0;
    for(j=0;j<=i;j++)
    {
        tmp=tmp+buff[j];
    }
    _avgNum=tmp/(j+1)*1.0;
    qDebug()<<"_avgNum="<<_avgNum;
}
void OpenFile::calculateMaxNum()
{
    int maxTmp=0;
    maxTmp=buff[0];
    for(int j=0;j<i;j++)
    {
        if(maxTmp<=buff[j])
        {
            maxTmp=buff[j];
        }
    }
    _maxNum=maxTmp;
    qDebug()<<"_maxNum="<<_maxNum;
}
void OpenFile::calculateMinNum()
{
    int minTmp=0;
    minTmp=buff[0];
    for(int j=0;j<i;j++)
    {
        if(minTmp>=buff[j])
        {
            minTmp=buff[j];
        }
    }
    _minNum=minTmp;
    qDebug()<<"_minNum="<<_minNum;
    emit filechanged();
}

void OpenFile::ProduceRange()
{
    int a[10];
    for(int i=0;i<10;i++)
    {
       a[i]=rand()%20;
       qDebug()<<a[i]<<" ";
    }
}

void OpenFile::setFileName(const QString &fileName)
{
    QString fileName_t = fileName;
    qDebug()<<"setFileName called";
    fileName_t = fileName_t.replace("file://","");
    _fileName = fileName_t;
    setFilePath(_fileName);
    ReadFile();
}

void OpenFile::setFilePath(const QString &filePath)
{
    _filePath = filePath;
    qDebug()<<"setFilePath called";
}

void OpenFile::ReadFile()
{
    qint64 pos;
    QByteArray dat;
    tempNum=0;i=0;
    QFile file(_filePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug()<< file.fileName() << file.exists();
        qDebug()<<"file open failed!!!!!!!!!!!";
        return;
    }
    qDebug()<<"open file ok";
    qDebug()<< file.fileName() << file.exists();    
    pos = file.size();
    qDebug()<<"file.size="<<pos<<endl;
    while (!file.atEnd())
    {
        dat = file.read(512);
        qDebug()<<dat.data();
    }
    char* numData=dat.data();
    while(*numData)
    {
        if((*numData) ==',')
        {
            numData++;
        }
        else
        {
            tempNum = tempNum + (*numData)-'0';
            numData++;
            if((*numData) ==',')
            {
                numData++;
                buff[i]=tempNum;
                qDebug()<<"buff"<<"["<<i<<"]"<<"="<<buff[i];
                tempNum=0;
                i++;
            }
            else
            {
                tempNum=tempNum*10;
            }
        }
    }
}
void OpenFile::changefile()
{
    qDebug()<<"emit filechanged() called!!!!!";
}

void OpenFile::writeXML() {
    QString strFile("Blogs.xml");
    QFile file(strFile);
    if (!file.open(QFile::WriteOnly | QFile::Text)) { // 只写模式打开文件
        qDebug() << QString("Cannot write file %1(%2).").arg(strFile).arg(file.errorString());
        return;
    }

    QXmlStreamWriter writer(&file);
    // writer.setCodec("GBK");  // XML 编码
    writer.setAutoFormatting(true); // 自动格式化
    writer.writeStartDocument("1.0", true);  // 开始文档（XML 声明）
    writer.writeComment(QString::fromLocal8Bit("纯正开源之美，有趣、好玩、靠谱。。。"));  // 注释
    writer.writeProcessingInstruction("xml-stylesheet type=\"text/css\" href=\"style.css\"");  // 处理指令

    // DTD
    writer.writeDTD(QString::fromLocal8Bit("<!DOCTYPE Blogs [ <!ENTITY Copyright \"Copyright 2016《Qt实战一二三》\"> <!ELEMENT Blogs (Blog)> <!ELEMENT Blog (作者,主页,个人说明)> <!ELEMENT 作者     (#PCDATA)> <!ELEMENT 主页     (#PCDATA)> <!ELEMENT 个人说明  (#PCDATA)> ]>"));

    writer.writeStartElement("Blogs");  // 开始根元素 <Blogs>
    writer.writeAttribute("Version", "1.0");  // 属性

    writer.writeStartElement("Blog");  // 开始子元素 <Blog>
    writer.writeTextElement(QString::fromLocal8Bit("num"), QString::fromLocal8Bit("一去丶二三里"));
    writer.writeTextElement(QString::fromLocal8Bit("avg"), "http://blog.csdn.net/liang19890820");
    writer.writeTextElement(QString::fromLocal8Bit("max"), QString::fromLocal8Bit("青春不老，奋斗不止！"));
    writer.writeTextElement(QString::fromLocal8Bit("min"), QString::fromLocal8Bit("一去丶二三里"));
    writer.writeEntityReference("Copyright");
    writer.writeCDATA(QString::fromLocal8Bit("<Qt分享&&交流>368241647</Qt分享&&交流>"));
    writer.writeCharacters(">");
    writer.writeEmptyElement(QString::fromLocal8Bit("Empty"));  // 空元素
    writer.writeEndElement();  // 结束子元素 </Blog>

    writer.writeEndElement();  // 结束根元素 </Blogs>
    writer.writeEndDocument();  // 结束文档

    qDebug()<<"writeXML finished!!!!!";

    file.close();  // 关闭文件
}
