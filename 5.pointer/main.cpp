#include<stdio.h>
#include<iostream>

void BuyItem(int* Money, int price)
{
	//int*MoneyëŠ” ë©”ëª¨ë¦¬ ë³µì œê°€ ì¼ì–´ë‚˜ì§€ ì•ŠëŠ”ë‹¤.
	//ë©”ëª¨ë¦¬ì˜ íš¨ìœ¨ì ì¸ ê´€ë¦¬, ë°ì´í„° ì°¸ì¡°ê°€ í¸ë¦¬í•˜ë‹¤.
	*Money -= price;
}

enum ePhoneType
{
	iPhone = 0,
	Galaxys23,
    GalaxyFold,
    GalaxyZ
};

struct stPhoneShop
{
	int iPhoneCnt;
	int Galaxys23;
	int GalaxyFold;
	int GalaxyZ;

	void printfPhoneCnt()
	{
		printf("iPhone=%d, Galaxys23=%d, GalaxyFold=%d, GalaxyZ=%d\n", iPhoneCnt, Galaxys23, GalaxyFold, GalaxyZ);
	}
};

void BuyPhone(ePhoneType phoneType,stPhoneShop* pPs)
{
	switch (phoneType)
	{
	case ePhoneType::iPhone:
		pPs->iPhoneCnt--;//í¬ì¸íŠ¸ë¡œ ì°¸ì¡°í•˜ëŠ” êµ¬ì¡°ì²´ì— ë³€ìˆ˜ëŠ” "->"í‚¤ì›Œë“œë¡œ ì°¸ì¡°í•œë‹¤.
		break;
	case ePhoneType::Galaxys23:
		pPs->Galaxys23--;
		break;
	case ePhoneType::GalaxyFold:
		pPs->GalaxyFold--;
		break;
	case ePhoneType::GalaxyZ:
		pPs->GalaxyZ--;
		break;
	default:
		break;
	}
}
//number¸¦ ¹Ş¾Æ¼­ È­¸é¿¡ Ãâ·ÂÇÑ´Ù.
void printNumber(const int* number)
{   // number = nullptr;// Æ÷ÀÎÅÍ ÁÖ¼Ò °ªÀ» º¯°æÇÒ ¼ö ÀÖ´Ù.
	// *number =2;
	printf("pinrt number=%d\n", *number);
}

void printNumber2(const int& number)
{
	// number = nullptr;
	// *number =4;
	printf("pinrt number=%d\n", number);
} //À§ÀÇ printNumber´ë½Å ¸¹ÀÌ ¾²ÀÓ. º¸Åë ·¹ÆÛ·±½º ÂüÁ¶¶ó°í ÇÔ.

void printPhoneShop(const stPhoneShop* ps)
{
	printf("pinrt iPhoneCnt=%d\n", ps -> iPhoneCnt);
}

void printPhoneShop(const stPhoneShop& ps)
{
	printf("pinrt iPhoneCnt=%d\n", ps.iPhoneCnt);
}

