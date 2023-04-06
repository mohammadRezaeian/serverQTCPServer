#ifndef GENERATOR_H
#define GENERATOR_H

#include <QObject>
#include <QtMath>
#include <QVector>
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QElapsedTimer>
#include <QCoreApplication>

class Generator : public QObject
{
    Q_OBJECT
public:
    explicit Generator(QObject *parent = nullptr);
    ~Generator();
//    QVector<double> getGenerated() const;

    bool status() const;
    void setStatus(bool newStatus);

private:
    void genereteNumbers();
    QTimer *m_timer;
    void checkUpperThan(const QVector<double> &_vector);
    bool m_status{true};
signals:
    void dataCreated(double _generated);

};

#endif // GENERATOR_H
