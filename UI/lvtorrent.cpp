#include "lvtorrent.h"
#include "ui_lvtorrent.h"

LvTorrent::LvTorrent(QWidget *parent) : QMainWindow(parent), ui(new Ui::LvTorrent){
    ui->setupUi(this);
    m_SidebarAnimator= new QPropertyAnimation(ui->Sidebar, "maximumSize");

    connect(ui->Filter, &QAbstractButton::clicked, this, &LvTorrent::ToggleSidebar);
}

LvTorrent::~LvTorrent(){
    delete ui;
}

void LvTorrent::ShowSidebar(){
    m_SidebarAnimator->setDuration(1000);
    QSize dsize = ui->Sidebar->size();
    m_SidebarAnimator->setStartValue(dsize);
    dsize.setWidth(dsize.width()+150);
    m_SidebarAnimator->setEndValue(dsize);
    m_SidebarAnimator->setEasingCurve(QEasingCurve::OutBounce);
    m_SidebarAnimator->start();
}

void LvTorrent::HideSidebar(){
    m_SidebarAnimator->setDuration(1000);
    QSize dsize = ui->Sidebar->size();
    m_SidebarAnimator->setStartValue(dsize);
    dsize.setWidth(dsize.width()-150);
    m_SidebarAnimator->setEndValue(dsize);
    m_SidebarAnimator->setEasingCurve(QEasingCurve::OutBounce);
    m_SidebarAnimator->start();

}

void LvTorrent::ToggleSidebar(){
    if(m_SidebarAnimator->state() == QAbstractAnimation::Running) return;
    m_SidebarIsShown ? HideSidebar() : ShowSidebar();
    m_SidebarIsShown = !m_SidebarIsShown;
}
