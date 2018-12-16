#include "wormmodel.h"

// Constructor
WormModel::WormModel(QObject *parent)
    : QAbstractListModel(parent)
    , m_data(10)
{
    m_roles.insert(PointX, QString("pointX").toLatin1());
    m_roles.insert(PointY, QString("pointY").toLatin1());
    m_roles.insert(Point, QString("point").toLatin1());

    // Just for testing MUST be removed later
    QPoint pt(200, 200);
    while (m_data.capacity() > m_data.size()) {
        setHead(pt);
        pt.setY( pt.y()+8 );
    }
}

// Override
// QAbstractListModel:  rowCount()
int WormModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_data.size());
}

// Override
// QAbstractListModel:  data()
QVariant WormModel::data(const QModelIndex &index, int role) const
{
    const QPoint& pt = m_data.at(static_cast<unsigned>(index.row()));
    QVariant val = QVariant();
    switch (role) {
    case PointX:
        val.setValue( pt.x() );
        break;
    case PointY:
        val.setValue( pt.y() );
        break;
    case Point:
        val.setValue(pt);
        break;
    }

    return val;
}

// Override
// QAbstractListModel:  roleNames()
QHash<int, QByteArray> WormModel::roleNames() const
{
    return m_roles;
}

// Set a new head position.
void WormModel::setHead(const QPoint &pt)
{
//    beginInsertRows(index(0), 0 , 0);
    m_data << pt;
//    endInsertRows();
    int last = static_cast<int>( m_data.size() - 1 );
//    beginRemoveRows(index(last), last, last);
//    endRemoveRows();
    dataChanged(index(0), index(last), QVector<int>() << Point << PointX << PointY);
}
