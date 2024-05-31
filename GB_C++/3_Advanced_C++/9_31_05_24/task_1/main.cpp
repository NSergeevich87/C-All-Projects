/** Задание 1. Реализация деревни эльфов
Что нужно сделать
Лесные эльфы расположили свою деревню в лесу, прямо на деревьях. Нужно расселить эльфов по веткам деревьев, 
а затем подсчитать общее количество соседей определённого эльфа.
Всего в лесу пять деревьев, каждое из которых генерируется с помощью случайных чисел, заданных в указанных 
далее диапазонах. На каждом дереве есть 3–5 основных больших ветвей. На каждой большой ветке расположены 
ещё 2-3 средние ветки. Дома эльфов построены на больших и на средних ветках. Более мелкие ветви не 
рассматриваются в этой задаче.
В начале программы пользователь размещает в каждом доме по одному эльфу. Делается это с помощью 
последовательного перебора всех имеющихся домов и запроса имени заселяемого эльфа через стандартный ввод. 
Если было введено None в качестве имени, то дом пропускается и не заселяется никем.
После этого требуется найти определённого эльфа по имени. Имя искомого эльфа вводится через стандартный ввод. 
Для найденного эльфа нужно вывести общее количество эльфов, живущих вместе с ним на одной большой ветви. 
Это и будет искомое количество соседей.

Советы и рекомендации
И для представления деревьев, и для представления больших и средних ветвей следует использовать один и 
тот же класс (например Branch) с полем, которое будет обозначать родительскую ветвь, и полем, обозначающим 
дочерние ветви. У самого дерева, в свою очередь, родительская ветвь будет всегда нулевой, то есть nullptr.
Функцию поиска эльфа в дереве можно реализовать с помощью рекурсивного метода в классе Branch, который 
сначала поищет эльфа в себе, а потом уже на дочерних ветвях.
Чтобы лучше представлять структуру дерева и понимать, как получать его вершину, взгляните на данный метод:

Branch\* getTopBranch()
{
//Если это дерево
if (parent == nullptr) return nullptr;
//Если это средняя ветка
if (parent->parent == nullptr) return parent;
//Если это маленькая ветка
return parent->getTopBranch();
}
[]()*/

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

class Elf
{
public:
    Elf(std::string name) : name(name) {}
    std::string getName() { return name; }
private:
    std::string name;
};

class Branch
{
public:
    Branch(Branch* parent) : parent(parent) {}
    Branch* getTopBranch()
    {
        if (parent == nullptr) return nullptr;
        if (parent->parent == nullptr) return parent;
        return parent->getTopBranch();
    }
    void addElf(Elf* elf) { elves.push_back(elf); }
    int getElvesCount()
    {
        int count = 0;
        for (auto elf : elves)
        {
            count++;
        }
        return count;
    }
    Branch* parent;
    std::vector<Branch*> children;
    std::vector<Elf*> elves;
};

class Tree
{
public:
    Tree()
    {
        srand(time(0));
        for (int i = 0; i < 5; i++)
        {
            Branch* tree = new Branch(nullptr);
            for (int j = 0; j < rand() % 3 + 2; j++)
            {
                Branch* bigBranch = new Branch(tree);
                tree->children.push_back(bigBranch);
                for (int k = 0; k < rand() % 2 + 1; k++)
                {
                    Branch* mediumBranch = new Branch(bigBranch);
                    bigBranch->children.push_back(mediumBranch);
                }
            }
            trees.push_back(tree);
        }
    }
    void addElf()
    {
        for (auto tree : trees)
        {
            countTree++;
            countBigBranch = 0;
            countMediumBranch = 0;
            for (auto bigBranch : tree->children)
            {
                countBigBranch++;
                countMediumBranch = 0;
                for (auto mediumBranch : bigBranch->children)
                {
                    countMediumBranch++;
                    std::string name;
                    std::cout << "Tree: " << countTree << " BigBranch: " << countBigBranch << " MediumBranch: " << countMediumBranch << std::endl;
                    std::cout << "Enter elf name or None: ";
                    std::cin >> name;
                    if (name != "None")
                    {
                        Elf* elf = new Elf(name);
                        mediumBranch->addElf(elf);
                    }
                }
            }
        }
    }

    void findElf(std::string name)
    {
        for (auto tree : trees)
        {
            for (auto bigBranch : tree->children)
            {
                for (auto mediumBranch : bigBranch->children)
                {
                    for (auto elf : mediumBranch->elves)
                    {
                        if (elf->getName() == name)
                        {
                            std::cout << "Elf " << name << " has " << mediumBranch->getElvesCount() << " neighbors" << std::endl;
                            return;
                        }
                    }
                }
            }
        }
        std::cout << "Elf not found" << std::endl;
    }

private:
    int elvesCount = 0;
    std::vector<Branch*> trees;
    int countTree = 0;
    int countBigBranch = 0;
    int countMediumBranch = 0;
};

int main()
{
    Tree tree;
    tree.addElf();
    std::string name;
    std::cout << "Enter elf name to find: ";
    std::cin >> name;
    tree.findElf(name);
    return 0;
}