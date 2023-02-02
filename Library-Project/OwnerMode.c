#include "OwnerMode.h"
const u8 OwnerName [6]="Owner";
const u32 OwnerPass = 1234;
void OWNER()
{
    u8 InputName[10];
    u32 InputPass;
    loop:
    printf("===================\n\n");
    printf("Enter Name : ");scanf("%s",&InputName);
    printf("Enter Password : ");scanf("%d",&InputPass);
    if(!strcmp(OwnerName,InputName)&&(InputPass==OwnerPass))//if name and password is correct
    {
        u8 input1,input2;
        mainLoop:
        printf("\n===================\n");
        printf("\t\t\t*** Owner Mode ***\n\t\t\t__________________\n");
        printf("=>Do you Want to..\na. Edit the list of admins.\nb. Edit admins  permissions.\n");scanf(" %c",&input1);
        if(input1=='a')//if you want to edit the list of admins
        {
            loop2:
            printf("  =>Do you want..\n  a. Add admin.\n  b. Delete admin.\n  c. Show admins list.\n");scanf(" %c",&input2);
            printf("===================\n\n");
            switch(input2)
            {
                case 'a': //Add admin
                    AddAdmin();
                    printf("\n===================\n");
                    if(AgainOrExit()==1)goto mainLoop;
                    break;
                case 'b'://Delete admin
                    DeleteAdmin();
                    printf("\n===================\n");
                    if(AgainOrExit()==1)goto mainLoop;
                    break;
                case 'c'://show admins
                    ShowList();
                    printf("\n===================\n");
                    if(AgainOrExit()==1)goto mainLoop;
                    break;
                default://if answer is not correct
                    printf("\t\tWrong answer ..!\n");
                    if(AgainOrExit()==1)goto loop2;
            }

        }
        else if(input1=='b') //if you want to edit admins  permissions
        {
            u32 input3;
            loop5:
            printf("  =>Do you want to edit\n  a. Member permission.\n  b. book permission.\n  c. Reservation permission.\n");scanf(" %c",&input3);
            if(input3=='a')//if you want to edit member permission
            {
                u8 wrong_true=1,exit_try=0;
                Permissions(1,&wrong_true,&exit_try);
                if(exit_try)
                {
                    printf("\n\t\t\t________________________\n");
                    printf("\t\t\tThe list has no admins...!");
                    printf("\n\t\t\t_________________________\n");
                }
                else if(wrong_true)
                {
                    printf("\\t\t\t\n____________________________\n");
                    printf("\t\t\t\This password is not exist...!");
                    printf("\n\t\t\t\_____________________________\n");
                }
                else
                {
                    printf("\n===================\n");
                }
                if(AgainOrExit()==1)goto mainLoop;

            }
            else if(input3=='b')//if you want to edit book permission
            {
                u8 wrong_true=1,exit_try=0;
                Permissions(2,&wrong_true,&exit_try);
                if(exit_try)
                {
                    printf("\n\t\t\t_________________________\n");
                    printf("\t\t\tThe list has no admins...!");
                    printf("\n\t\t\t_________________________\n");
                }
                else if(wrong_true)
                {
                    printf("\\t\t\t\n_____________________________\n");
                    printf("\t\t\t\This password is not exist...!");
                    printf("\n\t\t\t\_____________________________\n");
                }
                else
                {
                    printf("\n===================\n");
                }
                if(AgainOrExit()==1)goto mainLoop;

            }
            else if(input3=='c')//if you want to edit reservation permission
            {
                u8 wrong_true=1,exit_try=0;
                Permissions(3,&wrong_true,&exit_try);
                if(exit_try)
                {
                    printf("\n\t\t\t________________________\n");
                    printf("\t\t\tThe list has no admins...!");
                    printf("\n\t\t\t_________________________\n");
                }
                else if(wrong_true)
                {
                    printf("\\t\t\t\n_____________________________\n");
                    printf("\t\t\t\This password is not exist...!");
                    printf("\n\t\t\t\_____________________________\n");
                }
                else
                {
                    printf("\n===================\n");
                }
                if(AgainOrExit()==1)goto mainLoop;
            }
            else //if answer is not correct
            {
                printf("\n\t\t\t___________________________\n");
                printf("\t\t\tThis answer is not exist ..!");
                printf("\n\t\t\t___________________________\n");
                if(AgainOrExit()==1)goto loop5;
            }
        }
        else //if answer is not correct
        {
            printf("\n\t\t\t___________________________\n");
            printf("\t\t\tThis answer is not exist ..!");
            printf("\n\t\t\t___________________________\n");
            if(AgainOrExit()==1)goto mainLoop;
        }
    }
    else //if not
    {
        printf("\n\t\t\t___________________________________\n");
        printf("\t\t\tMay name or password is incorrect..!");
        printf("\n\t\t\t___________________________________\n");
        if(AgainOrExit()==1)goto loop;
    }

}
int AgainOrExit()//choose if you want to go to first page or repeat or Exit
{
    u8 bo_ol;
    loop:
    printf("\n===================\n=>Do you Want to\na. Go to first page.\nb. Try again.\nc. Exit.\n");
    scanf(" %c",&bo_ol);
    printf("\n===================\n");
    switch(bo_ol)
    {
        case 'a':
            MainProcess();
            break;
        case 'b':
            return 1;//for repeat
            break;
        case 'c': //for exit
            return 0;
            break;
        default:
            printf("\n\t\t\t__________________________________________\n");
            printf("\t\t\tThis answer is not exist,please try again..!");
            printf("\n\t\t\t__________________________________________\n");
            goto loop;

    };
}
void AddAdmin()
{
    admin* pNew;
    admin* pCheck;
    loop:
    printf("\t\tAdd Admin\n");
    if(AdminHead==NULL)
    {
        pNew=(admin* )malloc(sizeof(admin));
        AdminHead=pNew;
    }
    else
    {
        pCheck=AdminHead;
        while(pCheck->Next!=NULL)
            pCheck=pCheck->Next;
        pNew=(admin* )malloc(sizeof(admin));
        pCheck->Next=pNew;
    }
    printf("Enter admin user : ");scanf("%s",pNew->user);
    printf("Enter admin pass : ");scanf("%d",&pNew->pass);
    pNew->BookPer=1;
    pNew->MemberPer=1;
    pNew->ReservationPer=1;

    pNew->Next=NULL;
    pCheck=AdminHead;
    while(pCheck->Next!=NULL)//check if admin name is entered before
    {
        if(!strcmp(pNew->user,pCheck->user))
        {
            printf("\n\t\t\t___________________________________\n");
            printf("\t\t\tThis admin user is entered before..!");
            printf("\n\t\t\t___________________________________\n");
            free(pNew);
            goto loop;
        }
        pCheck=pCheck->Next;
    }
    printf("\n...Addded successfully...\n");

}
void DeleteAdmin()
{
    printf("\t\tDelete Admin\n");
    u8 bo_ol=1;
    u8 AdminName[15];
    if(AdminHead)
    {
        printf("Enter admin user : ");scanf("%s",&AdminName);
        admin* Selected=AdminHead;
        admin* Previous=NULL;
        while(Selected)//search if name is exist in the list and if it exist delete it
        {
            if(!strcmp(Selected->user,AdminName))
            {
                if(Previous)
                    Previous->Next=Selected->Next;
                else
                    AdminHead=Selected->Next;
                free(Selected);
                bo_ol=0;
            }
            Previous=Selected;
            Selected=Selected->Next;
        }
        bo_ol?printf("\n*this Admin is not exist..!\n"):printf("\n...Deleted successfully...\n");
    }
    else printf("*There is no Admin to delete..!\n");

}
void ShowList()
{
    u8 counter=1;
    admin* Selected=AdminHead;
    if(AdminHead)
    {
        printf("\t\tShow List of Admins\nId.User  :  Pass\n");
        while(Selected)
        {
            printf("%d.%s : %d\n",counter,Selected->user,Selected->pass);
            counter++;
            Selected=Selected->Next;
        }
    }
    else printf("...The list is empty...\n");
}
void Permissions(u8 index,u8* wrong_true,u8* exit_try)
{
    loop:
    if(AdminHead)
    {
        u8 adminUser[20];
        u8 give_deny,bo_ol=1;
        printf("Enter User of admin you want to edit his permissions : ");scanf("%s",&adminUser);
        printf(" =>Do you want to\n a. Give.\n b. Deny.\n");scanf(" %c",&give_deny);
        if(give_deny=='a')
        {
            admin* selected=AdminHead;
            while(selected)
            {
                if(!strcmp(adminUser,selected->user))
                {
                    if(index==1)selected->MemberPer=1;
                    else if(index==2)selected->BookPer=1;
                    else if(index==3)selected->ReservationPer=1;
                    printf("\n...Given successfully...!\n");
                    *wrong_true=0;
                }
                selected=selected->Next;
            }

        }
        else if(give_deny=='b')
        {
            admin* selected=AdminHead;
            while(selected)
            {
                if(!strcmp(adminUser,selected->user))
                {
                    if(index==1)selected->MemberPer=0;
                    else if(index==2)selected->BookPer=0;
                    else if(index==3)selected->ReservationPer=0;
                    printf("\n...Denied successfully...!\n");
                    *wrong_true=0;
                }
                selected=selected->Next;
            }
        }
        else
        {
            printf("\n\t\t\t__________________________\n");
            printf("\t\t\tThis answer is not exist ..!");
            printf("\n\t\t\t__________________________\n");
            if(AgainOrExit()==1)goto loop;
        }

    }
    else
      *exit_try=1;
}

