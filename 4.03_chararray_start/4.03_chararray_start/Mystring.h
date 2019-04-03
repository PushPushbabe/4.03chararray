#pragma once

typedef enum { False, True }BOOL;

typedef class strclass //������ 2��
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

strclass::strclass(char init_chr) //char �Ѱ� �޴°�� ������
{
	strlen = 1;
	one_char = init_chr;
	str_char = NULL;
}

strclass::strclass(char * const _str_char) //char ���ڿ� �޴� ��� ������
{
	strlen = Return_strlen(_str_char);
	one_char = *_str_char;
	str_char = _str_char;
}


int strclass::Return_strlen(char*  const str) //���ڿ��� �� ���� �Լ�
{
	int count = 0;
	if (*str == NULL)
	{
		puts("String was NULL");
		return NULL;
	}
	else
	{
		while (*(str + count) != NULL) //���� �� ī����
		{
			count += sizeof(char);
		}
		return count;
	}
}


char* strclass::Find_chr(char* const str, char const chr) //Ư�� ���� ã�� �Լ�
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

	while (*(str + count) != chr) //���ڿ� ����Ž�� ����
	{
		count += sizeof(char);

		if (*(str + count) == NULL) //Ž������
		{
			puts("Find_chr Ž������");
			return NULL;
		}
	}

	return (str + count); //Ž�� ����
}

int strclass::chrcmp(char* const chr1, char* const chr2)  //���ڿ� �� ��
{
	if (*chr1 == *chr2)
		return True;
	else
		return NULL;
}


char* strclass::Find_str(char * const base_str, char * const find_str) //���ڿ� ������ Ư�� ���ڿ��� ã�� �Լ�
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

	//����Ž�� ����
	ptr_str = Find_chr(base_str, *find_str);

	for (i = 0;i < max_count; i++)
	{
		if (chrcmp((ptr_str + i), (find_str + i)) == 0) //��� ���ڰ� ���� �ʴ� ��� �ʱ�ȭ
		{
			ptr_str = Find_chr((ptr_str + i), *find_str);
			i = NULL;

			if (ptr_str == NULL) //ã�� ���� ���
			{
				puts("Find_str Ž������");
				return ptr_str;
				break;
			}
		}
	}
	return ptr_str;

}

