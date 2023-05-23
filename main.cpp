#include "widget.h"
#include <QApplication>
#include <QString>
#define rep(i,a,b) for(int i=a;i<=b;i++)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
