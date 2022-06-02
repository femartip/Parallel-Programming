/* Ping-pong program */

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define NMAX 1000000
#define NREPS 100

char buf[NMAX];


//Tercer programa, se usan comunicaciones punto a punto para calcular la latencia de la red.
int main(int argc,char *argv[])
{
  int n, myid, numprocs;
   double inicio, fin;

  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD,&myid);

  /* The program takes 1 argument: message size (n), with a default size of 100
     bytes and a maximum size of NMAX bytes*/
  if (argc==2) n = atoi(argv[1]);
  else n = 100;
  if (n<0 || n>NMAX) n=NMAX;

  /* COMPLETE: Get current time, using MPI_Wtime() */
   inicio = MPI_Wtime();

  /* COMPLETE: loop of NREPS iterations.
     In each iteration, P0 sends a message of n bytes to P1, and P1 sends the same
     message back to P0. The data sent is taken from array buf and received into
     the same array. */
   for(int i=0;i<NREPS;i++){     //El programa repite la operacion un numero de veces para que el tiempo sea significativo 
      if(myid==0){
         MPI_Send(buf,n,MPI_BYTE,1,10,MPI_COMM_WORLD );
         MPI_Recv(buf,n,MPI_BYTE,1,10, MPI_COMM_WORLD,MPI_STATUS_IGNORE);
      } 
      else if(myid == 1){
         MPI_Recv(buf,n,MPI_BYTE,0,10, MPI_COMM_WORLD,MPI_STATUS_IGNORE);     //Si se elimina un mensaje de respuesta, esto podira causar interbloqueos.
         MPI_Send(buf,n,MPI_BYTE,0,10,MPI_COMM_WORLD );
      }        //En este caso podemos sustituir en ambas versiones por MPI_Sendrecv_replace porque ambas usan el mismo buffer.
   } 

  /* COMPLETE: Get current time, using MPI_Wtime() */
   fin = MPI_Wtime();

  /* COMPLETE: Only in process 0.
     Compute the time of transmission of a single message (in milliseconds) and print it.
     Take into account there have been NREPS repetitions, and each repetition involves 2
     messages. */
   printf("Tiempo tardado: %f\n", (fin-inicio)/numprocs);
  MPI_Finalize();
  return 0;
}

