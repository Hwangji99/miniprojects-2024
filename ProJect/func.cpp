/*
       File: Product Manager

         24-03-27

       Author: 황지환
*/


#include <iostream>
#include <string>
#include <vector>
#include "header.h"

using namespace std;
// 상품 추가 함수 정의


Product::Product(int _id, double _price, string _producer) : id(_id), price(_price), producer(_producer) {}

void Product::printInfo() const {
    cout << "ID: " << id << ", Price: " << price << ", Producer: " << producer << endl;
}

int Product::getID() const {
    return id;
}

Product::~Product() {}

Book::Book(int _id, double _price, string _producer, string _ISBN, string _author, string _title)
    : Product(_id, _price, _producer), ISBN(_ISBN), author(_author), title(_title) {}

void Book::printInfo() const {
    Product::printInfo();
    cout << "ISBN: " << ISBN << ", Author: " << author << ", Title: " << title << endl;
}

Handphone::Handphone(int _id, double _price, string _producer, string _model, int _ram)
    : Product(_id, _price, _producer), model(_model), ram(_ram) {}

void Handphone::printInfo() const {
    Product::printInfo();
    cout << "Model: " << model << ", RAM: " << ram << "GB" << endl;
}

Computer::Computer(int _id, double _price, string _producer, string _model, string _cpu, int _ram)
    : Product(_id, _price, _producer), model(_model), cpu(_cpu), ram(_ram) {}

void Computer::printInfo() const {
    Product::printInfo();
    cout << "Model: " << model << ", CPU: " << cpu << "GB" << ", RAM: " << ram << "GB" << endl;
}

void addProduct(vector<Product*>& products) {
    int productType;
    cout << "1. 책 2. 핸드폰 3. 컴퓨터" << endl;
    cout << "상품 종류 선택: ";
    cin >> productType;

    int id;
    double price;
    string producer;
    cout << "ID: ";
    cin >> id;
    cout << "Price: ";
    cin >> price;
    cout << "Producer: ";
    cin >> producer;

    if (productType == 1) {
        string ISBN, author, title;
        cout << "ISBN: ";
        cin >> ISBN;
        cout << "Author: ";
        cin >> author;
        cout << "Title: ";
        cin >> title;
        products.push_back(new Book(id, price, producer, ISBN, author, title)); // 책 객체 추가
    }
    else if (productType == 2) {
        string model;
        int ram;
        cout << "Model: ";
        cin >> model;
        cout << "RAM: ";
        cin >> ram;
        products.push_back(new Handphone(id, price, producer, model, ram));
    }
    else if (productType == 3) {
        string model, cpu;
        int ram;
        cout << "Model: ";
        cin >> model;
        cout << "CPU: ";
        cin >> cpu;
        cout << "RAM: ";
        cin >> ram;
        products.push_back(new Computer(id, price, producer, model, cpu, ram));
    }
}

void printProducts(const vector<Product*>& products) {
    cout << "상품 출력" << endl;
    for (const auto& product : products) {
        product->printInfo();
    }
}

void searchProduct(const vector<Product*>& products) {
    cout << "상품 검색" << endl;
    int searchId;
    cout << "검색할 상품의 ID를 입력하세요: ";
    cin >> searchId;


    bool found = false;
    for (const auto& product : products) {
        if (product->getID() == searchId) {
            product->printInfo();
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "해당 ID의 상품을 찾을 수 없습니다." << endl;
    }
}
