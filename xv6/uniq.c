#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];
char* result[512];
int Index[512];
char* strings[512];
/*
int IfEveryThingSame(char* lhs,char* lhs){
  if(strlen(lhs) != strlen(rhs)) return 1;
  int i;
  for(i = 0; i < strlen(lhs);++i){
    if
  }
}
*/
void
uniq(int fd, char *name)
{
  int count = 1;
 // int same = 0; // true = 1, false = 0
  int i, n, j;
  int index_num = 1;
  int buf_len = 1;
  Index[0] = -1;
  int s_index = 0;
  // Reading to buf
  //printf(1,"Entering while loop now:\n" );
  while((n = read(fd, buf, sizeof(buf))) > 0){
    // Get A Line index
   // printf(1,"Entering Get A Line Index loop now: \n" );
    for(i = 0; i < n; i++){
      if(buf[i] == '\n' || buf[i] == '\0'){
        Index[index_num] = i;
   //     printf(1,"Index_num: %d \n",Index[index_num]);
        index_num++;
      }
      buf_len++;
    }
    Index[index_num] = buf_len;
    Index[index_num+1] = -1;
   // printf(1,"The buf_len is: %d \n", Index[index_num+1]);

   // printf(1,"Entering Get A Line loop now: \n" );
    //Get lines
    /*
    Either  1.  You might freed some memory that you didn't malloc. 
            2.  you might go past the bounds of an array...
            3.  Didn't call exit()

    Solved
    */
    // -------------------------------------------------
    for(i = 1; i < sizeof(Index); ++i){
      if(Index[i] != -1){
        int strlen = Index[i]-Index[i-1];
        strings[s_index] = (char*) malloc(strlen + 1 );
        // loading from buffer, using index
        

        int temp_index = 0;
        for(j = Index[i-1]+1; j < Index[i]; ++j) {
     //     printf(1,"------------------------------------------------------------\n");
          strings[s_index][temp_index] = buf[j];
      //    printf(1,"just copied %c to index %d %d\n",strings[s_index][temp_index],s_index,temp_index);
          temp_index++;
        }
        

        s_index++;
      }
      else
        break;
    }
  }
  // While Loop ends here
  //---------------------------------------------------
  // Compare string table with result table, if no coincided, append to the result
  //  printf(1,"Entering LOADING TO RESULT loop now: \n" );
    // Compare and Load to result table

    //strcpy(result[0],strings[0]);
    result[0] = (char*) malloc(strlen(strings[0])+1);
    for(i = 0; i < strlen(strings[0]); ++i){
      result[0][i] = strings[0][i];
    }

  //  printf(1,"This is the first line: %s,%s \n",result[0],strings[0]);

    for(i = 1; i < s_index; ++i){
      //printf(1,"*******In Strings we have: %s ***********\n", strings[i]);
      
        //printf(1, "About to compare 2 strings now, with i,j value: %d , %d \n",i,j);
        //printf(1, "About to compare 2 strings now: %s , %s \n",result[j],strings[i]);
        //printf(1,"In j loop now");
        //----------------------------
        //printf(1, "strcmp(result[j],strings[i]) = %d \n", strcmp(result[j],strings[i]) );
        
        if(strcmp(strings[i-1],strings[i]) != 0){  
        //printf(1,"Finished Compare \n");
          // if the last element in our result buffer is still not same as the current line, we add it to result.

       
              //printf(1,"About to LOAD to result!!\n");
              //printf(1,"String Length and i value: %d , %d \n", strlen(strings[i])+1, i);
              
              result[count] = (char*) malloc(strlen(strings[i])+1);
              
              int k;
              for(k = 0; k < strlen(strings[i]); ++k){
                //printf(1,"Inserting String %s \n",strings[i][k]);
                result[count][k] = strings[i][k];
              }
              
              //strcpy(result[count],strings[i]);

   //           printf(1, "########## I am copying %s, %s ###############\n", strings[i],result[count]);
              //result[count-1] = p;
              count++;
            }
      }

  //  printf(1,"EndING \n");

  if(n < 0){
    printf(1, "UNIQ: read error\n");
    exit();
  }

  printf(1, "About to print the result \n");

  // printing result
  for(i = 0; i < count; ++i) {
    printf(1,"Final Output is: %s \n", result[i]);
  }
  exit();
}

int
main(int argc, char *argv[])
{
  printf(1, "Hello Uniq!!!!!!!!!!");
  int fd, i;

  if(argc <= 1){
    uniq(0, "");
    exit();
  }

  for(i = 1; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      printf(1, "in MAIN: unqi: cannot open %s\n", argv[i]);
      exit();
    }
    printf(1, "START UNIQ: %s\n", argv[i]);
    uniq(fd, argv[i]);
    close(fd);
  }
  exit();
}
