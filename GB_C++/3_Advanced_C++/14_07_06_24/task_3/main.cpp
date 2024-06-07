/** Задача 3. Модель данных компании на Protobuf
Что нужно сделать
Создайте модель данных для информации о предприятии. Обязательные поля: год основания (целое 32-битное число), 
юридический адрес (строка) и название (строка). Опциональные поля: род деятельности (строка), осуществление 
внешнеэкономической деятельности (булевый тип)
Опишите модель на языке proto2 и сохраните её в отдельный документ с расширением proto. Затем на основе созданного 
документа сгенерируйте C++-код с помощью компилятора protoc. */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "company.pb.h"

int main() {
    Company company;
    company.set_foundation_year(1990);
    company.set_legal_address("Moscow, Russia");
    company.set_name("Company Name");
    company.set_activity("IT");
    company.set_foreign_trade(true);

    std::ofstream file("company.dat", std::ios::binary);
    company.SerializeToOstream(&file);
    file.close();

    return 0;
}