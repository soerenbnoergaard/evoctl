#ifndef GUIELEMENTS_H
#define GUIELEMENTS_H

#include <FL/Fl.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Dial.H>

class VolumeFader : public Fl_Slider
{
public:
    VolumeFader(int X, int Y, Fl_Callback *callback, void *callback_data);
    void reset();
    int value(double v);

private:
    int handle(int event);
};


class PanDial : public Fl_Dial
{
public:
    PanDial(int X, int Y, Fl_Callback *callback, void *callback_data);
    void reset();

private:
    int handle(int event);
};

#endif

