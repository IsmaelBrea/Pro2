/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ISMAEL BREA ARIAS LOGIN 1: ismael.brea
 * AUTHOR 2: DIEGO ROMÁN POSE  LOGIN 2: diego.roman
 * GROUP: 4.3
 * DATE: 22 / 04 / 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "user_list.h"

#define MAX_BUFFER 255

void New(tUserName newUserName, tUserCategory newUserCategory, tListU *userList);
/* Objetivo: alta de un usuario de categoría basic o pro
     * Entradas:
     *      newUserName: Nombre del nuevo usuario.
     *      newUserCategory: Categoría del nuevo usuario.
     *      list: Puntero a la lista de usuarios.
     * Salidas: lista de usuarios modificada
     * Precondiciones: -
     * Postcondiciones: Se incorpora un nuevo usuario a la lista de usuarios con la categoría indicada.
*/

void Delete(tUserName  newUserName, tListU *userList);
/* Objetivo: eliminar un usuario de la lista
     * Entradas: nombre de usuario a eliminar y lista de usuarios
     * Salidas: lista de usuarios
     * Precondiciones:-
     * Postcondiciones: cambia la lista (tiene un elemento menos, por lo que se modifican las posiciones)
     *
*/

void Add(tUserName newUserName, tSongTitle newSongTitle, tListU *userList);
/* Objetivo: añadir una canción a la lista de reproducción de un usuario
     * Entradas:
     *      userName: Nombre del usuario al que se añadirá la canción.
     *      songTitle: Título de la canción a agregar.
     *      userList: Puntero a la lista de usuarios.
     * Salidas: lista de usuarios modificada
     * Precondiciones: -
     * Postcondiciones: Se agrega la canción a la lista de reproducción del usuario indicado.
*/


void Upgrade(tUserName newUserName, tListU *userList);
/* Objetivo: actualizar un usuario de basic a pro
     * Entradas: nombre de usuario y lista de usuarios
     * Salidas: lista de usuarios
     * Precondiciones: -
     * Postcondiciones: -
     *
*/

void Play(tUserName newUserName, tSongTitle newSongTitle, tPlayTime newPlayTime, tListU *userList);
/* Objetivo: reproducir una canción por parte de un usuario, actualizando los contadores de reproducción
             tanto de la canción como del usuario.
     * Entradas: nombre de usuario, título de la canción, tiempo de reproducción y lista de usuarios
     * Salidas: lista de usuarios
     * Precondiciones: -
     * Postcondiciones: Se actualiza el tiempo de reproducción de la canción  y el tiempo total de
                        reproducción del usuario correspondiente en la lista de usuarios, si la reproducción es exitosa
     *
*/

void Stats(tListU *userList);
/* Objetivo: mostrar la lista de los usuarios actuales de MUSFIC y sus datos
    * Entradas: lista de usuarios
    * Salidas: lista de usuarios
    * Precondiciones: -
    * Postcondiciones: -
 */

void Remove(int maxTime, tListU *userList);
/* Objetivo: eliminar todos los usuarios basic cuyo contador de tiempo de reproduciccón exceda de maxTime minutos
    * Entradas: lista de usuarios y el tiempo máximo permitido para los usuarios básicos.
    * Salidas: lista de usuarios modificada.
    * Precondiciones: -
    * Postcondiciones: los usuarios que hayan exedido el tiempo máximo de reproducción quedan eliminados de la lista.
 */


tUserCategory char_to_category(char *string);


