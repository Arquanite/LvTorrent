#include "lvtorrent.h"
#include "ui_lvtorrent.h"

#include <QScrollBar>
#include <QDebug>
#include <QSpacerItem>

LvTorrent::LvTorrent(QWidget *parent) : QMainWindow(parent), ui(new Ui::LvTorrent){
    ui->setupUi(this);
    m_SidebarAnimator = new QPropertyAnimation(ui->Sidebar, "maximumSize");

    connect(ui->Filter, &QAbstractButton::clicked, this, &LvTorrent::ToggleSidebar);
    m_ListModel = new TorrentListModel(m_Session.BasicInfo());
    connect(&m_Session, SIGNAL(BasicInfoUpdated()), m_ListModel, SLOT(refresh()));
    ui->TorrentList->setModel(m_ListModel);
    ui->TorrentList->horizontalScrollBar()->setStyleSheet("QScrollBar {"
                                                            "background: #eeeeee;"
                                                            "height: 8px;}"
                                                          "QScrollBar::handle {"
                                                            "background: #424242;"
                                                            "margin: 1px 1px 1px 1px;"
                                                            "border-radius: 3px;}"
                                                          "QScrollBar::add-page {"
                                                            "background: none;}"
                                                          "QScrollBar::sub-page {"
                                                            "background: none;}"
                                                          "QScrollBar::add-line {"
                                                            "border: none;"
                                                            "background: none;}"
                                                          "QScrollBar::sub-line {"
                                                            "border: none;"
                                                            "background: none;}");

    // make connections

    // session signals
    connect(&m_Session, &Session::BasicInfoUpdated, m_ListModel, &TorrentListModel::refresh);
    //connect(&m_Session, &Session::DetailedInfoUpdated, m_ListModel, &TorrentListModel::refresh);
    // TODO: connect detailed info updates

    // ui signals
    connect(ui->AddTorrent, &ToolbarButton::clicked, this, &LvTorrent::AddTorrentFile);
    connect(ui->Limits, &ToolbarButton::clicked, this, &LvTorrent::AddMagnetLink);
}

LvTorrent::~LvTorrent(){
    delete m_ListModel;
    delete m_SidebarAnimator;
    delete ui;
}

void LvTorrent::ShowSidebar(){
    m_SidebarAnimator->setDuration(1000);
    QSize dsize = ui->Sidebar->maximumSize();
    m_SidebarAnimator->setStartValue(dsize);
    dsize.setWidth(dsize.width()+150);
    m_SidebarAnimator->setEndValue(dsize);
    m_SidebarAnimator->setEasingCurve(QEasingCurve::OutBounce);
    m_SidebarAnimator->start();
}

void LvTorrent::HideSidebar(){
    m_SidebarAnimator->setDuration(1000);
    QSize dsize = ui->Sidebar->maximumSize();
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

void LvTorrent::SetFilter(View::Filter filter){
    Q_UNUSED(filter);
    //TODO: Implement SetFilter()
}

void LvTorrent::AddTorrentFile(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select .torrent file"), 0, tr("torrent files (*.torrent)"));
    QString savePath = QFileDialog::getExistingDirectory(this, "Where you want to save downloaded files?");
    m_Session.AddTorrentFile(fileName, savePath);
    m_ListModel->refresh();
}

void LvTorrent::AddMagnetLink(){
    //TODO: Implement AddMagnetLink()
    m_Session.UpdateBasicInfo();
    m_ListModel->refresh();
}

void LvTorrent::ResumeTorrent(){
    //TODO: Implement ResumeTorrent()
}

void LvTorrent::PauseTorrent(){
    //TODO: Implement me PauseTorrent();
}

void LvTorrent::UpdateAll(){
    m_Session.UpdateBasicInfo();
    m_ListModel->refresh();
}
