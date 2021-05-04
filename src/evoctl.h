#ifndef EVOCTL_H
#define EVOCTL_H

#include "settings.h"
#include "volumefader.h"
#include "pandial.h"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

class TextBox : Fl_Box
{
public:
    TextBox(int X, int Y, int W, int H, const char *L, Fl_Align align) : Fl_Box(X, Y, W, H, L)
    {
        this->align(align);
    }
};

class TextBoxCenter : TextBox
{
public:
    TextBoxCenter(int X, int Y, int W, int H, const char *L) : TextBox(X, Y, W, H, L, FL_ALIGN_CENTER) { }
};

class TextBoxLeft : TextBox
{
public:
    TextBoxLeft(int X, int Y, int W, int H, const char *L) : TextBox(X, Y, W, H, L, FL_ALIGN_LEFT|FL_ALIGN_INSIDE) { }
};

class Gui
{
public:
    Gui();
    ~Gui();
    void update(Settings s);
    Settings get_settings() { return this->settings; };

private:
    Mix<VolumeFader *, PanDial *> out12;
    Mix<VolumeFader *, PanDial *> out34;
    Settings settings;

    static void on_change(Fl_Widget *o, void *v);
};

#endif
