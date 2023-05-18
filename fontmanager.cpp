#include "fontmanager.h"
#include <QDebug>

FontManager::FontManager()
{

}

void FontManager::fontSizeChanged(QTextEdit *main_text,QString style,int fontSize)
{
    cursor = main_text->textCursor();
    format.setFontPointSize(fontSize);
    cursor.mergeCharFormat(format);
    format.setFontFamily(style);

    main_text->mergeCurrentCharFormat(format);
}

void FontManager::setBold(QTextEdit *main_text)
{
    cursor = main_text->textCursor();

    if(!isBold){
        format.setFontWeight(QFont::Bold);
        isBold = true;
    }else{
        format.setFontWeight(QFont::Normal);
        isBold = false;
    }

    cursor.mergeCharFormat(format);
    main_text->mergeCurrentCharFormat(format);
}

void FontManager::setItalic(QTextEdit *main_text)
{
    cursor = main_text->textCursor();

    if(!isItalic){
        format.setFontItalic(true);
        isItalic = true;
    }else{
        format.setFontItalic(false);
        isItalic = false;
    }

    cursor.mergeCharFormat(format);
    main_text->mergeCurrentCharFormat(format);

}

void FontManager::setUnderlined(QTextEdit *main_text)
{
    cursor = main_text->textCursor();

    if(!isUnderlined){
        format.setFontUnderline(true);
        isUnderlined = true;
    }else{
        format.setFontUnderline(false);
        isUnderlined = false;
    }

    cursor.mergeCharFormat(format);
    main_text->mergeCurrentCharFormat(format);
}

void FontManager::setStrikeOut(QTextEdit *main_text)
{
    cursor = main_text->textCursor();

    if(!isStrikeOut){
        format.setFontStrikeOut(true);
        isStrikeOut = true;
    }else{
        format.setFontStrikeOut(false);
        isStrikeOut = false;
    }

    cursor.mergeCharFormat(format);
    main_text->mergeCurrentCharFormat(format);
}
