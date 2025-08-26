/*
 * <src/vec2.cpp>
 * Copyright (c) 2025 YusufBahaKama
 *
 * This file is dedicated to the public domain under CC0 1.0 Universal.
 * See LICENSE-CC0-1.0 for full text or
 * https://creativecommons.org/publicdomain/zero/1.0/
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "cg/mat4.hpp"
#include <cmath>
#include <stdexcept>

namespace cg
{

bool Mat4::isAllmostEqualFloat(float a, float b)
{
    constexpr float EPSILON = 1e-6f;
    return std::fabs(a - b) < EPSILON;
}

Mat4::Mat4()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; j++)
        {
            m[i][j] = ((i * 4 + j) % 5 == 0) ? 1.0f : 0.0f; // Identity matrix
        }
    }
}

Mat4::Mat4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21,
           float m22, float m23, float m30, float m31, float m32, float m33)
{
    m[0][0] = m00;
    m[0][1] = m01;
    m[0][2] = m02;
    m[0][3] = m03;
    m[1][0] = m10;
    m[1][1] = m11;
    m[1][2] = m12;
    m[1][3] = m13;
    m[2][0] = m20;
    m[2][1] = m21;
    m[2][2] = m22;
    m[2][3] = m23;
    m[3][0] = m30;
    m[3][1] = m31;
    m[3][2] = m32;
    m[3][3] = m33;
}

Mat4 Mat4::operator*(const Mat4 &other) const
{
    Mat4 result;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            result.m[i][j] =
                m[i][0] * other.m[0][j] + m[i][1] * other.m[1][j] + m[i][2] * other.m[2][j] + m[i][3] * other.m[3][j];
        }
    }
    return result;
}

Mat4 Mat4::operator+(const Mat4 &other) const
{
    Mat4 result;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; j++)
        {
            result.m[i][j] = this->m[i][j] + other.m[i][j];
        }
    }
    return result;
}

Mat4 Mat4::operator-(const Mat4 &other) const
{
    Mat4 result;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; j++)
        {
            result.m[i][j] = this->m[i][j] - other.m[i][j];
        }
    }
    return result;
}

float Mat4::Determinant() const
{
    float det; // Laplace expansion
    det = m[0][3] * m[1][2] * m[2][1] * m[3][0] - m[0][2] * m[1][3] * m[2][1] * m[3][0] -
          m[0][3] * m[1][1] * m[2][2] * m[3][0] + m[0][1] * m[1][3] * m[2][2] * m[3][0] +
          m[0][2] * m[1][1] * m[2][3] * m[3][0] - m[0][1] * m[1][2] * m[2][3] * m[3][0];
    return det;
}

Mat4 Mat4::Transpose() const
{
    Mat4 result;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            result.m[i][j] = m[j][i];
        }
    }
    return result;
}

Mat4 Mat4::Minor() const
{
    Mat4 result;

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; j++)
        {
            // Create a 3x3 matrix by excluding row i and column j
            float minor[3][3]{};
            int rowIndex = 0, colIndex = 0;
            for (int row = 0; row < 4; ++row)
            {
                if (row == i)
                    continue;
                colIndex = 0;
                for (int col = 0; col < 4; ++col)
                {
                    if (col == j)
                        continue;
                    minor[rowIndex][colIndex] = this->m[row][col];
                    colIndex++;
                }
                rowIndex++;
            }

            // Calculate the determinant of the 3x3 matrix
            float det = minor[0][0] * (minor[1][1] * minor[2][2] - minor[1][2] * minor[2][1]) -
                        minor[0][1] * (minor[1][0] * minor[2][2] - minor[1][2] * minor[2][0]) +
                        minor[0][2] * (minor[1][0] * minor[2][1] - minor[1][1] * minor[2][0]);

            result.m[i][j] = det;
        }
    }

    return result;
}

Mat4 Mat4::Cofactor() const
{
    Mat4 result = Minor();

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; j++)
        {
            result.m[i][j] = result.m[i][j] * static_cast<float>(std::pow(-1.0f, i + j));
        }
    }

    return result;
}

Mat4 Mat4::Inverse() const
{
    const float det = Determinant();
    if (Mat4::isAllmostEqualFloat(det, 0.0f))
    {
        throw std::runtime_error("Matrix is singular and cannot be inverted.");
    }

    Mat4 result = Cofactor();

    result = result.Transpose();

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; j++)
        {
            result.m[i][j] *= 1.0f / det;
        }
    }

    return result;
}

} // namespace cg
