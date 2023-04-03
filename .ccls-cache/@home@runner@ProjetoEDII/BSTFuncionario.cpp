/*
Esta implementação inclui os métodos da classe `BSTFuncionario` que trabalham
com os funcionários armazenados na árvore binária de busca.

- O construtor e o destrutor estão implementados.
- O método `inserir` chama o método `inserirNo`, que insere um funcionário na
árvore de acordo com sua identificação.
- O método `percursoInOrder` chama o método `percursoInOrderNo`, que percorre a
árvore em ordem (in-order) e processa os funcionários usando uma função passada
como argumento.
- Os métodos `calcularGastoSalarios`, `contarFuncionariosPorSexo` e
`contarFuncionariosPorCategoria` utilizam o percurso in-order para calcular o
total de salários, contar funcionários por sexo e categoria, respectivamente.
- O método `exibirFuncionariosPorIdade` também utiliza o percurso in-order para
exibir os funcionários com idade igual ou superior à idade mínima especificada,
utilizando uma função de impressão passada como argumento.
*/

// Inclui o arquivo de cabeçalho da classe BSTFuncionario.
#include "BSTFuncionario.h"

// Implementação do construtor e destrutor da classe BSTFuncionario.
BSTFuncionario::BSTFuncionario() : raiz(nullptr) {}
BSTFuncionario::~BSTFuncionario() {}

// Implementação do método inserir da classe BSTFuncionario.
void BSTFuncionario::inserir(const Funcionario &funcionario) {
  inserirNo(raiz, funcionario);
}

// Implementação do método percursoInOrder da classe BSTFuncionario.
void BSTFuncionario::percursoInOrder(
    std::function<void(const Funcionario &)> processar) const {
  percursoInOrderNo(raiz.get(), processar);
}

// Implementação do construtor da estrutura No da classe BSTFuncionario.
BSTFuncionario::No::No(const Funcionario &funcionario)
    : funcionario(funcionario), esquerda(nullptr), direita(nullptr) {}

// Implementação do método inserirNo da classe BSTFuncionario.
void BSTFuncionario::inserirNo(std::unique_ptr<No> &no,
                               const Funcionario &funcionario) {
  if (!no) {
    no = std::make_unique<No>(funcionario);
  } else if (funcionario.getNome_Completo() <
             no->funcionario.getNome_Completo()) {
    inserirNo(no->esquerda, funcionario);
  } else {
    inserirNo(no->direita, funcionario);
  }
}

// Implementação do método percursoInOrderNo da classe BSTFuncionario.
void BSTFuncionario::percursoInOrderNo(
    No *no, std::function<void(const Funcionario &)> processar) const {
  if (!no) {
    return;
  }

  percursoInOrderNo(no->esquerda.get(), processar);
  processar(no->funcionario);
  percursoInOrderNo(no->direita.get(), processar);
}

// Implementação do método calcularGastoSalarios da classe BSTFuncionario.
double BSTFuncionario::calcularGastoSalarios() const {
  double totalSalarios = 0.0;
  auto processar = [&totalSalarios](const Funcionario &funcionario) {
    totalSalarios += funcionario.getSalario();
  };
  percursoInOrder(processar);
  return totalSalarios;
}

// Implementação do método contarFuncionariosPorSexo da classe BSTFuncionario.
int BSTFuncionario::contarFuncionariosPorSexo(char sexo) const {
  int totalFuncionarios = 0;
  percursoInOrder([&totalFuncionarios, sexo](const Funcionario &funcionario) {
    if (funcionario.getSexo() == sexo) {
      totalFuncionarios++;
    }
  });
  return totalFuncionarios;
}

// Implementação do método contarFuncionariosPorCategoria da classe
// BSTFuncionario.
int BSTFuncionario::contarFuncionariosPorCategoria(char categoria) const {
  int totalFuncionarios = 0;
  percursoInOrder(
      [&totalFuncionarios, categoria](const Funcionario &funcionario) {
        if (funcionario.getCategoria() == categoria) {
          totalFuncionarios++;
        }
      });
  return totalFuncionarios;
}

// Implementação do método exibirFuncionariosPorIdade da classe BSTFuncionario.
void BSTFuncionario::exibirFuncionariosPorIdade(
    int idadeMinima, void (*imprimir)(const Funcionario &)) const {
  percursoInOrder([&idadeMinima, imprimir](const Funcionario &funcionario) {
    if (funcionario.getIdade() >= idadeMinima) {
      imprimir(funcionario);
    }
  });
}
