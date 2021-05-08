#ifndef TRANSFER_MATRIX_TABLE_H
#define TRANSFER_MATRIX_TABLE_H

#include "settings.h"
#include <FL/Fl_Table.H>
#include <FL/Fl_Int_Input.H>
#include <FL/fl_draw.H>

class TransferMatrixTable : public Fl_Table
{
private:
    transfer_matrix_t H;
    Fl_Int_Input *input;
    int row_edit, col_edit;
    void (*callback_value_changed)(transfer_matrix_t);

    void draw_header(const char *s, int X, int Y, int W, int H);
    void draw_data(const char *s, int X, int Y, int W, int H);
    void draw_cell(TableContext context, int ROW=0, int COL=0, int X=0, int Y=0, int W=0, int H=0);
    void set_value_hide();
    void start_editing(int R, int C);
    void done_editing();
    void event_callback2();
    static void event_callback(Fl_Widget *, void *v) { ((TransferMatrixTable*)v)->event_callback2(); }
    static void input_cb(Fl_Widget *, void* v) { ((TransferMatrixTable*)v)->set_value_hide(); }

public:
    TransferMatrixTable(int X, int Y, int W, int H, const char *L=0);
    ~TransferMatrixTable() { }
    void set_callback_value_changed(void (*f)(transfer_matrix_t)) { this->callback_value_changed = f; };
};

#endif
