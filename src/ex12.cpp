
#include <cstdio>

struct Fruit 
{
    const char *name;
    int price;
    int size;
};
void PrintFruits(Fruit fruits[], int countFruits) 
{
    for (int i = 0; i< countFruits; i++)
        printf("%s , %d , %d\n", fruits[i].name, fruits[i].price, fruits[i].size);
} 
int ChooseFruits(Fruit fruits[], int countFruits, int size)
{
    int maxIndex = -1; 
    for (maxIndex = 0; maxIndex < countFruits; ++maxIndex)
    {
        if(fruits[maxIndex].size <= size) 
            break;
    } 
    if (maxIndex == countFruits) 
    {
        return -1;
    }
    for(int i = maxIndex+1; i < countFruits; ++i)
    {
        if(fruits[maxIndex].price < fruits[i].price && fruits[maxIndex].size <= size)
            maxIndex = i;
    } 
    return maxIndex;
} 
void RemoveFruit(Fruit fruits[], int& countFruits, int idx)
{
    for (int i = idx; i < countFruits-1; ++i)
    {
        fruits[i] = fruits[i+1];
    } 
    --countFruits;
}
int main()
{ 

    Fruit fruit[4] = { {"배",2500, 5}, {"바나나", 1500, 3}, {"사과", 1500, 2}, {"딸기", 2000, 1} }; 

    int backpacksize = 6; 
    int countFruits = 4; 

    while(1)
    {
        int idx = ChooseFruits(fruit, countFruits, backpacksize);   
    
        if (idx >= 0 ) { 
            backpacksize -= fruit[idx].size;
            printf("%s , %d , %d\n", fruit[idx].name, fruit[idx].price, fruit[idx].size);
            RemoveFruit(fruit, countFruits , idx);
        } else {
            break;
        }
    }
    //PrintFruits(fruit, 4); 
    return 0;
}
//void refund(int moneyType[], int ch, int countMoneyType[])
//{
//    int change = ch;  
//    for (int i = 0; i < 5; i++)  
//    {
//        int count = 0; 
//        for (count = 0; change/moneyType[i]; ++count)
//            change -= moneyType[i];
//        countMoneyType[i] = count;
//    } 
//    for (int i =0; i < 5; i++)
//        printf("%d : %d\n", moneyType[i], countMoneyType[i]);
//   
//    int cmpChange = 0;
//    
//    for (int i =0; i < 5; i++)
//        cmpChange += moneyType[i] * countMoneyType[i];
//
//    printf("총액 : %d\n", cmpChange);
//}
//int main()
//{  
//
//    int moneyType[5] = { 500, 100, 50, 10 ,1 };
//    int countMoneyType[5] = {0};
//    int change = 670;  
//    printf("입력 : ");
//    scanf("%d", &change);
//    refund(moneyType, change, countMoneyType);
//    return 0;
//}