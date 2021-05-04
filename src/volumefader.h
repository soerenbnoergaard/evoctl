#ifndef VOLUMEFADER_H
#define VOLUMEFADER_H

#include <FL/Fl.H>
#include <FL/Fl_Slider.H>

class VolumeFader : public Fl_Slider
{
public:
    VolumeFader(int X, int Y, double value, Fl_Callback0 *callback);
    void reset();

private:
    double reset_value;
    int handle(int event);
};


#endif
