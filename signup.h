#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include "tosignin.h"
#include "databasehandler.h"

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();
    bool emailTest(QString mail);

private slots:
    void on_signin_button_clicked();

    void on_signup_button_clicked();

private:
    Ui::SignUp *ui;
    DatabaseHandler *dbh;
};

#endif // SIGNUP_H
