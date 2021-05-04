#ifndef PANDIAL_H
#define PANDIAL_H

#include <FL/Fl.H>
#include <FL/Fl_Dial.H>

class PanDial : public Fl_Dial
{
public:
    PanDial(int X, int Y, Fl_Callback *callback, void *callback_data);
    void reset();

private:
    int handle(int event);
};

#endif

