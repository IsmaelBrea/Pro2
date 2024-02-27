/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ISMAEL BREA ARIAS    LOGIN 1: ismael.brea
 * AUTHOR 2: DIEGO ROMÁN POSE     LOGIN 2: diego.roman
 * DATE: ** / ** / **
 */

#include "dynamic_list.h"

void createEmptyList(tList *list){   //la lista se pasa por referencia
    *list = LNULL; //inicializamos el contenido de la lista a LNULL
}

bool isEmptyList(tList list){    //la lista se pasa por valor
    return (*list == LNULL);   //devuelve true si la lista no está vacía, false en caso contrario
}

tPosL first(tList list){      //la lista se pasa por valor
    return *list;    //devuelve el primer elemento de la lista
}


tPosL last(tList list){   //la lista se pasa por valor
    tPosL pos;
    for(pos=first(list);pos->next!=LNULL;pos=pos->next); //bucle que recorre la lista desde el primer elemento hasta el último
    return pos; //devuelve dicho elemento
}

tPosL next(tPosL pos, tList list){   //la lista se pasa por valor
    return pos->next;
}