void processCommand(tListU *userList, char *commandNumber, char command, char *param1, char *param2, char *param3) {

    switch (command) {
        case 'N':
            printf("********************\n");
            printf("%s %c: user %s category %s\n", commandNumber, command, param1, param2);
            New(param1, char_to_category(param2),userList);
            break;
        case 'D':
            printf("********************\n");
            printf("%s %c: user %s\n",commandNumber, command,param1);
            Delete(param1, userList);
            break;
        case 'A':
            printf("********************\n");
            printf("%s %c: user %s song %s\n", commandNumber, command, param1, param2);
            Add(param1, param2, userList);
            break;
        case 'U':
            printf("********************\n");
            printf("%s %c: user %s\n",commandNumber, command,param1);
            Upgrade(param1,userList);
            break;
        case 'P':
            printf("********************\n");
            printf("%s %c: user %s song %s minutes %s\n",commandNumber, command,param1,param2,param3);
            Play(param1,param2,atoi(param3),userList);
            break;
        case 'S':
            printf("********************\n");
            printf("%s %c:\n",commandNumber, command);
            Stats(userList);
            break;
        case 'R':
            printf("********************\n");
            printf("%s %c: maxtime %s\n",commandNumber, command,param1);
            Remove(atoi(param1),userList);
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {

    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    //definimos la lista de usuarios
    tListU userList;
    //creamos e inicilizamos la lista de usuarios
    createEmptyListU(&userList);

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);

            processCommand(&userList,commandNumber, command[0], param1, param2, param3);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
#ifdef INPUT_FILE
        file_name = INPUT_FILE;
#endif
    }

    readTasks(file_name);

    return 0;
}

void New(tUserName newUserName, tUserCategory newUserCategory, tListU *userList) {
    // Verificar si el usuario ya existe en la lista
    if (findItemU(newUserName, *userList) != NULLU) {
        printf("+ Error: New not possible\n");
        return;
    }

    // Crear un nuevo nodo para el nuevo usuario
    tUserNode *newNode = (tUserNode *)malloc(sizeof(tUserNode));
    if (newNode == NULL) {
        // No se pudo asignar memoria para el nuevo nodo, imprimir un mensaje de error
        printf("+ Error: New not possible\n");
        return;
    }

    // Asignar los datos del nuevo usuario al nodo
    strcpy(newNode->data.userName, newUserName);
    newNode->data.userCategory = newUserCategory;
    newNode->data.totalPlayTime = 0; // Inicializar el tiempo total de reproducción a 0
    createEmptyListS(&(newNode->data.songList)); // Crear una lista de canciones vacía

    // Buscar la posición de inserción para mantener el orden alfabético
    tPosU prev = NULLU;
    tPosU curr = *userList;
    while (curr != NULLU && strcmp(curr->data.userName, newUserName) < 0) {
        prev = curr;
        curr = curr->next;
    }

    // Insertar el nuevo nodo en la posición adecuada
    newNode->next = curr;
    if (prev == NULLU) {
        // El nuevo nodo será el primer elemento de la lista
        *userList = newNode;
    } else {
        prev->next = newNode;
    }

    // Imprimir un mensaje de confirmación
    printf("* New: user %s category %s\n", newUserName, newUserCategory == basic ? "basic" : "pro");
}



void Add(tUserName newUserName, tSongTitle newSongTitle, tListU *userList) {
    // Buscar al usuario en la lista
    tPosU userPos = findItemU(newUserName, *userList);
    if (userPos == NULLU) {
        printf("+ Error: Add not possible\n");
        return;
    }

    // Obtener el usuario
    tItemU user = getItemU(userPos, *userList);

    // Verificar si la canción ya está en la lista de reproducción del usuario
    tPosS songPos = findItemS(newSongTitle, user.songList);
    if (songPos != NULLS) {
        // La canción ya está en la lista, imprimir un mensaje de error
        printf("+ Error: Add not possible\n");
        return;
    }

    // Inicializar valores de la nueva canción
    tItemS newSong;
    strcpy(newSong.songTitle, newSongTitle);
    newSong.playTime = 0;

    // Buscar la posición de inserción para mantener la lista ordenada alfabéticamente
    songPos = findItemS(newSongTitle, user.songList);

    // Insertar la nueva canción en la posición adecuada
    if (!insertItemS(newSong, songPos, &(user.songList))) {
        // Error al insertar la nueva canción, imprimir un mensaje de error
        printf("+ Error: Add not possible\n");
        return;
    }

    // Actualizar la lista de usuarios con el usuario modificado
    deleteAtPositionU(userPos, userList); // Eliminar el usuario actual de la lista
    insertItemU(user, userList); // Insertar el usuario actualizado en la lista

    // Imprimir un mensaje de confirmación
    printf("* Add: user %s adds song %s\n", newUserName, newSongTitle);
}


