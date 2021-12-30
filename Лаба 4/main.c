#include <stdio.h>
#include <stdlib.h>

void fill_int_array( unsigned int * uiptr, unsigned int size_of_array );
void fill_float_array( float * fptr, unsigned int size_of_array );
void print_int_array( const unsigned int * A, unsigned int Size );
void print_float_array( const float * B, unsigned int Size );
double mean_value(const unsigned int * A, unsigned int Size );
unsigned int find_min(const unsigned int * A, unsigned int Size );
float find_max(const float * B, unsigned int Size );
unsigned int sum ( const unsigned int * uiptr, unsigned int size_of_array );
double product( const float * fptr, unsigned int size_of_array );

int main()
{
 unsigned int * A;
 float * B;
 unsigned int Size;
 unsigned int amount;
 double mult;
 double average_value;
 unsigned int min_value;
 float max_value;

 printf("Enter size of array: ");
 scanf("%u", &Size);
 A = (unsigned int *) calloc (Size, sizeof(unsigned int) );
 B = (float *) malloc (Size * sizeof(float) );
 if( A == NULL || B == NULL ){
 printf("Memory has not been allocated");
 exit(0);
 }
 fill_int_array( A, Size );
 fill_float_array( B, Size );
 print_int_array( A, Size );
 print_float_array( B, Size );
 amount = sum( A, Size );
 mult = product( B, Size );
 max_value = find_max(B, Size );
 average_value = mean_value( A, Size );
 min_value = find_min(A,Size );
 printf("\n\nSum = %u", amount);
 printf("\nProduct = %.3lf", mult);
 printf("\n\nMean value = %.3lf",average_value);
 printf("\n\nMin value = %u",min_value);
 printf("\n\nMax value = %.3lf",max_value);
 free(A);
 free(B);
 return 0;
}


void fill_int_array( unsigned int * A, unsigned int Size )
{
 unsigned int j;
 for( j = 0; j <= Size-1; j++ )
{
 A[j] = Size - (j + 1);
}
}

void fill_float_array( float * B, unsigned int Size )
{
 unsigned int j;
 for( j = 0; j <= Size-1; j++ )
{
 B[j] =  5.0 * j + 5.0;
}
}

void print_int_array( const unsigned int * A, unsigned int Size )
{
 unsigned int j;
 printf("\n\nArray of UNSIGNED INT values:\n");
 for( j = 0; j < Size; j++ )
 printf("%5d", A[j] );
}

void print_float_array( const float * B, unsigned int Size )
{
 unsigned int j;
 printf("\n\nArray of FLOAT values:\n");
 for( j = 0; j < Size; j++ )
 printf("%7.2f", B[j] );
}

unsigned int sum (const unsigned int * A, unsigned int Size )
{
 unsigned int j, S;
 S = 0;
 for( j = 0; j < Size; j++ )
 S += A[j];
 return S;
}

double product(const float * B, unsigned int Size )
{
 unsigned int j;
 double M;
 M = 1.0;
 for( j = 0; j < Size; j++ )
 M *= B[j];
 return M;
}
double mean_value(const unsigned int * A, unsigned int Size )
{
 double V;
 V = (double)sum( A, Size )/Size;
 return V;
}
unsigned int find_min(const unsigned int * A, unsigned int Size )
{
 int tempmin = A[0];
 int j;
 for(j = 1; j <= Size-1; j++)
{
 if( A[j] < tempmin )
{
 tempmin = A[j];
}
}
 return tempmin;
}

float find_max(const float * B, unsigned int Size )
{
 float tempmax = B[0];
 int j;
 for(j = 1; j <= Size-1; j++)
{
 if( B[j] > tempmax )
{
 tempmax = B[j];
}
}
 return tempmax;
}
