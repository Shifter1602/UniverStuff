#include <QtWidgets>
#include <QtWebKitWidgets>
#include "mainwindow.h"
MainWindow::MainWindow(const QUrl& url)
{
view = new QWebView(this);
view->load(url);
connect(view, SIGNAL(loadFinished(bool)), SLOT(adjustLocation()));

locationEdit = new QLineEdit(this);
locationEdit->setSizePolicy(QSizePolicy::Expanding, locationEdit->sizePolicy().verticalPolicy());
connect(locationEdit, SIGNAL(returnPressed()), SLOT(changeLocation()));

QToolBar *toolBar = addToolBar(tr("Navigation"));
toolBar->addAction(view->pageAction(QWebPage::Back));
toolBar->addAction(view->pageAction(QWebPage::Forward));
toolBar->addAction(view->pageAction(QWebPage::Reload));
toolBar->addAction(view->pageAction(QWebPage::Stop));
toolBar->addWidget(locationEdit);
setCentralWidget(view);
}
void MainWindow::adjustLocation()
{
    locationEdit->setText(view->url().toString());
}

void MainWindow::changeLocation()
{
    QUrl url = QUrl::fromUserInput(locationEdit->text());
    view->load(url);
    view->setFocus();
}
