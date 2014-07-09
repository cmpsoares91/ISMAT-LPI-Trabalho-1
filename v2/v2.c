/*************************************************
* Programa de conversão de Cadeias genéticas    *
**************************************************
* Autores:            Carlos Soares, nº 21103408 *
*                     Luciano Neves, nº 21100341 *
*                                                *
* Curso:                        Eng. Informática *
* Universidade:                  ISMAT, Portimão *
*                                                *
*                    Versão 2                    *
**************************************************/

/* Livrarias */
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

/* Definição: nº de codões */
#define TAM 64

/* Inicio do programa */
int main(){
	
	/* Os ficheiros que irei utilizar ao longo do programa */
	FILE* dna;
	FILE* comp;
	FILE* rna;
	FILE* prot;
	/* As variaveis auxiliares */
	char n, ch, temp[4]={'\0'}, nomeFicheiro[30];
	int count1 = 0, count2, flag, flag2=1;
	/* A matriz utilizada na opção 3 */
	char* listaCodons[][TAM] = {
		{ "GCT", "GCC", "GCA", "GCG", "CGT", "CGC", "CGA", "CGG", "AGA", "AGG", "AAT", "AAC", "GAT", "GAC",
		  "TGT", "TGC", "CAA", "CAG", "GAA", "GAG", "GGT", "GGC", "GGA", "GGG", "CAT", "CAC", "ATT", "ATC",
		  "ATA", "TTA", "TTG", "CTT", "CTC", "CTA", "CTG", "AAA", "AAG", "ATG", "TTT", "TTC", "CCT", "CCC",
		  "CCA", "CCG", "TCT", "TCC", "TCA", "TCG", "AGT", "AGC", "ACT", "ACC", "ACA", "ACG", "TGG", "TAT",
		  "TAC", "GTT", "GTC", "GTA", "GTG","TAA","TAG","TGA"},
		{ "Ala/A", "Ala/A", "Ala/A", "Ala/A", "Arg/R", "Arg/R", "Arg/R", "Arg/R", "Arg/R", "Arg/R", "Asn/N", "Asn/N", "Asp/D", "Asp/D",
		  "Cys/C", "Cys/C", "Gln/Q", "Gln/Q", "Glu/E", "Glu/E", "Gly/G", "Gly/G", "Gly/G", "Gly/G", "His/H", "His/H", "Ile/I", "Ile/I",
		  "Ile/I", "Leu/L", "Leu/L", "Leu/L", "Leu/L", "Leu/L", "Leu/L", "Lys/K", "Lys/K", "Met/M", "Phe/F", "Phe/F", "Pro/P", "Pro/P",
		  "Pro/P", "Pro/P", "Ser/S", "Ser/S", "Ser/S", "Ser/S", "Ser/S", "Ser/S", "Thr/T", "Thr/T", "Thr/T", "Thr/T", "Trp/W", "Tyr/Y",
		  "Tyr/Y", "Val/V", "Val/V", "Val/V", "Val/V","\"Ocre\"(Stop)","\"Âmbar\"(Stop)","\"Opala\"(Stop)"}
	};
	/* Mensagem de inicio e apresentação do programa */
	printf("|----------------------------------------------|\n|Bemvindo ao utilitario de conversao de cadeias|\n|----------------------------------------------|\n|Autores:           Carlos Soares, nr. 21103408|\n|                   Luciano Neves, nr. 21100341|\n|                                              |\n|Curso:                        Eng. Informatica|\n|Universidade:                  ISMAT, Portimao|\n|                                              |\n|                   Versao 2                   |\n|----------------------------------------------|\n");
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
				/* A primeira parte desta opção (processo de abertura de ficheiros) é identica a primeira opção */
				printf("\n\nIntroduza qual o nome do ficheiro em que se encontra a sequencia de dna(max: 30 caract.): ");
				scanf(" %s",nomeFicheiro);
				dna = fopen(nomeFicheiro, "r");
				if(!dna){
					printf("\n\nNao foi possivel abrir o ficheiro.");
					break;
				}
				printf("\n\nFoi aberto com sucesso o ficheiro %s.", nomeFicheiro);
				printf("\n\nIntroduza qual o nome do ficheiro que ira criar, exemplo: dna.txt(max: 30 caract.): ");
				scanf(" %s",nomeFicheiro);
				rna = fopen(nomeFicheiro, "w");
				if(!rna){
					printf("\n\nNao foi possivel abrir o ficheiro.");
					break;
				}
				printf("\n\nFoi criado com sucesso o ficheiro %s.", nomeFicheiro);
				/* Este ciclo é identico ao da primeira opção, sendo a diferença na forma como é trabalhado a informção */
				fputs("Sequencia de rna gerada e:\n\n" , rna);
				ch = fgetc(dna);
				while (ch != EOF ){
					if(ch == 'T'){	/* Copiamos o ficheiro e onde encontramos 'T's trocamo-los por 'U's */
						ch='U';
					}
					fputc(ch , rna);
					ch = fgetc(dna);
				}
				/* Fecho dos ficheiros como nas outras opções */
				fclose(dna);
				fclose(rna);
				break;
			}
			case '3':{
			/* A primeira parte desta opção (processo de abertura de ficheiros) é identica a primeira opção */
				printf("\n\nIntroduza qual o nome do ficheiro em que se encontra a sequencia de dna, exemplo: dna.txt(max: 30 caract.): ");
				scanf(" %s",nomeFicheiro);
				rna = fopen(nomeFicheiro, "r");
				if(!rna){
					printf("\n\nNao foi possivel abrir o ficheiro.");
					break;
				}
				printf("\n\nFoi aberto com sucesso o ficheiro %s.", nomeFicheiro);
				printf("\n\nIntroduza qual o nome do ficheiro que ira criar(max: 30 caract.): ");
				scanf(" %s",nomeFicheiro);
				prot = fopen(nomeFicheiro, "w");
				if(!prot){
					printf("\n\nNao foi possivel abrir o ficheiro.");
					break;
				}
				printf("\n\nFoi criado com sucesso o ficheiro %s.", nomeFicheiro);
				/* Ciclo corre enquanto não chegou ao final do ficheiro ou a flag2 de stop for igualada a 0 */
				while(((ch = fgetc(dna)) != EOF)&&(flag2)){
					if(flag){ /* Este flag é de iniciação, enquanto esta é igual a 1, procura o codão de iniciação */
						for(count2=0;count2<3;count2++){ /* Neste ciclo forma se um vector com 3 caracteres do ficheiro */
							ch = fgetc(dna);
							temp[count2]=ch;
							if(strcmp(temp, "ATG") == 0){ /* Compara com o codão de iniciação, com a função strcmp(char* s1, char* s2) */
								fputs("A proteina gerada é:\n\nMet/M; ",prot); /* Se encontrar o codão de iniciação inprime no segundo ficheiro o primeiro ficheiro e iguala flag a 0 */
								flag=0;
							}
							else if((count2==2) && (flag)){ /* Enquanto não encontra o codão start, apaga o caracter mais antigo e desvia os outros para poder la colocar um novo */
								for(count1=0;count1<3;count1++){
									temp[count1]=temp[count1+1];
								}
								count2--; /* depois abaixa o contador um valor para não sair do ciclo */
							}
						}
						count1=0; /* Se tiver encontrado o codão de iniciação coloca o count1 a 0 para reutiliza la a seguir. */
					}
					else{
						/* Como ja foi encontrado o codão de iniciação reutiliza-se as variaveis utilizadas anteriormente */
						if(count1 < 3){ /* Utiliza-se um contador para formar guardar de 3 em 3 caracteres para poder utilizar no ciclo a seguir */
							temp[count1] = ch;
							count1++;	
						}
						if(count1 == 3){ /* Aqui ja temos um vector com 3 caracteres para comparar com os codões presentes na matriz */
							for(count2 = 0; count2 < TAM; count2++){ /* O ciclo faz com que passamos pelos codões todos */
								if(strcmp(temp, listaCodons[0][count2]) == 0){ /* A função strcmp(char* s1, char* s2) compara duas strings e devolve 0 se forem iguais */
									fputs(listaCodons[1][count2], prot); /* Impressão dos resultados */
									fputs("; ",prot);
									if((strcmp(temp,"TAA")&&strcmp(temp,"TAG")&&strcmp(temp,"TGA")) == 0){ /* Depois ainda controla se alguem deles é um codão de finalização para poder terminar o processo todo */
										flag2=0; /* Se encontrar um dos 3 codões de finaliza, termina o ciclo principal */
									}
								}
							}
							count1 = 0; /* Impressão dos resultados */
						}
					}
				}
				/* Fecho dos ficheiros como nas outras opções */
				fclose(dna);
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
