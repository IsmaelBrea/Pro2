/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ISMAEL BREA ARIAS LOGIN 1: ismael.brea
 * AUTHOR 2: DIEGO ROMÁN POSE  LOGIN 2: diego.roman
 * GROUP: 4.3
 * DATE: ** / ** / **
 */

#include "song_list.h"
#include <string.h>

void createEmptyListS(tListS *listS){
    listS->lastPos = NULLS;  // Inicializamos la última posición como nula para indicar que la lista está vacía
}

bool isEmptyListS(tListS listS){
    return listS.lastPos == NULLS;  // Si la última posición de la lista es nula, la lista está vacía
}

tPosS firstS(tListS listS){
    return 0;  // La primera posición de la lista es 0
}

tPosS lastS(tListS listS){
    return listS.lastPos;  // Obtenemos la última posición de la lista con la variable lastPos definida en el TAD
}

tPosS nextS(tPosS pos, tListS listS) {
    if (pos == listS.lastPos) {
        return NULLS;  // Si la posición es el último elemento de la lista, devolvemos NULLS
    } else {
        return ++pos;  // Si no, devolvemos la siguiente posición
    }
}

tPosS previousS(tPosS pos, tListS listS) {
    if (pos == 0) {
        return NULLS;  // Si pos es el primer elemento, devolvemos NULLS
    } else {
        return pos - 1;  // Devolvemos la posición anterior
    }
}

bool insertItemS(tItemS item, tPosS pos, tListS *listS){
    tPosS i;

    if (listS->lastPos == MAX - 1) {  // Si la lista está llena, no se puede insertar el elemento
        return false;
    } else {
        listS->lastPos++;  // Sumamos 1 a lastPos para indicar la nueva última posición de la lista
        if (pos == NULLS) {  // Si la posición es nula, añadimos el elemento al final de la lista
            listS->data[listS->lastPos] = item;
        } else {
            for (i = listS->lastPos; i > pos; i--) {  // Recorremos la lista desde el final hasta llegar a pos
                listS->data[i] = listS->data[i - 1];  // Movemos los elementos hacia la derecha
            }
            listS->data[pos] = item;  // Insertamos el elemento en la posición indicada
        }
        return true;
    }
}

void deleteAtPositionS(tPosS pos, tListS *listS){
    tPosS i;

    for (i = pos; i < listS->lastPos; i++) {  // Recorremos la lista desde pos hasta el final
        listS->data[i] = listS->data[i + 1];  // Movemos los elementos hacia la izquierda
    }
    listS->lastPos--;  // Actualizamos lastPos al haber un elemento menos en la lista
}


tItemS getItemS(tPosS pos, tListS listS){
    return listS.data[pos];  // Devolvemos el elemento en la posición indicada
}

void updateItemS(tItemS item, tPosS pos, tListS *listS){
    listS->data[pos] = item;  // Actualizamos el elemento en la posición indicada
}

tPosS findItemS(tSongTitle song, tListS listS) {
    tPosS pos;

    if (isEmptyListS(listS)) {  // Si la lista está vacía, devolvemos NULLS
        return NULLS;
    }

    // Recorremos la lista y buscamos el elemento con el título de la canción 'song'
    for (pos = firstS(listS); pos != NULLS; pos = nextS(pos, listS)) {
        if (strcmp(listS.data[pos].songTitle, song) == 0) {
            // Si se encuentra un elemento cuyo título de canción coincide con 'song', devolvemos su posición
            return pos;
        }
    }
    // Si no se encuentra ningún elemento con ese título de canción, devolvemos NULLS
    return NULLS;
}