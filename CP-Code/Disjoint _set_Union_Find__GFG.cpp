/*
int find(int par[], int x) {
    // add code here
    if(par[x] == x) return x;
    int leader = find(par, par[x]);
    par[x] = leader; 
    return leader;
}

void unionSet(int par[], int x, int z) {
    // add code here.
    int A = find(par, x);
    int B = find(par, z);
    if(A != B) par[A] = B;
}
*/
// https://www.geeksforgeeks.org/problems/disjoint-set-union-find/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab