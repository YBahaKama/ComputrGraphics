/*
 * <src/vec2.cpp>
 * Copyright (c) 2025 YusufBahaKama
 *
 * This file is dedicated to the public domain under CC0 1.0 Universal.
 * See LICENSE-CC0-1.0 for full text or https://creativecommons.org/publicdomain/zero/1.0/
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "cg/vec2.hpp"
#include <cmath>
#include <stdexcept>

namespace cg
{

Vec2::Vec2() : x(0.0f), y(0.0f)
{
}

Vec2::Vec2(float x, float y) : x(x), y(y)
{
}

float Vec2::length() const
{
    return std::sqrt(x * x + y * y);
}

Vec2 Vec2::operator+(const Vec2 &other) const
{
    return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(const Vec2 &other) const
{
    return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator*(const Vec2 &other) const
{
    return Vec2(x * other.x, y * other.y);
}

Vec2 Vec2::operator/(const Vec2 &other) const
{
    return Vec2(x / other.x, y / other.y);
}

Vec2 Vec2::Normalize() const
{
    float len = Vec2::length();
    if (len == 0)
        throw std::runtime_error("Cannot normalize a zero-length vector.");
    return Vec2(x / len, y / len);
}

float Vec2::dot(const Vec2 &other) const
{
    return x * other.x + y * other.y;
}

float Vec2::cross(const Vec2 &other) const
{
    return x * other.y - y * other.x;
}
} // namespace cg
