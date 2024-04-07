/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ISMAEL BREA ARIAS LOGIN 1: ismael.brea
 * AUTHOR 2: DIEGO ROMÁN POSE  LOGIN 2: diego.roman
 * GROUP: 4.3
 * DATE: ** / ** / **
 */

#include "user_list.h"
#include "song_list.h"


void createEmptyListU(tListU *listU) {
    *listU = NULLU;  // Inicialización de la lista vacía a nulo
}

bool isEmptyListU(tListU listU) {
    return listU = NULLU;  // True si está vacía, false en caso contrario
}

tPosU firstU(tListU listU){
    return listU;
}

tPosU lastU(tListU listU){
    tPosU q;
    for(q=listU;q->next!=NULLU;q=q->next);
    return q;
}

tPosU nextU(tPosU pos, tListU listU) {   //la lista se pasa por valor
    return pos->next;
}

tPosU previousU(tPosU pos, tListU listU) {  //la lista se pasa por valor
    tPosU q;
    if (pos == firstU(listU)) {  //si p es el primer elemento de la lista
        return NULLU;     //devolvemos NULO
    } else {        //si no
        for (q = firstU(listU); q->next != pos; q = nextU(q, listU));  //recorremos la lista con nuestra variable auxiliar q
        /*mientras q->next no apunta a pos, pasamos al siguiente
         * cuando llegamos a la posición deseada, devolvemos, que es
         *el elemento anterior a pos */
        return q;
    }
}


bool createNode(tPosU *p) {
    *p = malloc(sizeof(**p));    //reserva en un puntero p una dirección de memoria con tamaño suficiente para un tNode
    return *p != NULLU;
}


bool insertItemU(tItemU item, tListU *listU) {
    tPosU q, r, prev;

    if (!createNode(&q)) {
        return false;
    } else {
        q->data = item;
        q->next = NULLU;
        if (isEmptyListU(*listU)) {
            *listU = q;
        } else {
            r = *listU;
            prev = NULLU;
            while (r!= NULLU && strcmp(r->data.userName, item.userName) < 0) {
                prev = r;
                r = r->next;
            }
            if (prev == NULLU) {
                q->next = *listU;
                *listU = q;
            } else {
                prev->next = q;
                q->next = r;
            }
        }
        return true;
    }
}


void deleteAtPositionU(tPosU pos, tListU *listU) {
    tPosU q;

    if (pos == firstU(*listU)) {
        *listU = pos->next;
    } else if (pos->next == NULLU) {
        for (q = *listU; q->next != pos; q = q->next);
        q->next = NULLU;
    } else {
        q = previousU(pos, *listU);
        q->next = pos->next;
    }
    free(pos);
}



tItemU getItemU(tPosU pos, tListU listU){
    return pos->data;   //devuelve el campo data situado en la posición que se pasa como argumento
}


void updateItemU(tItemU item, tPosU pos, tListU *listU) {
    pos->data = item; //cambia el campo data por el item pasado como argumento
}

tPosU findItemU(tUserName name, tListU listU) {
    tPosU q;
    if(isEmptyListU(listU)) {
        return NULLU;
    } else {
        for(q = listU; q!= NULLU && strcmp(q->data.userName, name)!= 0; q = q->next);
        return q;
    }
}