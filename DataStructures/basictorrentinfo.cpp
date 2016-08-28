#include "basictorrentinfo.h"

int BasicTorrentInfo::Peers() const {
    return m_Peers;
}

int BasicTorrentInfo::Seeds() const {
    return m_Seeds;
}

QString BasicTorrentInfo::Progress() const {
    return m_Progress;
}

QString BasicTorrentInfo::State() const {
    return m_State;
}

QString BasicTorrentInfo::EstimatedTime() const {
    return m_EstimatedTime;
}

QString BasicTorrentInfo::UploadRate() const {
    return m_UploadRate;
}

QString BasicTorrentInfo::DownloadRate() const {
    return m_DownloadRate;
}

QString BasicTorrentInfo::Uploaded() const {
    return m_Uploaded;
}

QString BasicTorrentInfo::ToDownload() const {
    return m_ToDownload;
}

QString BasicTorrentInfo::Downloaded() const {
    return m_Downloaded;
}

QString BasicTorrentInfo::TotalSize() const {
    return m_TotalSize;
}

QString BasicTorrentInfo::Size() const {
    return m_Size;
}

QString BasicTorrentInfo::SavePath() const {
    return m_SavePath;
}

QString BasicTorrentInfo::Name() const {
    return m_Name;
}

float BasicTorrentInfo::Progress_R() const {
    return m_Progress_R;
}

float BasicTorrentInfo::State_R() const {
    return m_State_R;
}

int BasicTorrentInfo::EstimatedTime_R() const {
    return m_EstimatedTime_R;
}

int BasicTorrentInfo::UploadRate_R() const {
    return m_UploadRate_R;
}

int BasicTorrentInfo::DownloadRate_R() const {
    return m_DownloadRate_R;
}

size_t BasicTorrentInfo::ToDownload_R() const {
    return m_ToDownload_R;
}

size_t BasicTorrentInfo::Uploaded_R() const {
    return m_Uploaded_R;
}

size_t BasicTorrentInfo::Downloaded_R() const {
    return m_Downloaded_R;
}

size_t BasicTorrentInfo::TotalSize_R() const {
    return m_TotalSize_R;
}

size_t BasicTorrentInfo::Size_R() const {
    return m_Size_R;
}
