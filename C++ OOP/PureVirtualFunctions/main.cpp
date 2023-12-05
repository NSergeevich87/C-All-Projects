#include <iostream>
#include <vector>

using namespace std;

class Shape //Pure virtual class
{
    private:
        //params
    public:
        virtual void draw() = 0;
        virtual void rotate() = 0;
        virtual ~Shape() {}
};

class Open_Shape : public Shape  //Also abstract class -> no override functions
{
    private:
        //params
    public:
        virtual ~Open_Shape() {}
};

class Close_Shape : public Shape  //Also abstract class -> no override functions
{
    private:
        //params
    public:
        virtual ~Close_Shape() {}
};

class Line : public Open_Shape  //Concrete class
{
    private:
        //params
    public:
        virtual void draw() override
        {
            cout << "Drawing Line" << endl;
        }
        
        virtual void rotate() override
        {
            cout << "Rotating Line" << endl;
        }
        virtual ~Line() {}
};

class Circle : public Close_Shape //Concrete class
{
    private:
        //params
    public:
        virtual void draw() override
        {
            cout << "Drawing Circle" << endl;
        }
        virtual void rotate() override
        {
            cout << "Rotating Circle" << endl;
        }
        virtual ~Circle() {}
};

class Square : public Close_Shape //Concrete class
{
    public:
        virtual void draw() override
        {
            cout << "Drawing Square" << endl;
        }
        virtual void rotate() override
        {
            cout << "Rotating Square" << endl;
        }
        virtual ~Square() {}
};

void screen_refreshing(const vector <Shape *> &vec)
{
    cout << "Refreshing" << endl;
    for(const auto n: vec)
        n->draw();
}

void rotating_refreshing(Shape *arr[])
{
    cout << endl;
    cout << "Rotating_refrashing" << endl;
    for(auto i = 0; i < 3; ++i)
        arr[i]->rotate();
}

int main()
{
    //Shape s; //error
    //Shape *s1 = new Shape(); //error
    
    //Circle c;
    //c.draw();
    
    //Shape *s = new Circle();
    //s->draw();
    //s->rotate();
    
    Shape *s1 = new Line();
    Shape *s2 = new Circle();
    Shape *s3 = new Square();
    
    vector <Shape *> vec {s1, s2, s3};
    
    for(const auto obj: vec)
        obj->draw();
        
    Shape *arr[] = {s1, s2, s3};
    for(auto i = 0; i < 3; ++i)
        arr[i]->rotate();
    
    screen_refreshing(vec);
    rotating_refreshing(arr);
    
    delete s1;
    delete s2;
    delete s3;
    
    cout << endl;
    return 0;
}