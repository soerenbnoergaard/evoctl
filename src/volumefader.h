#ifndef VOLUMEFADER_H
#define VOLUMEFADER_H

#include <FL/Fl.H>
#include <FL/Fl_Slider.H>

class VolumeFader : public Fl_Slider
{
public:
    VolumeFader(int X, int Y, Fl_Callback *callback, void *callback_data);
    void reset();
    int value(double v);

private:
    int handle(int event);
};


#endif
