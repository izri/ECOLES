#include "dishselectionwindow.h"
#include "startwindow.h"
#include "commandcheckwindow.h"
#include "ui_dishselectionwindow.h"
#include "src/customer.h"

///Blank constructor for initializing the DishSelectionWindow.
DishSelectionWindow::DishSelectionWindow(QWidget *parent) : QDialog(parent), ui(new Ui::DishSelectionWindow)
{
    ui->setupUi(this);
}

///Constructor for initializing the DishSelectionWindow for the first time it's printed.
DishSelectionWindow::DishSelectionWindow(Customer custo) : QDialog(0), ui(new Ui::DishSelectionWindow), m_custo(custo)
{
    ui->setupUi(this);
}

///Constructor for showing the DishSelectionWindow when a wrong parameter is given before.
DishSelectionWindow::DishSelectionWindow(Customer custo, QString error) : QDialog(0),ui(new Ui::DishSelectionWindow), m_custo(custo)
{
    ui->setupUi(this);
    ui->ErrorMessage->setText(error);
}

///Free the UI in the memory.
DishSelectionWindow::~DishSelectionWindow()
{
    delete ui;
}

///When clicked return to the main page.
void DishSelectionWindow::on_Abort_clicked()
{
    this->close();
    StartWindow w;
    w.setModal(true);
    w.exec();
}

///When clicked build an order, close the DishSelectionWindow and open the next window CommandCheckWindow.
void DishSelectionWindow::on_Order_clicked()
{
    unsigned short starter=0, mainDishe=0, desert=0, beverage=0;

        // Starters
    if (ui->greek->isChecked())
        starter =1;
    else if (ui->soup->isChecked())
        starter =2;
    else if (ui->sausage->isChecked())
        starter =3;
    else if (ui->Starter_None->isChecked())
        starter =4;

        // Mains
    if (ui->steak->isChecked())
        mainDishe =1;
    else if (ui->choucroute->isChecked())
        mainDishe =2;
    else if (ui->lasagna->isChecked())
        mainDishe =3;
    else if (ui->Main_None->isChecked())
        mainDishe =4;

        // Deserts
    if (ui->ice->isChecked())
        desert =1;
    else if (ui->tiramisu->isChecked())
        desert =2;
    else if (ui->bavarois->isChecked())
        desert =3;
    else if (ui->Desert_None->isChecked())
        desert =4;

        // Beverages
    if (ui->beer->isChecked())
        beverage =1;
    else if (ui->wine->isChecked())
        beverage =2;
    else if (ui->coca->isChecked())
        beverage =3;
    else if (ui->Beverage_None->isChecked())
        beverage =4;

    if (starter == 4 && mainDishe == 4 && desert == 4 && beverage == 4) // All order arer none
    {
        this->close();
        StartWindow w;
        w.setModal(true);
        w.exec();
    }

        // 4 empty boxes
    else if (starter == 0 && mainDishe == 0 && desert == 0 && beverage == 0)
    {
        this->close();
        DishSelectionWindow w(m_custo, "/!\\ - Empty field(s)... Try again.");
        w.setModal(true);
        w.exec();
    }
    // 3 empty boxes
    else if (starter == 0 && mainDishe == 0 && desert == 0)
    {
        this->close();
        DishSelectionWindow w(m_custo, "/!\\ - Empty field(s)... Try again.");
        w.setModal(true);
        w.exec();
    }
    else if (mainDishe == 0 && desert == 0 && beverage == 0)
    {
        this->close();
        DishSelectionWindow w(m_custo, "/!\\ - Empty field(s)... Try again.");
        w.setModal(true);
        w.exec();
    }
    else if (mainDishe == 0 && desert == 0 && beverage == 0)
    {
        this->close();
        DishSelectionWindow w(m_custo, "/!\\ - Empty field(s)... Try again.");
        w.setModal(true);
        w.exec();
    }
    else if (mainDishe == 0 && desert == 0 && beverage == 0)
    {
        this->close();
        DishSelectionWindow w(m_custo, "/!\\ - Empty field(s)... Try again.");
        w.setModal(true);
        w.exec();
    }
    // 2 empty boxes
    else if (starter == 0 && mainDishe == 0)
    {
        this->close();
        DishSelectionWindow w(m_custo, "/!\\ - Empty field(s)... Try again.");
        w.setModal(true);
        w.exec();
    }
    else if (mainDishe == 0 && desert == 0)
    {
        this->close();
        DishSelectionWindow w(m_custo, "/!\\ - Empty field(s)... Try again.");
        w.setModal(true);
        w.exec();
    }
    else if (desert == 0 && beverage == 0)
    {
        this->close();
        DishSelectionWindow w(m_custo, "/!\\ - Empty field(s)... Try again.");
        w.setModal(true);
        w.exec();
    }
    else if (desert == 0 && beverage == 0)
    {
        this->close();
        DishSelectionWindow w(m_custo, "/!\\ - Empty field(s)... Try again.");
        w.setModal(true);
        w.exec();
    }
    // 1 empty box
    else if (starter == 0)
    {
        this->close();
        DishSelectionWindow w(m_custo, "/!\\ - Empty field(s)... Try again.");
        w.setModal(true);
        w.exec();
    }
    else if (mainDishe == 0)
    {
        this->close();
        DishSelectionWindow w(m_custo, "/!\\ - Empty field(s)... Try again.");
        w.setModal(true);
        w.exec();
    }
    else if (desert == 0)
    {
        this->close();
        DishSelectionWindow w(m_custo, "/!\\ - Empty field(s)... Try again.");
        w.setModal(true);
        w.exec();
    }
    else if (beverage == 0)
    {
        this->close();
        DishSelectionWindow w(m_custo, "/!\\ - Empty field(s)... Try again.");
        w.setModal(true);
        w.exec();
    }

    else
    {
        if(m_custo.getAge()<18) //Can't take alcohol because too young
        {
            if(beverage==1||beverage==2)
            {
                this->close();
                DishSelectionWindow w(m_custo, "/!\\ - You are underage for alcohol.");
                w.setModal(true);
                w.exec();
            }
            else
            {
                Order custOrd(starter, mainDishe, desert, beverage);
                custOrd.totalPrice();
                this->close();
                CommandCheckWindow w(m_custo, custOrd);
                w.setModal(true);
                w.exec();
            }
        }
        else
        {
            Order custOrd(starter, mainDishe, desert, beverage);
            custOrd.totalPrice();
            this->close();
            CommandCheckWindow w(m_custo, custOrd);
            w.setModal(true);
            w.exec();
        }

    }
}
