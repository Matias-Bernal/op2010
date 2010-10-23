#include <stdio.h>
/* 
  Construye un arreglo (numbers) con los datos dados en input, decodificando cada número en su representación decimal.
  TODO: Implementar en nasm.
*/
void decode(short int *input, unsigned int i_size, unsigned short  int* numbers, unsigned int *n_size);
/* 
  Dado un arreglo de números desordenado (numbers) ordena el arreglo utilizando el algoritmo de ordenamiento bubble sort.
  TODO: Implementar en nasm.
*/
void bubble_sort(unsigned short int * numbers, unsigned int p_size);

int readDataFromFile(unsigned short int *array, unsigned int *size, const char * file_name);

int main(int argc, char *argv[]) 
{
  int i;
  int short input[300];
  unsigned  int input_size;
  unsigned short int numbers[300];  
  unsigned int numbers_size;


  if (readDataFromFile(input, &input_size, argv[1]) != 0)
  {
    printf("%s\n", "Error en la carga de datos");
    return -1;  // Error reading data.
  }
  printf("%s %d\n", "Tama~no de la entrada:", input_size);

/*  decode(input, input_size, numbers, &numbers_size);
 	
  printf("%s %d\n", "Cantidad de Digitos decodificados:", numbers_size);

  bubble_sort(numbers, numbers_size);
*/
  return 0;
}
/*
 * Carga el arreglo con los datos leyendo desde el archivo cuyo nombre es pasado como parametro.
 * No considera los guiones del archivo de entrada.
 * Tambien carga el entero size con el tamaño del arreglo.
*/
int readDataFromFile(unsigned short int *array, unsigned int *size, const char * file_name)
{
    FILE * file;
    file = fopen(file_name,"r");
 
	if (file == NULL){
        return -1;
    }else{
 
        char caracter;
        int i=0;

        while ((caracter=fgetc(file))!='#'){    	
            if(caracter !='-'){
                array[i] = caracter-48; /*Restamos 48 que es el ascii del cero, para tener números en representación decimal*/
                i++;
            }        
        }
        fclose(file);        
        *size =i;	
    return 0;
   }
}
