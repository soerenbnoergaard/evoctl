#ifndef EVOCTL_H
#define EVOCTL_H

#include "settings.h"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>

class Gui
{
public:
    Gui();
    ~Gui();

private:
    static void on_change(Fl_Widget *o, void *v);
};

#endif
