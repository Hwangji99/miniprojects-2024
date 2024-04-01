/*
       File: linkedList 버전2

         24-03-27

       Author: 황지환
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "proheader.h"

int main()
{
    int num;
    int id;
    char title[30];
    char author[10];
    char publisher[50];
    char renter[10];
    int year;

    // 메뉴를 반복하여 출력하고 사용자의 선택에 따라 동작 수행
    while (true) {
        showmenu();
        printf("메뉴를 선택하시오: ");
        scanf("%d", &num);

        switch (num) {
        case 1:
            addbook();
            printf("\n");
            break;
        case 2:
            //printf("검색할 도서의 제목을 입력하세요: ");
            //scanf("%s", title);
            searbook(title);
            printf("\n");
            break;
        case 3:
            printf("삭제할 도서의 제목을 입력하세요: ");
            scanf("%s", title);
            delbook(title);
            printf("\n");
            break;
        case 4:
            view();
            printf("\n");
            break;
        case 5:
            printf("도서를 대여할 도서의 번호를 입력하세요: ");
            scanf("%d", &id);
            printf("대여자 성함: ");
            scanf("%s", renter);
            rentedBook(id);
            printf("\n");
            break;
        case 6:
            printf("도서를 반납할 도서의 번호를 입력하세요: ");
            scanf("%d", &id);
            returnBook(id);
            printf("\n");
            break;
        case 0:
            printf("프로그램을 종료합니다.\n");
            exit(0);
        default:
            printf("잘못된 선택입니다. 다시 선택해주세요.\n");
        }
    }

    return 0;
}
