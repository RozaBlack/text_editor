#include "textchanger.h"

TextChanger::TextChanger(QTextEdit* textEditor, QWidget *parent) :
    QWidget(parent),
    m_edit(textEditor)
{
    QGridLayout *layout = new QGridLayout(this);

    before_le     = new QLineEdit(this);
    after_le      = new QLineEdit(this);
    change_button = new QPushButton(tr("Change"), this);

    before_le->setPlaceholderText(tr("from:"));
    after_le->setPlaceholderText(tr("to:"));

    layout->addWidget(before_le, 0, 0, 1, 1);
    layout->addWidget(after_le, 1, 0, 1, 1);
    layout->addWidget(change_button, 1, 1, 1, 1);

    connect(change_button, SIGNAL(clicked()), this, SLOT(changeText()));

    setFixedSize(350, 100);
}

void TextChanger::changeText()
{
    QString main_text = m_edit->toPlainText();
    QString from_text = before_le->text();
    QString to_text   = after_le->text();

    main_text.replace(from_text, to_text);
    m_edit->setText(main_text);
}
