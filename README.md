# corretor_ortografico - Trabalho de Oficina de Computação
## Especificação

Este projeto visa implementar um verificador ortográfico, que recebe um texto como entrada e produz o mesmo texto na saída, com as palavras potencialmente incorretas indicadas entre colchetes ([...]). Uma palavra é considerada potencialmente incorreta se não for encontrada em um arquivo de dicionário.

Atividade
Construa um programa para verificar a ortografia das palavras de um texto lido da entrada padrão (stdin). A saída padrão (stdout) deve reproduzir fielmente o texto de entrada, mas colocando as palavras que não estão no dicionário entre colchetes. O dicionário está disponível no arquivo /usr/share/dict/brazilian (em distribuições Linux populares).

Consideram-se palavras como sequências contíguas de letras (A-Z, a-z) com ou sem acentos; os demais caracteres (números, espaços e outros símbolos) não fazem parte de palavras.

Por exemplo, para esta entrada:
```
Para que o pocessador possa interromper a execução de uma tarefa
e retornar a ela mais tarde, sem corromper seu estado interno,
é necessário definir operações para salvar e restaurrar o
contexto da tarefa.

O ato de salvar os valores do contexto atual em seu TCB e
possivelmente restaurar o contexto de outra tarefa, previamente
salvo em outro TCB, é denominado "troca de contexto".
```
O programa deve gerar esta saída:

```
Para que o [pocessador] possa interromper a execução de uma tarefa
e retornar a ela mais tarde, sem corromper seu estado interno, 
é necessário definir operações para salvar e [restaurrar] o
contexto da tarefa.

O ato de salvar os valores do contexto atual em seu [TCB] e
possivelmente restaurar o contexto de outra tarefa, previamente
salvo em outro [TCB], é denominado "troca de contexto".
```

Forma de chamada:

```
./ortografia < entrada.txt > saida.txt
```
