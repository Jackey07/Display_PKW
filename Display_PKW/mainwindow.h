#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include "bremse.h"
#include "fahrenpkw.h"
#include "gang.h"
#include "gaspedal.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    FahrenPKW *fahrenp;
    Bremse *bremsep;
    Gang *gangp;
    Gaspedal *gaspedalp;

public:
    MainWindow(QWidget *parent = nullptr);
    //Tasten: S, (P?); N, 1 - 5, R; G; B
    void keyPressEvent(QKeyEvent*);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
