#include "Test02.h"
#include <QtWidgets/QApplication>
#include "Worker.h"
#include <stdlib.h>
#include "mythread.h"
#include <windows.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Test02 t;
    MyThread workerThread;
    Worker worker;
    worker.moveToThread(&workerThread);
    workerThread.start();
    qDebug() << "Main thread ID:" << QThread::currentThreadId();
    QMetaObject::invokeMethod(&worker, "doWork", Qt::QueuedConnection);
    Sleep(1000); 
    t.show();
    return a.exec();
}



