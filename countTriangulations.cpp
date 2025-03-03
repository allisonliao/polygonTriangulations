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

// void listTriangulations(int numEdges, int offset) {
//     if (numEdges <= 3) return;
    
//     for (int i = 1; i < numEdges - 1; i++) {
//         listTriangulations(i+1, offset);
//         printDiagonal()
//         listTriangulations(numEdges-i, i + offset);
//     }
// }

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
    for (int i = 3; i <= 20; i++) {
        printf("i = %d: %lu\n",i, listTriangulations(i, 0).size());
    }
    return 1;
}