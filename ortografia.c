//PETERSON WAGNER KAVA DE CARVALHO - GRR 20163053

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DICIONARIO "/usr/share/dict/brazilian"

//funcao para saber se um char eh uma letra do alfabeto (pt-br)
int isLetter (char character)
{
	if (((character >= 'A') && (character <= 'Z')) || ((character >= 'a') && (character <= 'z'))
		|| (character == -64) || (character == -63)  //À Á
		|| (character == -62) || (character == -61)  //Â Ã
		|| (character == -57) || (character == -55)  //Ç É
		|| (character == -54) || (character == -51)  //Ê Í
		|| (character == -45) || (character == -44)  //Ó Ô
		|| (character == -43) || (character == -38)  //Õ Ú
		|| (character == -32) || (character == -31)  //à á
		|| (character == -30) || (character == -29)  //â ã
		|| (character == -25) || (character == -23)  //ç é
		|| (character == -22) || (character == -19)  //ê í
		|| (character == -13) || (character == -12)  //ó ô
		|| (character == -11) || (character == -06)) //õ ú
		return 1;
	else
		return 0;
}

//funcao para ler dicionario
void ledicionario (FILE **dicionario)
{
	*dicionario = fopen (DICIONARIO, "r");
	if (!dicionario)
	{
		perror ("Erro ao abrir arquivo de dicionario") ;
		exit (1) ;
	}
}

//funcao para tornar um char minusculo
//ou nao altera-lo caso ele ja esteja minusculo
char tolower_char (char character)
{
	if (((character >= 'A') && (character <= 'Z'))
		|| (character == -64) || (character == -63)  //À Á
		|| (character == -62) || (character == -61)  //Â Ã
		|| (character == -57) || (character == -55)  //Ç É
		|| (character == -54) || (character == -51)  //Ê Í
		|| (character == -45) || (character == -44)  //Ó Ô
		|| (character == -43) || (character == -38))  //Õ Ú
		return (character + 32);
	else
		return character;
}

//funcao para tornar uma string minuscula
void tolower_string (char *str)
{
	for (int i = 0; str[i] != '\0'; ++i)
		str[i] = tolower_char (str[i]);
}

//funcao para comparar strings, usada por qsort e bsearch
int comparastrings (const void * a, const void * b)
{
	return (strcmp(*(const char **)a, *(const char **)b));
}

int main(int argc, char const *argv[])
{
	FILE *arquivo = NULL;
	char palavra[20], palavra_original[20], caractere;
	char *dicionario[376000], *key;
	int i=0, size=0;

	//lendo dicionario
	ledicionario (&arquivo);

	//armazenando palavras do dicionario na memoria
	//o dicionario sera armazenado em um vetor de ponteiros para strings
	fscanf (arquivo, "%s", palavra);
	for (i = 0; !feof(arquivo); ++i)
	{
		dicionario[i] = malloc (sizeof(char) * strlen (palavra) + 1);

		if (dicionario[i] == 0)
			abort();

		tolower_string (palavra);
		strcpy (dicionario[i], palavra);
		fscanf (arquivo, "%s", palavra);
	}
	size = i;

	//reordenando o dicionario pois ao tornar as palavras minusculas,
	//algumas palavras com inicias maiusculas ficam em lugares incorretos
	qsort (dicionario, size, sizeof(dicionario[0]), comparastrings);


	//tratamento do arquivo de texto
	caractere = getchar();

	while ((!feof(stdin)))
	{
		//avançar ate encontrar uma letra ou o fim da entrada
		while (!(isLetter(caractere)) && (!feof(stdin)))
		{
			putchar (caractere);
			caractere = getchar();
		}

		// encontrou uma letra, ler a palavra
		strcpy (palavra, "");
		i=0;
		while (isLetter(caractere) && (!feof(stdin)))
		{
			palavra[i++] = caractere;
			caractere = getchar();
		}
		palavra[i] = '\0';

		//deixando a palavra lida apenas com letras minusculas
		//e guardando uma copia da palavra original
		strcpy (palavra_original, palavra);
		tolower_string (palavra);

		key = palavra; //ponteiro para a palavra-chave

		//tratar a palavra
		if (strcmp(palavra, "")) //se palavra <> ""
		{
			//se minuscula(palavra) nao esta no dicionario
			if (bsearch (&key, dicionario, siez, sizeof(dicionario[0]), comparastrings) == NULL)
				printf("[%s]", palavra_original);
			else
				printf("%s", palavra_original);
		}
	}

	fclose (arquivo);
	return 0;
}