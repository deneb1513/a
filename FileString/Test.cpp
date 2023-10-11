#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std; //std라는 네임스페이스를 생성하여 sdt라이브러리 함수 앞에 std를 붙이지 않아도 된다.

struct stTest
{
	string m_name;
	int m_math;
	int m_eng;
	int m_lang; //멤버 변수 설정

	stTest(string name = "", int math = 0, int eng = 0, int lang = 0):m_name(name), m_math(math), m_eng(eng), m_lang(lang){} //멤버 함수 설정

	void printTest()
	{
		printf("name=%s, math=%d, eng=%d, lang=%d\n", m_name.c_str(), m_math, m_eng, m_lang);
	}//출력 함수 설정

	void SetData(string& str)
	{
		stringstream ssTest(str);// stirng 문자열을 stringstream이라는 변수형태로 만든다.
		string line; //읽어온 string을 담아둘 변수

		while (getline(ssTest, line, ','))//ssTest를 왼쪽부터 ','를 기준으로 문자를 읽어서 line에 넣는다.\
			//읽을 문자열이 없으면 종료
		{
			int index = line.find('=');//찾은 line값을 index에 저장한다.
			string leftStr = line.substr(0, index);//substr로 문자열을 잘라준다. 0에서부터 index까지. 그렇게 잘라준 값을 leftStr에 넣어준다.
			string rightStr = line.substr(index + 1, line.length() - index);//substr로 문자열을 잘라준다. index+1부터 라인의 전체길이에서 인덱스를 뺀길이 까지만큼. rightStr에 잘라준 값을 넣어준다. 

			if (leftStr == "name")//lefrStr과 "name"값이 값다면 작동
			{
				m_name = rightStr;//m_name에 rightStr 값을 대입한다.
			}
			else if (leftStr == "math")//if가 작동하지 않았을때 작동. leftStr과 math가 같다면 작동
			{
				m_math = stoi(rightStr);//m_math에 rightStr값을 대입한다.
			}
			else if (leftStr == "eng")//위의 else if가 작동하지 않았을때 작동. leftStr와 eng가 같다면 작동
			{
				m_eng = stoi(rightStr);//m_eng에 rightStr값을 대입한다.
			}
			else if (leftStr == "lang")//위의 else if가 작동하지 않았을때 작동. leftStr와 lang가 같다면 작동
			{
				m_lang = stoi(rightStr);//m_lang에 rightStr값을 대입한다.
			}
		}
	}

};

int main()
{
	std::ifstream readFile; //파일 읽기
	readFile.open("test.txt");//test.txt를 열어준다.

	vector<stTest>vecTest;//벡터 배열로 만들어준다.

	if (readFile.is_open())//파일이 열렸다면 작동
	{
		while (!readFile.eof())//파일이 열려있는 동안 반복
		{
			std::string str;
			std::getline(readFile, str);

			stTest newData;
			newData.SetData(str);
			vecTest.push_back(newData);
		}
		readFile.close();//파일을 닫아준다.
	}

	for (stTest& test : vecTest)
	{
		test.printTest();
	}//결과값 출력
}