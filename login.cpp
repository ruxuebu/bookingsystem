#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    //set the logo on the left hand
    QPixmap pix("C:/Users/Tesla.L/Desktop/login.png");
    ui->label_pic->setPixmap((pix));

    //whether the database is open or not
    if(!connOpen())
        ui->label->setText("Failed to open the database!");
    else
        ui->label->setText("Connected.....");
}

login::~login()
{
    delete ui;

}

void login::on_pushButton_clicked()
{
    //for the user to login to the booking system
    QString username,password;
    username=ui->lineEdit_username->text();
    password=ui->lineEdit_password->text();

    qry=new QSqlQuery(mydb);
    qry->prepare("select name from LoginInfo where username='"+username+"' and password='"+password+"'");

    if(qry->exec())

    {
        int count=0;
        while(qry->next()){
            //if the user is professor , the system will enter as an admin.
            count++;
            if(count==1&&QString::compare(ui->lineEdit_username->text(),"admin")==0){
               if(QString::compare(ui->lineEdit_password->text(),"123456")==0){
                    this->hide();
                    connClose();
                    admininfo Admininfo;
                    Admininfo.setModal(true);
                    Admininfo.exec();
                }
            }else if(count==1){

                // the user will login as a student.
                ui->label->setText("username and password is correct");
                this->hide();
                QString Name=qry->value(0).toString();
                connClose();
                studentinfo Studentinfo(Name);
                Studentinfo.setModal(true);
                Studentinfo.exec();
            }
          }
            if(count<1)
               QMessageBox::warning(this,tr("Fail to login"),tr("Id or password is incorrect!"));

    }

}

void login::connClose()
{
    mydb.close();
    mydb.removeDatabase(QSqlDatabase::defaultConnection);
}

bool login::connOpen(){

    mydb=QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/Tesla.L/Desktop/StudentInfo.sqlite");

    if(!mydb.open()){
        qDebug()<<("Failed to open the database!");
        return false;
    }
    else{
        qDebug()<<("Connected.....");
        return true;
    }
}
