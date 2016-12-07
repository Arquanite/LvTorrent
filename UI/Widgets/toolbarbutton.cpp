#include "toolbarbutton.h"

ToolbarButton::ToolbarButton(QWidget* parent){
    Q_UNUSED(parent);
    setStyleSheet("background-color: rgba(255, 255, 255, 0); border: none;");
    connect(this,&QAbstractButton::pressed, this, &ToolbarButton::buttonPressed);
    connect(this, &QAbstractButton::released, this, &ToolbarButton::buttonReleased);
    setFocusPolicy(Qt::NoFocus);
}

void ToolbarButton::enterEvent(QEvent *event){
    Q_UNUSED(event);
    setIcon(QIcon(":/Resources/Icons/Toolbar/Hover/"+objectName()+".png"));
}

void ToolbarButton::leaveEvent(QEvent *event){
    Q_UNUSED(event);
    setIcon(QIcon(":/Resources/Icons/Toolbar/Normal/"+objectName()+".png"));
}

void ToolbarButton::buttonPressed(){
    setIcon(QIcon(":/Resources/Icons/Toolbar/Pressed/"+objectName()+".png"));
}

void ToolbarButton::buttonReleased(){
    setIcon(QIcon(":/Resources/Icons/Toolbar/Hover/"+objectName()+".png"));
}
