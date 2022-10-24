/* Lee del usuario una fecha en formato dd/mm/aaaa e imprime si es correcta o no.
VARIABLES: "dia", "mes", "anio" ==> Componentes de la fecha leída del usuario.
 "fecha_correcta" ==> Flag utilizado para almacenar si la fecha es correcta o no. */

//PROTOTIPOS
int bisiesto (int anio);
int dias_mes (int mes, int anio);
int comprueba_dia (int dia, int mes, int anio);
int comprueba_mes (int mes);
int comprueba_anio (int anio);
int comprueba_fecha (int dia, int mes, int anio);
void leer_fecha (int *dia, int *mes, int *anio);
void escribir_resultado (int esValida);

#include <stdio.h>

int main() {
    int dia, mes, anio, esValida;
    leer_fecha(&dia,&mes,&anio);
    esValida=comprueba_fecha(dia,mes,anio);
    escribir_resultado(esValida);
    return 0;
}

int bisiesto (int anio){
    int esBisiesto=0;
    if (anio%4==0 && (anio%100!=0 || anio%400==0))
        esBisiesto=1;
    return esBisiesto;
}

int dias_mes (int mes, int anio){
    int dias;
    switch (mes) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dias=31;
            break;
        case 2:
            if (bisiesto(anio)==1)
               dias=29;
            else
               dias=28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            dias=30;
            break;
    }
    return dias;
}

int comprueba_dia (int dia, int mes, int anio){
    int valido=0;
    if (dia>0 && dia<=dias_mes(mes,anio))
        valido=1;
    return valido;
}

int comprueba_mes (int mes){
    int valido=0;
    if (mes>0 && mes<=12)
        valido=1;
    return valido;
}

int comprueba_anio (int anio){
    int valido=0;
    if (anio>0)
        valido=1;
    return valido;
}

int comprueba_fecha (int dia, int mes, int anio){
    int valido=0;
    if (comprueba_dia(dia,mes,anio)==1 && comprueba_mes(mes)==1 && comprueba_anio(anio)==1)
        valido=1;
    return valido;
}

void leer_fecha (int *dia, int *mes, int *anio){
    printf("Introduce una fecha (dd mm aaaa): ");
    scanf("%d %d %d",dia,mes,anio);
}

void escribir_resultado (int esValida){
    if (esValida==1)
        printf("\nLa fecha introducida SI es una fecha correcta.\n");
    else
        printf("\nLa fecha introducida NO es una fecha correcta.\n");
}