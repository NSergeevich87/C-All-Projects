/** Задача 1. Суперпёс
Все наши животные могут мяукать и гавкать, то есть издавать звуки в соответствии со своим классом. 
Но что, если нужно добавить им новое поведение, например, научить плавать или стоять на задних лапах. 
Рассмотрим класс Dog: все собаки умеют лаять и бегать, а некоторые собаки умеют хорошо плавать. 
Чтобы добавить эти качества классу Dog, мы можем создать ещё один класс «плавающих» животных и 
наследовать от него наш класс. Но что, если не все собаки умеют хорошо плавать, а некоторые из них 
совсем не умеют плавать.
Наша задача — построить класс Dog таким образом, чтобы к его объектам можно было выборочно добавлять 
новые умения, но при этом не менять поведение основного класса. Список умений будет вызываться с 
помощью метода show_talents().

Что нужно сделать
1. Создайте класс Dog, к которому можно добавлять новые способности.
2. Создайте абстрактный класс «Талант» (Talent), от которого будут наследоваться все добавляемые способности. 
Пока таких способностей три: умение плавать (Swimming), умение танцевать (Dancing), умение считать (Counting), 
но можете добавить и другие.
3. Создайте у класса Dog метод show_talents() для показа всех способностей, которыми обладает собака.

Требования к реализации
Класс Talent должен быть абстрактным. Это значит, что объекты такого класса мы создать не сможем, 
так как одна из его функций объявлена как «чисто» виртуальная (pure virtual).
Каждая способность, наследуемая от абстрактного класса Talent, должна быть представлена в виде отдельного 
класса.
Пример выполнения
Создаём собаку с именем Steve:
Dog dog1("Steve")
Добавляем ей умение танцевать и плавать.
Если мы сделаем запрос умений show_talents(), то на экран будет выведено:

This is Steve and it has some talents:
It can “Dance”
It can “Swim”

Советы и рекомендации
• Для хранения способностей можно использовать вектор.
• Для создания абстрактного класса рекомендуем пересмотреть видео, где функция voice в классе Animal 
была объявлена «чисто» виртуальной. Это поможет в выполнении задания.

Что оценивается
• Класс Talent является абстрактным.
• Все способности являются классами и наследуются от класса Talent.
• Класс Dog не наследуется от класса Talent.
• При ответе на запрос show_talents в консоли должны быть последовательно написаны все умения, 
которыми обладает собака.*/  

#include <iostream>
#include <string>
#include <vector>

class Talent
{
public:
    Talent() = default;
    virtual void show() = 0;
};

class Swimming : public Talent
{
public:
    virtual void show() override
    {
        std::cout << "Swim" << std::endl;
    }
};

class Dancing : public Talent
{
public:
    virtual void show() override
    {
        std::cout << "Dance" << std::endl;
    }
};

class Counting : public Talent
{
public:
    virtual void show() override
    {
        std::cout << "Count" << std::endl;
    }
};

class Animal 
{
public:
    Animal() = default;
    virtual void voice() = 0;
    virtual void add_talent(Talent* talent) = 0;
    virtual void show_talents() = 0;
};

class Dog : virtual public Animal
{
private:
    std::string name;
    int age;
    std::vector<Talent*> talents;

public:
    Dog() = default;
    Dog(std::string inName, int inAge) : name(inName), age(inAge) {}

    virtual void voice() override
    {
        std::cout << "Gav" << std::endl;
    }

    void show_talents()
    {
        std::cout << "This is " << name << " and it has some talents:" << std::endl;
        for (auto talent : talents)
        {
            std::cout << "It can ";
            talent->show();
        }
    }

    void add_talent(Talent* talent)
    {
        talents.push_back(talent);
    }
};

class Cat : virtual public Animal
{
private:
    std::string name;
    int age;
    std::vector<Talent*> talents;

public:
    Cat() = default;
    Cat(std::string inName, int inAge) : name(inName), age(inAge) {}

    virtual void voice() override
    {
        std::cout << "Meow" << std::endl;
    }

    void show_talents()
    {
        std::cout << "This is " << name << " and it has some talents:" << std::endl;
        for (auto talent : talents)
        {
            std::cout << "It can ";
            talent->show();
        }
    }

    void add_talent(Talent* talent)
    {
        talents.push_back(talent);
    }
};

int main()
{
    Animal* dog = new Dog("Dog", 5);
    Animal* cat = new Cat("Cat", 3);

    dog->voice();
    cat->voice();

    Talent* talent1 = new Dancing();
    Talent* talent2 = new Swimming();
    Talent* talent3 = new Counting();

    dog->add_talent(talent1);
    dog->add_talent(talent2);
    cat->add_talent(talent3);

    dog->show_talents();
    cat->show_talents();

    delete dog;
    delete cat;

    return 0;
}