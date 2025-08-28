/*
 * <src/transformations.cpp>
 * Copyright (c) 2025 YusufBahaKama
 *
 * This file is dedicated to the public domain under CC0 1.0 Universal.
 * See LICENSE-CC0-1.0 for full text or https://creativecommons.org/publicdomain/zero/1.0/
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#define _USE_MATH_DEFINES
#include <cg/mat4.hpp>
#include <cg/vec3.hpp>
#include <cmath>
#include <stdexcept>

namespace cg
{
static float degreesToRadians(float degrees)
{
    return degrees * (M_PI / 180.0f);
}
static float radiansToDegrees(float radians)
{
    return radians * (180.0f / M_PI);
}
static bool isAllmostEqualFloat(float a, float b)
{
    constexpr float EPSILON = 1e-6f;
    return std::fabs(a - b) < EPSILON;
}

} // namespace cg
