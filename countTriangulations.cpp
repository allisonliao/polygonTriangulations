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

int main() {
    for (int i = 3; i <= 20; i++) {
        printf("i = %d: %d\n",i, countTriangulations(i));
    }
    
    return 1;
}