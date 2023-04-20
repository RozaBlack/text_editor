#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>
#include <QTextCharFormat>

class SyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit SyntaxHighlighter(QTextDocument *parent = nullptr);

    void searchText(const QString &text);

protected:
    void highlightBlock(const QString &text) override;
private:
    QRegularExpression pattern;
    QTextCharFormat    format;
};

#endif // SYNTAXHIGHLIGHTER_H
