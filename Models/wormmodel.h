#ifndef WORMMODEL_H
#define WORMMODEL_H

#include "Utility/ringmem.h"
#include <QAbstractListModel>
#include <QPoint>


class WormModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Role { PointX=Qt::UserRole, PointY, Point };

    explicit WormModel(QObject *parent = nullptr);

    // QAbstractListModel interface
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void setHead(const QPoint& pt);

private:
    RingMem<QPoint> m_data;
    QHash<int, QByteArray> m_roles;
};

#endif // WORMMODEL_H
