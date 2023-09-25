#include<stdio.h>
#include "money.h"
#include"clacfunc.h"
//C++�� ������
//C++���� ����� �ۼ��� �ҽ��ڵ带 ��ǻ�Ͱ� ������ �ִ� �ڵ�� ��ȯ�Ͽ� ������ �� �ִ� ���Ϸ� ��ȯ�ϴ� ����
// 1. ��ó��(Preprocessing)�ܰ� : #include �� #define �� ���� ��ó���� ��ũ�ε��� ó���ϴ� �ܰ�
// 2. ������(Compile) �ܰ� : ������ �ҽ� ���ϵ��� ����� ��ɾ�� ��ȯ
// 3. �����(Assemble) �ܰ� : ����� �ڵ���� ���� ����� �̷���� ���� �ڵ�(Object file)�� ��ȯ�ϴ� �ܰ�
// 4. ��ŷ(Linking)�ܰ� : ������ ���� �ڵ���� �ѵ� ��Ƽ� �ϳ��� ���� ������ �����ϴ� �ܰ�

// �޸� ����
// code ���� : ������ �ڵ尡 ����Ǿ��ִ� ����(����� ����)
// Data ���� : ��������, Static �������� ����, ���μ����� ����ɶ� ���� �޸𸮿� �����
// Stack ����: ��������, �Ű��������� ����, �Լ��� ȣ��Ǹ� �����ǰ� �Լ��� ����Ǹ� �ý��ۿ� ��ȯ
// Heap ���� : malloc �Ǵ� new �Լ��� ���ؼ� �������� �Ҵ�Ǵ� ����, malloc()�Ǵ� new�����ڷ� �Ҵ�, free() �Ǵ� delete �����ڷ� ����

int g_money = 0;//��������

static int s_money = 0;

int aResult = 0;
int num1, num2;
float fnum1, fnum2;

int main()
{
	int t_money = 0;//��������
	addmoney(100);
	addmoney(100);
	addmoney(100);
	addmoney(100);
	addmoney(100);

    printf("main t_money=%d\n", t_money);
    printf("main g_money=%d\n", g_money);
  
    bool bRun = true;
    while (bRun)
    {
        int nlnput = 0;
        int num1, num2;

        printf("� ������ �Ͻðڽ��ϱ�?(0:���ϱ�, 1: ����, 2:���ϱ�, 3:������, 4:������)");
        scanf_s("%d", &aResult);

        switch (aResult)
        {
        case 0:
        {
            printf("���� 2���� �Է��Ͻÿ�(num1 num2):");
            scanf_s("%d %d", &num1, &num2);
            printf("�� ���� ���� %d�Դϴ�.\n", AddNum(num1, num2));
        }
        break;

        case 1:
        {
            printf("���� 2���� �Է��Ͻÿ�(num1 num2):");
            scanf_s("%d %d", &num1, &num2);
            printf("�� ���� ������ %d�Դϴ�.\n", MinusNum(num1, num2));
        }
        break;

        case 2:
        {
            printf("���� 2���� �Է��Ͻÿ�(num1 num2):");
            scanf_s("%d %d", &num1, &num2);
            printf("�� ���� ������ %d�Դϴ�.\n", MultiplyNum(num1, num2));
        }
        break;

        case 3:
        {
            printf("���� 2���� �Է��Ͻÿ�(num1 num2):");
            scanf_s("%f %f", &fnum1, &fnum2);
            printf("�� ���� �������� %f�Դϴ�.\n", DivideNum(fnum1, fnum2));
        }
        break;

        case 4:
        {
            printf("���� 2���� �Է��Ͻÿ�(num1 num2):");
            scanf_s("%d %d", &num1, &num2);
            printf("�� ���� �������� %d�Դϴ�.\n", RemainNum(num1, num2));
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