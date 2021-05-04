#include "evoctl.h"
#include <FL/Fl_Box.H>

Gui::Gui()
{
    int W = 640;
    int H = 640;

    Fl_Window *window = new Fl_Window(W, H, "evoctl");
    window->begin();

    int x, y, m, b, h, w;

    m = 80;
    b = 10;

    w = 40;
    h = 20;

    // new ResetButton(10, 10, "Reset", (void *)this);

    x = 0;
    y = 40;

    new TextBoxCenter(b + m*x++, y, w, h, "MIC 1");
    new TextBoxCenter(b + m*x++, y, w, h, "MIC 2");
    new TextBoxCenter(b + m*x++, y, w, h, "MIC 3");
    new TextBoxCenter(b + m*x++, y, w, h, "MIC 4");
    new TextBoxCenter(b + m*x++, y, w, h, "DAW 1");
    new TextBoxCenter(b + m*x++, y, w, h, "DAW 2");
    new TextBoxCenter(b + m*x++, y, w, h, "DAW 3");
    new TextBoxCenter(b + m*x++, y, w, h, "DAW 4");

    new TextBoxLeft(b, 70, w, h,  "OUTPUT 1 + 2");

    x = 0;
    y = 100;
    this->out12.mic1.pan_percent = new PanDial(b + m*x++, y, on_change, this);
    this->out12.mic2.pan_percent = new PanDial(b + m*x++, y, on_change, this);
    this->out12.mic3.pan_percent = new PanDial(b + m*x++, y, on_change, this);
    this->out12.mic4.pan_percent = new PanDial(b + m*x++, y, on_change, this);
    this->out12.daw1.pan_percent = new PanDial(b + m*x++, y, on_change, this);
    this->out12.daw2.pan_percent = new PanDial(b + m*x++, y, on_change, this);
    this->out12.daw3.pan_percent = new PanDial(b + m*x++, y, on_change, this);
    this->out12.daw4.pan_percent = new PanDial(b + m*x++, y, on_change, this);


    x = 0;
    y = 170;
    this->out12.mic1.volume_dB = new VolumeFader(b + m*x++, y, on_change, this);
    this->out12.mic2.volume_dB = new VolumeFader(b + m*x++, y, on_change, this);
    this->out12.mic3.volume_dB = new VolumeFader(b + m*x++, y, on_change, this);
    this->out12.mic4.volume_dB = new VolumeFader(b + m*x++, y, on_change, this);
    this->out12.daw1.volume_dB = new VolumeFader(b + m*x++, y, on_change, this);
    this->out12.daw2.volume_dB = new VolumeFader(b + m*x++, y, on_change, this);
    this->out12.daw3.volume_dB = new VolumeFader(b + m*x++, y, on_change, this);
    this->out12.daw4.volume_dB = new VolumeFader(b + m*x++, y, on_change, this);

    new TextBoxLeft(b, 350, w, h,  "OUTPUT 3 + 4");

    x = 0;
    y = 380;
    this->out34.mic1.pan_percent = new PanDial(b + m*x++, y, on_change, this);
    this->out34.mic2.pan_percent = new PanDial(b + m*x++, y, on_change, this);
    this->out34.mic3.pan_percent = new PanDial(b + m*x++, y, on_change, this);
    this->out34.mic4.pan_percent = new PanDial(b + m*x++, y, on_change, this);
    this->out34.daw1.pan_percent = new PanDial(b + m*x++, y, on_change, this);
    this->out34.daw2.pan_percent = new PanDial(b + m*x++, y, on_change, this);
    this->out34.daw3.pan_percent = new PanDial(b + m*x++, y, on_change, this);
    this->out34.daw4.pan_percent = new PanDial(b + m*x++, y, on_change, this);

    x = 0;
    y = 450;
    this->out34.mic1.volume_dB = new VolumeFader(b + m*x++, y, on_change, this);
    this->out34.mic2.volume_dB = new VolumeFader(b + m*x++, y, on_change, this);
    this->out34.mic3.volume_dB = new VolumeFader(b + m*x++, y, on_change, this);
    this->out34.mic4.volume_dB = new VolumeFader(b + m*x++, y, on_change, this);
    this->out34.daw1.volume_dB = new VolumeFader(b + m*x++, y, on_change, this);
    this->out34.daw2.volume_dB = new VolumeFader(b + m*x++, y, on_change, this);
    this->out34.daw3.volume_dB = new VolumeFader(b + m*x++, y, on_change, this);
    this->out34.daw4.volume_dB = new VolumeFader(b + m*x++, y, on_change, this);

    this->update(this->settings);
    window->end();
    window->show();
}

Gui::~Gui()
{
}

