/*
       File: linkedList 버전2

         24-03-27

       Author: 황지환
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "proheader.h"

Book* head = NULL;

void addbook()//char* tt, char* aa, char* publisher, int dd)
{
    Book* newBook = (Book*)malloc(sizeof(Book)); // 새로운 도서를 위한 메모리 할당

    printf("*************\n");

    // 도서 정보 입력 받기
    printf("도서 제목: ");
    scanf("%s", newBook->title);
    printf("도서 번호: ");
    scanf("%d", &newBook->id);
    printf("저자: ");
    scanf("%s", newBook->author);
    printf("출판사: ");
    scanf("%s", newBook->publisher);
    printf("출판년도: ");
    scanf("%d", &newBook->year);    // 정수형 변수를 받을 때는 &를 붙여야 한다

    newBook->next = NULL; // 새로운 도서의 다음 도서 포인터를 초기화

    if (head == NULL) {
        // 만약 도서관이 비어있다면 새로운 도서를 첫 번째 도서로 지정
        head = newBook;
    }
    else {
        // 도서관에 이미 도서가 있는 경우, 연결 리스트의 끝에 새로운 도서를 추가
        Book* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newBook;
    }

    printf("도서가 등록되었습니다.\n");
}

void showmenu()
{
    printf("**** 메뉴 ****\n");
    printf("1. 도서구입(등록)\n");
    printf("2. 도서검색\n");
    printf("3. 도서삭제\n");
    printf("4. 도서출력\n");
    printf("5. 도서대여\n");
    printf("6. 도서반납\n");
    printf("0. 종료\n");
    printf("**************\n");
}

void searbook()
{
    // 도서가 하나도 등록되지 않았을 경우 처리
    if (head == NULL) {
        printf("등록된 도서가 없습니다.\n");
        return;
    }

    int choice, num;
    int result = 0;
    char keyword[50];
    printf("검색할 조건을 선택하세요:\n");
    printf("1. 제목\n");
    printf("2. 도서 번호\n");
    printf("3. 저자\n");
    printf("4. 출판사\n");
    printf("5. 출판년도\n");
    printf("번호를 입력하세요: ");
    scanf("%d", &choice);

    if (choice == 1 || choice == 3 || choice == 4) {
        printf("검색어를 입력하세요: ");
        scanf("%s", keyword);
    }
    else if (choice == 2 || choice == 5) {
        printf("검색어를 입력하세요: ");
        scanf("%d", &num);
    }

    Book* current = head;
    bool found = false;

    while (current != NULL) {
        switch (choice) {
        case 1: // 제목으로 검색
            if (strcmp(current->title, keyword) == 0) {
                found = true;
            }
            break;
        case 2: // 도서 번호로 검색
            if (current->id == num) { // 문자열을 정수로 변환하여 비교
                found = true;
            }
            break;
        case 3: // 저자로 검색
            if (strcmp(current->author, keyword) == 0) {
                found = true;
            }
            break;
        case 4: // 출판사로 검색
            if (strcmp(current->publisher, keyword) == 0) {
                found = true;
            }
            break;
        case 5: // 출판년도로 검색
            if (current->year == num) { // 문자열을 정수로 변환하여 비교
                found = true;
            }
            break;
        default:
            printf("잘못된 선택입니다.\n");
            return;
        }

        // 검색어와 일치하는 도서를 찾은 경우 해당 도서 정보 출력
        if (found) {
            printf("도서가 존재합니다.  ");
            printf("도서 제목: %s  ", current->title);
            printf("저자: %s  ", current->author);
            printf("출판사: %s  ", current->publisher);
            printf("출판년도: %d\n", current->year);
            found = false;
            result++;
        }

        current = current->next;
    }

    // 도서를 찾지 못한 경우 메시지 출력
    if (result == 0) {
        printf("도서가 존재하지 않습니다.\n");
    }
}

void delbook(char* title)
{
    if (head == NULL) {
        printf("등록된 도서가 없습니다.\n");
        return;
    }

    Book* current = head;
    Book* prev = NULL;

    // 삭제할 도서를 찾음
    while (current != NULL) {
        if (strcmp(current->title, title) == 0)
        {
            // 삭제할 도서를 찾음
            if (prev == NULL)
            {
                // 삭제할 도서가 첫 번째 도서인 경우
                head = current->next;
            }
            else
            {
                // 삭제할 도서가 중간이나 마지막에 있는 경우
                prev->next = current->next;
            }
        }
        // 메모리 해제
        free(current);
        printf("도서가 삭제되었습니다.\n");
        return;
    }
}

void view()
{
    Book* current = head;

    if (current == NULL) {
        printf("등록된 도서가 없습니다.\n");
        return;
    }

    printf("등록된 도서 목록\n");

    while (current != NULL) {
        printf("도서 번호: %d  ", current->id);
        printf("도서 제목: %s  ", current->title);
        printf("저자: %s  ", current->author);
        printf("출판사: %s  ", current->publisher);
        printf("출판년도: %d  ", current->year);
        printf("\n");
        current = current->next;
    }
}


void rentedBook(int pid) {
    Book* current = head;

    while (current != NULL) {
        if (current->id == pid) {
            if (current->rented) {
                printf("이미 대여된 도서입니다.\n");
                return;
            }
            else {
                current->rented = true;
                printf("도서가 대여되었습니다.\n");
                return;
            }
        }
        current = current->next;
    }

    printf("해당 도서를 찾을 수 없습니다.\n");
}

void returnBook(int pid) {
    Book* current = head;

    while (current != NULL) {
        if (current->id == pid) {
            if (current->rented) {
                current->rented = false;
                printf("도서가 반납되었습니다.\n");
                return;
            }
            else {
                printf("이 도서는 이미 반납되었습니다.\n");
                return;
            }
        }
        current = current->next;
    }

    printf("해당 도서를 찾을 수 없습니다.\n");
}
