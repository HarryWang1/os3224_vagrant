#include "types.h"
#include "stat.h"
#include "user.h"

char buf[512];
char* result[512];
int Index[512];
char* strings[512];

void
uniq(int fd, char *name)
{
  int count = 1;
  int i, n, j;
  int index_num = 1;
  int buf_len = 1;
  Index[0] = -1;
  int s_index = 0;
  printf(1,"Entering while loop now:\n" );
  while((n = read(fd, buf, sizeof(buf))) > 0){
    printf(1,"Entering Get A Line Index loop now: \n" );
    for(i = 0; i < n; i++){
      if(buf[i] == '\n' || buf[i] == '\0'){
        Index[index_num] = i;
        printf(1,"Index_num: %d \n",Index[index_num]);
        index_num++;
      }
      buf_len++;
    }
    Index[index_num] = buf_len;
    Index[index_num+1] = -1;
    printf(1,"The buf_len is: %d \n", Index[index_num+1]);

    printf(1,"Entering Get A Line loop now: \n" );
    
    for(i = 1; i < sizeof(Index); ++i){
      if(Index[i] != -1){
        int strlen = Index[i]-Index[i-1];
        strings[s_index] = (char*) malloc(strlen + 1 );        

        int temp_index = 0;
        for(j = Index[i-1]+1; j < Index[i]; ++j) {
          strings[s_index][temp_index] = buf[j];
          temp_index++;
        }
        

        s_index++;
      }
      else
        break;
    }
  }
      
    result[0] = (char*) malloc(strlen(strings[0])+1);
    for(i = 0; i < strlen(strings[0]); ++i){
      result[0][i] = strings[0][i];
    }

    for(i = 1; i < s_index; ++i){
      
        
        if(strcmp(strings[i-1],strings[i]) != 0){  
              
              result[count] = (char*) malloc(strlen(strings[i])+1);
              
              int k;
              for(k = 0; k < strlen(strings[i]); ++k){
                result[count][k] = strings[i][k];
              }
              
              count++;
            }
      }


  if(n < 0){
    printf(1, "UNIQ: read error\n");
    exit();
  }

  // printing result
  for(i = 0; i < count; ++i) {
    printf(1," %s \n", result[i]);
  }
  exit();
}

void
uniq_c(int fd, char *name)
{
  int count = 1;
  int i, n, j;
  int index_num = 1;
  int buf_len = 1;
  Index[0] = -1;
  int s_index = 0;
  while((n = read(fd, buf, sizeof(buf))) > 0){
    for(i = 0; i < n; i++){
      if(buf[i] == '\n' || buf[i] == '\0'){
        Index[index_num] = i;
        index_num++;
      }
      buf_len++;
    }
    Index[index_num] = buf_len;
    Index[index_num+1] = -1;
    
    for(i = 1; i < sizeof(Index); ++i){
      if(Index[i] != -1){
        int strlen = Index[i]-Index[i-1];
        strings[s_index] = (char*) malloc(strlen + 1 );

        int temp_index = 0;
        for(j = Index[i-1]+1; j < Index[i]; ++j) {
          strings[s_index][temp_index] = buf[j];
          temp_index++;
        }
        

        s_index++;
      }
      else
        break;
    }
  }
    result[0] = (char*) malloc(strlen(strings[0])+1);
    for(i = 0; i < strlen(strings[0]); ++i){
      result[0][i] = strings[0][i];
    }
    for(i = 1; i < s_index; ++i){
        if(strcmp(strings[i-1],strings[i]) != 0){  
              result[count] = (char*) malloc(strlen(strings[i])+1);
              int k;
              for(k = 0; k < strlen(strings[i]); ++k){
                result[count][k] = strings[i][k];
              }
              count++;
            }
      }
  if(n < 0){
    printf(1, "UNIQ: read error\n");
    exit();
  }
  for(i = 0; i < count; ++i) {
    int occurrance = 1;
    for(j = i; j < s_index-1; ++j){
      if(strcmp(strings[j],result[i]) == 0){
        if(strcmp(strings[j],strings[j+1]) == 0) occurrance++;
        else break;
      }
    }
    printf(1,"%d  %s \n", occurrance, result[i]);
  }
  exit();
}