void Gui::update(Settings s)
{
    this->out12.mic1.volume_dB->value(s.out12.mic1.volume_dB);
    this->out12.mic2.volume_dB->value(s.out12.mic2.volume_dB);
    this->out12.mic3.volume_dB->value(s.out12.mic3.volume_dB);
    this->out12.mic4.volume_dB->value(s.out12.mic4.volume_dB);
    this->out12.daw1.volume_dB->value(s.out12.daw1.volume_dB);
    this->out12.daw2.volume_dB->value(s.out12.daw2.volume_dB);
    this->out12.daw3.volume_dB->value(s.out12.daw3.volume_dB);
    this->out12.daw4.volume_dB->value(s.out12.daw4.volume_dB);

    this->out34.mic1.volume_dB->value(s.out34.mic1.volume_dB);
    this->out34.mic2.volume_dB->value(s.out34.mic2.volume_dB);
    this->out34.mic3.volume_dB->value(s.out34.mic3.volume_dB);
    this->out34.mic4.volume_dB->value(s.out34.mic4.volume_dB);
    this->out34.daw1.volume_dB->value(s.out34.daw1.volume_dB);
    this->out34.daw2.volume_dB->value(s.out34.daw2.volume_dB);
    this->out34.daw3.volume_dB->value(s.out34.daw3.volume_dB);
    this->out34.daw4.volume_dB->value(s.out34.daw4.volume_dB);

    this->out12.mic1.pan_percent->value(s.out12.mic1.pan_percent);
    this->out12.mic2.pan_percent->value(s.out12.mic2.pan_percent);
    this->out12.mic3.pan_percent->value(s.out12.mic3.pan_percent);
    this->out12.mic4.pan_percent->value(s.out12.mic4.pan_percent);
    this->out12.daw1.pan_percent->value(s.out12.daw1.pan_percent);
    this->out12.daw2.pan_percent->value(s.out12.daw2.pan_percent);
    this->out12.daw3.pan_percent->value(s.out12.daw3.pan_percent);
    this->out12.daw4.pan_percent->value(s.out12.daw4.pan_percent);

    this->out34.mic1.pan_percent->value(s.out34.mic1.pan_percent);
    this->out34.mic2.pan_percent->value(s.out34.mic2.pan_percent);
    this->out34.mic3.pan_percent->value(s.out34.mic3.pan_percent);
    this->out34.mic4.pan_percent->value(s.out34.mic4.pan_percent);
    this->out34.daw1.pan_percent->value(s.out34.daw1.pan_percent);
    this->out34.daw2.pan_percent->value(s.out34.daw2.pan_percent);
    this->out34.daw3.pan_percent->value(s.out34.daw3.pan_percent);
    this->out34.daw4.pan_percent->value(s.out34.daw4.pan_percent);

    this->settings = s;
}

void Gui::on_change(Fl_Widget *o, void *v)
{
    Gui *gui = (Gui *)v;
    Settings s = gui->get_settings();

    VolumeFader *as_volume = (VolumeFader *)o;
    PanDial *as_pan = (PanDial *)o;

    if (o == nullptr) {
    }
    else if (o == gui->out12.mic1.volume_dB) {
        as_volume->update();
    }
    else if (o == gui->out12.mic2.volume_dB) {
        as_volume->update();
    }
    else if (o == gui->out12.mic3.volume_dB) {
        as_volume->update();
    }
    else if (o == gui->out12.mic4.volume_dB) {
        as_volume->update();
    }
    else if (o == gui->out12.daw1.volume_dB) {
        as_volume->update();
    }
    else if (o == gui->out12.daw2.volume_dB) {
        as_volume->update();
    }
    else if (o == gui->out12.daw3.volume_dB) {
        as_volume->update();
    }
    else if (o == gui->out12.daw4.volume_dB) {
        as_volume->update();
    }
    else if (o == gui->out34.mic1.volume_dB) {
        as_volume->update();
    }
    else if (o == gui->out34.mic2.volume_dB) {
        as_volume->update();
    }
    else if (o == gui->out34.mic3.volume_dB) {
        as_volume->update();
    }
    else if (o == gui->out34.mic4.volume_dB) {
        as_volume->update();
    }
    else if (o == gui->out34.daw1.volume_dB) {
        as_volume->update();
    }
    else if (o == gui->out34.daw2.volume_dB) {
        as_volume->update();
    }
    else if (o == gui->out34.daw3.volume_dB) {
        as_volume->update();
    }
    else if (o == gui->out34.daw4.volume_dB) {
        as_volume->update();
    }
    else if (o == gui->out12.mic1.pan_percent) {
        as_pan->update();
    }
    else if (o == gui->out12.mic2.pan_percent) {
        as_pan->update();
    }
    else if (o == gui->out12.mic3.pan_percent) {
        as_pan->update();
    }
    else if (o == gui->out12.mic4.pan_percent) {
        as_pan->update();
    }
    else if (o == gui->out12.daw1.pan_percent) {
        as_pan->update();
    }
    else if (o == gui->out12.daw2.pan_percent) {
        as_pan->update();
    }
    else if (o == gui->out12.daw3.pan_percent) {
        as_pan->update();
    }
    else if (o == gui->out12.daw4.pan_percent) {
        as_pan->update();
    }
    else if (o == gui->out34.mic1.pan_percent) {
        as_pan->update();
    }
    else if (o == gui->out34.mic2.pan_percent) {
        as_pan->update();
    }
    else if (o == gui->out34.mic3.pan_percent) {
        as_pan->update();
    }
    else if (o == gui->out34.mic4.pan_percent) {
        as_pan->update();
    }
    else if (o == gui->out34.daw1.pan_percent) {
        as_pan->update();
    }
    else if (o == gui->out34.daw2.pan_percent) {
        as_pan->update();
    }
    else if (o == gui->out34.daw3.pan_percent) {
        as_pan->update();
    }
    else if (o == gui->out34.daw4.pan_percent) {
        as_pan->update();
    }

    // gui->update(s);
}

int main()
{
    new Gui();
    return Fl::run();
}
