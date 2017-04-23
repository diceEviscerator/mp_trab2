# include "roman.h"

void indexator (char *numb, int size, int *vector_index){//converte a string num vetor de inteiros com um numero associado ao valor de cada caractere
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

int adder (int *vector_index, int size) {//soma o valor de todos os caracteres da string
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

int subtracter (int *vector_index, int size, int result) {//detecta subtrações necessárias e as realiza
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
    for (i=0;i<size; i++) {//detecta strings com caracteres inválidos
      if ((roman_number[i]!='I')&&(roman_number[i]!='V')&&(roman_number[i]!='X')
          &&(roman_number[i]!='L')&&(roman_number[i]!='C')
          &&(roman_number[i]!='D')&&(roman_number[i]!='M')) {
        printf("Erro: string invalida, caracteres invalidos na string\n");
        return -1;
      }
      indexator(roman_number, size, vector_index);
      if (i>0) {//impede que o programa tente acessar partes inexistentes do vetor
        if (roman_number[i]==roman_number[i-1]) {//parte conta casos de caracteres iguais seguidos, indica um erro se houverem muitos
          equal_char++;
          if (equal_char>=3) {
            printf("Erro: string invalida, muitos caracteres iguais seguidos\n");
            return -1;
          }
          if ((equal_char!=0)&&(vector_index[i]<vector_index[i+1])) {// usa da parte anterior para evitar strings como "IIV"
            printf("Erro: string invalida, caractere menor seguido de caractere subtraido\n");
            return -1;
          }
        } else {
          equal_char=0;//reinicia a contagem de caracteres iguais para o caso de novos caracteres repetidos indevidamente
        }
      }
      if (vector_index[i+1]-vector_index[i]>2) {//detecta erros de numeros seguidos serem muito distantes
        printf("Erro: string invalida, subtração impossivel\n");
        return -1;
      }
      if ((vector_index[i+1]==vector_index[i])&&(vector_index[i]%2==0)) {//impede strings com "VV", ou "LL"
        printf("Erro: string invalida, 'VV', 'LL' ou 'DD'\n");
        return -1;
      }
      if ((vector_index[i]%2==0)&&(vector_index[i+1]%2!=0)//impede casos de "VX"
          &&(vector_index[i+1]>vector_index[i])) {
        printf("Erro: string invalida, subtração com V, L ou D\n");
        return -1;
      }
      if (i>0) {
        if ((vector_index[i])>(vector_index[i-1])) {//impede numeros já subtraídos de serem usados novamente como, caso haja um IX, um novo X não pode ocorrer novamente
          subtract_case=vector_index[i];//a linha acima detecta casos em que ocorreriam uma subtração, aqui, o caractere cujo valor irá ser subtraído é armazenado
          for (j=i+1;j<=size;j++){//percorre o vetor buscando por caracteres iguais após já subtraído
            if (subtract_case==vector_index[j]) {
              printf("Erro: string invalida, numero já subtraido\n");
              return -1;
            }
          }
        }
        if ((vector_index[i-1]>vector_index[i])//caso de um numero menor entre dois maiores
            &&(vector_index[i]<vector_index[i+1])
            &&(vector_index[i-1]<vector_index[i+1])) {
          printf("Erro: string invalida, numero menor entre dois numeros maiores, sendo o segundo maior\n");
          return -1;
        }
        if ((vector_index[i-1]<vector_index[i])//caso de um numero maior entre dois maiores iguais
            &&(vector_index[i+1]<vector_index[i])
            &&(vector_index[i-1]==vector_index[i+1])){
          printf("Erro: string invalida, numero maior entre numeros menores e iguais\n");
          return -1;
        }
      }
    }
    result=adder(vector_index, size);
    result=subtracter(vector_index, size, result);
    if (result<=0) {//impede erros variados não detectados por outras partes em que o resultado é menor que zero
      printf("Erro: string invalida\n");
      return -1;
    }
    printf("%d\n", result);
    return result;
  }
  return 0;
}