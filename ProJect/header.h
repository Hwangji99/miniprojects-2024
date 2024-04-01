/*
       File: Product Manager

         24-03-27

       Author: 황지환
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 제품의 기본 클래스 정의
class Product {
protected:
    int id;
    double price;
    string producer;
public:
    // 생성자
    Product(int _id, double _price, string _producer);

    // 가상 함수를 통해 다형성을 지원하여 파생 클래스에서 재정의 가능한 출력 함수
    virtual void printInfo() const;

    // ID 반환 함수
    int getID() const;

    // 가상 소멸자
    virtual ~Product(); // 가상 소멸자 추가
};

// 책 클래스 정의 - 제품 클래스를 상속받음
class Book : public Product {
private:
    string ISBN;
    string author;
    string title;
public:
    // 생성자
    Book(int _id, double _price, string _producer, string _ISBN, string _author, string _title);


    // 재정의된 출력 함수
    void printInfo() const override;
};

// 핸드폰 클래스 정의 - 제품 클래스를 상속받음
class Handphone : public Product {
private:
    string model;
    int ram;
public:
    // 생성자
    Handphone(int _id, double _price, string _producer, string _model, int _ram);

    // 재정의된 출력 함수
    void printInfo() const override;
};

class Computer : public Product {
private:
    string model;
    string cpu;
    int ram;
public:

    // 생성자
    Computer(int _id, double _price, string _producer, string _model, string _cpu, int _ram);

    // 재정의된 출력 함수
    void printInfo() const override;
};


void addProduct(vector<Product*>& products);
void printProducts(const vector<Product*>& products);
void searchProduct(const vector<Product*>& products);

