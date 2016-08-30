#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include <QVector>
#include "basictorrentinfo.h"
#include "detailedtorrentinfo.h"

class Session : public QObject {
    Q_OBJECT
private:
    QVector<BasicTorrentInfo> m_BasicInfo; //NOTE: ???
    bool MakeTorrentFromMagnet(int ID);

public:
    explicit Session(QObject *parent = 0);

    bool AddTorrentFile(QString filePath, QString savePath);
    bool AddMagnetLink(QString magnet, QString savePath);
    bool RemoveTorrent();

    bool SaveFastResumeData();
    bool LoadTorrents();

    QVector<BasicTorrentInfo>* BasicInfo();
    DetailedTorrentInfo* DetailedInfo(int ID);

    bool Pause();
    bool Start();

signals:
    void AddedTorrent(int ID);
    void RemovedTorrent(int ID);
    void ReceivedMetadata(int ID);
public slots:
};

#endif // SESSION_H
