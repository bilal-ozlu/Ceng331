/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
/*
 * Please fill in the following student struct
 */
team_t team = {
    "1942614",              /* Student ID */

    "Bilal Ozlu",     /* full name */
    "e1942614@ceng.metu.edu.tr",  /* email address */

    "",                   /* leave blank */
    ""                    /* leave blank */
};


/***************
 * CONVOLUTION KERNEL
 ***************/

/******************************************************
 * Your different versions of the convolution functions  go here
 ******************************************************/

/*
 * naive_conv - The naive baseline version of convolution
 */
char naive_conv_descr[] = "naive_conv: Naive baseline implementation";
void naive_conv(int dim,int *src, int *ker,int *dst) {
    int i,j,k,l;

    for(i = 0; i < dim-8+1; i++)
        for(j = 0; j < dim-8+1; j++) {
            dst[j*dim+i] = 0;
            for(k = 0; k < 8; k++)
                for(l = 0; l < 8; l++) {
                    dst[j*dim+i] = dst[j*dim+i] +src[(j+l)*dim+(i+k)]*ker[l*dim+k];
                }
        }

}

/*
 * convolution - Your current working version of convolution
 * IMPORTANT: This is the version you will be graded on
 */
char convolution_descr[] = "Dot product: Current working version";
void convolution(int dim,int *src, int *ker,int *dst){

int i,j,a,b,c,d;
    for(j = 0; j < dim-7; j++) {
      b=j*dim;
      for(i = 0; i < dim-7; i++){
        c=b+i;
        d=0;
        a= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c]*ker[d];
        c+=dim-7;
        d+=dim-7;
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c]*ker[d];
        c+=dim-7;
        d+=dim-7;
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c]*ker[d];
        c+=dim-7;
        d+=dim-7;
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c]*ker[d];
        c+=dim-7;
        d+=dim-7;
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c]*ker[d];
        c+=dim-7;
        d+=dim-7;
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c]*ker[d];
        c+=dim-7;
        d+=dim-7;
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c]*ker[d];
        c+=dim-7;
        d+=dim-7;
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c++]*ker[d++];
        a+= src[c]*ker[d];
        dst[b+i]=a;
    }
  }
}

/*********************************************************************
 * register_conv_functions - Register all of your different versions
 *     of the convolution functions  with the driver by calling the
 *     add_conv_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_conv_functions() {
    add_conv_function(&naive_conv, naive_conv_descr);
    add_conv_function(&convolution, convolution_descr);
    /* ... Register additional test functions here */
}




/***************
 * MATRIX MULTIP KERNEL
 ***************/

/******************************************************
 * Your different versions of the matrix multiplications  go here
 ******************************************************/

/*
 * naive_matrix_multiplication - The naive baseline version of matrix multiplication
 */
char naive_matrix_multiplication_descr[] = "Naive_matrix_multiplication: Naive baseline implementation";
void naive_matrix_multiplication(int dim,int *src, int *src2,int *dst) {
    int i,j,k;

    for(i = 0; i < dim; i++)
        for(j = 0; j < dim; j++) {
            dst[j*dim+i]=0;
            for(k = 0; k < dim; k++)
                dst[j*dim+i] = dst[j*dim+i] + src[j*dim+k]*src2[i+k*dim];
        }
}


/*
 * matrix_multiplication - Your current working version of matrix_multiplication
 * IMPORTANT: This is the version you will be graded on
 */


