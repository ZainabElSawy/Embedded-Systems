#include "AdminMode.h"
void ADMIN()
{
    u32 Admin_Pass;
    u8 Admin_User[10],bo_ol=1;
    loop:
    //login to admin mode
    printf("===================\n\n");
    printf("Enter admin user : ");scanf("%s",&Admin_User);
    printf("Enter admin pass : ");scanf("%d",&Admin_Pass);
    printf("\n===================\n");
    admin* selected=AdminHead;
    if(AdminHead)
    {
        while(selected)
        {
            if(!strcmp(Admin_User,selected->user)&&Admin_Pass==selected->pass)
            {
                u8 input;
                mainLoop:
                printf("\t\t\t*** Admin Mode ***\n\t\t\t__________________\n");
                printf("=>Do want to\na. View all users data.\nb. View all books with all data.\nc. Edit user id.\nd. Search for a book.\ne. Make a reserved book available.\n");
                if(selected->MemberPer)
                    printf("f. Edit list of users.\n");
                if(selected->BookPer)
                    printf("g. Edit list of books.\n");
                if(selected->ReservationPer)
                    printf("h. Make a reservation of books.\n");
                printf("i. Logout\n");
                scanf(" %c",&input);
                if(input=='a')//View all users data.
                {
                    printf("\n===================\n");
                    ViewUsersData();
                    if(AgainOrExit()==1)goto mainLoop;
                }
                else if (input=='b')//View all books with all data.
                {
                    printf("\n===================\n");
                    ViewBooksData(1);
                    if(AgainOrExit()==1)goto mainLoop;
                }
                else if (input=='c')//Edit user id.
                {
                    printf("\n===================\n");
                    EditUserId();
                    if(AgainOrExit()==1)goto mainLoop;
                }
                else if (input=='d')//Search for a book.
                {
                    printf("\n===================\n");
                    SearchBook();
                    if(AgainOrExit()==1)goto mainLoop;
                }
                else if (input=='e')//Make a reserved book available.
                {
                    printf("\n===================\n");
                    u8 Id;
                    u8 YorN=1;
                    u8 ExistOrNo=1;
                    book* search=BookHead;
                    if(BookHead)
                    {
                        printf("Enter Id of book you want to make it available : ");scanf("%d",&Id);
                        while(search)
                        {
                            if(Id==search->Id)
                            {
                                if(search->AvailableOrNot==0)
                                {
                                    search->AvailableOrNot=1;
                                    YorN=0;
                                    printf("\n... The book is available now ...\n");
                                }
                                ExistOrNo=0;
                            }
                            search=search->Next;
                        }
                        if(YorN)
                        {
                            printf("\t\t\t__________________________________\n");
                            printf("\t\t\tThis book is already available..!");
                            printf("\n\t\t\t________________________________");
                        }
                        if(ExistOrNo)
                        {
                            printf("\t\t\t__________________________________\n");
                            printf("\t\t\tThis Id is not exist..!");
                            printf("\n\t\t\t________________________________");
                        }
                    }
                    else
                    {
                        printf("\t\t\t________________________________\n");
                        printf("\t\t\tThere is no books in library..!");
                        printf("\n\t\t\t______________________________");
                    }
                    if(AgainOrExit()==1)goto mainLoop;
                }
                else if (input=='f'&&(selected->MemberPer))//Edit list of users.
                {
                    u8 input1;
                    printf("  =>Do you want to\n  a. Add User.\n  b. Delete User.\n");scanf(" %c",&input1);
                    printf("\n===================\n");
                    switch(input1)
                    {
                        case 'a':
                            AddUser();
                            break;
                        case 'b':
                            DeleteUser();
                            break;
                        default:
                            printf("\t\t\t___________________________\n");
                            printf("\t\t\tThis answer is not exist..!");
                            printf("\n\t\t\t___________________________");
                            break;
                    }
                    if(AgainOrExit()==1)goto mainLoop;
                }
                else if (input=='g'&&(selected->BookPer))//Edit list of books.
                {
                    u8 input1;
                    printf("  =>Do you want to\n  a. Add Book.\n  b. Delete Book.\n");scanf(" %c",&input1);
                    printf("\n===================\n");
                    switch(input1)
                    {
                        case 'a':
                            AddBook();
                            break;
                        case 'b':
                            DeleteBook();
                            break;
                        default:
                            printf("\t\t\t___________________________\n");
                            printf("\t\t\tThis answer is not exist..!");
                            printf("\n\t\t\t___________________________");
                            break;
                    }
                    if(AgainOrExit()==1)goto mainLoop;
                }
                else if (input=='h'&&(selected->ReservationPer))//Make a reservation of books.
                {
                    printf("\n===================\n");
                    Make_A_Reservation();
                    printf("\n... All requests have been replaied...! ");
                    printf("\n===================\n");
                    if(AgainOrExit()==1)goto mainLoop;
                }
                else if (input=='i')//Logout.
                {
                    u8 charIn;
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
                            printf("\t\t\tThis answer is not exist..!");
                            printf("\n\t\t\t___________________________");
                            goto Again;
                            break;
                    }
                    printf("\n===================\n");
                }
                else//if answer is not exist.
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
        printf("\t\t\tThere is no admins..!");
        printf("\n\t\t\t_____________________\n");
        if(AgainOrExit()==1)goto loop;
    }

}
//View all data about user
void ViewUsersData()
{
    user* Selected=UserHead;
    book* searchReq;
    book* searchBor;
    if(UserHead)
    {
        printf("\t\tShow List of Users\n\nName\t\tId\t\tRequested books\t\tBorrowed Books\n");
        while(Selected)
        {
            printf("%s\t\t%d\t\t",Selected->Name,Selected->Id);

            for(u8 counter=0;counter<2;counter++)
            {
                if(Selected->RequestedBooks[counter]!=0)
                {
                    printf("(R)");
                    searchReq =BookHead;
                    while(searchReq)
                    {
                        if(searchReq->Id==Selected->RequestedBooks[counter])printf("%s, ",searchReq->Name);
                        searchReq=searchReq->Next;
                    }
                }
            }

            for(u8 counter=0;counter<2;counter++)
            {

                if(Selected->BorrowedBooks[counter]!=0)
                {
                    printf("(B)");
                    searchBor =BookHead;
                    while(searchBor)
                    {
                        if(searchBor->Id==Selected->BorrowedBooks[counter])printf("%s, ",searchBor->Name);
                        searchBor=searchBor->Next;
                    }
                }
            }
            printf("\n");
            Selected=Selected->Next;
        }
    }
    else
    {
        printf("\n\t\t\t____________________\n");
        printf("\t\t\tThe list is empty...!");
        printf("\n\t\t\t____________________\n");
    }
}
//View all data about books
void ViewBooksData(u8 Case)
{
    book* Selected=BookHead;
    if(BookHead)
    {
        if(Case==1)printf("\t\tList of books\n\nId. Book Name\t\tBook Author\t\tAvailable\t\t\tCost\n");
        else if(Case==2)printf("\t\tList of books\n\nId. Book Name\t\tBook Author\t\tCost\n");
        else if (Case==3)printf("\t\List of available books\n\nId. Book Name\t\tBook Author\n");
        while(Selected)
        {
            if(Case==1)printf("%d. %s\t\t%s\t\t%d\t\t%0.2f\n",Selected->Id,Selected->Name,Selected->Author,Selected->AvailableOrNot,Selected->Cost);
            else if(Case==2)
            {
                if(Selected->AvailableOrNot==1)printf("%d. %s\t\t%s\t\t%0.2f\n",Selected->Id,Selected->Name,Selected->Author,Selected->Cost);
            }
            else if(Case==3)
            {
                if(Selected->AvailableOrNot==1)printf("%d. %s\t\t%s\n",Selected->Id,Selected->Name,Selected->Author);
            }
            CLEAROUT;
            Selected=Selected->Next;
        }
    }
    else
    {
        printf("\n\t\t\t____________________\n");
        printf("\t\t\tThe list is empty...!");
        printf("\n\t\t\t____________________\n");
    }
}
//Edit User Id
void EditUserId()
{
    u8 InputUser[20],bo_ol=1;
    printf("Enter User you want to edit his id : ");scanf("%s",&InputUser);
    user* selected=UserHead;
    if(UserHead)
    {
        while(selected)
        {
            if(!strcmp(InputUser,selected->Name))
            {
                printf("Enter new Id : ");scanf("%d",&selected->Id);
                bo_ol=0;
            }
            selected=selected->Next;
        }
        bo_ol?printf("\t\t\tThis user is not exist..!\n"):printf("...Edited successfully...\n");
    }
    else
    {
        printf("\n\t\t\t__________________________________\n");
        printf("\t\t\tThere is no user to edit his id...!");
        printf("\n\t\t\t__________________________________\n");
    }
}
//Add new user to the list
void AddUser()
{
    user* pNew;
    user* pCheck;
    loop:
    printf("\t\tAdd User\n");
    if(UserHead==NULL)
    {
        pNew=(user* )malloc(sizeof(user));
        UserHead=pNew;
    }
    else
    {
        pCheck=UserHead;
        while(pCheck->Next!=NULL)
            pCheck=pCheck->Next;
        pNew=(user* )malloc(sizeof(user));
        pCheck->Next=pNew;
    }

    printf("Enter user name : ");scanf("%s",pNew->Name);
    printf("Enter user Id : ");scanf("%d",&pNew->Id);
    printf("Enter user pass : ");scanf("%d",&pNew->pass);
    for(u8 count=0;count<2;count++)pNew->RequestedBooks[count]=0;
    for(u8 count=0;count<2;count++)pNew->BorrowedBooks[count]=0;
    for(u8 count=0;count<2;count++)pNew->status[count]=0;
    //Check if user Id or user name is entered before
    pNew->Next=NULL;
    pCheck=UserHead;
    while(pCheck->Next!=NULL)
    {
        if(!strcmp(pNew->Name,pCheck->Name)||pNew->Id==pCheck->Id)
        {
            printf("\n\t\t\t________________________________________\n");
            printf("\t\t\tThis user name or Id is entered before..!");
            printf("\n\t\t\t________________________________________\n");
            free(pNew);
            goto loop;
        }
        pCheck=pCheck->Next;
    }
    printf("\n...Addded successfully...\n");
}
//Delete user from the list
void DeleteUser()
{
    printf("\t\tDelete User\n");
    u8 bo_ol=1;
    u32 IdUser;
    if(AdminHead)
    {
        printf("Enter Id of user you want to delete : ");scanf("%d",&IdUser);
        user* Selected=UserHead;
        user* Previous=NULL;
        while(Selected)
        {
            if(Selected->Id==IdUser)
            {
                if(Previous)
                    Previous->Next=Selected->Next;
                else
                    UserHead=Selected->Next;
                free(Selected);
                bo_ol=0;
            }
            Previous=Selected;
            Selected=Selected->Next;
        }

        bo_ol?printf("\nthis Id is not exist...!"):printf("\n...Deleted successfully...\n");
    }
    else printf("*There is no user to delete..!\n");

}
//Check if book is entered before or nod
u8 EnteredBefore(book*Head,u8 ID)
{
     book *newId =Head ;
     while(newId)
     {
        if(newId->Id == ID)
        {
             printf("\n\t\t\t______________________________\n");
             printf("\t\t\tthis id is entered befor ....! ");
             printf("\n\t\t\t______________________________\n");
             return 1;
        }
        newId =newId->Next;
    }
     return 0;
}
//Add new book to library
void AddBook()
{
    book* pNew;
    book* pCheck;
    u8 ID;
    printf("\t\tAdd Book\n");
    while(1)
    {
        printf("Enter Book Id : ");scanf("%d",&ID);
        CLEARIN;
        if(EnteredBefore(BookHead,ID)==0)break;
    }
    if(BookHead==NULL)
    {
        pNew=(book* )malloc(sizeof(book));
        BookHead=pNew;
    }
    else
    {
        pCheck=BookHead;
        while(pCheck->Next!=NULL)
            pCheck=pCheck->Next;
        pNew=(book* )malloc(sizeof(book));
        pCheck->Next=pNew;
    }
    pNew->Id=ID;
    printf("Enter Book name : ");gets(pNew->Name);
    CLEARIN;
    printf("Enter Book author : ");gets(pNew->Author);
    CLEARIN;
    printf("Enter Book cost : ");scanf("%f",&pNew->Cost);
    pNew->AvailableOrNot=1;
    pNew->Next=NULL;
    printf("\n...Addded successfully...\n");

}
//Delete a book from the library
void DeleteBook()
{
    printf("\t\tDelete Book\n");
    u8 bo_ol=1;
    u8 Id;
    if(BookHead)
    {
        printf("Enter Id of book you want to delete : ");scanf("%d",&Id);
        user* Selected=BookHead;
        user* Previous=NULL;
        while(Selected)
        {
            if(Selected->Id==Id);
            {
                if(Previous)
                    Previous->Next=Selected->Next;
                else
                    BookHead=Selected->Next;
                free(Selected);
                bo_ol=0;
            }
            Previous=Selected;
            Selected=Selected->Next;
        }

        bo_ol?printf("\nthis book is not exist...!\n"):printf("\n...Deleted successfully...\n");
    }
    else printf("There is no book to delete..!\n");

}
//search for a book.
void SearchBook()
{
    while(1)
    {
        u8 charIn;
        book* search=BookHead;
        printf("  =>Do you want to search use.\n  a. Book Name.\n  b. Book ID.\n  c. Book Author.\n");scanf(" %c",&charIn);
        if(charIn=='a')//search with name
        {
            u8 Name[50];
            printf("Enter book name : ");
            CLEARIN;
            gets(Name);
            u8 bo_ol=1;
            while(search)
            {
                if(!strcmp(Name,search->Name))
                {
                    printf("%d. %s\t\t%s\t\t%d\n",search->Id,search->Name,search->Author,search->AvailableOrNot);
                    bo_ol=0;
                }
                search=search->Next;
            }
            if(bo_ol)
            {
                printf("\n\t\t\t_____________________________\n");
                printf("\t\t\tThis book is not exist ....! ");
                printf("\n\t\t\t_____________________________\n");
            }
        }
        else if(charIn=='b')//search with book id
        {
            u8 bo_ol=1;
            u8 Id;
            printf("Enter book Id : ");
            CLEARIN;scanf("%d",&Id);
            while(search)
            {
                if(Id==search->Id)
                {
                    printf("%d. %s\t\t%s\t\t%d\n",search->Id,search->Name,search->Author,search->AvailableOrNot);
                    bo_ol=0;
                }
                search=search->Next;
            }
            if(bo_ol)
            {
                printf("\n\t\t\t_________________________________\n");
                printf("\t\t\tThere is no book with this id ....! ");
                printf("\n\t\t\t_________________________________\n");
            }
        }
        else if(charIn=='c')//search with author name
        {
            u8 author[50];
            printf("Enter book author : ");
            CLEARIN;
            gets(author);
            u8 bo_ol=1;
            while(search)
            {
                if(!strcmp(author,search->Author))
                {
                    printf("%d. %s\t\t%s\t\t%d\n",search->Id,search->Name,search->Author,search->AvailableOrNot);
                    bo_ol=0;
                }
                search=search->Next;
            }
            if(bo_ol)
            {
                printf("\n\t\t\t__________________________________\n");
                printf("\t\t\tThis author has no book here ....! ");
                printf("\n\t\t\t__________________________________\n");
            }
        }
        else
        {
            printf("\t\t\t_____________________________\n");
            printf("\t\t\tThis answer is not exist..!");
            printf("\n\t\t\t___________________________");
            continue;
        }
        break;
    }
}
void Make_A_Reservation()
{
    user* search=UserHead;
    while(search)
    {
        for(u8 counter=0;counter<2;counter++)
        {
            if(search->RequestedBooks[counter])
            {
                u8 sum_borrowed=0;
                for(u8 counter2=0;counter2<2;counter2++)
                {
                    if(search->BorrowedBooks[counter2])sum_borrowed++;
                }
                book* selected=BookHead;
                while(selected)
                {
                    if(search->RequestedBooks[counter]==selected->Id)
                    {
                        if(selected->AvailableOrNot==1&&sum_borrowed<2)
                        {
                            search->status[counter]=3;//3 mean approved
                            printf("User Name: %s\nUser requested Book %d : %s\nRequest status %d : "
                                   ,search->Name,counter+1,selected->Name,counter+1);
                        }
                        else
                        {

                            search->status[counter]=1;//1 means denied
                            printf("User Name: %s\nUser requested Book %d : %s\nRequest status %d : "
                            ,search->Name,counter+1,selected->Name,counter+1);

                        }
                        search->RequestedBooks[counter]=0;
                        if(search->status[counter]==1)printf("Denied\n");
                        else if(search->status[counter]==2)printf("Waiting\n");
                        else if(search->status[counter]==3)
                        {

                            printf("Approved\n");
                            search->BorrowedBooks[counter]=selected->Id;
                            selected->AvailableOrNot=0;
                        }
                        printf("\n===================\n");
                    }
                    selected=selected->Next;
                }
            }
        }
        search=search->Next;
    }
}
