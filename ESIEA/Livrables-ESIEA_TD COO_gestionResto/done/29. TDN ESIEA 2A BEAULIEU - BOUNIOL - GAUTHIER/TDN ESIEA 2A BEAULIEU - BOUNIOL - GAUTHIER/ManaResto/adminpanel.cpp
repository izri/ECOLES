#include "adminpanel.h"
#include "startwindow.h"
#include "src/tools.h"
#include "ui_adminpanel.h"

///Constructor of a UI with no arguments given.
AdminPanel::AdminPanel(QWidget *parent) : QDialog(parent),ui(new Ui::AdminPanel)
{

    std::stringstream tempo;
    tempo << totalIncome();
    std::string str = tempo.str();
    ui->setupUi(this);
    // Most ordered
    ui->MStarter->setText(mostOrderStarter().c_str());
    ui->MMain->setText(mostOrderMain().c_str());
    ui->MDesert->setText(mostOrderDesert().c_str());
    ui->MBeverage->setText(mostOrderBeverage().c_str());
    // Less ordered
    ui->LStarter->setText(lessOrderStarter().c_str());
    ui->LMain->setText(lessOrderMain().c_str());
    ui->LDesert->setText(lessOrderDesert().c_str());
    ui->LBeverage->setText(lessOrderBeverage().c_str());
    // Income & Fidel Client
    ui->custoFidel->setText(fidelityCustomer().c_str());
    ui->totIncome->setText(str.c_str());
}

///Destructor.
AdminPanel::~AdminPanel()
{
    delete ui;
}

///Destroy the curent windows and load and show StartWindow.
void AdminPanel::on_pushButton_clicked()
{
    this->close();
    StartWindow w;
    w.setModal(true);
    w.exec();
}
