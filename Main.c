#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_LENGTH 100
int main()
{
 //Variaveis
 char loop[MAX_LENGTH] = "sim";
 int tentativas = 0;
 srand(time(NULL)); //Semente do numero aleatorio
 int numero_sorteado = rand() % 1000; //Gera o numero sorteado
 while (strcmp(loop, "sim") == 0)
 {
 int chute;

 printf("Digite um numero de 1 a 1000: ");
 scanf("%d", &chute);
 getchar(); //Limpar o "\n"
 //logica do jogo
 if (chute == numero_sorteado)
 {
 printf("Voce acertou!\n");
 printf("Numero de tentativas: %d\n", tentativas);
 // Encerrar o loop
 printf("Deseja jogar novamente? (sim ou nao): ");
 fgets(loop, MAX_LENGTH, stdin);
 loop[strcspn(loop, "\n")] = '\0';
 if (strcmp(loop, "nao") == 0)
 {
 printf("PROGRAMA ENCERRADO!\n");
 break;
 }
 //Sorteio de um novo numero
 numero_sorteado = rand() % 1000;
 tentativas = 0;
 }
 //Condiçoes das dicas
 else if (chute > numero_sorteado)
 {
 printf("Voce digitou um numero maior que o numero secreto:\n");
 tentativas += 1;
 printf("Tentativa de numero %d\n", tentativas);
 }
 else if (numero_sorteado > chute)
 {
 printf("Voce digitou um numero menor que o numero secreto:\n");
 tentativas += 1;
 printf("Tentativa de numero %d\n", tentativas);
 }
 }
 return 0;
}
