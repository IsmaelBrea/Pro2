/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ISMAEL BREA ARIAS    LOGIN 1: ismael.brea
 * AUTHOR 2: DIEGO ROMÁN POSE     LOGIN 2: diego.roman
 * DATE: ** / ** / **
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

//Valor nulo de la lista
#define LNULL NULL

typedef struct tNode *tPosL;
struct tNode {
    tItemL data;
    tPosL next;
};
typedef tPosL *tList;

////Prototipos de las funciones

/* createEmptyList (tList) -> tList
 {Objetivo: Crear una lista vacía.
 Salida:
    tList: una lista vacía
PostCD: La lista queda inicializada y no contiene elementos }
 */
void createEmptyList(tList *list);

/* isEmptyList (tList) -> bool
 {0bjetivo: Determinar si la lista está vacía.
 Entrada:
    tList: lista
 Salida:
    bool: true (1) si está vacía, false (0) si no lo está
 PreCD: La lista debe estar previamente inicializada}
 */
bool isEmptyList(tList list);

/* first (tList) -> tPosL
 {Objetivo: Devolver la posición del primer elemento de la lista.
 Entrada:
    tList: lista
 Salida:
    tPosL: posición de la lista
 PreCD: La lista no está vacía}
 */
tPosL first(tList list);

/* last (tList) -> tPosL
 {Objetivo: Devolver la posición del último elemento de la lista.
 Entrada:
    tList: lista
 Salida:
    tPosL: posición de la lista
 PreCD: La lista no está vacía}
 */
tPosL last(tList list);

/* next (tPosL, tList) -> tPosL
 {Objetivo: Devolver la posición en la lista del elemento siguiente al de la posición indicada
          (o LNULL si la posición no tiene siguiente).
 Entrada:
   tPosL: posición de la lista y tList: lista
 Salida:
    tPosL: posición de la lista
 PreCD: La posición indicada es una posición válida en la lista}
 */
tPosL next(tPosL pos, tList list);


/* previous (tPosL, tList) -> tPosL
 {Objetivo: Devolver la posición en la lista del elemento anterior al de la posición indicada
 (o LNULL si la posición no tiene anterior).
  Entrada:
   tPosL: posición de la lista y tList: lista
 Salida:
    tPosL: posición de la lista
 PreCD: La posición indicada es una posición válida en la lista}
 */
tPosL previous(tPosL pos, tList list);


/* insertItem (tItemL, tPosL, tList) -> tList, bool
 {Objetivo: Insertar un elemento en la lista antes de la posición indicada. Si la posición es LNULL,
 entonces se añade al final. Devuelve un valor true si el elemento fue insertado;
 false en caso contrario.
 Entrada:
    tItem: contenido a añadir, tPosL: posición a añadir el contenido, tList: lista
 Salida:
    tList: lista modificada con el nuevo elemento y true si se ha podido insertar y false en caso contrario
 PreCD: La posición indicada es una posición válida en la lista o bien nula (LNULL).
 PostCD: Las posiciones de los elementos de la lista posteriores a la del
          elemento insertado pueden haber variado}
*/

/*necesitamos crear una función auxiliar para poder usar insertItem
  *Esta función reservará en un puntero una dirección de memoria con tamaño suficiente para un tNode) */
bool createNode(tPosL *P);

bool insertItem(tItemL item, tPosL pos, tList *list);


/* deleteAtPosition (tPosL, tList) -> tList
 {Objetivo: Eliminar de la lista el elemento que ocupa la posición indicada.
 Entrada:
    tPosL: posición a eliminar, tList: lista
 Salida:
    tList: lista con el contenido de la posición indicada
 PreCD: La posición indicada es una posición válida en la lista.
 PostCD: Las posiciones de los elementos de la lista posteriores a la de la
        posición eliminada pueden haber variado}
 */
void deleteAtPosition(tPosL pos, tList *list);


/* getItem (tPosL, tList) -> tItemL
 {Objetivo: Devolver el contenido del elemento que ocupa la posición indicada.
 Entrada:
    tPosL: posición del elemento a obtener, tList: lista
 Salida:
    tItemL: contenido de la posición indicada
 PreCD: La posición indicada es una posición válida en la lista}
 */
tItemL getItem(tPosL pos, tList list);


/* updateItem (tItemL, tPosL, tList) -> tList
 {Objetivo: Modificar el contenido del elemento situado en la posición indicada.
 Entrada:
    tItemL: contenido a modificar, tPosL: posición indicada para modificar el contenido, tList: lista
 Salida:
    tList: list
 PreCD: La posición indicada es una posición válida en la lista.
 PostCD: El orden de los elementos de la lista no se ve modificado}
 */
void updateItem(tItemL item, tPosL pos, tList *list);


/* findItem (tUserName, tList) → tPosL
 {Objetivo: Devolver la posición del primer elemento de la lista cuyo nombre de usuario se
 corresponda con el indicado (o LNULL si no existe tal elemento).
 Entrada:
    tUserName: string,   tList: lista
 Salida:
    tPosL: posición
 PreCD: La lista debe estar previamente inicializada}
*/
tPosL findItem(tUserName name, tList list);


#endif



