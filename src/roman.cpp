# include "roman.h"

int transf_roman (char *numb){
	int result=0, size=0, i=0, eq_char=0;

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