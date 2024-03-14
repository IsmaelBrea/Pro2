/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ISMAEL BREA ARIAS    LOGIN 1: ismael.brea
 * AUTHOR 2: DIEGO ROMÁN POSE     LOGIN 2: diego.roman
 * GROUP:4.3                       DATE:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif


void New(tUserName newUserName, tUserCategory newUserCategory, tList *list){
    /* Objetivo: alta de un usuario de categoría basic o pro
  * Entradas: lista de usuarios, nombre de usuario y categoría del usuario
  * Salidas: lista
  * Precondiciones: ninguna
  * Postcondiciones: la lista de usuarios se modifica para incluir el nuevo usuario.
   */

    // Verificar si el usuario ya existe en la lista
    if (findItem(newUserName, *list) != LNULL) {
        // El usuario ya existe, imprimir un mensaje de error
        printf("+ Error: New not possible\n");
        return;
    }

    // Crear un nuevo objeto tItemL para representar al nuevo usuario
    tItemL newUser;

    strcpy(newUser.userName, newUserName);
    newUser.userCategory = newUserCategory;
    newUser.numPlay = 0;   //inicializamos el número de reproducciones a 0

    // Agregar el nuevo usuario al final de la lista
    if (insertItem(newUser,LNULL, list)) {   //si la posición que le pasamos es NULL el usuario se insertará al final de la lista
        // Imprimir un mensaje de confirmación
        printf("* New: user %s category %s\n", newUserName, newUserCategory == basic ? "basic" : "pro");
    } else {
        // No se pudo agregar el nuevo usuario, imprimir un mensaje de error
        printf("+ Error: New not possible\n");
    }
}

void Delete(tUserName newUserName,tList *list){
    /* Objetivo: eliminar un usuario de la lista
     * Entradas: nombre de usuario y lista de usuarios
     * Salidas: lista de usuarios
     * Precondiciones: el usuario debe existir en la lista, no debe estar vacía
     * Postcondiciones: cambia la lista (tiene un elemento menos, por lo que se modifican las posiciones)
     *
     */

    //Verificar que el usuario no existe en la lista
    if(findItem(newUserName,*list) == LNULL){
        //El usuario no existe, imprimir un mensaje de error
        printf("+ Error: Delete not possible\n");
        return;

    }else{   //si existe
        //Tenemos que encontrar su posición
        tPosL pos = findItem(newUserName, *list);

        //Verificamos que la posición obtenida es válida
        if(pos != LNULL){
           tItemL item = getItem(pos, *list);   //obtenemos los datos del usuario
            //y eliminamos su posición
            deleteAtPosition(pos,list);
            // Imprimir mensaje de éxito
            printf("* Delete: user %s category %s numplays %d\n", item.userName, item.userCategory == basic ? "basic" : "pro", item.numPlay);
        }
        else{
            printf("+ Error: Delete not possible\n");
        }
    }
}


void Stats(tList *list){
    /* Objetivo: mostrar la lista de los usuarios actuales de MUSFIC y sus datos
     * Entradas: lista de usuarios
     * Salidas: lista de usuarios
     * Precondiciones: -
     * Postcondiciones: -
     */
    static int totalUsersBasic = 0, totalUsersPro = 0;
    static int totalPlaysBasic = 0, totalPlaysPro = 0;
    static double averageBasic = 0.0, averagePro = 0.0;

    if (isEmptyList(*list)) { // Comprobar si la lista está vacía
        printf("+ Error: Stats not possible\n");
        return;
    }

    // Imprimir usuarios actuales
    tPosL pos = first(*list);
    while (pos != LNULL) {
        tItemL item = getItem(pos, *list);
        printf("User %s category %s numplays %d\n", item.userName, item.userCategory == basic ? "basic" : "pro", item.numPlay);
        if (item.userCategory == basic) {
            totalUsersBasic++;
            totalPlaysBasic += item.numPlay;
        } else {
            totalUsersPro++;
            totalPlaysPro += item.numPlay;
        }
        pos = next(pos, *list);
    }
    // Cálculo de estadísticas agregadas
    averageBasic = totalUsersBasic > 0 ? (double)totalPlaysBasic / totalUsersBasic : 0.0;
    averagePro = totalUsersPro > 0 ? (double)totalPlaysPro / totalUsersPro : 0.0;

    // Imprimir tabla de estadísticas
    printf("Category   Users   Plays   Average\n");
    printf("Basic      %5d   %6d   %8.2f\n", totalUsersBasic, totalPlaysBasic, averageBasic);
    printf("Pro        %5d   %6d   %8.2f\n", totalUsersPro, totalPlaysPro, averagePro);
}



//Funcion auxiliar que convierte un char a la categoria
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


void processCommand(tList *list,char *commandNumber, char command, char *param1, char *param2) {

    switch (command) {
        case 'N':
            printf("********************\n");
            printf("%s %c: user %s category %s\n", commandNumber, command, param1, param2);
            New(param1, char_to_category(param2), list);
            break;
        case 'D':
            printf("********************\n");
            printf("%s %c: user %s\n",commandNumber, command, param1);
            Delete(param1,list);
            break;
        case 'U':
            printf("********************\n");
            break;
        case 'P':
            printf("********************\n");
            break;
        case 'S':
            printf("********************\n");
            printf("%s %c:\n",commandNumber,command);
            Stats(list);
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    tList list;
    createEmptyList(&list);


    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);

            processCommand(&list,commandNumber, command[0], param1, param2);
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