#include "torrentlistmodel.h"

#include <QDebug>

TorrentListModel::TorrentListModel(QVector<BasicTorrentInfo> *info) : m_Info(info){

}

QVariant TorrentListModel::data(const QModelIndex &index, int role) const{
    if(role != Qt::DisplayRole) return QVariant();
    switch(index.column()){
        case 0:
            return m_Info->at(index.row()).Name();
        break;
        case 1:
            return m_Info->at(index.row()).Size();
        break;
        case 2:
            return m_Info->at(index.row()).Progress();
        break;
        case 3:
            return m_Info->at(index.row()).State();
        break;
        case 4:
            return m_Info->at(index.row()).DownloadRate();
        break;
        case 5:
            return m_Info->at(index.row()).UploadRate();
        break;
        case 6:
            return m_Info->at(index.row()).Seeds();
        break;
        case 7:
            return m_Info->at(index.row()).Peers();
        break;
        case 8:
            return m_Info->at(index.row()).EstimatedTime();
        break;

        default:
            return QVariant();
        break;
    }
}

QVariant TorrentListModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(orientation != Qt::Horizontal or role != Qt::DisplayRole) return QVariant();
    else return m_Headers[section];
}

int TorrentListModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;

    return m_Info->size();
}

int TorrentListModel::columnCount(const QModelIndex &parent) const {
    if(parent.isValid()) return 0;
    return m_Headers.size();
}

bool TorrentListModel::insertRows(int row, int count, const QModelIndex &parent){
    if(row < 0 or row >= rowCount() or count <= 0) return false;

    beginInsertRows(parent, row, row + count - 1);
    // There is nothing to be done because it works :)
    endInsertRows();
    return true;
}

bool TorrentListModel::removeRows(int row, int count, const QModelIndex &parent){
    if(row < 0 or row >= rowCount() or count <= 0 or count > rowCount()) return false;

    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me! but this may work as is...
    endRemoveRows();
    return true;
}

void TorrentListModel::refresh(){
    if(m_Info->size() > m_OldRowCount) insertRows(0,m_Info->size() - m_OldRowCount);
    m_OldRowCount = rowCount();
    emit dataChanged(index(0,0), index(rowCount(), columnCount()));
}
