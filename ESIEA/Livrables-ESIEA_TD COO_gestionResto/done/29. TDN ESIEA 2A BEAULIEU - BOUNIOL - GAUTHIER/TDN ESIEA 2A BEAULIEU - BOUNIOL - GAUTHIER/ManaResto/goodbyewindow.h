#ifndef GOODBYEWINDOW_H
#define GOODBYEWINDOW_H

#include <QDialog>

///Name space for the graphical interface.
namespace Ui {
class GoodByeWindow;
}

///This class is the UI for thanking the customer at the end of his order.
class GoodByeWindow : public QDialog
{
    Q_OBJECT

public:
    ///Constructor.
    explicit GoodByeWindow(QWidget *parent = 0);
    ///Destructor.
    ~GoodByeWindow();

private slots:
    ///Method called when the button logout is pressed.
    void on_pushButton_clicked();

private:
    Ui::GoodByeWindow *ui;/**<The graphical interface.*/
};

#endif // GOODBYEWINDOW_H
