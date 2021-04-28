/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/Diff/blob/main/LICENSE.txt
*/

#include "AlgorithmsTests.h"
#include "Ishiko/Diff/Algorithms.h"

using namespace Ishiko;
using namespace Ishiko::Diff;
using namespace Ishiko::Tests;

AlgorithmsTests::AlgorithmsTests(const TestNumber& number, const TestEnvironment& environment)
    : TestSequence(number, "Algorithms tests", environment)
{
    append<HeapAllocationErrorsTest>("WagnerFischerAlgorithm test 1", WagnerFischerAlgorithmTest1);
    append<HeapAllocationErrorsTest>("WagnerFischerAlgorithm test 2", WagnerFischerAlgorithmTest2);
    append<HeapAllocationErrorsTest>("WagnerFischerAlgorithm test 3", WagnerFischerAlgorithmTest3);
    append<HeapAllocationErrorsTest>("WagnerFischerAlgorithm test 4", WagnerFischerAlgorithmTest4);
    append<HeapAllocationErrorsTest>("WagnerFischerAlgorithm test 5", WagnerFischerAlgorithmTest5);
    append<HeapAllocationErrorsTest>("WagnerFischerAlgorithm test 6", WagnerFischerAlgorithmTest6);
    append<HeapAllocationErrorsTest>("MyersAlgorithm test 1", MyersAlgorithmTest1);
    append<HeapAllocationErrorsTest>("MyersAlgorithm test 2", MyersAlgorithmTest2);
    append<HeapAllocationErrorsTest>("MyersAlgorithm test 3", MyersAlgorithmTest3);
    append<HeapAllocationErrorsTest>("MyersAlgorithm test 4", MyersAlgorithmTest4);
    append<HeapAllocationErrorsTest>("MyersAlgorithm test 5", MyersAlgorithmTest5);
    append<HeapAllocationErrorsTest>("MyersAlgorithm test 6", MyersAlgorithmTest6);
    append<HeapAllocationErrorsTest>("MyersAlgorithm test 7", MyersAlgorithmTest7);
    append<HeapAllocationErrorsTest>("MyersAlgorithm test 8", MyersAlgorithmTest8);
    append<HeapAllocationErrorsTest>("MyersAlgorithm test 9", MyersAlgorithmTest9);
    append<HeapAllocationErrorsTest>("MyersAlgorithm test 10", MyersAlgorithmTest10);
    append<HeapAllocationErrorsTest>("MyersAlgorithm test 11", MyersAlgorithmTest11);
    append<HeapAllocationErrorsTest>("MyersAlgorithm test 12", MyersAlgorithmTest12);
}

void AlgorithmsTests::WagnerFischerAlgorithmTest1(Test& test)
{
    size_t distance = WagnerFischerAlgorithm("", "");

    ISHTF_FAIL_IF_NEQ(distance, 0);
    ISHTF_PASS();
}

void AlgorithmsTests::WagnerFischerAlgorithmTest2(Test& test)
{
    size_t distance = WagnerFischerAlgorithm("abc", "");

    ISHTF_FAIL_IF_NEQ(distance, 3);
    ISHTF_PASS();
}

void AlgorithmsTests::WagnerFischerAlgorithmTest3(Test& test)
{
    size_t distance = WagnerFischerAlgorithm("", "abc");

    ISHTF_FAIL_IF_NEQ(distance, 3);
    ISHTF_PASS();
}

void AlgorithmsTests::WagnerFischerAlgorithmTest4(Test& test)
{
    size_t distance = WagnerFischerAlgorithm("abc", "abc");

    ISHTF_FAIL_IF_NEQ(distance, 0);
    ISHTF_PASS();
}

void AlgorithmsTests::WagnerFischerAlgorithmTest5(Test& test)
{
    size_t distance = WagnerFischerAlgorithm("kitten", "sitting");

    ISHTF_FAIL_IF_NEQ(distance, 3);
    ISHTF_PASS();
}

void AlgorithmsTests::WagnerFischerAlgorithmTest6(Test& test)
{
    size_t distance1 = WagnerFischerAlgorithm("kitten", "smitten");
    size_t distance2 = WagnerFischerAlgorithm("kitten", "mitten");
    size_t distance3 = WagnerFischerAlgorithm("kitten", "kitty");
    size_t distance4 = WagnerFischerAlgorithm("kitten", "fitting");
    size_t distance5 = WagnerFischerAlgorithm("kitten", "written");
    size_t distance6 = WagnerFischerAlgorithm("Saturday", "Sunday");

    ISHTF_FAIL_IF_NEQ(distance1, 2);
    ISHTF_FAIL_IF_NEQ(distance2, 1);
    ISHTF_FAIL_IF_NEQ(distance3, 2);
    ISHTF_FAIL_IF_NEQ(distance4, 3);
    ISHTF_FAIL_IF_NEQ(distance5, 2);
    ISHTF_FAIL_IF_NEQ(distance6, 3);
    ISHTF_PASS();
}

void AlgorithmsTests::MyersAlgorithmTest1(Test& test)
{
    size_t distance = MyersAlgorithm("", "");

    ISHTF_FAIL_IF_NEQ(distance, 0);
    ISHTF_PASS();
}

void AlgorithmsTests::MyersAlgorithmTest2(Test& test)
{
    size_t distance = MyersAlgorithm("abc", "");

    ISHTF_FAIL_IF_NEQ(distance, 3);
    ISHTF_PASS();
}

void AlgorithmsTests::MyersAlgorithmTest3(Test& test)
{
    size_t distance = MyersAlgorithm("", "abc");

    ISHTF_FAIL_IF_NEQ(distance, 3);
    ISHTF_PASS();
}

