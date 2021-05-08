#include "transfer_matrix_table.h"

void TransferMatrixTable::draw_header(const char *s, int X, int Y, int W, int H)
{
    fl_push_clip(X,Y,W,H);
    fl_draw_box(FL_THIN_UP_BOX, X,Y,W,H, row_header_color());
    fl_color(FL_BLACK);
    fl_draw(s, X,Y,W,H, FL_ALIGN_CENTER);
    fl_pop_clip();
} 

void TransferMatrixTable::draw_data(const char *s, int X, int Y, int W, int H)
{
    fl_push_clip(X,Y,W,H);
    fl_color(FL_WHITE); fl_rectf(X,Y,W,H);
    fl_color(FL_GRAY0); fl_draw(s, X,Y,W,H, FL_ALIGN_CENTER);
    fl_color(color()); fl_rect(X,Y,W,H);
    fl_pop_clip();
} 

void TransferMatrixTable::draw_cell(TableContext context, int ROW, int COL, int X, int Y, int W, int H)
{
    static char s[40];
    switch (context) {
    case CONTEXT_STARTPAGE:
        return;

    case CONTEXT_COL_HEADER:
        switch (COL) {
        case INPUT_MIC1:      sprintf(s, "MIC1"); break;
        case INPUT_MIC2:      sprintf(s, "MIC2"); break;
        case INPUT_MIC3:      sprintf(s, "MIC3"); break;
        case INPUT_MIC4:      sprintf(s, "MIC4"); break;
        case INPUT_DAW1:      sprintf(s, "DAW1"); break;
        case INPUT_DAW2:      sprintf(s, "DAW2"); break;
        case INPUT_DAW3:      sprintf(s, "DAW3"); break;
        case INPUT_DAW4:      sprintf(s, "DAW4"); break;
        case INPUT_LOOPBACK1: sprintf(s, "LB1"); break;
        case INPUT_LOOPBACK2: sprintf(s, "LB2"); break;
        default:              s[0] = '\0'; break;
        }

        draw_header(s,X,Y,W,H);

        return; 

    case CONTEXT_ROW_HEADER:
        switch (ROW) {
        case OUTPUT1: sprintf(s, "OUT1"); break;
        case OUTPUT2: sprintf(s, "OUT2"); break;
        case OUTPUT3: sprintf(s, "OUT3"); break;
        case OUTPUT4: sprintf(s, "OUT4"); break;
        default:              s[0] = '\0'; break;
        }

        draw_header(s,X,Y,W,H);

        return;

    case CONTEXT_CELL:
        sprintf(s,"%d", this->H.values[ROW][COL]);
        draw_data(s,X,Y,W,H);
        return;

    default:
        return;
    }
}

void TransferMatrixTable::set_value_hide()
{
    int v = atoi(input->value());
    if (v > 0) {
        v = 0;
    }
    if (v < -100) {
        v = -100;
    }

    this->H.values[row_edit][col_edit] = v;
    input->hide();
    window()->cursor(FL_CURSOR_DEFAULT);
}

void TransferMatrixTable::start_editing(int R, int C)
{
    int X, Y, W, H;
    char s[30];

    row_edit = R;
    col_edit = C;

    set_selection(R, C, R, C);
    find_cell(CONTEXT_CELL, R, C, X, Y, W, H);
    input->resize(X, Y, W, H);
    sprintf(s, "%d", this->H.values[R][C]);

    input->value(s);
    input->position(0,strlen(s));
    input->show();
    input->take_focus();
}

void TransferMatrixTable::done_editing()
{
    if (input->visible()) {
        set_value_hide();
    }
}

void TransferMatrixTable::event_callback2()
{
    int R = callback_row();
    int C = callback_col();
    TableContext context = callback_context(); 

    switch (context) {
    case CONTEXT_CELL: {
        switch (Fl::event()) {
        case FL_PUSH:
            done_editing();
            if (R != rows()-1 && C != cols()-1 )
                start_editing(R,C);
            return;

        case FL_KEYBOARD:
            if ( Fl::event_key() == FL_Escape )
                exit(0);
            done_editing();

            if (C == cols()-1 || R == rows()-1)
                return;

            switch (Fl::e_text[0]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '+':
            case '-':
                start_editing(R,C);
                input->handle(Fl::event());
                break;
            case '\r':
            case '\n':
                start_editing(R,C);
                break;
            }
            return;
        }
        return;
    }

    case CONTEXT_TABLE:
    case CONTEXT_ROW_HEADER:
    case CONTEXT_COL_HEADER:
        done_editing();
        return;

    default:
        return;
    }
}

TransferMatrixTable::TransferMatrixTable(int X, int Y, int W, int H, const char *L) : Fl_Table(X,Y,W,H,L)
{
    // Initialize transfer matrix
    for (int i = 0; i < NUM_OUTPUTS; i++) {
        for (int j = 0; j < NUM_INPUTS; j++) {
            this->H.values[i][j] = -100;
        }
    }
    this->H.values[OUTPUT1][INPUT_DAW1] = 0;
    this->H.values[OUTPUT2][INPUT_DAW2] = 0;
    this->H.values[OUTPUT3][INPUT_DAW1] = 0;
    this->H.values[OUTPUT4][INPUT_DAW2] = 0;

    // Set up callbacks
    callback(&event_callback, (void*)this);
    when(FL_WHEN_NOT_CHANGED|when());

    input = new Fl_Int_Input(W/2,H/2,0,0);
    input->hide();
    input->callback(input_cb, (void*)this);
    input->when(FL_WHEN_ENTER_KEY_ALWAYS);

    // Set up table UI
    rows(NUM_OUTPUTS);
    row_header(1);
    row_height_all(20);
    row_resize(0);

    cols(NUM_INPUTS);
    col_header(1);
    col_width_all(80);
    col_resize(1);

    end();
    row_edit = 0;
    col_edit = 0;
    set_selection(0, 0, 0, 0);
}
