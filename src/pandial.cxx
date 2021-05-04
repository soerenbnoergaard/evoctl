#include "pandial.h"

PanDial::PanDial(int X, int Y, double value, Fl_Callback0 *callback) : Fl_Dial(X, Y, 40, 40, "")
{
    reset_value = value;
    this->minimum(-100.0);
    this->maximum(100.0);
    this->step(1.0);
    this->value(reset_value);
    this->callback(callback);
    this->do_callback();
}

void PanDial::reset()
{
    this->value(reset_value);
    this->do_callback();
}

int PanDial::handle(int event)
{
    switch (event) {
    case FL_RELEASE:
        if (Fl::event_clicks() > 0) {
            Fl::event_clicks(0);
            reset();
        }
    default:
        return Fl_Dial::handle(event);
    }
}
