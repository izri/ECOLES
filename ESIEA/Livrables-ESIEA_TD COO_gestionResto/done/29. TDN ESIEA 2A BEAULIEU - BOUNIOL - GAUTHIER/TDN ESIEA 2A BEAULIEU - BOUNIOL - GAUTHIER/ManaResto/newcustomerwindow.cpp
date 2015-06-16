#include "newcustomerwindow.h"
#include "dishselectionwindow.h"
#include "ui_newcustomerwindow.h"

///Constructor with no parameter given.
NewCustomerWindow::NewCustomerWindow(QWidget *parent) : QDialog(parent),ui(new Ui::NewCustomerWindow)
{
    ui->setupUi(this);
}

///Constructor of a window print the name and the surname.
NewCustomerWindow::NewCustomerWindow(QString name, QString surname) : QDialog(0),ui(new Ui::NewCustomerWindow), m_name(name), m_surname(surname)
{
    ui->setupUi(this);
    ui->Label_Name->setText(m_name);
    ui->Label_Surname->setText(m_surname);
}

///Constructor of a window print the errors in the window.
NewCustomerWindow::NewCustomerWindow(QString error1, QString error2, QString name, QString surname) : QDialog(0),ui(new Ui::NewCustomerWindow)
{
    m_name =name;
    m_surname =surname;
    ui->setupUi(this);
    ui->Label_Name->setText(m_name);
    ui->Label_Surname->setText(m_surname);
    ui->AgeError->setText(error1);
    ui->GenderError->setText(error2);
}

///Free the UI from the memory.
NewCustomerWindow::~NewCustomerWindow()
{
    delete ui;
}

///Check if all the field are completed and correct and print the next window, DishSelectionWindow.
void NewCustomerWindow::on_Subscribe_clicked()
{
    bool gender;
    QString age =ui->Age->text();

    if (age.isEmpty()) // Age is not filled
    {
        if (!ui->Male->isChecked() && !ui->Female->isChecked()) // If no field have been filled
        {
            this->close();
            NewCustomerWindow w("/!\\ - Empty field... Try again.", "/!\\ - Please specify a gender.", m_name, m_surname);
            w.setModal(true);
            w.exec();
        }
        else // If only age is not filled
        {
            this->close();
            NewCustomerWindow w("/!\\ - Empty field... Try again.", " ", m_name, m_surname);
            w.setModal(true);
            w.exec();
        }
    }

    else // Age is filled
    {
        if (age.toInt() <= 0 || age.toInt() > 125) // Age is not legal
        {
            if (!ui->Male->isChecked() && !ui->Female->isChecked()) // Gender aren't checked
            {
                this->close();
                NewCustomerWindow w("/!\\ - Are you lying on your age?", "/!\\ - Please specify a gender.", m_name, m_surname);
                w.setModal(true);
                w.exec();
            }
            else // Gender is checked
            {
                this->close();
                NewCustomerWindow w("/!\\ - Are you lying on your age?", " ", m_name, m_surname);
                w.setModal(true);
                w.exec();
            }
        }

        else // Age is okay
        {
            if (!ui->Male->isChecked() && !ui->Female->isChecked()) // Gender aren't checked
            {
                this->close();
                NewCustomerWindow w(" ", "/!\\ - Please specify a gender.", m_name, m_surname);
                w.setModal(true);
                w.exec();
            }
            else // Everything is OK
            {
                if (ui->Male->isChecked())
                    gender =true;
                else
                    gender =false;

                Customer custo(ui->Label_Name->text().toStdString(), ui->Label_Surname->text().toStdString(), ui->Age->text().toInt(), gender);
                custo.saveCustomer();

                std::ifstream tmpR("../ManaResto/lastid.txt");
                std::string tmp1, tmp2;
                int gipsy;
                getline(tmpR, tmp1);
                getline(tmpR, tmp2);
                tmpR.close();
                gipsy=strtoul(tmp1.c_str(), NULL, 0);
                gipsy++;
                std::stringstream tempo;
                tempo << gipsy;
                tmp1 = tempo.str();
                std::ofstream tmpW("../ManaResto/lastid.txt");
                tmpW << tmp1 << std::endl;
                tmpW << tmp2 << std::endl;
                tmpW.close();


                this->close();
                DishSelectionWindow w(custo);
                w.setModal(true);
                w.exec();
            }
        }
    }


}

///Return to the StartWindow.
void NewCustomerWindow::on_Abort_clicked()
{
    this->close();
    StartWindow w;
    w.setModal(true);
    w.exec();
}
