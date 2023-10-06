#include "MKL25Z4.h"
#include "stdio.h"
#include "TecMat.h"

uint8_t array_Cols[4] = {17, 16, 13, 12};
uint8_t array_Fils[4] = {11, 10,  6,  5};
int i, j, estado=0;
char key[4][4] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'},
};


void configTec(){
    SIM -> SCGC5 |= SIM_SCGC5_PORTA_MASK;
    for (i = 0; i < 4; i++)
    {
        PORTC   -> PCR[array_Cols[i]] |= PORT_PCR_MUX(0)| PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
        PORTC   -> PCR[array_Fils[i]] |= PORT_PCR_MUX(1);
        PTC     -> PSOR|=(1u << i);
    }
}
char lectura(){
    for(i = 0; i < 4; i++){
        PTC -> PSOR |= (0u<< (array_Fils[i]));
        for(j = 0; j < 4; j++){
            estado = (PTC -> PDIR &(1<<(array_Cols[i])));
            if(estado == 0){
                return key[i][j]; 
            }else{
                return 0;
            }
        }            
        PTC -> PSOR |= (1u<< (array_Fils[i]));
    }

}