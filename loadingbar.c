#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEEP 500000

int main() {
    system("clear");
    printf("[        ]");
    fflush(stdout);
    usleep(SLEEP);
    printf("\r[##      ]");
    fflush(stdout);
    usleep(SLEEP);
    printf("\r[####    ]");
    fflush(stdout);
    usleep(SLEEP);
    printf("\r[######  ]");
    fflush(stdout);
    usleep(SLEEP);
    printf("\r[########]\n"); 
}    
      