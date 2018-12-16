#include "wormcontroler.h"

// Constructor
WormControler::WormControler(QObject *parent)
    : QObject(parent)
{

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
    QModelIndex index = m_pModel->index(0);
    QPoint pt = m_pModel->data(index, WormModel::Point).toPoint();
    switch (key) {
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
