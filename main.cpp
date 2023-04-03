#include "BSTFuncionario.h"
#include "Funcionario.h"
#include "BSTFuncionario.h"
#include "BSTFuncionario.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void ler_arquivo() {
 // Abre o arquivo
    ifstream arquivo("renumeracao01-2023aticriacao20230125(1).csv");

    // Cria uma árvore vazia
    Node* root = nullptr;

    // Lê os dados do arquivo linha por linha
    string linha;
    while (getline(arquivo, linha)) {
        // Usa um stringstream para separar os dados da linha
        stringstream ss(linha);
        string valor;
        while (getline(ss, valor, ';')) {
            // Converte o valor para inteiro e adiciona na árvore
            int data = stoi(valor);
            root = inserir(root, data);
        }
    }

    // Fecha o arquivo
    arquivo.close();
}

// Função auxiliar para imprimir as informações do funcionário
void imprimirFuncionario(const Funcionario &funcionario) {
  cout << "Nome Completo: " << funcionario.getNome_Completo() << endl;
  cout << "Cargo Base: " << funcionario.getCargo_Base() << endl;
  cout << "Cargo em Comissao: " << funcionario.getCargo_Comissao() << endl;
  cout << "Remuneracao do Mes: " << funcionario.getRenumeracao_Mensal() << endl;
  cout << "Demais Elementos da Remuneracao: " << funcionario.getResto_Renumeracao) << endl;
  cout << "Renumeracao Bruta: " << funcionario.getRenumeracao_Bruta() << endl;
  cout << "Unidade: " << funcionario.getUnidade() << endl;
  cout << "Tipo de Logradouro: " << funcionario.getTipo_Logradouro() << endl;
  cout << "Logradouro: " << funcionario.getLogradouro() << endl;
  cout << "Numero: " << funcionario.getNumero_Logradouro() << endl;
  cout << "Complemneto: " << funcionario.getComplemento() << endl;
  cout << "Jornada: " << funcionario.getJornada() << endl;
  cout << endl;
}

