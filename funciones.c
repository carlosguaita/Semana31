#include <stdio.h>
#include <string.h>
#include "funciones.h"


float validarFlotanteRango(float min, float max){
    int val = 0;
    float aux = 0;
    do{
        val = scanf("%f",&aux);
        while((getchar())!='\n');
            if (aux < min || aux > max || val != 1)
            {
                printf("Error: EL valor ingresado es incorrecto\n");
            }
    }while(aux < min || aux > max  || val != 1);
    return aux;
}


void calificacionAltaBaja(float m1[N_ALUMNOS], float m2[N_ALUMNOS], 
                            float m3[N_ALUMNOS], float altasBajas[3][2], int cont){

    float max = 0, min = 10;
    for(int i = 0; i<cont; i++){
        if (m1[i] < min){
            min = m1[i];
        }
        if (m1[i] >= max){
            max = m1[i];
        }
    }
    altasBajas[0][0]=min;
    altasBajas[0][1]=max;

    max = 0;
    min = 10;
    for(int i = 0; i<cont; i++){
        if (m2[i] < min){
            min = m2[i];
        }
        if (m2[i] >= max){
            max = m2[i];
        }
    }
    altasBajas[1][0]=min;
    altasBajas[1][1]=max;

    max = 0;
    min = 10;
    for(int i = 0; i<cont; i++){
        if (m3[i] < min){
            min = m3[i];
        }
        if (m3[i] >= max){
            max = m3[i];
        }
    }
    altasBajas[2][0]=min;
    altasBajas[2][1]=max;
}

void aprobadosReprobados(char nombres[N_ALUMNOS][20], float m1[N_ALUMNOS],
                         float m2[N_ALUMNOS], float m3[N_ALUMNOS], int cont){
    char aprep[3][20];
    printf("#\t\tNombre\t\tMatematicas\t\tLenguaje\t\tProgramacion\n");
    for (int i = 0; i < cont; i++)
    {
        if(m1[i]>=6){
            strcpy(aprep[0],"aprobado");
        }else{
            strcpy(aprep[0],"reprobado");
        }

        if(m2[i]>=6){
            strcpy(aprep[1],"aprobado");
        }else{
            strcpy(aprep[1],"reprobado");
        }

        if(m3[i]>=6){
            strcpy(aprep[2],"aprobado");
        }else{
            strcpy(aprep[2],"reprobado");
        }
    
        printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\n",i,nombres[i],aprep[0],aprep[1],aprep[2]);

    }

}
