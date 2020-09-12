//
//  main.c
//  Ackermann
//
//  Created by APPLE on 09/09/2020.
//  Copyright © 2020 DataStructure. All rights reserved.
//

#include <stdio.h>

int Ackermann(int a, int b){
    if(a == 0)
        return b + 1;
    if(b == 0)
        return Ackermann(a-1,1);
    else
        return Ackermann(a-1, Ackermann(a,b-1));
    
}

int Ackermann_iter(int a, int b){
    while(a != 0){
        if(b == 0)
            b = 1;
        else
            b = Ackermann_iter(a,b-1);
        
        a -= 1;
           
    }
    
    return b + 1;
    
}

int main(int argc, const char * argv[]) {
    printf("%d\n",Ackermann(2, 3));
    
    printf("%d\n", Ackermann_iter(2, 3));
    
    printf("%d\n", ack2(2, 3));
    
    return 0;
}
