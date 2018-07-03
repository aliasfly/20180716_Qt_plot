import QtQuick 2.2
import QtCharts 2.2
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.3
import DataStore 1.0

Rectangle {
    width: 640;
    height: 480;
    Text {                          //test to display
        id: txtLabel;
        anchors.centerIn: parent;
        font.pixelSize: 26;
        color: "red";
    }
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

            Button{                                            //OK
                id:openfile;
                anchors.top:outlineBorder.top;
                anchors.topMargin: 5;
                text:"open";
                anchors.left: outlineBorder.left;
                anchors.leftMargin: 5;
                onClicked: fileDialog.open();
            }

            FileDialog {                                       //OK
                id: fileDialog
                title: "Please choose a file"
                folder: shortcuts.home
                onAccepted: {
                    console.log("You chose: " + fileDialog.fileUrl);
                    openFile.fileName = fileDialog.fileUrl
                    console.log("read  OK!!!");
                }
                onRejected: {
                    console.log("Canceled")
                }
            }


            Button{                                     //OK
                id:rangemake;
                anchors.top:outlineBorder.top;
                anchors.topMargin: 5;
                text:"make";
                anchors.left: openfile.right;
                anchors.leftMargin: 5;
                onClicked:
                {
                   messageDialog.open();
                   inputWindow.visible=true;
                }
            }
            MessageDialog {                             //OK
                id: messageDialog;
                title: "range A-B";
                text: "enter number:";
                onAccepted: {
                    console.log("messageDialog.show up.");
                    //put handle function;or connected function;
                    openFile.ProduceRange();
                    dataPlot.produceXYvalue();
                }
                Component.onCompleted: visible = false
            }


            Button{                                    //OK
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

            Rectangle{                               //input window;
                id:inputWindow;
                visible: false;
                width: 300;
                height: 150;
                anchors.centerIn: outlineBorder;
                border.color: "#888888";
                border.width: 1.5;
                z:2;
                Button{                             //inputWindowOk;
                    id:inputWindowOk;
                    anchors.right:inputWindow.right;
                    anchors.rightMargin: 3;
                    anchors.bottom: inputWindow.bottom;
                    anchors.bottomMargin: 3;
                    text:"Ok"
                    onClicked: {

                    }
                }
                Button{                               //inputWindowCancel
                    id:inputWindowCancel;
                    anchors.right:inputWindowOk.left;
                    anchors.rightMargin: 2;
                    anchors.bottom: inputWindow.bottom;
                    anchors.bottomMargin: 3;
                    text:"Cancel"
                    onClicked: {
                        inputWindow.visible=false;
                    }
                }
                Text{                                //inputWindowLine1
                    id:inputWindowLine1;
                    text:"start_value:";
                    font.pixelSize: 24;
                    anchors.left:inputWindow.left;
                    anchors.leftMargin:6;
                    anchors.top: inputWindow.top;
                    anchors.topMargin: 6;
                    TextInput{
                        id:textInputLine1;
                        width: 100;
                        height: 50;
                        font.pixelSize: 24;
                        anchors.left:inputWindowLine1.right;
                        validator: IntValidator{top:20; bottom: 1;}
                        color: "red";
                        onAccepted: {
                            dataStore.getstr(text);
                        }
                    }
                }
                Text{                                //inputWindowLine2
                    id:inputWindowLine2;
                    text:"stop_value:";
                    font.pixelSize: 24;
                    anchors.left:inputWindow.left;
                    anchors.leftMargin:6;
                    anchors.top: inputWindowLine1.bottom;
                    anchors.topMargin: 6;
                    TextInput{
                        id:textInputLine2;
                        width: 100;
                        height: 50;
                        font.pixelSize: 24;
                        anchors.left:inputWindowLine2.right;
                        validator: IntValidator{top:30; bottom: 1;}
                        color: "red";
                    }
                }
                Text{                               //inputWindowLine3
                    id:inputWindowLine3;
                    text:"random_n:";
                    font.pixelSize: 24;
                    anchors.left:inputWindow.left;
                    anchors.leftMargin:6;
                    anchors.top: inputWindowLine2.bottom;
                    anchors.topMargin: 6;
                    TextInput{
                        id:textInputLine3;
                        width: 100;
                        height: 50;
                        font.pixelSize: 24;
                        anchors.left:inputWindowLine3.right;
                        validator: IntValidator{top:40; bottom: 1;}
                        color: "red";
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
                      animationOptions: ChartView.NoAnimation              //Animation is disabled in the chart
                      legend.visible: false                                         //Graphic title
                      anchors.fill: parent;
                      onSeriesAdded: DataStore.seriesAdded()

                      DataStore {
                            id:dataStore
                            axisX: axisX
                            axisY: axisY
//                            var myAxisX = chartView.axisX(lineSeries);
//                            var myAxisY = chartView.axisY(lineSeries);
//                            var scatter = chartView.createSeries(ChartView.SeriesTypeScatter, "scatter series", myAxisX, myAxisY);
                      }



                      DateTimeAxis {
                          id: axisX
                          titleFont.pointSize: 10
                          labelsFont.pointSize: 10
                      }

                      ValueAxis {
                          id: axisY
                          titleFont.pointSize: 10
                          labelsFont.pointSize: 10        //y zhou
                      }
                  }
            }

            Rectangle{
                id:rcnumid;
                width:135;
                height: 80;
                border.width: 1.5;
                border.color: "#888888";
                anchors.left:data_statistic.left;
                anchors.leftMargin: 15;
                anchors.top:data_statistic.top;
                anchors.topMargin: 5;
                Text{
                    id: numid;
                    anchors.left: rcnumid.left;
                    anchors.leftMargin: 5;
                    text: "num:";
                    font.pixelSize: 20;
                }
            }

            Rectangle{
                id:rcavgid;
                width:135;
                height: 80;
                border.width: 1.5;
                border.color: "#888888";
                anchors.left:rcnumid.right;
                anchors.leftMargin: 5;
                anchors.top:data_statistic.top;
                anchors.topMargin: 5;
                Text{
                    id: avgid;
                    anchors.left: rcavgid.left;
                    anchors.leftMargin: 5;
                    text:"avg:";
                    font.pixelSize: 20;
                }

            }

            Rectangle{
                id:rcmaxid;
                width:135;
                height: 80;
                border.width: 1.5;
                border.color: "#888888";
                anchors.left:rcavgid.right;
                anchors.leftMargin: 5;
                anchors.top:data_statistic.top;
                anchors.topMargin: 5;
                Text{
                    id: maxid;
                    anchors.left: rcmaxid.left;
                    anchors.leftMargin: 5;
                    text: "max:";
                    font.pixelSize: 20;
                }
            }

            Rectangle{
                id:rcminid;
                width:135;
                height: 80;
                border.width: 1.5;
                border.color: "#888888";
                anchors.left:rcmaxid.right;
                anchors.leftMargin: 5;
                anchors.top:data_statistic.top;
                anchors.topMargin: 5;
                Text{
                    id: minid;
                    anchors.left: rcminid.left;
                    anchors.leftMargin: 5;
                    text: "min:";
                    font.pixelSize: 20;
                }
            }
        }
Connections{
    target:dataPlot;
    onXvalueChanged:{
//        xypoint.x=xvalue;
//        console.debug("qmlxypoint.x=",xypoint.x);
    }
}
Connections{
    target:dataPlot;
    onYvalueChanged:{
//        xypoint.y=yvalue;
//        console.debug("qmlxypoint.y=",xypoint.y);
    }
}


Connections{
    target: dataStore;
    onStrChanged:{
        textInputLine1.text=str;
    }
}
Connections{
    target: dataStore;
    onStr2Changed:{
        textInputLine2.validator=str2;
    }
}
Connections{
    target: dataStore;
    onStr3Changed:{
        textInputLine3.validator=str3;
    }
}
}

