#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int hexToDec(char palabra[])
{
    long long decimal = 0, base = 1;
    int i = 0, value, length;

    length = strlen(palabra);
    for(i = length--; i >= 0; i--)
    {
        if(palabra[i] >= '0' && palabra[i] <= '9')
        {
            decimal += (palabra[i] - 48) * base;
            base *= 16;
        }
        else if(palabra[i] >= 'A' && palabra[i] <= 'F')
        {
            decimal += (palabra[i] - 55) * base;
            base *= 16;
        }
        else if(palabra[i] >= 'a' && palabra[i] <= 'f')
        {
            decimal += (palabra[i] - 87) * base;
            base *= 16;
        }
    }

    return decimal;
}

int asciiToBinary(int ascii)
{
	int res = 0, i = 1, rem;
        
	while (ascii > 0)
	{
		rem = ascii % 2;
		res = res + (i * rem);
		ascii = ascii / 2;
		i = i * 10;
	}

    
	return(res);
}

int encode(char palabra[]){

    int bits;
    bits = (strlen(palabra) / 2) * 8;
    int bitsFalt; 
    bitsFalt = 7 - (bits%7);
    printf("%d \n", bits);

    int *salida = malloc((4*(sizeof((bits + bitsFalt)) / sizeof(int))) * sizeof(int));

    int x, y, binario, index, k, i;
    char *pivote = (char *) malloc(2);
    i = strlen(palabra) - 1;
    char *listaTemp = malloc((bits + bitsFalt) * sizeof(int));
    int *palTmp = malloc(10 * sizeof(int));
    int *palCodTmp = malloc(11 * sizeof(int));
    
    k = (bits + bitsFalt) - 1;

    while(k > -1){
        listaTemp[k] = 0;
        k--;
    }
    
    index = (bits + bitsFalt) - 1;
    
    while(i >= 0){

        y = 7;

        while(y > -1){
            palTmp[y] = 0;
            y--;
        } 

        pivote[1] = palabra[i];
        pivote[0] = palabra[i-1];
        printf("Pivote: %s \n", pivote);
        binario = asciiToBinary(hexToDec(pivote));
        printf("%d \n", binario);

       x = 7;
       while(binario > 0){
            
           palTmp[x] = binario%10;
           x--;
           binario = binario/10;
           printf("%d \n", binario);
        }

        x = 7;
       while(x > -1){
            
           listaTemp[index] = palTmp[x];
           index--;
           x--;

        }
       
        i = i-2;
    }

    x = 0;
    while(x < (bits + bitsFalt)){
            
        printf("%d", palTmp[x]);
        x++;

    }
     printf("\n");


	return 0;

}

int main(int argc, char *argv[])
{

    if(strcmp(argv[1], "encode") == 0){

        encode(argv[2]);

    }
    printf("%s \n", argv[1]);
    return 0;
}
