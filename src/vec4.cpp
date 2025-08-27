/*
 * <src/vec4.cpp>
 * Copyright (c) 2025 YusufBahaKama
 *
 * This file is dedicated to the public domain under CC0 1.0 Universal.
 * See LICENSE-CC0-1.0 for full text or https://creativecommons.org/publicdomain/zero/1.0/
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "cg/vec4.hpp"
#include <cg/mat4.hpp>
#include <cg/transformations.hpp>
#include <cmath>
#include <stdexcept>

namespace cg
{

Vec4::Vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
{
}

Vec4::Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{
}

float Vec4::length() const
{
    return std::sqrt((x * x) + (y * y) + (z * z) + (w * w));
}

Vec4 Vec4::operator+(const Vec4 &other) const
{
    return Vec4(x + other.x, y + other.y, z + other.z, w + other.w);
}

Vec4 Vec4::operator-(const Vec4 &other) const
{
    return Vec4(x - other.x, y - other.y, z - other.z, w - other.w);
}

template <typename T> Vec4 Vec4::operator*(const T &other) const
{
    try
    {
        return Vec4(x * other, y * other, z * other, w * other);
    }
    catch (const std::exception &)
    {
        throw std::runtime_error("Multiplication with the given type is not supported.");
    }
}

template <typename T> Vec4 Vec4::operator/(const T &other) const
{
    try
    {
        if (Transformations::isAllmostEqualFloat(static_cast<float>(other), 0.0f))
        {
            throw std::runtime_error("Division by zero is not allowed!");
        }
        return Vec4(x / other, y / other, z / other, w / other);
    }
    catch (const std::exception &)
    {
        throw std::runtime_error("Division with the given type is not supported.");
    }
}

float Vec4::dot(const Vec4 &other) const
{
    return (x * other.x) + (y * other.y) + (z * other.z) + (w * other.w);
}

Vec4 Vec4::Normalize() const
{
    float len = Vec4::length();
    if (Transformations::isAllmostEqualFloat(len, 0.0f))
    {
        throw std::runtime_error("Cannot normalize a zero-length vector.");
    }
    return Vec4(x / len, y / len, z / len, w / len);
}

Vec4 Vec4::operator*(const Mat4 &other) const
{
    Vec4 result;
    result.x = other.m[0][0] * x + other.m[0][1] * y + other.m[0][2] * z + other.m[0][3] * w;
    result.y = other.m[1][0] * x + other.m[1][1] * y + other.m[1][2] * z + other.m[1][3] * w;
    result.z = other.m[2][0] * x + other.m[2][1] * y + other.m[2][2] * z + other.m[2][3] * w;
    result.w = other.m[3][0] * x + other.m[3][1] * y + other.m[3][2] * z + other.m[3][3] * w;
    return result;
}
} // namespace cg
