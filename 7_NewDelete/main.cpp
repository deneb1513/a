#include<stdio.h>
#include<iostream>
//C++�� ������
//C++���� ����� �ۼ��� �ҽ��ڵ带 ��ǻ�Ͱ� ������ �ִ� �ڵ�� ��ȯ�Ͽ� ������ �� �ִ� ���Ϸ� ��ȯ�ϴ� ����
// 1. ��ó��(Preprocessing)�ܰ� : #include �� #define �� ���� ��ó���� ��ũ�ε��� ó���ϴ� �ܰ�
// 2. ������(Compile) �ܰ� : ������ �ҽ� ���ϵ��� ������� ���ɾ�� ��ȯ
// 3. �����(Assemble) �ܰ� : ������� �ڵ���� ���� ����� �̷���� ���� �ڵ�(Object file)�� ��ȯ�ϴ� �ܰ�
// 4. ��ŷ(Linking)�ܰ� : ������ ���� �ڵ���� �ѵ� ��Ƽ� �ϳ��� ���� ������ �����ϴ� �ܰ�

// �޸� ����
//1. code ���� : ������ �ڵ尡 ����Ǿ��ִ� ����(����� ����)
//2. Data ���� : ��������, Static �������� ����, ���μ����� ����ɶ� ���� �޸𸮿� �����
//3. Stack ����: ��������, �Ű��������� ����, �Լ��� ȣ��Ǹ� �����ǰ� �Լ��� ����Ǹ� �ý��ۿ� ��ȯ
//4. Heap ���� : malloc �Ǵ� new �Լ��� ���ؼ� �������� �Ҵ�Ǵ� ����, malloc()�Ǵ� new�����ڷ� �Ҵ�, free() �Ǵ� delete �����ڷ� ����

int main()
{
 /*���� �޸� �Ҵ�
 * �������� �޸𸮸� �Ҵ��ϸ� ������ �� Stack������ �Ҵ�Ǹ�, �Լ��� ���������� �Ҹ�ȴ�.
 * ���α׷� ������ �� Stack�� �󸶸�ŭ�� ũ��� �Ҵ��� �ؾ��ϴ��� �����Ǳ� ������, ������ ���� ũ�⺯�� �Ұ���
 * ���� ���� �迭 ����� ũ�⸦ ���������� �����ϸ� ������ �� �� �ִ�.
 */
	/*int a = 0;
	int arr[100];*/

 /*���� �޸� �Ҵ�
 * �������� �޸𸮸� �Ҵ��ϴ� ��� �����Ͱ� heap������ �Ҵ��� ��.
 * heap�� ���α׷��ӿ� ���� �Ҵ�(new), �Ҹ�(delete)�ȴ�.
 * ���α׷��Ӱ� ���� �� ���ϴ� ũ��� �Ҵ��� �� �ִ�.
 * ����: ������ ������ stack�� �Ҵ��.
 */
	//int* pM = (int*)malloc(4);//C���� ���� �Ҵ��ϴ� ���
	//free(pM);

	//new&delete
	//new �����ڷ� ������ �ݵ�� delete �����ڷ� ���� ���־�� �Ѵ�.
	//new �����ڷ� �迭 ������ delete[] �����ڷ� �迭���� ���� ���־�� �Ѵ�.

	//int* pA = new int(0);//C++���� ���� �Ҵ��ϴ� ����� �߰���.
	//int* pArr = new int[10];

	//delete pA;
	//delete[] pArr;

	int* pArr = new int[10] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	//int�ڷ���, ������ pArr���� new������ ���: ���� �Ҵ� �迭.�� �迭�� ������� �߰�ȣ�� �� ����
	for (int i = 0; i < 10; i++)//int i=0 ���� ����, i�� 10���� ������������ �ݺ�, i�� ����
	{
		printf("%d", pArr[i]);//i���� �����ϴ� �迭 ���� ���
	}
	delete[] pArr;//delete[]�� �迭���� ����


	// ���� ���� & ���� ����
	int* a;
	a = new int(10);
	int* b = new int(20);

	a = b;//���� ���� : a�� �ּҰ��� b�� �ּҰ��� �ִ´�. b�� ����Ű�� �ִ°� a�� ����Ű�� �Ѵ�.
	*a = *b;//���� ����: a�� ����Ű�� �ִ� ���� b�� ����Ű�� �ִ� ������ �����Ѵ�.

	delete a;
	delete b;



















}