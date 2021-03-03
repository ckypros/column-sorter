// Charles Kypros
// CS 2600 Systems Programming
// Column Sort Program

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Struct is use to hold data columns read from a CSV in this program
struct Input
{
    char item[3][30];
};

int getFileLineCount(const char* filename);
void loadData(struct Input data[], int numDataRows, const char* fileName);
void merge(struct Input data[], int leftIndex, int middleIndex, int rightIndex, int colNum);
void mergeSort(struct Input data[], int leftIndex, int rightIndex, int colNum);
void printData(struct Input data[], int numDataRows);
void printRow(struct Input dataRow);
void sort(struct Input data[], int size, int colNum);


// Gets the quantity of rows of data to hold
int getFileLineCount(const char* filename) {
    int lineCount = 0;
    FILE *file = fopen(filename, "rb");

    if (file)
    {
        int ch;
        while ((ch = fgetc(file)) != EOF)
        {
            if (ch == '\n') {
                lineCount++;
            }
        }
        lineCount++;
        fclose(file);
    }
    else printf("ERROR: Unable to load file.\n");
    return lineCount;
}


// Loads the data from a csv file into the struct
void loadData(struct Input data[], int numDataRows, const char* fileName)
{
    char line[95];
    FILE* file = fopen(fileName, "rb");
    if (file)
    {
        for (int i = 0; i < numDataRows; ++i) {
            // Capture the row of CSV's
            fgets(line, sizeof(line), file);
            line[strcspn(line, "\r")] = 0;
            line[strcspn(line, "\n")] = 0;

            // Store the CSV's inside the struct's string array
            strcpy(data[i].item[0], strtok(line, ","));
            strcpy(data[i].item[1], strtok(NULL, ","));
            strcpy(data[i].item[2], strtok(NULL, ""));

        }
        fclose(file);
    }
}


// Function used to initiate recursive merge sort without specifying every argument
void sort(struct Input data[], int size, int colNum)
{
    mergeSort(data, 0, size-1, colNum);
}


// Helper function used as a part of mergeSort()
void merge(struct Input data[], int leftIndex, int middleIndex, int rightIndex, int colNum)
{
    // Create left and right array to be used for merge sort back into original array
    int leftArraySize = middleIndex - leftIndex + 1;
    int rightArraySize = rightIndex - middleIndex;
    struct Input leftArray[leftArraySize];
    struct Input rightArray[rightArraySize];

    // Copy data to left and right array, separated by the middleIndex
    for (int i = 0; i < leftArraySize; i++)
        leftArray[i] = data[leftIndex + i];
    for (int i = 0; i < rightArraySize; i++)
        rightArray[i] = data[middleIndex + 1 + i];

    // Using the left and right array index, iterate and merge data to merged array index
    int leftArrayIndex = 0;
    int rightArrayIndex = 0;
    int mergedArrayIndex = leftIndex;

    while (leftArrayIndex < leftArraySize && rightArrayIndex < rightArraySize)
    {
        char* leftData = leftArray[leftArrayIndex].item[colNum];
        char* rightData = rightArray[rightArrayIndex].item[colNum];

        if (strcmp(leftData, rightData) <= 0)
            data[mergedArrayIndex++] = leftArray[leftArrayIndex++];
        else
            data[mergedArrayIndex++] = rightArray[rightArrayIndex++];
    }

    // Remaining items of the array are copied to left and right array
    while (leftArrayIndex < leftArraySize)
    {
        data[mergedArrayIndex++] = leftArray[leftArrayIndex++];
    }

    while (rightArrayIndex < rightArraySize)
    {
        data[mergedArrayIndex++] = rightArray[rightArrayIndex++];
    }
}


// Efficient sorting function using supplied column argument
void mergeSort(struct Input data[], int leftIndex, int rightIndex, int colNum)
{
    if (leftIndex < rightIndex)
    {
        int middleIndex = (leftIndex + rightIndex) / 2;

        // Sort left and right halves of the array recursively, then merge
        mergeSort(data, leftIndex, middleIndex, colNum);
        mergeSort(data, middleIndex + 1, rightIndex, colNum);
        merge(data, leftIndex, middleIndex, rightIndex, colNum);
    }
}


// Prints the data in the struct in its current sorted/unsorted representation
void printData(struct Input data[], int numDataRows)
{
    // Print Column Header
    printf("\n%30s%30s%30s", "COLUMN 1", "COLUMN 2", "COLUMN 3\n");
    printf("==========================================================================================\n");

    // Print Each Row
    for (int i = 0; i < numDataRows; ++i) {
        printRow(data[i]);
    }
    printf("\n");
}


// Prints individual row of data, helper function to printData()
void printRow(struct Input dataRow)
{
    for (int i = 0; i < 3; ++i) {
        printf("%30s", dataRow.item[i]);
    }
    printf("\n");
}


// argv[0] = makefile, arv[1] = <data>.txt file, argv[2] = sort column
int main(int argc, char *argv[])
{
    // Ensure Command Line Arguments is 3
    if (argc == 3)
    {
        const char* FILENAME = argv[1];
        const int SORT_COLUMN = atoi(argv[2]) - 1;
        const int NUM_LINES = getFileLineCount(FILENAME);
        // Ensure col is 1, 2, or 3 -> converted to 0, 1, or 2
        if (SORT_COLUMN < 0 || SORT_COLUMN > 2)
            printf("ERROR: Invalid sort column");
        // Only run if number of lines is > 0
        else if (NUM_LINES > 0)
        {
            struct Input inputs[NUM_LINES];
            loadData(inputs, NUM_LINES, FILENAME);
            sort(inputs, NUM_LINES, SORT_COLUMN);
            printData(inputs, NUM_LINES);
        }
    }
    else
    {
        printf("ERROR: Invalid number of arguments supplied\n");
        printf("Expected format:\t<makefile> <filename>.txt <# 1-3 for sort column #>\n");
    }
}