/** Задание 1. Работа корзины с покупками
Что нужно сделать
Реализуйте простую и безопасную модель работы корзины онлайн-магазина.
• В начале программы вы заполняете базу данных самого магазина через стандартную консоль. 
Каждый элемент этой базы данных состоит из двух компонентов — артикула и количества штук.
• Корзина должна поддерживать следующие операции: добавление товара с указанным его количеством — add, 
удаление товара с указанным количеством — remove. Обе операции принимают артикул товара в виде строки и 
количество в виде целого числа.
• При вводе аргументов к операциям должна осуществляться их валидация. Артикул должен быть в базе данных магазина, 
количество не должно превышать количество доступного продукта на складе (при удалении — в корзине).

Рекомендации
В качестве контейнера для базы данных и самой корзины можете использовать std::map.
Если пользователь ввёл некорректную информацию, то лучше выбросить std::invalid_argument, 
в других случаях — runtime_error. */

#include <iostream>
#include <map>
#include <stdexcept>

class Basket
{
public:
    void add(const std::string &article, int count)
    {
        if (store.find(article) == store.end())
        {
            throw std::invalid_argument("Article not found");
        }
        if (store[article] < count)
        {
            throw std::invalid_argument("Not enough items in the store");
        }
        basket[article] += count;
        store[article] -= count;
    }

    void remove(const std::string &article, int count)
    {
        if (basket.find(article) == basket.end())
        {
            throw std::invalid_argument("Article not found in the basket");
        }
        if (basket[article] < count)
        {
            throw std::invalid_argument("Not enough items in the basket");
        }
        basket[article] -= count;
        store[article] += count;
    }

    void add_to_store(const std::string &article, int count)
    {
        store[article] += count;
    }

    void print_store()
    {
        std::cout << "Store:" << std::endl;
        for (const auto &item : store)
        {
            std::cout << item.first << " " << item.second << std::endl;
        }
    }

    void print_basket()
    {
        std::cout << "Basket:" << std::endl;
        for (const auto &item : basket)
        {
            std::cout << item.first << " " << item.second << std::endl;
        }
    }

private:
    std::map<std::string, int> store;
    std::map<std::string, int> basket;
};

int main()
{
    Basket basket;
    basket.add_to_store("item1", 10);
    basket.add_to_store("item2", 20);
    basket.add_to_store("item3", 30);
    basket.print_store();
    try
    {
        basket.add("item1", 5);
        basket.add("item2", 10);
        basket.add("item3", 15);
        basket.print_store();
        basket.print_basket();
        basket.remove("item1", 2);
        basket.remove("item2", 5);
        basket.remove("item3", 10);
        basket.print_store();
        basket.print_basket();
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}