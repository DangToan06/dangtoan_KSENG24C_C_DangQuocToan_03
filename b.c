#include<stdio.h>
#include<math.h>
#include<limits.h>

int main(){
    int arr[100], n = 0, number;
    do{
        printf("\n\nMENU");
        printf("1.Nhap so pghan tu va gia tri cho mang\n");
        printf("2.In ra cac gia tri trong mang\n");
        printf("3.Dem so luong cac so nguyen to co trong mang\n");
        printf("4.Tim gia tri nho thu 2 trong mang\n");
        printf("5.Them 1 phan tu vao vi tri ngau nhien trong mang\n");
        printf("6.Xoa phan tu tai 1 vi tri cu the\n");
        printf("7.Xap xep mang theo thu tu giam dan\n");
        printf("8.Tim kiem xem phan tu nhap vao co ton tai trong mang khong\n");
        printf("9.Xoa toan bo phan tu trung lap trong mang va hien thi toan bo pha tu do nhat co trong mang\n");
        printf("10.Dao nguoc cac phan tu co trong mang\n");
        printf("11.Thoat\n");
        printf("Nhap su lua chon cua ban: ");
        scanf("%d", &number);
        int check = 0, count = 0, addNumber, position, searchNumber;
        int min = INT_MAX, min2 = INT_MAX;
        switch(number){
            case 1:
                printf("Nhap chieu dai cho mang: ");
                scanf("%d", &n);
                while(n <= 0){
                    printf("Chieu dai mang khong duoc nho hon hoac bang 0 hay nhap lai: ");
                    scanf("%d", &n);
                }
                printf("Nhap gia tri cho mang:\n");
                for(int i = 0; i < n; i++){
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                if(n == 0){
                    printf("Ban chua nhap gia tri cho mang");
                }else{
                    printf("mang ban vua nhap vao la:\n");
                    for(int i = 0; i < n; i++){
                        printf("arr[%d] = %d\n", i, arr[i]);
                    }
                }
                break;
            case 3:
                if(n == 0){
                    printf("Ban chua nhap gia tri cho mang");
                }else{
                    for(int i = 0; i < n; i++){
                        check = 1;
                        if(arr[i] <= 1){
                            check = 0;
                        }
                        for(int j = 2; j <= sqrt(arr[i]); j++){
                            if(arr[i] % j == 0){
                                check = 0;
                            }
                        }
                        if(check == 1){
                            count++;
                        }
                    }
                    printf("So luong cac so nguyen to co trong mang la: %d", count);
                }
                break;
            case 4:
                if(n == 0){
                    printf("Ban chua nhap gia tri cho mang");
                }else{
                    for(int i = 0; i < n; i++){
                        if(arr[i] < min2){
                            min2 = arr[i];

                        }
                        if(min2 < min){
                            int temp = min;
                            min = min2;
                            min2 = temp;
                        }
                    }
                    printf("%d ", min2);
                }
                break;
            
            case 5:
                if(n == 0){
                    printf("Ban chua nhap gia tri cho mang");
                }else{
                    printf("Nhap gia tri ban muon them vao: ");
                    scanf("%d", &addNumber);
                    printf("Nhap vi tri ban muon them: ");
                    scanf("%d", &position);
                    while(position <= 0 || position > n){
                        printf("Vi tri nhap khong thoa man chieu dai mang Nhap lai: ");
                        scanf("%d", &position);
                    }
                    n = n + 1;
                    for(int i = n; i >= position; i--){
                        arr[i] = arr[i - 1];
                    }
                    printf("Mang sau khi duoc them vao la:\n");
                    for(int i = 0; i < n; i++){
                        if(i == position - 1){
                            arr[i] = addNumber;
                        }
                        printf("%d ", arr[i]);
                    }
                }
                break;
            case 6:
                if(n == 0){
                    printf("Ban chua nhap gia tri cho mang");
                }else{
                    printf("Nhap vi tri ban muon xoa: ");
                    scanf("%d", &position);
                    while(position <= 0 || position > n){
                        printf("Vi tri nhap khong thoa man chieu dai mang Nhap lai: ");
                        scanf("%d", &position);
                    }
                    n = n - 1;
                    for(int i = position - 1; i < n; i++){
                        arr[i] = arr[i + 1];
                    }
                    printf("Mang sau khi duoc xoa la:\n");
                    for(int i = 0; i < n; i++){
                        printf("%d ", arr[i]);
                    }
                }
                break;
            case 7:
                if(n == 0){
                    printf("Ban chua nhap gia tri cho mang");
                }else{
                    int j;
                    for(int i = 0; i < n; i++){
                        int key = arr[i];
                        for(j = i - 1; j >= 0 && key > arr[j]; j--){
                            arr[j + 1] = arr[j];
                        }
                        arr[j + 1] = key;
                    }
                    printf("Mang sau khi duoc xap xe la:\n");
                    for(int i = 0; i < n; i++){
                        printf("%d ", arr[i]);
                    }
                }
                break;
            case 8:
                if(n == 0){
                    printf("Ban chua nhap gia tri cho mang");
                }else{
                    printf("Nhap phan tu ban muon tim: ");
                    scanf("%d", &searchNumber);
                    check = 0;
                    int start = 0;
                    int end = n;
                    int mid;
                    while(start <= end){
                        mid = (start + end)/2;
                        if(arr[mid] == searchNumber){
                            check = 1;
                            break;
                        }else if(searchNumber > arr[mid]){
                            start = mid + 1;
                        }else if(searchNumber < arr[mid]){
                            end = mid - 1;
                        }
                    }
                    if(check == 0){
                        printf("Phan tu khong tai trong mang");
                    }else if(check == 1){
                        printf("Phan tu ban can tim co ton tai trong mang");
                    }
                }
                break;
            case 10:
                if(n == 0){
                    printf("Ban chua nhap gia tri cho mang");
                }else{
                    printf("Cac phan tu co trong mang sau khi bi dao nguoc thu tu la:\n");
                    for(int i = n - 1; i >= 0; i--){
                        printf("%d ", arr[i]);
                    }
                }
                break;
        }
    }while(number != 11);

    return 0;
}