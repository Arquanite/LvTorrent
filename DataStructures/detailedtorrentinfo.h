#ifndef DETAILEDTORRENTINFO_H
#define DETAILEDTORRENTINFO_H

#include "libtorrent/torrent_handle.hpp"
#include "libtorrent/torrent_status.hpp"

class DetailedTorrentInfo {
public:
    DetailedTorrentInfo();
    DetailedTorrentInfo(libtorrent::torrent_handle lol);
};

#endif // DETAILEDTORRENTINFO_H
