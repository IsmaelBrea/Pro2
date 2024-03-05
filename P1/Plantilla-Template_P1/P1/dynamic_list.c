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
    return (list == LNULL);   //devuelve TRUE si la lista no está vacía, FALSE en caso contrario
}

tPosL first(tList list) {      //la lista se pasa por valor
    return list;    //devuelve el primer elemento de la lista
}


tPosL last(tList list) {   //la lista se pasa por valor
    tPosL pos;   //creamos una variable de tipo tPosL

    for (pos = first(list);
         pos->next != LNULL; pos = pos->next); //bucle que recorre la lista desde el primer elemento hasta el último
    return pos; //devuelve el último elemento
}

tPosL next(tPosL pos, tList list) {   //la lista se pasa por valor
    return pos->next;
}

tPosL previous(tPosL pos, tList list) {  //la lista se pasa por valor
    tPosL q;
    if (pos == first(list)) {  //si p es el primer elemento de la lista
        return LNULL;     //devolvemos NULO
    } else {        //si no
        for (q = first(list); q->next != pos; q = next(q, list));  // recorremos la lista con la variable q, mientras q->next no apunta a p, pasamos al siguiente
            return q;                                   //cuando llegamos a la posición deseada, devolvemos q (elemento anterior a pos)
        }
    }


bool createNode(tPosL *p) {
    *p = malloc(sizeof(**p));    //reserva en un puntero p una dirección de memoria con tamaño suficiente para un tNode
    return *p != LNULL;
}


bool insertItem(tItemL item, tPosL pos, tList *list) {
    tPosL q, r;

    if (!createNode(&q)) { // Se verifica si se pudo crear un nuevo nodo
        return false; // Si no se pudo, se devuelve false
    }

    // asignamos los valores al nuevo nodo creado
    q->data = item;
    q->next = LNULL;

    if (*list == LNULL) {  // si la lista está vacía
        *list = q;  // el nuevo nodo se convierte en el primer elemento de la lista
    } else {
        if (pos == LNULL) {  // si la posición es nula, se inserta al final de la lista
            r = last(*list); // se inicializa r como el primer elemento de la lista
            r->next = q; // se añade el nuevo nodo al final de la lista
        } else {
            if (pos == *list) {  // si la posición es el primer elemento de la lista
                q->next = *list; // el nuevo nodo apunta al primer elemento actual
                *list = q; // el nuevo nodo se convierte en el primer elemento de la lista
            } else { // si no
                q->next = pos->next; // el nuevo nodo apunta al siguiente nodo del nodo en la posición pos
                pos->next = q; // el nodo en la posición pos apunta al nuevo nodo
                q->data = pos->data; // se copia el dato del nodo pos al nuevo nodo
                pos->data = item; // se actualiza el dato del nodo pos con el nuevo dato
            }
        }
    }
    return true; // Se devuelve true indicando que la inserción fue exitosa
}

void deleteAtPosition(tPosL pos, tList *list) {
    tPosL q = LNULL;

    if (pos == first(*list)) { //si pos es el primer elemento de la lista
        *list = (*list)->next; //cambiamos la lista por el siguiente nodo
    } else {
        if (pos->next == LNULL) { //si pos es el último elemento de la lista
            for (q = *list; q->next != pos; q = q->next); //recorremos la lista hasta el penúltimo nodo
            q->next = LNULL; //hacemos que el penúltimo nodo apunte a NULL
        } else { //si pos está en medio de la lista
            q = pos->next; //guardamos la dirección del siguiente nodo
            pos->data = q->data; //copiamos los datos del siguiente nodo en pos
            pos->next = q->next; //hacemos que pos apunte al nodo siguiente al siguiente nodo
            free(q); //liberamos el nodo siguiente
        }
    }
}


tItemL getItem(tPosL pos, tList list){
    return pos->data;   //devuelve el campo data situado en la pisición que se pasa como argumento
}


void updateItem(tItemL item, tPosL pos, tList *list) {
        pos->data = item; //cambia el campo data por el item pasado como argumento
    }

tPosL findItem(tUserName name, tList list) {
    tPosL p;  //creamos una variable p de tipo tPosL
    for (p = list; (p != LNULL) && (strcmp(p->data.userName, name) != 0); p = p->next);   //si la lista está vacía la
                                                                    //la recorremos con la variable q hasta que el campo
                                                                    // data coincida con el deseado
    return p;  //devolvemos la variable auxiliar p con la posición del elemento buscado
}