int main() {
  // Criação da árvore binária de busca de funcionários
  BSTFuncionario bst;

  // Criação dos funcionários
  Funcionario f1(1, 'P', "João Silva", "Gerente", 'M', 35, 4500.00);
  Funcionario f2(2, 'H', "Maria Santos", "Analista", 'F', 30, 3500.00);
  Funcionario f3(3, 'O', "Carlos Pereira", "Desenvolvedor", 'M', 28, 4000.00);
  Funcionario f4(4, 'H', "Luciana Andrade", "Coordenadora", 'F', 38, 6000.00);
  Funcionario f5(5, 'P', "Maurício Gomes", "Analista Financeiro", 'M', 29,
                 3500.00);
  Funcionario f6(6, 'O', "Fernanda Lima", "Designer Gráfico", 'F', 27, 3000.00);
  Funcionario f7(7, 'H', "Ricardo Souza", "Engenheiro de Software", 'M', 33,
                 5500.00);
  Funcionario f8(8, 'P', "Patrícia Oliveira", "Assistente Administrativo", 'F',
                 25, 2000.00);
  Funcionario f9(9, 'O', "André Almeida", "Redator", 'M', 31, 2800.00);
  Funcionario f10(10, 'H', "Cláudia Costa", "Analista de Marketing", 'F', 34,
                  4000.00);
  // Inserção dos funcionários na árvore
  bst.inserir(f1);
  bst.inserir(f2);
  bst.inserir(f3);
  bst.inserir(f4);
  bst.inserir(f5);
  bst.inserir(f6);
  bst.inserir(f7);
  bst.inserir(f8);
  bst.inserir(f9);
  bst.inserir(f10);

  int opcao;
  do {
    // Exibe o menu de opções
    std::cout << "Menu:" << std::endl;
    std::cout << "1 - Listar funcionários em ordem crescente de ID"
              << std::endl;
    std::cout << "2 - Calcular gasto total com salários" << std::endl;
    std::cout << "3 - Contar funcionários por sexo" << std::endl;
    std::cout << "4 - Contar funcionários por categoria" << std::endl;
    std::cout << "5 - Exibir funcionários com idade maior que a informada"
              << std::endl;
    std::cout << "6 - Adicionar funcionário" << std::endl;
    cout << "7 - Ler o arquivo"
    std::cout << "0 - Sair" << std::endl;
    std::cout << "Digite a opção desejada: ";
    // Lê a opção escolhida pelo usuário
    std::cin >> opcao;

    // Executa a ação correspondente à opção escolhida
    switch (opcao) {
    case 1:
      // Listar funcionários em ordem crescente de ID
      std::cout << "Funcionários em ordem crescente de ID:" << std::endl
                << std::endl;
      bst.percursoInOrder(imprimirFuncionario);
      break;
    case 2: {
      // Calcular gasto total com salários
      double gastoTotalSalarios = bst.calcularGastoSalarios();
      std::cout << "Gasto total com salários: R$" << gastoTotalSalarios
                << std::endl
                << std::endl;
      break;
    }
    case 3: {
      // Contar funcionários por sexo
      char sexo;
      std::cout << "Informe o sexo (F - feminino, M - masculino): ";
      std::cin >> sexo;
      int totalFuncionarios = bst.contarFuncionariosPorSexo(sexo);
      std::cout << "Total de funcionários com sexo " << sexo << ": "
                << totalFuncionarios << std::endl
                << std::endl;
      break;
    }
    case 4: {
      // Contar funcionários por categoria
      char categoria;
      std::cout << "Informe a categoria (P - Presencial, O - Home Office, H - "
                   "Híbrido): ";
      std::cin >> categoria;
      int totalFuncionarios = bst.contarFuncionariosPorCategoria(categoria);
      std::cout << "Total de funcionários na categoria " << categoria << ": "
                << totalFuncionarios << std::endl
                << std::endl;
      break;
    }
    case 5: {
      // Exibir funcionários com idade maior que a informada
      int idade;
      std::cout << "Informe a idade mínima: ";
      std::cin >> idade;
      std::cout << "Funcionários com idade maior que " << idade << ":"
                << std::endl;
      bst.exibirFuncionariosPorIdade(idade, imprimirFuncionario);
      std::cout << std::endl;
      break;
    }
    case 6: {
      // Adicionar funcionário
      string nome_completo, cargo_base, cargo_comissao, unidade, tp_log, complemento, jornada, logradouro;
      float renumeracao_mensal, resto_renumeracao, renumeracao_bruta;
      int numero;

      cout << "Informe o nome completo do funcionario: ";
      cin >> nome_completo;
      cout << "Informe o cargo base do funcionario: ";
      cin >> cargo_base;
      cout << "Informe o cargo em comissao do funcionario: ";
      cin >> cargo_comissao;
      cout << "Informe a renumeracao  do mes do funcionario: ";
      cin >> renumeracao_mensal;
      cout << "Informe os demais elementos da renumeracao do funcionario: ";
      cin >> resto_renumeracao;
      cout << "Informe a renumeracao bruta do funcionario: ";
      cin >> renumeracao_bruta;
      cout << "Informe a unidade do funcionario: ";
      cin >> unidade;
      cout << "Informe o tipo de logradouro do funcionario: ";
      cin >> tp_log;
      cout << "Informe o logradouro do funcionario: ";
      cin >> logradouro;
      cout << "Informe o numero do logradouro do funcioanrio: ";
      cin >> numero;
      cout << "Informe o complemento do logradouro do funcionario: ";
      cin >> complemento;
      cout << "Informe a jornada de trabalho do funcionario: ";
      cin >> jornada;

      Funcionario novoFuncionario(nome_completo, cargo_base, cargo_comissao, renumeracao_mensal, resto_renumeracao, renumeracao_bruta,
                                  unidade, tp_log, logradouro, numero, complemento, jornada);
      bst.inserir(novoFuncionario);

      std::cout << "Funcionário adicionado com sucesso!" << std::endl
                << std::endl;
      break;
    }

    case 7:  {
        // Abre o arquivo
        ifstream arquivo("renumeracao01-2023aticriacao20230125(1).csv");

        // Cria uma árvore vazia
        Node* root = nullptr;

        // Lê os dados do arquivo linha por linha
        string linha;
        while (getline(arquivo, linha)) {
        // Usa um stringstream para separar os dados da linha
        stringstream ss(linha);
        string valor;
        while (getline(ss, valor, ';')) {
            // Converte o valor para inteiro e adiciona na árvore
            int data = stoi(valor);
            root = inserir(root, data);
        }
    }

    // Fecha o arquivo
    arquivo.close();
    }

    case 0:
      // Sair do programa
      std::cout << "Saindo..." << std::endl;
      break;
    default:
      // Opção inválida
      std::cout << "Opção inválida!" << std::endl << std::endl;
      break;
    }
  } while (opcao != 0); // Repete até que a opção "Sair" seja escolhida

  return 0;
}
