#ifndef NEWCUSTOMERWINDOW_H
#define NEWCUSTOMERWINDOW_H

#include <QDialog>
#include "dishselectionwindow.h"
#include "startwindow.h"

///Name space for the graphical interface.
namespace Ui {
class NewCustomerWindow;
}

///This class is for the window where you specify your Customer information.
class NewCustomerWindow : public QDialog
{
    Q_OBJECT

public:
    ///Constructor of the window without any arguments.
    explicit NewCustomerWindow(QWidget *parent = 0);
    ///Constructor of the window with a name and a surname given.
    explicit NewCustomerWindow(QString name, QString surname);
    ///Constructor of the windows with two given errors and a var for choosing the good constructor.
    explicit NewCustomerWindow(QString error1, QString error2, QString name, QString surname);

    ///Destructor.
    ~NewCustomerWindow();

private slots:
    ///When the Customer hit the "Subscribe" button.
    void on_Subscribe_clicked();
    ///When the Customer hit the "Abort" button.
    void on_Abort_clicked();

private:
    Ui::NewCustomerWindow *ui;/**<The graphical interface.*/
    QString m_name;
    QString m_surname;
};

#endif // NEWCUSTOMERWINDOW_H
