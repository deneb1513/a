#include<stdio.h>
#include<iostream>
#include<string>
unsigned int GetStringLength(const wchar_t* _pString)
{
	int i = 0;

	while (1)
	{
		wchar_t c = *(_pString + i);//�������� �ּҰ��� ���ڸ� ����
		//if(c==0)
		if (c == '\0')
		{
			break;
		}
		++i;
	}
	return i;
}
using namespace std;

int main()
{
	_wsetlocale(LC_ALL, L"Korean");

	//2�� ��� ����ϱ�(0~100)

	//int num = 100;
	/*for (int a = 0; a <= num; a+=2)
	{
		printf("%d\n", a);
	}*/

	//n�� ���� �ϳ��� �Է� �ޱ�
	//n�� ��� ����ϱ�

	/*int a, b, c;
	printf("���ϴ� ����� �Է����ּ���");
	scanf_s("%d", &a);
	printf("����ݺ��Ұ�����");
	scanf_s("%d", &b);
	for (c=1; c<b+1; c++)
	{
		printf("%d\n", c*a);
	}*/

	//(0~100) 2�� ����� ���� ���
	//int sum2 = 0;// int�� sum2������� �����ϰ� �ʱⰪ�� 0���� �����Ѵ�.
	//sum2 = 1;// sum2�� 1�� �����Ѵ�.
	//sum2 = sum2+1;// sum2�� 1�� ���Ѱ��� �����Ѵ�.

	/*for (int i = 1; i <= 100; i++)
	{
		if (i % 2 == 0)
		{
			sum2 += 1;
		}
	}
	printf("2�� ����� ������ ���� %d�Դϴ�.\n", sum2);*/

	//abcdef�� ������ ����ϱ� ->fedcba
	//wchar_t szWChar[20] = L"abcdef";

	//int a = wcslen(szWChar);
	//for (int b = 0; b < a; b++)
	//{
	//	wprintf(L"���� ���%c\n", szWChar[a-1-b]);
	//}
	//����� Ǯ��
	//int size = wcslen(szWChar);
	///*printf("size=%d\n", size);
	//printf("%c", szWChar[size - 1]);
	//printf("%c", szWChar[size - 2]);
	//printf("%c", szWChar[size - 3]);
	//printf("%c", szWChar[size - 4]);
	//printf("%c", szWChar[size - 5]);
	//printf("%c", szWChar[size - 6]);*/
 //   //���� for������ �ۼ�
	//for (int i = 1; i <= size; ++i)
	//{
	//	printf("%c", szWChar[size - i]);
	//}




	//wchar_t������ ���� �Է� �ޱ�
	//"szWCharInput"�̸��� ���� wchar_t�������� �����ϰ�
	// [20]�� ũ��� �����ϰ� L""���� �ʱⰪ���� �ִ´�. 
	wchar_t szWCharInput[20] = L"";
	//wscanf_s�� �Է��� �޴� ����� ����ϰڴ�.
	//L"%Is" �������·� �Է��� �ްڴ�.
	//"szWCharInput"������ �Է��� ���� �־��ְڴ�.
	//"(unsigned)_countof(szWCharInput)"�� ���� ���� ������ ũ��
	wscanf_s(L"%Is", szWCharInput, (unsigned)_countof(szWCharInput));
	//wprintf�� ����� �ϴ� ����� ����ϰڴ�.
	//L"szWCharInput=%s"���� ���·� ����ϰڴ�.
	//%s ��ġ�� szWCharInput���� ����ϰڴ�.
	wprintf(L"szWCharInput=%s", szWCharInput);



	//�Է� ���� ���ڿ����� 'a'���� ���� ���
	/*int size = wcslen(szWCharInput);
	int cnt = 0;
	for (int i = 0; i < size; ++i)
	{
		if (szWCharInput[i]=='a')
		{
			cnt++;
		}
	}
	printf("cnt=%d\n", cnt);*/

	int size = wcslen(szWCharInput);
	int cnt = 0;
	for (int i = 0; i < size; ++i)
	{
		if (szWCharInput[i] == 'a')
		{
			cnt++;
		}
	}
	printf("cnt=%d\n", cnt);








}

