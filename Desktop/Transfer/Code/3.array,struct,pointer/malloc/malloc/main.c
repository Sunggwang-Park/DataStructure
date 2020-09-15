//
//  main.c
//  malloc
//
//  Created by APPLE on 19/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Example{
    int number;
    char name[10];
};

int main(int argc, const char * argv[]) {
    
    struct Example *p;
    
    p = (struct Example *)malloc(3*sizeof(struct Example));
    
    if(p==NULL){
        fprintf(stderr, "can't allocate memory\n");
        exit(1);
    }
    p->number = 1;
    strcpy(p->name,"Park");
    (p+1)->number = 2;
    strcpy((p+1)->name,"Developer");
    strcpy((p+2)->name, "Apple");
    printf("%s  %d\n%s   %d\n%s   %d\n",p->name,p,(p+1)->name,p+1,(p+2)->name,p+2);
    
    free(p);
    
    printf("%s  %d  \n%s  %d\n",p->name,p,(p+1)->name,p+1);

    
    
    
    return 0;
}
