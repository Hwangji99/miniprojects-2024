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

// 메인 함수
int main() {
    vector<Product*> products;  // 제품들을 보관하는 벡터

    int choice;
    while (true) {
        cout << "상품관리 프로그램" << endl;
        cout << "1. 상품추가 2. 상품출력 3. 상품검색 0. 종료" << endl;
        cout << "선택: ";
        cin >> choice;

        switch (choice) {
        case 0:
            // 동적 할당한 객체들 삭제
            for (auto& product : products) {
                delete product;
            }
            return 0;
        case 1:
            addProduct(products);       // 상품 추가 함수 호출
            break;
        case 2:
            printProducts(products);    // 상품 출력 함수 호출
            break;
        case 3:
            searchProduct(products);    // 상품 검색 함수 호출
            break;
        default:
            cout << "잘못된 선택입니다. 다시 선택해주세요." << endl;
            break;
        }
    }

    return 0;
}
