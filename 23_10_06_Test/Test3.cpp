#include<stdio.h>

float standardWeight(float height)
{
	return (height - 100) * 0.9;
}

float GetBMI(float weight, float standardWeight)
{
	return (weight - standardWeight) * 100 / standardWeight;
}
int main()
{
	int nInput = 0;
	bool bRun = true;
	float weight = 0;
	float height = 0;
	float sWeight = 0;
	float BMI = 0;
	while (bRun)
	{
		printf("BMI�� ����Ͻðڽ��ϱ�? 0)No 1)Yes\n");
		scanf_s("%d", & nInput);

		switch (nInput)
		{
		case 0:
		 {bRun = false; }
		 break;

	    case 1:
			printf("Ű�� �Է����ּ���\n");
			scanf_s("%f", &height);
			sWeight=standardWeight(height);
			printf("�����Ը� �Է����ּ���\n");
			scanf_s("%f", &weight);
			BMI = GetBMI(weight, sWeight);
			
			if (BMI > 20)
			{
				printf("��\n");
			}
			else if (10 < BMI && BMI <= 20)
			{
				printf("��ü��\n");
			}
			else if (BMI <= 10)
			{
				printf("����\n");
			}

		default:
			break;
		}
	}
}