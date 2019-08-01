#include<stdio.h>
#include<stdlib.h>

typedef struct tree{                                          // Initializing structure

    long initialHeight;
    long growthRate;
} Trees;

unsigned long long int calMonths( Trees *arr, long size,unsigned long long int hRequired, unsigned long long int mHeight)
{

    unsigned long long int left = 0;
    unsigned long long int right = hRequired;                  // taking worst case if there is only 1 tree and  size, growth are 1,1;
    unsigned long long int sum = 0;
    unsigned long long int mid;

    while ( left < right)
    {
        mid = ( left + right ) / 2;
        sum = 0;

        for(int i = 0; i < size ; i++)
        {
            if( arr[i].initialHeight +  (arr[i].growthRate * mid) >= mHeight )                      // checking if the law allows the tree to be cut
            {
                sum += arr[i].initialHeight +  (arr[i].growthRate * mid);

                if( sum >= hRequired)
                {
                    break;
                }
            }
        }

        if(sum >= hRequired)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return right;
}


int main()
{
    long treeCount;
    unsigned long long int requiredHeight;
    unsigned long long int minHeight;

    scanf("%ld",&treeCount);
    scanf("%lld",&requiredHeight);
    scanf("%lld",&minHeight);

    Trees *arr = (Trees *)malloc(treeCount*sizeof(Trees));                          // Initializing Structure Array

    for(int i = 0 ; i < treeCount; i++)
    {
        scanf("%ld",&arr[i].initialHeight);
        scanf("%ld",&arr[i].growthRate);
    }

    unsigned long long int months = calMonths(arr,treeCount,requiredHeight,minHeight);

    printf("%lld",months);
    return 0;


}