// https://www.beecrowd.com.br/judge/en/problems/view/1162?origem=1
// Train Swapping

#include <stdio.h>
#include <stdlib.h>

int swaps = 0;
int v[50];  

void merge(int *v, int l, int m, int r){
	int *c=malloc(sizeof(int)*(r-l+1));
	int i=l,j=m+1,k=0;

	while(i<=m && j<=r){
	    if(v[i] <= v[j])
		    c[k++]=v[i++];
        else {
    		c[k++]=v[j++];
            swaps += (m+1-i);
        }
  	}

  	while(i<=m)
    	c[k++]=v[i++];
  	while(j<=r)
      	c[k++]=v[j++];

  	k=0;
  	for(i=l;i<=r;i++)
    	v[i]=c[k++];
  	free(c);
}

void merge_sort(int *v, int l, int r){
	if(l>=r)return; //criterio de parada
	int m = (l+r)/2;
	
	merge_sort(v, l, m);
	merge_sort(v, m+1, r);
	
	merge(v, l, m, r);
}


int main(){
    int n, i, loops;
    scanf("%d", &loops);
    while(loops--){
        scanf("%d", &n);
	    i = swaps = 0;
	    while (n--)
	    	scanf("%d", &v[i++]);
	    merge_sort(v, 0, i-1);
	    printf("Optimal train swapping takes %d swaps.\n", swaps);
    }
    return 0;
}