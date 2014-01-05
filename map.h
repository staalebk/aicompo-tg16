#ifndef MAP_H
#define MAP_H

#include <QList>
#include <QObject>
#include <QPoint>

#include "tile.h"

class Player;

class Map : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int width READ width() CONSTANT)
    Q_PROPERTY(int height READ height() CONSTANT)
    Q_PROPERTY(QList<QObject*> tiles READ tiles() CONSTANT)
    Q_PROPERTY(QString name READ name() CONSTANT)

public:
    explicit Map(QObject *parent, const QString &mapName);

    int width();
    int height();

    bool isNull();
    bool isValid();

    QList<QObject*> tiles();

    const QList<QPoint> &startingPositions() const;

    bool isValidPosition(const QPoint &position) const;
    bool isWithinBounds(const QPoint &position) const;

    QByteArray mapData() const;
    QString name() const;

public slots:
    void detonateBomb(const QPoint &position);

signals:
    void explosionAt(QPoint position);

private:
    Tile *tileAt(const QPoint &position) const;
    void explodeTile(const QPoint &position);

    int m_width;
    int m_height;
    QList<QObject*> m_tiles;
    QList<QPoint> m_startingPositions;
    QByteArray m_mapData;
    QString m_name;
};

#endif // MAP_H
