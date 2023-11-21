#include <iostream>
#include <fstream>
#include <cmath>
#include <random>


class Circle {
private:
    double x;
    double y;
    double radius;
    std::string color;
    const double pi = 3.14;

public:
    // конструктор
    Circle() : x(0), y(0), radius(1), color("black") {}

    // конструктор с параметрами
    Circle(double x, double y, double radius, std::string color) : x(x), y(y), radius(radius), color(color) {}


    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    double getRadius() const {
        return radius;
    }

    std::string getColor() const {
        return color;
    }

    // Сеттеры
    void setX(double x) {
        this->x = x;
    }

    void setY(double y) {
        this->y = y;
    }

    void setRadius(double radius) {
        this->radius = radius;
    }

    void setColor(std::string color) {
        this->color = color;
    }

    // Подсчет длины окружности
    double calculateCircumference() const {
        return 2 * pi * radius;
    }

    // Подсчет площади окружности
    double calculateArea() const {
        return pi * radius * radius;
    }

    // Печать информации об объекте в файл
    void printInfoToFile(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << "Circle information:\n";
            file << "Center coordinates: (" << x << ", " << y << ")\n";
            file << "Radius: " << radius << "\n";
            file << "Color: " << color << "\n";
            file.close();
            std::cout << "Information printed to file: " << filename << std::endl;
        }
        else {
            std::cout << "Unable to open file: " << filename << std::endl;
        }
    }

    // Изменение цвета окружности случайным образом
    void changeColorRandomly() {
        std::vector<std::string> colors = { "red", "green", "blue", "yellow", "orange" };
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, colors.size() - 1);
        color = colors[dis(gen)];
        std::cout << "Circle color changed to: " << color << std::endl;
    }
};

int main() {
    Circle circle1(0, 0, 5, "red");
    Circle circle2;

    std::cout << "Circle attributes:\n";
    std::cout << "Center coordinates: (" << circle1.getX() << ", " << circle1.getY() << ")\n";
    std::cout << "Radius: " << circle1.getRadius() << "\n";
    std::cout << "Color: " << circle1.getColor() << "\n";



    std::cout << "Circumference of circle : " << circle1.calculateCircumference() << "\n";
    std::cout << "Area of circle : " << circle1.calculateArea() << "\n";

    circle1.printInfoToFile("circle_info.txt");

    circle1.changeColorRandomly();

    return 0;
}
