#ifndef LVTORRENT_H
#define LVTORRENT_H

#include <QMainWindow>
#include <QPropertyAnimation>

#include "torrentlistmodel.h"

namespace Ui {
class LvTorrent;
}

class LvTorrent : public QMainWindow {
    Q_OBJECT

private:
    QPropertyAnimation *m_SidebarAnimator;
    bool m_SidebarIsShown = true;
    TorrentListModel *m_ListModel;

public:
    explicit LvTorrent(QWidget *parent = 0);
    ~LvTorrent();

public slots:
    void ShowSidebar();
    void HideSidebar();
    void ToggleSidebar();

private:
    Ui::LvTorrent *ui;
};

#endif // LVTORRENT_H
