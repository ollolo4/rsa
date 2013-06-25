#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "superlong.h"
#include <QFileDialog>
#include <QTextStream>
#include <QLineEdit>
#include <QRegExp>
#include <QMessageBox>
#include <string>
#include <fstream>
#include <QTime>

#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    display();
    connect(ui->pushOpen1, SIGNAL( clicked() ), SLOT( openfil1() ));
    connect(ui->pushOpen2, SIGNAL( clicked() ), SLOT( openfil2() ));
    connect(ui->linep, SIGNAL( textChanged(QString) ), SLOT( checkP() ));
    connect(ui->lineq, SIGNAL( textChanged(QString) ), SLOT( checkQ() ));
    connect(ui->linee, SIGNAL( textChanged(QString) ), SLOT( checke() ));
    connect(ui->lined, SIGNAL( textChanged(QString) ), SLOT( checkd() ));
    connect(ui->gen_p, SIGNAL( clicked() ), SLOT( gen_p() ));
    connect(ui->gen_q, SIGNAL( clicked() ), SLOT( gen_q() ));
    connect(ui->pushto, SIGNAL( clicked() ), SLOT( to() ));
    connect(ui->pushfrom, SIGNAL( clicked() ), SLOT( from() ));

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
}

void MainWindow::display()
{
    ui->pushOpen2->setVisible(false);
    ui->openline2->setVisible(false);
    ui->gen_p->setVisible(false);
    ui->linep->setVisible(false);
    ui->label_p->setVisible(false);
    ui->n_p->setVisible(false);
    ui->gen_q->setVisible(false);
    ui->lineq->setVisible(false);
    ui->label_q->setVisible(false);
    ui->n_q->setVisible(false);
    ui->label_e->setVisible(false);
    ui->linee->setVisible(false);
    ui->label_d->setVisible(false);
    ui->lined->setVisible(false);
    ui->pushto->setVisible(false);
    ui->pushfrom->setVisible(false);
}

void MainWindow::openfil1()
{
    QString str = QFileDialog::getOpenFileName( this, QString::fromLocal8Bit( "Выбрать исходный файл" ) );
    if ( !str.isEmpty() )
    {
        ui->openline1->setText(str);
        ui->pushOpen2->setVisible(true);
        ui->openline2->setVisible(true);
    }
}

void MainWindow::openfil2()
{
    QString str = QFileDialog::getSaveFileName( this, QString::fromLocal8Bit( "Выбрать результирующий файл" ) );
    if ( !str.isEmpty() )
    {
        ui->openline2->setText(str);
        if( !ui->linee->isVisible() ) ui->gen_p->setVisible(true);
        ui->label_p->setVisible(true);
        ui->linep->setVisible(true);
    }
}

void MainWindow::checkP()
{
    if( !ui->lineq->isVisible() )
    {
        ui->gen_q->setVisible(true);
        ui->label_q->setVisible(true);
        ui->lineq->setVisible(true);
        ui->gen_p->setVisible(false);
    }
}

void MainWindow::checkQ()
{
    if( !ui->linee->isVisible() )
    {
        ui->gen_q->setVisible(false);
        ui->label_e->setVisible(true);
        ui->linee->setVisible(true);
        ui->label_d->setVisible(true);
        ui->lined->setVisible(true);
    }
}

void MainWindow::gen_p()
{
    superlong p;
    string str;
    p = generatep( "10000000000" );
    p.give( str );
    ui->linep->setText( QString::fromStdString( str ));
}

void MainWindow::gen_q()
{
    superlong q;
    string str;
    q = generatep( "10000000000" );
    q.give( str );
    ui->lineq->setText( QString::fromStdString( str ));
}

void MainWindow::checke()
{
    ui->lined->setReadOnly(true);
    ui->pushto->setVisible(true);
}

void MainWindow::checkd()
{
    ui->linee->setReadOnly(true);
    ui->pushfrom->setVisible(true);
}

