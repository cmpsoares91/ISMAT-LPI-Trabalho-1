/*************************************************
* Programa de conversão de Cadeias genéticas    *
**************************************************
* Autores:            Carlos Soares, nº 21103408 *
*                     Luciano Neves, nº 21100341 *
*                                                *
* Curso:                        Eng. Informática *
* Universidade:                  ISMAT, Portimão *
*                                                *
*                    Versão 1                    *
**************************************************/

/* Livrarias */
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

/* Definição: nº de codões */
#define TAM 61

/* Inicio do programa */
int main(){
	
	/* Os ficheiros que irei utilizar ao longo do programa */
	FILE* dna;
	FILE* comp;
	FILE* rna;
	FILE* prot;
	/* As variaveis auxiliares */
	char n, ch, temp[4]={'\0'}, nomeFicheiro[30];
	int count1 = 0, count2;
	/* A matriz utilizada na opção 3 */
	char* listaCodons[][TAM] = {
		{ "GCU", "GCC", "GCA", "GCG", "CGU", "CGC", "CGA", "CGG", "AGA", "AGG", "AAU", "AAC", "GAU", "GAC",
		  "UGU", "UGC", "CAA", "CAG", "GAA", "GAG", "GGU", "GGC", "GGA", "GGG", "CAU", "CAC", "AUU", "AUC",
		  "AUA", "UUA", "UUG", "CUU", "CUC", "CUA", "CUG", "AAA", "AAG", "AUG", "UUU", "UUC", "CCU", "CCC",
		  "CCA", "CCG", "UCU", "UCC", "UCA", "UCG", "AGU", "AGC", "ACU", "ACC", "ACA", "ACG", "UGG", "UAU",
		  "UAC", "GUU", "GUC", "GUA", "GUG"},
		{ "Ala/A", "Ala/A", "Ala/A", "Ala/A", "Arg/R", "Arg/R", "Arg/R", "Arg/R", "Arg/R", "Arg/R", "Asn/N", "Asn/N", "Asp/D", "Asp/D",
		  "Cys/C", "Cys/C", "Gln/Q", "Gln/Q", "Glu/E", "Glu/E", "Gly/G", "Gly/G", "Gly/G", "Gly/G", "His/H", "His/H", "Ile/I", "Ile/I",
		  "Ile/I", "Leu/L", "Leu/L", "Leu/L", "Leu/L", "Leu/L", "Leu/L", "Lys/K", "Lys/K", "Met/M", "Phe/F", "Phe/F", "Pro/P", "Pro/P",
		  "Pro/P", "Pro/P", "Ser/S", "Ser/S", "Ser/S", "Ser/S", "Ser/S", "Ser/S", "Thr/T", "Thr/T", "Thr/T", "Thr/T", "Trp/W", "Tyr/Y",
		  "Tyr/Y", "Val/V", "Val/V", "Val/V", "Val/V"}
	};
	
	/* Mensagem de inicio e apresentação do programa */
	printf("|----------------------------------------------|\n|Bemvindo ao utilitario de conversao de cadeias|\n|----------------------------------------------|\n|Autores:           Carlos Soares, nr. 21103408|\n|                   Luciano Neves, nr. 21100341|\n|                                              |\n|Curso:                        Eng. Informatica|\n|Universidade:                  ISMAT, Portimao|\n|                                              |\n|                   Versao 1                   |\n|----------------------------------------------|\n");
	/* Ciclo do-while representando as varias opções do menu, solicitando uma opção, e de seguida executa essa opção atravez de um switch-case */
	do{
		printf("\n\nSelecione uma opcao do menu:\n ");
		printf("1-Gerar ficheiro DNA Complemento \n 2-Gerar ficheiro RNA \n 3-Gerar ficheiro Proteinas \n\n [S]air \n\n --> ");
		scanf(" %c",&n);

		switch ( n ){ 
			case '1': {
				/* Pede o nome do ficheiro com a sequência de DNA para input */
				printf("\n\nIntroduza qual o nome do ficheiro em que se encontra a sequencia de dna, exemplo: dna.txt(max: 30 caract.): ");
				scanf(" %s",nomeFicheiro);
				/* Tenta abrir o ficheiro e de seguida controla se foi aberto com sucesso */
				dna = fopen(nomeFicheiro, "r");
				if(!dna){
					printf("\n\nNao foi possivel abrir o ficheiro.");
					break;
				}
				printf("\n\nFoi aberto com sucesso o ficheiro %s.", nomeFicheiro);
				/* Aqui repete o que foi referido nos ultimos dois comentários só que desta vez para o Output, neste caso a sequência de DNA complementar  */
				printf("\n\nIntroduza qual o nome do ficheiro que ira criar(max: 30 caract.): ");
				scanf(" %s",nomeFicheiro);
				comp = fopen(nomeFicheiro, "w");
				if(!comp){
					printf("\n\nNao foi possivel abrir o ficheiro.");
					break;
				}
				printf("\n\nFoi criado com sucesso o ficheiro %s.", nomeFicheiro);
				/* Como os ficheiros foram ambos abertos com sucesso iremos agora escrever o resultado no segundo ficheiro */
				fputs("Sequencia de dna complementar gerada e:\n\n" , comp);
				ch = fgetc(dna); /* Inicializando a variavel auxiliar ao processo com o primeiro caracter do ficheiro */
				while(ch != -1){ /* Um ciclo que ira utilizar todos os caracteres do primeiro ficheiro e escrever as correspondentes no segundo ficheiro */
					if(ch=='A')
						fputc('T', comp);
					else if(ch=='T')
						fputc('A', comp);
					else if(ch=='C')
						fputc('G', comp);
					else if(ch=='G')
						fputc('C', comp);
					else
						fputc('?', comp);
					ch = fgetc(dna);
				}
				/* Se terminar o ciclo fechamos os ficheiros e saimos do switch-case */
				fclose(dna);
				fclose(comp);
				break;
			} 
			case '2': {
				/* Esta opção é identica a primeira opção tendo só uns pequenos pormenores como diferença */
				printf("\n\nIntroduza qual o nome do ficheiro em que se encontra a sequencia de dna, exemplo: dna.txt(max: 30 caract.): ");
				scanf(" %s",nomeFicheiro);
				dna = fopen(nomeFicheiro, "r");
				if(!dna){
					printf("\n\nNao foi possivel abrir o ficheiro.");
					break;
				}
				printf("\n\nFoi aberto com sucesso o ficheiro %s.", nomeFicheiro);
				printf("\n\nIntroduza qual o nome do ficheiro que ira criar(max: 30 caract.): ");
				scanf(" %s",nomeFicheiro);
				rna = fopen(nomeFicheiro, "w");
				if(!rna){
					printf("\n\nNao foi possivel abrir o ficheiro.");
					break;
				}
				printf("\n\nFoi criado com sucesso o ficheiro %s.", nomeFicheiro);

				fputs("Sequencia de rna gerada e:\n\n" , rna);
				ch = fgetc(dna);
				while (ch != EOF ){
					if(ch=='A')
						fputc('U', rna);
					else if(ch=='T')
						fputc('A', rna);
					else if(ch=='C')
						fputc('G', rna);
					else if(ch=='G')
						fputc('C', rna);
					else
						fputc('?', rna);
					ch = fgetc(dna);
				}
				fclose(dna);
				fclose(rna);
				break;
			}
			case '3':{
				/* A primeira parte desta opção (processo de abertura de ficheiros) é identica a primeira opção */
				printf("\n\nIntroduza qual o nome do ficheiro em que se encontra a sequencia de rna, exemplo: rna.txt(max: 30 caract.): ");
				scanf(" %s",nomeFicheiro);
				rna = fopen(nomeFicheiro, "r");
				if(!rna){
					printf("\n\nNao foi possivel abrir o ficheiro.");
					break;
				}
				printf("\n\nFoi aberto com sucesso o ficheiro %s.", nomeFicheiro);
				/* O utilizador aqui tem ter cuidado em não utilizar o ficheiro gerado com a segunda opção sem a modificar deixando la só a sequência de aminoácidos */
				printf("\n\nIntroduza qual o nome do ficheiro que ira criar(max: 30 caract.): ");
				scanf(" %s",nomeFicheiro);
				prot = fopen(nomeFicheiro, "w");
				if(!prot){
					printf("\n\nNao foi possivel abrir o ficheiro.");
					break;
				}
				printf("\n\nFoi criado com sucesso o ficheiro %s.", nomeFicheiro);

				fputs("A proteina gerada é:\n\n",prot);
				while((ch = fgetc(rna)) != EOF){ /* Ciclo: inicializa a variavel auxiliar cada vez que entra outra vez no ciclo  */
					if(count1 < 3){	/* Utiliza-se um contador para formar guardar de 3 em 3 caracteres para poder utilizar no ciclo a seguir */
						temp[count1] = ch;
						count1++;	
					}
					if(count1 == 3) { /* Aqui ja temos um vector com 3 caracteres para comparar com os codões presentes na matriz */
						for(count2 = 0; count2 < TAM; count2++){ /* O ciclo faz com que passamos pelos codões todos */
							if(strcmp(temp, listaCodons[0][count2]) == 0){ /* A função strcmp(char* s1, char* s2) compara duas strings e devolve 0 se forem iguais */
								fputs(listaCodons[1][count2], prot); /* Impressão dos resultados */
								fputs("; ",prot);
							}
						}
						count1 = 0;
					}
				}
				/* Fecho dos ficheiros como nas outras opções */
				fclose(rna);
				fclose(prot);
				break;
			} 
			case 's': 
			case 'S':{
				/* A opção para sair do programa */
				printf("\nO programa vai fechar.");
				n = -1; /* Termina o ciclo do-while */
				break;
			} 
			default : /* Uma mensagem de erro caso introduzam uma opção errada */
				printf ("\n\nErro: %c e' opcao invalida\n", n);
		}
		printf("\n\n");
		system("PAUSE");
	}while (n!=-1); /* O menu continua a aparecer enquanto o valor de n é diferente de -1 */
  
    return 0;
}
