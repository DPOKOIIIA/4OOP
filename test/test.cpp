#include "../include/figures.h"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

// Тесты для Octagon с разными типами
void testOctagonArea() {
    Octagon<double> o1(0, 0, 1);
    assert(abs(o1.area() - 2 * tan(M_PI/8)) < 1e-6);
    
    Octagon<float> o2(0, 0, 2.0f);
    assert(abs(o2.area() - 8 * tan(M_PI/8)) < 1e-6);
    
    Octagon<int> o3(0, 0, 1);
    assert(o3.area() > 0); // Проверка что площадь вычисляется для int
    
    cout << "Octagon area tests passed!" << endl;
}

void testOctagonCentroid() {
    Octagon<double> o1(0, 0, 1);
    Point<double> c1 = o1.centroid();
    assert(c1.x == 0 && c1.y == 0);
    
    Octagon<int> o2(5, 3, 2);
    Point<int> c2 = o2.centroid();
    assert(c2.x == 5 && c2.y == 3);
    
    Octagon<float> o3(-2, -4, 1.5f);
    Point<float> c3 = o3.centroid();
    assert(c3.x == -2 && c3.y == -4);
    
    cout << "Octagon centroid tests passed!" << endl;
}

void testOctagonConversion() {
    Octagon<double> o1(0, 0, 1);
    double area1 = static_cast<double>(o1);
    assert(abs(area1 - 2 * tan(M_PI/8)) < 1e-6);
    
    Octagon<int> o2(0, 0, 2);
    double area2 = static_cast<double>(o2);
    assert(area2 > 0);
    
    Octagon<float> o3(0, 0, 1.5f);
    double area3 = static_cast<double>(o3);
    assert(area3 > 0);
    
    cout << "Octagon conversion tests passed!" << endl;
}

// Тесты для Triangle с разными типами
void testTriangleArea() {
    Triangle<double> t1(0, 0, 1);
    assert(abs(t1.area() - (3*sqrt(3)/4)) < 1e-6);
    
    Triangle<float> t2(0, 0, 2.0f);
    assert(abs(t2.area() - (3*sqrt(3))) < 1e-6);
    
    Triangle<int> t3(0, 0, 1);
    assert(t3.area() > 0);
    
    cout << "Triangle area tests passed!" << endl;
}

void testTriangleCentroid() {
    Triangle<double> t1(0, 0, 1);
    Point<double> c1 = t1.centroid();
    assert(c1.x == 0 && c1.y == 0);
    
    Triangle<int> t2(3, 7, 2);
    Point<int> c2 = t2.centroid();
    assert(c2.x == 3 && c2.y == 7);
    
    Triangle<float> t3(-1, -5, 1.5f);
    Point<float> c3 = t3.centroid();
    assert(c3.x == -1 && c3.y == -5);
    
    cout << "Triangle centroid tests passed!" << endl;
}

void testTriangleConversion() {
    Triangle<double> t1(0, 0, 1);
    double area1 = static_cast<double>(t1);
    assert(abs(area1 - (3*sqrt(3)/4)) < 1e-6);
    
    Triangle<int> t2(0, 0, 3);
    double area2 = static_cast<double>(t2);
    assert(area2 > 0);
    
    Triangle<float> t3(0, 0, 2.0f);
    double area3 = static_cast<double>(t3);
    assert(area3 > 0);
    
    cout << "Triangle conversion tests passed!" << endl;
}

// Тесты для Square с разными типами
void testSquareArea() {
    Square<double> s1(0, 0, 1);
    assert(abs(s1.area() - 2.0) < 1e-6);
    
    Square<float> s2(0, 0, 2.0f);
    assert(abs(s2.area() - 8.0) < 1e-6);
    
    Square<int> s3(0, 0, 1);
    assert(s3.area() == 2.0); // Для int должно работать
    
    cout << "Square area tests passed!" << endl;
}

void testSquareCentroid() {
    Square<double> s1(0, 0, 1);
    Point<double> c1 = s1.centroid();
    assert(c1.x == 0 && c1.y == 0);
    
    Square<int> s2(4, 6, 2);
    Point<int> c2 = s2.centroid();
    assert(c2.x == 4 && c2.y == 6);
    
    Square<float> s3(-3, -2, 1.5f);
    Point<float> c3 = s3.centroid();
    assert(c3.x == -3 && c3.y == -2);
    
    cout << "Square centroid tests passed!" << endl;
}

