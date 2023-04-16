#include <iostream>
#include <vector>
#include <typeinfo>

class Class1
{
public:
    Class1() {}
    virtual ~Class1() {}
    virtual Class1* clone() const
    {
        return new Class1(*this);
    }
};

class Class2 : public Class1
{
public:
    Class2() {}
    virtual ~Class2() {}
    virtual Class1* clone() const
    {
        return new Class2(*this);
    }
};

void my_copy(const Class1& obj, std::vector<Class1*>& dB)
{
    dB.push_back(obj.clone());
}

int main()
{
    std::vector<Class1*> dataBase;

    Class1 obj1;
    Class2 obj2;

    my_copy(obj1, dataBase);
    my_copy(obj2, dataBase);

    for (int i = 0; i < dataBase.size(); ++i)
    {
        std::cout << typeid(*dataBase[i]).name() << std::endl;
        delete dataBase[i];
    }

    return 0;
}