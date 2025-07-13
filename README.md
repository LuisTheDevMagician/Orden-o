# Análise de Algoritmos de Ordenação em C

Este projeto implementa e compara três algoritmos clássicos de ordenação (Insertion Sort, Quick Sort e Heap Sort) para organizar uma lista de pessoas por nome. O código foi desenvolvido em C e inclui métricas de desempenho detalhadas.

---

## 📌 Visão Geral

O programa:

* Define uma estrutura `Pessoa` com nome e idade.
* Implementa três algoritmos de ordenação.
* Coleta estatísticas de comparações e trocas.
* Mede o tempo de execução para cada algoritmo.
* Executa testes repetidos para obter médias confiáveis.

---

## 📊 Algoritmos Implementados

### 1. Insertion Sort

* **Complexidade:** $O(n^2)$ no pior caso
* **Características:**
    * Simples de implementar
    * Eficiente para conjuntos pequenos de dados
    * Ordenação **estável**

### 2. Quick Sort

* **Complexidade:** $O(n \log n)$ médio, $O(n^2)$ pior caso
* **Características:**
    * Geralmente o mais rápido na prática
    * Usa divisão e conquista
    * **Não é estável**

### 3. Heap Sort

* **Complexidade:** $O(n \log n)$ em todos os casos
* **Características:**
    * Performance consistente
    * Não requer espaço adicional significativo
    * **Não é estável**

---

## 📈 Métricas Coletadas

Para cada algoritmo, o programa calcula:

* Número médio de **comparações**
* Número médio de **trocas**
* Tempo médio de **execução** em milissegundos

Os testes são repetidos **5 vezes (REPS)** para garantir medições consistentes.

---

## 🛠️ Como Compilar e Executar

Certifique-se de ter um compilador C instalado (GCC recomendado).

1.  **Compile o programa:**
    ```bash
    gcc -o ordenacao algoritmos_ordenacao.c
    ```
2.  **Execute o programa:**
    ```bash
    ./ordenacao
    ```

---

## 📝 Resultados Esperados

O programa irá exibir uma tabela comparativa com as estatísticas médias para cada algoritmo. Espera-se que:

* **Insertion Sort** tenha o maior número de comparações e trocas.
* **Quick Sort** seja o mais rápido na maioria dos casos.
* **Heap Sort** mostre performance consistente entre execuções.

---

## 📂 Estrutura do Código

* `Pessoa`: Struct que armazena nome e idade.
* `Estatisticas`: Struct para contagem de operações.
* **Funções auxiliares:**
    * `comparar_pessoas`: Compara dois registros pelo nome.
    * `trocar`: Troca dois elementos no vetor.
    * `copiar_vetor`: Cria cópias para testes isolados.
* **Funções de ordenação:** Cada uma com sua implementação específica.
* `testar_algoritmo`: Função que padroniza os testes e medições.

---

## 📌 Observações

* O conjunto de dados contém **1000 registros** pré-definidos.
* Para testar com outros dados, modifique o array `pessoas` na função `main`.
* O tamanho do vetor pode ser ajustado alterando a constante `TAM`.

Este projeto serve como base para estudos de algoritmos de ordenação e análise de desempenho em C.
