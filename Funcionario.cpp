// Inclui o arquivo de cabeçalho da classe Funcionario.
#include "Funcionario.h"

// Implementação do construtor da classe Funcionario.
Funcionario::Funcionario(string nome_completo, string cargo_base, const string cargo_comissao,
              int renumeracao_mensal, int resto_renumeracao, int renumeracao_bruta, int unidade,
              const string tp_log, const string logradouro, int numero, const string complemento, const string jornada)
    : nome_completo(nome_completo), cargo_base(cargo_base), cargo_comissao(cargo_comissao),
      renumeracao_mensal(renumeracao_mensal), resto_renumeracao(resto_renumeracao), renumeracao_bruta(renumeracao_bruta), unidade(unidade),
      tp_log(tp_log), logradouro(logradouro), numero(numero), complemento(complemento), jornada(jornada) {}

// Implementação dos métodos get para acessar os atributos privados da classe.
int Funcionario::getExcecao() const { return excecao; }
// Retorna o valor do atributo nome_completo.
const string Funcionario::getNome_Completo() const { return nome_completo; }

// Retorna o valor do atributo cargo_base.
const string Funcionario::getCargo_Base() const { return cargo_base; }

// Retorna uma referência constante ao atributo nome.
const string Funcionario::getCargo_Comissao() const { return cargo_comissao; }

// Retorna uma referência constante ao atributo cargo.
float Funcionario::getRenumeracao_Mensal() const { return renumeracao_mensal; }

// Retorna o valor do atributo sexo.
float Funcionario::getResto_Renumeracao() const { return resto_renumeracao; }

// Retorna o valor do atributo idade.
float Funcionario::getRenumeracao_Bruta() const { return renumeracao_bruta; }

// Retorna o valor do atributo salario.
const string  Funcionario::getUnidade() const { return unidade; }

const string Funcionario::getTipo_Logradouro() const { return tp_log; }

const string Funcionario::getLogradouro() const { return logradouro; }

int Funcionario::getNumero_Logradouro() const { return numero; }

const string Funcionario::getComplemento() const { return complemento; }

const string Funcionario::getJornada() const { return jornada; }
