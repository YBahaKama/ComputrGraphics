/*
 * <src/transformations.cpp>
 * Copyright (c) 2025 YusufBahaKama
 *
 * This file is dedicated to the public domain under CC0 1.0 Universal.
 * See LICENSE-CC0-1.0 for full text or https://creativecommons.org/publicdomain/zero/1.0/
 *
 * SPDX-License-Identifier: CC0-1.0
 *
 * Portions of this file are derived from the following source:
 * https://github.com/toji/gl-matrix/blob/accefb6ddf1897a0dc443bbc7664c90e67af6455/src/mat4.js
 * Licensed under the MIT License.
 *
 * Copyright (c) 2015-2025, Brandon Jones, Colin MacKenzie IV.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and
 * to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of
 * the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 *
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

Mat4 translationMatrix(const Vec3 &tran)
{
    Mat4 t;
    t[0][3] = tran.x;
    t[1][3] = tran.y;
    t[2][3] = tran.z;
    t[3][3] = 1.0f;
    return t;
}

Mat4 rotationMatrixColumn(float angle, const Vec3 &axis)
{
    float x = axis.x;
    float y = axis.y;
    float z = axis.z;

    float len = std::sqrt(x * x + y * y + z * z);
    if (isAllmostEqualFloat(len, 0.0f))
    {
        throw std::runtime_error("length = 0, cannot produce a rotation matrix!");
    }

    // Normalize
    float invLen = 1.0f / len;
    x *= invLen;
    y *= invLen;
    z *= invLen;

    float s = std::sin(angle);
    float c = std::cos(angle);
    float t = 1.0f - c;

    float xx = x * x;
    float yy = y * y;
    float zz = z * z;
    float xy = x * y;
    float xz = x * z;
    float yz = y * z;

    Mat4 out;

    // 3x3 rotation block (Rodrigues formula, column-vector convention)
    out[0][0] = xx * t + c;
    out[0][1] = xy * t - z * s;
    out[0][2] = xz * t + y * s;
    out[0][3] = 0.0f;

    out[1][0] = xy * t + z * s;
    out[1][1] = yy * t + c;
    out[1][2] = yz * t - x * s;
    out[1][3] = 0.0f;

    out[2][0] = xz * t - y * s;
    out[2][1] = yz * t + x * s;
    out[2][2] = zz * t + c;
    out[2][3] = 0.0f;

    // Homogeneous row
    out[3][0] = 0.0f;
    out[3][1] = 0.0f;
    out[3][2] = 0.0f;
    out[3][3] = 1.0f;

    return out;
    /*
     * This function is based on the following gl-matrix function:
     * gl-matrix.fromRotation(out, rad, axis)
     */
}

Mat4 scalingMatrix(const Vec3 &scale)
{
    Mat4 s;
    s[0][0] = scale.x;
    s[1][1] = scale.y;
    s[2][2] = scale.z;
}

} // namespace cg
