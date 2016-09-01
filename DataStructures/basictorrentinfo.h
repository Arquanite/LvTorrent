#ifndef BASICTORRENTINFO_H
#define BASICTORRENTINFO_H

#include <libtorrent/torrent_handle.hpp>
#include <libtorrent/torrent_status.hpp>
#include <cstddef>  //size_t
#include <QVector>
#include <QString>
#include <QObject> //tr()

enum TorrentState {
    QueuedForChecking,
    CheckingFiles,
    DownloadingMetadata,
    Downloading,
    Finished,
    Seeding,
    Allocating,
    CheckingResumeData,
    Paused,
    InQueue
};

class BasicTorrentInfo {

private:
    /* Raw data for use in some mathematical operations
     * all sizes are in bytes (B)
     * all speeds are in bits per seconds (b/s)
     * time is in seconds (s)
     * progress is a value between 0 and 1
     */

    size_t m_Size_R = 0;
    size_t m_Downloaded_R = 0;
    size_t m_ToDownload_R = 0;

    size_t m_TotalDownload_R = 0;
    size_t m_TotalUpload_R = 0;

    int m_DownloadRate_R = 0;
    int m_UploadRate_R = 0;
    int m_EstimatedTime_R = 0;

    TorrentState m_State_R = Paused;
    float m_Progress_R = 0;

    /* Human-readable data for use in UI
     * there is also raw data (like peers count)
     * that is readable and there is no need for processing it.
     *
     * All sizes are dynamically converted into higher
     * unit (e.g. kB to MB) when it becomes bigger than 1024.
     *
     * All speeds are in BYTES per seconds and dynamically
     * converted into higher unit (e.g. kB/s to MB/s)
     * when it becomes bigger than 1024.
     *
     * Prefixes are up to Tera (k, M, G, T).
     *
     * Time is converted into bigger units just like previous
     * but uses different notation:
     * s for seconds
     * m for minutes
     * h for hours
     * d for days
     * w for weeks.
     * If time is bigger than 2 weeks it change to infinity (∞).
     * If time is bigger than 60 seconds it is always displayed
     * with two units - higher and lower (e.g. 5m 23s or 5d 17h).
     *
     * State is string representation of State_R (enum TorrentState).
     *
     * Progress is percentage value (e.g. 35.4%).
     */

    QString m_Name;
    QString m_SavePath;

    QString m_Size;
    QString m_Downloaded;
    QString m_ToDownload;

    QString m_TotalDownload;
    QString m_TotalUpload;

    QString m_DownloadRate;
    QString m_UploadRate;
    QString m_EstimatedTime;

    QString m_State;
    QString m_Progress;
    
    int m_Seeds = 0;
    int m_Peers = 0;

public:
    BasicTorrentInfo();
    BasicTorrentInfo(libtorrent::torrent_handle handle);
    static QString BytesToString(size_t bytes, bool isSpeedUnit = false);
    static QString SecondsToString(int seconds);
    static QString PercentToString(float percent);
    static QString StateToString(TorrentState state);

    //Raw data
    size_t Size_R() const;
    size_t Downloaded_R() const;
    size_t ToDownload_R() const;

    size_t TotalDownload_R() const;
    size_t TotalUpload_R() const;

    int DownloadRate_R() const;
    int UploadRate_R() const;
    int EstimatedTime_R() const;

    int State_R() const;
    float Progress_R() const;

    //Human-readable data
    QString Name() const;
    QString SavePath() const;

    QString Size() const;
    QString Downloaded() const;
    QString ToDownload() const;

    QString TotalDownload() const;
    QString TotalUpload() const;

    QString DownloadRate() const;
    QString UploadRate() const;
    QString EstimatedTime() const;

    QString State() const;
    QString Progress() const;

    int Seeds() const;
    int Peers() const;

};

#endif // BASICTORRENTINFO_H
