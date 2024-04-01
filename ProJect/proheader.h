/*
	   File: linkedList 버전2

		 24-03-27

	   Author: 황지환
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Book {
	int id;
	char title[30];
	char author[10];
	char publisher[50];
	int year;
	bool rented;
	struct Book* next;
} Book;

// Book *head = NULL;

void addbook();

void searbook();

void delbook(char* title);

void view();

void showmenu();

void rentedBook(int pid);

void returnBook(int pid);

