#include<stdio.h>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;

struct  stTest
{
	//��� ���� ����
	string m_name = "";
	int m_math = 0;
	int m_eng  = 0;
	int m_lang = 0;
	
	//������ �ʱ�ȭ
	stTest(string name, int math, int eng, int lang):
	m_name(name), m_math(math), m_eng(eng), m_lang(lang){}

	void printTest()
	{
		printf("name=%s,math=%d, eng=%d, lang=%d\n", m_name.c_str(), m_math, m_eng, m_lang);
	}//������ ���� ����ϴ� ����
};

void pushStTest(vector<stTest>&vecTest, string& str)
{
	stringstream ssTest(str);//string ���ڿ��� �о�ͼ� stringstream�̶�� �������·� ������ش�.
	string line;//�о�� string�� ����� ����

	while (getline(ssTest, line, ','))//���ڿ��� ���پ� �о��ش�. sstest�� ���ʺ��� ','�� ��������  ���ڸ� �о line�� �־��ش�.
		//���̻� ���� ���ڿ��� ������ ����
	{
		line.erase(remove(line.begin(), line.end(), ' '), line.end());//���ο��� Ư�� ���ڸ� �����ش�. ���⼭�� ���鹮�ڸ� �����Ѵ�.
		printf("line[%s]\n", line.c_str());//�о�� �迭�� ����Ѵ�.
	}
}


int main()
{
	//���Ͼ���
	std::ofstream writeFile;
	writeFile.open("test.txt");//"test.txt" ������ ����.(������ ���ٸ� �����Ѵ�.)

	//std::string strTest = "a=100, b=200\n";
	//writeFile.write(strTest.c_str(), strTest.size());

	//writeFile.close();//������ �������� �ݵ�� �ݱ�

	//���� �б�
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
			std::getline(readFile, str);//readFile�� �ؽ�Ʈ�� ���� �о str�� �ִ´�.
			printf("str=%s\n", str.c_str());
			
			int nPointL = str.find('=');
			
			pushStTest(vectest, str);
			string strleft = str.substr(0, nPointL);
			
			printf("strleft=%s\n", strleft.c_str());

			//str���� a=100, b=200�� �������.
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
