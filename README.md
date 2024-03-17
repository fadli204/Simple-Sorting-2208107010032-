# Simple-Sorting-2208107010032

Program ini bertujuan untuk menguji dan mencatat waktu eksekusi dari tiga algoritma pengurutan berbeda: Bubble Sort, Selection Sort, dan Insertion Sort. Setiap algoritma diuji dengan berbagai ukuran array dan hasilnya dicatat dalam file teks.

## Cara Menjalankan Kode Program

1. Pastikan Anda memiliki kompiler C yang terinstal di sistem Anda.
2. Salin kode program C yang disediakan ke dalam file dengan ekstensi `.c`.
3. Kompilasi kode program menggunakan perintah berikut:
   ```bash
   gcc 2208107010032_Simple_Sorting.c -o 2208107010032_Simple_Sorting
   ```
4. Jalankan program dengan perintah:
   ```bash
   ./2208107010032_Simple_Sorting
   ```
5. Setelah program selesai dieksekusi, Anda akan melihat file-file hasil yang berisi array yang diurutkan dan waktu eksekusi.

## Fungsi yang Digunakan di dalam Kode Program
- `generate_and_save_random_numbers`: Fungsi ini menghasilkan bilangan acak dan menyimpannya dalam sebuah file teks.
- `bubble_sort`: Fungsi ini mengurutkan array menggunakan algoritma Bubble Sort.
- `selection_sort`: Fungsi ini mengurutkan array menggunakan algoritma Selection Sort.
- `insertion_sort`: Fungsi ini mengurutkan array menggunakan algoritma Insertion Sort.
- `save_sorted_to_file`: Fungsi ini menyimpan array yang telah diurutkan ke dalam file beserta waktu eksekusi.
