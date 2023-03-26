#include "generator.h"

generator::generator(QObject *parent)
    : QObject{parent}
{
    genereteNumbers();
}

QVector<double> generator::getGenerated() const
{
    return m_generated;
}

void generator::genereteNumbers()
{
    static int amp = 50; // بزرگی موج
    const int freq = 2; //فرکانس موج (تعداد دوره در ثانیه)
    static int num_of_cycles = 2; // تعداد دوره های ارتعاش
    const double phase = 0; // فاز اولیه
    const int num_of_samples = num_of_cycles * 100;
    double y_value;
    m_generated.resize(num_of_samples);

    for(int i = 0; i < num_of_cycles; i++)
    {
        for(float t = 0; t < 1; t += 0.01)
        {
            y_value = amp * sin(2 * M_PI * freq * t + phase);
            m_generated[i*100 + int(t*100)] = y_value;
        }
    }
}
