/*
 * <include/cg/mat4.hpp>
 * Copyright (c) 2025 YusufBahaKama
 *
 * This file is dedicated to the public domain under CC0 1.0 Universal.
 * See LICENSE-CC0-1.0 for full text or https://creativecommons.org/publicdomain/zero/1.0/
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#pragma once
#include "Export.h"
#include <cmath>

namespace cg
{
class CG_API Mat4
{
  public:
    float m[4][4];

    Mat4();
    Mat4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21,
         float m22, float m23, float m30, float m31, float m32, float m33);

    Mat4 operator*(const Mat4 &other) const;
    Mat4 operator+(const Mat4 &other) const;
    Mat4 operator-(const Mat4 &other) const;

    float Determinant() const;

    Mat4 Transpose() const;
    Mat4 Minor() const;
    Mat4 Cofactor() const;
    Mat4 Inverse() const;

    static bool isAllmostEqualFloat(float a, float b);
};

} // namespace cg
