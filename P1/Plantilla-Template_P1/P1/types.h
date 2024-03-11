/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ISMAEL BREA ARIAS    LOGIN 1: ismael.brea
 * AUTHOR 2: DIEGO ROMÁN POSE     LOGIN 2: diego.roman
 * GROUP:4.3                       DATE: 10 / 03 / 2024
 */

#ifndef PRO2_2023_P1_TYPES_H
#define PRO2_2023_P1_TYPES_H


#define NAME_LENGTH_LIMIT 25
#include <stdbool.h>

typedef char tUserName[NAME_LENGTH_LIMIT];
typedef char tSongTitle[NAME_LENGTH_LIMIT];
typedef int tNumPlay;

typedef enum {basic, pro} tUserCategory;

typedef struct tItemL {
    tUserName userName;
    tNumPlay numPlay;
    tUserCategory userCategory;
} tItemL;

typedef struct tSong{
    tSongTitle songTitle;
} tSong;

#endif //PRO2_2023_P1_TYPES_H