void AlgorithmsTests::MyersAlgorithmTest4(Test& test)
{
    size_t distance = MyersAlgorithm("abc", "abc");

    ISHTF_FAIL_IF_NEQ(distance, 0);
    ISHTF_PASS();
}

void AlgorithmsTests::MyersAlgorithmTest5(Test& test)
{
    size_t distance = MyersAlgorithm("kitten", "sitting");

    ISHTF_FAIL_IF_NEQ(distance, 5);
    ISHTF_PASS();
}

void AlgorithmsTests::MyersAlgorithmTest6(Test& test)
{
    size_t distance1 = MyersAlgorithm("kitten", "smitten");
    size_t distance2 = MyersAlgorithm("kitten", "mitten");
    size_t distance3 = MyersAlgorithm("kitten", "kitty");
    size_t distance4 = MyersAlgorithm("kitten", "fitting");
    size_t distance5 = MyersAlgorithm("kitten", "written");
    size_t distance6 = MyersAlgorithm("Saturday", "Sunday");

    ISHTF_FAIL_IF_NEQ(distance1, 3);
    ISHTF_FAIL_IF_NEQ(distance2, 2);
    ISHTF_FAIL_IF_NEQ(distance3, 3);
    ISHTF_FAIL_IF_NEQ(distance4, 5);
    ISHTF_FAIL_IF_NEQ(distance5, 3);
    ISHTF_FAIL_IF_NEQ(distance6, 4);
    ISHTF_PASS();
}

void AlgorithmsTests::MyersAlgorithmTest7(Test& test)
{
    std::vector<Point2D<int>> path;
    size_t distance = MyersAlgorithm("", "", path);

    ISHTF_FAIL_IF_NEQ(distance, 0);
    ISHTF_FAIL_IF_NEQ(path.size(), 0);
    ISHTF_PASS();
}

void AlgorithmsTests::MyersAlgorithmTest8(Test& test)
{
    std::vector<Point2D<int>> path;
    size_t distance = MyersAlgorithm("abc", "", path);

    ISHTF_FAIL_IF_NEQ(distance, 3);
    ISHTF_FAIL_IF_NEQ(path, std::vector<Point2D<int>>({ {1,0}, {2,0}, {3,0} }));
    ISHTF_PASS();
}

void AlgorithmsTests::MyersAlgorithmTest9(Test& test)
{
    std::vector<Point2D<int>> path;
    size_t distance = MyersAlgorithm("", "abc", path);

    ISHTF_FAIL_IF_NEQ(distance, 3);
    ISHTF_FAIL_IF_NEQ(path, std::vector<Point2D<int>>({ {0,1}, {0,2}, {0,3} }));
    ISHTF_PASS();
}

void AlgorithmsTests::MyersAlgorithmTest10(Test& test)
{
    std::vector<Point2D<int>> path;
    size_t distance = MyersAlgorithm("abc", "abc", path);

    ISHTF_FAIL_IF_NEQ(distance, 0);
    ISHTF_FAIL_IF_NEQ(path, std::vector<Point2D<int>>({ {3,3} }));
    ISHTF_PASS();
}

void AlgorithmsTests::MyersAlgorithmTest11(Test& test)
{
    std::vector<Point2D<int>> path;
    size_t distance = MyersAlgorithm("kitten", "sitting", path);

    ISHTF_FAIL_IF_NEQ(distance, 5);
    ISHTF_FAIL_IF_NEQ(path, std::vector<Point2D<int>>({ {1,0}, {4,4}, {5,4}, {6,6}, {6,7} }));
    ISHTF_PASS();
}

void AlgorithmsTests::MyersAlgorithmTest12(Test& test)
{
    std::vector<Point2D<int>> path1;
    size_t distance1 = MyersAlgorithm("kitten", "smitten", path1);
    std::vector<Point2D<int>> path2;
    size_t distance2 = MyersAlgorithm("kitten", "mitten", path2);
    std::vector<Point2D<int>> path3;
    size_t distance3 = MyersAlgorithm("kitten", "kitty", path3);
    std::vector<Point2D<int>> path4;
    size_t distance4 = MyersAlgorithm("kitten", "fitting", path4);
    std::vector<Point2D<int>> path5;
    size_t distance5 = MyersAlgorithm("kitten", "written", path5);
    std::vector<Point2D<int>> path6;
    size_t distance6 = MyersAlgorithm("Saturday", "Sunday", path6);

    ISHTF_FAIL_IF_NEQ(distance1, 3);
    ISHTF_FAIL_IF_NEQ(path1, std::vector<Point2D<int>>({ {1,0}, {1,1}, {6,7} }));
    ISHTF_FAIL_IF_NEQ(distance2, 2);
    ISHTF_FAIL_IF_NEQ(path2, std::vector<Point2D<int>>({ {1,0}, {6,6} }));
    ISHTF_FAIL_IF_NEQ(distance3, 3);
    ISHTF_FAIL_IF_NEQ(path3, std::vector<Point2D<int>>({ {5,4}, {6,4}, {6,5} }));
    ISHTF_FAIL_IF_NEQ(distance4, 5);
    ISHTF_FAIL_IF_NEQ(path4, std::vector<Point2D<int>>({ {1,0}, {4,4}, {5,4}, {6,6}, {6,7} }));
    ISHTF_FAIL_IF_NEQ(distance5, 3);
    ISHTF_FAIL_IF_NEQ(path5, std::vector<Point2D<int>>({ {1,0}, {1,1}, {6,7} }));
    ISHTF_FAIL_IF_NEQ(distance6, 4);
    ISHTF_FAIL_IF_NEQ(path6, std::vector<Point2D<int>>({ {2,1}, {4,2}, {5,2}, {8,6} }));
    ISHTF_PASS();
}
