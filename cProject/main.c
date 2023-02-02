#include "main.h"
admin* AdminHead=NULL;
user* UserHead=NULL;
book* BookHead=NULL;
int main()
{
    DATABASE();//Data Base of library
    MainProcess();//Call Main function
}
void MainProcess()
{
    u8 chooseMode = 0;
    u8 bo_ol;
    loop:
    printf("\t\t\t*** Welcome ***\n\t\t\t_______________\n");
    printf("a. Owner Mode.\nb. Admin Mode.\nc. User Mode.\n");//Choose which mode you want
    scanf(" %c",&chooseMode);
    switch(chooseMode)
    {
        case 'a':
            OWNER();
            break;
        case 'b':
            ADMIN();
            break;
        case 'c':
            USER();
            break;
        default://in case you enter an incorrect answer
            {
                printf("\t\t\t___________________________\n");
                printf("\t\t\tThis answer is not exist..!");
                printf("\n\t\t\t___________________________");
                if(AgainOrExit()==1)goto loop;
            }
    }
}
