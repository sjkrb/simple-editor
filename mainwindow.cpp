#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTextCursor>
#include <QDebug>
#include <QTextBrowser>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_bold_clicked()
{
    if (ui->plainTextEdit->textCursor().hasSelection())
    {
        if(ui->plainTextEdit->textCursor().charFormat().font().weight() == QFont::Bold)
        {
            QTextCharFormat format;
            format.setFontWeight(QFont::Normal);
            ui->plainTextEdit->textCursor().setCharFormat(format);
        }
        else
        {
            QTextCharFormat format;
            format.setFontWeight(QFont::Bold);
            ui->plainTextEdit->textCursor().setCharFormat(format);
        }
    }
}


void MainWindow::on_btn_subscript_clicked(bool checked)
{
    if (ui->plainTextEdit->textCursor().hasSelection())
    {
        if(checked)
        {
            QString str = ui->plainTextEdit->textCursor().selectedText();
            ui->plainTextEdit->textCursor().removeSelectedText();
            ui->plainTextEdit->textCursor().insertHtml(QString("<sub>%1</sub>").arg(str));
        }
        else
        {
            QString str = ui->plainTextEdit->textCursor().selectedText();
            ui->plainTextEdit->textCursor().removeSelectedText();
            ui->plainTextEdit->textCursor().insertText(str);
        }
    }
}


void MainWindow::on_btn_superscript_clicked(bool checked)
{
    if (ui->plainTextEdit->textCursor().hasSelection())
    {
        if(checked)
        {
            QString str = ui->plainTextEdit->textCursor().selectedText();
            ui->plainTextEdit->textCursor().removeSelectedText();
            ui->plainTextEdit->textCursor().insertHtml(QString("<sup>%1</sup>").arg(str));
        }
        else
        {
            QString str = ui->plainTextEdit->textCursor().selectedText();
            ui->plainTextEdit->textCursor().removeSelectedText();
            ui->plainTextEdit->textCursor().insertText(str);
        }
    }
}


void MainWindow::on_plainTextEdit_selectionChanged()
{
    if(ui->plainTextEdit->textCursor().hasSelection())
    {
        if(ui->plainTextEdit->textCursor().charFormat().verticalAlignment() ==
                QTextCharFormat::VerticalAlignment::AlignSubScript)
            ui->btn_subscript->setChecked(true);
        else
            ui->btn_subscript->setChecked(false);


        if(ui->plainTextEdit->textCursor().charFormat().verticalAlignment() ==
                QTextCharFormat::VerticalAlignment::AlignSuperScript)
            ui->btn_superscript->setChecked(true);
        else
            ui->btn_superscript->setChecked(false);


        if(ui->plainTextEdit->textCursor().charFormat().font().weight() == QFont::Bold)
            ui->btn_bold->setChecked(true);
        else
            ui->btn_bold->setChecked(false);
    }
    else
    {
        ui->btn_bold->setChecked(false);
        ui->btn_subscript->setChecked(false);
        ui->btn_superscript->setChecked(false);
    }
}

void MainWindow::on_actionMy_Resume_triggered()
{
    QWidget *wdg = new QWidget();
    QTextBrowser *browser = new QTextBrowser();

    browser->setSource(QUrl("qrc:/htmls/index.html"));
    wdg->setLayout(new QGridLayout());
    wdg->layout()->addWidget(browser);
    wdg->show();
}


