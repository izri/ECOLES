#include "commandcheckwindow.h"
#include "startwindow.h"
#include "goodbyewindow.h"
#include "ui_commandcheckwindow.h"

///Empty constructor for initialisation.
CommandCheckWindow::CommandCheckWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CommandCheckWindow)
{
    ui->setupUi(this);
}

///Constructor that copy a given Customer and a given Order to his attributes.
CommandCheckWindow::CommandCheckWindow(Customer custo, Order custOrd) : QDialog(0), ui(new Ui::CommandCheckWindow), m_custo(custo), m_custOrd(custOrd)
{
    std::stringstream tempo;
    tempo << custOrd.ntaxPrice();
    std::string str = tempo.str();

    std::stringstream tempo2;
    tempo2 << custOrd.getPrice();
    std::string str2 = tempo2.str();

    ui->setupUi(this);
    ui->Starter->setText((custOrd.getNameStarter()).c_str());
    ui->MainDishe->setText(custOrd.getNameMain().c_str());
    ui->Desert->setText(custOrd.getNameDesert().c_str());
    ui->Beverage->setText(custOrd.getNameBeverage().c_str());
    ui->Ntaxe->setText(str.c_str());
    ui->Wtaxe->setText(str2.c_str());
}

///Destructor. Free the memory of the UI.
CommandCheckWindow::~CommandCheckWindow()
{
    delete ui;
}

///When clicked return to the main page.
void CommandCheckWindow::on_pushButton_2_clicked() // abort
{
    this->close();
    StartWindow w;
    w.setModal(true);
    w.exec();
}

///When clicked go to the next page, the goodbyewindow.
void CommandCheckWindow::on_pushButton_clicked() // pay
{

    std::ifstream tmpR("../ManaResto/lastid.txt");
    std::string tmp1, tmp2;
    int gipsy; //This variable is not called gipsy for nothing (it was like 1 am when we implement it so...)
    getline(tmpR, tmp1);
    getline(tmpR, tmp2);
    tmpR.close();
    gipsy=strtoul(tmp2.c_str(), NULL, 0);
    gipsy++;
    std::stringstream tempo;
    tempo << gipsy;
    tmp2 = tempo.str();
    std::ofstream tmpW("../ManaResto/lastid.txt");
    tmpW << tmp1 << std::endl;
    tmpW << tmp2 << std::endl;
    tmpW.close();

    unsigned int check;
    m_custOrd.totalPrice();
    check =m_custOrd.getPrice();
    m_custo.newVisit();
    m_custo.addExpense(check);

    m_custo.saveCustomer();
    m_custOrd.updateOrder();

    m_custOrd.saveOrder(m_custo.getCustomerName());
    this->close();
    GoodByeWindow w;
    w.setModal(true);
    w.exec();
}
