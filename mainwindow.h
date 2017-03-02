#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

struct node {
    QString uid;
    QString name;
    QString price;
    node* next;
};

typedef node* nodeptr;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_readerfile_clicked();

    
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
