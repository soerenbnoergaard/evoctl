#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Dial.H>

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

class HeaderLabel : public Fl_Box
{
public:
    HeaderLabel(int X, int Y, const char *L, Fl_Align align);
};

class VolumeFader : public Fl_Slider
{
public:
    VolumeFader(int X, int Y, double value, Fl_Callback0 *callback);
    void reset();

private:
    double reset_value;
    int handle(int event);
};

class PanDial : public Fl_Dial
{
public:
    PanDial(int X, int Y, double value, Fl_Callback0 *callback);
    void reset();

private:
    double reset_value;
    int handle(int event);
};

class ResetButton : Fl_Button
{
public:
    ResetButton(int X, int Y, const char *L, void *parent);

private:
    static void reset(Fl_Widget *o, void *parent);
};

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
