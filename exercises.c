#include "arraylist.h"
#include "stack.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "exercises.h"

// Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
// NO MODIFICAR
void imprime_lista(List *L) {
  int *dato;
  dato = (int *)first(L);
  printf("[");
  while (dato != NULL) {
    printf("%d ", *dato);
    dato = (int *)next(L);
  }
  printf("]\n");
}

// Ojo que la pila se vacía al imprimir y se imprime en orden inverso
// NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
  void *dato;
  printf("[");
  while ((dato = pop(P)) != NULL) {
    printf("%d ", *(int *)dato);
  }
  printf("]\n");
}

/*
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List *crea_lista() {
  List *L = create_list();
  for (int i = 1; i <= 10; i++) {
    int *elemento = (int *)malloc(sizeof(int));
    if (elemento == NULL)
      exit(EXIT_FAILURE);
    *elemento = i;
    push(L, elemento);
  }
  return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
  int suma = 0;
  while (first(L) != NULL) {
    suma += *(int *)first(L);
    popFront(L);
  }

  return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos de la lista que
sean iguales a elem. Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List *L, int elem) {
  int *el = first(L);
  while (el != NULL) {
    if (*el == elem) {
      popCurrent((List *)L);
    }
    el = next(L);
  }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack *P1, Stack *P2) {
  int *el = first(P1);

  while (el != NULL) {
    pushBack(P2, el);
    el = next(P1);
  }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
  Stack *pila = create_stack();

  // int largo = get_size((List *)cadena);
  int largo = strlen(cadena);
  // char *caracter = (char *)first((List *)cadena);

  for (int i = 0; i < largo; i++) {

    if (cadena[i] == '(' || cadena[i] == '[' || cadena[i] == '{')
      push(pila, &cadena[i]);

    else if (cadena[i] == ')' || cadena[i] == ']' || cadena[i] == '}') {
      if (top(pila) == NULL)
        return 0;
      else {
        char *ult = (char *)pop(pila);
        if ((cadena[i] == ')' && *ult != '('))
          return 0;
        else if ((cadena[i] == '}' && *ult != '{'))
          return 0;
        else if ((cadena[i] == ']' && *ult != '['))
          return 0;
      }
    }
  }
  return 1;
}
