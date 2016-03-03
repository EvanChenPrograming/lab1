//
//  main.cpp
//  lab1_quesB
//
//  Created by Evan Chen on 2016/3/2.
//  Copyright © 2016年 Evan Chen. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int n=0;
    
    cout<<"Please input a integer.";
    cin>>n;
loop:
    cout<<n<<" ";
    if (n == 1)
        return 0;
    else if (n%2!=0)
        n=3*n+1;
    else
        n=n/2;
    goto loop;
    
    return 0;
}
