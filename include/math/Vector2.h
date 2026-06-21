#pragma once

struct Vector2
{
    float x;
    float y;

    Vector2()
        : x(0.0f),
          y(0.0f)
    {
    }

    Vector2(
        float px,
        float py)
        : x(px),
          y(py)
    {
    }

    Vector2 operator+(
        const Vector2& rhs) const
    {
        return
        {
            x + rhs.x,
            y + rhs.y
        };
    }

    Vector2 operator*(
        float scalar) const
    {
        return
        {
            x * scalar,
            y * scalar
        };
    }
};