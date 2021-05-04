#include "guielements.h"

VolumeFader::VolumeFader(int X, int Y, Fl_Callback *callback, void *callback_data) : Fl_Slider(X, Y, 40, 150, "")
{
    this->minimum(6.0);
    this->maximum(-60.0);
    this->step(1.0);
    this->callback(callback, callback_data);
    this->reset();
}

PanDial::PanDial(int X, int Y, Fl_Callback *callback, void *callback_data) : Fl_Dial(X, Y, 40, 40, "")
{
    this->minimum(-100.0);
    this->maximum(100.0);
    this->step(1.0);
    this->callback(callback, callback_data);
    this->reset();
}

void VolumeFader::reset()
{
    this->value(0.0);
    this->do_callback();
}

void PanDial::reset()
{
    this->value(0.0);
    this->do_callback();
}

void VolumeFader::update()
{
    char *buffer = new char[16];
    snprintf(buffer, 16, "%.0f", this->value());
    this->label(buffer);
    // this->value(v);
}

void PanDial::update()
{
    char *buffer = new char[16];
    snprintf(buffer, 16, "%.0f", this->value());
    this->label(buffer);
    // this->value(v);
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
