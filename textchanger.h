#ifndef TEXTCHANGER_H
#define TEXTCHANGER_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QGridLayout>

class TextChanger : public QWidget
{
    Q_OBJECT
public:
    explicit TextChanger(QTextEdit* textEditor, QWidget *parent = nullptr);

private slots:
    void changeText();

private:
    QPushButton *change_button;
    QLineEdit       *before_le;
    QLineEdit        *after_le;

    QTextEdit *m_edit;
    QString    m_text;
};

#endif // TEXTCHANGER_H
