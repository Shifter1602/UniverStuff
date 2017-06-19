#include <QtWidgets>
#include "mainwindow.h"

int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    QUrl url;
    url = QUrl("http://www.yandex.ru");
    MainWindow browser(url);
    browser.show();
    return app.exec();
}
