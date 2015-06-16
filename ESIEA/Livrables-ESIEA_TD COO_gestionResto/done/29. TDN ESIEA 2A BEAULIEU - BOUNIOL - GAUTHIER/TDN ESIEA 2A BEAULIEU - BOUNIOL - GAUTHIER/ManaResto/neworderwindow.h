#ifndef NEWORDERWINDOW_H
#define NEWORDERWINDOW_H

#include <QDialog>
#include <iostream>
#include <string>
#include <fstream>
#include "startwindow.h"
#include "newcustomerwindow.h"

///Name space for the graphical interface.
namespace Ui {
class NewOrderWindow;
}

///This class will print the window when the Customer login.
class NewOrderWindow : public QDialog
{
    Q_OBJECT

public:
    ///Constructor of the window without any arguments.
    explicit NewOrderWindow(QWidget *parent = 0);
    ///constructor of thr window with an error given.
    explicit NewOrderWindow(QString error);
    ///Destructor of the window.
    ~NewOrderWindow();

private slots:
    ///Method called when the "Abort" button is pressed.
    void on_Abort_clicked();
    ///Method called when the "Prcoeed" button is pressed.
    void on_Proceed_clicked();

private:
    Ui::NewOrderWindow *ui;/**<The graphical interface.*/
};

#endif // NEWORDERWINDOW_H
