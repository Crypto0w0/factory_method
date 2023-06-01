#include <iostream>
using namespace std;

class House{
public:
};

class PanelHouse : public House{
public:
    PanelHouse(){
        cout << "Panel house built\n";
    }
};

class WoodHouse : public House{
public:
    WoodHouse(){
        cout << "Wooden house built\n";
    }
};

class BrickHouse : public House{
public:
    BrickHouse(){
        cout << "Brick house built\n";
    }
};

class Developer{
public:
    virtual House* Create() = 0;
};

class PanelDeveloper : public Developer{
public:
    virtual House* Create(){
        return new PanelHouse;
    }
};

class WoodDeveloper : public Developer{
public:
    virtual House* Create(){
        return new WoodHouse;
    }
};

class BrickDeveloper : public Developer{
public:
    virtual House* Create(){
        return new BrickHouse;
    }
};

House* Client(Developer* dev){
    return dev->Create();
}

int main() {
    Developer* dev = new PanelDeveloper();
    House* house = Client(dev);
    delete house;
    delete dev;
    dev = new WoodDeveloper();
    house = Client(dev);
    delete house;
    delete dev;
    dev = new BrickDeveloper();
    house = Client(dev);
    delete house;
    delete dev;
}
