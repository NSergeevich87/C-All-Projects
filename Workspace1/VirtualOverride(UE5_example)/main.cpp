#include <iostream>

using namespace std;

class Gun
{
    public:
    virtual void Shoot()
    {
        cout << "Bang!" << endl;
    }
};

class Pistol : public Gun
{
    public:
    void Shoot() override
    {
        cout << "Pew" << endl;
    }
};

int main()
{
    Gun myGun;
    Pistol myPistol;
    
    Gun* GunPtr;
    
    GunPtr = &myGun;
    GunPtr->Shoot();
    
    GunPtr = &myPistol;
    GunPtr->Shoot();
    
    cout << endl;
    return 0;
}