// ArrayReversal.cpp : This is the file for the Array Reversal project.

#include <iostream>

// Function prototypes
int* new_int_array(int);
void delete_int_array(int*);
void read_ints(int*, int);
void reverse(int*, int);

// desc: Accepts a non-negative integer "n" as input followed by n amount
// of integers separated by spaces.
// Stores the inputs after the first integer into a dynamic int array
// Prints the values recieved after the first integer in reverse order
// Frees the dynamically allocated memory
int main() {

    // Gather input for the n value
    int n;
    do {
        std::cout << "Input a non-negative integer: ";

        if (!(std::cin >> n)) {
            std::cout << "Error to read integer!\n";
            return 0;
        }
        if (n < 0) {
            std::cout << "Invalid integer!\n";
        }
    } while (n < 0);

    int* array_point = new_int_array(n);
    read_ints(array_point, n);
    reverse(array_point, n);

    // Print out reversed numbers in array
    for (int i = 0; i < n; i++) {
        std::cout << array_point[i] << " ";
    }
    std::cout << std::endl;

    delete_int_array(array_point);
    return 0;
}

// desc: Returns a pointer to an int array with count elements
int* new_int_array(int count) {
    int* array_ptr = new int[count];
    return array_ptr;
}

// desc: Deallocates the int pointed by ptr
void delete_int_array(int* array_ptr) {
    delete[] array_ptr;
}

// desc: Accepts a pointer to an array with count elements
// Takes count amount of integers from the user as input and places them
// in the array identified by the pointer in the order given
void read_ints(int* array_ptr, int count) {
    std::cout << "Please enter integers to place in the array: ";
    for (int i = 0; i < count; i++) {
        int val;
        std::cin >> val;
        array_ptr[i] = val;
    }
}

// desc: Accepts a pointer to an array with count elements
// and reverses the elements of the array pointed
void reverse(int* array_ptr, int count) {
    int i = 0;
    int j = count - 1;

    while (i < j) {
        int temp = array_ptr[i];
        array_ptr[i] = array_ptr[j];
        array_ptr[j] = temp;
        i++;;
        j--;
    }
}

