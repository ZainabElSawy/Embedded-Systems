#ifndef STD_TYPES_H_INCLUDED
#define STD_TYPES_H_INCLUDED
#define CLEARIN ;fflush(stdin)
#define CLEAROUT fflush(stdout)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short int u16;
typedef signed short int s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;
typedef double f64;
typedef struct Admin
{
    u8 user[15];
    u8 MemberPer;
    u8 BookPer;
    u8  ReservationPer;
    u32 pass;
    struct Admin* Next;
}admin;
typedef struct User
{
    u8 Name[50];
    u32 Id;
    u32 pass;
    u32 RequestedBooks[2];
    u32 BorrowedBooks[2];
    u8 status[2];
    struct User* Next;
}user;
typedef struct Book
{
    u8 Id;
    u8 Name[25];
    u8 Author[25];
    f32 Cost;
    u8 AvailableOrNot;
    struct Book* Next;
}book;
typedef struct card
{
    u32 libraryCardID;
    u32 CardPass;
    f32 money;
}card;
extern admin* AdminHead;
extern user* UserHead;
extern book* BookHead;



int AgainOrExit();

void MainProcess();

int cmp (unsigned char *ptrConst,unsigned char *ptrInput);
#endif // STD_TYPES_H_INCLUDED