void testSquareConversion() {
    Square<double> s1(0, 0, 1);
    double area1 = static_cast<double>(s1);
    assert(abs(area1 - 2.0) < 1e-6);
    
    Square<int> s2(0, 0, 2);
    double area2 = static_cast<double>(s2);
    assert(area2 == 8.0);
    
    Square<float> s3(0, 0, 1.5f);
    double area3 = static_cast<double>(s3);
    assert(area3 > 0);
    
    cout << "Square conversion tests passed!" << endl;
}

// Тесты для Array с разными типами
void testArrayBasicOperations() {
    Array<Figure<double>> arr1;
    Array<Figure<float>> arr2;
    Array<Figure<int>> arr3;
    
    // Тест добавления для double
    arr1.add(make_shared<Octagon<double>>(0,0,1));
    assert(arr1.size() == 1);
    
    // Тест добавления для float
    arr2.add(make_shared<Triangle<float>>(0,0,1.0f));
    assert(arr2.size() == 1);
    
    // Тест добавления для int
    arr3.add(make_shared<Square<int>>(0,0,1));
    assert(arr3.size() == 1);
    
    cout << "Array basic operations test passed!" << endl;
}

void testArrayRemove() {
    Array<Figure<double>> arr;
    arr.add(make_shared<Octagon<double>>(0,0,1));
    arr.add(make_shared<Triangle<double>>(0,0,1));
    arr.add(make_shared<Square<double>>(0,0,1));
    
    assert(arr.size() == 3);
    arr.remove(1);
    assert(arr.size() == 2);
    arr.remove(0);
    assert(arr.size() == 1);
    arr.remove(0);
    assert(arr.size() == 0);
    
    cout << "Array remove operations test passed!" << endl;
}

void testArrayTotalArea() {
    Array<Figure<double>> arr;
    
    assert(arr.totalArea() == 0);
    
    arr.add(make_shared<Square<double>>(0,0,1));
    double expected1 = 2.0;
    assert(abs(arr.totalArea() - expected1) < 1e-6);
    
    arr.add(make_shared<Triangle<double>>(0,0,1));
    double expected2 = expected1 + (3*sqrt(3)/4);
    assert(abs(arr.totalArea() - expected2) < 1e-6);
    
    cout << "Array total area test passed!" << endl;
}

// Тесты для конкретных типов массивов
void testSpecificTypeArrays() {
    Array<Square<double>> squares_double;
    squares_double.add(make_shared<Square<double>>(0,0,1));
    squares_double.add(make_shared<Square<double>>(0,0,2));
    assert(squares_double.size() == 2);
    assert(abs(squares_double.totalArea() - 10.0) < 1e-6);
    
    Array<Triangle<float>> triangles_float;
    triangles_float.add(make_shared<Triangle<float>>(0,0,1.0f));
    triangles_float.add(make_shared<Triangle<float>>(0,0,2.0f));
    assert(triangles_float.size() == 2);
    
    Array<Octagon<int>> octagons_int;
    octagons_int.add(make_shared<Octagon<int>>(0,0,1));
    assert(octagons_int.size() == 1);
    
    cout << "Specific type arrays test passed!" << endl;
}

void testArrayGetMethod() {
    Array<Figure<double>> arr;
    auto square = make_shared<Square<double>>(1, 2, 3);
    arr.add(square);
    
    auto retrieved = arr.get(0);
    assert(retrieved != nullptr);
    assert(retrieved->area() == square->area());
    
    auto nullRetrieved = arr.get(5);
    assert(nullRetrieved == nullptr);
    
    cout << "Array get method test passed!" << endl;
}

// Тест концептов
void testConcepts() {
    // Эти компилируются (скалярные типы)
    Point<int> p1;
    Point<float> p2;
    Point<double> p3;
    
    Octagon<int> o1(0,0,1);
    Octagon<float> o2(0,0,1.0f);
    Octagon<double> o3(0,0,1.0);
    
    // Эти НЕ должны компилироваться (нескалярные типы)
    // Point<string> p4; // Ошибка компиляции
    // Octagon<string> o4("0","0","1"); // Ошибка компиляции
    
    cout << "Concepts test passed!" << endl;
}

int main() {
    // Тесты концептов
    testConcepts();
    
    // Octagon tests
    testOctagonArea();
    testOctagonCentroid();
    testOctagonConversion();
    
    // Triangle tests
    testTriangleArea();
    testTriangleCentroid();
    testTriangleConversion();
    
    // Square tests
    testSquareArea();
    testSquareCentroid();
    testSquareConversion();
    
    // Array tests
    testArrayBasicOperations();
    testArrayRemove();
    testArrayTotalArea();
    testSpecificTypeArrays();
    testArrayGetMethod();
    
    cout << "\n=================================" << endl;
    cout << "All tests passed successfully!" << endl;
    cout << "=================================" << endl;
    
    return 0;
}