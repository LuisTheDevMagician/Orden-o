#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM 100
#define REPS 5

typedef struct {
    char nome[100];
    int idade;
} Pessoa;

typedef struct {
    long comparacoes;
    long trocas;
} Estatisticas;

// Função de comparação por nome
int comparar_pessoas(const Pessoa *a, const Pessoa *b, Estatisticas *est) {
    est->comparacoes++;
    return strcmp(a->nome, b->nome);
}

// Função para trocar duas pessoas
void trocar(Pessoa *a, Pessoa *b, Estatisticas *est) {
    Pessoa temp = *a;
    *a = *b;
    *b = temp;
    est->trocas++;
}

// --- Algoritmos de ordenação ---

void insertion_sort(Pessoa v[], int n, Estatisticas *est) {
    for (int i = 1; i < n; i++) {
        Pessoa chave = v[i];
        int j = i - 1;
        while (j >= 0 && comparar_pessoas(&v[j], &chave, est) > 0) {
            v[j + 1] = v[j];
            est->trocas++;
            j--;
        }
        v[j + 1] = chave;
        est->trocas++;
    }
}

void quick_sort_rec(Pessoa v[], int low, int high, Estatisticas *est) {
    if (low < high) {
        Pessoa pivo = v[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (comparar_pessoas(&v[j], &pivo, est) <= 0) {
                i++;
                trocar(&v[i], &v[j], est);
            }
        }
        trocar(&v[i + 1], &v[high], est);
        int pi = i + 1;

        quick_sort_rec(v, low, pi - 1, est);
        quick_sort_rec(v, pi + 1, high, est);
    }
}

void quick_sort(Pessoa v[], int n, Estatisticas *est) {
    quick_sort_rec(v, 0, n - 1, est);
}

void heapify(Pessoa v[], int n, int i, Estatisticas *est) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && comparar_pessoas(&v[esq], &v[maior], est) > 0)
        maior = esq;
    if (dir < n && comparar_pessoas(&v[dir], &v[maior], est) > 0)
        maior = dir;

    if (maior != i) {
        trocar(&v[i], &v[maior], est);
        heapify(v, n, maior, est);
    }
}

void heap_sort(Pessoa v[], int n, Estatisticas *est) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i, est);
    for (int i = n - 1; i > 0; i--) {
        trocar(&v[0], &v[i], est);
        heapify(v, i, 0, est);
    }
}

// --- Funções auxiliares ---

void imprimir_pessoas(Pessoa v[], int n) {
    for (int i = 0; i < n; i++)
        printf("%s (%d)\n", v[i].nome, v[i].idade);
}

void copiar_vetor(Pessoa destino[], Pessoa origem[], int n) {
    for (int i = 0; i < n; i++)
        destino[i] = origem[i];
}

void testar_algoritmo(void (*sort_func)(Pessoa[], int, Estatisticas*), const char *nome_alg, Pessoa original[], int n) {
    Estatisticas est_total = {0, 0};
    clock_t tempo_total = 0;

    Pessoa copia[TAM];

    for (int i = 0; i < REPS; i++) {
        copiar_vetor(copia, original, n);
        Estatisticas est = {0, 0};
        clock_t inicio = clock();
        sort_func(copia, n, &est);
        clock_t fim = clock();
        tempo_total += (fim - inicio);
        est_total.comparacoes += est.comparacoes;
        est_total.trocas += est.trocas;
    }

    printf("Algoritmo: %s\n", nome_alg);
    printf("Comparacoes medias: %ld\n", est_total.comparacoes / REPS);
    printf("Trocas medias: %ld\n", est_total.trocas / REPS);
    printf("Tempo medio: %.2f ms\n\n", (double)(tempo_total * 1000) / (REPS * CLOCKS_PER_SEC));
}

int main() {
    Pessoa pessoas[TAM] = {
        {"Lucas", 24},
        {"Mariana", 29},
        {"Pedro", 22},
        {"Sofia", 26},
        {"Rafaela", 33},
        {"Gustavo", 18},
        {"Larissa", 20},
        {"Felipe", 32},
        {"Camila", 25},
        {"Bruno", 30},
        {"Isabela", 21},
        {"Thiago", 27},
        {"Amanda", 19},
        {"Diego", 31},
        {"Juliana", 28},
        {"Andre", 23},
        {"Patricia", 34},
        {"Ricardo", 26},
        {"Viviane", 22},
        {"Marcelo", 29},
        {"Monica", 30},
        {"Paulo", 25},
        {"Simone", 28},
        {"Victor", 20},
        {"Priscila", 31},
        {"Alexandre", 24},
        {"Fernanda", 27},
        {"Cristiano", 33},
        {"Luiza", 19},
        {"Renato", 35},
        {"Laura", 21},
        {"Sergio", 26},
        {"Aline", 32},
        {"Roberto", 23},
        {"Daniela", 29},
        {"Fabio", 18},
        {"Erica", 30},
        {"Guilherme", 22},
        {"Luciana", 25},
        {"Marcio", 31},
        {"Natalia", 20},
        {"Vinicius", 28},
        {"Elisa", 34},
        {"Jorge", 27},
        {"Debora", 24},
        {"Rodrigo", 30},
        {"Claudia", 26},
        {"Leandro", 21},
        {"Barbara", 33},
        {"Leonardo", 19},
        {"Tatiane", 25},
        {"Rogerio", 32},
        {"Vanessa", 23},
        {"Mauro", 29},
        {"Cintia", 18},
        {"Kleber", 31},
        {"Adriana", 20},
        {"Rafael", 28},
        {"Silvia", 35},
        {"Wagner", 22},
        {"Valeria", 27},
        {"Marcelo", 24},
        {"Denise", 30},
        {"Emerson", 26},
        {"Flavia", 21},
        {"Otavio", 33},
        {"Eliane", 19},
        {"Anderson", 25},
        {"Carla", 32},
        {"Arthur", 23},
        {"Rosana", 29},
        {"Tiago", 18},
        {"Sandra", 30},
        {"Celso", 22},
        {"Gisele", 27},
        {"Marcelo", 24},
        {"Regina", 31},
        {"Marcos", 20},
        {"Leticia", 28},
        {"Sebastiao", 34},
        {"Julio", 26},
        {"Bianca", 21},
        {"Elias", 33},
        {"Isadora", 19},
        {"Ramon", 25},
        {"Renata", 32},
        {"Alex", 23},
        {"Michele", 29},
        {"Davi", 18},
        {"Carolina", 30},
        {"Joaquim", 22},
        {"Thais", 27},
        {"Vicente", 24},
        {"Alice", 31},
        {"Bruno", 20},
        {"Mariana", 28}
    };

    testar_algoritmo(insertion_sort, "Insertion Sort", pessoas, TAM);
    testar_algoritmo(quick_sort, "Quick Sort", pessoas, TAM);
    testar_algoritmo(heap_sort, "Heap Sort", pessoas, TAM);

    return 0;
}
