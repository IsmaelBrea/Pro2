/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ISMAEL BREA ARIAS LOGIN 1: ismael.brea
 * AUTHOR 2: DIEGO ROMÁN POSE  LOGIN 2: diego.roman
 * GROUP: 4.3
 * DATE: ** / ** / **
 */

#ifndef SONG_LIST_H
#define SONG_LIST_H

#include "types.h"
#include <stdio.h>
#include <stdbool.h>

//Valor nulo de la lista
#define NULLS (-1)

//Valor máximo de la lista de canciones
#define MAX 25

//tipos de datos incluidos en el TAD SongList
typedef tSong tItemS;
typedef int tPosS;
typedef struct{
    tItemS data[MAX];
    tPosS lastPos;
}tListS;

////Prototipo de las funciones

void createEmptyListS(tListS *ListS);
/* createEmptyListS(tListS) -> tListS
   {Objetivo: crear una lista vacía e inicializarla
   Salida:
        tListS: una lista vacía
   PostCD: la lista sin datos}
*/


bool isEmptyListS(tListS listS);
/* isEmptyListS(tListS) -> Boolean
   {Objetivo: determina si la lista está vacía
   Entrada:
        tListS: lista a comprobar
   Salida:
        Boolean: true si la lista está vacía, false en caso contrario}
*/

tPosS firstS(tListS listS);
/* firstS(tListS) -> tPosS
   {Objetivo: devuelve la posición del primer elemento de la lista
   Entrada:
        tListS: lista a manipular
   Salida:
        tPosS: posición del primer elemento
    PreCD: la lista no está vacía
*/

tPosS lastS(tListS listS);
/* lastS(tListS) -> tPosS
   Objetivo: devuelve la posición del último elemento de la lista
   Entrada:
        tListS: lista a manipular
   Salida:
        tPosS: posición del último elemento
    PreCD: la lista no está vacía}
*/

tPosS nextS(tPosS pos, tListS listS);
/* nextS(tPosS,tListS) -> tPosS
   {Objetivo: devuelve la posición del elemento siguiente al actual
   Entrada:
        tPosS: posición del elemento actual
        tListS: lista a manipular
   Salida:
        tPosS: posición del elemento siguiente al actual
    PreCD: tPosS es una posición válida de la lista}
*/

tPosS previousS(tPosS pos, tListS listS);
/* previousS(tPosS,tListS) -> tPosS
   {Objetivo: devuelve la posición del elemento anterior al actual
   Entrada:
        tPosS: posición del elemento actual
        tListS: lista a manipular
   Salida:
        tPosS: posición del elemento anterior al actual
    PreCD: tPosS es una posición válida de la lista}
*/


bool insertItemS(tItemS item, tPosS pos, tListS *listS);
/* insertItemS(tItemS, tPosS, tListS) -> tListS, bool
    {Objetivo: si la posición es nula, añade el elemento al final de la lista. En caso contrario, el elemento
                quedará insertado justo antes del que actualemente ocupa la posición indicada
    Entradas:
        -tItemS: contenido del elemento a insertar
        -tPosS: posición del elemento a insertar
        -tListS: lista en donde se va a insertar
    Salida:
        -tListS: lista con el elemento insertado, true en caso de que se haya insertado correctamente, false en caso contrario
    PreCD: Position es una posición válida de la lista o es una posición nula
    PostCD: las posiciones de los elementos de la lista posteriores a la del elemento insertado pueden haber variado}
*/

void deleteAtPositionS(tPosS pos, tListS *listS);
/* deleteAtPositionS(tPosS, tListS) -> tListS
   {Objetivo: elimina de la lista un elemento con cierta posición
   Entradas:
        -tPosS: posición del elemento a eliminar
        -tListS: lista a modificar
    Salida:
        -tListS: lista sin el elemento correspondiente a tPosS
    PreCD: tPosS tiene qu ser una posición válida de la lista
    PostCD: las posiciones de los elementos de la lista posteriores a la de la posición eliminada pueden haber variado}
*/

tItemS getItemS(tPosS pos, tListS listS);
/* getItemS(tPosS, tListS) -> tItemS
 {Objetivo: Devolver el contenido del elemento que ocupa la posición indicada.
 Entrada:
    tPosLS: posición del elemento a obtener, tList: lista
 Salida:
    tItemS: contenido de la posición indicada
 PreCD: La posición indicada es una posición válida en la lista}
 */

void updateItemS(tItemS item, tPosS pos, tListS *listS);
/* updateItemS(tItemS, tPosS, tListS) -> tListS
 {Objetivo: Modificar el contenido del elemento situado en la posición indicada.
 Entrada:
    -tItemLS: contenido a modificar
    -tPosS: posición indicada para modificar el contenido
    -tListS: lista a modificar
 Salida:
    tListS: list
 PreCD: La posición indicada es una posición válida en la lista.}
 */


tPosS findItemS(tSongTitle song, tListS listS);
/* findItemS(tSongTitle, tListS) → tPosS
 {Objetivo: Devolver la posición del primer elemento de la lista cuyo título de la canción se
 corresponda con el indicado (o null si no existe tal elemento).
 Entrada:
    tSongTitle: string
    tListU: lista
 Salida:
    tPosL: posición del elemento encontrado, si se encuentra}
*/

#endif
