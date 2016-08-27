#ifndef BASICTORRENTINFO_H
#define BASICTORRENTINFO_H

#include <cstddef>  //size_t
#include <QString>

class BasicTorrentInfo {
public:
    BasicTorrentInfo();

    /* Raw data for use in some mathematical operations
     * all sizes are in bytes (B)
     * all speeds are in bits per seconds (b/s)
     * time is in seconds (s)
     * progress is a value between 0 and 1
     */

    size_t m_Size_R = 0;
    size_t m_TotalSize_R = 0;
    size_t m_Downloaded_R = 0;
    size_t m_Uploaded_R = 0;
    size_t m_ToDownload_R = 0;

    int m_DownloadRate_R = 0;
    int m_UploadRate_R = 0;
    int m_EstimatedTime_R = 0;

    float m_State_R = 0; //NOTE: What State_R does?
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
     * TODO: Documentation for State
     *
     * Progress is percentage value (e.g. 35.4%).
     */

    QString m_Name;
    QString m_SavePath;

    QString m_Size;
    QString m_TotalSize;
    QString m_Downloaded;
    QString m_ToDownload;
    QString m_Uploaded;

    QString m_DownloadRate;
    QString m_UploadRate;
    QString m_EstimatedTime;

    QString m_State;
    QString m_Progress;
    
    int m_Seeds = 0;
    int m_Peers = 0;


};

#endif // BASICTORRENTINFO_H
