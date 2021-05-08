#include "evoctl.h"
#include "transfer_matrix_table.h"

Gui::Gui()
{
    int W = 80*(NUM_INPUTS+1);
    int H = 20*(NUM_OUTPUTS+1) + 40;

    Fl_Window *window = new Fl_Window(W, H, "evoctl");
    window->begin();

    new TransferMatrixTable(10, 30, W-20, H-40, "Transfer matrix");

    window->end();
    window->show();
}

Gui::~Gui()
{
}

int main()
{
    new Gui();
    return Fl::run();
}
