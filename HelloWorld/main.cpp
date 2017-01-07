#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //在堆上创界你一个QLable对象, 赋值"Hello, world"
    QLabel *lable = new QLabel("Hello, world");
    //调用show方法显示lable
    lable->show();
    //设置在关闭时释放lable
    lable->setAttribute(Qt::WA_DeleteOnClose);

    //在栈中创建一个PushButton按钮对象, 赋值为Quit
    QPushButton button("Quit");

    //信号槽连接 信号:button对象的chicked事件 槽:QApplication对象的quit动作
    QObject::connect(&button, &QPushButton::clicked, QApplication::quit);

    //button窗口移动至200,200位置 (相对父窗口, 即桌面)
    button.move(200, 200);

    //显示button
    button.show();
    //MainWindow w;
    //w.show();

    return app.exec();
}
