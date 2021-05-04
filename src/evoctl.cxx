#include "evoctl.h"

Gui::Gui()
{
    int W = 480;
    int H = 640;

    Fl_Window *window = new Fl_Window(W, H, "evoctl");
    window->begin();

    int x, y, m, b;

    m = 80;
    b = 10;

    // new ResetButton(10, 10, "Reset", (void *)this);

    /* x = 0; */
    /* y = 40; */
    /* new HeaderLabel(b + m*x++, y, "MIC 1",   FL_ALIGN_CENTER); */
    /* new HeaderLabel(b + m*x++, y, "MIC 2",   FL_ALIGN_CENTER); */
    /* new HeaderLabel(b + m*x++, y, "MIC 3",   FL_ALIGN_CENTER); */
    /* new HeaderLabel(b + m*x++, y, "MIC 4",   FL_ALIGN_CENTER); */
    /* new HeaderLabel(b + m*x++, y, "DAW 1+2", FL_ALIGN_CENTER); */
    /* new HeaderLabel(b + m*x++, y, "DAW 3+4", FL_ALIGN_CENTER); */
    /*  */
    /* new HeaderLabel(10, 70,  "OUTPUT 1+2", FL_ALIGN_LEFT | FL_ALIGN_INSIDE); */

    x = 0;
    y = 100;
    out12_pan_mic1 = new PanDial(b + m*x++, y, 0.0, cb_out12_pan_mic1);
    out12_pan_mic2 = new PanDial(b + m*x++, y, 0.0, cb_out12_pan_mic2);
    out12_pan_mic3 = new PanDial(b + m*x++, y, 0.0, cb_out12_pan_mic3);
    out12_pan_mic4 = new PanDial(b + m*x++, y, 0.0, cb_out12_pan_mic4);

    x = 0;
    y = 170;
    out12_vol_mic1  = new VolumeFader(b + m*x++, y, -60.0, cb_out12_vol_mic1);
    out12_vol_mic2  = new VolumeFader(b + m*x++, y, -60.0, cb_out12_vol_mic2);
    out12_vol_mic3  = new VolumeFader(b + m*x++, y, -60.0, cb_out12_vol_mic3);
    out12_vol_mic4  = new VolumeFader(b + m*x++, y, -60.0, cb_out12_vol_mic4);
    out12_vol_daw12 = new VolumeFader(b + m*x++, y,   0.0, cb_out12_vol_daw12);
    out12_vol_daw34 = new VolumeFader(b + m*x++, y, -60.0, cb_out12_vol_daw34);

    // new HeaderLabel(10, 350, "OUTPUT 3+4", FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

    x = 0;
    y = 380;
    out34_pan_mic1 = new PanDial(b + m*x++, y, 0.0, cb_out34_pan_mic1);
    out34_pan_mic2 = new PanDial(b + m*x++, y, 0.0, cb_out34_pan_mic2);
    out34_pan_mic3 = new PanDial(b + m*x++, y, 0.0, cb_out34_pan_mic3);
    out34_pan_mic4 = new PanDial(b + m*x++, y, 0.0, cb_out34_pan_mic4);


    x = 0;
    y = 450;
    out34_vol_mic1  = new VolumeFader(b + m*x++, y, -60.0, cb_out34_vol_mic1);
    out34_vol_mic2  = new VolumeFader(b + m*x++, y, -60.0, cb_out34_vol_mic2);
    out34_vol_mic3  = new VolumeFader(b + m*x++, y, -60.0, cb_out34_vol_mic3);
    out34_vol_mic4  = new VolumeFader(b + m*x++, y, -60.0, cb_out34_vol_mic4);
    out34_vol_daw12 = new VolumeFader(b + m*x++, y, -60.0, cb_out34_vol_daw12);
    out34_vol_daw34 = new VolumeFader(b + m*x++, y,   0.0, cb_out34_vol_daw34);

    window->end();
    window->show();
}

Gui::~Gui()
{
}

void Gui::reset()
{
    out12_pan_mic1->reset();
    out12_pan_mic2->reset();
    out12_pan_mic3->reset();
    out12_pan_mic4->reset();
    out12_vol_mic1->reset();
    out12_vol_mic2->reset();
    out12_vol_mic3->reset();
    out12_vol_mic4->reset();
    out12_vol_daw12->reset();
    out12_vol_daw34->reset();

    out34_pan_mic1->reset();
    out34_pan_mic2->reset();
    out34_pan_mic3->reset();
    out34_pan_mic4->reset();
    out34_vol_mic1->reset();
    out34_vol_mic2->reset();
    out34_vol_mic3->reset();
    out34_vol_mic4->reset();
    out34_vol_daw12->reset();
    out34_vol_daw34->reset();
}

void Gui::on_change(identifier_t id, Fl_Widget *o)
{
    char *label = new char[10];

    Fl_Slider *as_slider = (Fl_Slider *)o;
    Fl_Dial *as_dial = (Fl_Dial *)o;

    switch (id) {
    case ID_OUT12_PAN_MIC1:
    case ID_OUT12_PAN_MIC2:
    case ID_OUT12_PAN_MIC3:
    case ID_OUT12_PAN_MIC4:
    case ID_OUT34_PAN_MIC1:
    case ID_OUT34_PAN_MIC2:
    case ID_OUT34_PAN_MIC3:
    case ID_OUT34_PAN_MIC4:
        snprintf(label, 10, "%.1lf", as_dial->value());
        as_dial->label(label);
        break;
    case ID_OUT12_VOL_MIC1:
    case ID_OUT12_VOL_MIC2:
    case ID_OUT12_VOL_MIC3:
    case ID_OUT12_VOL_MIC4:
    case ID_OUT12_VOL_DAW12:
    case ID_OUT12_VOL_DAW34:
    case ID_OUT34_VOL_MIC1:
    case ID_OUT34_VOL_MIC2:
    case ID_OUT34_VOL_MIC3:
    case ID_OUT34_VOL_MIC4:
    case ID_OUT34_VOL_DAW12:
    case ID_OUT34_VOL_DAW34:
        snprintf(label, 10, "%.1lf", as_slider->value());
        as_slider->label(label);
        break;
    }
}

int main()
{
    new Gui();
    return Fl::run();
}
