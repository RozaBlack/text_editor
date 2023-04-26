#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <QFont>
#include <QTextEdit>
#include <QTextCharFormat>
#include <QTextCursor>

class FontManager
{
public:
    FontManager();

    void fontSizeChanged(QTextEdit*,QString,int);
    void setBold(QTextEdit*);
    void setItalic(QTextEdit*);
    void setUnderlined(QTextEdit*);
    void setStrikeOut(QTextEdit*);

private:
    bool isBold       = false;
    bool isItalic     = false;
    bool isUnderlined = false;
    bool isStrikeOut = false;

    QFont font;
    QTextCharFormat format;
    QTextCursor cursor;
};

#endif // FONTMANAGER_H
