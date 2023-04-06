#include "generator.h"
#define PI_NUMBER   3.14
#define FREQUENCY   0.5
#define INTERVAL    0.00555
#define AMPLITUDE   4

Generator::Generator(QObject *parent)
    : QObject{parent}
{
    m_timer = new QTimer(this);
    connect(m_timer , &QTimer::timeout , this , &Generator::genereteNumbers);
    m_timer->start(6);
}


void Generator::genereteNumbers()
{
    static float saveInterval = 0;

    if(m_status)
    {

        double _numbers;

        _numbers = AMPLITUDE * qSin(2 * PI_NUMBER * FREQUENCY * (saveInterval) ) + AMPLITUDE;
        saveInterval += INTERVAL;

        emit dataCreated(_numbers);
    }
    else
    {
        saveInterval = 0;
        double _numbers = 0;
        emit dataCreated(_numbers);
    }

}

bool Generator::status() const
{
    return m_status;
}

void Generator::setStatus(bool newStatus)
{
    m_status = newStatus;
}
Generator::~Generator()
{
    m_timer->stop();
    delete m_timer;
}
