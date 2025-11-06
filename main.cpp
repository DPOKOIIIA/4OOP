#include "include/figures.h"
#include <iostream>
#include <limits>

using namespace std;

void displayMenu() {
    cout << "\n========== Figures Manager ==========" << endl;
    cout << "1. Add Octagon" << endl;
    cout << "2. Add Triangle" << endl;
    cout << "3. Add Square" << endl;
    cout << "4. Show all figures" << endl;
    cout << "5. Calculate total area" << endl;
    cout << "6. Remove figure by index" << endl;
    cout << "7. Show figure details by index" << endl;
    cout << "8. Clear all figures" << endl;
    cout << "9. Demo: Add sample figures" << endl;
    cout << "0. Exit" << endl;
    cout << "=====================================" << endl;
    cout << "Choose an option: ";
}

void addOctagon(Array<Figure<double>>& figures) {
    double x, y, radius;
    cout << "Enter center coordinates (x y): ";
    cin >> x >> y;
    cout << "Enter radius: ";
    cin >> radius;
    if (radius <= 0) {
        cout << "Error: Radius must be positive!" << endl;
        return;
    }
    figures.add(make_shared<Octagon<double>>(x, y, radius));
    cout << "Octagon added successfully!" << endl;
}

void addTriangle(Array<Figure<double>>& figures) {
    double x, y, radius;
    cout << "Enter center coordinates (x y): ";
    cin >> x >> y;
    cout << "Enter radius: ";
    cin >> radius;
    if (radius <= 0) {
        cout << "Error: Radius must be positive!" << endl;
        return;
    }
    figures.add(make_shared<Triangle<double>>(x, y, radius));
    cout << "Triangle added successfully!" << endl;
}

void addSquare(Array<Figure<double>>& figures) {
    double x, y, radius;
    cout << "Enter center coordinates (x y): ";
    cin >> x >> y;
    cout << "Enter radius: ";
    cin >> radius;
    if (radius <= 0) {
        cout << "Error: Radius must be positive!" << endl;
        return;
    }
    figures.add(make_shared<Square<double>>(x, y, radius));
    cout << "Square added successfully!" << endl;
}

void showAllFigures(Array<Figure<double>>& figures) {
    if (figures.size() == 0) {
        cout << "No figures in the array." << endl;
        return;
    }
    cout << "\n=== All Figures ===" << endl;
    figures.printAll();
    cout << "Total figures: " << figures.size() << endl;
}

void removeFigure(Array<Figure<double>>& figures) {
    if (figures.size() == 0) {
        cout << "No figures to remove." << endl;
        return;
    }
    cout << "Current figures count: " << figures.size() << endl;
    cout << "Enter index to remove (0 to " << figures.size() - 1 << "): ";
    size_t index;
    cin >> index;
    if (index < figures.size()) {
        figures.remove(index);
        cout << "Figure at index " << index << " removed successfully!" << endl;
    } else {
        cout << "Error: Invalid index!" << endl;
    }
}

void showFigureDetails(Array<Figure<double>>& figures) {
    if (figures.size() == 0) {
        cout << "No figures to display." << endl;
        return;
    }
    cout << "Current figures count: " << figures.size() << endl;
    cout << "Enter index to display (0 to " << figures.size() - 1 << "): ";
    size_t index;
    cin >> index;
    if (index >= figures.size()) {
        cout << "Error: Invalid index!" << endl;
        return;
    }
    auto figure = figures.get(index);
    if (figure) {
        cout << "\n=== Figure at index " << index << " ===" << endl;
        figure->print(cout);
        cout << "\nArea: " << figure->area() << endl;
        Point<double> center = figure->centroid();
        cout << "Centroid: (" << center.x << ", " << center.y << ")" << endl;
    } else {
        cout << "Error: Could not retrieve figure!" << endl;
    }
}

void addDemoFigures(Array<Figure<double>>& figures) {
    figures.add(make_shared<Octagon<double>>(0, 0, 5));
    figures.add(make_shared<Triangle<double>>(1, 1, 3));
    figures.add(make_shared<Square<double>>(2, 2, 4));
    figures.add(make_shared<Octagon<double>>(-1, -1, 2));
    figures.add(make_shared<Triangle<double>>(3, -2, 2.5));
    cout << "5 demo figures added successfully!" << endl;
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    Array<Figure<double>> figures;
    int choice;
    cout << "Welcome to Figures Management System!" << endl;
    do {
        displayMenu();
        cin >> choice;
        clearInputBuffer();
        switch (choice) {
            case 1:
                addOctagon(figures);
                break;
            case 2:
                addTriangle(figures);
                break;
            case 3:
                addSquare(figures);
                break;
            case 4:
                showAllFigures(figures);
                break;
            case 5:
                if (figures.size() > 0) {
                    cout << "Total area of all figures: " << figures.totalArea() << endl;
                } else {
                    cout << "No figures to calculate area." << endl;
                }
                break;
            case 6:
                removeFigure(figures);
                break;
            case 7:
                showFigureDetails(figures);
                break;
            case 8:
                figures = Array<Figure<double>>();
                cout << "All figures cleared!" << endl;
                break;
            case 9:
                addDemoFigures(figures);
                break;
            case 0:
                cout << "Thank you for using Figures Management System!" << endl;
                break;
            default:
                cout << "Invalid option! Please try again." << endl;
                break;
        }
        if (choice != 0) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
    } while (choice != 0);
    
    return 0;
}