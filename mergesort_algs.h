#include<vector>
using namespace std;


int median(vector<int> &v,int a, int b);

int bin_search(vector<int> &v,int l,int u,int x);

void show_vec(vector<int> v, int l, int u);

void show_vec(vector<int> v);

vector<vector<int>> merge_step(vector<int> &v, vector<int>);

void merge_until(vector<int> &v, int l, int m, int u);

void merge_sort(vector<int> &v);
