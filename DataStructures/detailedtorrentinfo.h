#ifndef DETAILEDTORRENTINFO_H
#define DETAILEDTORRENTINFO_H

#include "libtorrent/torrent_handle.hpp"
#include "libtorrent/torrent_status.hpp"

#include "basictorrentinfo.h"

#include <QVector>

namespace lt = libtorrent;

class DetailedTorrentInfo {
private:
    QVector<bool> m_DownloadedPieces;
    QVector<int> m_PieceAvailability;
    QVector<QString> m_Files;

    QVector<size_t> m_FileSizes_R;
    QVector<QString> m_FileSizes;
    QVector<QString> m_FileNames;

    QVector<QString> FileSizesToStrings(QVector<size_t> Sizes);

public:
    DetailedTorrentInfo();
    DetailedTorrentInfo(lt::torrent_handle handle);
    void UpdateData(lt::torrent_handle handle);

    QVector<bool> DownloadedPieces() const;
    QVector<int> PieceAvailability() const;
    QVector<QString> Files() const;
    QVector<size_t> FileSizes_R() const;
    QVector<QString> FileSizes() const;
};

#endif // DETAILEDTORRENTINFO_H
