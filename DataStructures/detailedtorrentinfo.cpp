#include "detailedtorrentinfo.h"

DetailedTorrentInfo::DetailedTorrentInfo()
{

}

DetailedTorrentInfo::DetailedTorrentInfo(libtorrent::torrent_handle handle)
{
    handle.status();
}

void DetailedTorrentInfo::UpdateData(libtorrent::torrent_handle handle)
{

}
