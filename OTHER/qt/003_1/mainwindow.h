#include <QtWidgets>
class QWebView;
class QLineEdit;
class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
    MainWindow(const QUrl& url);

    protected slots:
    void adjustLocation();
    void changeLocation();

    private:
    QWebView *view;
    QLineEdit *locationEdit;
};
