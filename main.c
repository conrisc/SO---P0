#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 13

void *sayHello(void *threadID) {
  printf("Hello Wordl! Thread nr %ld\n",(long)threadID);
  pthread_exit(NULL);
}

int main() {

  pthread_t threads[NUM_THREADS];

  long i=0;
  while (i<NUM_THREADS) {
    pthread_create(&threads[i], NULL, sayHello, (void *)i);
    i++;
  }

  i=0;
  while (i<NUM_THREADS) {
    pthread_join(threads[i],NULL);
    i++;
  }

  printf("Hello World! I'm main thread.\n");
  pthread_exit(NULL);

  return 0;
}
