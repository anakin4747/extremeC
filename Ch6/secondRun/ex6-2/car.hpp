#ifndef CAR_CPP_H
#define CAR_CPP_H

class Car {
public:
    // Constructor
    Car(const char*);
    // Destructor
    ~Car();

    void Accelerate();
    void Brake();
    void Refuel(double);

    // Data members
    char name[32];
    double speed;
    double fuel;

};

#endif // CAR_CPP_H