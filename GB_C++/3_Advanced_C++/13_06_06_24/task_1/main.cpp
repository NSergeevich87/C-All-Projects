/** 1. Использование умного указателя
    Что нужно сделать
    1. Реализуйте класс Dog, который использует стандартный умный указатель shared_ptr для класса Toy.
    2. Реализуйте у класса Dog метод getToy, с помощью которого собака подбирает игрушку.
— Если у собаки уже есть эта игрушка, необходимо вывести в консоль фразу: I already have this toy.
— Если в данный момент игрушка находится у другой собаки, нужно вывести в консоль: Another dog is playing with this toy.
— Если игрушка свободна, собака подбирает её.
    3. Реализуйте у класса Dog метод dropToy, с помощью которого собака бросает игрушку на пол, после чего другая может подобрать её.
— Если у собаки в этот момент нет игрушки, в консоль необходимо вывести: Nothing to drop.

Советы и рекомендации
• Чтобы узнать, у скольких собак в данный момент есть игрушка, можно использовать метод use_count() у класса shared_ptr. 
При этом необходимо учитывать, что создание shared_ptr от класса Toy тоже увеличивает показатели счётчика.
• Чтобы увидеть удаление класса Toy, используйте следующее определение:

class Toy {
public:
Toy(const std::string& name) {
name_ = name;
}
std::string getNmae() {
return name_;
}
~Toy() {
std::cout << "Toy " << name_ << " was dropped " << std::endl;
}
private:
std::string name_;
}; */

#include <iostream>
#include <memory>
#include <string>

class Toy {
public:
    Toy(const std::string& name) {
        name_ = name;
    }
    std::string getName() {
        return name_;
    }
    ~Toy() {
        std::cout << "Toy " << name_ << " was dropped " << std::endl;
    }
private:
    std::string name_;
};

class Dog {
public:
    Dog() {
        toy_ = nullptr;
    }
    void getToy(std::shared_ptr<Toy> toy) {
        if (toy_ == toy) {
            std::cout << "I already have this toy." << std::endl;
        } else if (toy.use_count() > 1) {
            std::cout << "Another dog is playing with this toy." << std::endl;
        } else {
            toy_ = toy;
        }
    }
    void dropToy() {
        if (toy_ == nullptr) {
            std::cout << "Nothing to drop." << std::endl;
        } else {
            toy_ = nullptr;
        }
    }
private:
    std::shared_ptr<Toy> toy_;
};

int main() {
    std::shared_ptr<Toy> toy1 = std::make_shared<Toy>("Ball");
    std::shared_ptr<Toy> toy2 = std::make_shared<Toy>("Bone");
    Dog dog1;
    Dog dog2;
    dog1.getToy(toy1);
    dog2.getToy(toy1);
    dog1.getToy(toy2);
    dog1.dropToy();
    dog2.getToy(toy1);
    return 0;
}