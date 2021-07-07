#include "signin.h"
#include "ui_signin.h"
#include <signup.h>

SignIn::SignIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignIn)
{
    ui->setupUi(this);
    ui->email->setPlaceholderText("Email");
    ui->password->setPlaceholderText("Password");
}

SignIn::~SignIn()
{
    delete ui;
}

void SignIn::on_SignUp_clicked()
{
    this->hide();
    SignUp su;
    su.setModal(true);
    su.exec();
}

