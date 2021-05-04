#include "volumefader.h"

VolumeFader::VolumeFader(int X, int Y, double value, Fl_Callback0 *callback) : Fl_Slider(X, Y, 40, 150, "")
{
    reset_value = value;
    this->minimum(6.0);
    this->maximum(-60.0);
    this->step(1.0);
    this->value(reset_value);
    this->callback(callback);
    this->do_callback();
}

void VolumeFader::reset()
{
    this->value(reset_value);
    this->do_callback();
}

int VolumeFader::handle(int event)
{
    switch (event) {
    case FL_RELEASE:
        if (Fl::event_clicks() > 0) {
            reset();
        }
    default:
        return Fl_Slider::handle(event);
    }
}

