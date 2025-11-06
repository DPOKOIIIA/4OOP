#include "../include/figures.h"
#include <numbers>

using namespace std;

template<Scalar T>
Octagon<T>::Octagon(T x, T y, T r) : center(make_unique<Point<T>>(x, y)), radius(r) {
    static_assert(Scalar<T>, "T must be a scalar type for Octagon");
}

template<Scalar T>
double Octagon<T>::area() const {
    return 2.0 * static_cast<double>(radius) * static_cast<double>(radius) * tan(numbers::pi / 8.0);
}

template<Scalar T>
Point<T> Octagon<T>::centroid() const {
    return *center;
}

template<Scalar T>
void Octagon<T>::print(ostream& os) const {
    os << "Octagon: Center(" << center->x << ", " << center->y << "), Radius: " << radius;
}

template<Scalar T>
Octagon<T>::operator double() const {
    return area();
}

template<Scalar T>
Triangle<T>::Triangle(T x, T y, T r) : center(make_unique<Point<T>>(x, y)), radius(r) {
    static_assert(Scalar<T>, "T must be a scalar type for Triangle");
}

template<Scalar T>
double Triangle<T>::area() const {
    return (3.0 * sqrt(3.0) / 4.0) * static_cast<double>(radius) * static_cast<double>(radius);
}

template<Scalar T>
Point<T> Triangle<T>::centroid() const {
    return *center;
}

template<Scalar T>
void Triangle<T>::print(ostream& os) const {
    os << "Triangle: Center(" << center->x << ", " << center->y << "), Radius: " << radius;
}

template<Scalar T>
Triangle<T>::operator double() const {
    return area();
}

template<Scalar T>
Square<T>::Square(T x, T y, T r) : center(make_unique<Point<T>>(x, y)), radius(r) {
    static_assert(Scalar<T>, "T must be a scalar type for Square");
}

template<Scalar T>
double Square<T>::area() const {
    return 2.0 * static_cast<double>(radius) * static_cast<double>(radius);
}

template<Scalar T>
Point<T> Square<T>::centroid() const {
    return *center;
}

template<Scalar T>
void Square<T>::print(ostream& os) const {
    os << "Square: Center(" << center->x << ", " << center->y << "), Radius: " << radius;
}

template<Scalar T>
Square<T>::operator double() const {
    return area();
}

template<typename T>
void Array<T>::add(shared_ptr<T> elem) {
    data.push_back(move(elem));
}

template<typename T>
void Array<T>::remove(size_t index) {
    if (index < data.size()) data.erase(data.begin() + index);
}

template<typename T>
double Array<T>::totalArea() const {
    double total = 0;
    for (const auto& elem : data) total += static_cast<double>(*elem);
    return total;
}

template<typename T>
void Array<T>::printAll() const {
    for (const auto& elem : data) {
        elem->print(cout);
        cout << "\n";
    }
}

template<typename T>
size_t Array<T>::size() const {
    return data.size();
}

template<typename T>
shared_ptr<T> Array<T>::get(size_t index) const {
    if (index < data.size()) {
        return data[index];
    }
    return nullptr;
}
template class Point<int>;
template class Point<float>;
template class Point<double>;
template class Point<long>;
template class Octagon<int>;
template class Octagon<float>;
template class Octagon<double>;
template class Triangle<int>;
template class Triangle<float>;
template class Triangle<double>;
template class Square<int>;
template class Square<float>;
template class Square<double>;
template class Array<Figure<int>>;
template class Array<Figure<float>>;
template class Array<Figure<double>>;
template class Array<Octagon<int>>;
template class Array<Octagon<float>>;
template class Array<Octagon<double>>;
template class Array<Triangle<int>>;
template class Array<Triangle<float>>;
template class Array<Triangle<double>>;
template class Array<Square<int>>;
template class Array<Square<float>>;
template class Array<Square<double>>;