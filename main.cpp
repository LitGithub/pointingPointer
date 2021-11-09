#include <iostream>
#include <array>
using namespace std;

double median(int *point, int size);
void display(int *point, int size);
int main() {
    int arr[999];
    int sizepass;
    int numpass;
    cout << "How many numbers " << endl;
    cin >> sizepass;
    cout << "Type the numbers " << endl;
    for (int i = 0; i < sizepass; i++) {
        cin >> numpass;
        arr[i] = numpass;
    }



    
    cout << median(arr, sizepass) << endl;;
    int e;
    cin >> e;


}

double median(int *point, int size) {
        bool flip = true;
        int start = 0;
       
        int end = size-1;

        while (flip)
        {

            flip = false;
            for (int i = start; i < end; ++i)
            {
                if (*(point + i) > *(point + i + 1)) {
                    swap(*(point + i), *(point + i + 1));
                    flip = true;
                }
                else if (*(point + i) == *(point + i + 1)) {
                    swap(*(point + i), *(point + i + 1));
                    flip = true;
                }
            }
            if (!flip)
                break;
            flip = false;
            --end;
            for (int i = end - 1; i >= start; --i)
            {
                if (*(point + i) > *(point + i + 1)) {
                    swap(*(point + i), *(point + i + 1));
                    flip = true;
                }
                else if (*(point + i) == *(point + i + 1)) {
                    swap(*(point + i), *(point + i + 1));
                    flip = true;
                }
            }
            ++start;
        }
        //cout << sizeof(point);
        display(point, size);
	if (!(size % 2 == 0)) {//odd
        cout << "odd" << endl;
        int midpoint = (size) / 2;
        return (*(point + midpoint));
	}
	else {//even
        cout << "even" << endl;
        int midpoint = (size+1) / 2;
        int mid2 = midpoint - 1;
		//int midpoint = (size + 1)/2;
        return (double(*(point + mid2)) + double(*(point + midpoint))) / 2.0;
	}
    
}

void display(int* point, int size) {
    for (int i = 0; i < size; i++) {
        cout << *(point + i) << ", ";
    }
    cout << endl;
}
