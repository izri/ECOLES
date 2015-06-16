#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QDialog>
#include "neworderwindow.h"

///Name space for the graphical interface.
namespace Ui {
class StartWindow;
}

///This class is the main window of the program.
class StartWindow : public QDialog
{
    Q_OBJECT

public:
    ///Constructor of StartWindow with no parameters given.
    explicit StartWindow(QWidget *parent = 0);
    ///Destructor of StartWindow.
    ~StartWindow();

private slots:
    ///Method called when the "New Order" button is pressed.
    void on_pushButton_clicked();
    ///Method called when the "Statistic" button is pressed.
    void on_pushButton_2_clicked();

private:
    Ui::StartWindow *ui;/**<The graphical interface.*/
};

#endif // STARTWINDOW_H
