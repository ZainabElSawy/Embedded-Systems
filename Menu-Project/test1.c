#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "Std_Types.h"
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

int main()
{
    u8 admnORusr;
    label:
	//choose Admin mode or user mode
    printf("a. Admin mode.\nb. User mode.\n");scanf(" %c",&admnORusr);
    printf("-------------------------------\n-------------------------------\n");
   if(admnORusr=='a')
   {
        //Admin mode
        u8 Admin_Name[15];
		u32 Admin_ID;
        printf("Admin Name : ");scanf("%s",Admin_Name);
        printf("Admin ID : ");scanf("%d",&Admin_ID);

        //check the admin name and admin ID is correct or not
        if(((!strcmp(Admins[0].Name,Admin_Name))&&(Admin_ID==Admins[0].ID))||(!strcmp(Admins[1].Name,Admin_Name)&&(Admin_ID==Admins[1].ID)))
        {
            //Show menu
            printf("\t\t\t***All Items***\n\nItemNumber\tIntemName\tItemCount\tItemPrice\n\n1.Snacks\n________\n");
			//show snacks branch
            for(u32 i=0;i<7;i++)
            {
                if(i==1||i==5||i==6)
                {
                    printf("%d\t\t%s\t%d\t\t%0.2f\n",snacks[i].itemIndex,snacks[i].itemName,snacks[i].itemCount,snacks[i].itemPrice);
                    continue;
                }
                printf("%d\t\t%s\t\t%d\t\t%0.2f\n",snacks[i].itemIndex,snacks[i].itemName,snacks[i].itemCount,snacks[i].itemPrice);
            }
            printf("\n2.Hot Drinks\n____________\n");
			//show hot drinks branch
            for(u32 i=0;i<5;i++)
            {
                if(i!=2)
                {
                    printf("%d\t\t%s\t%d\t\t%0.2f\n",hotDrinks[i].itemIndex,hotDrinks[i].itemName,hotDrinks[i].itemCount,hotDrinks[i].itemPrice);
                    continue;
                }
                printf("%d\t\t%s\t\t%d\t\t%0.2f\n",hotDrinks[i].itemIndex,hotDrinks[i].itemName,hotDrinks[i].itemCount,hotDrinks[i].itemPrice);
            }
            printf("\n3.Cold Drinks\n____________\n");
			//show cold drinks branch
            for(u32 i=0;i<5;i++)
            {
                if(i!=1)
                {
                    printf("%d\t\t%s\t%d\t\t%0.2f\n",coldDrinks[i].itemIndex,coldDrinks[i].itemName,coldDrinks[i].itemCount,coldDrinks[i].itemPrice);
                    continue;
                }
                printf("%d\t\t%s\t\t%d\t\t%0.2f\n",coldDrinks[i].itemIndex,coldDrinks[i].itemName,coldDrinks[i].itemCount,coldDrinks[i].itemPrice);
            }
            u32 typeNum,itemNum,itemQntity;
			//Editing the quantity of items
            printf("\nInput the number of type you want to edit : ");scanf("%d",&typeNum);
            switch(typeNum)
            {
                case 1:
                    printf("Input the number of item  you want to edit it in Snacks branch and the Quantity: ");scanf("%d %d",&itemNum,&itemQntity);
                    snacks[itemNum-1].itemCount=itemQntity;
                    break;
                case 2:
                    printf("Input the number of item  you want to edit it in hot drinks branch and the Quantity: ");scanf("%d %d",&itemNum,&itemQntity);
                    hotDrinks[itemNum-1].itemCount=itemQntity;
                    break;
                case 3:
                    printf("Input the number of item  you want to edit it in cold drinks branch and the Quantity: ");scanf("%d %d",&itemNum,&itemQntity);
                    coldDrinks[itemNum-1].itemCount=itemQntity;
                    break;
            }
            goto label;
        }
        else
        {
            printf("\n**** May admin name or admin ID is incorrect ,please try again! ***\n\n");
            goto label;
        }
    }
    else if(admnORusr=='b')
    {
		//User mode
        u8 subOrgst;
		//choose subscriber or guest mode
        printf("a. Subscriber.\nb. Guest.\n");scanf(" %c",&subOrgst);
        printf("-------------------------------\n-------------------------------\n");
        if(subOrgst=='a')
        {
			//Subscriber mode
            u8 inputName[15];u32 inputID;
            printf("Input Subscriber name: ");scanf("%s",&inputName);
            printf("Input Subscriber ID: ");scanf("%d",&inputID);
			//chech if subscriber name and id is true or not
            if(!strcmp(Subscribers[0].Name,inputName)&&(Subscribers[0].ID==inputID))
            {
                user('S',Subscribers[0].subscriberCard);
            }
            else if(!strcmp(Subscribers[1].Name,inputName)&&(Subscribers[1].ID==inputID))
            {
                user('S',Subscribers[1].subscriberCard);
            }
            else if(!strcmp(Subscribers[2].Name,inputName)&&(Subscribers[2].ID==inputID))
            {
                user('S',Subscribers[2].subscriberCard);
            }
            else
            {
                printf("\nYou are not subscriber ,Please try again!\n\n");
                goto label;
            }
        }
        else if(subOrgst=='b')
        {
           user('G',0.0);
        }
    }
    return 0;
}

