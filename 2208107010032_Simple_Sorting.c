#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fungsi untuk menghasilkan dan menyimpan bilangan acak ke dalam file
void generate_and_save_random_numbers(int *array, int size, int num) {
    char nama_file[20];
    sprintf(nama_file, "%d_input.txt", num);

    FILE *file = fopen(nama_file, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand(); // Mengisi array dengan bilangan acak
        fprintf(file, "%d\n", array[i]); // Menulis bilangan acak ke dalam file
    }

    fclose(file);
}

// Fungsi untuk mengurutkan array menggunakan Bubble Sort
void bubble_sort(int *array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j]; // Menukar elemen array jika tidak terurut
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Fungsi untuk mengurutkan array menggunakan Selection Sort
void selection_sort(int *array, int size) {
    int minIndex, temp;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j; // Mencari nilai minimum dalam array
            }
        }
        temp = array[minIndex]; // Menukar nilai minimum dengan elemen pertama yang belum terurut
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

// Fungsi untuk mengurutkan array menggunakan Insertion Sort
void insertion_sort(int *array, int size) {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j]; // Memindahkan elemen yang lebih besar ke posisi yang sesuai
            j = j - 1;
        }
        array[j + 1] = key; // Menempatkan elemen yang disisipkan ke posisi yang sesuai
    }
}

// Fungsi untuk menyimpan array yang telah diurutkan ke dalam file beserta waktu eksekusi
void save_sorted_to_file(char *nama_file, int *array, int size, double waktu) {
    FILE *file = fopen(nama_file, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "Array yang diurutkan:\n");
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n", array[i]); // Menulis array yang diurutkan ke dalam file
    }

    fprintf(file, "\nWaktu Eksekusi (ms): %.2f\n", waktu); // Menulis waktu eksekusi ke dalam file

    fclose(file);
}

int main() {
    const int max_ukuran = 1000000;
    int *array = (int *)malloc(max_ukuran * sizeof(int));

    printf("+-----------------+------------------+---------------------+\n");
    printf("| Jenis Algoritma | Jumlah Bilangan  | Waktu Eksekusi (ms) |\n");
    printf("+=================+==================+=====================+\n");

    clock_t mulai, selesai;
    double waktu_penggunaan_cpu;

    // Pengujian dan pencatatan waktu eksekusi untuk Bubble Sort
    for (int ukuran = 100000; ukuran <= max_ukuran; ukuran += 100000) {
        printf("| Bubble Sort     | %8dk        |", ukuran / 1000);

        generate_and_save_random_numbers(array, ukuran, ukuran);

        mulai = clock();
        bubble_sort(array, ukuran);
        selesai = clock();

        char nama_file[20];
        sprintf(nama_file, "bubble_sort_%dk_output.txt", ukuran / 1000);
        save_sorted_to_file(nama_file, array, ukuran, ((double)(selesai - mulai)) / CLOCKS_PER_SEC * 1000);

        waktu_penggunaan_cpu = ((double)(selesai - mulai)) / CLOCKS_PER_SEC * 1000;
        printf(" %11.2f         |\n", waktu_penggunaan_cpu);
    }

    printf("+-----------------+------------------+---------------------+\n");

    // Pengujian dan pencatatan waktu eksekusi untuk Selection Sort
    for (int ukuran = 100000; ukuran <= max_ukuran; ukuran += 100000) {
        printf("| Selection Sort  | %8dk        |", ukuran / 1000);

        generate_and_save_random_numbers(array, ukuran, ukuran);

        mulai = clock();
        selection_sort(array, ukuran);
        selesai = clock();

        char nama_file[20];
        sprintf(nama_file, "selection_sort_%dk_output.txt", ukuran / 1000);
        save_sorted_to_file(nama_file, array, ukuran, ((double)(selesai - mulai)) / CLOCKS_PER_SEC * 1000);

        waktu_penggunaan_cpu = ((double)(selesai - mulai)) / CLOCKS_PER_SEC * 1000;
        printf(" %11.2f         |\n", waktu_penggunaan_cpu);
    }

    printf("+-----------------+------------------+---------------------+\n");

    // Pengujian dan pencatatan waktu eksekusi untuk Insertion Sort
    for (int ukuran = 100000; ukuran <= max_ukuran; ukuran += 100000) {
        printf("| Insertion Sort  | %8dk        |", ukuran / 1000);

        generate_and_save_random_numbers(array, ukuran, ukuran);

        mulai = clock();
        insertion_sort(array, ukuran);
        selesai = clock();

        char nama_file[20];
        sprintf(nama_file, "insertion_sort_%dk_output.txt", ukuran / 1000);
        save_sorted_to_file(nama_file, array, ukuran, ((double)(selesai - mulai)) / CLOCKS_PER_SEC * 1000);

        waktu_penggunaan_cpu = ((double)(selesai - mulai)) / CLOCKS_PER_SEC * 1000;
        printf(" %11.2f         |\n", waktu_penggunaan_cpu);
    }

    printf("+-----------------+------------------+---------------------+\n");

    free(array);

    return 0;
}
