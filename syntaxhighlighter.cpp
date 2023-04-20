#include "syntaxhighlighter.h"

SyntaxHighlighter::SyntaxHighlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
    format.setBackground(Qt::yellow);
}

void SyntaxHighlighter::searchText(const QString &text)
{
    pattern = QRegularExpression(text);
    rehighlight();
}

void SyntaxHighlighter::highlightBlock(const QString &text)
{
    QRegularExpressionMatchIterator matchIterator = pattern.globalMatch(text);

    while (matchIterator.hasNext())
    {
        QRegularExpressionMatch match = matchIterator.next();
        setFormat(match.capturedStart(), match.capturedLength(), format);
    }
}
