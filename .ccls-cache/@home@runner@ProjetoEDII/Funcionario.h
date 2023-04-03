// Verifica se o símbolo FUNCIONARIO_H já foi definido, caso contrário, o
// define.
#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

// Inclui a biblioteca de strings do C++ para manipulação de strings.
#include <string>

using namespace std;

// Declaração da classe Funcionario.
class Funcionario {
public:
  // Construtor da classe Funcionario com os parâmetros necessários.
  Funcionario(int excecao, const string nome_completo, const string cargo_base, const string cargo_comissao,
              float renumeracao_mensal, float resto_renumeracao, float renumeracao_bruta, const string unidade,
              const string tp_log, const string logradouro, int numero, const string complemento, const string jornada);

  // Métodos get para acessar os atributos privados da classe.
  int getExcecao() const;
  const string getNome_Completo() const;
  const string getCargo_Base() const;
  const string getCargo_Comissao() const;
  float getRenumeracao_Mensal() const;
  float getResto_Renumeracao() const;
  float getRenumeracao_Bruta() const;
  const string getUnidade() const;
  const string getTipo_Logradouro() const;
  const string getLogradouro() const;
  int getNumero_Logradouro() const;
  const string getComplemento() const;
  const string getJornada() const;

private:
  // Atributos privados da classe Funcionario.
  int excecao;
  const string nome_completo; // Identificação do funcionário.
  const string cargo_base;    // Categoria do funcionário (ex: A, B, C).
  const string cargo_comissao;  // Nome do funcionário.
  int renumeracao_mensal; // Cargo do funcionário.
  int resto_renumeracao;         // Sexo do funcionário (ex: M, F).
  int renumeracao_bruta;         // Idade do funcionário.
  int unidade;    // Salário do funcionário.
  const string tp_log;
  const string logradouro;
  int numero;
  const string complemento;
  const string jornada;
};

// Finaliza a verificação da diretiva de pré-processador.
#endif // FUNCIONARIO_H
