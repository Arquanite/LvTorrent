#ifndef TOOLBARBUTTON_H
#define TOOLBARBUTTON_H

#include <QToolButton>

class ToolbarButton : public QToolButton {
public:
    ToolbarButton(QWidget* parent = 0);
private:
    void enterEvent(QEvent * event);
    void leaveEvent(QEvent * event);
public slots:
    void buttonPressed();
    void buttonReleased();
};

#endif // TOOLBARBUTTON_H
