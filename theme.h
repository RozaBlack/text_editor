#ifndef THEME_H
#define THEME_H

#include <QObject>
#include <QPalette>

class Theme : public QObject
{
    Q_OBJECT
public:
    Theme(QObject* parent = nullptr);

signals:
    void setThemeSignal(QPalette);

public:
    void setTheme(int);

private:
    QPalette pal;

    QPalette setDarkPalette();
    QPalette setLightPalette();
};

#endif // THEME_H
