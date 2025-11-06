#pragma once
#include <iostream>
#include <memory>
#include <concepts>
#include <cmath>
#include <vector>
#include <numbers>

using namespace std;
template<typename T>
concept Scalar = is_arithmetic_v<T>;
template<typename T>
concept FloatingPoint = is_floating_point_v<T>;
template<Scalar T>
class Point {
public:
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}
};

template<Scalar T>
class Figure {
public:
    virtual ~Figure() = default;
    virtual double area() const = 0;
    virtual Point<T> centroid() const = 0;
    virtual void print(ostream& os) const = 0;
    virtual operator double() const = 0;
};

template<Scalar T>
class Octagon : public Figure<T> {
private:
    unique_ptr<Point<T>> center;
    T radius;
public:
    Octagon(T x, T y, T r);
    double area() const override;
    Point<T> centroid() const override;
    void print(ostream& os) const override;
    operator double() const override;
};

template<Scalar T>
class Triangle : public Figure<T> {
private:
    unique_ptr<Point<T>> center;
    T radius;
public:
    Triangle(T x, T y, T r);
    double area() const override;
    Point<T> centroid() const override;
    void print(ostream& os) const override;
    operator double() const override;
};

template<Scalar T>
class Square : public Figure<T> {
private:
    unique_ptr<Point<T>> center;
    T radius;
public:
    Square(T x, T y, T r);
    double area() const override;
    Point<T> centroid() const override;
    void print(ostream& os) const override;
    operator double() const override;
};

template<typename T>
class Array {
private:
    vector<shared_ptr<T>> data;
public:
    void add(shared_ptr<T> elem);
    void remove(size_t index);
    double totalArea() const;
    void printAll() const;
    size_t size() const;
    shared_ptr<T> get(size_t index) const;
};