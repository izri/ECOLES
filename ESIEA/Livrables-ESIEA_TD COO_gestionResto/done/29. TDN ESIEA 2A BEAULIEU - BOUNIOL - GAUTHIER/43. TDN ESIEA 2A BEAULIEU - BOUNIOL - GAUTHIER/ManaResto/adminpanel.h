#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QDialog>

namespace Ui
{
    class AdminPanel;
}

///The class for the UI of the administration panel.
class AdminPanel : public QDialog
{
    Q_OBJECT

public:
    ///Constructor of AdminPanel.
    explicit AdminPanel(QWidget *parent = 0);
    ///Destructor of AdminPanel.
    ~AdminPanel();

private slots:
    /// Method called when the "main menu" button is hit.
    void on_pushButton_clicked();

private:
    Ui::AdminPanel *ui; /**<The graphical interface.*/
};

#endif // ADMINPANEL_H
