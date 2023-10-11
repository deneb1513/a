#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std; //std��� ���ӽ����̽��� �����Ͽ� sdt���̺귯�� �Լ� �տ� std�� ������ �ʾƵ� �ȴ�.

struct stTest
{
	string m_name;
	int m_math;
	int m_eng;
	int m_lang; //��� ���� ����

	stTest(string name = "", int math = 0, int eng = 0, int lang = 0):m_name(name), m_math(math), m_eng(eng), m_lang(lang){} //��� �Լ� ����

	void printTest()
	{
		printf("name=%s, math=%d, eng=%d, lang=%d\n", m_name.c_str(), m_math, m_eng, m_lang);
	}//��� �Լ� ����

	void SetData(string& str)
	{
		stringstream ssTest(str);// stirng ���ڿ��� stringstream�̶�� �������·� �����.
		string line; //�о�� string�� ��Ƶ� ����

		while (getline(ssTest, line, ','))//ssTest�� ���ʺ��� ','�� �������� ���ڸ� �о line�� �ִ´�.\
			//���� ���ڿ��� ������ ����
		{
			int index = line.find('=');//ã�� line���� index�� �����Ѵ�.
			string leftStr = line.substr(0, index);//substr�� ���ڿ��� �߶��ش�. 0�������� index����. �׷��� �߶��� ���� leftStr�� �־��ش�.
			string rightStr = line.substr(index + 1, line.length() - index);//substr�� ���ڿ��� �߶��ش�. index+1���� ������ ��ü���̿��� �ε����� ������ ������ŭ. rightStr�� �߶��� ���� �־��ش�. 

			if (leftStr == "name")//lefrStr�� "name"���� ���ٸ� �۵�
			{
				m_name = rightStr;//m_name�� rightStr ���� �����Ѵ�.
			}
			else if (leftStr == "math")//if�� �۵����� �ʾ����� �۵�. leftStr�� math�� ���ٸ� �۵�
			{
				m_math = stoi(rightStr);//m_math�� rightStr���� �����Ѵ�.
			}
			else if (leftStr == "eng")//���� else if�� �۵����� �ʾ����� �۵�. leftStr�� eng�� ���ٸ� �۵�
			{
				m_eng = stoi(rightStr);//m_eng�� rightStr���� �����Ѵ�.
			}
			else if (leftStr == "lang")//���� else if�� �۵����� �ʾ����� �۵�. leftStr�� lang�� ���ٸ� �۵�
			{
				m_lang = stoi(rightStr);//m_lang�� rightStr���� �����Ѵ�.
			}
		}
	}

};

int main()
{
	std::ifstream readFile; //���� �б�
	readFile.open("test.txt");//test.txt�� �����ش�.

	vector<stTest>vecTest;//���� �迭�� ������ش�.

	if (readFile.is_open())//������ ���ȴٸ� �۵�
	{
		while (!readFile.eof())//������ �����ִ� ���� �ݺ�
		{
			std::string str;
			std::getline(readFile, str);

			stTest newData;
			newData.SetData(str);
			vecTest.push_back(newData);
		}
		readFile.close();//������ �ݾ��ش�.
	}

	for (stTest& test : vecTest)
	{
		test.printTest();
	}//����� ���
}