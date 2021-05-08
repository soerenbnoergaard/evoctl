#include "settings.h"
#include "transfer_matrix_table.h"

#include <FL/Fl.H>
#include <FL/Fl_Window.H>

void evo_update(transfer_matrix_t H)
{
    for (int i = 0; i < NUM_OUTPUTS; i++) {
        for (int j = 0; j < NUM_INPUTS; j++) {
            printf("%5d ", H.values[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int W = 80*(NUM_INPUTS+1);
    int H = 20*(NUM_OUTPUTS+1) + 40;

    Fl_Window *window = new Fl_Window(W, H, "evoctl");
    window->begin();

    TransferMatrixTable *t = new TransferMatrixTable(10, 30, W-20, H-40, "Transfer matrix");
    t->set_callback_value_changed(evo_update);

    window->end();
    window->show();

    return Fl::run();
}
