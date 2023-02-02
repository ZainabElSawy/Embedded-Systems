#ifndef FILE_H_
#define FILE_H_
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

/*const struct info Admins[2]={{"ZainabHamdy",1000174501},{"RanaAshraf",1000149801}};
const struct info Subscribers[3]={{"HebaMohamed",155,510.75},{"NadaHossam",1234,200.0},{"MahaAshraf",2001,150.5}};
struct items snacks[7]={{1,"Molto",50,3.5},{2,"Biscuits",45,2},{3,"Cupcake",60,5},{4,"Rusk",100,1.75},{5,"yogurt",90,4.5},{6,"Dark chocolate",150,10},{7,"Potato Chips",70,5.5}};
struct items hotDrinks[5]={{1,"Fruit tea",160,6},{2,"Hot chocolate",100,7.5},{3,"Coffee",115,7},{4,"Hot lemon",120,5},{5,"Green tea",160,7}};
struct items coldDrinks[]={{1,"Lemonade",110,5},{2,"Ice Tea",90,10},{3,"Ice Coffee",140,9},{4,"Vegetable Juice",120,8},{5,"Fruit Juice",180,11}};*/

void payMessage (u8 gOrS,f32 Sum,f32 SubCard);
void user(u8 gOrs,f32 SubCard);
#endif