/*
 * Copyright (c) 2019 - 2021 Geode-solutions
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include <iostream>
#include <string>

class OverloadMethod
{
public:
    void test( const std::string& number )
    {
        std::cout << "Number " << number << std::endl;
    }

    void test( int number )
    {
        std::cout << "Number " << number << std::endl;
    }

    void test( int number, int another_number )
    {
        std::cout << "Number " << number + another_number << std::endl;
    }
};

#include <genepi/genepi.h>

GENEPI_CLASS( OverloadMethod )
{
    GENEPI_CONSTRUCTOR();
    GENEPI_MULTIMETHOD( test, void, "test_string", const std::string& );
    GENEPI_MULTIMETHOD( test, void, "test_int", int );
    GENEPI_MULTIMETHOD( test, void, "test_int2", int, int );
}

GENEPI_MODULE( overloaded_methods );
