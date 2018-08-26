#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,a,b, j, k, n, **arr;

    scanf("%d", &n);

    //initializing values with zero
    arr = (int **)calloc(n, sizeof(int *));
    for (i=0; i<n; i++)
         arr[i] = (int *)calloc(n, sizeof(int));

    i=0;j=n/2;k=1;

    while(k<=n*n) {
        if(arr[i][j] != 0) {    //inserting new value below the previously stored value in case of \
                                            current index pointing to a value other than zero.
            i = a+1;
            j = b;
            arr[i][j] = k;
            k++;
        }
        else {
            arr[i][j] = k;
            k++;                //incrementing array element
        }

        a = i;  //storing previous index in a,b
        b = j;
        i-=1;   //one up
        j+=1;   //one right

        if(i<0) {   //boundary conditions
            if(j>=n){
                i+=n; j-=n;
            }
            else {
                i+=n;
            }
        }
        else if(j==n) {
            j-=n;
        }
    }

    // printing the array below
    for (i=0; i<n; i++){
        for(j=0;j<n;j++) {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}
