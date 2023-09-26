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

//�����ε�
int Add(int a, int b) //������ ������ int. Add(1, 1)
{
    return a + b;
}

float Add(float a, float b) // �Ǽ��� f�� ���̸� �۵�. Add(1.5f, 1.2f)
{
    return a + b;
}

double Add(double a, double b)//�Ǽ��� ������ �۵�. Add(1.5, 1.2)
{
    return a + b;
}

struct fruitShop
{
    //����ü ���ο� ������ ������ ����ü�� ������� �ʴ� �̻� �Ȼ����.
    int appleA;
    int mangoA;
    int strawberryA;

    //����ü  ������ ":"�� ���� �����ʿ� ������ �ʱⰪ�� �����Ѵ�.
    fruitShop() : appleA(1000), mangoA(1000), strawberryA(1000)
    {

    }

    //����ü�� �Լ� ����
    void SetFruitValue(int apple, int mango, int strawberry)
    {
        int appleB = apple; //SetFrutvalue �Լ��� ����Ǹ� �����.
        appleA = apple;
        mangoA = mango;
        strawberryA = strawberry;
    }

    void printShopValue()
    {
        printf("���ϰ��� ���� ���:%d, ����:%d, ����:%d\n", appleA, mangoA, strawberryA);
    }

};
       // Struct PhoneShop
       // int iPhone;
       // int zFlip;
       // int GalaxyS23;
       // int GalaxyFold;
       // PhoneShop[0], iPhone=100, zFlip=90, GalaxyS23= 80, GalaxyFold=150
       // PhoneShop[1], iPhone = 110, zFlip = 100, GalaxyS23 = 90, GalaxyFold = 160
       // PhoneShop[2], iPhone = 90, zFlip = 80, GalaxyS23 = 70, GalaxyFold = 140
       // PhoneShop[0], PhoneShop[1],  PhoneShop[2]�� ������ ���

struct PhoneShop
{    
    int index;
    int iPhoneA;
    int zFlipA;
    int GalaxyS23A;
    int GalaxyFoldA;

    PhoneShop():index(0), iPhoneA(100), zFlipA(90), GalaxyS23A(80), GalaxyFoldA(150)
    {}

    void SetPhoneValue(int iPhone, int zFlip, int GalaxyS23, int GalaxyFold)
    {
        iPhoneA = iPhone;
        zFlipA = zFlip;
        GalaxyS23A = GalaxyS23;
        GalaxyFoldA = GalaxyFold;
    }

    void printPhoneValue()
    {
        printf("%d �븮�� �ڵ������� iPhoneA:%d, zFlipA:%d, GalaxyS23A:%d, GalaxyFoldA:%d\n", index, iPhoneA, zFlipA, GalaxyS23A, GalaxyFoldA);
    }


};


int main()
{
	//int t_money = 0;//��������
	//addmoney(100);
	//addmoney(100);
	//addmoney(100);
	//addmoney(100);
	//addmoney(100);

 //   printf("main t_money=%d\n", t_money);
 //   printf("main g_money=%d\n", g_money);
 // 
 //   bool bRun = true;
 //   while (bRun)
 //   {
 //       int nlnput = 0;
 //       int num1, num2;

 //       printf("� ������ �Ͻðڽ��ϱ�?(0:���ϱ�, 1: ����, 2:���ϱ�, 3:������, 4:������)");
 //       scanf_s("%d", &aResult);

 //       switch (aResult)
 //       {
 //       case 0:
 //       {
 //           printf("���� 2���� �Է��Ͻÿ�(num1 num2):");
 //           scanf_s("%d %d", &num1, &num2);
 //           printf("�� ���� ���� %d�Դϴ�.\n", AddNum(num1, num2));
 //       }
 //       break;

 //       case 1:
 //       {
 //           printf("���� 2���� �Է��Ͻÿ�(num1 num2):");
 //           scanf_s("%d %d", &num1, &num2);
 //           printf("�� ���� ������ %d�Դϴ�.\n", MinusNum(num1, num2));
 //       }
 //       break;

 //       case 2:
 //       {
 //           printf("���� 2���� �Է��Ͻÿ�(num1 num2):");
 //           scanf_s("%d %d", &num1, &num2);
 //           printf("�� ���� ������ %d�Դϴ�.\n", MultiplyNum(num1, num2));
 //       }
 //       break;

 //       case 3:
 //       {
 //           printf("���� 2���� �Է��Ͻÿ�(num1 num2):");
 //           scanf_s("%f %f", &fnum1, &fnum2);
 //           printf("�� ���� �������� %f�Դϴ�.\n", DivideNum(fnum1, fnum2));
 //       }
 //       break;

 //       case 4:
 //       {
 //           printf("���� 2���� �Է��Ͻÿ�(num1 num2):");
 //           scanf_s("%d %d", &num1, &num2);
 //           printf("�� ���� �������� %d�Դϴ�.\n", RemainNum(num1, num2));
 //       }
 //       break;

 //       default:
 //           break;
 //       }


 //       printf("���⸦ �����Ͻðڽ��ϱ�?(0:No, 1:Yes)");
 //       scanf_s("%d", &nlnput);

 //       switch (nlnput)
 //       {
 //       case 1:
 //           bRun = false;
 //           break;
 //       }
 //   }

    //�迭
        /*int arrint[10] = { 0 } ���� 0���� �ʱ�ȭ
        int arrint[10] = { 0, } ���� 0���� �ʱ�ȭ*/
        int arrint[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; //������ �迭�� �ʱⰪ �ִ� ���
        arrint[0] = 10; //0�� �迭�� ���ֱ�
        arrint[4] = 40; //4�� �迭�� ���ֱ�
        arrint[9] = 90; //9�� �迭�� ���ֱ�

        for (int i = 0; i < 10; i++)
        {
            printf("%d��° �迭 ���� %d �Դϴ�.\n", i, arrint[i]); //2�� �̻��� �Ķ��Ÿ ��� ���
        }

        int number = 0;
        for (int value : arrint)
        {
            printf("for each %d��° �迭 ���� %d�Դϴ�.\n", number, value);
            number++;
        }
        //Struct�� ���
        //fruitShop : ������
        //shop : ������ �̸�
        fruitShop shop[3];

        //Struct �Լ� ����
        shop[0].SetFruitValue(1000, 2000, 3000);
        shop[1].SetFruitValue(1100, 2100, 3100);
        shop[2].SetFruitValue(900, 1900, 2900);

        for (fruitShop stValue : shop)
        {
            stValue. printShopValue();
        }

        PhoneShop Shop[3];
        Shop[0].index = 0;
        Shop[0].SetPhoneValue(100, 90, 80, 150);
        Shop[1].index = 1;
        Shop[1].SetPhoneValue(110, 100, 90, 160);
        Shop[2].index = 2;
        Shop[2].SetPhoneValue(90, 80, 70, 140);
            
        for (PhoneShop PValue : Shop)
        {
            PValue.printPhoneValue();
        }
            

    return 0;
}
