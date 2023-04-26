#include "fontmanager.h"
#include <QDebug>

FontManager::FontManager()
{

}

void FontManager::fontSizeChanged(QTextEdit *main_text,QString style,int fontSize)
{
    cursor = main_text->textCursor();
    font = main_text->font();

    format.setFontPointSize(fontSize);
    cursor.mergeCharFormat(format);
    format.setFontFamily(style);

    font.setPointSize(fontSize);
    font.setFamily(style);

    main_text->mergeCurrentCharFormat(format);
    main_text->setFont(font);
}

void FontManager::setBold(QTextEdit *main_text)
{
    cursor = main_text->textCursor();
    font = main_text->font();

    if(!isBold){
        format.setFontWeight(QFont::Bold);
        font.setBold(true);
        isBold = true;
    }else{
        format.setFontWeight(QFont::Normal);
        font.setBold(false);
        isBold = false;
    }

    cursor.mergeCharFormat(format);
    main_text->mergeCurrentCharFormat(format);

}

void FontManager::setItalic(QTextEdit *main_text)
{
    cursor = main_text->textCursor();
    font = main_text->font();
    if(!isItalic){
        format.setFontItalic(true);
        font.setItalic(true);
        isItalic = true;
    }else{
        format.setFontItalic(false);
        font.setItalic(false);
        isItalic = false;
    }

    cursor.mergeCharFormat(format);
    main_text->mergeCurrentCharFormat(format);

}

void FontManager::setUnderlined(QTextEdit *main_text)
{
    cursor = main_text->textCursor();
    font = main_text->font();
    if(!isUnderlined){
        format.setFontUnderline(true);
        font.setUnderline(true);
        isUnderlined = true;
    }else{
        format.setFontUnderline(false);
        font.setUnderline(false);
        isUnderlined = false;
    }

    cursor.mergeCharFormat(format);
    main_text->mergeCurrentCharFormat(format);
    main_text->setFont(font);
}

void FontManager::setStrikeOut(QTextEdit *main_text)
{
    cursor = main_text->textCursor();
    font = main_text->font();
    if(!isStrikeOut){
        format.setFontStrikeOut(true);
        font.setStrikeOut(true);
        isStrikeOut = true;
    }else{
        format.setFontStrikeOut(false);
        font.setStrikeOut(false);
        isStrikeOut = false;
    }

    cursor.mergeCharFormat(format);
    main_text->setFont(font);
    main_text->mergeCurrentCharFormat(format);
}
