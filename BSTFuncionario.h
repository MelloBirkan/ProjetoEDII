// Verifica se o símbolo BSTFUNCIONARIO_H já foi definido, caso contrário, o
// define.
#ifndef BSTFUNCIONARIO_H
#define BSTFUNCIONARIO_H

// Inclui o arquivo de cabeçalho da classe Funcionario.
#include "Funcionario.h"
// Inclui a biblioteca para funções funcionais e ponteiros inteligentes.
#include <functional>
#include <memory>

// Declaração da classe BSTFuncionario.
class BSTFuncionario {
public:
  // Construtor e destrutor da classe BSTFuncionario.
  BSTFuncionario();
  ~BSTFuncionario();

  // Métodos públicos da classe BSTFuncionario.
  int contarFuncionariosPorSexo(char sexo) const;
  void exibirFuncionariosPorIdade(int idadeMinima,
                                  void (*imprimir)(const Funcionario &)) const;
  int contarFuncionariosPorCategoria(char categoria) const;
  double calcularGastoSalarios() const;
  void inserir(const Funcionario &funcionario);
  void
  percursoInOrder(std::function<void(const Funcionario &)> processar) const;

private:
  // Declaração da estrutura No.
  struct No {
    Funcionario funcionario;
    std::unique_ptr<No> esquerda;
    std::unique_ptr<No> direita;

    No(const Funcionario &funcionario);
  };

  // Atributo privado da classe BSTFuncionario.
  std::unique_ptr<No> raiz;

  // Métodos privados da classe BSTFuncionario.
  void inserirNo(std::unique_ptr<No> &no, const Funcionario &funcionario);

  void
  percursoInOrderNo(No *no,
                    std::function<void(const Funcionario &)> processar) const;
};

// Finaliza a verificação da diretiva de pré-processador.
#endif // BSTFUNCIONARIO_H
