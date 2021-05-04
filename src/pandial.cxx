#include "pandial.h"

PanDial::PanDial(int X, int Y, Fl_Callback *callback, void *callback_data) : Fl_Dial(X, Y, 40, 40, "")
{
    this->minimum(-100.0);
    this->maximum(100.0);
    this->step(1.0);
    this->callback(callback, callback_data);
    this->reset();
}

void PanDial::reset()
{
    this->value(0.0);
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