void Upgrade(tUserName newUserName, tListU *userList) {
    // Buscar al usuario en la lista
    tPosU userPos = findItemU(newUserName, *userList);
    if (userPos == NULLU) {
        printf("+ Error: Upgrade not possible\n");
        return;
    }

    // Obtener el usuario
    tItemU user = getItemU(userPos, *userList);

    // Verificar si el usuario ya es de categoría 'pro'
    if (user.userCategory == pro) {
        printf("+ Error: Upgrade not possible\n");
        return;
    }

    // Actualizar la categoría del usuario a 'pro'
    user.userCategory = pro;

    // Actualizar la lista de usuarios con el usuario modificado
    updateItemU(user, userPos, userList);

    // Imprimir un mensaje de confirmación
    printf("* Upgrade: user %s category pro\n", newUserName);
}


void Play(tUserName newUser, tSongTitle newSong, tPlayTime newPlayTime, tListU *userList) {
    // Buscar al usuario en la lista
    tPosU userPos = findItemU(newUser, *userList);
    if (userPos == NULLU) {
        printf("+ Error: Play not possible\n");
        return;
    }

    // Obtener el usuario
    tItemU user = getItemU(userPos, *userList);

    // Verificar si la canción está en la lista de reproducción del usuario
    tPosS songPos = findItemS(newSong, user.songList);
    if (songPos == NULLS) {
        // La canción no está en la lista, imprimir un mensaje de error
        printf("+ Error: Play not possible\n");
        return;
    }

    // Obtener la canción
    tItemS song = getItemS(songPos, user.songList);

    // Actualizar el tiempo de reproducción de la canción
    song.playTime += newPlayTime;

    // Actualizar la lista de canciones del usuario con la canción modificada
    updateItemS(song, songPos, &(user.songList));

    // Actualizar el tiempo total de reproducción del usuario
    user.totalPlayTime += newPlayTime;

    // Actualizar la lista de usuarios con el usuario modificado
    updateItemU(user, userPos, userList);

    // Imprimir un mensaje de confirmación
    printf("* Play: user %s plays song %s playtime %d totalplaytime %d\n", newUser, newSong, newPlayTime, user.totalPlayTime);
}


void Stats(tListU *list) {
    int totalUsersBasic = 0, totalUsersPro = 0;
    int totalPlaysBasic = 0, totalPlaysPro = 0;
    double averageBasic = 0.0, averagePro = 0.0;

    // Verificar si la lista está vacía
    if (isEmptyListU(*list)) {
        printf("+ Error: Stats not possible\n");
        return;
    }

    // Crear una lista temporal para almacenar los usuarios ordenados
    tListU sortedList;
    createEmptyListU(&sortedList);

    // Copiar la lista original en la lista temporal
    tPosU pos = firstU(*list);
    while (pos != NULLU) {
        insertItemU(getItemU(pos, *list), &sortedList);
        pos = nextU(pos, *list);
    }

    // Iterar sobre la lista de usuarios ordenada
    pos = firstU(sortedList);
    while (pos != NULLU) {
        tItemU user = getItemU(pos, sortedList);

        // Imprimir datos del usuario
        printf("User %s category %s totalplaytime %d\n", user.userName, (user.userCategory == basic) ? "basic" : "pro", user.totalPlayTime);

        // Imprimir canciones del usuario
        if (isEmptyListS(user.songList)) {
            printf("No songs\n");
        } else {
            tPosS songPos = firstS(user.songList);
            while (songPos != NULLS) {
                tItemS song = getItemS(songPos, user.songList);
                printf("Song %s playtime %d\n", song.songTitle, song.playTime);
                songPos = nextS(songPos, user.songList);
            }
        }

        printf("\n"); // Imprimir una línea en blanco después de cada usuario
        // Sumar al contador de usuarios y tiempo total de reproducción
        if (user.userCategory == basic) {
            totalUsersBasic++;
            totalPlaysBasic += user.totalPlayTime;
        } else {
            totalUsersPro++;
            totalPlaysPro += user.totalPlayTime;
        }

        pos = nextU(pos, sortedList); // Avanzar al siguiente usuario
    }

    // Calcular el promedio para cada categoría
    if (totalUsersBasic > 0) {
        averageBasic = (double)totalPlaysBasic / totalUsersBasic;
    }
    if (totalUsersPro > 0) {
        averagePro = (double)totalPlaysPro / totalUsersPro;
    }

    // Imprimir tabla de estadísticas
    printf("Category  Users  TimePlay  Average\n");
    printf("Basic     %5d %9d %8.2f\n", totalUsersBasic, totalPlaysBasic, averageBasic);
    printf("Pro       %5d %9d %8.2f\n", totalUsersPro, totalPlaysPro, averagePro);
}


