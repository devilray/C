/* Compilar con: gcc -Wall -g -std=c99 -oprogexamen progexamen.c mips-runtime.c keyio.c */

#include <stdbool.h>
#include "mips-runtime.h"

typedef struct {
  int numerador;
  int denominador;
} Fraccion;

#define NUM_FRACCIONES 10
Fraccion fracciones[NUM_FRACCIONES] = {
  { 1, 2 },
  { 3, 2 },
  { -200, 101 },
  { 2000, 1111 },
  { 100, 101 },
  { -70, 71 },
  { 2, 1111 },
  { 21, 33 },
  { 8, 9 },
  { 13, 11 }
};


int preguntar_entero(char* mensaje) {
  /* ??? */
}

void preguntar_fraccion(Fraccion* f) {
  f->numerador = preguntar_entero("Introduce el numerador: ");
  f->denominador = preguntar_entero("Introduce el denominador: ");
}

void print_fraccion(Fraccion* f) {
  print_integer(f->numerador);
  print_character('/');
  print_integer(f->denominador);
}

int mcd(int a, int b) {
  if (a < 0) {
    a = -a;
  } 

  if (b < 0) {
    b = -b;
  } 

  if (a == 0) {
    return b;
  } else if (b == 0) {
    return a;
  }

  while (a != b) {
    if (b < a) {
      a = a - b;
    } else {
      b = b - a;
    }
  }
  return a;
}

void simplificar_fraccion(Fraccion* f) {
  /* ??? */
}

void sumar_fracciones(Fraccion* fc, Fraccion* fa, Fraccion* fb) {
  /* ??? */
}

void sumar_fracciones_array(Fraccion* resultado, Fraccion* array, int num_elems) {
  resultado->numerador = 0;
  resultado->denominador = 1;
  for (int i = 0; i < num_elems; ++i) {
    sumar_fracciones(resultado, resultado, &array[i]);
    simplificar_fraccion(resultado);
  }
}

int main(int argc, char* argv[]) {
  clear_screen();
  print_string("\nExamen de ETC de ensamblador\n");
  while (true) {
    print_string("\n\n 1. Lectura de enteros por teclado\n 2. Cálculo del Máximo Común divisor (MCD)\n 3. Lectura de fracciones por teclado\n 4. Simplificación de fracciones\n 5. Suma de dos fracciones\n 6. Suma de un array de fracciones\n 7. Salir\n\nElige una opción: ");
    char opc = read_character();
    print_string("\n\n");
    if (opc == '1') {
      int n = preguntar_entero("Introduce un entero: ");
      print_string("\nEl entero leído ha sido: ");
      print_integer(n);
      print_string("\n");
    } else if (opc == '2') {
      int a = preguntar_entero("Introduce un número (a): ");
      int b = preguntar_entero("Introduce otro número (b): ");
      print_string("\nEl MCD de a y b es: ");
      print_integer(mcd(a, b));
      print_string("\n");
    } else if (opc == '3') {
      Fraccion f;
      preguntar_fraccion(&f);
      print_string("\nLa fraccion leída ha sido: ");
      print_fraccion(&f);
      print_string("\n");
    } else if (opc == '4') {
      Fraccion f;
      preguntar_fraccion(&f);
      print_string("\nLa fraccion leída ha sido: ");
      print_fraccion(&f);
      simplificar_fraccion(&f);
      print_string("\nLa fraccion simplificada es: ");
      print_fraccion(&f);
      print_string("\n");
    } else if (opc == '5') {
      Fraccion fa;
      print_string("\nLeyendo la primera fracción:\n");
      preguntar_fraccion(&fa);
      print_string("La primera fraccion leída ha sido: ");
      print_fraccion(&fa);
      Fraccion fb;
      print_string("\nLeyendo la segunda fracción:\n");
      preguntar_fraccion(&fb);
      print_string("La segunda fraccion leída ha sido: ");
      print_fraccion(&fb);
      Fraccion fc;
      sumar_fracciones(&fc, &fa, &fb);
      print_string("\nLa suma es: ");
      print_fraccion(&fc);
      simplificar_fraccion(&fc);
      print_string("\nLa suma simplificada es: ");
      print_fraccion(&fc);
      print_string("\n");
    } else if (opc == '6') {
      print_string("\n");
      for (int i = 0; i < NUM_FRACCIONES - 1; ++i) {
        print_fraccion(&fracciones[i]);
        print_string(" + ");
      }
      print_fraccion(&fracciones[NUM_FRACCIONES - 1]);
      print_string(" = ");
      Fraccion fr;
      sumar_fracciones_array(&fr, fracciones, NUM_FRACCIONES);
      print_fraccion(&fr);
      print_string("\n");
    } else if (opc == '7') {
      print_string("¡Adiós!\n");
      mips_exit(0);
    } else {
      print_string("Opción incorrecta. Pulse cualquier tecla para seguir.\n");
      read_character();
    }
  }
}





