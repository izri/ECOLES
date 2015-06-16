#include "startwindow.h"
#include "neworderwindow.h"
#include "adminpanel.h"
#include "ui_startwindow.h"

///Constructor with no parameter given.
StartWindow::StartWindow(QWidget *parent) : QDialog(parent), ui(new Ui::StartWindow)
{
    ui->setupUi(this);
}

///Free the UI from the memory.
StartWindow::~StartWindow()
{
    delete ui;
}

///Print the window NewOrderWindow.
void StartWindow::on_pushButton_clicked()
{
    this->close();
    NewOrderWindow w;
    w.setModal(true);
    w.exec();
}

///Print the window AdminPanel.
void StartWindow::on_pushButton_2_clicked()
{
    this->close();
    AdminPanel w;
    w.setModal(true);
    w.exec();
}
