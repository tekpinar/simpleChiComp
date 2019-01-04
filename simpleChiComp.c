//Purpose  : To make chiSquared test between experimental and theoretical values
//Author   : Mustafa Tekpinar - tekpinar@buffalo.edu
//Date     : 04 May 2011
//Version 2: I removed some unused functions and implemented scattering intensity averaging. 
//Version 3: I added a function for form factor weighted coordinates and a function which 
//           determines the number of atoms in each residue. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
//Personal header files
#include <stat_functions.h>

int main(int argc, char **argv)
{
  if(argc!=6)
    {
      fprintf(stderr,"Usage:./simpleChiComp.exe experimental.dat theoretical.dat min_range max_range fit.dat\n");
      exit(EXIT_FAILURE);
    }

  //  chi_of_data_files(argv[1], argv[2],  1);
  char  *experimentalFile=argv[1];
  char  *theoreticalFile=argv[2];
  double min_range=0.00; 
  double max_range=1.50;
  FILE *FIT_FILE=fopen(argv[5], "w");
  if(FIT_FILE==NULL)
    {
      fprintf(stderr, "ERROR: File %s can not be produced!\n", argv[5]);
      exit(EXIT_FAILURE);
    }

  if(argv[3]!=NULL)
    min_range=atof(argv[3]);

  if(argv[4]!=NULL)
    max_range=atof(argv[4]);

  int    scaleTheoretical=1;/*0: NO, 1:YES*/;
  int    printDetails=0 /*0: NO, 1:YES*/;

  //  chi_of_data_files(experimentalFile, theoreticalFile, scaleTheoretical);

  chi_of_data_files_v3(experimentalFile, theoreticalFile,  min_range, max_range, scaleTheoretical, printDetails, FIT_FILE);

  //For exact data point calculations!  
  //  chi_of_data_files_v2(argv[1], argv[3],  1);
  fclose(FIT_FILE);
  return 0;
}
