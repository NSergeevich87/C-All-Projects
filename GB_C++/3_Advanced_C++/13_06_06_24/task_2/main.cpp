/** 2. Реализация умного указателя
    Что нужно сделать
    1. Реализуйте умный указатель shared_ptr_toy с распределённым доступом и механикой подсчёта ссылок для класса Toy, 
    реализованного в задании.
Указатель должен:
— иметь все стандартные методы класса,
— быть функциональной заменой использованию shared_ptr<Toy>.
    2. Реализуйте свободную функцию make_shared_toy, которая принимает набор аргументов и конструирует игрушку от названия 
    или при помощи копии другой игрушки.

Советы и рекомендации
Не забудьте уменьшить число ссылок на единицу в деструкторе умного указателя. Когда на счётчике появится значение 0, удалите объект.
• Вы можете использовать перегрузки под разные типы. Их количество ограничено.

Чек-лист для проверки задания
• Класс называется shared_ptr_toy.
• Реализованы конструктор, конструктор копий, оператор присваивания копированием, деструктор и функция make_shared.

Что оценивается
• Соответствие разработанного типа указателя стандартному типу shared_ptr при использовании с классом Toy.
• Корректность логики работы функции создания экземпляра класса. */

#include <iostream>
#include <memory>
#include <string>

class Toy {
private:
    std::string name_;

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
};

class shared_ptr_toy {
private:
    Toy* toy_;
    int* count_;
    
public:
    shared_ptr_toy(Toy* toy) {
        toy_ = toy;
        count_ = new int(1);
    }
    shared_ptr_toy(const shared_ptr_toy& other) {
        toy_ = other.toy_;
        count_ = other.count_;
        (*count_)++;
    }
    shared_ptr_toy& operator=(const shared_ptr_toy& other) {
        if (this != &other) {
            if (--(*count_) == 0) {
                delete toy_;
                delete count_;
            }
            toy_ = other.toy_;
            count_ = other.count_;
            (*count_)++;
        }
        return *this;
    }
    Toy* operator->() {
        return toy_;
    }
    Toy& operator*() {
        return *toy_;
    }
    ~shared_ptr_toy() {
        if (--(*count_) == 0) {
            delete toy_;
            delete count_;
        }
    }
};

shared_ptr_toy make_shared_toy(const std::string& name) {
    return shared_ptr_toy(new Toy(name));
}

int main() {
    shared_ptr_toy toy1 = make_shared_toy("Ball");
    shared_ptr_toy toy2 = toy1;
    shared_ptr_toy toy3 = make_shared_toy("Cube");
    toy2 = toy3;
    std::cout << toy1->getName() << std::endl;
    std::cout << (*toy2).getName() << std::endl;
    return 0;
}