#include <stdio.h>
#include <math.h>

int costs[1000], num=0;
int sumation() {
    int sum = 0;
    for (int i=0; i < num; i++) {
        sum += costs[i];
    }
    return sum;
}

int main() {
    while(1==1){
        scanf("%d", &num);
        for (int i=0; i < num; i++) {
            int dollars, cents;
            scanf("%d.%d", &dollars, &cents);
            costs[i] = dollars * 100 + cents;            
        }
        int sum = sumation();
        double avg = ((double) sum)/num, a=0, b=0;
        for (int i = 0; i < num; i++) {
            double diff = costs[i] - avg;
            if (diff < 0) {
                a += -((int) diff) / 100.0;
            }else{
                b += ((int) diff) / 100.0;
            }
        }
        printf("$%.2f\n", a > b ? a : b);
    }
    return 0;
}