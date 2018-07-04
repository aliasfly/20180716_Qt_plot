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

OpenFile::OpenFile(QObject *parent)
    :QObject(parent)
    ,_sumNum(0)
    ,_avgNum(0)
    ,_maxNum(0)
    ,_minNum(0)
{

}

OpenFile::~OpenFile()
{

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
