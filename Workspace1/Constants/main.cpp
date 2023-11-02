#include <iostream>

 using namespace std;
 
 int main()
 {
     cout << "Welcome to cleaning service!" << endl;
     cout << "\nHow many rooms whold you like cleaned? ";
     
     int number_of_rooms {0};
     cin >> number_of_rooms;
     
     const double price {30};
     const double tax {0.06};
     const int days {30};
     
     cout << "Will clean " << number_of_rooms << " rooms" << endl;
     cout << "Price per room $: " << price << endl;
     cout << "We should pay: " << price * number_of_rooms << endl;
     cout << "Tax $: " << price * number_of_rooms * tax << endl;
     cout << "=============================================" << endl;
     cout << "Total price: " << (price * number_of_rooms) + (price * number_of_rooms * tax) << endl;
     cout << "This estimate is valid for " << days << " days" << endl;
     
     return 0;
 }