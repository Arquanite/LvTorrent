#include "detailedtorrentinfo.h"

#include "libtorrent/torrent_info.hpp"
#include <QDebug>

DetailedTorrentInfo::DetailedTorrentInfo(){

}

DetailedTorrentInfo::DetailedTorrentInfo(lt::torrent_handle handle){
    handle.status();
}

void DetailedTorrentInfo::UpdateData(lt::torrent_handle handle){
    lt::torrent_status status = handle.status();

    // Downloaded pieces
    lt::bitfield bt = status.pieces;
    m_DownloadedPieces.reserve(bt.size());
    for(int i=0; i<bt.size(); i++){
        m_DownloadedPieces.push_back(bt[i]);
    }

    // Piece availability
    std::vector<int> avail;
    handle.piece_availability(avail);
    m_PieceAvailability = QVector<int>::fromStdVector(avail);

    // Files
    std::shared_ptr<const lt::torrent_info> ti = handle.torrent_file();
    if(ti == nullptr){
        m_FileNames.append(QObject::tr("No metadata..."));
        m_FileSizes_R.append(0);
    }

    for(auto i=0; i<ti->num_files(); i++){
        qDebug()<<QString::fromStdString(ti->files().file_path(i));
    }

}

QVector<bool> DetailedTorrentInfo::DownloadedPieces() const {
    return m_DownloadedPieces;
}

QVector<int> DetailedTorrentInfo::PieceAvailability() const {
    return m_PieceAvailability;
}

QVector<QString> DetailedTorrentInfo::Files() const {
    return m_Files;
}

QVector<size_t> DetailedTorrentInfo::FileSizes_R() const {
    return m_FileSizes_R;
}

QVector<QString> DetailedTorrentInfo::FileSizes() const {
    return m_FileSizes;
}

QVector<QString> DetailedTorrentInfo::FileSizesToStrings(QVector<size_t> Sizes){
    
}
