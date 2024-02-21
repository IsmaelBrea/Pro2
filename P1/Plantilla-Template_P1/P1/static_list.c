/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ISMAEL BREA ARIAS    LOGIN 1: ismael.brea
 * AUTHOR 2: DIEGO ROMÁN POSE     LOGIN 2: diego.roman
 * DATE: ** / ** / **
 */

#include "static_list.h"

/*  Write your code here */
#include <string.h>

void createEmptyList(tList *list){  //la lista se pasa por referencia
    list->lastPos = LNULL;
}

bool isEmptyList(tList list){    //la lista se pasa por valor
    return list.lastPos == LNULL;
}

tPosL first(tList list) {        //la lista se pasa por valor
    return 0;
}

tPosL last(tList list){           //la lista se pasa por valor
    return list.lastPos;
}

tPosL next(tPosL pos, tList list){  //la lista se pasa por valor
    if(pos == list.lastPos){
       return LNULL;
    }else{
        return ++pos;
    }
}

tPosL previous(tPosL pos, tList list){  //la lista se pasa por valor
    return --pos; /* no es necesario especificar que ocurre cuando p es el primer elemento de la lista,0, porque en este
                      *caso p-- sería igual a -1 que es nuestro LNULL */
}

void insertItem(tItemL item, tPosL pos, tList *list){  //la lista se pasa por referencia


}