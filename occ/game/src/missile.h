#ifndef MISSILE_H_
#define MISSILE_H_

#include "geometry.h"
#include "misc.h"

struct Missile
{
  Missile()
    : alive(false),
      frame(0),
      position(),
      right(false)
  {
  }

  bool alive;
  unsigned frame;
  geometry::Position position;
  bool right;  // Direction...

  static constexpr auto size = geometry::Size(16, 16);
  static constexpr auto speed = misc::make_array(4, 4, 4, 4, 4, 4, 6, 8, 10, 12, 14);
};

#endif  // MISSILE_H_
