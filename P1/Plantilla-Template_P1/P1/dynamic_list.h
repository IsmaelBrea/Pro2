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

//Valor nulo de la lista
#define LNULL NULL

typedef int ItemL;
typedef struct tNode *tPosL;
struct tNode{
    tItemL data;
    tPosL next;
};
typedef tPosL *tList;


#endif
