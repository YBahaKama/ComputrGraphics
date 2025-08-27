/*
 * <include/cg/vec4.hpp>
 * Copyright (c) 2025 YusufBahaKama
 *
 * This file is dedicated to the public domain under CC0 1.0 Universal.
 * See LICENSE-CC0-1.0 for full text or https://creativecommons.org/publicdomain/zero/1.0/
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#pragma once
#include "Export.h"
#include "mat4.hpp"

namespace cg
{
class Vec4
{
  public:
    float x, y, z, w;

    Vec4();
    Vec4(float x, float y, float z, float w);

    float length() const;

    template <typename T> Vec4 operator*(const T &other) const;
    template <typename T> Vec4 operator/(const T &other) const;
    Vec4 operator+(const Vec4 &other) const;
    Vec4 operator-(const Vec4 &other) const;
    Vec4 operator*(const Mat4 &other) const;

    Vec4 Normalize() const;
    float dot(const Vec4 &other) const;
};
} // namespace cg