void MainWindow::to()
{
    superlong p, q, n, phi, e, d, M, m;
    string str;
    bool c = false;

    QFile file1( ui->openline1->text().toUtf8().data() ), file2( ui->openline2->text().toUtf8().data() );
    file1.open( QIODevice::ReadOnly );
    file2.open( QIODevice::WriteOnly );

      //int tp = ui->linep->text().toInt();
//    QByteArray buf = file1.read(10);

//    qDebug() << "buf length: " << buf();

//    qDebug() << "buf - " << buf;
//    QString qstr = QString(buf);
//    M.get(qstr.toStdString());

//    FILE *f1, *f2;
//    f1 = fopen(ui->openline1->text().toUtf8().data(), "rb");
//    f2 = fopen(ui->openline2->text().toUtf8().data(), "wb");
//    char *buf;
//    fread(buf,1,1,f1);
//    str = string(buf);



    //M.getstr( QString(file1.readAll()).toLocal8Bit().data() );
    M.get( QString(file1.readAll()).toStdString() );
    //qDebug() << "***>" << buf << " --- " << str.data();

    //M.get(str);
    p.get( ui->linep->text().toStdString() );
    if( !isPrimitive( p ) )
    {
        ui->n_p->setVisible(true);
        ui->linep->setStyleSheet("QLineEdit#linep {background:red}");
        c = true;
    }
    else
    {
        ui->n_p->setVisible(false);
        ui->linep->setStyleSheet("QLineEdit#lineq {background:white}");
        ui->linep->setReadOnly(true);
    }

    q.get( ui->lineq->text().toStdString() );
    if( !isPrimitive( q ) )
    {
        ui->n_q->setVisible(true);
        ui->lineq->setStyleSheet("QLineEdit#lineq {background:red}");
        c = true;
    }
    else
    {
        ui->n_q->setVisible(false);
        ui->lineq->setStyleSheet("QLineEdit#lineq {background:white}");
        ui->lineq->setReadOnly(true);
    }

    if( c ) return;

    e.get( ui->linee->text().toStdString() );

    n = p * q;
    phi = (p-1) * (q-1);
    d = evklid_ext_x( e, phi );

    d.give(str);
    ui->lined->setText( QString::fromStdString(str) );

    m = powm( M, e, n );

    //---------------------------------------------
    superlong m_shtrih = powm(m, d, n);
    string m1,M1,m_s1;
    M.give(M1);
    m.give(m1);
    m_shtrih.give(m_s1);
    qDebug() << "--->" << M1.data() << "----" << m1.data() << "---" << m_s1.data();
    //---------------------------------------------

    //------------------------------------------
    superlong super_a, super_b, super_c;
    string _a = "ba", _b = "", _c = "";
    super_a.get(_a);
    super_b.get(_b);
    super_c.get(_c);

    super_c  = super_a + super_b;

    super_a.give(_a);
    super_b.give(_b);
    super_c.give(_c);
    QString xx, xt;
    int l = _c.length();
    for(int i = 0; i < l; i+=2)
    {
        xt.clear();
        xt.sprintf("%c",(_c[i]*10+_c[i+1]+32));
        xx += xt;
    }

    //qDebug() << _a.data() << " --- " << _b.data() << "---" << qstr;

    //------------------------------------------

    //QString s;
    //m.givestr(s);
    //file2.write( QByteArray().append( s )  );
    m.give(str);
    file2.write( QByteArray().append( QString::fromStdString(str) ) );


    file1.close();
    file2.close();

    //ui->res->setText( QString(str).toLocal8Bit() );
    QMessageBox::information(this, QString::fromLocal8Bit("Внимание!"), QString::fromLocal8Bit("Файл зашифрован"));
}

void MainWindow::from()
{
    superlong p, q, n, phi, e, d, M, m;
    string str;
    bool c = false;

    QFile file1( ui->openline1->text().toUtf8().data() ), file2( ui->openline2->text().toUtf8().data() );
    file1.open( QIODevice::ReadOnly );
    file2.open( QIODevice::WriteOnly );

    //ofstream OUT;
    //OUT.open(ui->openline2->text().toUtf8().data()) ;

    //M.getstr( QString(file1.readAll()).toLocal8Bit().data() );
    M.get( QString(file1.readAll()).toStdString() );

    p.get( ui->linep->text().toStdString() );
    if( !isPrimitive( p ) )
    {
        ui->n_p->setVisible(true);
        ui->linep->setStyleSheet("QLineEdit#linep {background:red}");
        c = true;
    }
    else
    {
        ui->n_p->setVisible(false);
        ui->linep->setStyleSheet("QLineEdit#lineq {background:white}");
        ui->linep->setReadOnly(true);
    }

    q.get( ui->lineq->text().toStdString() );
    if( !isPrimitive( q ) )
    {
        ui->n_q->setVisible(true);
        ui->lineq->setStyleSheet("QLineEdit#lineq {background:red}");
        c = true;
    }
    else
    {
        ui->n_q->setVisible(false);
        ui->lineq->setStyleSheet("QLineEdit#lineq {background:white}");
        ui->lineq->setReadOnly(true);
    }

    if( c ) return;

    d.get( ui->lined->text().toStdString() );

    n = p * q;
    phi = (p-1) * (q-1);
    e = evklid_ext_x( d, phi );

    e.give(str);
    ui->linee->setText( QString::fromStdString(str) );

    m = powm( M, d, n );

    //QString s;
    //m.givestr(s);
    m.give(str);
    qDebug() << "\n -- " << str.data();
    string _str;
    M.give(_str);
    qDebug() << "\n -- " << _str.data();

    //file2.write( QByteArray().append( s ) );
    file2.write( QByteArray().append( QString::fromStdString(str) ) );

    //OUT << str;

    file1.close();
    file2.close();

    //ui->res->setText( s );
    QMessageBox::information(this, QString::fromLocal8Bit("Внимание!"), QString::fromLocal8Bit("Файл расшифрован"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
