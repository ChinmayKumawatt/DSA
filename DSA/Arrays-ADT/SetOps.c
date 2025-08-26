#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[10];
    int size;
    int length;
};
int i=0;
int j=0;
int k=0;

void Display(struct Array *a){
    for(int i=0;i<a->length;i++){
        printf("%d\n",a->A[i]);
    }
}

struct Array* intersection(struct Array *a,struct Array *b){
    struct Array *c = (struct Array*)malloc(sizeof(struct Array));
    
    while(i<a->length && j<b->length){
        if(a->A[i]==b->A[j]){
            c->A[k++] = a->A[i];
            i++;
            j++;
        }
        else if(a->A[i]<b->A[j]){
            i++;
        }
        else{
            j++;
        }
    }
    c->length = k;
    return c;
    
}

struct Array* unionn(struct Array *a,struct Array *b){
    struct Array *c = (struct Array*)malloc(sizeof(struct Array));
    while(i<a->length && j<b->length){
        if(a->A[i] == b->A[j]){
            c->A[k++] = a->A[i++];
            j++;
        }
        else if(a->A[i]<b->A[j])
        c->A[k++] = a->A[i++];
        else
        c->A[k++]=b->A[j++];
    }
    for(;i<a->length;i++)
    c->A[k++] = a->A[i];
    for(;j<b->length;j++)
    c->A[k++] = b->A[j];
    c->length = k;
    return c;
}

struct Array* difference(struct Array *a,struct Array *b){
    struct Array *c = (struct Array*)malloc(sizeof(struct Array));
    while(i<a->length && j<b->length){
        if(a->A[i] == b->A[j]){
            i++;
            j++;
        }
    else if(a->A[i]<b->A[j])
        c->A[k++] = a->A[i++];
        else
        c->A[k++]=b->A[j++];
    }
    for(;i<a->length;i++)
    c->A[k++] = a->A[i];
    for(;j<b->length;j++)
    c->A[k++] = b->A[j];
    c->length = k;
    return c;
}

int main()
{
    struct Array arr1 = {{3,5,6,10,11,15},10,6};
    struct Array arr2 = {{0,2,3,6},10,4};
    
    // struct Array *c = unionn(&arr1,&arr2);
   
    // struct Array *d = intersection(&arr1,&arr2);
    
    struct Array *e = difference(&arr1,&arr2);
    // printf("Union\n");
    // Display(c);
    //  printf("Intersection\n");
    // Display(d);
    printf("Difference\n");
    Display(e);
    return 0;
}