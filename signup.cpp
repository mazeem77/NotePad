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

bool SignUp::emailTest(QString mail)
{
    std::string Email = mail.toStdString();
    int lim = Email.length();
    for(int i=0; i < lim; i++){
        if (Email[i] == '@'){
            for(int j=0; j < lim; j++){
                if(Email[i] == '.' && Email[i+1] == 'c' && Email[i+2] == 'o' && Email[i+3] == 'm' && Email[i-1] == '@'){
                    return true;
                }
            }
        }
    }
//    return false;
}

void SignUp::on_signin_button_clicked()
{
    this->hide();
    SignIn si;
    si.setModal(true);
    si.exec();
}


void SignUp::on_signup_button_clicked()
{
    QString FName = ui->firstName->text();
    QString LName = ui->secondName->text();
    QString UName = ui->userName->text();
    QString Email = ui->email->text();
    QString Pass = ui->password->text();
    QString CPass = ui->confirmPassword->text();

    if (!FName.isEmpty()){
        if(!LName.isEmpty()){
            if (!UName.isEmpty()){
                if(Pass.length()>=6){
                    if(Pass == CPass){
                        if(emailTest(Email)){
                            dbh = new DatabaseHandler(this);
                            dbh->setAPIkey("AIzaSyAoB27uJgJKRfy9l_DewZvTUkVJDeGH5mY");
                            dbh->signup(Email, Pass);
                        }
                    else ui->signup_text->setText("Please Enter correct Email!");
                    }
                    else ui->signup_text->setText("Password and Confirm Password Mismatch!");
                }
                else ui->signup_text->setText("Password length must be larger than 6 characters!");
            }
            else ui->signup_text->setText("Username cannot be Empty!");
        }
        else ui->signup_text->setText("Last Name cannot be Empty!");
    }
    else ui->signup_text->setText("First Name cannot be Empty!");


}

