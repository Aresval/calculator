#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStack>
#include <QPushButton>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
  //  QStack <double> q1;
  //  QStack <char> q2;
    int result;

private slots:
    void on_num1_clicked();

    void on_num2_clicked();

    void on_num3_clicked();

    void on_num4_clicked();

    void on_num5_clicked();

    void on_num6_clicked();

    void on_num7_clicked();

    void on_num8_clicked();

    void on_num9_clicked();

    void on_leftbut_clicked();

    void on_rightbut_clicked();

    void on_jia_clicked();

    void on_jian_clicked();

    void on_cheng_clicked();

    void on_chu_clicked();

    void on_num0_clicked();

    void on_pushButton_clicked();


    void on_clear_clicked();

    void on_num8_2_clicked();

    void on_yu_clicked();

    void on_huo_clicked();

    void on_dengyu_clicked();

private:
    Ui::Widget *ui;
    QString exp;
    QString error;
    std::string infix;
    std::string postfix;
};

#endif // WIDGET_H
