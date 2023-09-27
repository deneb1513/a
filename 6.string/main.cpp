#include<stdio.h>
#include<iostream>
#include<assert.h>
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
//_Dest : "abcde"
//pSource : "fghi"
void StringCat(wchar_t* _Dest, unsigned int size, const wchar_t *_pSource)
{
	int destLen = GetStringLength(_Dest);
	int SourceLen = GetStringLength(_pSource);

	if (size < destLen + SourceLen + 1)// \0�� ���� 1���� �� �ʿ��ϱ� ������ +1�� ���ش�.
	{
		assert(nullptr);
	}

	for (int i = 0; i < SourceLen; i++)
	{
		*(_Dest + destLen + i) = *(_pSource + i);
		//_Dest[destLen + i] = _pSource[i]; �� ������ ����
	}	
}

int StringCmp(const wchar_t* _pLeft, const wchar_t* _pRight)
{
	int LeftLen = GetStringLength(_pLeft);
	int RinghtLen = GetStringLength(_pRight);
	//���� �� ������ ���� ��ŭ�� ���Ѵ�.
	//���忡 ������ \0�� ���ϱ� ������
	int nLoop = (LeftLen > RinghtLen) ? LeftLen : RinghtLen; //���� ª�� ������ ���� ��ŭ�� ���Ѵ�.

	for (int i = 0; i < nLoop; i++)
	{
		if (_pLeft[i] == _pRight[i])// ���ڰ� ������ ũ��� ����x, �ٽ� for�� ����
			continue;
		return(_pLeft[i] > _pRight[i]) ? 1 : -1; // ũ��� ����� ��ȯ
	}
	//if (LeftLen != RinghtLen)
	//{   //left�� ��� 1, right�� ��� -1
	//	return(LeftLen > RinghtLen) ? 1 : -1; //ũ��� ����� ��ȯ
	//}
	return 0;//��� ���ڰ� ���� ���̵� ����.
}

    int main()

	{
		//���� ó��
		//�ƽ�Ű �ڵ� ��ũ:https://namu.wiki/w/%EC%95%84%EC%8A%A4%ED%82%A4%20%EC%BD%94%EB%93%9C
		//multi-byte
		//127���� �ƽ�Ű �ڵ� ���� ǥ��, ���ڿ� ���� ���������� ũ�Ⱑ �����
		//�������� ȣȯ�� ���� ���� ������� �ٸ� �ý������� ������ ���ڸ� �˾ƺ� �� ���� ����
		//�Ϻ��� �ؽ�Ʈ ������ �ѱ� �����쿡�� �������� ���� ������ ������ ����
		//ö���� �ڱ��� ǥ�⸸�� ���� ���ڵ�, �ܱ��� ���� ���� �ٸ� ����ü�谡 �ʿ��� ��� ������.

		char c1 = 'a';//1Byte(0~255). �ѱ��� �϶��� ''���
		printf("c1=%c\n", c1); // �ѱ��� char ��½� %c ���

		setlocale(LC_ALL, "korea");//multi-byte ��� ����

		char arrC1[10] = "abc�ѱ�";//����� 1Byte, �ѱ��� 2Byte ���. ���ڿ� �϶��� ""���
		printf("arrC1=%s\n", arrC1); // ���ڿ� char ��½� %s ���

		//���̵� ����(wide character)
		//multi-byte�� ������ �ذ��ϱ� ���� ���� �����ڵ� ���
		//������ ���� ��� ���ڸ� ǥ���� �� �ֱ� ������ �ֱٿ� ���� ����
		//���� ���� ����ϴ� ����� UTF-8�� �ִ�.
		wchar_t wc1 = L'a';//2Byte(0~65535)���� ������ 1bit�� �����ϸ� 32767�� ǥ������),wchar_t���� ���ڸ� ������ �տ� L�� ���δ�.
		wprintf(L"wc1=%c\n", wc1); //wchar_t���� ����Ҷ��� wprintf�� ���, ��� ���ڿ� �տ� L�� ���δ�.

		_wsetlocale(LC_ALL, L"korean");//���̵� ���� ��� ����

		wchar_t arrWC1[10] = L"abc�ѱ�"; //wchar_t�迭�� ���ڿ��� ������ �տ� L�� ���δ�.
		wprintf(L"arrWC1=%s\n", arrWC1); //wchar_t���� ����Ҷ��� wprintf�� ���, ��� ���ڿ� �տ� L�� ���δ�.

		wchar_t szWChar[10] = L"abcdefghi";//������ �������� �̸� ���ϴ� ǥ��� '\0'���ڰ� ����>>abcdefghi(\0)�̷��� �����ΰ�
		wprintf(L"szWChar=%s\n", szWChar);

		wchar_t szWCharLen[20] = L"abcdefg";
		int size = wcslen(szWCharLen);//���ڿ� ���� ���ϱ�(iostream ���̺귯�� �Լ�)
		size = GetStringLength(szWCharLen);//���ڿ� ���� ���ϱ�
		printf("szWCharLen size=%d\n", size);

		wcscat_s(szWCharLen, 20, L"hij");//���ڿ� ���̱�(iostream ���̺귯�� �Լ�)
		wprintf(L"szWCharLen=%s\n", szWCharLen);

		wchar_t _Dest[10] = L"abcde";
		wcscat_s(_Dest, 10, L"fghi");
		wprintf(L"_Dest=%s\n", _Dest);

		StringCat(szWCharLen, 20, L"hij");

		wcscpy_s(szWCharLen, L"abcdef");//���� ���ڿ��� �� ���ڿ��� �����ؼ� �ִ´�.

		int nResult = wcscmp(L"abcdef", L"cbcdef");//������ 0, �� �� ���� ������ ������ 1, �� ���� ������ ������ -1
		printf("nResult=%d\n", nResult);

		


		return 0;
	}
