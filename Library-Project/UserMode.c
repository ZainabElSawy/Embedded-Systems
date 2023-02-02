#include "UserMode.h"

//Accounts for library cards
card CardAcounts[5]=
{
    {10151,752,700},{20718,201,500},{10001,789,100},{23456,123,150},{1591,456,300}
};
void USER()
{
    u32 User_Pass;
    u8 User_Name[10],bo_ol=1;
    loop:
    printf("===================\n\n");
    CLEARIN;
    printf("Enter user name: ");scanf("%s",User_Name);
    printf("Enter user pass : ");scanf("%d",&User_Pass);
    printf("\n===================\n");
    user* selected=UserHead;
    if(UserHead)
    {

        while(selected)
        {
                if(!strcmp(User_Name,selected->Name)&&User_Pass==selected->pass)
                {
                    u8 input;
                    u8 charIn;
                    u32 libraryCardID=NULL;
                    u32 CardPass;
                    f32 sum=0;
                    mainLoop:
                    printf("\t\t\t*** User Mode ***\n\t\t\t__________________\n");
                    printf("=>Do want to\na. View the user data.\nb. Change user password.\nc. View all books.\nd. Search for a book.\ne. Make a request to borrow an available book.\nf. Buy an available book.\n");
                    printf("g. Request a new book to be provided in the future.\nh. Show current user borrow requests.\ni. Logout.\n");
                    scanf(" %c", &input);
                    if(input=='a')//View the user data
                    {
                        printf("\n===================\n");
                        printf("User name : %s\n",selected->Name);
                        printf("User Id : %d\n",selected->Id);
                        if(libraryCardID)printf("Library card id : %d\n",libraryCardID);

                        for(u8 counter=0;counter<2;counter++)
                        {
                            user* search=UserHead;
                            if(selected->BorrowedBooks[counter])
                            {
                                while(search)
                                {
                                    if(selected->BorrowedBooks[counter]==search->Id)printf("Borrow book %d : %s \n",counter,search->Name);
                                    search=search->Next;
                                }
                            }
                        }
                        if(AgainOrExit()==1)goto mainLoop;
                    }
                    else if(input=='b')//Change user password
                    {
                        printf("\n===================\n");
                        printf("Enter new password : ");
                        scanf("%d",&selected->pass);
                        printf("\n... Password is changed successfully ...\n");
                        goto loop;
                    }
                    else if(input=='c')//View all books.
                    {
                        printf("\n===================\n");
                        ViewBooksData(1);
                        if(AgainOrExit()==1)goto mainLoop;
                    }
                    else if(input=='d')//Search for a book.
                    {
                        SearchBook();
                        if(AgainOrExit()==1)goto mainLoop;
                    }
                    else if(input=='e')//Make a request to borrow an available book.
                    {
                        printf("\n===================\n");
                        ViewBooksData(3);
                        printf("\n===================\n");
                        for(u8 counter=0;counter<2;counter++)
                        {
                            if(selected->RequestedBooks[counter]==0)
                            {
                                CLEAROUT;
                                printf("Enter Book Id you want to request : ");
                                CLEARIN;
                                scanf("%d",&selected->RequestedBooks[counter]);
                                CLEAROUT;
                                printf("\n... Status is pending, Please wait ...!\n");
                                CLEAROUT;
                                selected->status[counter]=2;//2 means waiting
                                if(AgainOrExit()==1)goto mainLoop;
                            }
                        }
                        printf("\t\t\t_____________________________________________________________________________________\n");
                        printf("\t\t\tYou Can not Request more than 2, please wait for other requested to be replaied..!\n");
                        printf("\t\t\t_____________________________________________________________________________________");
                        if(AgainOrExit()==1)goto mainLoop;
                    }
                    else if(input=='f')// Buy an available book.
                    {


                        u8 charIn;
                        sum=0;
                        printf("\n===================\n");
                        ViewBooksData(2);
                        printf("\n===================\n");
                        u32 num;
                        printf("Enter the number of books you want to buy : ");
                        CLEARIN;
                        scanf("%d",&num);
                        u32 x=num;
                        for(u8 count=1;count<=x;count++)
                        {
                            u8 bookId=0;
                            book* search=BookHead;
                            printf("Enter Id of book %d : ",count);scanf("%d",&bookId);                            ;
                            while(search)
                            {
                                if(bookId==search->Id)
                                    sum+=(search->Cost);
                                search=search->Next;
                            }
                        }
                        printf("\nTotal Price : %0.2f\n",sum);
                        printf("=>Do you want to pay with\na. Cash.\nb. Library card.\n");scanf(" %c",&charIn);
                        if(charIn=='a')//if you want to pay with cash
                        {
                           printf("\n... Thank you for coming here, Please go to the cashier ...!\n");
                        }
                        else if(charIn=='b')//if you want to pay with library card
                        {
                           while(1)
                           {
                                //Login to Library card with one of accounts in line 6.
                                printf("Enter library card ID : ");scanf("%d",&libraryCardID);
                                printf("Enter card pass : ");scanf("%d",&CardPass);
                                if(CheckAcount(libraryCardID,CardPass)==0)
                                {
                                    printf("\n\t\t\t___________________________________\n");
                                    printf("\t\t\tMay user or passwore is incorrect..!");
                                    printf("\n\t\t\t____________________________________\n");
                                    continue;
                                }
                                break;
                            }
                            printf("\n===================\n");
                            printf("\nMoney in library card : %0.2f\n",CheckAcount(libraryCardID,CardPass));
                            if(CheckAcount(libraryCardID,CardPass)<sum)printf("\n... Money in card is no enough, please go to the cashier ...!\n\n");
                            else printf("... Payment completed successfully ...!\nRemaining money : %0.2f\n",CheckAcount(libraryCardID,CardPass)-sum);
                            printf("\n===================\n");

                        }
                        else
                        {
                            printf("\t\t\t____________________________\n");
                            printf("\t\t\tThis answer is not exist..!\n");
                            printf("\t\t\t____________________________");
                        }
                        if(AgainOrExit()==1)goto mainLoop;

                    }
                    else if(input=='g')//Request a new book to be provided in the future.
                    {
                        u8 book_name[30];
                        u8 outhar_name[30];
                        printf("\n===================\n");
                        printf("Enter book name : ");
                        CLEAROUT
                        CLEARIN;
                        gets(book_name);
                        printf("Enter author name :");
                        CLEAROUT
                        CLEARIN;
                        gets(outhar_name);
                        printf("\n\n... This book will be available soon ...!");
                        printf("\n===================\n");
                        if(AgainOrExit()==1)goto mainLoop;
                    }
                    else if(input=='h')//Show current user borrow requests.
                    {
                        u8 YorN=1;
                        printf("\n===================\n");
                        for(u8 counter=0;counter<2;counter++)
                        {
                            if(selected->status[counter]==2)
                            {
                                printf("The request %d status : Waiting\n",counter+1);
                                YorN=0;
                            }
                            else if(selected->status[counter]==3)
                            {
                                printf("The request %d status : Approved\n",counter+1);
                                YorN=0;
                            }
                            else if(selected->status[counter]==1)
                            {
                                printf("The request %d status : Denied\n",counter+1);
                                YorN=0;
                            }
                        }
                        if(YorN)printf("*there is no request ...!");
                        printf("\n===================\n");
                        if(AgainOrExit()==1)goto mainLoop;
                    }
                    else if(input=='i')//Logout or go to first page.
                    {
                        Again:
                        printf("  =>Do you want to\n  a. Go to the first page.\n  b.Exit.\n");scanf(" %c",&charIn);
                        switch(charIn)
                        {
                            case 'a':
                                MainProcess();
                                break;
                            case 'b':
                                return 0;
                                break;
                            default:
                                printf("\t\t\t___________________________\n");
                                printf("\t\t\tThis answer is not exist..!\n");
                                printf("\t\t\t___________________________");
                                goto Again;
                                break;
                        }
                        printf("\n===================\n");
                    }
                    else
                    {
                        printf("\t\t\t___________________________\n");
                        printf("\t\t\tThis answer is not exist..!");
                        printf("\n\t\t\t___________________________");
                        if(AgainOrExit()==1)goto mainLoop;
                    }

                    bo_ol=0;
                }
                selected=selected->Next;
            }
            if(bo_ol)
            {
                printf("\n\t\t\t___________________________________\n");
                printf("\t\t\tMay user or passwore is incorrect..!");
                printf("\n\t\t\t____________________________________\n");
                if(AgainOrExit()==1)goto loop;
            }
    }
    else
    {
        printf("\n\t\t\t_____________________\n");
        printf("\t\t\tThere is no users..!");
        printf("\n\t\t\t_____________________\n");
        if(AgainOrExit()==1)goto loop;
    }
}
f32 CheckAcount(u32 cardId,u32 cardPass)
{
    for(u32 counter=0;counter<5;counter++)
    {
        if(CardAcounts[counter].libraryCardID==cardId&&CardAcounts[counter].CardPass==cardPass)
        {
            return CardAcounts[counter].money;
        }
    }
    return 0;
}
