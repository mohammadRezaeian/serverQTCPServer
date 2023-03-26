#ifndef GENERATOR_H
#define GENERATOR_H

#include <QObject>
#include <QtMath>
#include <QVector>

class generator : public QObject
{
    Q_OBJECT
public:
    explicit generator(QObject *parent = nullptr);
    QVector<double> getGenerated() const;

private:
    QVector<double> m_generated;

    void genereteNumbers();

signals:

};

#endif // GENERATOR_H
