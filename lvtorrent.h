#ifndef LVTORRENT_H
#define LVTORRENT_H

#include <QMainWindow>

namespace Ui {
class LvTorrent;
}

class LvTorrent : public QMainWindow
{
    Q_OBJECT

public:
    explicit LvTorrent(QWidget *parent = 0);
    ~LvTorrent();

private:
    Ui::LvTorrent *ui;
};

#endif // LVTORRENT_H
