#include "Std_Types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct info
{
    u8 Name[15];
    u32 ID;
    f32 subscriberCard;
};
struct items
{
    u8 itemIndex;
    u8 itemName[20];
    u32 itemCount;
    f32 itemPrice;
};
const struct info Admins[2]={{"ZainabHamdy",1000174501},{"RanaAshraf",1000149801}};
const struct info Subscribers[3]={{"HebaMohamed",155,510.75},{"NadaHossam",1234,200.0},{"MahaAshraf",2001,150.5}};
struct items snacks[7]={{1,"Molto",50,3.5},{2,"Biscuits",45,2},{3,"Cupcake",60,5},{4,"Rusk",100,1.75},{5,"yogurt",90,4.5},{6,"Dark chocolate",150,10},{7,"Potato Chips",70,5.5}};
struct items hotDrinks[5]={{1,"Fruit tea",160,6},{2,"Hot chocolate",100,7.5},{3,"Coffee",115,7},{4,"Hot lemon",120,5},{5,"Green tea",160,7}};
struct items coldDrinks[]={{1,"Lemonade",110,5},{2,"Ice Tea",90,10},{3,"Ice Coffee",140,9},{4,"Vegetable Juice",120,8},{5,"Fruit Juice",180,11}};
void user(u8 gOrs,f32 SubCard)
{
    u32 index,quantity;
    u8 yORn='Y',bl;
    f32 sum=0.0;
    printf("\t\t\t***Menu***\n\n1.Snacks\n________\nItemNumber\tIntemName\tItemPrice\n\n");
	//show snacks branch
    for(u32 i=0;i<7;i++)
    {
        if(i==1||i==5||i==6)
        {
            printf("%d\t\t%s\t%0.2f\n",snacks[i].itemIndex,snacks[i].itemName,snacks[i].itemPrice);
            continue;
        }
        printf("%d\t\t%s\t\t%0.2f\n",snacks[i].itemIndex,snacks[i].itemName,snacks[i].itemPrice);
    }
    while(yORn=='Y')
    {
        printf("\nInput index of item you want to buy and the quantity: ");scanf("%d %d",&index,&quantity);
        sum+=(snacks[index-1].itemPrice)*quantity;
        printf("=>Do you want more ?(Y/N): ");scanf(" %c",&yORn);
    }
    printf("\n=>Do you want? \na. Hot drink.\nb. Cold drink.\nc. Nothing else.\n");scanf(" %c",&bl);
    switch(bl)
    {
        case 'a':
            {
                printf("\n2.Hot Drinks\n____________\nItemNumber\tIntemName\tItemPrice\n\n");
                for(u32 i=0;i<5;i++)
                {
                    if(i!=2)
                    {
                        printf("%d\t\t%s\t%0.2f\n",hotDrinks[i].itemIndex,hotDrinks[i].itemName,hotDrinks[i].itemPrice);
                        continue;
                    }
                    printf("%d\t\t%s\t\t%0.2f\n",hotDrinks[i].itemIndex,hotDrinks[i].itemName,hotDrinks[i].itemPrice);
                }
                u8 YNflav,flav,YN='Y';
                while(YN=='Y')
                {
                    printf("\nInput index of item you want to buy and the quantity: ");scanf("%d %d",&index,&quantity);
                    sum+=(hotDrinks[index-1].itemPrice)*quantity;
                    printf("\n=>Do you want to add some flavors(Y/N): ");scanf(" %c",&YNflav);
                    if(YNflav=='Y')
                    {
                        printf("a. Mint \t: price =10.\nb. strawberry \t: price =15.\nc. Milk \t: price =20.\n");scanf(" %c",&flav);
                        switch(flav)
                        {
                            case 'a':sum+=10;break;
                            case 'b':sum+=15;break;
                            case 'c':sum+=20;break;
                        }
                    }
                    printf("=>Do you want more ?(Y/N)");scanf(" %c",&YN);
                }
            }
            goto label2;
            break;
        case 'b':
            {
                u8 YN='Y';
                printf("\n2.Cold Drinks\n____________\nItemNumber\tIntemName\tItemPrice\n\n");
                for(u32 i=0;i<5;i++)
                {
                    if(i!=1)
                    {
                        printf("%d\t\t%s\t%0.2f\n",coldDrinks[i].itemIndex,coldDrinks[i].itemName,coldDrinks[i].itemPrice);
                        continue;
                    }
                    printf("%d\t\t%s\t\t%0.2f\n",coldDrinks[i].itemIndex,coldDrinks[i].itemName,coldDrinks[i].itemPrice);
                }
                while(YN=='Y')
                {
                    printf("\nInput index of item you want to buy and the quantity: ");scanf("%d %d",&index,&quantity);
                    sum+=(coldDrinks[index-1].itemPrice)*quantity;
                    printf("=>Do you want more ?(Y/N):");scanf(" %c",&YN);
                }
            }
            goto label2;
            break;
        case 'c':
            label2:
            payMessage(gOrs,sum,SubCard);
    }
}
void payMessage (u8 gOrS,f32 sum,f32 SubCard)
{
	//if you want to pay cash or card
    printf("\n----------------------\n\n");
    if(gOrS=='G')printf("Thank you for coming here!\nYour purchase price is: %0.3f\nyou will pay it cash...!\n",sum);
    else if(gOrS=='S')
    {
        u8 cshORcrd;
        printf("You want to pay:\na. Cash.\nb. Card\n");scanf(" %c",&cshORcrd);
        if(cshORcrd=='a')printf("Thank you for coming here!\nYour purchase price is: %0.3f\nyou will pay it cash...!\n",sum);
        else if(cshORcrd=='b')
        {
            if(SubCard>=sum)
            printf("Thank you for coming here!\nMoney in Card is: %0.3f\nYour purchase price is: %0.3f\nRemaining Money in card is: %0.3f\n",SubCard,sum,SubCard-sum);
            else
            printf("Money in card is not enough!\nPlease pay cash!\nYour purchase price is: %0.3f\n");
        }
    }
    printf("\n----------------------\n");
}
