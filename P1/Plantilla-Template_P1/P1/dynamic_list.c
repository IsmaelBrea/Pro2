/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ISMAEL BREA ARIAS    LOGIN 1: ismael.brea
 * AUTHOR 2: DIEGO ROMÁN POSE     LOGIN 2: diego.roman
 * DATE: ** / ** / **
 */

#include "dynamic_list.h"

void createEmptyList(tList *list) {   //la lista se pasa por referencia
    *list = LNULL; //inicializamos el contenido de la lista a NULO
}

bool isEmptyList(tList list) {    //la lista se pasa por valor
    return (*list == LNULL);   //devuelve TRUE si la lista no está vacía, FALSE en caso contrario
}

tPosL first(tList list) {      //la lista se pasa por valor
    return *list;    //devuelve el primer elemento de la lista
}


tPosL last(tList list) {   //la lista se pasa por valor
    tPosL pos;   //creamos una variable de tipo tPosL

    for (pos = first(list); pos->next != LNULL; pos = pos->next); //bucle que recorre la lista desde el primer elemento hasta el último
    return pos; //devuelve el último elemento
}

tPosL next(tPosL pos, tList list) {   //la lista se pasa por valor
    return pos->next;
}

tPosL previous(tPosL pos, tList list) {  //la lista se pasa por valor
    tPosL q;
    if (pos == list) {  //si p es el primer elemento de la lista
        q = LNULL;
        return q;  //devuelve q como nulo
    } else {         //si no
        for (q = list; q->next != pos; q = q->next) {  /* recorremos la lista con la variable q, mientras q->next no apunta a p, pasamos al siguiente
                                                *cuando llegamos a la posición deseada, devolvemos q (elemento anterior a pos)*/
            return q;
        }
    }
}

bool createNode(tPosL *pos) {     //función auxiliar para hacer insertItem
    *pos = malloc(sizeof(struct tNode));
    return *pos != LNULL;
}

bool insertItem(tItemL item, tPosL pos, tList *list) {
    tPosL q, r;

    if (createNode(&q)) {
        return false;

    } else {
        q->data = item;
        q->next = LNULL;
    }

    if (*list == LNULL) {  //si la lista está vacía
        *list = q;      //se inserta como primer y único elemento
    } else if (pos == LNULL) {  //si la posición es nula insertamos el elemento al final
        for (r = *list; r->next != LNULL; r = r->next);
        r->next = q;
    } else if (pos == *list) {  //si queremos insertar pos como primer elemento de la lista
        q->next = pos;    //el campo next de q apuntará a p
        *list = q;        //igualamos q y la lista
    } else {
        q->next = pos->next;
        pos->next = q;
        q->data = pos->data;
        pos->data = item;
    }
    return true;  //devolvemos TRUE si se ha podido insertar correctamente el elemento
}


void deleteAtPosition(tPosL pos, tList *list) {
    tPosL q;

    if (pos == *list) { //si p es el primer elemento de la lista
        *list = pos->next; //cambiamos la lista por pos->next
    } else if (pos->next == LNULL) { //si pos es el último elemento de la lista
        for (q = *list; q->next != pos; q = q->next); //recorremos la lista mientras desde q=*list hasta q->next = p
        q->next = LNULL;   //igualamos q->next a NULO

    } else {
        q = pos->next; //si no igualamos q a p->next (apunta al elemento siguiente de p)
        pos->data = q->data;
        pos->next = q->next;
        pos = q;
    }
    free(pos); //liberamos p
}


tItemL getItem(tPosL pos, tList list) {
    return pos->data;   //devuelve el campo data situado en la posición que se pasa como argumento
}

void updateItem(tItemL item, tPosL pos, tList *list) {
    pos->data = item; //cambia el campo data por el item pasado como argumento
}


tPosL findItem(tUserName name, tList list) {
    tPosL p;  //creamos una variable p de tipo tPosL
    for (p = list; (p != LNULL) && (strcmp(p->data.userName, name) != 0); p = p->next);   /*si la lista está vacía la
 *                                                                la recorremos con la variable q hasta que el campo data
 *                                                                coincida con el deseado*/
    return p;  //devolvemos la variable auxiliar p con la posición del elemento buscado

}