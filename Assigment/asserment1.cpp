
#include<iostream>
#include<utility>

using namespace std;

class Animal {
protected:
    int age;
    long uniqueID;
    bool alive;
    pair<double, double> location;

public:
    Animal(): age(0), uniqueID(0), alive(true), location(make_pair(0.0, 0.0)) {
        static long id = 0;
        uniqueID = ++id;
    }

    Animal(int age, double x, double y): age(age), uniqueID(0), alive(true), location(make_pair(x, y)) {
        static long id = 0;
        uniqueID = ++id;
    }

    virtual ~Animal() {}

    virtual void move(double x, double y) {
        location = make_pair(x, y);
        cout << "Animal " << uniqueID << " moved to " << location.first << ", " << location.second << endl;
    }

    virtual void sleep() {
        cout << "Animal " << uniqueID << " is sleeping" << endl;
    }

    virtual void eat() {
        cout << "Animal " << uniqueID << " is eating" << endl;
    }

    void setAlive(bool isAlive) {
        alive = isAlive;
    }

    friend ostream& operator<<(ostream& os, const Animal& animal) {
        os << "Animal " << animal.uniqueID << " is " << (animal.alive ? "alive" : "dead") << ", age " << animal.age << ", at " << animal.location.first << ", " << animal.location.second << endl;
        return os;
    }
};

class Bird : public Animal {
private:
    int wingspan;

public:
    Bird(): Animal(), wingspan(0) {}

    Bird(int age, double x, double y, int wingspan): Animal(age, x, y), wingspan(wingspan) {}

    virtual void fly(double x, double y) {
        move(x, y);
        cout << "Bird " << uniqueID << " is flying with wingspan " << wingspan << endl;
    }

    virtual void eat() {
        cout << "Bird " << uniqueID << " is eating seeds" << endl;
    }
};

class Canine : public Animal {
protected:
    int numLegs;

public:
    Canine(): Animal(), numLegs(4) {}

    Canine(int age, double x, double y, int numLegs): Animal(age, x, y), numLegs(numLegs) {}

    virtual void bark() {
        cout << "Canine " << uniqueID << " is barking" << endl;
    }

    virtual void eat() {
        cout << "Canine " << uniqueID << " is eating meat" << endl;
    }
};

int main() {
    Animal animal1;
    cout << animal1;

    Animal animal2(5, 2.5, 3.5);
    cout << animal2;

    Bird bird1(3, 1.0, 2.0, 10);
    cout << bird1;

    Canine canine1(2, 3.0, 4.0, 3);
    cout << canine1;

    bird1.fly(3.0, 5.0);

    canine1.bark();

    animal1.move(2.0, 2.0);
    animal1.sleep();

    bird1.eat();
    canine1.eat();

    return 0;
}
