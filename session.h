#ifndef SESSION_H
#define SESSION_H

#include <QTimer>
#include <QVector>
#include <QDataStream>
#include <QApplication>
#include <fstream>
#include "basictorrentinfo.h"
#include "detailedtorrentinfo.h"
#include "libtorrent/session.hpp"

namespace lt = libtorrent;

class Session : public QObject {
    Q_OBJECT
private:
    lt::session m_Session;
    QVector<int> m_TorrentsWithoutMetadata;
    QString m_AppLocation;
    QVector<lt::torrent_handle> m_Handles;
    QMap<QString, QString> m_Torrents;
    int m_Selected = 0;
    QVector<BasicTorrentInfo> m_BasicInfo;
    DetailedTorrentInfo m_DetailedInfo;
    QTimer m_Updater;

    bool MakeTorrentFromMagnet(int ID);
public:
    explicit Session(QObject *parent = 0);

    bool AddTorrentFile(QString filePath, QString savePath);
    bool AddTorrentFile(QString filePath, QString savePath, QString resumeData);
    void AddMagnetLink(QString magnet, QString savePath);

    bool PauseTorrent();
    bool ResumeTorrent();
    bool RemoveTorrent(bool deleteFiles = false);

    bool SaveFastResumeData();
    bool LoadTorrents();

    QVector<BasicTorrentInfo> *BasicInfo();
    DetailedTorrentInfo *DetailedInfo();

    void Pause();
    void Resume();

    int UpdateInterval();
    bool setUpdateInterval(int miliseconds);

public slots:
    void UpdateBasicInfo();
    void UpdateDetailedInfo();
signals:
    void BasicInfoUpdated();
    void DetailedInfoUpdated();
};

#endif // SESSION_H
