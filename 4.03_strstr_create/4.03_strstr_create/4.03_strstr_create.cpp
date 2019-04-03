// 4.03_strstr_create.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

//string.h에 구현되어 있는 strstr함수를 구현해보자.
//동작 : 문자열내의 특정 문자를 확인하여 해당 문자열의 위치를 문자열 포인터로 반환, 없으면 null 반환
//시작 : strlen을 구현해야 한다.
//strchr도 구현
#include "pch.h"
#include <iostream>
#include <string.h>

using namespace std;



int Return_strlen(char*  const str) //문자열의 수 리턴 함수
{
	int count= 0;

	if (*str == NULL)
	{
		puts("String was NULL");
		return 0;
	}
	else
	{
		while (*(str+count) != NULL) //문자 수 카운팅
		{
			count += sizeof(char);
		}
		return count; 
	}
}

char* Find_chr(char* const str, char const chr) //특정 문자 찾기 함수
{
	if (chr == NULL)
	{
		puts("chr was NULL");
		return 0;
	}
	else if (str == NULL)
	{	
		puts("str was NULL");
		return 0;
	}	
	int count = 0;

	while (*(str + count) != chr) //문자열 순차탐색 시작
	{
		count += sizeof(char);

		if (*(str + count) == NULL) //탐색실패
		{
			puts("Find_chr 탐색실패");
			return 0;
		}
	}

	return (str + count); //탐색 성공
}



int chrcmp(char* const chr1, char* const chr2)
{
	if (*chr1 == *chr2)
		return 1;
	else
		return 0;
}




char* Find_str(char * const base_str, char * const find_str) //문자열 내에서 특정 문자열을 찾는 함수
{
	int count = 0;
	int i = 0;
	int max_count = strlen(find_str);
	char * ptr_str = base_str;
	int num = 0;

	if (base_str == NULL)
	{
		puts("base_str was NULL");
		return 0;
	}
	else if (find_str == NULL)
	{
		puts("find_str was NULL");
		return 0;
	}
	
	//순차탐색 시작
	ptr_str = Find_chr(base_str, *find_str);
	/*Find_chr(ptr_str + 1, *(find_str + 1)) != 0 ?;
	Find_chr(ptr_str + 2, *(find_str + 2)) != 0 ?;
	Find_chr(ptr_str + 3, *(find_str + 3)) != 0 ?;
	....add < strlen(find_str);
*/
	for (i = 0;i < max_count; i++)
	{
		printf("ptr_str이 가리키는 것 %c, find_str이 가리키는 것 %c\n", *(ptr_str + i),*( find_str + i));
		num = chrcmp((ptr_str + i), (find_str + i));		
		if (num == 0)
		{
			ptr_str = Find_chr((ptr_str + i), *find_str);
			i = 0;
		}
		else if (ptr_str == NULL)
			return 0;
	}
	printf("ptr_str이 가리키는 것 %c, ptr_str이 가리키는 주소 %d", *(ptr_str), ptr_str);
	return ptr_str;
	
}







int main()
{
	int num=0;
	char str1[20] = "des des dis";
	char * ptr_char=0;
	char str2[10] = "dis";

	num = Return_strlen(str1);
	
	ptr_char = Find_chr(str1, 'w');
	cout << endl;
	//printf("str1의 주소 %d, ptr_char의 주소 %d, ptr_char가 가리키고 있는 것%c", str1, ptr_char, *ptr_char);

	ptr_char = Find_str(str1, str2);
	if (ptr_char != NULL)
		printf("\n베이스문자열 str1의 주소는 %d 찾은 문자열 %s이고 위치는 %d 가리키는 값은 %c", str1, str2, ptr_char, *ptr_char);

	cout << endl;

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
