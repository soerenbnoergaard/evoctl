#include "evoctl.h"

HeaderLabel::HeaderLabel(int X, int Y, const char *L) : Fl_Box(X, Y, 40, 20, L)
{
}

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
            reset();
        }
    default:
        return Fl_Dial::handle(event);
    }
}

ResetButton::ResetButton(int X, int Y, const char *L, void *parent) : Fl_Button(X, Y, 40, 20, L)
{
    this->callback(reset, parent);
}

void ResetButton::reset(Fl_Widget *o, void *parent)
{
    Gui *gui = (Gui *)parent;
    gui->reset();
}

Gui::Gui()
{
    int W = 480;
    int H = 320;

    Fl_Window *window = new Fl_Window(W, H);
    window->begin();

    int x, y, m, b;

    m = 80;
    b = 10;

    new ResetButton(10, 10, "Reset", (void *)this);

    x = 0;
    y = 40;
    new HeaderLabel(b + m*x++, y, "MIC 1");
    new HeaderLabel(b + m*x++, y, "MIC 2");
    new HeaderLabel(b + m*x++, y, "MIC 3");
    new HeaderLabel(b + m*x++, y, "MIC 4");
    new HeaderLabel(b + m*x++, y, "DAW 1+2");
    new HeaderLabel(b + m*x++, y, "DAW 3+4");

    x = 0;
    y = 70;
    pan_mic1 = new PanDial(b + m*x++, y, 0.0, cb_pan_mic1);
    pan_mic2 = new PanDial(b + m*x++, y, 0.0, cb_pan_mic2);
    pan_mic3 = new PanDial(b + m*x++, y, 0.0, cb_pan_mic3);
    pan_mic4 = new PanDial(b + m*x++, y, 0.0, cb_pan_mic4);

    x = 0;
    y = 140;
    vol_mic1  = new VolumeFader(b + m*x++, y, -60.0, cb_vol_mic1);
    vol_mic2  = new VolumeFader(b + m*x++, y, -60.0, cb_vol_mic2);
    vol_mic3  = new VolumeFader(b + m*x++, y, -60.0, cb_vol_mic3);
    vol_mic4  = new VolumeFader(b + m*x++, y, -60.0, cb_vol_mic4);
    vol_daw12 = new VolumeFader(b + m*x++, y,   0.0, cb_vol_daw12);
    vol_daw34 = new VolumeFader(b + m*x++, y, -60.0, cb_vol_daw34);

    window->end();
    window->show();
}

Gui::~Gui()
{
}

void Gui::reset()
{
    pan_mic1->reset();
    pan_mic2->reset();
    pan_mic3->reset();
    pan_mic4->reset();

    vol_mic1->reset();
    vol_mic2->reset();
    vol_mic3->reset();
    vol_mic4->reset();

    vol_daw12->reset();
    vol_daw34->reset();
}

void Gui::on_change(identifier_t id, Fl_Widget *o)
{
    static char label[10];

    Fl_Slider *as_slider = (Fl_Slider *)o;
    Fl_Dial *as_dial = (Fl_Dial *)o;

    switch (id) {
    case ID_VOL_MIC1:
    case ID_VOL_MIC2:
    case ID_VOL_MIC3:
    case ID_VOL_MIC4:
    case ID_VOL_DAW12:
    case ID_VOL_DAW34:
        snprintf(label, 10, "%.1lf", as_slider->value());
        as_slider->label(label);
        break;
    case ID_PAN_MIC1:
    case ID_PAN_MIC2:
    case ID_PAN_MIC3:
    case ID_PAN_MIC4:
        snprintf(label, 10, "%.1lf", as_dial->value());
        as_dial->label(label);
        break;
    }
}

int main()
{
    new Gui();
    return Fl::run();
}
