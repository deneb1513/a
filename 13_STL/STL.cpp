#include<stdio.h>
#include<vector>
#include<list>

struct stMonster
{
	int index = 0;//���� Ÿ��
};

bool isFindMonindex(const stMonster& mon)
{
	return mon.index == 3;//���� Monindex�� 3�̸� true��ȯ, �ƴϸ� false ��ȯ
}

int main()
{
	/*STL
	�������� ���� �������� �迭
	�迭 �����ϸ鼭 ó������ ������ �������� �ʰ� �ʿ��Ҷ� ���� �ø��� ���ϼ� �ִ� �迭
	1.����(vector)
	�������� �޸𸮸� Ȯ���Ѵ�.
	�ڽ��� ��Ҹ� ������ ���� �迭(Dynamic array)�� �����Ѵ�.
	���� ���� �����ڸ� ����([])�ϱ� ������ ��� ���� �����ϵ� ����ð�(������ �ð�)�� �ҿ�ȴ�.
	���� �迭�̱� ������ �迭�� �߰��� ���� �߰��ϰų� �����ϸ� ���� ���� �̵��ؾ��ϱ� ������ ���� �ð��� �ɸ���.
	�߰��� �߰��ϴ� ���� ������尡 ũ�� ������ ���� �޺κп� �߰��Ѵ�(push_back)
	���� �迭�̱� ������ ũ���� Ȯ��� ��Ұ� ���������� ���Ҵ� ����� ũ��.

	����
	���� ������ ����ð�(������ �ð�)�� �����ϹǷ�, �б� �ӵ��� �ſ� ������.

	����
	�߰��� ���� �߰�/�����ϴ� ����� ũ��.
	���Ҵ� ����� ũ��.

	std::vector<int> : int���� vector�迭
	vecint : vector �迭�� ����
	{0, 1, 2, 3, 4} : vecint�� �ʱⰪ �ֱ�*/
	//std::vector<int>vecint{0, 1, 2, 3, 4};
	//int vectorsize = vecint.size();//������ ��� ���� ��ȯ
	//int vec0 = vecint[0];//[]��Ȯ�� ��ġ�� �־ ���� ����
	//int* pData = vecint.data();//���� �迭 ���� ������ �޸� ������ �ּ�(������)�� ��ȯ
	//int vCap = vecint.capacity();//������ ũ�� ���鿡���� ���� ���� ũ�⸦ ��ȯ
	//printf("vecint capacity=%d\n", vCap);
	//for (int i = 0; i < vecint.size(); i++)
	//{
	//	printf("vecint[%d]=%d\n", i, vecint[i]);
	//}
	//for (int value : vecint)//�� ���� ������� ���� �����ϸ��� ���� �����ʹ� ���� �ȵ�
	//{
	//	value = 0;
	//	printf("vecint=%d\n", value);
	//}
	//for (int& value : vecint)//���۷��� ���� ������� ���� �����ϸ� ���� �����͵� �����
	//{
	//	value = 1;
	//	printf("Ref vecint=%d\n", value);
	//}
	//for (const int& value : vecint)//���۷��� ������ const ������ �����ϸ� �� ���� �Ұ���
	//{
	//	//value = 0; <<-const�� �����Ͽ��� ������ ���� �߻�
	//	printf("vecint=%d\n", value);
	//}

	std::vector<int> vecint{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int>::iterator veciter = vecint.begin();
	//veclter++; ���������� ���� �迭�� ��ġ�� ����Ű�ڴ�.
	//veclter+=2; ���������� 2�� �̵��� �迭�� ��ġ�� ����Ű�ڴ�.
	//veclter--; �������� ��ĭ �̵�
	//vecint.end(); �迭�� �����ٴ� �ǹ�. ������ �迭�� �ҷ����°� �ƴ�.

	//vecint.push_back(100);
	//for (std::vector<int>::iterator iter = vecint.begin(); iter != vecint.end(); ++iter)
	//{
	//	printf("iter= %d\n", *iter);
	//}

	//vecint.pop_back();
	//veciter = vecint.begin();
	//while (veciter != vecint.end())
	//{
	//	printf("while iter= %d\n", *veciter);
	//	veciter++;
	//}
	//printf("while size= %d\n", int(vecint.size()));

	//veciter = vecint.begin();
	//while (veciter != vecint.end())
	//{
	//	if (*veciter == 5)
	//	{
	//		veciter = vecint.erase(veciter);//veciter�� ����Ű�� �ִ� �迭 ��Ҹ� �����Ѵ�.
	//	}
	//	else
	//	{
	//		veciter++;
	//	}
	//}
	//veciter = vecint.begin();
	//while (veciter != vecint.end())
	//{
	//	printf("while iter= %d\n", *veciter);
	//	veciter++;
	//}

/*2.����Ʈ(list)
����Ʈ�� ��ҵ��� ����� ���Ḯ��Ʈ�� ���·� �����Ѵ�.(Doubly linked List)
����Ʈ ��ü�� ��Ŀ�� �Ҹ��� ������ 2���� �����ϴµ� �̴� head�� tail�� ����Ŵ
���ο� ��ҵ��� �����ϱ� ���ؼ��� �� ������(��Ŀ)�� �����Ѵ�.
����Ʈ�� ���� ����([])�� �������� �ʴ´�.(n���� ��ҿ� �����ϱ� ���ؼ� ������ ���ľ� �ϱ� ����)
Ư�� ��ġ�� �߰�/������ �����Ӵ�.(Ư�� ��ġ�� ã�� �ð��� ����)
���Ҵ� ������ ����. �������� �޸𸮰� �ƴϱ� ������(�޸𸮰� �����Ǵ� ��) ������ �߰� ����

����
������ ��ġ�� ��Ҹ� �߰��ϴ� ���� �����Ӵ�(Ư�� ��ġ�� ã�� �ð��� ����) ���� ���⿡ �ſ찭�ϴ�.

����
���������� �Ұ����ϱ� ������ ���� Ž���Ͽ� ��ġ�� ã�´�.
���Ұ��� ������ ���� �߰����� �޸𸮸� �Ҹ��Ѵ�.(���� ����� ������ �޸�)*/

	//std::list<int> :����Ʈ�� ������ ������
	//listint: ������ ����Ʈ �̸�
	//{ 0, 1, 2, 3, 4 }: ����Ʈ�� �⺻��
	/*std::list<int> listint{ 0, 1, 2, 3, 4 };

	for (int value : listint)
	{
		value = 0;
		printf("List Value=%d\n", value);
	}

	for (const int& value : listint)
	{
		printf("List Value=%d\n", value);
	}

	std::list<int>::iterator listiter = listint.begin();
	printf("List Value=%d\n", *listiter);

	for(std::list<int>::iterator iter=listint.begin(); iter != listint.end(); ++iter)
		{
			printf("For List Value=%d\n", *iter);
		}

	listiter = listint.begin();
	while (listiter != listint.end())
	{
		printf("While List Value=%d\n", *listiter);
		listiter++;
	}*/

	std::list<int>listint{ 0, 8, 14, 96, 4 };
	listint.push_back(100);//����Ʈ�� ���ʿ� ���� �߰� �����Ѵ�.
	listint.push_front(100);//����Ʈ�� ���ʿ� ���� �߰� �����Ѵ�.
	
	listint.pop_back();//����Ʈ�� ���ʿ� ���� �����Ѵ�.
	listint.pop_front();//����Ʈ�� ���� ���� �����Ѵ�.

	for (const int& value : listint)
	{
		printf("List  Value=%d\n", value);
	}
	//����Ʈ���� Ư�� ���� ã��
	std::list<int>::iterator it = std::find(listint.begin(), listint.end(), 96);
	if (it != listint.end())
	{//ã������
		printf("Find List  Value=%d\n", *it);
		//listint.erase(it);����Ʈ �ȿ� Ư�� ���� �����ϱ�
		int value = 2023;
		//listint.insert(it, value);//Ư�� ��� ���ʿ� ���ο� ��� �����ֱ�
		//listint.emplace(it, 2024);//Ư�� ��� ���ʿ� ���ο� ��� �����ֱ�
	}

	else//�� ã������
	{
		printf("Find List Fail\n");
	}

	for (const int& value : listint)
	{
		printf( "List Value=%d\n", value);
	}
	//����ü �迭 find_if�� Ư�� ��� ã��
	std::list<stMonster>arrMon;
	for (int i = 0; i < 5; ++i)
	{
		stMonster temp;
		temp.index = i;
		arrMon.push_back(temp);
	}
	std::list<stMonster>::iterator moniter;
	//moniter = std::find_if(arrMon.begin(), arrMon.end(), isFindMonindex);
	moniter = std::find_if(arrMon.begin(), arrMon.end(),
		[](const stMonster& mon) {return mon.index == 3; });


	if (moniter != arrMon.end())
	{//ã����
		printf("find Monster index=%d\n", moniter->index);
	}
	else
	{//��ã��
		printf("moniter FInd fail\n");
	}

	for (const stMonster& value : arrMon)
	{
		printf("Monster index=%d\n", value.index);
	}

}