char matrix_multiplication_descr[] = "Matrix multiplications: Current working version";
void matrix_multiplication(int dim,int *src, int *src2,int *dst) {

  int i,j,k,x,y,z1,z2,a;
  for (int i = 0; i < dim; i++) {
      for (int j = i+1; j < dim; j++) {
          a = src2[i*dim+j];
          src2[i*dim+j] = src2[j*dim+i];
          src2[j*dim+i] = a;
      }
  }
  for(i = 0; i < dim; i++) {
    x=i*dim;
    for(j = 0; j < dim; j++) {
      y=j*dim;
      a=0;
      if (!(dim%64)) {
      for(k = 0; k < dim; k+=64) {
        z1=x+k;
        z2=y+k;
        a+=src[z1]*src2[z2];
        a+=src[z1+1]*src2[z2+1];
        a+=src[z1+2]*src2[z2+2];
        a+=src[z1+3]*src2[z2+3];
        a+=src[z1+4]*src2[z2+4];
        a+=src[z1+5]*src2[z2+5];
        a+=src[z1+6]*src2[z2+6];
        a+=src[z1+7]*src2[z2+7];
        a+=src[z1+8]*src2[z2+8];
        a+=src[z1+9]*src2[z2+9];
        a+=src[z1+10]*src2[z2+10];
        a+=src[z1+11]*src2[z2+11];
        a+=src[z1+12]*src2[z2+12];
        a+=src[z1+13]*src2[z2+13];
        a+=src[z1+14]*src2[z2+14];
        a+=src[z1+15]*src2[z2+15];
        a+=src[z1+16]*src2[z2+16];
        a+=src[z1+17]*src2[z2+17];
        a+=src[z1+18]*src2[z2+18];
        a+=src[z1+19]*src2[z2+19];
        a+=src[z1+20]*src2[z2+20];
        a+=src[z1+21]*src2[z2+21];
        a+=src[z1+22]*src2[z2+22];
        a+=src[z1+23]*src2[z2+23];
        a+=src[z1+24]*src2[z2+24];
        a+=src[z1+25]*src2[z2+25];
        a+=src[z1+26]*src2[z2+26];
        a+=src[z1+27]*src2[z2+27];
        a+=src[z1+28]*src2[z2+28];
        a+=src[z1+29]*src2[z2+29];
        a+=src[z1+30]*src2[z2+30];
        a+=src[z1+31]*src2[z2+31];
        a+=src[z1+32]*src2[z2+32];
        a+=src[z1+33]*src2[z2+33];
        a+=src[z1+34]*src2[z2+34];
        a+=src[z1+35]*src2[z2+35];
        a+=src[z1+36]*src2[z2+36];
        a+=src[z1+37]*src2[z2+37];
        a+=src[z1+38]*src2[z2+38];
        a+=src[z1+39]*src2[z2+39];
        a+=src[z1+40]*src2[z2+40];
        a+=src[z1+41]*src2[z2+41];
        a+=src[z1+42]*src2[z2+42];
        a+=src[z1+43]*src2[z2+43];
        a+=src[z1+44]*src2[z2+44];
        a+=src[z1+45]*src2[z2+45];
        a+=src[z1+46]*src2[z2+46];
        a+=src[z1+47]*src2[z2+47];
        a+=src[z1+48]*src2[z2+48];
        a+=src[z1+49]*src2[z2+49];
        a+=src[z1+50]*src2[z2+50];
        a+=src[z1+51]*src2[z2+51];
        a+=src[z1+52]*src2[z2+52];
        a+=src[z1+53]*src2[z2+53];
        a+=src[z1+54]*src2[z2+54];
        a+=src[z1+55]*src2[z2+55];
        a+=src[z1+56]*src2[z2+56];
        a+=src[z1+57]*src2[z2+57];
        a+=src[z1+58]*src2[z2+58];
        a+=src[z1+59]*src2[z2+59];
        a+=src[z1+60]*src2[z2+60];
        a+=src[z1+61]*src2[z2+61];
        a+=src[z1+62]*src2[z2+62];
        a+=src[z1+63]*src2[z2+63];
      }
    }
      else if(!(dim%32)) {
        for(k = 0; k < dim; k+=32) {
          z1=x+k;
          z2=y+k;
          a+=src[z1]*src2[z2];
          a+=src[z1+1]*src2[z2+1];
          a+=src[z1+2]*src2[z2+2];
          a+=src[z1+3]*src2[z2+3];
          a+=src[z1+4]*src2[z2+4];
          a+=src[z1+5]*src2[z2+5];
          a+=src[z1+6]*src2[z2+6];
          a+=src[z1+7]*src2[z2+7];
          a+=src[z1+8]*src2[z2+8];
          a+=src[z1+9]*src2[z2+9];
          a+=src[z1+10]*src2[z2+10];
          a+=src[z1+11]*src2[z2+11];
          a+=src[z1+12]*src2[z2+12];
          a+=src[z1+13]*src2[z2+13];
          a+=src[z1+14]*src2[z2+14];
          a+=src[z1+15]*src2[z2+15];
          a+=src[z1+16]*src2[z2+16];
          a+=src[z1+17]*src2[z2+17];
          a+=src[z1+18]*src2[z2+18];
          a+=src[z1+19]*src2[z2+19];
          a+=src[z1+20]*src2[z2+20];
          a+=src[z1+21]*src2[z2+21];
          a+=src[z1+22]*src2[z2+22];
          a+=src[z1+23]*src2[z2+23];
          a+=src[z1+24]*src2[z2+24];
          a+=src[z1+25]*src2[z2+25];
          a+=src[z1+26]*src2[z2+26];
          a+=src[z1+27]*src2[z2+27];
          a+=src[z1+28]*src2[z2+28];
          a+=src[z1+29]*src2[z2+29];
          a+=src[z1+30]*src2[z2+30];
          a+=src[z1+31]*src2[z2+31];
      }
    }
      else {
      for(k = 0; k < dim; k+=2) {
        a+=src[x+k]*src2[y+k];
        a+=src[x+k+1]*src2[y+k+1];
      }
      }
            dst[x+j]=a;
          }
        }
    for (int i = 0; i < dim; i++) {
        for (int j = i+1; j < dim; j++) {
            a = src2[i*dim+j];
            src2[i*dim+j] = src2[j*dim+i];
            src2[j*dim+i] = a;
        }
    }
}


/*********************************************************************
 * register_matrix_multiplication_functions - Register all of your different versions
 *     of the matrix multiplication  with the driver by calling the
 *     add_matrix_multiplication_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.
 *********************************************************************/

void register_matrix_multiplication_functions() {
    add_matrix_multiplication_function(&naive_matrix_multiplication, naive_matrix_multiplication_descr);
    add_matrix_multiplication_function(&matrix_multiplication, matrix_multiplication_descr);
    /* ... Register additional test functions here */
}
