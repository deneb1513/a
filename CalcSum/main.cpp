#include<stdio.h>

int Sum(int a, int b)
{
	return a + b;
}

int Minus(int a, int b)
{
	return a - b;
}

int main()
{	
	bool bRun = true;
	while (bRun)
	{
		int nlnput = 0;
		int num1, num2;

		printf("� ������ �Ͻðڽ��ϱ�?(0:���ϱ�, 1: ����, 2:���ϱ�, 3:������, 4:������)");
		scanf_s("%d", &nlnput);

		switch (nlnput)
		{
		  case 0:
		  {
			printf("���� 2���� �Է��Ͻÿ�(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("�� ���� ���� %d�Դϴ�.\n", Sum(num1, num2));
		  }
		  break;
		  
		  case 1:
		  {
			printf("���� 2���� �Է��Ͻÿ�(num1 num2):");
			scanf_s("%d %d", &num1, &num2);
			printf("�� ���� ������ %d�Դϴ�.\n", Minus(num1, num2));
		  }
		  break;

		  default:
			  break;
		}

		
		printf("���⸦ �����Ͻðڽ��ϱ�?(0:No, 1:Yes)");
		scanf_s("%d", &nlnput);

		switch (nlnput)
		{
		case 1:
			bRun = false;
			break;
		}
	}

	return 0;
}