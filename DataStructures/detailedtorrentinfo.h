#ifndef DETAILEDTORRENTINFO_H
#define DETAILEDTORRENTINFO_H

#include "libtorrent/torrent_handle.hpp"
#include "libtorrent/torrent_status.hpp"

class DetailedTorrentInfo {
public:
    DetailedTorrentInfo();
    DetailedTorrentInfo(libtorrent::torrent_handle handle);
    void UpdateData(libtorrent::torrent_handle handle);
    //TODO: Implement DetailedTorrentInfo class
};

#endif // DETAILEDTORRENTINFO_H
