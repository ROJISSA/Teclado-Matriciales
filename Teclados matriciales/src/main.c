#include "MKL25Z4.h"
#include "stdio.h"
#include "TecMat.h"
#include "string.h"
#include "strings.h"
char Contra[4] = {'0', '0', '0', '0'};
char caracteresContra[4] = {'0', '0', '0', '0'};
char carry;
int i, sizecC= sizeof(caracteresContra), sizeC = sizeof(Contra);
int main(){
    configTec();
            printf("La contraseña por defecto es: '0 0 0 0'\n Esto se cumplirá siempre y cuando la misma no haya sido modificada");
    while(1){
        printf("La contraseña por defecto es: '0 0 0 0'\n Esto se cumplirá siempre y cuando la misma no haya sido modificada");
        for(i = 0; i < sizecC; i++){
            if(lectura() == '*'){
                for(i = 0; i < sizecC; i++){
                    carry = caracteresContra[i-1];
                    caracteresContra[i-1]= caracteresContra[i];
                    caracteresContra[i]= carry;
                }
                i=4;
            }else{
                caracteresContra[i] = lectura();
            }
        }
        if(strncmp(caracteresContra, Contra, sizeC) == 0){
            printf("la Contraserña es correcta. \n Si desea modificarla, por favor presione '#'");
            if(lectura() == '#'){
            printf("Porfavor, ingrese una contraseña nueva a continuación: ");
            for(i = 0; i < sizeC; i++){
                if(lectura() == '*'){
                    if(lectura() == '*'){
                        for(i = 0; i < sizeC; i++){
                            carry = Contra[i-1];
                            Contra[i-1]= Contra[i];
                            Contra[i]= carry;
                        }
                        i=4;
                    }else{
                        Contra[i] = lectura();
                    }
                }    
            }
            }
        }else{
            printf("La contraseña es incorrecta, por favor inténtelo de nuevo");
        }
        return 0;
    }
}