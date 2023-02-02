#include "main.h"
//Add some exambles to books and users
void DATABASE()
{
    book Library[20]=
    {
        {1,"Hamlet","William Shakespeare",99.0},
        {2,"Richard II","William Shakespeare",65.75},
        {3,"As You Like It","William Shakespeare",45.5},
        {4,"King Lear","William Shakespeare",40.0},
        {5,"The Tempest","William Shakespeare",73.75},

        {6,"Ulysses","James Joyce",105.5},
        {7,"Finn's Hotel","James Joyce",110.5},
        {8,"Dubliners","James Joyce",35.5},
        {9,"Finnegans Wake","James Joyce",48.6},
        {10,"Chamber Music","James Joyce",80.75},
        {11,"Stephen Hero","James Joyce",91.0},

        {12,"Tomb of Sand","Geetanjali Shree’s",48.0},
        {13,"Between Two Worlds","Geetanjali Shree’s",23.5},

        {14,"War and Peace","Leo Tolstoy",67},
        {15,"The Great Gatsby","F. Scott Fitzgerald",84.5},
        {16,"Don Quixote","Miguel de Cervantes",33.75},
        {17,"Hear Yourself","Prem Rawat",47.0},
        {18,"Lal Salam","Smriti Irani",54.75},
        {19,"Queen of Fire","Devika Rangachari",42.0},
        {20,"When Breath Becomes Air","Paul Kalanithi",60.0},

    };
    user UserList[5]=
    {
        {"Zainab",105,7520,{0,0},{0,0}},
        {"Heba",212,2001,{0,0},{0,0}},
        {"Rana",010,1919,{0,0},{0,0}},
        {"Asmaa",300,2022,{0,0},{0,0}},
        {"Haidy",407,5951,{0,0},{0,0}},
    };
    for(u8 counter=0;counter<5;counter++)
    {
        user* pNew;
        user* pCheck;
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
        strcpy(pNew->Name,UserList[counter].Name);
        pNew->Id=UserList[counter].Id;
        pNew->pass=UserList[counter].pass;
        for(u8 count=0;count<2;count++)pNew->RequestedBooks[count]=UserList[counter].RequestedBooks[count];
        for(u8 count=0;count<2;count++)pNew->BorrowedBooks[count]=UserList[counter].BorrowedBooks[count];
        pNew->Next=NULL;
    }
    for(u8 counter=0;counter<20;counter++)
    {
        book* pNew;
        book* pCheck;
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
        pNew->Id=Library[counter].Id;
        strcpy(pNew->Name,Library[counter].Name);
        strcpy(pNew->Author,Library[counter].Author);
        pNew->Cost=Library[counter].Cost;
        pNew->AvailableOrNot=1;
        pNew->Next=NULL;
    }
}


