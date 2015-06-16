#ifndef DISHSELECTIONWINDOW_H
#define DISHSELECTIONWINDOW_H

#include <QDialog>
#include "dishselectionwindow.h"
#include "startwindow.h"
#include "commandcheckwindow.h"
#include "ui_dishselectionwindow.h"
#include "src/customer.h"

///Name space for the graphical interface.
namespace Ui {
class DishSelectionWindow;
}

///This class is for the window where you choose your dishes.
class DishSelectionWindow : public QDialog
{
    Q_OBJECT

public:
    ///Constructor of the selection dish window without any arguments.
    explicit DishSelectionWindow(QWidget *parent = 0);
    ///Constructor of the selection dish window with a customer given.
    explicit DishSelectionWindow(Customer custo);
    ///Constructor of the selection dish window with a customer and a error given.
    explicit DishSelectionWindow(Customer custo, QString error);

    ///Destructor of a selection dish window.
    ~DishSelectionWindow();

private slots:
    ///Method called when the user press the "abord button".
    void on_Abort_clicked();
    ///Method called when the user press the "order" button.
    void on_Order_clicked();

private:
    Ui::DishSelectionWindow *ui; /**<The graphical interface.*/
    Customer m_custo;/**<Customer information for saving in data base.*/
};

#endif // DISHSELECTIONWINDOW_H
