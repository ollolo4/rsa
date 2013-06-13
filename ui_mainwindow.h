/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 13. Jun 06:18:38 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushOpen1;
    QLineEdit *openline1;
    QPushButton *pushOpen2;
    QLineEdit *openline2;
    QPushButton *gen_p;
    QLineEdit *linep;
    QLabel *n_p;
    QLineEdit *lineq;
    QLabel *label_p;
    QLabel *label_q;
    QPushButton *pushto;
    QPushButton *pushfrom;
    QLabel *n_q;
    QPushButton *gen_q;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(629, 342);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(170, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushOpen1 = new QPushButton(centralWidget);
        pushOpen1->setObjectName(QString::fromUtf8("pushOpen1"));
        pushOpen1->setGeometry(QRect(20, 20, 161, 31));
        openline1 = new QLineEdit(centralWidget);
        openline1->setObjectName(QString::fromUtf8("openline1"));
        openline1->setGeometry(QRect(200, 20, 271, 31));
        openline1->setReadOnly(true);
        pushOpen2 = new QPushButton(centralWidget);
        pushOpen2->setObjectName(QString::fromUtf8("pushOpen2"));
        pushOpen2->setGeometry(QRect(20, 60, 161, 31));
        openline2 = new QLineEdit(centralWidget);
        openline2->setObjectName(QString::fromUtf8("openline2"));
        openline2->setGeometry(QRect(200, 60, 271, 31));
        openline2->setReadOnly(true);
        gen_p = new QPushButton(centralWidget);
        gen_p->setObjectName(QString::fromUtf8("gen_p"));
        gen_p->setGeometry(QRect(20, 120, 101, 21));
        linep = new QLineEdit(centralWidget);
        linep->setObjectName(QString::fromUtf8("linep"));
        linep->setGeometry(QRect(200, 120, 271, 20));
        n_p = new QLabel(centralWidget);
        n_p->setObjectName(QString::fromUtf8("n_p"));
        n_p->setGeometry(QRect(490, 120, 61, 21));
        lineq = new QLineEdit(centralWidget);
        lineq->setObjectName(QString::fromUtf8("lineq"));
        lineq->setGeometry(QRect(200, 150, 271, 20));
        label_p = new QLabel(centralWidget);
        label_p->setObjectName(QString::fromUtf8("label_p"));
        label_p->setGeometry(QRect(130, 120, 61, 21));
        QFont font;
        font.setPointSize(10);
        label_p->setFont(font);
        label_q = new QLabel(centralWidget);
        label_q->setObjectName(QString::fromUtf8("label_q"));
        label_q->setGeometry(QRect(130, 150, 61, 21));
        label_q->setFont(font);
        pushto = new QPushButton(centralWidget);
        pushto->setObjectName(QString::fromUtf8("pushto"));
        pushto->setGeometry(QRect(40, 220, 111, 31));
        pushfrom = new QPushButton(centralWidget);
        pushfrom->setObjectName(QString::fromUtf8("pushfrom"));
        pushfrom->setGeometry(QRect(170, 220, 111, 31));
        n_q = new QLabel(centralWidget);
        n_q->setObjectName(QString::fromUtf8("n_q"));
        n_q->setGeometry(QRect(490, 150, 61, 21));
        gen_q = new QPushButton(centralWidget);
        gen_q->setObjectName(QString::fromUtf8("gen_q"));
        gen_q->setGeometry(QRect(20, 150, 101, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 629, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "RSA", 0, QApplication::UnicodeUTF8));
        pushOpen1->setText(QApplication::translate("MainWindow", " \320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\262\321\205\320\276\320\264\321\217\321\211\320\270\320\271 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        pushOpen2->setText(QApplication::translate("MainWindow", " \320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\270\321\201\321\205\320\276\320\264\321\217\321\211\320\270\320\271 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        gen_p->setText(QApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 p", 0, QApplication::UnicodeUTF8));
        n_p->setText(QApplication::translate("MainWindow", "\320\235\320\265 \320\277\321\200\320\276\321\201\321\202\320\276\320\265 ", 0, QApplication::UnicodeUTF8));
        label_p->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\200", 0, QApplication::UnicodeUTF8));
        label_q->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 q", 0, QApplication::UnicodeUTF8));
        pushto->setText(QApplication::translate("MainWindow", "\320\227\320\260\321\210\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushfrom->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\210\320\270\321\204\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        n_q->setText(QApplication::translate("MainWindow", "\320\235\320\265 \320\277\321\200\320\276\321\201\321\202\320\276\320\265 ", 0, QApplication::UnicodeUTF8));
        gen_q->setText(QApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 q", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
