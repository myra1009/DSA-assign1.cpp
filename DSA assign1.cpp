//Ques1
#include <iostream>
using namespace std;

int main() {
    int A[100], n = 0, choice, pos, value, key;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            cout << "Enter number of elements: ";
            cin >> n;

            cout << "Enter elements:\n";
            for(int i = 0; i < n; i++)
                cin >> A[i];

            cout << "Array created successfully.\n";
            break;

        case 2:
            cout << "Array elements: ";
            for(int i = 0; i < n; i++)
                cout << A[i] << " ";
            cout << endl;
            break;

        case 3:
            cout << "Enter position (1 to " << n + 1 << "): ";
            cin >> pos;

            cout << "Enter value: ";
            cin >> value;

            if(pos < 1 || pos > n + 1) {
                cout << "Invalid position.\n";
                break;
            }

            for(int i = n; i >= pos; i--)
                A[i] = A[i - 1];

            A[pos - 1] = value;
            n++;

            cout << "Element inserted successfully.\n";
            break;

        case 4:
            cout << "Enter position to delete: ";
            cin >> pos;

            if(pos < 1 || pos > n) {
                cout << "Invalid position.\n";
                break;
            }

            for(int i = pos - 1; i < n - 1; i++)
                A[i] = A[i + 1];

            n--;

            cout << "Element deleted successfully.\n";
            break;

        case 5:
            cout << "Enter element to search: ";
            cin >> key;

            {
                int found = -1;

                for(int i = 0; i < n; i++) {
                    if(A[i] == key) {
                        found = i;
                        break;
                    }
                }

                if(found != -1)
                    cout << "Element found at position " << found + 1 << endl;
                else
                    cout << "Element not found.\n";
            }
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while(choice != 6);

    return 0;
}

//Ques2

#include <iostream>
using namespace std;

int main() {
    int A[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++)
        cin >> A[i];

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {

            if(A[i] == A[j]) {

                for(int k = j; k < n - 1; k++)
                    A[k] = A[k + 1];

                n--;
                j--;
            }
        }
    }

    cout << "Array after removing duplicates:\n";

    for(int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}

//Ques3

#include <iostream>
using namespace std;

int main() {
    int A[100], n, k, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Enter K: ";
    cin >> k;

    k = k % n;

    cout << "\n1. Left Rotation";
    cout << "\n2. Right Rotation";
    cout << "\nEnter choice: ";
    cin >> choice;

    if(choice == 1) {
        // Left rotation
        for(int r = 0; r < k; r++) {
            int temp = A[0];

            for(int i = 0; i < n - 1; i++)
                A[i] = A[i + 1];

            A[n - 1] = temp;
        }
    }
    else if(choice == 2) {
        // Right rotation
        for(int r = 0; r < k; r++) {
            int temp = A[n - 1];

            for(int i = n - 1; i > 0; i--)
                A[i] = A[i - 1];

            A[0] = temp;
        }
    }
    else {
        cout << "Invalid choice.";
        return 0;
    }

    cout << "Rotated array:\n";

    for(int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}

//Ques4(a)

#include <iostream>
using namespace std;

int main() {
    int A[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for(int i = 0; i < n; i++)
        cin >> A[i];

    int start = 0;
    int end = n - 1;

    while(start < end) {
        int temp = A[start];
        A[start] = A[end];
        A[end] = temp;

        start++;
        end--;
    }

    cout << "Reversed array:\n";

    for(int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}

//Ques4(b)

#include <iostream>
using namespace std;

int main() {
    int A[10][10], B[10][10], C[10][10];
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;

    if(c1 != r2) {
        cout << "Matrix multiplication is not possible.";
        return 0;
    }

    cout << "Enter first matrix:\n";
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c1; j++)
            cin >> A[i][j];
    }

    cout << "Enter second matrix:\n";
    for(int i = 0; i < r2; i++) {
        for(int j = 0; j < c2; j++)
            cin >> B[i][j];
    }

    // Initialize result matrix
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            C[i][j] = 0;
        }
    }

    // Matrix multiplication
    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++) {
            for(int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Resultant Matrix:\n";

    for(int i = 0; i < r1; i++) {
        for(int j = 0; j < c2; j++)
            cout << C[i][j] << " ";

        cout << endl;
    }

    return 0;
}

//Ques4(c)

#include <iostream>
using namespace std;

int main() {
    int A[10][10], T[10][10];
    int rows, cols;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter matrix:\n";

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            cin >> A[i][j];
    }

    // Find transpose
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            T[j][i] = A[i][j];
    }

    cout << "Transpose of matrix:\n";

    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < rows; j++)
            cout << T[i][j] << " ";

        cout << endl;
    }

    return 0;
}

//Ques5

#include <iostream>
using namespace std;

int main() {
    int A[10][10];
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter matrix elements:\n";

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++)
            cin >> A[i][j];
    }

    // Row sums
    cout << "\nSum of each row:\n";

    for(int i = 0; i < rows; i++) {
        int sum = 0;

        for(int j = 0; j < cols; j++)
            sum += A[i][j];

        cout << "Row " << i + 1 << " = " << sum << endl;
    }

    // Column sums
    cout << "\nSum of each column:\n";

    for(int j = 0; j < cols; j++) {
        int sum = 0;

        for(int i = 0; i < rows; i++)
            sum += A[i][j];

        cout << "Column " << j + 1 << " = " << sum << endl;
    }

    return 0;
}