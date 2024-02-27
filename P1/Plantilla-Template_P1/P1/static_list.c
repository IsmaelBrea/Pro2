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
    list->lastPos = LNULL; //inicializa la última posición como nula para indicar que la lista está vacía
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

    if(list->lastPos == MAX-1){    //si la lista está llena
        return false;              //devolvemos FALSE porque no se pueden añadir más elementos a la lista
    }else{                         //si no
        list->lastPos++;           //sumamos 1 a lastPos para indicar la nueva última posición de la lista
        if(pos  == LNULL){         //si la posición es NULL
            list->data[list->lastPos] = item; //añadimos nuestro elemento a la última posición de la lista
        }else{                                //si no
            for(i=list ->lastPos;i>=pos+1;i--){ //recorremos la lista desde el final hasta llegar a pos+1
                list->data[i]=list->data[i-1]; //cambiando el elemento actual por el anterior y al llegar a la posición deseada
            }
            list->data[pos]= item;        //insertamos el elemento item en la posición pos del array data
        }
        return true;       //devolvemos TRUE si hemos sido capaces de añadir el nuevo elemento
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
    return list.data[pos];   //devolvemos el elemento data que se corresponde con la posición pos del array data
    }


void updateItem (tItemL item, tPosL pos, tList *list){ //la lista se pasa por referencia
    list->data[pos]=item;
}


tPosL findItem (tUserName name, tList list){     //la lista se pasa por valor
    tPosL pos;
    if(list.lastPos==LNULL){   //si la lista está vacía devolvemos LNULL
        return LNULL;
    } else {    // Si la lista no está vacía, procedemos con la búsqueda
        // Recorremos la lista y buscamos el elemento con el nombre de usuario 'name'
        for (pos = 0; (pos <= list.lastPos) && (strcmp(list.data[pos].userName, name) != 0); pos++);

        if (strcmp(list.data[pos].userName, name) == 0) { // Si se encuentra un elemento cuyo nombre de usuario coincide con 'name', devolvemos su posición
            return pos;
        } else {    // Si no se encuentra ningún elemento con ese nombre de usuario, devolvemos LNULL
            return LNULL;
        }
    }
}
