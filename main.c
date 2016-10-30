#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 13

void *sayHello(void *threadID) {
  printf("Hello Wordl! Thread nr %ld\n",(long)threadID);
  pthread_exit(NULL);
}

int main() {

  pthread_t threads[NUM_THREADS];

  for (long i=0;i<NUM_THREADS;i++) {
    pthread_create(&threads[i], NULL, sayHello, (void *)i);
  }
  printf("Hello World! I'm main thread.\n");
  pthread_exit(NULL);
  printf("LOL\n");
  return 0;
}
