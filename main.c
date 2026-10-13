#include <stdio.h>
#define  N_MATERIAS 5 

float validarFlotanteRango(float min, float max);

int main (int argc, char *argv[]) {

    char nombres[N_MATERIAS][20];
    float m1[N_MATERIAS] = {0}, m2[N_MATERIAS] = {0}, m3[N_MATERIAS] = {0};
    int opc = 0, opc1 = 0;

    int contE = 0;

    do
    {
        printf("Selecione una opcion:\n");
        printf("1.Crear estudiante\n");
        printf("2.Ingresar calificaciones\n");
        printf("3.Mostrar promedios\n");
        printf("4.Mostrar calificacion mas alta y mas baja\n");
        printf("5.Mostrar aprobados y reprobados\n");
        printf(">> ");
        scanf("%d",&opc1);

        switch (opc1)
        {
        case 1:
            if(contE<N_MATERIAS){
                printf("Ingrese el estudiante %d: ",contE);
                scanf("%s",&nombres[contE]);
                contE++;
            }else{
                printf("No se puede ingresar mas estudiantes\n");
            }
            break;
        case 2:
            int sel=0;
            printf("Seleccione un estudiante:\n");
            for (int i = 0; i < contE; i++)
            {
                printf("%d.%s\n",i,nombres[i]);
            }
            scanf("%d",&sel);
            if(sel<0 || sel >= contE){
                printf("Error: no existe la seleccion\n");
                break;
            }
            printf("Seleccionado estudiate %d: %s\n",sel,nombres[sel]);
            printf("Ingrese las calificaciones\n");

            printf("Matematicas: ");
            m1[sel] = validarFlotanteRango(1,10);
            
            printf("Lenguaje: ");
            m2[sel] = validarFlotanteRango(1,10);

            printf("Programacion: ");
            m3[sel] = validarFlotanteRango(1,10);
  
            break;
        case 3:
            float prom=0;
            float promM[3]={0};
            printf("#\t\tNombre\t\tMat\t\tLen\t\tPro\t\tProm\n");
            for (int i = 0; i < contE; i++)
            {
                prom = (m1[i] + m2[i] + m3[i])/3;
                printf("%d\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",i,nombres[i],m1[i],m2[i],m3[i],prom);
                promM[0]+=m1[i];
                promM[1]+=m2[i];
                promM[2]+=m3[i];
            }
            promM[0]/=contE;
            promM[1]/=contE;
            promM[2]/=contE;
            printf("#\t\tProme.\t\t%.2f\t\t%.2f\t\t%.2f\n",promM[0],promM[1],promM[2]);
            break;
        
        default:
            break;
        }






        printf("Desea seleccionar una opcion 1.Si/2.No: ");
        scanf("%d",&opc);
    } while (opc==1);
    



    return 0;
}


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