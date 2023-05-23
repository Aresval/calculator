#include "widget.h"
#include "ui_widget.h"
#include "Calculator.cpp"
#include <cstring>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //    QPalette pa(this->palette());

    //    QImage img = QImage(":/bg.jpg");
    //    img = img.scaled(this->size());
     //   QBrush *pic = new QBrush(img);

     ///   pa.setBrush(QPalette::Window,*pic);

    //  this->setStyleSheet("background-image: url(:/bg1.png);");
    QPalette pal =this->palette();
    pal.setBrush(QPalette::Background,QBrush(QPixmap(":/bg1.png")));
    setPalette(pal);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_num1_clicked()
{
    exp+="1";
    ui->lineEdit->setText(exp);
}

void Widget::on_num2_clicked()
{
    exp+="2";
    ui->lineEdit->setText(exp);
}

void Widget::on_num3_clicked()
{
    exp+="3";
    ui->lineEdit->setText(exp);
}

void Widget::on_num4_clicked()
{
    exp+="4";
    ui->lineEdit->setText(exp);
}

void Widget::on_num5_clicked()
{
    exp+="5";
    ui->lineEdit->setText(exp);
}

void Widget::on_num6_clicked()
{
    exp+="6";
    ui->lineEdit->setText(exp);
}

void Widget::on_num7_clicked()
{
    exp+="7";
    ui->lineEdit->setText(exp);
}

void Widget::on_num8_clicked()
{
    exp+="8";
    ui->lineEdit->setText(exp);
}

void Widget::on_num9_clicked()
{
    exp+="9";
    ui->lineEdit->setText(exp);
}

void Widget::on_leftbut_clicked()
{
    exp+="(";
    ui->lineEdit->setText(exp);
}

void Widget::on_rightbut_clicked()
{
    exp+=")";
    ui->lineEdit->setText(exp);
}

void Widget::on_jia_clicked()
{
    exp+="+";
    ui->lineEdit->setText(exp);
}

void Widget::on_jian_clicked()
{
    exp+="-";
    ui->lineEdit->setText(exp);
}

void Widget::on_cheng_clicked()
{
    exp+="*";
    ui->lineEdit->setText(exp);
}

void Widget::on_chu_clicked()
{
    exp+="/";
    ui->lineEdit->setText(exp);
}


void Widget::on_num0_clicked()
{
    exp+="0";
    ui->lineEdit->setText(exp);
}

void Widget::on_pushButton_clicked()
{
    exp=exp.left(exp.length()-1);
    ui->lineEdit->setText(exp);
}
void Widget::on_clear_clicked()
{
    exp.clear();
    ui->lineEdit->setText(exp);
}

void Widget::on_num8_2_clicked()
{
    exp+='!';
    ui->lineEdit->setText(exp);
}

void Widget::on_yu_clicked()
{
    exp+='&';
  //  exp+='&';
    ui->lineEdit->setText(exp);
}

void Widget::on_huo_clicked()
{
    exp+='|';
  //  exp+='|';
    ui->lineEdit->setText(exp);
}

void Widget::on_dengyu_clicked()
{

    try {
            infix = exp.toStdString();
            postfix = infixToPostfix(infix);
            int result = evaluatePostfixExpression(postfix);
            exp.clear();
            exp = QString::number(result);
            ui->lineEdit->setText(exp);
        } catch (const char* msg) {
            error += msg;
            ui->lineEdit->setText(error);
        }

}
