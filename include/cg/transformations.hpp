/*
 * <include/cg/transformations.hpp>
 * Copyright (c) 2025 YusufBahaKama
 *
 * This file is dedicated to the public domain under CC0 1.0 Universal.
 * See LICENSE-CC0-1.0 for full text or https://creativecommons.org/publicdomain/zero/1.0/
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#pragma once
#include "Export.h"
#include "vec3.hpp"

namespace cg
{

class CG_API Transformations
{
  public:
    static float degreesToRadians(float degrees);
    static float radiansToDegrees(float radians);
    static bool isAllmostEqualFloat(float a, float b);

    Mat4 translationMatrix(const Vec3 &);
    Mat4 rotationMatrix(float angle, const Vec3 &axis);
    Mat4 scalingMatrix(const Vec3 &);
};
} // namespace cg