//Función auxiliar que convierte un char a la categoría
tUserCategory char_to_category(char* string){
    tUserCategory category;
    if(strcmp(string, "basic") == 0){
        category = basic;
        return category;
    }
    if(strcmp(string, "pro") == 0){
        category = pro;
        return category;
    }
    printf("Categoria inexistente");


    return 0;
}

void Delete(tUserName newUserName, tListU *userList) {
    // Buscar al usuario en la lista
    tPosU userPos = findItemU(newUserName, *userList);
    if (userPos == NULLU) {
        printf("+ Error: Delete not possible\n");
        return;
    }

    // Obtener el usuario a eliminar
    tItemU user = getItemU(userPos, *userList);

    // Eliminar todas las canciones de la lista de reproducción del usuario
    tPosS songPos = firstS(user.songList);
    while (songPos != NULLS) {
        deleteAtPositionS(songPos, &(user.songList));
        songPos = firstS(user.songList);
    }

    // Eliminar al usuario de la lista
    deleteAtPositionU(userPos, userList);

    // Imprimir un mensaje de confirmación
    printf("* Delete: user %s category %s totalplaytime %d\n", newUserName, 
            (user.userCategory == basic) ? "basic" : "pro", user.totalPlayTime);
}

void Remove(int maxTime, tListU *userList) {
    // Verificar si la lista está vacía
    if (isEmptyListU(*userList)) {
        printf("+ Error: Remove not possible\n");
        return;
    }

    // Inicializar variables para contar usuarios eliminados
    int removedUsers = 0;

    // Recorrer la lista de usuarios
    tPosU pos = firstU(*userList);
    while (pos != NULLU) {
        tItemU user = getItemU(pos, *userList);

        // Verificar si el usuario es de categoría 'basic' y su tiempo total de reproducción excede maxTime
        if (user.userCategory == basic && user.totalPlayTime > maxTime) {
            // Eliminar todas las canciones de la lista de reproducción del usuario
            tPosS songPos = firstS(user.songList);
            while (songPos != NULLS) {
                deleteAtPositionS(songPos, &(user.songList));
                songPos = firstS(user.songList);
            }

            // Eliminar al usuario de la lista
            deleteAtPositionU(pos, userList);

            // Imprimir un mensaje de confirmación
            printf("Removing user %s totalplaytime %d\n", user.userName, user.totalPlayTime);

            // Incrementar el contador de usuarios eliminados
            removedUsers++;
        }
        pos = nextU(pos, *userList); // Avanzamos al siguiente usuario
    }
    // Si no se eliminaron usuarios, imprimimos un mensaje de error
    if (removedUsers == 0) {
        printf("+ Error: Remove not possible\n");
    }
}

