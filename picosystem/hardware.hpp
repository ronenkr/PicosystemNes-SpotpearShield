#pragma once

#include <memory>
#include <cstdint>
#include <climits>
#include <initializer_list>

#include <string>
#include <vector>

#include "pico/stdlib.h"

// limit sound frequency below 10khz to protect piezo.
// #define PWM_RANGE_BITS (10) // dirty hack , also defined in hardware.cpp

namespace picosystem {


  // io state
  uint32_t _io = 0;  // dirty hack, also defined in picosystem.hpp. 
// hardware
  bool        pressed(uint32_t b);
  bool        button(uint32_t b);
  uint32_t    battery();
  void        led(uint8_t r, uint8_t g, uint8_t b);
  void        backlight(uint8_t b);

  // weird and wonderful...
  //void        screenshot();

  // internal methods - do not call directly, will change!
  void       _logo();
  void       _init_hardware();
  void       _start_audio();
  uint32_t   _gpio_get();
  void       _gpio_get2();
  float      _battery_voltage();
  void       _reset_to_dfu();
  void       _wait_vsync();
  void       _flip();
  void       _flipbuffer(void * buffer, uint32_t c);
  bool       _is_flipping();
  void       _camera_offset(int32_t &x, int32_t &y);
  void       _camera_offset(bool enable);
  void       _update_audio();
  void       _play_note(uint32_t f, uint32_t v);

  // input pins
enum button {
    UP    = 16,
    DOWN  = 14,
    LEFT  = 13,
    RIGHT = 17,
    A     = 3,
    B     = 6,
    X     = 2,
    Y     = 4,
    START = 27,
    SELECT = 26,
    R = 1,
    L = 18
  };

  // utility

  uint32_t    time();
  uint32_t    time_us();
  void        sleep(uint32_t d);
  void	      psg_vol(int);
}
