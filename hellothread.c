#include <stdio.h>
#include <pthread.h>

void *hello_thread(void *arg) {
    int *p = (int *)arg;
    for (int i = 0; i < 4; i++) {
        printf("thread %d: %d\n", *p, i);
    }
    return NULL;
}

int main() {

    pthread_t t1, t2;
    int a = 1, b = 2;
    int status;

    // Creating thread 1
    status = pthread_create(&t1, NULL, hello_thread, &a);
    if (status != 0) {
        perror("pthread_create");
    }

    // Creating thread 2
    status = pthread_create(&t2, NULL, hello_thread, &b);
    if (status != 0) {
        perror("pthread_create");
    }

    // Joining thread 1
    status = pthread_join(t1, NULL);
    if (status != 0) {
        perror("pthread_join");
    }

    // Joining thread 2
    status = pthread_join(t2, NULL);
    if (status != 0) {
        perror("pthread_join");
    }

    return 0;
}