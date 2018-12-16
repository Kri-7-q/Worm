#ifndef WORMCONTROLER_H
#define WORMCONTROLER_H

#include "Models/wormmodel.h"
#include <QObject>

class WormControler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(WormModel* model READ model WRITE setModel NOTIFY modelChanged)

public:
    explicit WormControler(QObject *parent = nullptr);

    WormModel* model() const;
    void setModel(WormModel* pModel);

signals:
    void modelChanged();

public slots:
    void keyPressed(const int key);

private:
    WormModel* m_pModel;
};

#endif // WORMCONTROLER_H
