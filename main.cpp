#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec *utfcodec = QTextCodec::codecForName("CP-1251");
    QTextCodec::setCodecForTr(utfcodec);
    QTextCodec::setCodecForCStrings(utfcodec);
    QTextCodec::setCodecForLocale(utfcodec);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
