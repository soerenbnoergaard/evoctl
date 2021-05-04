#ifndef SETTINGS_H
#define SETTINGS_H

struct Settings
{
    Settings() : 
        out12_vol_mic1_dB(0.0),
        out12_vol_mic2_dB(0.0),
        out12_vol_mic3_dB(0.0),
        out12_vol_mic4_dB(0.0),
        out12_vol_daw1_dB(0.0),
        out12_vol_daw2_dB(0.0),
        out12_vol_daw3_dB(0.0),
        out12_vol_daw4_dB(0.0),

        out12_pan_mic1_percent(0.0),
        out12_pan_mic2_percent(0.0),
        out12_pan_mic3_percent(0.0),
        out12_pan_mic4_percent(0.0),
        out12_pan_daw1_percent(0.0),
        out12_pan_daw2_percent(0.0),
        out12_pan_daw3_percent(0.0),
        out12_pan_daw4_percent(0.0),

        out34_vol_mic1_dB(0.0),
        out34_vol_mic2_dB(0.0),
        out34_vol_mic3_dB(0.0),
        out34_vol_mic4_dB(0.0),
        out34_vol_daw1_dB(0.0),
        out34_vol_daw2_dB(0.0),
        out34_vol_daw3_dB(0.0),
        out34_vol_daw4_dB(0.0),

        out34_pan_mic1_percent(0.0),
        out34_pan_mic2_percent(0.0),
        out34_pan_mic3_percent(0.0),
        out34_pan_mic4_percent(0.0),
        out34_pan_daw1_percent(0.0),
        out34_pan_daw2_percent(0.0),
        out34_pan_daw3_percent(0.0),
        out34_pan_daw4_percent(0.0) {}

    double out12_vol_mic1_dB;
    double out12_vol_mic2_dB;
    double out12_vol_mic3_dB;
    double out12_vol_mic4_dB;
    double out12_vol_daw1_dB;
    double out12_vol_daw2_dB;
    double out12_vol_daw3_dB;
    double out12_vol_daw4_dB;

    double out12_pan_mic1_percent;
    double out12_pan_mic2_percent;
    double out12_pan_mic3_percent;
    double out12_pan_mic4_percent;
    double out12_pan_daw1_percent;
    double out12_pan_daw2_percent;
    double out12_pan_daw3_percent;
    double out12_pan_daw4_percent;

    double out34_vol_mic1_dB;
    double out34_vol_mic2_dB;
    double out34_vol_mic3_dB;
    double out34_vol_mic4_dB;
    double out34_vol_daw1_dB;
    double out34_vol_daw2_dB;
    double out34_vol_daw3_dB;
    double out34_vol_daw4_dB;

    double out34_pan_mic1_percent;
    double out34_pan_mic2_percent;
    double out34_pan_mic3_percent;
    double out34_pan_mic4_percent;
    double out34_pan_daw1_percent;
    double out34_pan_daw2_percent;
    double out34_pan_daw3_percent;
    double out34_pan_daw4_percent;
};

#endif
