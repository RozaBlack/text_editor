#include "syntaxhighlighter.h"
#include <QDebug>
SyntaxHighlighter::SyntaxHighlighter(QTextEdit *editor) :
    QSyntaxHighlighter(editor->document()),
    m_editor(editor)
{

}

void SyntaxHighlighter::searchText(const QString &text)
{
    pattern = QRegularExpression(text);
    rehighlight();
}

void SyntaxHighlighter::highlightBlock(const QString &text)
{
    QRegularExpressionMatchIterator matchIterator = pattern.globalMatch(text);

    format.setBackground(Qt::yellow);

    while (matchIterator.hasNext())
    {
        QRegularExpressionMatch match = matchIterator.next();
        setFormat(match.capturedStart(), match.capturedLength(), format);
    }


}
