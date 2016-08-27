#include "lvtorrent.h"
#include "ui_lvtorrent.h"

LvTorrent::LvTorrent(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LvTorrent)
{
    ui->setupUi(this);
}

LvTorrent::~LvTorrent()
{
    delete ui;
}