int main()
{
	int a = 0; //4Byte
	int b = 0;
	//í¬ì¸í„°ë¥¼ ì‚¬ìš©í•˜ëŠ” ì´ìœ 
	// ë©”ëª¨ë¦¬ì— íš¨ìœ¨ì ì¸ ê´€ë¦¬, ë°ì´í„° ì°¸ì¡°ê°€ í¸ë¦¬í•˜ë‹¤.
	// int*pA: í¬ì¸í„° ë³€ìˆ˜ì˜ ì„ ì–¸(pAì— ë“¤ì–´ê°€ìˆëŠ” ì£¼ì†Œì— intí˜•ì˜ í¬ê¸°ë§Œí¼ ì°¸ì¡°í•œë‹¤.)
	// nullptr : í¬ì¸í„° ë³€ìˆ˜ì˜ ì´ˆê¸°í™” ê°’(ì£¼ì†Œê°’ì´ ë¹„ì–´ìˆìŒ)
	//ì´ì „ì—ëŠ” NULLì„ ì‚¬ìš©í–ˆëŠ”ë° Null=0ì„ ì˜ë¯¸ ê·¸ë˜ì„œ 0ì´ë‘ ì˜ë¯¸ê°€ ë™ì¼í•´ì„œ ë¬¸ì œ ë°œìƒ
	//ì£¼ì†Œê°’ì´ ë¹„ì–´ìˆìŒì´ë¼ëŠ” ëª…í™•í•œ ì˜ë¯¸ë¥¼ ê°€ì§„ Nullptrì‚¬ìš©
	//í¬ì¸í„°ì˜ í¬ê¸°(x32ì—ëŠ” 4Byte, x64ì—ëŠ” 8Byte)
	int* pA = nullptr;
	pA = &a;//aì£¼ì†Œê°’ì„ pAì— ë„£ëŠ”ë‹¤.
	// *:ë ˆí¼ëŸ°ìŠ¤ë¥¼ ì°¸ì¡°í•œë‹¤. (ì£¼ì†Œê°€ ê°€ë¥´í‚¤ê³  ìˆëŠ” ê°’ì„ ì°¸ì¡°í•¨.)
	b = *pA;//bì— pAê°€ ê°€ë¥´í‚¤ê³  ìˆëŠ” ì£¼ì†Œë ˆ ê°’ì„ ë„£ëŠ”ë‹¤.
	*pA = 10; //pAê°€ ê°€ë¥´í‚¤ê³  ìˆëŠ” ì£¼ì†Œì— ê°’ì„ 10ìœ¼ë¡œ ë³€ê²½í•œë‹¤.

	int num1 = 0;
	int num2 = 0;
	int* pNum = nullptr;
	pNum = &num1; //pNumì— num1ì˜ ì£¼ì†Œê°’ì„ ë„£ëŠ”ë‹¤.(pNumì€ num1ì„ ê°€ë¥´í‚¤ê³  ìˆëŠ” ìƒíƒœ)
	printf("pNum=%d\n", *pNum); //num1ê°’ 0
	*pNum = 20;   //pNumì´ ê°€ë¥´í‚¤ê³  ìˆëŠ” num1ì— 20ì„ ë„£ëŠ”ë‹¤.
	printf("pNum=%d\n", *pNum); //num1ê°’ 20
	pNum = &num2; //pNumì— num2ì˜ ì£¼ì†Œê°’ì„ ë„£ëŠ”ë‹¤.(pNumì€ num2ì„ ê°€ë¥´í‚¤ê³  ìˆëŠ” ìƒíƒœ)
	printf("pNum=%d\n", *pNum); //num2ê°’ 0
	*pNum = 30;	  //pNumì´ ê°€ë¥´í‚¤ê³  ìˆëŠ” num2ì— 30ì„ ë„£ëŠ”ë‹¤.
	printf("pNum=%d\n", *pNum); //num2ê°’ 30
	printf("%d, %d\n", num1, num2);

	//-----------------------------------------------------------------------------------//
	int Money = 10000;
	
	BuyItem(&Money, 1000);
	printf("MyMoney=%d\n", Money);

	stPhoneShop stPs;
	stPs.iPhoneCnt = 100;
	stPs.Galaxys23 = 100;
	stPs.GalaxyFold = 100;
	stPs.GalaxyZ = 100;

	BuyPhone(ePhoneType::Galaxys23, & stPs);
	stPs.printfPhoneCnt();

	//-----------------------------------------------------------------------------------//
	//ë°°ì—´ê³¼ í¬ì¸í„°

	int arrint[10] = { 0,10,20,30,40,50,60,70,80,90 };
	int* pint = nullptr;
	pint = arrint;
	printf("pint=%d\n", *pint);
	pint += 1;
	printf("pint=%d\n", *pint);

	short arrS[10] = { 0,10,20,30,40,50,60,70,80,90 };
	pint = (int*)arrS; //(int*)ë¥¼ ì‚¬ìš©í•´ì„œ int*ë¡œ ê°•ì œ í˜•ë³€í™˜(Cast)í•œë‹¤.
	pint += 1; //pintê°€ int*ì´ë¯€ë¡œ int(4Byte)ë§Œí¼ ë‹¤ìŒ ì£¼ì†Œê°’ì„ ì°¸ì¡°í•œë‹¤.
	short* pS = (short*)pint;//int(4BYte)ë§Œí¼ ì´ë™í•œ ì£¼ì†Œê°’ì€ Short(2Byte) 2ë²ˆ ì´ë™í•œ ê°’ >>>ë‚´ ë””ì½”ì„œë²„ ì°¸ì¡°
	printf("pS=%d\n", *pS);

	//x32 ì•„í‚¤í…ì³ = x86 ì•„í‚¤í…ì³
	//int32(4Byte) = 0~ 4,294,967,295(Byte) >>4Gì´ìƒì„ ì°¸ì¡°í•˜ì§€ ëª»í•˜ëŠ” ì—ëŸ¬ ë°œìƒ

	//ì•„ë˜ ë°°ì—´ì„ ë‚®ì€ ìˆ«ì ìˆœì„œëŒ€ë¡œ ì¶œë ¥
	int arr[10] = { 10,2,78,53,6,33,27,99,7,31 };


	printf("ì •ë ¬ ì „:");
	for (int i = 0; i < 10; i++)
	{
		if (i > 0) printf(",");
		printf("%d", arr[i]);
	}
	printf("\n");
	
	for (int i = 0; i < 10; i++)
	{
		int lowestindex = i;//ê°€ì¥ ë‚®ì€ indexì €ì¥

		for (int j = i + 1; j < 10; j++)
		{
			if (arr[lowestindex] > arr[j])
			{
				// lowestindexì™€ jë¥¼ ìˆœì„œëŒ€ë¡œ ë¹„êµ
				// j indexì— ê°’ì´ ë‚®ìœ¼ë©´ jëŠ” ìƒˆë¡œìš´  lowestindex
				lowestindex = j;
			}
		}
		//j forë¬¸ì´ ì¢…ë£Œë˜ë©´ lowestindexì—ëŠ” ê°€ì¥ ë‚®ì€ ìˆ˜ì˜ index ê°’ì´ ì €ì¥
		//i ëŠ” ìˆœì°¨ì ìœ¼ë¡œ ëŒë©´ì„œ ê°€ì¥ ë‚®ì€ ìˆ˜ê°€ ë“¤ì–´ê°€ì•¼ë¨
		// lowestindex ê°’ê³¼ i indexì— ê°’ì„ êµì²´í•œë‹¤.
		int temp = arr[i];
		arr[i] = arr[lowestindex];
		arr[lowestindex] = temp;
	}

	printf("ì •ë ¬ í›„:");
	for (int i = 0; i < 10; i++)
	{
		if (i > 0) printf(",");
		printf("%d", arr[i]);
	}
	printf("\n");

	// const »ó¼öÈ­
	// ½Ç¼ö¸¦ ÁÙÀÏ¼ö ÀÖ¾î¼­ µğ¹ö±ë È½¼ö¸¦ ÁÙÀÏ¼ö ÀÖ´Ù. µğ¹ö±ë: ¹ö±×¸¦ Ã£°Å³ª ¼öÁ¤ÇÏ´Â ¸ğµç ÇàÀ§
	const int cint = 100;//»ó¼ö

	int value = 0;
	int value2 = 0;
	int* pValue = &value;
	// const int* pValue = &value; // Æ÷ÀÎÅÍ°¡ °¡¸£Å°´Â ³»¿ë ¼öÁ¤ ºÒ°¡´É, Æ÷ÀÎÅÍ °ª ¼öÁ¤°¡´É, ÂüÁ¶ °¡´É
	// int const* pValue = &value; // Æ÷ÀÎÅÍ°¡ °¡¸£Å°´Â ³»¿ë ¼öÁ¤ ºÒ°¡´É, Æ÷ÀÎÅÍ °ª ¼öÁ¤°¡´É, ÂüÁ¶ °¡´É
	// int *const pValue = &value; // Æ÷ÀÎÅÍ°¡ °¡¸£Å°´Â ³»¿ë ¼öÁ¤ °¡´É, Æ÷ÀÎÅÍ °ª ¼öÁ¤ ºÒ°¡´É, ÂüÁ¶ °¡´É
	// const int *const pValue = &value; // Æ÷ÀÎÅÍ°¡ °¡¸£Å°´Â ³»¿ë ¼öÁ¤ ºÒ°¡´É, Æ÷ÀÎÅÍ °ª ¼öÁ¤ ºÒ°¡´É, ÂüÁ¶ °¡´É
	// int const *const pValue = &value; // Æ÷ÀÎÅÍ°¡ °¡¸£Å°´Â ³»¿ë ¼öÁ¤ ºÒ°¡´É, Æ÷ÀÎÅÍ °ª ¼öÁ¤ ºÒ°¡´É, ÂüÁ¶ °¡´É

	*pValue = 2;
	pValue = &value2;
	printf("pValue=%d\n", *pValue);
	
	printNumber(&value);

	printNumber2(value);




	return 0; 

}
