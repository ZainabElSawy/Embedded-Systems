#ifndef OWNERMODE_H_INCLUDED
#define OWNERMODE_H_INCLUDED
#include "STD_TYPES.h"

void OWNER();
void AddAdmin();
void DeleteAdmin();
void ShowList();
void Permissions(u8 index,u8* wrong_true,u8* exit_try);
#endif // OWNERMODE_H_INCLUDED
