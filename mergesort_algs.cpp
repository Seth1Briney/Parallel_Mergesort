#include<iostream>
#include<vector>
using namespace std;

int median(vector<int> &v,int a, int b)
{
    int c = (a+b)/2;
    cout << "Median\n";
    cout << "a, b, c\n";
    cout << a << ", " << b << ", " << c << "\n";
    if (v[a]<=v[b])
    {
        if (v[c]<v[b])
        {
            if (v[a]<v[c]) return c;
            else return a;
        }
        else return b;
    }
    else // v[b]<v[a]
    {
        if (v[c]<v[a])
        {
            if (v[b]<v[c]) return c;
            else return b;
        }
        else return a;
    }
}

int bin_search(vector<int> &v,int l,int u,int x)
{// assmes v is sorted and finds x between l and u. Returns index of first element larger than or equal to x in v, in range l,u.
    int m;
    while (l!=u)
    {
        if (x>v[u]) return u+1;
        else if (x<=v[l]) return l;
        else
        {
            m = (l+u)/2;
            if (v[m]==x) return m;
            else if (v[m]>x) u = m;
            else l = m+1;
            // cout << l << ", " << m << ", " << u << "\n";
            // cout << v[l] << ", " << v[m] << ", " << v[u] << "\n\n";
        } 
    }
    return u;
}
int first_larger(vector<int> &v, int l, int u, int x)
{
    u = bin_search(v, l, u, x);
    while (u!=0 && v[u-1]==x)
    {
        u = u-1;
    }
    return u;
}
void show_vec(vector<int> v, int l, int u)
{
    cout << "{ ";
    for (int i=l; i<u-1; i++)
    {
        cout << v[i] << ", ";
    }
    cout << v[u-1] << " }\n";
}
void show_vec(vector<int> v)
{
    show_vec(v,0,v.size());
}

void swap_sections(vector<int> &v, int l1, int l2, int d)
{
    for (int i=0; i<d; i++)
    {
        iter_swap(v.begin()+(l1+i),v.begin()+(l2+i));
    }
}

void swap_until(vector<int> &v, int l, int m, int u)
{
    int ul, ll;
    ul = u-m;
    ll = m-l;
    int i=0;
    while (i<10 && ll!=ul)
    {
        i++;
        if (ll<ul)
        {
            swap_sections(v, l, m, ll);
            l = l + ll;
            m = m + ll;
        }
        else
        {
            swap_sections(v, l, m, ul);
            l = l + ul;
        }
        ul = u-m;
        ll = m-l;
    }
    swap_sections(v, l, m, ul);
}

vector<vector<int>> merge_step(vector<int> &v, vector<int>rem)
// int * merge_step(vector<int> &v, int l, int m, int u)
{ // takes a vector v passed by reference and a range of three indeces representing two contiguous subsections of v, performs a single step of mergesort and returns the indeces representing sections remaining to be sorted.
    // if (u-m>=m-l-1)
    int l,m,u;
    l = rem[0];
    m = rem[1];
    u = rem[2];
    if (true)
    {
        if (v[m-1]<=v[m])
        { // sections are already oredered
            return vector<vector<int>> {{-1},{-1}};
        }
        else
        { // split the second section in half
            int m2 = (u+m-1)/2;
            // cout << "m2 = " << m2 << "\n";
            int m1 = first_larger(v,l,m-1,v[m2]);
            // cout << "m1 = " << m1 << "\n";
            swap_until(v, m1, m, m2+1); // if m1=m this does nothing.
            return vector<vector<int>> {{l,m1,m2-(m-m1)+1},{m2-(m-m1)+1,m2+1,u}};
        }
    }
    return vector<vector<int>> {{-1},{-1}};
}

void merge_until(vector<int> &v, int l, int m, int u)
{ // pseudo-recursively calls merge_step, which merge_step returns indexes to be sorted. This completes a merge 
    vector<vector<vector<int>>> rems {{{}}};
    vector<vector<vector<int>>> rems_tmp = vector<vector<vector<int>>> {{ {l,m,u}, {-1}}};
    int i = 0;
    int max_iter = v.size()*v.size();
    while(i<max_iter && rems.size()>0)
    {
        i++;
        rems = {};
        for (auto rem:rems_tmp)
        {
            // show_vec(rem[0]);
            // show_vec(rem[1]);
            if (rem[0].size()>1)
            {
                if ( rem[0][0]!=rem[0][1] && rem[0][1]!=rem[0][2])
                {
                    rems.push_back(merge_step(v,rem[0]));
                    // show_vec(v);
                }
            }
            if (rem[1].size()>1)
            {
                if ( rem[1][0]!=rem[1][1] && rem[1][1]!=rem[1][2])
                {
                    rems.push_back(merge_step(v,rem[1]));
                    // show_vec(v);
                }
            }
        }
        rems_tmp = rems;
    }
}

void merge_sort(vector<int> &v)
{ 
    int width = 2;
    int low, mid, hig;
    int range;
    // the largest multiple of w that doesn't exceed l,
    // (l/w) * l.
    // merge_until( v, v.size()/width, v.size()/width+width, v.size() );
    // merge_until( v, 0, 1, 2);
    // merge_until( v, 7, 8, 9);
    while (width<v.size())
    {
        // cout << "width: " << width << endl;
        range = v.size()/width;
        for (int i=0; i<range; i++)
        {
            low = i*width;
            mid = low+width/2;
            hig = low+width;
            // cout << low << ", " << mid << ", " << hig << endl;
            merge_until(v, low, mid, hig);
        }
        show_vec(v);
        width = width*2;
    }
    if (v.size()%width!=0)
    {
        low = 0;
        mid = hig;
        hig = v.size();
        // cout << low << ", " << mid << ", " << hig << endl;
        merge_until(v, low, mid, hig);
    }
    else
    {
        low = 0;
        mid = width/2;
        hig = width;
        // cout << low << ", " << mid << ", " << hig << endl;
        merge_until(v, low, mid, hig);
    }

}