#include <stdio.h>

// Função que valida a quantidade de peças fabricadas por um funcionário
int validaQuantidade() {
  int qtd;
  printf("Digite a quantidade de pecas fabricadas pelo funcionario ou -1 para encerrar: ");
  scanf("%d", &qtd);
  while (qtd < -1) {
    printf("Quantidade invalida. Digite novamente: ");
    scanf("%d", &qtd);
  }
  return qtd;
}

//  calcula o salário total de um funcionário
float calculaSalario(int qtd) {
  float salario = 600.0; 
  if (qtd > 50 && qtd <= 80) {
    salario += (qtd - 50) * 0.5; 
  } else if (qtd > 80) {
    salario += 30 * 0.5; 
    salario += (qtd - 80) * 0.75; 
  }
  return salario;
}

//  mostra o resultado final para cada funcionário
void mostraFinal(int qtd, float salario) {
  printf("O funcionário que fabricou %d peças recebeu um salário de R$ %.2f\n", qtd, salario);
}

// Programa principal
int main() {
  int qtd; 
  float salario; 
  qtd = validaQuantidade(); 
  while (qtd != -1) { 
    salario = calculaSalario(qtd); 
    mostraFinal(qtd, salario); 
    qtd = validaQuantidade(); 
  }
  printf("Fim do programa.\n");
  return 0;
}