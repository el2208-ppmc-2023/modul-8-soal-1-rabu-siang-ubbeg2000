/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>

int solve(int i, int j, int n, int arr[n][n]);
int max(int a, int b);

int main() {
    int n;
    scanf("%d",&n);
    int arr[n][n];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("%d\n",solve(0,0,n,arr));
}

int solve(int i, int j, int n, int arr[n][n]) {
    int a,b,c,d;
    a=0;b=0;c=0;d=0;
    if(i-1>=0) {
        if(arr[i-1][j]==1+arr[i][j]) {
            a=solve(i-1,j,n,arr);
        }
    }
    if(i+1<n) {
        if(arr[i+1][j]==1+arr[i][j]) {
            b=solve(i+1,j,n,arr);
        }
    } 
    if(j-1>=0) {
        if(arr[i][j-1]==1+arr[i][j]) {
        c=solve(i,j-1,n,arr);
        }
    }
    if(j+1<n) {
        if(arr[i][j+1]==1+arr[i][j]) {
            d=solve(i,j+1,n,arr);
        }
    }
    return max(max(a,b),max(c,d))+1;
}

int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}
