#ifndef EVOCTL_H
#define EVOCTL_H

#include "volumefader.h"
#include "pandial.h"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>

typedef enum {
    ID_OUT12_PAN_MIC1,
    ID_OUT12_PAN_MIC2,
    ID_OUT12_PAN_MIC3,
    ID_OUT12_PAN_MIC4,
    ID_OUT12_VOL_MIC1,
    ID_OUT12_VOL_MIC2,
    ID_OUT12_VOL_MIC3,
    ID_OUT12_VOL_MIC4,
    ID_OUT12_VOL_DAW12,
    ID_OUT12_VOL_DAW34,

    ID_OUT34_PAN_MIC1,
    ID_OUT34_PAN_MIC2,
    ID_OUT34_PAN_MIC3,
    ID_OUT34_PAN_MIC4,
    ID_OUT34_VOL_MIC1,
    ID_OUT34_VOL_MIC2,
    ID_OUT34_VOL_MIC3,
    ID_OUT34_VOL_MIC4,
    ID_OUT34_VOL_DAW12,
    ID_OUT34_VOL_DAW34,
} identifier_t;

class Gui
{
public:
    Gui();
    ~Gui();
    void reset();

private:
    PanDial *out12_pan_mic1;
    PanDial *out12_pan_mic2;
    PanDial *out12_pan_mic3;
    PanDial *out12_pan_mic4;
    VolumeFader *out12_vol_mic1;
    VolumeFader *out12_vol_mic2;
    VolumeFader *out12_vol_mic3;
    VolumeFader *out12_vol_mic4;
    VolumeFader *out12_vol_daw12;
    VolumeFader *out12_vol_daw34;

    PanDial *out34_pan_mic1;
    PanDial *out34_pan_mic2;
    PanDial *out34_pan_mic3;
    PanDial *out34_pan_mic4;
    VolumeFader *out34_vol_mic1;
    VolumeFader *out34_vol_mic2;
    VolumeFader *out34_vol_mic3;
    VolumeFader *out34_vol_mic4;
    VolumeFader *out34_vol_daw12;
    VolumeFader *out34_vol_daw34;

    static void cb_out12_pan_mic1(Fl_Widget *o)  { on_change(ID_OUT12_PAN_MIC1, o); }
    static void cb_out12_pan_mic2(Fl_Widget *o)  { on_change(ID_OUT12_PAN_MIC2, o); }
    static void cb_out12_pan_mic3(Fl_Widget *o)  { on_change(ID_OUT12_PAN_MIC3, o); }
    static void cb_out12_pan_mic4(Fl_Widget *o)  { on_change(ID_OUT12_PAN_MIC4, o); }
    static void cb_out12_vol_mic1(Fl_Widget *o)  { on_change(ID_OUT12_VOL_MIC1, o); }
    static void cb_out12_vol_mic2(Fl_Widget *o)  { on_change(ID_OUT12_VOL_MIC2, o); }
    static void cb_out12_vol_mic3(Fl_Widget *o)  { on_change(ID_OUT12_VOL_MIC3, o); }
    static void cb_out12_vol_mic4(Fl_Widget *o)  { on_change(ID_OUT12_VOL_MIC4, o); }
    static void cb_out12_vol_daw12(Fl_Widget *o) { on_change(ID_OUT12_VOL_DAW12, o); }
    static void cb_out12_vol_daw34(Fl_Widget *o) { on_change(ID_OUT12_VOL_DAW34, o); }

    static void cb_out34_pan_mic1(Fl_Widget *o)  { on_change(ID_OUT34_PAN_MIC1, o); }
    static void cb_out34_pan_mic2(Fl_Widget *o)  { on_change(ID_OUT34_PAN_MIC2, o); }
    static void cb_out34_pan_mic3(Fl_Widget *o)  { on_change(ID_OUT34_PAN_MIC3, o); }
    static void cb_out34_pan_mic4(Fl_Widget *o)  { on_change(ID_OUT34_PAN_MIC4, o); }
    static void cb_out34_vol_mic1(Fl_Widget *o)  { on_change(ID_OUT34_VOL_MIC1, o); }
    static void cb_out34_vol_mic2(Fl_Widget *o)  { on_change(ID_OUT34_VOL_MIC2, o); }
    static void cb_out34_vol_mic3(Fl_Widget *o)  { on_change(ID_OUT34_VOL_MIC3, o); }
    static void cb_out34_vol_mic4(Fl_Widget *o)  { on_change(ID_OUT34_VOL_MIC4, o); }
    static void cb_out34_vol_daw12(Fl_Widget *o) { on_change(ID_OUT34_VOL_DAW12, o); }
    static void cb_out34_vol_daw34(Fl_Widget *o) { on_change(ID_OUT34_VOL_DAW34, o); }

    static void on_change(identifier_t id, Fl_Widget *o);
};

#endif
