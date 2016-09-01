#include "basictorrentinfo.h"

BasicTorrentInfo::BasicTorrentInfo(){

}

BasicTorrentInfo::BasicTorrentInfo(libtorrent::torrent_handle handle){
    libtorrent::torrent_status status = handle.status();
    m_Size_R = status.total_wanted;
    m_Downloaded_R = status.total_wanted_done;
    m_ToDownload_R = m_Size_R - m_Downloaded_R;

    m_TotalDownload_R = status.all_time_download;
    m_TotalUpload_R = status.all_time_upload;

    m_DownloadRate_R = status.download_rate;
    m_UploadRate_R = status.upload_rate;
    m_EstimatedTime_R = m_ToDownload_R / m_DownloadRate_R;

    m_State_R = (TorrentState)status.state;
    if(status.paused) status.auto_managed ? m_State_R = InQueue : m_State_R = Paused;
    m_Progress_R = status.progress;

    m_Name = QString::fromStdString(status.name);
    m_SavePath = QString::fromStdString(status.save_path);

    m_Size = BytesToString(m_Size_R);
    m_Downloaded = BytesToString(m_Downloaded_R);
    m_ToDownload = BytesToString(m_ToDownload_R);

    m_TotalDownload = BytesToString(m_TotalDownload_R);
    m_TotalUpload = BytesToString(m_TotalUpload_R);

    m_DownloadRate = BytesToString(m_DownloadRate_R, true);
    m_UploadRate = BytesToString(m_UploadRate_R, true);
    m_EstimatedTime = SecondsToString(m_EstimatedTime_R);

    m_State = StateToString(m_State_R);
    m_Progress = PercentToString(m_Progress_R);

    m_Seeds = status.num_peers;
    m_Peers = status.num_seeds;
}

QString BasicTorrentInfo::BytesToString(size_t bytes, bool isSpeedUnit){
    QVector<QString> units = {"", "k", "M", "G", "T"};
    int unit = 0;
    bytes *= 10;
    while(bytes > 10240){
        bytes/=1024;
        unit++;
    }
    bytes /= 10;
    QString string = QString::number(bytes) + " " + units[unit];
    if(isSpeedUnit) string += "/s";
    return string;
}

QString BasicTorrentInfo::SecondsToString(int seconds){
    int minutes, hours, days;
    if(seconds >= 86400){ //there are 86400 seconds in a day
        days = seconds/86400;
        seconds %= 86400;
    }
    if(seconds >= 3600){ //there are 3600 seconds in a hour
        hours = seconds/3600;
        seconds %= 3600;
    }
    if(seconds >= 60){ //there are 60 seconds in a minute
        minutes = seconds/60;
        seconds %= 60;
    }
    QString string;
    if(days > 14) string = "∞";
    else if(days > 0) string = QString().number(days) + "d " + QString().number(hours) + "h";
    else if(hours > 0) string = QString().number(hours) + "h " + QString().number(minutes) + "m";
    else if(minutes > 0) string = QString().number(minutes) + "m " + QString().number(seconds) + "s";
    else if(seconds > 0) string = QString().number(seconds) + "s";
    else string = QObject::tr("Done");

    return string;
}

QString BasicTorrentInfo::PercentToString(float percent){
    int round = percent *1000;
    percent = round /100.0;
    return QString::number(percent) + "%";
}

QString BasicTorrentInfo::StateToString(TorrentState state){
    switch (state) {
        case QueuedForChecking:
            return QObject::tr("Queued for checking");
            break;

        case CheckingFiles:
            return QObject::tr("Checking files");
            break;

        case DownloadingMetadata:
            return QObject::tr("Downloading metadata");
            break;

        case Downloading:
            return QObject::tr("Downloading");
            break;

        case Finished:
            return QObject::tr("Finished");
            break;

        case Seeding:
            return QObject::tr("Seeding");
            break;

        case Allocating:
            return QObject::tr("Allocating");
            break;

        case CheckingResumeData:
            return QObject::tr("Checking resume data");
            break;

        case Paused:
            return QObject::tr("Paused");
            break;

        case InQueue:
            return QObject::tr("In queue");
            break;
        default:
            return QObject::tr("Unknown");
            break;
    }
}

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

QString BasicTorrentInfo::ToDownload() const {
    return m_ToDownload;
}

QString BasicTorrentInfo::Downloaded() const {
    return m_Downloaded;
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

int BasicTorrentInfo::State_R() const {
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

size_t BasicTorrentInfo::Downloaded_R() const {
    return m_Downloaded_R;
}

size_t BasicTorrentInfo::Size_R() const {
    return m_Size_R;
}

size_t BasicTorrentInfo::TotalDownload_R() const {
    return m_TotalDownload_R;
}

size_t BasicTorrentInfo::TotalUpload_R() const {
    return m_TotalUpload_R;
}

QString BasicTorrentInfo::TotalDownload() const {
    return m_TotalDownload;
}

QString BasicTorrentInfo::TotalUpload() const {
    return m_TotalUpload;
}
