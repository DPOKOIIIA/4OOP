#include "../include/figures.h"
#include <numbers>

using namespace std;

template<floating_point T>
Octagon<T>::Octagon(T x, T y, T r) : center(make_unique<Point<T>>(x, y)), radius(r) {}

template<floating_point T>
double Octagon<T>::area() const {
    return 2 * radius * radius * tan(numbers::pi / 8);
}

template<floating_point T>
Point<T> Octagon<T>::centroid() const {
    return *center;
}

template<floating_point T>
void Octagon<T>::print(ostream& os) const {
    os << "Octagon: Center(" << center->x << ", " << center->y << "), Radius: " << radius;
}

template<floating_point T>
Octagon<T>::operator double() const {
    return area();
}

template<floating_point T>
Triangle<T>::Triangle(T x, T y, T r) : center(make_unique<Point<T>>(x, y)), radius(r) {}

template<floating_point T>
double Triangle<T>::area() const {
    return (3 * sqrt(3) / 4) * radius * radius;
}

template<floating_point T>
Point<T> Triangle<T>::centroid() const {
    return *center;
}

template<floating_point T>
void Triangle<T>::print(ostream& os) const {
    os << "Triangle: Center(" << center->x << ", " << center->y << "), Radius: " << radius;
}

template<floating_point T>
Triangle<T>::operator double() const {
    return area();
}

template<floating_point T>
Square<T>::Square(T x, T y, T r) : center(make_unique<Point<T>>(x, y)), radius(r) {}
template<floating_point T>
double Square<T>::area() const {
    return 2 * radius * radius;
}

template<floating_point T>
Point<T> Square<T>::centroid() const {
    return *center;
}

template<floating_point T>
void Square<T>::print(ostream& os) const {
    os << "Square: Center(" << center->x << ", " << center->y << "), Radius: " << radius;
}

template<floating_point T>
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

template class Octagon<float>;
template class Octagon<double>;
template class Triangle<float>;
template class Triangle<double>;
template class Square<float>;
template class Square<double>;
template class Array<Figure<float>>;
template class Array<Figure<double>>;
template class Array<Octagon<float>>;
template class Array<Octagon<double>>;
template class Array<Triangle<float>>;
template class Array<Triangle<double>>;
template class Array<Square<float>>;
template class Array<Square<double>>;