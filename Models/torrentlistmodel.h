#ifndef TORRENTLISTMODEL_H
#define TORRENTLISTMODEL_H

#include <QAbstractTableModel>

class TorrentListModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit TorrentListModel(QObject *parent = 0);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

private:
};

#endif // TORRENTLISTMODEL_H
