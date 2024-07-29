

#include <QMainWindow>

#include "ui_mainwindow.h"



class MainWindow : public QMainWindow, public Ui_MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr): QMainWindow(parent){
        this->setupUi(this);
    }



    ~MainWindow(){
        delete this;
    }
};
