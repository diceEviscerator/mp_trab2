# include "roman.h"

void indexator (char *numb, int size, int *vector_index){
  int i;
  char c_numb;

  for (i=0;i<=size; i++) {
    c_numb=numb[i];
    switch (c_numb) {
      case 0:
        vector_index[i]=0;
        break;
      case 73:
        vector_index[i]=1;
        break;
      case 86:
        vector_index[i]=2;
        break;
      case 88:
        vector_index[i]=3;
        break;
      case 76:
        vector_index[i]=4;
        break;
      case 67:
        vector_index[i]=5;
        break;
      case 68:
        vector_index[i]=6;
        break;
      case 77:
        vector_index[i]=7;
        break;
      default:
        vector_index[i]=-1;
        break;
    }
  }
  return;
}

int adder (int *vector_index, int size) {
  int i, result=0;

  for (i=0;i<=size; i++) {
    switch (vector_index[i]) {
      case 1: 
        result=result+1;
        break;
      case 2:
        result=result+5;
        break;
      case 3:
        result=result+10;
        break;
      case 4:
        result=result+50;
        break;
      case 5:
        result=result+100;
        break;
      case 6:
        result=result+500;
        break;
      case 7:
        result=result+1000;
        break;
      default:
        result=result+0;
        break;
    }
  }
  return result;
}

int subtracter (int *vector_index, int size, int result) {
  int i;

  for (i=0;i<=size;i++) {
    if (i>0) {
      if ((vector_index[i])>(vector_index[i-1])) {
        switch (vector_index[i]) {
          case 2:
            result=result-2;
            break;
          case 3:
            result=result-2;
            break;
          case 4:
            result=result-20;
            break;
          case 5:
            result=result-20;
            break;
          case 6:
            result=result-200;
            break;
          case 7:
            result=result-200;
            break;
          default:
            result=result-0;
            break;
        }
      }
    }
  }
  return result;
}

int transf_roman (char *roman_number) {
  int result=0, size=strlen(roman_number), i=0, j=0, equal_char=0,
     vector_index[31], subtract_case=0;

  if (size<=0) {
    printf("Erro: string vazia\n"); return -1;
  } else {
    for (i=0;i<size; i++) {
      if ((roman_number[i]!='I')&&(roman_number[i]!='V')&&(roman_number[i]!='X')
          &&(roman_number[i]!='L')&&(roman_number[i]!='C')
          &&(roman_number[i]!='D')&&(roman_number[i]!='M')) {
        printf("Erro: string invalida, falha 1\n");
        return -1;
      }
      indexator(roman_number, size, vector_index);
      if (i>0) {
        if (roman_number[i]==roman_number[i-1]) {
          equal_char++;
          if (equal_char>=3) {
            printf("Erro: string invalida, falha 2\n");
            return -1;
          }
          if ((equal_char!=0)&&(vector_index[i]<vector_index[i+1])) {
            printf("Erro: string invalida, falha 3\n");
            return -1;
          }
        } else {
          equal_char=0;
        }
      }
      if (vector_index[i+1]-vector_index[i]>2) {
        printf("Erro: string invalida, falha 4\n");
        return -1;
      }
      if ((vector_index[i+1]==vector_index[i])&&(vector_index[i]%2==0)) {
        printf("Erro: string invalida, falha 5\n");
        return -1;
      }
      if ((vector_index[i]%2==0)&&(vector_index[i+1]%2!=0)
          &&(vector_index[i+1]>vector_index[i])) {
        printf("Erro: string invalida, falha 6\n");
        return -1;
      }
      if (i>0) {
        if ((vector_index[i])>(vector_index[i-1])) {
          subtract_case=vector_index[i];
          for (j=i+1;j<=size;j++){
            if (subtract_case==vector_index[j]) {
              printf("Erro: string invalida, falha 8\n");
              return -1;
            }
          }
        }
      }
    }
    result=adder(vector_index, size);
    result=subtracter(vector_index, size, result);
    if (result<=0) {
      printf("Erro: string invalida, falha 7\n");
      return -1;
    }
    printf("%d\n", result);
    return result;
  }
  return 0;
}