#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int cont = 0;
int soma = 0;
int tam_total = 0;
int *point_array = NULL;


void* increment_sum(void *arg){
  pthread_mutex_lock(&mutex);
  for (int j = 0; j < tam_total; j++){
    soma += *(point_array + cont);
    cont++;
    }
  pthread_mutex_unlock(&mutex);
  return arg;
}


int main(void) {
  int tam;
  int qtd_threads;
  scanf("%d\n", &tam);
  
  tam_total = tam;
  qtd_threads = tam;

  
  point_array = malloc((tam*tam)* sizeof(int));
  
  for (int i = 0; i < tam*tam; i++) {
    scanf("%d", &point_array[i]);
  }


  pthread_t threads [qtd_threads];
  for (long i = 0; i < qtd_threads; i++) {
    if (pthread_create(&threads[i], NULL, increment_sum, NULL)){
      printf("Erro na criação da threads %ld", threads[i]);
    }
  }

  for (int i = 0; i < qtd_threads; i++) {
    pthread_join(threads[i], NULL);
  }


  free(point_array);
  printf("\n%d", soma);
  return 0;
}
