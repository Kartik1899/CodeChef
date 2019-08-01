#include<stdio.h>
#include<stdlib.h>


unsigned long long int calMonths(unsigned long long int *heights, unsigned long long int *growth, unsigned long long int size, unsigned long long int required, unsigned long long int min)
{
    unsigned long long int left = 0;
    unsigned long long int right = required;                // taking worst case if there is only 1 tree and  size, growth are 1,1;

    unsigned long long int mid;

    unsigned long long int sum = 0;
    
    while( left < right)
    {
        mid = (left + right) / 2;
        sum = 0;
        for(unsigned long long int i = 0; i < size ; i++)
        {
            if( heights[i] + ( growth[i] * mid ) >= min)
            {
                
                sum += heights[i] + ( growth[i] * mid ) ;
                
                if(sum >= required)
                {
                    break;
                }
            }
        }

        if( sum >= required)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }

    return right;
}

int main()
{
    unsigned long long int treeCount;
    scanf("%llu",&treeCount);
    unsigned long long int *initialHeights = (unsigned long long int*)malloc(treeCount * sizeof(unsigned long long int));
    unsigned long long int *growthRates = (unsigned long long int*)malloc(treeCount * sizeof(unsigned long long int));

    unsigned long long int hRequired;
    scanf("%llu",&hRequired);
    
    unsigned long long int minHeight;
    scanf("%llu",&minHeight);

    for(unsigned long long int i = 0 ; i < treeCount ; i++)
    {
        scanf("%llu",&initialHeights[i]);
        scanf("%llu",&growthRates[i]);
    }


    unsigned long long int months = calMonths(initialHeights, growthRates, treeCount, hRequired, minHeight);

    printf("%llu",months);
    return 0;
}