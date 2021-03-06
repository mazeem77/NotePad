#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>
#include "tosignup.h"

namespace Ui {
class SignIn;
}

class SignIn : public QDialog
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = nullptr);
    ~SignIn();

private slots:
    void on_SignUp_clicked();

private:
    Ui::SignIn *ui;
};

#endif // SIGNIN_H
