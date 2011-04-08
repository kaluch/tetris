
#include "../include/workspace.h"

workspace::workspace()
{
    Set_nb_col(10);
    Set_nb_lignes(20);
    Set_tableau();
}

workspace::~workspace()
{
    free_tableau();
}
