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
    std::string email = mail.toStdString();
    bool atCheck = false;
    bool comCheck = false;

    std::string temp = ".com";
    int length = email.length();
    for (int i = 0; i < length; i++)
    {
        if (email[i] == '@')
        {
            atCheck = true;
            break;
        }
    }

    if (atCheck == true)
    {
        if (email[email.length() - 5] == '@')
        {
            return false;
        }
        comCheck = true;
        for (int i = 4; i > 0; i--)
        {
            if (email[length - i] == temp[4 - i])
            {
                continue;
            }
            else
            {
                comCheck = false;
                break;
            }
        }
    }
    if (atCheck && comCheck)
    {
        return true;
    }
    else
    {
        return false;
    }
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

