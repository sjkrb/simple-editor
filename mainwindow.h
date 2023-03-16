#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_bold_clicked();

    void on_btn_subscript_clicked(bool checked);

    void on_btn_superscript_clicked(bool checked);

    void on_plainTextEdit_selectionChanged();

    void on_actionMy_Resume_triggered();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
