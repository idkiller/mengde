#ifndef LAYOUT_HELPER_H_
#define LAYOUT_HELPER_H_

#include "util/common.h"
#include "rect.h"

class LayoutHelper {
 public:
  enum Align {
    kAlignNone = 0,
    kAlignLft  = 0x01,
    kAlignHMid = 0x02,
    kAlignRgt  = 0x03,
    kAlignTop  = 0x01 << 2,
    kAlignVMid = 0x02 << 2,
    kAlignBot  = 0x03 << 2,

    // composite types
    kAlignLftTop = kAlignLft | kAlignTop,
    kAlignMidTop = kAlignHMid | kAlignTop,
    kAlignRgtTop = kAlignRgt | kAlignTop,
    kAlignLftMid = kAlignLft | kAlignVMid,
    kAlignCenter = kAlignHMid | kAlignVMid,
    kAlignRgtMid = kAlignRgt | kAlignVMid,
    kAlignLftBot = kAlignLft | kAlignBot,
    kAlignMidBot = kAlignHMid | kAlignBot,
    kAlignRgtBot = kAlignRgt | kAlignBot,
  };

 public:
  static Rect CalcPosition(Vec2D, Vec2D, Align, int = 0);
  static Rect CalcPosition(const Rect*, Vec2D, Align, int = 0);

 public:
  static const int kDefaultSpace = 8; // default value for margin and padding
};

#endif // LAYOUT_HELPER_H_
