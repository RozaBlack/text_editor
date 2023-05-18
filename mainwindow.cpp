#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    searchHighlighter = new SyntaxHighlighter(ui->main_text);
    fontManager       = new FontManager();
    theme             = new Theme();

    QLabel *text_label           = new QLabel(tr("find text:"), this);
    QPushButton *next_button     = new QPushButton(tr("next"), this);
    QPushButton *previous_button = new QPushButton(tr("previous"), this);
    find_le                      = new QLineEdit(this);
//setWindowFlag(Qt::ToolTip);
    ui->statusbar->addWidget(text_label);
    ui->statusbar->addWidget(find_le);
    ui->statusbar->addWidget(previous_button);
    ui->statusbar->addWidget(next_button);
    ui->statusbar->hide();

    ui->font_combo_box->setEditable(false);
    ui->font_size_box->setEditable(false);
    ui->theme_box->setEditable(false);
    ui->font_size_box->addItem("8", 8);
    ui->font_size_box->addItem("9", 9);
    ui->font_size_box->addItem("10", 10);
    ui->font_size_box->addItem("11", 11);
    ui->font_size_box->addItem("12", 12);
    ui->font_size_box->addItem("14", 14);
    ui->font_size_box->addItem("16", 16);
    ui->font_size_box->addItem("18", 18);
    ui->font_size_box->addItem("20", 20);
    ui->font_size_box->addItem("22", 22);
    ui->font_size_box->addItem("24", 24);
    ui->font_size_box->addItem("26", 26);
    ui->font_size_box->addItem("28", 28);
    ui->font_size_box->addItem("36", 36);
    ui->font_size_box->addItem("48", 48);
    ui->font_size_box->addItem("72", 72);

    ui->theme_box->addItem("light", 1);
    ui->theme_box->addItem("dark", 2);

    theme->setTheme(2);

    connect(ui->open_button,     &QPushButton::clicked, this, &MainWindow::openFile);
    connect(ui->actionOpen_file, &QAction::triggered,   this, &MainWindow::openFile);
    connect(ui->save_button,     &QPushButton::clicked, this, &MainWindow::saveFileAs);
    connect(ui->actionSave_as,   &QAction::triggered,   this, &MainWindow::saveFileAs);
    connect(ui->actionSave_2,    &QAction::triggered,   this, &MainWindow::saveFile);
    connect(next_button,         &QPushButton::clicked, this, &MainWindow::findNext);
    connect(previous_button,     &QPushButton::clicked, this, &MainWindow::findPrevious);

    connect(ui->font_size_box,      SIGNAL(activated(int)), this, SLOT(fontBoxChanged()));
    connect(ui->font_combo_box,     SIGNAL(activated(int)), this, SLOT(fontBoxChanged()));
    connect(ui->theme_box,          SIGNAL(activated(int)), this, SLOT(changeTheme()));
    connect(ui->bold_button,        SIGNAL(clicked()),      this, SLOT(boldButton()));
    connect(ui->italic_button,      SIGNAL(clicked()),      this, SLOT(italicButton()));
    connect(ui->underlined_button,  SIGNAL(clicked()),      this, SLOT(underlinedButton()));
    connect(ui->strikeout_button,   SIGNAL(clicked()),      this, SLOT(strikeOutButton()));

    connect(theme, SIGNAL(setThemeSignal(QPalette)), this, SLOT(setTheme(QPalette)));
}

MainWindow::~MainWindow()
{
    delete searchHighlighter;
    delete fontManager;
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
                find_le->setFocus();
            }else{
                ui->statusbar->hide();
            }
            break;
        }
    }
}

void MainWindow::fontBoxChanged()
{
   fontManager->fontSizeChanged(ui->main_text,ui->font_combo_box->currentText(),
                                ui->font_size_box->currentData().toInt());
}

void MainWindow::boldButton()
{
    fontManager->setBold(ui->main_text);
}

void MainWindow::italicButton()
{
    fontManager->setItalic(ui->main_text);
}

void MainWindow::underlinedButton()
{
    fontManager->setUnderlined(ui->main_text);
}

void MainWindow::strikeOutButton()
{
    fontManager->setStrikeOut(ui->main_text);
}

void MainWindow::changeTheme()
{
    theme->setTheme(ui->theme_box->currentData().toInt());
}

void MainWindow::setTheme(QPalette pal)
{
    qApp->setPalette(pal);
}

