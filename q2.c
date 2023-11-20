#include <stdio.h>

// Constante que representa o salário mínimo nacional
#define SALARIO_MINIMO 1400.0

//sexo e o salário de um assalariado
void obterDados(char *sexo, float *salario) {
  printf("Digite o sexo do assalariado (M ou F) ou X para encerrar: ");

  scanf(" %c", sexo); 

  *sexo = toupper(*sexo); 

  while (*sexo != 'M' && *sexo != 'F' && *sexo != 'X') {
    printf("Sexo invalido. Digite novamente: ");
    scanf(" %c", sexo);
    *sexo = toupper(*sexo);
  }
  if (*sexo != 'X') {
    printf("Digite o salario do assalariado: ");
    scanf("%f", salario);
    while (*salario <= 1.0) {
      printf("Salario invalido. Digite novamente: ");
      scanf("%f", salario);
    }
  }
}


char* classificarSalario(float salario) {
  if (salario > SALARIO_MINIMO) {
    return "Acima";
  } else if (salario == SALARIO_MINIMO) {
    return "Igual";
  } else {
    return "Abaixo";
  }
}


char* sexoPorExtenso(char sexo) {
  if (sexo == 'M') {
    return "Masculino";
  } else {
    return "Feminino";
  }
}


void mostrarFinal(char sexo, float salario) {
  printf("O assalariado de sexo %s recebeu um salario de R$ %.2f, que esta %s do salario minimo.\n", sexoPorExtenso(sexo), salario, classificarSalario(salario));
}

// Programa principal
int main() {
  char sexo; 
  float salario; 
  obterDados(&sexo, &salario); 
  while (sexo != 'X') { 
    mostrarFinal(sexo, salario); 
    obterDados(&sexo, &salario); 
  }
  printf("Fim do programa.\n");
  return 0;
}
