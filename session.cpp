#include "session.h"

Session::Session(QObject *parent) : QObject(parent){
    m_AppLocation = QApplication::applicationDirPath() + "/";
}

bool Session::AddTorrentFile(QString filePath, QString savePath){
    if(!QFile(filePath).exists()) return false;
    lt::add_torrent_params atp;
    atp.save_path = savePath.toStdString();
    std::shared_ptr<lt::torrent_info> ti(new lt::torrent_info(filePath.toStdString()));
    atp.ti = ti;
    lt::torrent_handle handle = m_Session.add_torrent(atp);
    QFile::copy(filePath, m_AppLocation + "Torrents/" + QString::fromStdString(handle.status().name) + ".torrent");
    m_Torrents.insert(QString::fromStdString(handle.status().name), QString::fromStdString(handle.status().save_path));
    return true;
}

bool Session::AddTorrentFile(QString filePath, QString savePath, QString resumeData){
    if(!QFile(filePath).exists()) return false;
    lt::add_torrent_params atp;
    atp.save_path = savePath.toStdString();
    std::shared_ptr<lt::torrent_info> ti(new lt::torrent_info(filePath.toStdString()));
    atp.ti = ti;

    std::ifstream ifs(resumeData.toStdString(), std::ios_base::binary);
    ifs.unsetf(std::ios_base::skipws);
    atp.resume_data.assign(std::istream_iterator<char>(ifs), std::istream_iterator<char>());

    lt::torrent_handle handle = m_Session.add_torrent(atp);
    QFile::copy(filePath, m_AppLocation + "Torrents/" + QString::fromStdString(handle.status().name) + ".torrent");
    m_Torrents.insert(QString::fromStdString(handle.status().name), QString::fromStdString(handle.status().save_path));
    return true;
}

void Session::AddMagnetLink(QString magnet, QString savePath){
    lt::add_torrent_params atp;
    atp.save_path = savePath.toStdString();
    atp.url = magnet.toStdString();
    //TODO: Magnet2Torrent
}

bool Session::PauseTorrent(int ID){
    if(ID >= m_Handles.size()) return false;
    m_Handles.at(ID).pause();
    return true;
}

bool Session::ResumeTorrent(int ID){
    if(ID >= m_Handles.size()) return false;
    m_Handles.at(ID).resume();
    return true;
}

bool Session::RemoveTorrent(int ID, bool deleteFiles){
    if(ID >= m_Handles.size()) return false;
    if(deleteFiles) m_Session.remove_torrent(m_Handles.at(ID), m_Session.delete_files);
    else m_Session.remove_torrent(m_Handles.at(ID));
    return true;
    //TODO: remove files
}

bool Session::SaveFastResumeData(){
    int counter = 0;
    m_Handles.fromStdVector(m_Session.get_torrents());
    Pause();
    for(auto H : m_Handles){
        if(!m_Torrents.contains(QString::fromStdString(H.status().name))){
            m_Torrents.insert(QString::fromStdString(H.status().name), QString::fromStdString(H.status().save_path));
        }
        if(!H.is_valid()) continue;
        if(!H.status().has_metadata) continue;
        if(!H.status().need_save_resume) continue;

        H.save_resume_data();
        counter++;
    }

    QFile File(m_AppLocation + "torrents.lv");
    File.open(QIODevice::WriteOnly);
    QDataStream out(&File);
    out<<m_Torrents;
    File.flush();
    File.close();

    while(counter > 0){
        std::vector<lt::alert*> alerts;
        m_Session.pop_alerts(&alerts);
        for(auto a : alerts){  //NOTE: This is shit :u
            if(auto rd = lt::alert_cast<lt::save_resume_data_alert>(a)){
                std::string resumeFile = m_AppLocation.toStdString() + "ResumeData/" + rd->handle.status().name+ ".resume";
                std::ofstream of(resumeFile, std::ios_base::binary);
                of.unsetf(std::ios_base::skipws);
                lt::bencode(std::ostream_iterator<char>(of), *rd->resume_data);
                counter--;
            }
        }
    }
    Resume();
    return true;
}

bool Session::LoadTorrents(){
    QFile File(m_AppLocation + "torrents.lv");
    if(!File.open(QIODevice::ReadOnly)) return false;
    QDataStream in(&File);
    in>>m_Torrents;
    File.close();
    for(QString S : m_Torrents.keys()){
        if(QFile(m_AppLocation + "Torrents/" + S + ".torrent").exists()){
            if(QFile(m_AppLocation + "ResumeData/" + S + ".resume").exists()){
                AddTorrentFile(m_AppLocation + "Torrents/" + S + ".torrent", m_Torrents.value(S), m_AppLocation + "ResumeData/" + S + ".resume");
            }
            else AddTorrentFile(m_AppLocation + "Torrents/" + S + ".torrent", m_Torrents.value(S));
        }
    }
    return true;
}

QVector<BasicTorrentInfo> Session::BasicInfo(){
    QVector<BasicTorrentInfo> Info;
    for(auto H : m_Handles){
        Info.append(BasicTorrentInfo(H));
    }
    return Info;
}

DetailedTorrentInfo Session::DetailedInfo(int ID){
    return DetailedTorrentInfo(m_Handles.at(ID));
}

void Session::Pause(){
    m_Session.pause();
}

void Session::Resume(){
    m_Session.resume();
}
