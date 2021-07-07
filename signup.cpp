#include "signup.h"
#include "ui_signup.h"

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
    this->setWindowTitle("SignUp");
    ui->firstName->setPlaceholderText("First Name");
    ui->secondName->setPlaceholderText("Last Name");
    ui->userName->setPlaceholderText("Username");
    ui->email->setPlaceholderText("Email");
    ui->password->setPlaceholderText("Password");
    ui->confirmPassword->setPlaceholderText("Confirm Password");
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_signin_button_clicked()
{
    this->hide();
    SignIn si;
    si.setModal(true);
    si.exec();
}

