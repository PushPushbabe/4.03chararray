#pragma once

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
	void big_str_compare();
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

