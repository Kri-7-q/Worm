#include "wormcontroler.h"

// Constructor
WormControler::WormControler(QObject *parent)
    : QObject(parent),
      m_pTimer(new QTimer(this)),
      m_lastKey(Qt::Key_Down),
      m_time(200)
{
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(move()));
}

WormModel* WormControler::model() const
{
    return m_pModel;
}

void WormControler::setModel(WormModel* pModel)
{
    if (m_pModel != pModel) {
        m_pModel = pModel;
        emit modelChanged();
    }
}

void WormControler::keyPressed(const int key)
{
    if (key==Qt::Key_Up || key==Qt::Key_Down || key==Qt::Key_Left || key==Qt::Key_Right) {
        m_lastKey = key;
        return;
    }
    if (key==Qt::Key_S) {
        m_pTimer->stop();
        return;
    }
    if (key==Qt::Key_P) {
        m_pTimer->start(m_time);
        return;
    }
}

void WormControler::move()
{
    QModelIndex index = m_pModel->index(0);
    QPoint pt = m_pModel->data(index, WormModel::Point).toPoint();
    switch (m_lastKey) {
    case Qt::Key_Up:
        pt.setY( pt.y()-8 );
        break;
    case Qt::Key_Down:
        pt.setY( pt.y()+8 );
        break;
    case Qt::Key_Left:
        pt.setX( pt.x()-8 );
        break;
    case Qt::Key_Right:
        pt.setX( pt.x()+8 );
        break;
    }
    m_pModel->setHead(pt);
}
