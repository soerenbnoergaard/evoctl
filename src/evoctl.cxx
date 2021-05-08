#include "evoctl.h"
#include <FL/Fl_Box.H>
#include <FL/Fl_Table.H>
#include <FL/fl_draw.H>

class TransferMatrixTable : public Fl_Table
{
    transfer_matrix_t H;

    void DrawHeader(const char *s, int X, int Y, int W, int H)
    {
        fl_push_clip(X,Y,W,H);
        fl_draw_box(FL_THIN_UP_BOX, X,Y,W,H, row_header_color());
        fl_color(FL_BLACK);
        fl_draw(s, X,Y,W,H, FL_ALIGN_CENTER);
        fl_pop_clip();
    } 

    void DrawData(const char *s, int X, int Y, int W, int H)
    {
        fl_push_clip(X,Y,W,H);
        fl_color(FL_WHITE); fl_rectf(X,Y,W,H);
        fl_color(FL_GRAY0); fl_draw(s, X,Y,W,H, FL_ALIGN_CENTER);
        fl_color(color()); fl_rect(X,Y,W,H);
        fl_pop_clip();
    } 

    void draw_cell(TableContext context, int ROW=0, int COL=0, int X=0, int Y=0, int W=0, int H=0)
    {
        static char s[40];
        switch (context) {
        case CONTEXT_STARTPAGE:
            fl_font(FL_HELVETICA, 12);
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

            DrawHeader(s,X,Y,W,H);

            return; 

        case CONTEXT_ROW_HEADER:
            switch (ROW) {
            case OUTPUT1: sprintf(s, "OUT1"); break;
            case OUTPUT2: sprintf(s, "OUT2"); break;
            case OUTPUT3: sprintf(s, "OUT3"); break;
            case OUTPUT4: sprintf(s, "OUT4"); break;
            default:              s[0] = '\0'; break;
            }

            DrawHeader(s,X,Y,W,H);

            return;

        case CONTEXT_CELL:
            sprintf(s,"%d", this->H.values[ROW][COL]);
            DrawData(s,X,Y,W,H);
            return;

        default:
            return;
        }
    }

public:
    TransferMatrixTable(transfer_matrix_t transfer_matrix, int X, int Y, int W, int H, const char *L=0) : Fl_Table(X,Y,W,H,L)
    {
        this->H = transfer_matrix;

        rows(NUM_OUTPUTS);
        row_header(1);
        row_height_all(20);
        row_resize(0);

        cols(NUM_INPUTS);
        col_header(1);
        col_width_all(80);
        col_resize(1);
        end();
    }
    ~TransferMatrixTable() { }
};

Gui::Gui()
{
    int W = 80*(NUM_INPUTS+1);
    int H = 20*(NUM_OUTPUTS+1) + 40;

    Fl_Window *window = new Fl_Window(W, H, "evoctl");
    window->begin();

    Fl_Table *t = new TransferMatrixTable(this->H, 10, 30, W-20, H-40, "Transfer matrix");

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
