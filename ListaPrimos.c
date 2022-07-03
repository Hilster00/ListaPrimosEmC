#include <stdio.h>
#include <stdlib.h>

/*
Este algoritmo utiliza os proprios primos encontrados para verificar se o valor é primo,
com base no principio matemático de que todo valor n não primo tera um divisor m, e esse m terá um divisor o ...
isso até chegar em um numero primo
e outro principio que um valor n nao pode ser dividido por (n/2)+1 ou (n/2)+2 ... (n/2)+(n-1)
com isso reduzindo muito os valores que serao usados para a verificacao
*/

void main(){
	int quantidade=0;
	
	//tratamento para receber apenas uma quantidade valida
	while(quantidade<1){
		system("cls");
		printf("Digite a quantidade de primos que deseja encontrar:");
		scanf("%i",&quantidade);
	}
	
	//criacao da lista e set do primeiro primo
	int lista_primos[quantidade];
	lista_primos[0]=2;
	
	//i representa a quantidade de primos encontrados, e x o valor de verificacao se e primo
	int i=1,x=3,j,validado,quantidade_verificacos=0;
	
	//laco que encerra assim que a lista for preenchida
	while(i!=quantidade){
		
		//validacao que verifica se ouve uma divisao
		validado=1;
		
		//percorre os elementos da lista a partir do segundo e somente até o meio dela
		quantidade_verificacos=quantidade_verificacos+1;
		for(j=1;j<i/2;j++){
			//verifica se o valor e divisivel por um elemento da lista
			if(x%lista_primos[j]==0){
				validado=0;
				break;
			}
			//atualiza a quantidade de verificacoes feitas
			quantidade_verificacos=quantidade_verificacos+1;
		}
		
		//verifica se ocorreu uma divisao
		if(validado==1){
			//adiciona um novo primo a lista e atualiza a quantidade de primos encontrados
			lista_primos[i]=x;
			i++;
		}
		//incrementa o valor de verifica em dois para pular os pares
		x++;
		x++;
	}
	

	system("cls");
	printf("Os %i primeiros primos sao:",quantidade);
	//listagem dos primos encontrados
	for(i=0;i<quantidade;i++){
		printf(" %i",lista_primos[i]);
		//tratamento para virgula nao aparecer apos o utlimo elemento
		if(i+1<quantidade){
			printf(",");
		}
	}
	printf("\nForam feitas %i verificacoes",quantidade_verificacos);//quantidade de verificacoes feitas
}
