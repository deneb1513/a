#include<stdio.h>
#include<iostream>

class CName
{
public:
	CName(const wchar_t*name):szName(nullptr), len(0)//������
	{
		len = wcslen(name)+1;
		szName = new wchar_t[len];//���� ����
		wcscpy_s(szName, len, name);
	}
	//���� ������ �� ���� �Ҵ� ������(C++)
	//�Ķ��Ÿ�� (const CName& Other)�� ���� �ڽ��� Ŭ���� Ÿ���� ���۷����� ������ ���� ������
	CName(const CName& Other) :szName(nullptr), len(0)//������
	{
		if (szName != nullptr)
		{
			delete[]szName;
		}

		len = wcslen(Other.szName) + 1;
		szName = new wchar_t[len];
		wcscpy_s(szName, len, Other.szName);
	}

	~CName()//�ı���
	{
		delete[] szName;//new�� ����߱� ������ delete�� ���, []�� �Ἥ �迭���� �˷���
	}

	wchar_t* GetName()
	{
		return szName;
	}

	const CName& operator=(const CName& Other)
	{
		//szName = Other. szName;//other. szName�� ����Ű�� �ִ� ���� szname�� ����Ű�� �ϰڴ�.(���� ����)
		//len = Other.len;

		if (szName != nullptr)
		{
			delete[]szName;
		}

		//Other.szName�� �����ؼ� szName�� �ִ´�.(���� ����)
		len = wcslen(Other.szName) + 1;
		szName = new wchar_t[len];
		wcscpy_s(szName, len, Other. szName);
		return*this;
	}

	wchar_t* szName;
	size_t len;
};

int main()
{
	_wsetlocale(LC_ALL, L"korean");

	CName name1(L"����");
	CName name2(L"������");
	
	name1 = name2;//���� ������ ó��

	CName name3 = name1;

	wprintf(L"name1=%s", name1.GetName());
}