#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTextCharFormat>
#include <QMainWindow>
#include <QTextDocument>
#include <QFileDialog>
#include <QTextStream>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextCursor>
#include <QLineEdit>
#include <QTextEdit>
#include <QKeyEvent>
#include <QLabel>
#include <QFile>

#include "syntaxhighlighter.h"

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
private:
    Ui::MainWindow *ui;

    QLineEdit *find_le;

    QString file_name; // This var located here for cashing file name

    SyntaxHighlighter *searchHighlighter;
};
#endif // MAINWINDOW_H
