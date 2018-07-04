import QtQuick 2.2
import QtCharts 2.2
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.3
import OpenFile 1.0

Rectangle {
    width: 640;
    height: 480;
    Rectangle{
            id:outlineBorder;
            width: 600;
            height: 450;
            anchors.top:parent.top;
            anchors.topMargin: 15;
            anchors.left: parent.left;
            anchors.leftMargin: 20;
            border.width: 1.5;
            border.color: "#888888";
            Button{
                id:openfile;
                anchors.top:outlineBorder.top;
                anchors.topMargin: 5;
                text:"open";
                anchors.left: outlineBorder.left;
                anchors.leftMargin: 5;
                onClicked: fileDialog.open();
            }
            FileDialog {
                id: fileDialog
                title: "Please choose a file"
                folder: shortcuts.home
                onAccepted: {
                    console.log("You chose: " + fileDialog.fileUrl);
                    openFile.fileName = fileDialog.fileUrl
                    console.log("read  OK!!!");

                    openFile.calculateSumNum();
                    openFile.calculateAvgNum();
                    openFile.calculateMaxNum();
                    openFile.calculateMinNum();

                    sum.text="sum: " + openFile.sumNum;
                    avg.text="avg: " + openFile.avgNum;
                    max.text="max: " + openFile.maxNum;
                    min.text="min: " + openFile.minNum;
                }
                onRejected: {
                    console.log("Canceled")
                }
            }
            Button{
                id:rangemake;
                anchors.top:outlineBorder.top;
                anchors.topMargin: 5;
                text:"make";
                anchors.left: openfile.right;
                anchors.leftMargin: 5;
                onClicked:
                {
                   inputWindow.visible=true;
                }
            }
            Button{
                id:xmlout;
                anchors.top:outlineBorder.top;
                anchors.topMargin: 5;
                text:"export"
                anchors.left: rangemake.right;
                anchors.leftMargin: 5;
                onClicked:{
                    console.log("writeXML start");
                    openFile.writeXML();
                    console.log("writeXML end");
                }
            }
            Rectangle{
                id:inputWindow;
                visible: false;
                width: 300;
                height: 150;
                anchors.centerIn: outlineBorder;
                border.color: "#888888";
                border.width: 1.5;
                z:2;
                Text {
                    id:inputWindowText
                    text: "please enter 3 number"
                    font.pixelSize: 20
                    color: "red"
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Button{
                    id:inputWindowOk;
                    anchors.right:inputWindow.right;
                    anchors.rightMargin: 3;
                    anchors.bottom: inputWindow.bottom;
                    anchors.bottomMargin: 3;
                    text:"Ok"
                    onClicked: {
                        inputWindow.visible=false
//                        console.log("messageDialog.show up.");
//                        //put handle function;or connected function;
//                        openFile.ProduceRange();
//                        dataPlot.produceXYvalue();
                    }
                }
                Button{
                    id:inputWindowCancel;
                    anchors.right:inputWindowOk.left;
                    anchors.rightMargin: 2;
                    anchors.bottom: inputWindow.bottom;
                    anchors.bottomMargin: 3;
                    text:"Cancel"
                    onClicked: {
                        inputWindow.visible=false
                    }
                }
                Text{
                    id:inputWindowLine1;
                    text:"start_value:";
                    font.pixelSize: 20;
                    anchors.left:inputWindow.left;
                    anchors.leftMargin:6;
                    anchors.top: inputWindowText.bottom;
                    anchors.topMargin: 2;
                    TextInput{
                        id:textInputLine1;
                        width: 100;
                        height: 50;
                        font.pixelSize: 20;
                        anchors.left:inputWindowLine1.right;
                        validator: IntValidator{top:20; bottom: 1;}
                        color: "red";
                        onAccepted: {
                            dataStore.getstr(text);
                        }
                    }
                }
                Text{
                    id:inputWindowLine2;
                    text:"stop_value:";
                    font.pixelSize: 20;
                    anchors.left:inputWindow.left;
                    anchors.leftMargin:6;
                    anchors.top: inputWindowLine1.bottom;
                    anchors.topMargin: 2;
                    TextInput{
                        id:textInputLine2;
                        width: 100;
                        height: 50;
                        font.pixelSize: 20;
                        anchors.left:inputWindowLine2.right;
                        validator: IntValidator{top:30; bottom: 1;}
                        color: "red";
                    }
                }
                Text{
                    id:inputWindowLine3;
                    text:"  random_n:";
                    font.pixelSize: 20;
                    anchors.left:inputWindow.left;
                    anchors.leftMargin:6;
                    anchors.top: inputWindowLine2.bottom;
                    anchors.topMargin: 2;
                    TextInput{
                        id:textInputLine3;
                        width: 100;
                        height: 50;
                        font.pixelSize: 20;
                        anchors.left:inputWindowLine3.right;
                        validator: IntValidator{top:40; bottom: 1;}
                        color: "red";
                    }
                }
            }
            Rectangle{
                id:chartplot;
                width: 590;
                height: 300;
                anchors.left: outlineBorder.left;
                anchors.leftMargin: 5;
                anchors.bottom:data_statistic.top;
                anchors.bottomMargin: 5;
                border.width: 1.5;
                border.color: "#888888";
                ChartView {
                      id: chartView
                      legend.visible: true
                      anchors.fill: parent;
                      title: "file_data_statistic"
                      backgroundColor: Qt.rgba(1,0,0,1)
                      OpenFile {
                        id:openChart
                        axisX:axisX
                        axisY:axisY
                      }
                      Connections{
                          target: openFile
                          onFilechanged: {
                              chartView.backgroundColor=Qt.rgba(0,0,0,1)
                          }
                      }
                      DateTimeAxis {
                          id: axisX
                          titleFont.pointSize: 10
                          labelsFont.pointSize: 10
                      }

                      ValueAxis {
                          id: axisY
                          titleFont.pointSize: 10
                          labelsFont.pointSize: 10
                      }
                  }
            }
            Rectangle{
                id:data_statistic;
                width: 590;
                height: 90;
                anchors.bottom: outlineBorder.bottom;
                anchors.bottomMargin: 5;
                anchors.left: outlineBorder.left;
                anchors.leftMargin: 5;
                border.width: 1.5;
                border.color:"#888888";
                Text{
                    id: sum;
                    width: 100
                    anchors.verticalCenter: data_statistic.verticalCenter
                    anchors.left:parent.left
                    anchors.leftMargin: 10
                    text: "sum: "+0;
                    font.pixelSize: 30;
                    color: Qt.rgba(1,0,0,1)
                }
                Text{
                    id: avg;
                    width: 160
                    anchors.verticalCenter: data_statistic.verticalCenter
                    anchors.left:sum.right
                    anchors.leftMargin: 60
                    text:"avg: "+0;
                    font.pixelSize: 30;
                    color: Qt.rgba(0,0.5,0,1)
                }
                Text{
                    id: max;
                    width: 140
                    anchors.verticalCenter: data_statistic.verticalCenter
                    anchors.left:avg.right
                    anchors.leftMargin: 25
                    text: "max: "+0;
                    font.pixelSize: 30;
                    color: Qt.rgba(0,0,0.5,1)
                }
                Text{
                    id: min;
                    width: 100
                    anchors.verticalCenter: data_statistic.verticalCenter
                    anchors.left:max.right
                    anchors.leftMargin: 1
                    text: "min: "+0;
                    font.pixelSize: 30;
                    color: Qt.rgba(1,0.5,0,1)
                }
            }
        }

}

