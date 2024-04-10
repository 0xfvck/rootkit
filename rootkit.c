#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESOS 100
#define MAX_ARCHIVOS 100

typedef struct {
    pid_t pid;
    char nombre[256];
} proceso_t;

typedef struct {
    char path[4096];
    char nombre[256];
} archivo_t;

proceso_t procesos_ocultos[MAX_PROCESOS];
archivo_t archivos_ocultos[MAX_ARCHIVOS];

int num_procesos_ocultos = 0;
int num_archivos_ocultos = 0;

void ocultar_proceso(pid_t pid, char *nombre) {
    if (num_procesos_ocultos < MAX_PROCESOS) {
        procesos_ocultos[num_procesos_ocultos].pid = pid;
        strcpy(procesos_ocultos[num_procesos_ocultos].nombre, nombre);
        num_procesos_ocultos++;
    }
}

void mostrar_procesos_ocultos() {
    for (int i = 0; i < num_procesos_ocultos; i++) {
        printf("Proceso oculto: %d, %s\n", procesos_ocultos[i].pid, procesos_ocultos[i].nombre);
    }
}

void ocultar_archivo(char *path, char *nombre) {
    if (num_archivos_ocultos < MAX_ARCHIVOS) {
        strcpy(archivos_ocultos[num_archivos_ocultos].path, path);
        strcpy(archivos_ocultos[num_archivos_ocultos].nombre, nombre);
        num_archivos_ocultos++;
    }
}

int main() {
    ocultar_proceso_actual();
    ocultar_archivo_actual();

    // Ocultar procesos adicionales
    ocultar_proceso(1234, "proceso_extra_1");
    ocultar_proceso(5678, "proceso_extra_2");

    // Ocultar archivos adicionales
    ocultar_archivo("/path/to/file_1", "file_1");
    ocultar_archivo("/path/to/file_2", "file_2");

    while (1) {
        sleep(1);
    }

    return 0;
}
