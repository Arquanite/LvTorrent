#ifndef LVTORRENT_H
#define LVTORRENT_H

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QFileDialog>

#include "torrentlistmodel.h"
#include "session.h"

namespace Ui {
class LvTorrent;
}

namespace View {
    enum Filter{
        All,
        Downloading,
        Seeding,
        Finished,
        Waiting
    };
}


class LvTorrent : public QMainWindow {
    Q_OBJECT

private:
    QPropertyAnimation *m_SidebarAnimator;
    bool m_SidebarIsShown = true;
    TorrentListModel *m_ListModel;
    Session m_Session;

public:
    explicit LvTorrent(QWidget *parent = 0);
    ~LvTorrent();

public slots:
    void ShowSidebar();
    void HideSidebar();
    void ToggleSidebar();

    void SetFilter(View::Filter filter);
    void AddTorrentFile();
    void AddMagnetLink();

    void ResumeTorrent();
    void PauseTorrent();



private:
    Ui::LvTorrent *ui;
};

#endif // LVTORRENT_H