void
uniq_d(int fd, char *name)
{
  int count = 1;
  int i, n, j;
  int index_num = 1;
  int buf_len = 1;
  Index[0] = -1;
  int s_index = 0;
  while((n = read(fd, buf, sizeof(buf))) > 0){
    for(i = 0; i < n; i++){
      if(buf[i] == '\n' || buf[i] == '\0'){
        Index[index_num] = i;
        index_num++;
      }
      buf_len++;
    }
    Index[index_num] = buf_len;
    Index[index_num+1] = -1;
    
    for(i = 1; i < sizeof(Index); ++i){
      if(Index[i] != -1){
        int strlen = Index[i]-Index[i-1];
        strings[s_index] = (char*) malloc(strlen + 1 );

        int temp_index = 0;
        for(j = Index[i-1]+1; j < Index[i]; ++j) {
          strings[s_index][temp_index] = buf[j];
          temp_index++;
        }
        

        s_index++;
      }
      else
        break;
    }
  }
    result[0] = (char*) malloc(strlen(strings[0])+1);
    for(i = 0; i < strlen(strings[0]); ++i){
      result[0][i] = strings[0][i];
    }
    for(i = 1; i < s_index; ++i){
        if(strcmp(strings[i-1],strings[i]) != 0){  
              result[count] = (char*) malloc(strlen(strings[i])+1);
              int k;
              for(k = 0; k < strlen(strings[i]); ++k){
                result[count][k] = strings[i][k];
              }
              count++;
            }
      }
  if(n < 0){
    printf(1, "UNIQ: read error\n");
    exit();
  }
  for(i = 0; i < count; ++i) {
    int occurrance = 1;
    for(j = i; j < s_index-1; ++j){
      if(strcmp(strings[j],result[i]) == 0){
        if(strcmp(strings[j],strings[j+1]) == 0) occurrance++;
        else break;
      }
    }
    if(occurrance > 1)
      printf(1," %s \n",  result[i]);
  }
  exit();
}

void
uniq_i(int fd, char *name)
{
  int count = 1;
  int i, n, j;
  int index_num = 1;
  int buf_len = 1;
  Index[0] = -1;
  int s_index = 0;
  while((n = read(fd, buf, sizeof(buf))) > 0){
    for(i = 0; i < n; i++){
      if(buf[i] == '\n' || buf[i] == '\0'){
        Index[index_num] = i;
        index_num++;
      }
      buf_len++;
    }
    Index[index_num] = buf_len;
    Index[index_num+1] = -1;
    
    for(i = 1; i < sizeof(Index); ++i){
      if(Index[i] != -1){
        int strlen = Index[i]-Index[i-1];
        strings[s_index] = (char*) malloc(strlen + 1 );

        int temp_index = 0;
        for(j = Index[i-1]+1; j < Index[i]; ++j) {
          strings[s_index][temp_index] = buf[j];
          temp_index++;
        }

        s_index++;
      }
      else
        break;
    }
  }
    result[0] = (char*) malloc(strlen(strings[0])+1);
    for(i = 0; i < strlen(strings[0]); ++i){
      result[0][i] = strings[0][i];
    }
    for(i = 1; i < s_index; ++i){
      char *temp_table[2];
      temp_table[0] = (char*) malloc(strlen(strings[i])+1);
      temp_table[1] = (char*) malloc(strlen(strings[i-1])+1);
      int a;
      
      for(a = 0; a < strlen(strings[i]); ++a) {
        if(strings[i][a] < 97) temp_table[0][a] = (strings[i][a])+32;
        else temp_table[0][a] = (strings[i][a]);
      }
      for(a = 0; a < strlen(strings[i-1]); ++a) {
        if(strings[i-1][a] < 97) temp_table[1][a] = (strings[i-1][a]) + 32;
        else temp_table[1][a] = (strings[i-1][a]);
      }
        if(strcmp(temp_table[0],temp_table[1]) != 0){  
              result[count] = (char*) malloc(strlen(strings[i])+1);
              int k;
              for(k = 0; k < strlen(strings[i]); ++k){
                result[count][k] = strings[i][k];
              }
              count++;
            }
      
      }
  if(n < 0){
    printf(1, "UNIQ: read error\n");
    exit();
  }
  for(i = 0; i < count; ++i) 
      printf(1,"%s \n", result[i]);
  
  exit();
}

