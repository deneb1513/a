#include<stdio.h>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;

struct  stTest
{
	//멤버 변수 설정
	string m_name = "";
	int m_math = 0;
	int m_eng  = 0;
	int m_lang = 0;
	
	//변수값 초기화
	stTest(string name, int math, int eng, int lang):
	m_name(name), m_math(math), m_eng(eng), m_lang(lang){}

	void printTest()
	{
		printf("name=%s,math=%d, eng=%d, lang=%d\n", m_name.c_str(), m_math, m_eng, m_lang);
	}//각각의 값을 출력하는 구문
};

void pushStTest(vector<stTest>&vecTest, string& str)
{
	stringstream ssTest(str);//string 문자열을 읽어와서 stringstream이라는 변수형태로 만들어준다.
	string line;//읽어온 string을 담아줄 변수

	while (getline(ssTest, line, ','))//문자열을 한줄씩 읽어준다. sstest를 왼쪽부터 ','를 기준으로  문자를 읽어서 line에 넣어준다.
		//더이상 읽을 문자열이 없으면 종료
	{
		line.erase(remove(line.begin(), line.end(), ' '), line.end());//라인에서 특정 문자를 없애준다. 여기서는 공백문자를 제거한다.
		printf("line[%s]\n", line.c_str());//읽어온 배열을 출력한다.
	}
}


int main()
{
	//파일쓰기
	std::ofstream writeFile;
	writeFile.open("test.txt");//"test.txt" 파일을 연다.(파일이 없다면 생성한다.)

	//std::string strTest = "a=100, b=200\n";
	//writeFile.write(strTest.c_str(), strTest.size());

	//writeFile.close();//파일을 열었으면 반드시 닫기

	//파일 읽기
	std::ifstream readFile;
	readFile.open("test.txt");

	vector <stTest> vectest;
	stTest aaa("aaa", 80, 70, 60); 
	vectest.push_back(aaa);
	stTest bbb("bbb", 90, 30, 40);
	vectest.push_back(bbb);
	stTest ccc("ccc", 20, 90, 80);
	vectest.push_back(ccc);

	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			std::string str;
			std::getline(readFile, str);//readFile에 텍스트를 한줄 읽어서 str에 넣는다.
			printf("str=%s\n", str.c_str());
			
			int nPointL = str.find('=');
			
			pushStTest(vectest, str);
			string strleft = str.substr(0, nPointL);
			
			printf("strleft=%s\n", strleft.c_str());

			//str에서 a=100, b=200이 들어있음.
			/*size_t index= str.find('=');
			std::string strRight = str.substr(index+1, str.length() - index);
			std::string strleft = str.substr(0, index);
			int num = atoi(strRight.c_str());

			if (strleft == "a")
			{
				test.a = num;
			}
			else if (strRight == "b")
			{
				test.b = num;
			}*/
		}
		readFile.close();
	}

	for (stTest& test : vectest)
	{
		test.printTest();
	}
	
}
