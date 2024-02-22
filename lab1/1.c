// Phubordin Poolnai 66070501040

#include <stdio.h>

int main(){
    int length, j = 0;

    scanf("%d",&length);

    int arr[length];
    
    for(int i = 0; i < length; i++){
        int tmp;

        scanf("%d",&tmp);

        if (j == 0){
            arr[j] = tmp;

            j++;
        } else {
            if(arr[j - 1] != tmp){
                arr[j] = tmp;

                j++;
            }
        }
    }

    printf("%d\n",j);
    
    for(int i = 0; i < j; i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}
