/*
       File: file 입출력

         24-03-27

       Author: 황지환
*/

#include <stdio.h>
#include <string.h>

#define MAX_ID_LENGTH 20      // ID 최대 길이
#define MAX_PASSWORD_LENGTH 20   // 비밀번호 최대 길이

int main() {
    char id[MAX_ID_LENGTH];
    char pw[MAX_PASSWORD_LENGTH];
    char stid[MAX_ID_LENGTH];    // 저장된 아이디
    char stpw[MAX_PASSWORD_LENGTH];    // 저장된 비밀번호

    // 저장된 아이디와 비밀번호 설정
    strcpy(stid, "wlghks123");   // strcpy를 사용한 이유는 문자열을 나중에 변경해야 할 수도 있고, 사용자로부터 입력을 받는 경우에 코드를 유연하게 유지하면서 가독성을 높일 수 있기 때문
    strcpy(stpw, "wlghks123");

    // 아이디 입력
    printf("아이디를 입력하세요: ");
    scanf("%s", id);

    // 비밀번호 입력
    printf("비밀번호를 입력하세요: ");
    scanf("%s", pw);

    // 입력된 아이디와 비밀번호가 저장된 것과 일치하는지 확인
    if (strcmp(id, stid) == 0 && strcmp(pw, stpw) == 0) {   // strcmp() 함수를 사용하여 두 문자열 비교   // id < stid 인 경우 음수 반환, 반대면 양수 반환, 같으면 0을 반환
        printf("로그인 성공!\n");
        // 파일 열기
        FILE* file = fopen("myinfo.txt", "r");     // myinfo 파일 읽기
        if (file != NULL) {
            printf("파일을 열었습니다.\n");
            // 파일 내용 읽기 등 파일 작업 수행
            fclose(file); // 파일 닫기
        }
        else {
            printf("파일을 열 수 없습니다.\n");
        }
    }
    else {
        printf("아이디 또는 비밀번호가 일치하지 않습니다.\n");
    }

    return 0;
}
