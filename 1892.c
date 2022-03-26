// https://www.beecrowd.com.br/judge/en/questions/view/1892/8703
// Freshman Beats Veteran?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100100

long long n, i;
long long inversions = 0;

typedef struct {
	char s[15];
} string;

string v[MAXSIZE];

void merge(string *v, int l, int m, int r){
	string *c=malloc(sizeof(string)*(r-l+1));
	int i=l,j=m+1,k=0;

	while(i<=m && j<=r){
	    if(strcmp(v[i].s, v[j].s) < 0)
		    c[k++]=v[i++];
    	else {
    		c[k++]=v[j++];
            inversions += (m+1-i);
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

int merge_sort(string *v, int l, int r){
    if(l>=r)return n; //criterio de parada
	int m = (l+r)/2;
	
	merge_sort(v, l, m);
	merge_sort(v, m+1, r);
	
	merge(v, l, m, r);
}

int main(){

    while (scanf("%lld", &n) != EOF){
		i = inversions = 0;

		while (n--)
			scanf("%s[^/]%*s", v[i++].s);

		merge_sort(v, 0, i-1);
		printf("%lld\n", inversions);
	}

    return 0;
}