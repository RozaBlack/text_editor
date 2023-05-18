#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>
#include <QTextCharFormat>
#include <QTextBlock>
#include <QTextCursor>
#include <QTextEdit>

class SyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit SyntaxHighlighter(QTextEdit *editor = nullptr);

    void searchText(const QString &text);

protected:
    void highlightBlock(const QString &text) override;
private:
    QRegularExpression pattern;
    QTextCharFormat     format;
    QTextEdit        *m_editor;
    QTextCursor      m_tCursor;
};

#endif // SYNTAXHIGHLIGHTER_H
