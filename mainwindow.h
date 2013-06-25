#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    void display();

private slots:
    void openfil1();
    void openfil2();
    void checkP();
    void checkQ();
    void gen_p();
    void gen_q();
    void checke();
    void checkd();
    void to();
    void from();
};

#endif // MAINWINDOW_H
