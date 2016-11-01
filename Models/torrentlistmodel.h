#ifndef TORRENTLISTMODEL_H
#define TORRENTLISTMODEL_H

#include <QAbstractTableModel>

#include "basictorrentinfo.h"

class TorrentListModel : public QAbstractTableModel{
    Q_OBJECT
public:
    explicit TorrentListModel(QVector<BasicTorrentInfo>* info);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

public slots:
    void refresh();

private:
    int m_OldRowCount = 0;
    QVector<BasicTorrentInfo>* m_Info;
    QStringList m_Headers = {
        tr("Name"),
        tr("Size"),
        tr("Progress"),
        tr("State"),
        tr("Download speed"),
        tr("Upload speed"),
        tr("Seeds"),
        tr("Peers"),
        tr("Estimated time"),
    };
};

#endif // TORRENTLISTMODEL_H
