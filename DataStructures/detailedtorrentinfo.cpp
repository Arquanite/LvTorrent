#include "detailedtorrentinfo.h"

DetailedTorrentInfo::DetailedTorrentInfo()
{

}

DetailedTorrentInfo::DetailedTorrentInfo(libtorrent::torrent_handle lol)
{
    lol.status();
}
