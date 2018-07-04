#include <QApplication>
#include <QQuickView>
#include <QtQml>
#include "openFile.h"
#include "dataStore.h"
#include "dataPlot.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    qmlRegisterType<OpenFile>("OpenFile",1,0,"OpenFile");
    QQuickView viewer;

    QObject::connect(viewer.engine(), SIGNAL(quit()), &app, SLOT(quit()));//quit_use
    viewer.rootContext()->setContextProperty("openFile", new OpenFile);
    viewer.rootContext()->setContextProperty("dataStore", new DataStore);
    viewer.rootContext()->setContextProperty("dataPlot", new DataPlot);
    viewer.setSource(QUrl("qrc:///main.qml"));
    viewer.setResizeMode(QQuickView::SizeRootObjectToView);//default
    viewer.show();

    return app.exec();
}
