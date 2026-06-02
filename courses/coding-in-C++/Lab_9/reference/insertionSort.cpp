#include <iostream>

// Hilfsfunktion, um das Array im Terminal auszugeben
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Vorgegebenes Array mit 4 Integer-Werten
    int arr[] = {34, 12, 5, 23};
    int n = 4;

    std::cout << "Ausgangsarray: ";
    printArray(arr, n);
    std::cout << "-----------------------" << std::endl;

    // Insertion Sort Algorithmus
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Das Element, das richtig einsortiert werden soll
        int j = i - 1;

        // Verschiebe Elemente, die größer als der 'key' sind,
        // um eine Position nach rechts
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Setze den 'key' an die richtige Stelle

        // Ausgabe nach jedem Sortierschritt
        std::cout << "Schritt " << i << ": ";
        printArray(arr, n);
    }

    std::cout << "-----------------------" << std::endl;
    std::cout << "Sortiertes Array: ";
    printArray(arr, n);

    return 0;
}