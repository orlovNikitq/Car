#include <iostream>
#include <string>

#include <ctime>

#define random rand() % 5
std::string generateRandomNumber() {
    std::string number;
    for (int i = 0; i < 4; ++i) {
        number += '0' + std::rand() % 10;
    }
    return number;
}
struct Car {
    std::string number;
    std::string color;
    std::string model;
};

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    const std::string COLOR[5] = { "red", "yellow", "black", "white", "pink" };
    const std::string MODEL[5] = { "BMW", "Lada", "Mazda", "Nissan", "Toyota" };
    Car cars[10];
    
  
    for (int i = 0; i < 10; i++) {
        cars[i].model = MODEL[random];
        cars[i].color = COLOR[random];
        cars[i].number = generateRandomNumber();
        for (int j = 0; j < i; ++j) {
            if (cars[i].number == cars[j].number) {
                --i; 
                break;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        std::cout << " model: " << cars[i].model;
        std::cout << " | color: " << cars[i].color;
        std::cout << " | number: " << cars[i].number << std::endl;
    }
}