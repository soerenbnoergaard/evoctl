#include <stdio.h>
#include <libusb.h>

#define EVO_VENDOR_ID 0x2708
#define EVO_4_PRODUCT_ID 0x0006
#define EVO_8_PRODUCT_ID 0x0007

int main()
{
    static libusb_device_handle *devh = NULL;

    int err;
    err = libusb_init(NULL);
    if (err != LIBUSB_SUCCESS) {
        printf("libusb_init failed: %s\n", libusb_error_name(err));
        return 1;
    }

    // First try to open an EVO 8
    devh = libusb_open_device_with_vid_pid(NULL, EVO_VENDOR_ID, EVO_8_PRODUCT_ID);
    if (devh == NULL) {
        printf("Unable to find an Audient EVO 8 or Audient EVO 4\n");
        return 1;
    }

    #define PERR() printf("%4d: %s\n", __LINE__, libusb_error_name(err))

    //
    // INIT
    //

    err = libusb_set_auto_detach_kernel_driver(devh, 1);
    PERR();

    err = libusb_claim_interface(devh, 0);
    PERR();

    //
    // TRANSFER
    //

    uint8_t bytes[2] = {0x00, 0x80};

    err = libusb_control_transfer(devh, 0x21, 0x01, 0x100, 0x3c00, bytes, 2, 0);
    PERR();

    err = libusb_control_transfer(devh, 0x21, 0x01, 0x101, 0x3c00, bytes, 2, 0);
    PERR();

    //
    // CLOSE
    //

    err = libusb_reset_device(devh);
    PERR();

    err = libusb_release_interface(devh, 0);
    PERR();

    libusb_close(devh);
    libusb_exit(NULL);

    return 0;
}

