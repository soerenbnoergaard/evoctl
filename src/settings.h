#ifndef SETTINGS_H
#define SETTINGS_H

const double volume_silence_dB = -60.0;
const double pan_left_percent = -100.0;
const double pan_rignt_percent = 100.0;

template <typename T0, typename T1>
struct Source
{
    T0 volume_dB;
    T1 pan_percent;
};

template <typename T0, typename T1>
struct Mix
{
    Source<T0, T1> mic1;
    Source<T0, T1> mic2;
    Source<T0, T1> mic3;
    Source<T0, T1> mic4;

    Source<T0, T1> daw1;
    Source<T0, T1> daw2;
    Source<T0, T1> daw3;
    Source<T0, T1> daw4;
};

struct Settings
{
    Settings()
    {
        out12.mic1.volume_dB = volume_silence_dB;
        out12.mic2.volume_dB = volume_silence_dB;
        out12.mic3.volume_dB = volume_silence_dB;
        out12.mic4.volume_dB = volume_silence_dB;
        out12.daw1.volume_dB = 0.0;
        out12.daw2.volume_dB = 0.0;
        out12.daw3.volume_dB = volume_silence_dB;
        out12.daw4.volume_dB = volume_silence_dB;

        out34.mic1.volume_dB = volume_silence_dB;
        out34.mic2.volume_dB = volume_silence_dB;
        out34.mic3.volume_dB = volume_silence_dB;
        out34.mic4.volume_dB = volume_silence_dB;
        out34.daw1.volume_dB = volume_silence_dB;
        out34.daw2.volume_dB = volume_silence_dB;
        out34.daw3.volume_dB = 0.0;
        out34.daw4.volume_dB = 0.0;

        out12.mic1.pan_percent = 0.0;
        out12.mic2.pan_percent = 0.0;
        out12.mic3.pan_percent = 0.0;
        out12.mic4.pan_percent = 0.0;
        out12.daw1.pan_percent = pan_left_percent;
        out12.daw2.pan_percent = pan_rignt_percent;
        out12.daw3.pan_percent = pan_left_percent;
        out12.daw4.pan_percent = pan_rignt_percent;

        out34.mic1.pan_percent = 0.0;
        out34.mic2.pan_percent = 0.0;
        out34.mic3.pan_percent = 0.0;
        out34.mic4.pan_percent = 0.0;
        out34.daw1.pan_percent = pan_left_percent;
        out34.daw2.pan_percent = pan_rignt_percent;
        out34.daw3.pan_percent = pan_left_percent;
        out34.daw4.pan_percent = pan_rignt_percent;
    }

    Mix<double, double> out12;
    Mix<double, double> out34;
};

#endif
