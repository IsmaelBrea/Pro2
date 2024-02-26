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

bool insertItem(tItemL item, tPosL pos, tList *list){  //la lista se pasa por referencia
    tPosL i;

    if(list->lastPos == MAX-1){
        return false;
    }else{
        list->lastPos++;
        if(pos  == LNULL){
            list->data[list->lastPos] = item;
        }else{
            for(i=list ->lastPos;i>=pos+1;i--)
                list->data[i]=list->data[i-1];
            list->data[pos]= item;
        }
        return true;
    }
}

void deleteAtPosition (tPosL pos,tList *list){     //la lista se pasa por referencia
    tPosL i;

    list->lastPos--;       //actualizamos lastPos al haber un elemento menos en la lista
    for(i=pos;i<=list->lastPos;i++){   //recorremos la lista desde p hasta el final
        list->data[i] = list->data[i+1];  //cambiando el elemento actual por el siguiente eliminando p
    }
}


tItemL getItem(tPosL pos, tList list){//la lista se pasa por valor
    return list.data[pos];
    }


void updateItem (tItemL item, tPosL pos, tList *list){ //la lista se pasa por referencia
    list->data[pos]=item;
}


tPosL findItem (tUserName name, tList list){     //la lista se pasa por valor
    tPosL pos;
    if(list.lastPos==LNULL){
        return LNULL;
    }else{
        for(pos=0;(pos<=list.lastPos )&&(strcmp(list.data[pos].userName,name)!=0);pos++);
        if(strcmp(list.data[pos].userName,name)==0){
            return pos;
        }else{
            return LNULL;
        }
    }
}
