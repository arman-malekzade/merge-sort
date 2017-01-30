//
//  merge-sort.cpp
//  Algorithms
//
//  Created by Arman-Malekzade on 1/30/17.
//  Copyright © 2017 Arman-Malekzade. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> merged_vector(vector<int> v1,vector<int> v2){
    vector<int> merged={};
    int i=0,j=0;
    while(1){
        if(i<v1.size()&&j<v2.size()){
            if(v1[i]<=v2[j]){
                merged.push_back(v1[i]);
                i++;
            }
            else{
                merged.push_back(v2[j]);
                j++;
            }
        }
        else{
            break;
        }
    }
    if(i==v1.size()){
        while(j!=v2.size()){
            merged.push_back(v2[j]);
            j++;
        }
    }
    else if(j==v2.size()){
        while(i!=v1.size()){
            merged.push_back(v1[i]);
            i++;
        }
    }
    return merged;
}
vector<int> first_half_vector(vector<int> v){
    vector<int> first_half={};
    int n= v.size();
    int middle=n/2;
    for(int i=0;i<middle;i++){
        first_half.push_back(v[i]);
    }
    return first_half;
}
vector<int> second_half_vector(vector<int> v){
    vector<int> second_half={};
    int n=v.size();
    int middle=n/2;
    for(int i=middle;i<v.size();i++){
        second_half.push_back(v[i]);
    }
    return second_half;
}
vector<int> merge_sort(vector<int> v){
    if(v.size()<=1){
        return v;
    }
    else{
        vector<int> v1=merge_sort(first_half_vector(v));
        vector<int> v2=merge_sort(second_half_vector(v));
        return merged_vector(v1,v2);
    }
}
void print_vector(vector<int> v){
    cout<<"printing started\n";
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"\n";
    }
    cout<<"printing finished\n";
}
int main(){
    vector<int> v={10,2,3,5,14,10};
    vector<int> sorted=merge_sort(v);
    for(int i:sorted){
        cout<<i<<"\n";
    }
    cout<<"\n";
    return 0;
}
