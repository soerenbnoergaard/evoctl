#include <cmath>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Widget.H>
#include <libusb.h>

#include "settings.h"
#include "transfer_matrix_table.h"

#define EVO_VENDOR_ID 0x2708
#define EVO_4_PRODUCT_ID 0x0006
#define EVO_8_PRODUCT_ID 0x0007

static libusb_device_handle *devh = NULL;

void evo_init()
{
    int err;
    err = libusb_init(NULL);
    if (err != LIBUSB_SUCCESS) {
        printf("libusb_init failed: %s\n", libusb_error_name(err));
    }

    // First try to open an EVO 8
    devh = libusb_open_device_with_vid_pid(NULL, EVO_VENDOR_ID, EVO_8_PRODUCT_ID);
    if (devh == NULL) {

        // Otherwise try EVO 4
        devh = libusb_open_device_with_vid_pid(NULL, EVO_VENDOR_ID, EVO_4_PRODUCT_ID);

        if (devh == NULL) {
            printf("Unable to find an Audient EVO 8 or Audient EVO 4\n");
            exit(1);
        }

    }

    err = libusb_set_auto_detach_kernel_driver(devh, 1);
    if (err < 0) {
        printf("libusb_set_auto_detach_kernel_driver failed: %s\n", libusb_error_name(err));
        exit(1);
    }
    err = libusb_claim_interface(devh, 0);
    if (err < 0) {
        printf("libusb_claim_interface failed: %s\n", libusb_error_name(err));
        exit(1);
    }
}

void evo_close()
{
    /* libusb_release_interface(devh, 0); */
    libusb_close(devh);
    libusb_exit(NULL);
}

void evo_update(transfer_matrix_t H)
{
    for (int i = 0; i < NUM_OUTPUTS; i++) {
        for (int j = 0; j < NUM_INPUTS; j++) {
            printf("%5d ", H.values[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Volume mapping:
    // - Minimum = 0x0080 = 128
    // - Maximum = 0xefff = 61439 = +6 dB
    // Theory: The format is in dB (fixed-point Q8.8?)

    int v = H.values[OUTPUT1][INPUT_MIC1];
    uint8_t bytes[2];

    if (v == -100) {
        bytes[1] = 0x80;
        bytes[0] = 0x00;
    } else {
        bytes[1] = v;
        bytes[0] = v/0xff;
    }

    int err;
    err = libusb_control_transfer(devh, 0x21, 0x01, 0x0100, 0x3c00, bytes, 2, 0);
    err = libusb_control_transfer(devh, 0x21, 0x01, 0x0101, 0x3c00, bytes, 2, 0);
}

void on_window_close(Fl_Widget *w, void *o)
{
    Fl_Window *win = (Fl_Window *)w;
    evo_close();
    win->hide();
}

int main()
{
    evo_init();

    int W = 880;
    int H = 140;

    Fl_Window *window = new Fl_Window(W, H, "evoctl");
    window->begin();

    TransferMatrixTable *t = new TransferMatrixTable(10, 30, W-20, H-40, "Transfer matrix");
    t->set_callback_value_changed(evo_update);

    window->end();
    window->callback(on_window_close);
    window->show();

    return Fl::run();
}
