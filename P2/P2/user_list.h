/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ISMAEL BREA ARIAS LOGIN 1: ismael.brea
 * AUTHOR 2: DIEGO ROMÁN POSE  LOGIN 2: diego.roman
 * GROUP: 4.3
 * DATE: ** / ** / **
 */

#ifndef USER_LIST_H
#define USER_LIST_H

#include "types.h"
#include "song_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Valor nulo de la lista
#define NULLU NULL

//tipos de datos incluidos en el TAD UserList
typedef struct {
    tUserName userName;
    tPlayTime totalPlayTime;
    tUserCategory userCategory;
    tListS songList;
} tItemU;

typedef struct tUserNode {
    tItemU data;
    struct tUserNode *next;
} tUserNode;

typedef tUserNode *tPosU;
typedef tPosU *tListU;



////Prototipo de las funciones

void createEmptyListU(tListU *ListU);
/* createEmptyListU(tListU) -> tListU
   {Objetivo: crear una lista vacía e inicializarla
   Salida:
        tListU: una lista vacía
   PostCD: la lista sin datos}
*/

bool isEmptyListU(tListU listU);
/* isEmptyListU(tListU) -> Boolean
   {Objetivo: determina si la lista está vacía
   Entrada:
        tListU: lista a comprobar
   Salida:
        Boolean: true si la lista está vacía, false en caso contrario}
*/

tPosU firstU(tListU listS);
/* firstU(tListU) -> tPosU
   {Objetivo: devuelve la posición del primer elemento de la lista
   Entrada:
        tListU: lista a manipular
   Salida:
        tPosU: posición del primer elemento
    PreCD: la lista no está vacía
*/

tPosU lastU(tListU listU);
/* lastU(tListU) -> tPosU
   Objetivo: devuelve la posición del último elemento de la lista
   Entrada:
        tListU: lista a manipular
   Salida:
        tPosU: posición del último elemento
    PreCD: la lista no está vacía}
*/

tPosU nextU(tPosU pos, tListU listU);
/* nextU(tPosU,tListU) -> tPosU
   {Objetivo: devuelve la posición del elemento siguiente al actual
   Entrada:
        tPosU: posición del elemento actual
        tListU: lista a manipular
   Salida:
        tPosU: posición del elemento siguiente al actual
    PreCD: tPosU es una posición válida de la lista}
*/

tPosU previousU(tPosU pos, tListU listU);
/* previousU(tPosU,tListU) -> tPosU
   {Objetivo: devuelve la posición del elemento anterior al actual
   Entrada:
        tPosU: posición del elemento actual
        tListU: lista a manipular
   Salida:
        tPosU: posición del elemento anterior al actual
    PreCD: tPosU es una posición válida de la lista}
*/


bool insertItemU(tItemU item, tListU *listU);
/* insertItemU(tItemU, tListU) -> tListU, bool
    {Objetivo: inserta en la lista de forma ordenada en función del campo userName, un elemento con los datos indicados.
        Devuelve un valor true si el elemento fue insertado; false en caso contrario
    Entradas:
        -tItemU: contenido del elemento a insertar
        -tListU: lista en donde se va a insertar
    Salida:
        -tListU: lista con el elemento insertado, true en caso de que se haya insertado correctamente, false en caso contrario
    PostCD: las posiciones de los elementos de la lista posteriores a la del elemento insertado pueden haber variado}
*/

void deleteAtPositionU(tPosU pos, tListU *listU);
/* deleteAtPositionU(tPosU, tListU) -> tListU
   {Objetivo: elimina de la lista un elemento con cierta posición
   Entradas:
        -tPosU: posición del elemento a eliminar
        -tListU: lista a modificar
    Salida:
        -tList: lista sin el elemento correspondiente a tPosS
    PreCD: tPosU tiene qu ser una posición válida de la lista y el usuario en dicha posición tiene una lista de canciones
    vacía.
    PostCD: las posiciones de los elementos de la lista posteriores a la de la posición eliminada pueden haber variado}
*/

tItemU getItemU(tPosU pos, tListU listU);
/* getItemU(tPosU, tListU) -> tItemU
 {Objetivo: Devolver el contenido del elemento que ocupa la posición indicada.
 Entrada:
    tPosU: posición del elemento a obtener, tListU: lista
 Salida:
    tItemU: contenido de la posición indicada
 PreCD: La posición indicada es una posición válida en la lista}
 */

void updateItemU(tItemU item, tPosU pos, tListU *listU);
/* updateItemU(tItemU, tPosU, tListU) -> tListU
 {Objetivo: Modificar el contenido del elemento situado en la posición indicada.
 Entrada:
    -tItemU: contenido a modificar
    -tPosU: posición indicada para modificar el contenido
    -tListU: lista a modificar
 Salida:
    tListU: list
 PreCD: La posición indicada es una posición válida en la lista.}
 */


tPosU findItemU(tSongTitle song, tListU listU);
/* findItemU(tSongTitle, tListU) -> tPosU
 {Objetivo: Devolver la posición del primer elemento de la lista cuyo título de la canción se
 corresponda con el indicado (o null si no existe tal elemento).
 Entrada:
    tSongTitle: string
    tListU: lista
 Salida:
    tPosU: posición del elemento encontrado, si se encuentra}
*/

#endif
