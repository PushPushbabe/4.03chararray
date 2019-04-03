// 4.03_chararray_start.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
//#include "Mystring.h"

typedef enum { False, True }BOOL;


typedef class strclass //생성자 2개
{
private:
	int strlen;
	char one_char;
	char * str_char;
public:
	strclass(char);
	strclass(char*);
	int Return_strlen(char*);
	int chrcmp(char* const, char* const);
	char * str_cat(char * const, char * const);
	char * Find_str(char * const, char * const);
	char * Find_chr(char * const, char);
}Str;

strclass::strclass(char init_chr) //char 한개 받는경우 생성자
{
	strlen = 1;
	one_char = init_chr;
	str_char = NULL;
}

strclass::strclass(char * const _str_char) //char 문자열 받는 경우 생성자
{
	strlen = Return_strlen(_str_char);
	one_char = *_str_char;
	str_char = _str_char;
}


int strclass::Return_strlen(char*  const str) //문자열의 수 리턴 함수
{
	int count = 0;
	if (*str == NULL)
	{
		puts("String was NULL");
		return NULL;
	}
	else
	{
		while (*(str + count) != NULL) //문자 수 카운팅
		{
			count += sizeof(char);
		}
		return count;
	}
}


char* strclass::Find_chr(char* const str, char const chr) //특정 문자 찾기 함수
{
	if (chr == NULL)
	{
		puts("chr was NULL");
		return NULL;
	}
	else if (str == NULL)
	{
		puts("str was NULL");
		return NULL;
	}
	int count = NULL;

	while (*(str + count) != chr) //문자열 순차탐색 시작
	{
		count += sizeof(char);

		if (*(str + count) == NULL) //탐색실패
		{
			puts("Find_chr 탐색실패");
			return NULL;
		}
	}

	return (str + count); //탐색 성공
}

int strclass::chrcmp(char* const chr1, char* const chr2)  //문자열 값 비교
{
	if (*chr1 == *chr2)
		return True;
	else
		return NULL;
}


char* strclass::Find_str(char * const base_str, char * const find_str) //문자열 내에서 특정 문자열을 찾는 함수
{
	int count = 0;
	int i = 0;
	int max_count = Return_strlen(find_str);
	char * ptr_str = base_str;


	if (base_str == NULL)
	{
		puts("base_str was NULL");
		return NULL;
	}
	else if (find_str == NULL)
	{
		puts("find_str was NULL");
		return NULL;
	}

	//순차탐색 시작
	ptr_str = Find_chr(base_str, *find_str);

	for (i = 0;i < max_count; i++)
	{
		if (chrcmp((ptr_str + i), (find_str + i)) == 0) //모든 문자가 맞지 않는 경우 초기화
		{
			ptr_str = Find_chr((ptr_str + i), *find_str);
			i = NULL;

			if (ptr_str == NULL) //찾지 못한 경우
			{
				puts("Find_str 탐색실패");
				return ptr_str;
				break;
			}
		}
	}
	return ptr_str;

}

char* strclass::str_cat(char* const forepart_str, char* const postpart_str)
{	
	if (forepart_str == NULL || postpart_str == NULL)
		return 0;

	int fore_leng = Return_strlen(forepart_str);
	int post_leng = Return_strlen(postpart_str);
	int max_leng = fore_leng + post_leng +1;
	int i = 0;
	char * full_str = new char[max_leng];

	for (i = 0; i < fore_leng;i++)
	{
		*(full_str + i) = *(forepart_str + i);
	}
	for (i = 0;i < post_leng;i++)
	{
		*(full_str + fore_leng + i) = *(postpart_str + i);
	}
	*(full_str + max_leng) = NULL;

	return full_str;

}


int main()
{
	char str1[20] = "Hello";
	char str2[20] = "master";
	char * str4 = NULL;
	Str * str3;
	str3 = new Str(str2);

	str4 = str3->str_cat(str1, str2);

	std::cout <<str4;
	BOOL logic = True;
	//std::cout << logic;
   
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
