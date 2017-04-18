# include "roman.h"

void index_vector (char *numb, int size, int *v_index){
	int i;
	char c_numb;

	for(i=0;i<size; i++){
		c_numb=numb[i];
		switch (c_numb){
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
		}
	}
	return;
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
				printf("Erro: string invalida\n");
				return -1;
			}
			if(i>0){
				if(numb[i]==numb[i-1]){
					eq_char++;
					if(eq_char>=3){
						return -1;
					}
				}else{
					eq_char=0;
				}
			}
		}
		for(i=0;i<size; i++){
			if((numb[i]=='I')){
				result++;
			}
		}
		return result;
	}
	return 0;
}