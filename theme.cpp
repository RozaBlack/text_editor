#include "theme.h"

Theme::Theme(QObject* parent) : QObject(parent)
{

}

void Theme::setTheme(int theme)
{
    switch (theme)
    {
    case 1:
        emit setThemeSignal(setLightPalette());
        break;

    case 2:
        emit setThemeSignal(setDarkPalette());
        break;
    }
}

QPalette Theme::setDarkPalette()
{
    pal.setColor(QPalette::Window, QColor(53, 53, 53));
    pal.setColor(QPalette::WindowText, Qt::white);
    pal.setColor(QPalette::Base, QColor(25, 25, 25));
    pal.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    pal.setColor(QPalette::ToolTipBase, Qt::white);
    pal.setColor(QPalette::ToolTipText, Qt::white);
    pal.setColor(QPalette::Text, Qt::white);
    pal.setColor(QPalette::Button, QColor(53, 53, 53));
    pal.setColor(QPalette::ButtonText, Qt::white);
    //pal->setColor(QPalette::BrightText, Qt::red);
    pal.setColor(QPalette::Link, QColor(42, 130, 218));

    return pal;
}

QPalette Theme::setLightPalette()
{
    pal.setColor(QPalette::Window, QColor(255,255,255));
    pal.setColor(QPalette::WindowText, Qt::black);
    pal.setColor(QPalette::Base, QColor(255, 255, 255));
    pal.setColor(QPalette::AlternateBase, QColor(255,255,255));
    pal.setColor(QPalette::ToolTipBase, Qt::black);
    pal.setColor(QPalette::ToolTipText, Qt::black);
    pal.setColor(QPalette::Text, Qt::black);
    pal.setColor(QPalette::Button, QColor(255,255,255));
    pal.setColor(QPalette::ButtonText, Qt::black);
    //pal->setColor(QPalette::BrightText, Qt::red);
    pal.setColor(QPalette::Link, QColor(42, 130, 218));

    return pal;
}

