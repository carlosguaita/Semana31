#define  N_ALUMNOS 5 

float validarFlotanteRango(float min, float max);
void calificacionAltaBaja(float m1[N_ALUMNOS], float m2[N_ALUMNOS], 
                            float m3[N_ALUMNOS], float altasBajas[3][2], int cont);
void aprobadosReprobados(char nombres[N_ALUMNOS][20], float m1[N_ALUMNOS],
                         float m2[N_ALUMNOS], float m3[N_ALUMNOS], int cont);