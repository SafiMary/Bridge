#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <memory>
#include <windows.h>

class Stok
{
public:
    virtual ~Stok() {}
    virtual void addProduct() = 0;
    virtual void printProduct() = 0;
};


class SmallStok : public Stok
{
public:
    void addProduct() override {
        std::string name;
        std::cout << "¬ведите наименование груза, который хотите добавить" << std::endl;
        std::cin >> name;
        _Product.push_back(name);
        std::cout << "√руз добавлен  и размещен на маленьком складе" << std::endl;
    }
    void printProduct() override {
        for (auto& el : _Product) {
            std::cout << el << " ";
        }
    }
private:
    std::vector <std::string> _Product;
};
class BigStok : public Stok
{
    void addProduct() override {
        std::string name;
        std::cout << "¬ведите наименование груза, который хотите добавить" << std::endl;
        std::cin >> name;
        _Product.push_back(name);
        std::cout << "√руз добавлен и размещен на большом складе" << std::endl;
    }
    void printProduct() override {
        for (auto& el : _Product) {
            std::cout << el << std::endl;
            std::cout << '\n';
        }
    }

private:
    std::vector <std::string> _Product;
};

class Truck
{
public:
    virtual ~Truck() {}
    virtual void printProduct() = 0;
    virtual void BusinessLogistic() const = 0;
};
class SmallTruck : public Truck
{
public:
    SmallTruck(Stok* stok = nullptr) : _stok(stok)
    {
    }
    ~SmallTruck()
    {
        delete this->_stok;
    }

    void setStok(Stok* stok)
    {
        delete this->_stok;
        this->_stok = stok;
    }

    void BusinessLogistic() const override
    {
        std::cout << "¬езем мелкий груз  на маленький склад\n";
        _stok->addProduct();
        
    }
  
    void printProduct() override {
        for (auto& el : _Product) {
            std::cout << el << " ";
        }
    }
private:
    std::vector <std::string> _Product;
    Stok* _stok;
};
class BigTruck : public Truck
{
public:
    BigTruck(Stok* stok = nullptr) : _stok(stok)
    {
    }
    ~BigTruck()
    {
        delete this->_stok;
    }

    void setStok(Stok* stok)
    {
        delete this->_stok;
        this->_stok = stok;
    }

    void BusinessLogistic() const override
    {
        std::cout << "¬езем крупный груз  на  большой склад\n";
        _stok->addProduct();
        
    }
  
    void printProduct() override {
        for (auto& el : _Product) {
            std::cout << el << std::endl;
            std::cout << '\n';
        }
    }
private:
    std::vector <std::string> _Product;
    Stok* _stok;
};


void ClientCode()
{
    //создали большой и маленький склад
    Stok* smalls = new SmallStok();
    Stok* bigs = new BigStok();
    //создали грузовики большой и маленький которые будут работать с такими складами как они и возить им подход€щие грузы
    Truck* min = new SmallTruck(smalls);
    Truck* max = new BigTruck(bigs);

    
    int input;
    std::cout << "¬ыберите размер груза,  который необходимо доставить на склад\n";
    std::cout << "1. ћаленький\n";
    std::cout << "2. Ѕольшой\n";
    std::cin >> input;
    switch (input) {
    case 1:
        min->BusinessLogistic();
        smalls->printProduct();
        std::cout << "\n"; break;
    case 2:
        max->BusinessLogistic();
        bigs->printProduct();
        std::cout << "\n"; break;
    default:
        std::cout << "3. ќшибка ввода\n";
        break;
    }

    delete min;
    delete smalls;
    delete max;
    delete bigs;
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    ClientCode();








    return 0;
}
