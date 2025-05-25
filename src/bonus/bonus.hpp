#ifndef BONUS_HPP
#define BONUS_HPP

#include "hittable_object/hittable_object.hpp"
#include "raylib.h"

enum class BonusType {
    ExtraBall,
    PaddleSizeIncrease,
    PaddleSizeDecrease,
    BallSpeedUp,
    BallStickiness,
    TemporaryBottom
};

class Bonus : public HittableObject {
public:
    Vector2 pos;
    Vector2 size = { 20.0f, 20.0f };
    BonusType type;
    float fallSpeed = 100.0f;
    bool collected = false;

    Bonus(Vector2 position, BonusType t)
        : pos(position), type(t) {}

    void update(float dt) {
        pos.y += fallSpeed * dt;
    }

    Rectangle getBounds() const override {
        return { pos.x, pos.y, size.x, size.y };
    }

    void onBallHit() override {
    }

    void onCollected() {
        collected = true;
    }

    bool isDestroyed() const override {
        return collected;
    }

    void draw() const override {
        Color color;
        switch (type) {
            case BonusType::ExtraBall:         color = YELLOW;  break;
            case BonusType::PaddleSizeIncrease:color = GREEN;   break;
            case BonusType::PaddleSizeDecrease:color = RED;     break;
            case BonusType::BallSpeedUp:       color = ORANGE;  break;
            case BonusType::BallStickiness:    color = PURPLE;  break;
            case BonusType::TemporaryBottom:   color = SKYBLUE; break;
        }
        DrawRectangleV(pos, size, color);
    }
};


#endif
