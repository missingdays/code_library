/*
 * a.cpp
 * Copyright (C) 2016 missingdays <missingdays@missingdays>
 *
 * Distributed under terms of the MIT license.
 */

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#define ALL(v) v.begin(),v.end()
#define what_is(x) cout<<#x<<" is "<<x<<endl;
#define min3(a,b,c) min(min(a,b),c)
#define max3(a,b,c) max(max(a,b),c)
#define SIZE 1000005
#define MAXN 1000000007
#define PI 3.141592653589793

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> a; 
int n;

int next_to_bribe(){
    int j = 0;
    for(int i = 1; i < n; i++){
        if(a[i] >= a[j]){
            j = i;
        }
    }
    return j;
}

int bribe(){
    int v = a[0];
    int i = next_to_bribe();

    if(i == 0){
        return 0;
    }

    a[i] -= 1;

    a[0] += 1;

    return 1;

}

struct cmp{
    const bool operator() (int& a, int& b){
        return b > a;
    }
};

int main(int argc, const char *argv[]){ 
    std::ios::sync_with_stdio(false);
    
    cin >> n;

    a = vector<int>(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a.begin()+1, a.end(), cmp());

    int candies = 0;
    int get;
    do{
        get = bribe();
        candies += get;

    } while(get != 0);

    cout << candies << endl;
}



