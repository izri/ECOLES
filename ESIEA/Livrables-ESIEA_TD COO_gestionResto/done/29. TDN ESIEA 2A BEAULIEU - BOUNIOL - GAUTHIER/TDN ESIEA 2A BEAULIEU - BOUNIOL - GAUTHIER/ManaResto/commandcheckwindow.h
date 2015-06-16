#ifndef COMMANDCHECKWINDOW_H
#define COMMANDCHECKWINDOW_H

#include <QDialog>
#include <sstream>
#include "src/customer.h"
#include "src/order.h"
#include "src/dish.h"
///Name space for the graphical interface.
namespace Ui {
class CommandCheckWindow;
}
///This class confirm Order make by a Customer.
class CommandCheckWindow : public QDialog
{
    Q_OBJECT
public:
    ///Constructor with no parameters given.
    explicit CommandCheckWindow(QWidget *parent = 0);
    ///Constructor with a given Customer and a given Order.
    explicit CommandCheckWindow(Customer custo, Order custOrd);
    ///Destructor.
    ~CommandCheckWindow();

private slots:
    ///Method called when abort button is pressed.
    void on_pushButton_2_clicked();
    ///Method called when pay button is clicked.
    void on_pushButton_clicked();

private:

    Ui::CommandCheckWindow *ui; /**<The UI interface*/
    Customer m_custo;/**<Customer information for saving in data base.*/
    Order m_custOrd;/**<Order informations for saving it into the database.*/
};

#endif // COMMANDCHECKWINDOW_H
