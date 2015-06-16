#include "neworderwindow.h"
#include "newcustomerwindow.h"
#include "ui_neworderwindow.h"

///Constructor with no parameter given.
NewOrderWindow::NewOrderWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewOrderWindow)
{
    ui->setupUi(this);
}

///Constructor for printing an error in the window.
NewOrderWindow::NewOrderWindow(QString error) : QDialog(0),ui(new Ui::NewOrderWindow)
{
    ui->setupUi(this);
    ui->Errormessage->setText(error);
}

///Free the UI from the memory.
NewOrderWindow::~NewOrderWindow()
{
    delete ui;
}

///Return to the StartWindow.
void NewOrderWindow::on_Abort_clicked()
{
    this->close();
    StartWindow w;
    w.setModal(true);
    w.exec();
}

///Check if the customer exist and if he don't exist go to the window NewCustomerWindow if he is exist go to DishSelectionWindow.
void NewOrderWindow::on_Proceed_clicked()
{

    QString name =ui->Name->text();
    QString surname =ui->Surname->text();

    name =ui->Name->text();
    surname =ui->Surname->text();

    this->close();
    //ajouter le test pour savoir si le customer existe dans la bdd ou pas
    std::string tmp;
    tmp="../ManaResto/customers/";
    tmp+=name.toStdString();
    tmp+="_";
    tmp+=surname.toStdString();
    tmp+=".txt";
    std::cerr << tmp << std::endl;
    std::ifstream custo(tmp.c_str());

    if(!name.isEmpty() && !surname.isEmpty())
    {
        if (!custo) // New customer
        {
            NewCustomerWindow w(name, surname);
            w.setModal(true);
            w.exec();
        }

        else // Existing customer
        {
            custo.close();
            Customer custo(tmp);
            DishSelectionWindow w(custo);
            w.setModal(true);
            w.exec();
        }
    }
    else // Dick
    {
        NewOrderWindow w("/!\\ - Empty field(s)... Try again.");
        w.setModal(true);
        w.exec();
    }

}
