#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>


//네임스페이스는 내부 식별자로 여러개의 라이브러리를 사용할때 이름 간에 충동을 방지하기 위해서 사용
using namespace std;//std의 이름 공간을 가져오겠다=std 라이브러리 함수 앞에 std를 붙이지 않아도 된다.

int main()
{
	/*String이란?
	C++STL에서 제공하는 클래스로, 문자열을 다루는 클래스
	C에서는 char*또는 char[]의 형태로 문자열을 다루었다면, C++에서는 문자열을 하나의 변수 type처럼 사용한다. 
	문자열을 다양하고 쉽게 다룰 수 있게 해준다.
	char*, char[]와는 다르게 문자열의 끝에'\0'문자가 들어가지 않으며, 문자열의 길이를 동적으로 변경 가능하다.*/

	wchar_t chars[20] = L"abcdef";
	int result = wcscmp(chars, L"abcdef"); //길이확인
	wcscpy_s(chars, 20, L"ghijkl"); //문자열 붙이기

	//변수명 : std::string
	//변수 이름: strA
	//기본값 : ("abcdef")
	std::string strA("abcdef");//<<-기본 문법
	printf("strA= %s\n", strA.c_str());//문자열 출력은 c_str()을 사용하여 출력
	size_t size = strA.size();//문자열 크기 구하기
	size_t len = strA.length();//문자열 길이 구하기

	std::string A("12");
	std::string B("34");
	A += B;// A에다가 B의 문자열을 붙힌다.
	A = B;// A에 B값을 대입한다.
	printf("A=%s, B=%s\n", A.c_str(), B.c_str());
	//if(A="A")string 비교시에 문자열은 ""로 비교한다.
	if (A == B)//문자열 비교 연산자 가능
	{
		printf("A와 B는 같다.\n");
	}

	std::wstring wstr;//wchar_t형 string
	//auto : 대입한 값의 형태에 따라 자동으로 변수형이 설정이 된다.
	auto stringS = "abcdef"s;

	double d = 3.14;
	string strD = to_string(d);//숫자->문자 변환
	printf("strD=%s\n", strD.c_str());

	string toParse = " 123USD";
	size_t index = 0;
	//stoi(int), stof(float), stod(double), stol(long)
	int nResult = stoi(toParse, &index); //문자 -> 숫자로 변환
	printf("stoi result=%d\n", nResult); //nResult 변환된 숫자
	printf("toParse index Character =%c\n", toParse[index]);//index : Parse가 불가능한 시작 포인트
	
	
	string findStr = "123SABC456SORRY";
	int nPointL = findStr.find('S'); //왼쪽에서 부터 문자 찾기
	printf("Finf Point[%d] Character =%c\n", nPointL, findStr[nPointL]); //nPoint : 찾은 문자열 위치
	int nPointR = findStr.rfind('S');//오른쪽에서 부터 문자찾기
	printf("rFinf Point[%d] Character =%c\n", nPointR, findStr[nPointR]);

	string strleft = findStr.substr(0, nPointL);//문자열 잘라오기. 0부터 nPointL 길이만큼
	string strcenter = findStr.substr(nPointL, nPointR- nPointL);//nPointL부터 nPointR- nPointL뺀만큼의 길이까지 출력
	string strright = findStr.substr(nPointR, findStr.length() - nPointR);//nPointR부터 findStr.length()(전체길이에서) - nPointR이만큼을 제거한 길이까지만 출력
	printf("strleft=%s\nstrcenter=%s\nstrright=%s\n", strleft.c_str(), strcenter.c_str(), strright.c_str());//각각의 길이를 출력한다.

	string testStr = "1, 2, 3, 4, 5, 6, 7, 8, 9";

	stringstream ssTest(testStr);// string문자열을 stringstream 변수형태로 만든다.
	string line; //읽어온 string을 담아둘 변수
	
	//ssTest를 왼쪽부터 ','를 기준으로 문자를 잘라서 line에 넣는다.
	//getline 결과가 false(더 이상 읽을 문자열이 없다)면 종료
	while (getline(ssTest, line, ','))
	{
		printf("line=%s\n", line.c_str());
	}

	//스트링에서 특정 문자 제거
	remove(testStr.begin(), testStr.end(), ',');
	testStr.erase(remove(testStr.begin(), testStr.end(),','), testStr.end());

}