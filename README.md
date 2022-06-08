# Parallelization  solutions in C
  
  This repository is a collection of various solutions for problems trying to solve them with multiprocessing. All are done in C language, using two open source libraries: OpenMP and MPI.
  
## OpenMP  
  In this section, the code tries to solve a ransomware  that shuffles images so they are unusable. This ransomware  interchanges rows and columns randomly.
  The code tries to search first by rows, then by columns, which pixels are the most similar for each row/column and rearranges  them. An example is shown above;
  
  ![image](https://user-images.githubusercontent.com/99536660/172684008-bcfe9ddb-916c-43c5-86e2-88bd2466a774.png)

  Different approaches  have been made for computing this problem;
  1. restore1.c -> This version tries to run in parallel the functions that calculates the distance (difference in pixels between two rows/columns), and that swaps rows/columns.
  2. restore2.c -> This other  version tries to run in parallel the loop that searches for the similar row/column and that swaps rows/columns.
  3. restore3.c -> Same implementation as restore2, however this one gives information about how many threads have been made and how many iterations have done.
 
  **Results**-
  -------------------------------------------------------------------------------------------------------
  Performance for each planification;    
![image](https://user-images.githubusercontent.com/99536660/172688090-0e5292b5-f812-4e12-953a-0968229b7cd9.png)
---------------------------------------------------------------------------------------------------------
For all the above results, we have used static planification as is the one that gives better results.
![image](https://user-images.githubusercontent.com/99536660/172688222-b360f315-ee15-49a6-8385-0a9c9badb82e.png)
![image](https://user-images.githubusercontent.com/99536660/172688276-0989b93e-223f-4f02-9092-8926966364bd.png)
![image](https://user-images.githubusercontent.com/99536660/172688320-55ec2f0f-507d-4199-81b4-19640163a712.png)

 
  To run this code: $ ./restore -i image_in.ppm -o image_out.ppm -b block_size    
  Where the options are:      
  -i Input image "default"=in.ppm   
  -o  Output image "default"=out.ppm  If "" no output image will be generated  
  -w  Block width "default"=8  
  -h  Block height "default"=8  
  -b  Block size   
  
  
  OpenMP: https://www.openmp.org/
## MPI
  
  
  
  
  
  MPI: https://www.open-mpi.org/
