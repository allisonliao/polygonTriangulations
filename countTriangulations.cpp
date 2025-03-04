#include <stdio.h>
#include <vector>

using namespace std;

int countTriangulations(int numEdges) {
    int count = 0;
    if (numEdges <= 3) {
        return 1;
    }

    for (int i = 1; i < numEdges - 1; i++) {
        count += countTriangulations(i+1) * countTriangulations(numEdges-i);
    }
    return count;
}

void printDiagonal(int a, int b, int offset) {
    printf("(%d, %d), ", a + offset, b + offset);
}

vector<vector<pair<int, int> > > listTriangulations(int numEdges, int offset) {
    vector<vector<pair<int, int> > > list;
    for (int n = 1; n < numEdges - 1; n++) {
        auto left = listTriangulations(n + 1, offset);
        if (left.empty()) left.push_back(vector<pair<int, int> >());
        auto right = listTriangulations(numEdges - n, n + offset);
        if (right.empty()) right.push_back(vector<pair<int, int> >());
        for (auto i:left) {
            for (auto j:right) {
                vector<pair<int, int> > a = i;
                
                if (n > 1) a.push_back(make_pair(offset, n + offset));
                if (n < numEdges - 2) a.push_back(make_pair(n + offset, numEdges - 1 + offset));
                a.insert(a.end(), j.begin(), j.end()); // concats j to a
                list.push_back(a);
            }
        }
    }
    return list;
}

int main() {
    clock_t start, end;

    printf("Recursively count triangulations without enumeration.\n");
    for (int i = 3; i <= 20; i++) {
        printf("i = %d: %d\n",i, countTriangulations(i));
    }

    printf("First few triangulations of n < 7 polygons enumerated.\n");
    for (int i = 4; i < 10; i++) {
        printf("----------------------%d----------------------\n",i);
        for (auto l : listTriangulations(i, 0)) {
            for (auto p : l) {
                printf("(%d, %d), ", p.first, p.second);
            }
            printf("\n");
        }
    }
    
    printf("Enumerate polygons without printing.\n");
    start = clock();
    for (int i = 3; i <= 20; i++) {
        long size = listTriangulations(i, 0).size();
        end = clock();
        double elapsed = double (end-start) / double(CLOCKS_PER_SEC);
        printf("i = %d: %lu\t\ttime taken: %lf\n",i, size, elapsed);
        start = clock();
    }
    return 1;
}