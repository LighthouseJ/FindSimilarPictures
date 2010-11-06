#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_scanButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this,
                                                    tr("Select directory"),
                                                    QString(),
                                                    QFileDialog::ShowDirsOnly);

}
