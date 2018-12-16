#ifndef WORMMODEL_H
#define WORMMODEL_H

#include <QAbstractListModel>

class WormModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit WormModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
};

#endif // WORMMODEL_H