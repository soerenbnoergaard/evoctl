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
    libusb_reset_device(devh);
    libusb_release_interface(devh, 0);
    libusb_close(devh);
    libusb_exit(NULL);
}

void evo_ctrl_volume(int wValue, int wIndex, int32_t volume_dB)
{
    // Volume mapping:
    // It looks like little endian Q8.8 encoded dB values.
    // - Minimum = 0x0080 = 128 = -128 dB
    // - Maximum = 0xefff = 61439 = -0.066 dB

    if (volume_dB <= -100) {
        volume_dB = -128;
    } else if (volume_dB > 0) {
        volume_dB = 0;
    }

    uint16_t v = (uint16_t)(256 * volume_dB);
    uint8_t bytes[2];

    bytes[1] = (v >> 8) & 0xff;
    bytes[0] = (v     ) & 0xff;

    libusb_control_transfer(devh, 0x21, 0x01, wValue, wIndex, bytes, 2, 0);
}

void evo_update(transfer_matrix_t H)
{

    for (int i = 0; i < NUM_OUTPUTS; i++) {
        for (int j = 0; j < NUM_INPUTS; j++) {
            int32_t v = H.values[i][j];
            /* printf("%5d ", v); */

            switch (i) {
            case OUTPUT1:
                switch (j) {
                case INPUT_MIC1:      evo_ctrl_volume(0x100, 0x3c00, v); break;
                case INPUT_MIC2:      evo_ctrl_volume(0x104, 0x3c00, v); break;
                case INPUT_MIC3:      evo_ctrl_volume(0x108, 0x3c00, v); break;
                case INPUT_MIC4:      evo_ctrl_volume(0x10c, 0x3c00, v); break;
                case INPUT_DAW1:      evo_ctrl_volume(0x110, 0x3c00, v); break;
                case INPUT_DAW2:      evo_ctrl_volume(0x114, 0x3c00, v); break;
                case INPUT_DAW3:      evo_ctrl_volume(0x118, 0x3c00, v); break;
                case INPUT_DAW4:      evo_ctrl_volume(0x11c, 0x3c00, v); break;
                case INPUT_LOOPBACK1: evo_ctrl_volume(0x120, 0x3c00, v); break;
                case INPUT_LOOPBACK2: evo_ctrl_volume(0x124, 0x3c00, v); break;
                }
                break;

            case OUTPUT2:
                switch (j) {
                case INPUT_MIC1:      evo_ctrl_volume(0x101, 0x3c00, v); break;
                case INPUT_MIC2:      evo_ctrl_volume(0x105, 0x3c00, v); break;
                case INPUT_MIC3:      evo_ctrl_volume(0x109, 0x3c00, v); break;
                case INPUT_MIC4:      evo_ctrl_volume(0x10d, 0x3c00, v); break;
                case INPUT_DAW1:      evo_ctrl_volume(0x111, 0x3c00, v); break;
                case INPUT_DAW2:      evo_ctrl_volume(0x115, 0x3c00, v); break;
                case INPUT_DAW3:      evo_ctrl_volume(0x119, 0x3c00, v); break;
                case INPUT_DAW4:      evo_ctrl_volume(0x11d, 0x3c00, v); break;
                case INPUT_LOOPBACK1: evo_ctrl_volume(0x121, 0x3c00, v); break;
                case INPUT_LOOPBACK2: evo_ctrl_volume(0x125, 0x3c00, v); break;
                }
                break;

            case OUTPUT3:
                switch (j) {
                case INPUT_MIC1:      evo_ctrl_volume(0x102, 0x3c00, v); break;
                case INPUT_MIC2:      evo_ctrl_volume(0x106, 0x3c00, v); break;
                case INPUT_MIC3:      evo_ctrl_volume(0x10a, 0x3c00, v); break;
                case INPUT_MIC4:      evo_ctrl_volume(0x10e, 0x3c00, v); break;
                case INPUT_DAW1:      evo_ctrl_volume(0x112, 0x3c00, v); break;
                case INPUT_DAW2:      evo_ctrl_volume(0x116, 0x3c00, v); break;
                case INPUT_DAW3:      evo_ctrl_volume(0x11a, 0x3c00, v); break;
                case INPUT_DAW4:      evo_ctrl_volume(0x11e, 0x3c00, v); break;
                case INPUT_LOOPBACK1: evo_ctrl_volume(0x122, 0x3c00, v); break;
                case INPUT_LOOPBACK2: evo_ctrl_volume(0x126, 0x3c00, v); break;
                }
                break;

            case OUTPUT4:
                switch (j) {
                case INPUT_MIC1:      evo_ctrl_volume(0x103, 0x3c00, v); break;
                case INPUT_MIC2:      evo_ctrl_volume(0x107, 0x3c00, v); break;
                case INPUT_MIC3:      evo_ctrl_volume(0x10b, 0x3c00, v); break;
                case INPUT_MIC4:      evo_ctrl_volume(0x10f, 0x3c00, v); break;
                case INPUT_DAW1:      evo_ctrl_volume(0x113, 0x3c00, v); break;
                case INPUT_DAW2:      evo_ctrl_volume(0x117, 0x3c00, v); break;
                case INPUT_DAW3:      evo_ctrl_volume(0x11b, 0x3c00, v); break;
                case INPUT_DAW4:      evo_ctrl_volume(0x11f, 0x3c00, v); break;
                case INPUT_LOOPBACK1: evo_ctrl_volume(0x123, 0x3c00, v); break;
                case INPUT_LOOPBACK2: evo_ctrl_volume(0x127, 0x3c00, v); break;
                }
                break;

            }
        }
        /* printf("\n"); */
    }
    /* printf("\n"); */
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
    evo_update(t->get_transfer_matrix());

    window->end();
    window->callback(on_window_close);
    window->show();

    return Fl::run();
}
