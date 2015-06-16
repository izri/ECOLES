#include "goodbyewindow.h"
#include "startwindow.h"
#include "ui_goodbyewindow.h"

///Constructor with no parameter given.
GoodByeWindow::GoodByeWindow(QWidget *parent) : QDialog(parent), ui(new Ui::GoodByeWindow)
{
    ui->setupUi(this);
}

///Free the UI in the memory.
GoodByeWindow::~GoodByeWindow()
{
    delete ui;
}

///Close the window and return to the StartWindow
void GoodByeWindow::on_pushButton_clicked()
{
    this->close();
    StartWindow w;
    w.setModal(true);
    w.exec();
}
