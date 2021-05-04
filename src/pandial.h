#ifndef PANDIAL_H
#define PANDIAL_H

#include <FL/Fl.H>
#include <FL/Fl_Dial.H>

class PanDial : public Fl_Dial
{
public:
    PanDial(int X, int Y, double value, Fl_Callback0 *callback);
    void reset();

private:
    double reset_value;
    int handle(int event);
};

#endif

