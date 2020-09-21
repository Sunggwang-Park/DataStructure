//
//  main.c
//  FunctionPointer
//
//  Created by APPLE on 19/06/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>

void foo(int a)
{
    printf("foo : %d\n" , a);
}
int main(int argc, const char * argv[]) {
    
    void (*f)(int);
    f = foo;
    f(10);
    (*f)(10);
    f(100);
    
    return 0;
}
