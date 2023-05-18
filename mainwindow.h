#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTextCharFormat>
#include <QMainWindow>
#include <QTextDocument>
#include <QDockWidget>
#include <QFileDialog>
#include <QTextStream>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextCursor>
#include <QPalette>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QKeyEvent>
#include <QLabel>
#include <QFile>

#include "syntaxhighlighter.h"
#include "fontmanager.h"
#include "theme.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void openFile();
    void saveFileAs();
    void saveFile();
    void findNext();
    void findPrevious();
    void setCursorPos(int, int); 

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void fontBoxChanged();
    void boldButton();
    void italicButton();
    void underlinedButton();
    void strikeOutButton();
    void changeTheme();
    void setTheme(QPalette);

private:
    Ui::MainWindow *ui;

    QLineEdit *find_le;

    QString file_name; // This var located here for cashing file name

    SyntaxHighlighter *searchHighlighter;
    FontManager             *fontManager;
    Theme                         *theme;
};
#endif // MAINWINDOW_H
