#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#include <unistd.h>

#define u32 unsigned int

int main() {
  Display *display;

  display = XOpenDisplay(NULL);

  if (display == NULL) {
    printf("Could not open display");

    return -1;
  }

  u32 bar = XKeysymToKeycode(display, XK_bar);
  u32 shiftL = XKeysymToKeycode(display, XK_Shift_L);

  usleep(100 * 1000);

  XTestFakeKeyEvent(display, shiftL, True, 0);
  XTestFakeKeyEvent(display, bar, True, 0);

  XTestFakeKeyEvent(display, bar, False, 0);
  XTestFakeKeyEvent(display, shiftL, False, 0);

  XFlush(display);

  XCloseDisplay(display);

  return 0;
}
