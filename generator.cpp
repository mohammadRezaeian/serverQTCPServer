#include "generator.h"
#define PI 3.14159265358979323846
#define FrameNum 300

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

    //    static int amp = 50; // بزرگی موج
    //    const int freq = 2; //فرکانس موج (تعداد دوره در ثانیه)
    //    static int num_of_cycles = 2; // تعداد دوره های ارتعاش
    //    const double phase = 0; // فاز اولیه
    //    const int num_of_samples = num_of_cycles * 100;
    //    double y_value;
    //    m_generated.resize(num_of_samples);

    //    for(int i = 0; i < num_of_cycles; i++)
    //    {
    //        for(float t = 0; t < 1; t += 0.01)
    //        {
    //            y_value = amp * sin(2 * M_PI * freq * t + phase);
    //            m_generated[i*100 + int(t*100)] = y_value;
    //        }
    //    }



    using namespace std;

    const int NUM_OF_CYCLES = 2;
    const int AMP = 20;

    const int freq = 2;
    const double phase = 50.0;
    const int num_of_samples = NUM_OF_CYCLES * (FrameNum - 1); // reduce by 1 to include x=15
    const double amp_scale = 10.0 / FrameNum;
    const double x_step = 3.0;

    vector<double> sin_wave;
    sin_wave.reserve(num_of_samples + 1);

    for (int i = 0; i < NUM_OF_CYCLES; i++)
    {
        for (int j = 0; j < FrameNum; j++)
        {
            double t = 3.0 * i + (3.0 / FrameNum) * j;
            double y_value = AMP * sin(2.0 * PI * freq * t + phase);
            y_value = (y_value + AMP) / 2.0 + i * amp_scale;
            sin_wave.push_back(y_value);
        }
    }


    for(int i = 0; i < num_of_samples; i++)
    {
        double y_value = sin_wave[i];
        double x_value = 15.0 * i / num_of_samples;
        if(i % 3 == 0){ // add condition to only plot x values incremented by 3
//             x_value << " " << y_value << endl;
            m_generated.append(x_value);
            m_generated.append(y_value);
        }
    }

}
