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
#include <cg/transformations.hpp>
#include <cg/vec4.hpp>
#include <cmath>
#include <stdexcept>

namespace cg
{

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

template <typename T> Mat4 Mat4::operator*(const T &other) const
{
    Mat4 result;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            try
            {
                result.m[i][j] = this->m[i][j] * static_cast<float>(other);
            }
            catch (const std::exception &)
            {
                throw std::runtime_error("Multiplication with the given type is not supported.");
            }
        }
    }
    return result;
}

Vec4 Mat4::operator*(const Vec4 &other) const
{
    Vec4 result;
    result.x = m[0][0] * other.x + m[0][1] * other.y + m[0][2] * other.z + m[0][3] * other.w;
    result.y = m[1][0] * other.x + m[1][1] * other.y + m[1][2] * other.z + m[1][3] * other.w;
    result.z = m[2][0] * other.x + m[2][1] * other.y + m[2][2] * other.z + m[2][3] * other.w;
    result.w = m[3][0] * other.x + m[3][1] * other.y + m[3][2] * other.z + m[3][3] * other.w;
    return result;
}

template <typename T> Mat4 Mat4::operator/(const T &other) const
{
    Mat4 result;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            try
            {
                if (Transformations::isAllmostEqualFloat(static_cast<float>(other), 0.0f))
                {
                    throw std::runtime_error("Division by zero is not allowed.");
                }
                result.m[i][j] = this->m[i][j] / static_cast<float>(other);
            }
            catch (const std::exception &)
            {
                throw std::runtime_error("Division with the given type is not supported.");
            }
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
    if (Transformations::isAllmostEqualFloat(det, 0.0f))
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
    // The implementation of the Mat4 class appears to be well-structured and follows good practices.
    // However, you could consider adding more functionality or optimizations, such as:
    // 1. Implementing additional matrix operations (e.g., scaling, rotation).
    //
    // 2. Adding operator overloads for scalar multiplication.
    // 5. Adding comments and documentation for better maintainability.
}

bool Mat4::IsEqual(const Mat4 &t) const
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (!Transformations::isAllmostEqualFloat(this->m[i][j], t.m[i][j]))
            {
                return false;
            }
        }
    }
    return true;
}

Mat4 Mat4::Identity() const
{
    return Mat4();
}

Mat4 Mat4::SetRow(Vec4 &other, int rowIndex)
{
    if (rowIndex < 0 || rowIndex >= 4)
    {
        throw std::out_of_range("Row index must be between 0 and 3.");
    };
    m[rowIndex][0] = other.x;
    m[rowIndex][1] = other.y;
    m[rowIndex][2] = other.z;
    m[rowIndex][3] = other.w;
    return *this;
}

Mat4 Mat4::SetCol(Vec4 &other, int colIndex)
{
    if (colIndex < 0 || colIndex >= 4)
    {
        throw std::out_of_range("Column index must be between 0 and 3.");
    };
    m[0][colIndex] = other.x;
    m[1][colIndex] = other.y;
    m[2][colIndex] = other.z;
    m[3][colIndex] = other.w;
    return *this;
}

Vec4 Mat4::GetRow(Mat4 &mat4, int rowIndex) const
{
    if (rowIndex < 0 || rowIndex >= 4)
    {
        throw std::out_of_range("Row index must be between 0 and 3.");
    };
    return Vec4(mat4.m[rowIndex][0], mat4.m[rowIndex][1], mat4.m[rowIndex][2], mat4.m[rowIndex][3]);
}

Vec4 Mat4::GetCol(Mat4 &mat4, int colIndex) const
{
    if (colIndex < 0 || colIndex >= 4)
    {
        throw std::out_of_range("Column index must be between 0 and 3.");
    };
    return Vec4(mat4.m[0][colIndex], mat4.m[1][colIndex], mat4.m[2][colIndex], mat4.m[3][colIndex]);
}

float &Mat4::operator()(int row, int col)
{
    if (row < 0 || row >= 4 || col < 0 || col >= 4)
        throw std::out_of_range("Mat4 index out of range");
    return m[row][col];
}

const float &Mat4::operator()(int row, int col) const
{
    if (row < 0 || row >= 4 || col < 0 || col >= 4)
        throw std::out_of_range("Mat4 index out of range");
    return m[row][col];
}

std::array<float, 4> &Mat4::operator[](int row)
{
    if (row < 0 || row >= 4)
        throw std::out_of_range("Mat4 row index out of range");
    return m[row];
}

const std::array<float, 4> &Mat4::operator[](int row) const
{
    if (row < 0 || row >= 4)
        throw std::out_of_range("Mat4 row index out of range");
    return m[row];
}
} // namespace cg
