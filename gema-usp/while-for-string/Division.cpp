#include <bits/stdc++.h>
using namespace std;
int main(void){
    int t, rating;
    cin >> t;
    while (t != 0){
    cin >> rating;
    if (rating <= 1399)
        printf("Division 4\n");
    else 
        if (rating <= 1599)
             printf("Division 3\n");
        else
            if (rating <= 1899)
                 printf("Division 2\n");
            else 
                 printf("Division 1\n");
    t = t - 1;
    }
    return 0;
}