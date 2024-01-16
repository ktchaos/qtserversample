#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStartServer_clicked()
{
    if (server == nullptr) {
        auto port = ui->spnServerPort->value();
        server = new MyTCPServer(port);
        connect(server, &MyTCPServer::newClientConnected, this, &MainWindow::onNewClientConnected);
    }
}

void MainWindow::onNewClientConnected() {
    ui->lstConsole->addItem(QString("new Client connected"));
}

