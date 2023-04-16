#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Car {
public:
    Car(const string& _brand, string _model) : m_brand(_brand), m_model(_model) {}

    virtual ~Car() {}

    virtual void print() const = 0;

protected:
    string m_brand;
    string m_model;
};

class Mercedes : public Car {
public:
    Mercedes(const string& _model) : Car("Mercedes", _model) {}

    void print() const override
    {
        cout << "Brand: " << m_brand << ", Model: " << m_model << endl;
    }
};

class BMW : public Car {
public:
    BMW(string _model) : Car("BMW", _model) {}

    void print() const override
    {
        cout << "Brand: " << m_brand << ", Model: " << m_model << endl;
    }
};

int main() {

    ifstream  inFile("cars.txt");
    if (inFile.fail()) {
        cerr << "Failed to open file." << endl;
        return 1;
    }

    vector<Car*> cars;
    string maker, model;
    while (inFile >> maker >> model) {
        if (maker == "Mercedes") {
            cars.push_back(new Mercedes(model));
        }
        else if (maker == "BMW") {
            cars.push_back(new BMW(model));
        }
        else {
            cerr << "Unknown car brand: " << maker << endl;
            continue;
        }
    }

    inFile.close();

    for (int i = 0; i < cars.size(); ++i)
    {
        cars[i]->print();
        delete cars[i];
    }

    return 0;
}