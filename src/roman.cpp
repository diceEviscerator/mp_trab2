# include "roman.h"

void index_vector (char *numb, int size, int *v_index){
	int i;
	char c_numb;

	for(i=0;i<=size; i++){
		c_numb=numb[i];
		switch (c_numb){
			case 0:
				v_index[i]=0;
				break;
			case 73:
				v_index[i]=1;
				break;
			case 86:
				v_index[i]=2;
				break;
			case 88:
				v_index[i]=3;
				break;
			case 76:
				v_index[i]=4;
				break;
			case 67:
				v_index[i]=5;
				break;
			case 68:
				v_index[i]=6;
				break;
			case 77:
				v_index[i]=7;
				break;
			default:
				v_index[i]=-1;
				break;
		}
	}
	return;
}

int adder (int *v_index, int size){
	int i, result=0;

	for(i=0;i<=size; i++){
		switch(v_index[i]){
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

int subtracter (int *v_index, int size, int result){
	int i;

	for(i=0;i<=size;i++){
		if(i==0){}else{
			if((v_index[i])>(v_index[i-1])){
				switch (v_index[i]){
					case 2:
						result=result-2;
						break;
					case 3:
						result=result-2;
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

int transf_roman (char *numb){
	int result=0, size=0, i=0, eq_char=0, v_index[31];

	size=strlen( numb);
	if(size<=0){
		printf("Erro: string vazia\n"); return -1;
	}
	else{
		for(i=0;i<size; i++){
			if((numb[i]!='I')&&(numb[i]!='V')&&(numb[i]!='X')&&(numb[i]!='L')&&(numb[i]!='C')&&(numb[i]!='D')&&(numb[i]!='M')){
				printf("Erro: string invalida, falha 1\n");
				return -1;
			}
			index_vector(numb, size, v_index);
			if(i>0){
				if(numb[i]==numb[i-1]){
					eq_char++;
					if(eq_char>=3){
						printf("Erro: string invalida, falha 2\n");
						return -1;
					}
					if((eq_char!=0)&&(v_index[i]<v_index[i+1])){
						printf("Erro: string invalida, falha 3\n");
						return -1;
					}
				}else{
					eq_char=0;
				}
			}
			if(v_index[i+1]-v_index[i]>2){
				printf("Erro: string invalida, falha 4\n");
				return -1;
			}
			if((v_index[i+1]==v_index[i])&&(v_index[i]%2==0)){
				printf("Erro: string invalida, falha 5\n");
				return -1;
			}
			if((v_index[i]%2==0)&&(v_index[i+1]%2!=0)&&(v_index[i+1]>v_index[i])){
				printf("Erro: string invalida, falha 6\n");
				return -1;
			}
			
		}
		result=adder(v_index, size);
		result=subtracter(v_index, size, result);
		if(result<=0){
			printf("Erro: string invalida, falha 7\n");
			return -1;
		}
		printf("%d\n", result);
		return result;
	}
	return 0;
}