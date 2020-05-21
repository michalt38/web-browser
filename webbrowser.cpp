#include "webbrowser.h"
#include "ui_webbrowser.h"

WebBrowser::WebBrowser(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WebBrowser)
{
    ui->setupUi(this);

    ui->prevButton->setIcon(QIcon(":/buttons/icons/go-previous.png"));
    ui->nextButton->setIcon(QIcon(":/buttons/icons/go-next.png"));
    ui->refreshButton->setIcon(QIcon(":/buttons/icons/view-refresh.png"));


    QString style = "QPushButton {border:none; width:25px; height:25px;}"
                    "QPushButton:hover {background-color: rgb(233, 223, 220);}";

    ui->prevButton->setStyleSheet(style);
    ui->nextButton->setStyleSheet(style);
    ui->refreshButton->setStyleSheet(style);

    connect(ui->addressBar, &QLineEdit::returnPressed, this, &WebBrowser::onAddressBarEnterPressed);

    ui->webView->load(QUrl("https://www.google.com"));
    ui->webView->show();
}

void WebBrowser::onAddressBarEnterPressed()
{
    ui->webView->load(QUrl(ui->addressBar->text()));
}


WebBrowser::~WebBrowser()
{
    delete ui;
}

