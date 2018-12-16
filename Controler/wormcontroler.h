#ifndef WORMCONTROLER_H
#define WORMCONTROLER_H

#include "Models/wormmodel.h"
#include <QObject>
#include <QTimer>

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

private slots:
    void move();

private:
    WormModel* m_pModel;
    QTimer* m_pTimer;
    int m_lastKey;
    int m_time;
};

#endif // WORMCONTROLER_H
