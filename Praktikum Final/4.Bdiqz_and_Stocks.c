/*
Bdiqz akhirnya menjadi orang sukses. Ia memiliki banyak harta, tahta, dan wanita pula. Dari hasil jerih payahnya itu, ia membangun sebuah perusahaan besar. Perusahaannya ia daftarkan ke dalam sebuah komunitas perusahaan saham.

Dalam komunitas tersebut, diadakan sebuah event bagi keuntungan akhir tahun. Bagi keuntungan akhir tahun ini memiliki aturan : apabila saham yang dimiliki suatu perusahaan lebih dari 50% dari total saham, maka seluruh keuntungan komunitas (100% keuntungan) diberikan kepada pemegang saham tersebut.

Bagi pemilik perusahaan yang sahamnya lebih dari 50% sejak awal, tentunya akan sangat mudah bagi mereka untuk mendapatkan seluruh keuntungan. Lalu bagaimana dengan yang sahamnya kurang dari 50%? Untuk tetap bisa mendapatkan seluruh keuntungan, diperbolehkan aturan koalisi, yang mana sebuah perusahaan dapat menggabung-gabungkan sahamnya dengan saham perusahaan lain agar total sahamnya melebihi 50%. Lalu, dari koalisi tersebut, setiap pemegang sahamnya akan mendapatkan sejumlah keuntungan sesuai dengan besar partisipasinya dalam koalisi tersebut.

Misalnya, anggaplah ada 5 pemegang saham: A, B, C, D dan E, memiliki 20%, 12%, 14%, 29% dan 25% dari saham perusahaan. Pemegang saham E bisa membentuk beberapa kemenangan koalisi. Misalnya, jika E akan membentuk koalisi dengan A dan B, dia akan mendapatkan 43,86% keuntungan akhir tahun. Jika E membentuk koalisi dengan B dan C, dia juga bisa memenangkan koalisi dan mendapatkan keuntungan bagian sebesar 49.02%. Di sisi lain, E tidak dapat membentuk koalisi pemenang hanya dengan A.

Karena Bdiqz ingin menjadi kaya raya, tentunya ia ingin mendapatkan keuntungan tersebut. Ia juga berpendirian, bila ia harus berkoalisi, ia mau mendapatkan keuntungan sebesar-besarnya dengan berkoalisi dengan sesedikit mungkin pemegang saham.

Input Format

Baris pertama berisi 2 buah bilangan T dan P. T menyatakan banyaknya perusahaan dan P menyatakan perusahaan Bdiqz adalah perusahaan ke berapa sesuai dengan urutan input.

T baris berikutnya berisi besar saham yang dimiliki masing-masing perusahaan dengan format dua angka di belakang koma.

Akhir inputan ditandai dengan T = P = 0.

Dipastikan bahwa total saham dari tiap casenya adalah 100%..

Constraints

2 ≤ T ≤ 100

1 ≤ P ≤ T

0.00 ≤ Ti ≤ 100.00

Output Format

Untuk setiap casenya, outputkan keuntungan maksimal yang bisa didapatkan perusahaan Bdiqz. Apabila hasil perhitungan keuntungan bdiqz nantinya lebih dari 2 angka di belakang koma, maka bulatkan menjadi 2 angka di belakang koma sesuai dengan aturan pembulatan pada umumnya. (Misal: Bdiqz mendapat keuntungan 49.087, maka bulatkan menjadi 49.09. Misal : Bdiqz mendapat keuntungan 49.081, maka bulatkan menjadi 49.08). Sertakan pula jumlah perusahaan dalam koalisi yang dibuat.

Sample Input 0

5 5
20.00
12.00
29.00
14.00
25.00
2 1
56.87
43.13
2 2
56.87
43.13
3 1
10.00
45.00
45.00
0 0
Sample Output 0

49.02 3
100.00 1
43.13 2
18.18 2
Explanation 0

Pada kasus pertama, dapat dilihat bahwa saham Bdiqz besarnya adalah 25.00 (<50%). Artinya ia harus membuat koalisi. Untuk mendapat keuntungan maksimum, dia berkoalisi dengan saham ke 2 dan saham ke 4. Dengan total koalisi 51.00. Dari situ, keuntungan yang didapat Bdiqz adlaah 25.00/51.00 = 49.02 dengan total anggota koalisi sebanyak 3 perusahaan.

Sample Input 1

5 5
26.00
12.00
23.00
14.00
25.00
2 1
56.87
43.13
2 2
56.87
43.13
3 1
10.00
45.00
45.00
0 0
Sample Output 1

49.02 2
100.00 1
43.13 2
18.18 2
*/