#include <QtWidgets>
#include <QtWebKitWidgets>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   QUrl url;
   url = QUrl("http://www.yandex.ru");
  // QTabWidget tab;
   MainWindow browser(url);
   browser.show();
   return a.exec();
}

