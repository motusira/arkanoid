#ifndef HITTABLE_OBJECT_HPP
#define HITTABLE_OBJECT_HPP

#include "raylib.h"

class HittableObject {
public:
  virtual ~HittableObject() = default;

  virtual Rectangle getBounds() const = 0;

  virtual void onBallHit() = 0;

  virtual bool isDestroyed() const { return false; }

  virtual void draw() const = 0;
};

#endif