void
uniq_c_i(int fd, char *name)
{
  int count = 1;
  int i, n, j;
  int index_num = 1;
  int buf_len = 1;
  Index[0] = -1;
  int s_index = 0;
  while((n = read(fd, buf, sizeof(buf))) > 0){
    for(i = 0; i < n; i++){
      if(buf[i] == '\n' || buf[i] == '\0'){
        Index[index_num] = i;
        index_num++;
      }
      buf_len++;
    }
    Index[index_num] = buf_len;
    Index[index_num+1] = -1;
    
    for(i = 1; i < sizeof(Index); ++i){
      if(Index[i] != -1){
        int strlen = Index[i]-Index[i-1];
        strings[s_index] = (char*) malloc(strlen + 1 );

        int temp_index = 0;
        for(j = Index[i-1]+1; j < Index[i]; ++j) {
          strings[s_index][temp_index] = buf[j];
          temp_index++;
        }
        

        s_index++;
      }
      else
        break;
    }
  }
    result[0] = (char*) malloc(strlen(strings[0])+1);
    for(i = 0; i < strlen(strings[0]); ++i){
      result[0][i] = strings[0][i];
    }
    for(i = 1; i < s_index; ++i){
      char *temp_table[2];
      temp_table[0] = (char*) malloc(strlen(strings[i])+1);
      temp_table[1] = (char*) malloc(strlen(strings[i-1])+1);
      int a;
      
      for(a = 0; a < strlen(strings[i]); ++a) {
        if(strings[i][a] < 97) temp_table[0][a] = (strings[i][a])+32;
        else temp_table[0][a] = (strings[i][a]);
      }
      for(a = 0; a < strlen(strings[i-1]); ++a) {
        if(strings[i-1][a] < 97) temp_table[1][a] = (strings[i-1][a]) + 32;
        else temp_table[1][a] = (strings[i-1][a]);
      }
        if(strcmp(temp_table[0],temp_table[1]) != 0){  
              result[count] = (char*) malloc(strlen(strings[i])+1);
              int k;
              for(k = 0; k < strlen(strings[i]); ++k){
                result[count][k] = strings[i][k];
              }
              count++;
            }
      
      }
  if(n < 0){
    printf(1, "UNIQ: read error\n");
    exit();
  }

  char *temp_result[count];
  char *temp_string[s_index];

  for(i = 0; i < count; ++i){
    temp_result[i] = (char*)malloc(strlen(result[i])+1);
    for(j = 0; j < strlen(result[i]); ++j){
      if(result[i][j] < 97)
        temp_result[i][j] = result[i][j] + 32;
      else temp_result[i][j] = result[i][j];
    }
  }
  for(i = 0; i < s_index; ++i){
    temp_string[i] = (char*)malloc(strlen(strings[i])+1);
    for(j = 0; j < strlen(strings[i]); ++j){
      if(strings[i][j] < 97)
        temp_string[i][j] = strings[i][j] + 32;
      else temp_string[i][j] = strings[i][j];
    }
  }
  /*for(j = 0; j < s_index; ++j){
      printf(1,"In string I have: %s \n",strings[j]);
    }
    */
  //int mem = 0;
  for(i = 0; i < count; ++i) {
    int occurrance = 1;
    
    for(j = i; j < s_index-1; ++j){
      if(strcmp(temp_string[j],temp_result[i]) == 0){
        if(strcmp(temp_string[j],temp_string[j+1]) == 0) occurrance++;
        else break;
      }
    }

    printf(1,"%d  %s \n", occurrance, result[i]);
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

  // uniq example.txt checked
  char* extend[3];
  extend[0] = "-c";
  extend[1] = "-d";
  extend[2] = "-i";
  if(strcmp(argv[1],extend[0])!=0 && strcmp(argv[1], extend[1]) != 0 && strcmp(argv[1], extend[2]) != 0) {
      printf(1, "START UNIQ: %s\n", argv[1]);
      for(i = 1; i < argc; ++i){
        if((fd = open(argv[i], 0)) < 0){
          printf(1, "in MAIN: unqi: cannot open %s\n", argv[i]);
          exit();
        }
        uniq(fd, argv[i]);
        close(fd);
      }
    }
  // uniq -c example.txt checked
  else if( strcmp(argv[1], extend[0]) == 0 && strcmp(argv[2], extend[2]) != 0) {
    printf(1, "START UNIQ. -C: %s\n", argv[2]);
    for(i = 2; i < argc; ++i){
      if((fd = open(argv[i], 0)) < 0){
        printf(1, "in MAIN: unqi: cannot open %s\n", argv[i]);
        exit();
      }
      uniq_c(fd, argv[i]);
      close(fd);
    }
  }
  
  // uniq -d example.txt
  else if(strcmp(argv[1],extend[1]) == 0){
      printf(1, "START UNIQ -D: %s\n", argv[2]);
      for(i = 2; i < argc; ++i){
        if((fd = open(argv[i], 0)) < 0){
          printf(1, "in MAIN: unqi: cannot open %s\n", argv[i]);
          exit();
        }
        uniq_d(fd, argv[i]);
        close(fd);
      }
    }
    
    //uniq -i example.txt
   else if(strcmp(argv[1] , extend[2]) == 0){
      printf(1, "START UNIQ -I: %s\n", argv[2]);
      for(i = 2; i < argc; ++i){
        if((fd = open(argv[i], 0)) < 0){
          printf(1, "in MAIN: unqi: cannot open %s\n", argv[i]);
          exit();
        }
        uniq_i(fd, argv[i]);
        close(fd);
      }
   }
   
   // -c. -i
   else if(strcmp(argv[1] , extend[0]) == 0 && strcmp(argv[2] , extend[2]) == 0){
      printf(1, "START UNIQ -I: %s\n", argv[3]);
      for(i = 3; i < argc; ++i){
        if((fd = open(argv[i], 0)) < 0){
          printf(1, "in MAIN: unqi: cannot open %s\n", argv[i]);
          exit();
        }
        uniq_c_i(fd, argv[i]);
        close(fd);
      }
   }

exit();
return 0;
}
