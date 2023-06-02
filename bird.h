#ifndef BIRD_H
#define BIRD_H

#include <QObject>

class Bird : public QObject
{
    Q_OBJECT
public:
    explicit Bird(QObject *parent = nullptr);

signals:

};

#endif // BIRD_H
