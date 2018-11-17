#ifndef WORM_H
#define WORM_H

#include <QObject>
#include <QRect>

class Worm : public QObject
{
    enum MaxWormLength { MaxLength = 200 };

    Q_OBJECT
public:
    explicit Worm(QObject *parent = nullptr);

signals:

public slots:

private:
    QRect m_segment[MaxLength];
    int m_lengthUnit;
    int m_level;
};

#endif // WORM_H
