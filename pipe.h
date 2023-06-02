#ifndef PIPE_H
#define PIPE_H

#include <QObject>

class Pipe : public QObject
{
    Q_OBJECT
public:
    explicit Pipe(QObject *parent = nullptr);

signals:

};

#endif // PIPE_H
