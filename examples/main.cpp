/*
 * <examples/main.cpp>
 * Copyright (c) 2025 YusufBahaKama
 *
 * This file is dedicated to the public domain under CC0 1.0 Universal.
 * See LICENSE-CC0-1.0 for full text or https://creativecommons.org/publicdomain/zero/1.0/
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <cg/mat4.hpp>
#include <cg/vec2.hpp>
#include <iostream>

int main()
{
    cg::Vec2 a(1.0f, 2.0f);
    cg::Vec2 b(3.0f, 4.0f);
    auto c = a + b;
    std::cout << "Result: " << c.x << ", " << c.y << "\n";

    cg::Mat4 d(1.f, 1.f, 1.f, 1.f, 1.f, -1.f, 1.f, 0.f, 1.f, 1.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << d.m[i][j] << ", ";
        }
        std::cout << std::endl;
    }

    d = d.Inverse();
    std::cout << "Printing Inverse\n";

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << d.m[i][j] << ", ";
        }
        std::cout << std::endl;
    }
}
