#include "torrentlistmodel.h"

TorrentListModel::TorrentListModel(QObject *parent) : QAbstractTableModel(parent){

}

QVariant TorrentListModel::data(const QModelIndex &index, int role) const{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}

QVariant TorrentListModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(orientation != Qt::Horizontal || role != Qt::DisplayRole) return QVariant();
    switch(section){
    case 0: return tr("Name");
    case 1: return tr("Size");
    case 2: return tr("Progress");
    case 3: return tr("Download speed");
    case 4: return tr("Upload speed");
    case 5: return tr("Seeds");
    case 6: return tr("Peers");
    case 7: return tr("Estimated time");
    default: return QVariant();
    }
}

int TorrentListModel::rowCount(const QModelIndex &parent) const {
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int TorrentListModel::columnCount(const QModelIndex &parent) const {
    if (!parent.isValid())
        return 8;

    // FIXME: Implement me!
}

bool TorrentListModel::insertRows(int row, int count, const QModelIndex &parent){
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();
}

bool TorrentListModel::removeRows(int row, int count, const QModelIndex &parent){
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
}
