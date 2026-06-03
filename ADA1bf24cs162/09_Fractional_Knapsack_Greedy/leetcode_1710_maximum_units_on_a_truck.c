#include <stdlib.h>

// Compare function for qsort to sort in descending order of units per box
int compare(const void* a, const void* b) {
    int* rowA = *(int**)a;
    int* rowB = *(int**)b;
    return rowB[1] - rowA[1]; // Sort descending based on units per box
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize) {
    // Sort boxTypes based on units per box in descending order
    qsort(boxTypes, boxTypesSize, sizeof(int*), compare);
    
    int totalUnits = 0;
    for (int i = 0; i < boxTypesSize; i++) {
        int numBoxes = boxTypes[i][0];
        int unitsPerBox = boxTypes[i][1];
        
        if (truckSize >= numBoxes) {
            totalUnits += numBoxes * unitsPerBox;
            truckSize -= numBoxes;
        } else {
            totalUnits += truckSize * unitsPerBox;
            truckSize = 0;
            break;
        }
    }
    return totalUnits;
}
