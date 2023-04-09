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
        std::cout << "������� ������������ �����, ������� ������ ��������" << std::endl;
        std::cin >> name;
        _Product.push_back(name);
        std::cout << "���� ��������  � �������� �� ��������� ������" << std::endl;
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
        std::cout << "������� ������������ �����, ������� ������ ��������" << std::endl;
        std::cin >> name;
        _Product.push_back(name);
        std::cout << "���� �������� � �������� �� ������� ������" << std::endl;
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
        std::cout << "����� ������ ����  �� ��������� �����\n";
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
        std::cout << "����� ������� ����  ��  ������� �����\n";
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
    //������� ������� � ��������� �����
    Stok* smalls = new SmallStok();
    Stok* bigs = new BigStok();
    //������� ��������� ������� � ��������� ������� ����� �������� � ������ �������� ��� ��� � ������ �� ���������� �����
    Truck* min = new SmallTruck(smalls);
    Truck* max = new BigTruck(bigs);

    
    int input;
    std::cout << "�������� ������ �����,  ������� ���������� ��������� �� �����\n";
    std::cout << "1. ���������\n";
    std::cout << "2. �������\n";
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
        std::cout << "3. ������ �����\n";
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
