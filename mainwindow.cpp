#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    searchHighlighter = new SyntaxHighlighter(ui->main_text->document());

    QLabel *text_label           = new QLabel(tr("find text:"), this);
    QPushButton *next_button     = new QPushButton(tr("next"), this);
    QPushButton *previous_button = new QPushButton(tr("previous"), this);
    find_le                      = new QLineEdit(this);

    ui->statusbar->addWidget(text_label);
    ui->statusbar->addWidget(find_le);
    ui->statusbar->addWidget(next_button);
    ui->statusbar->addWidget(previous_button);
    ui->statusbar->hide();

    connect(ui->open_button,     &QPushButton::clicked, this, &MainWindow::openFile);
    connect(ui->actionOpen_file, &QAction::triggered,   this, &MainWindow::openFile);
    connect(ui->save_button,     &QPushButton::clicked, this, &MainWindow::saveFileAs);
    connect(ui->actionSave_as,   &QAction::triggered,   this, &MainWindow::saveFileAs);
    connect(ui->actionSave_2,    &QAction::triggered,   this, &MainWindow::saveFile);
    connect(next_button,         &QPushButton::clicked, this, &MainWindow::findNext);
    connect(previous_button,     &QPushButton::clicked, this, &MainWindow::findPrevious);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    file_name = "";
    file_name = QFileDialog::getOpenFileName(this,tr("Open file"),QDir::current().path(),
                                                    tr("Text file(*.txt);;Binary file(*.original)"));

    if(file_name.length() > 0)
    {
        QFile file(file_name);

        if(file.open(QIODevice::ReadWrite | QIODevice::ExistingOnly))
        {
            QTextStream stream(&file);
            ui->main_text->setText(stream.readAll());
        }
    }
}

void MainWindow::saveFileAs()
{
    file_name = "";
    file_name = QFileDialog::getSaveFileName(this,tr("Open file"),QDir::current().path(),
                                            tr("Text file(*.txt);;Binary file(*.original)"));
    if(file_name.length() > 0)
    {

            QFile file(file_name);
            if(file.open(QIODevice::WriteOnly | QIODevice::Text))
            {
                QTextStream stream(&file);
                QString to_write = ui->main_text->toPlainText();
                stream << to_write;
                file.close();
            }

    }
}

void MainWindow::saveFile()
{
    if(file_name.length() > 0)
    {
        QFile file(file_name);
        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream stream(&file);
            QString to_write = ui->main_text->toPlainText();
            stream << to_write;
            file.close();
        }
    }
}


void MainWindow::findNext()
{
    searchHighlighter->searchText(find_le->text());
    QString searchString = find_le->text();
    QString mainText     = ui->main_text->toPlainText();

    int pos   = ui->main_text->textCursor().position();
    int index = mainText.indexOf(searchString,pos);

    if(index != -1)
        setCursorPos(index, searchString.length());

}

void MainWindow::findPrevious()
{
    searchHighlighter->searchText(find_le->text());
    QString searchString = find_le->text();
    QString mainText     = ui->main_text->toPlainText();

    int pos  = ui->main_text->textCursor().position();
    pos -= searchString.length();
    mainText = mainText.mid(0,pos);
    int index = mainText.lastIndexOf(searchString);

    if(index != -1)
        setCursorPos(index, searchString.length());
}

void MainWindow::setCursorPos(int start, int lenght)
{
    QTextCursor tCursor = ui->main_text->textCursor();

    tCursor.setPosition(start);
    tCursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, lenght);

    ui->main_text->setTextCursor(tCursor);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers() & Qt::ControlModifier)
    {
        switch (event->key()) {

        case Qt::Key_O:
            openFile();
            break;
        case Qt::Key_S:
            saveFile();
            break;
        case Qt::Key_F:
            if(ui->statusbar->isHidden())
            {
                ui->statusbar->show();
            }else{
                ui->statusbar->hide();
            }
            break;
        }
    }
}

