#include <iostream>
#include <string>
#include <cmath>

using namespace std;


union digits_union
{
    int int_num;
    long double double_num;
    unsigned char char_represent[sizeof(long double)];
};


template<typename Type>
Type show_bits(Type num, digits_union bit){



    for (int j = sizeof(num) - 1; j >= 0; j--)
    {
        cout << " ";
        for (int i = 128; i; i >>= 1)
        {
            if (bit.char_represent[j] & i)
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }
        }
    }

    cout << endl;
    return 0;
}

template <class T>
void bit_manip(T, digits_union&);

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Lab Noskov Evgeny.\nTo enter the var type, use \"int\" or \"long double\" " << endl<<endl;

    digits_union number;
    string answer;
    string a;


    while (true) {

        cout << "enter the type of var or \"stop\": ";

        getline(cin, answer);

        if (answer == "int") {
            cout << "enter a number: ";
            cin >> number.int_num;

            show_bits(number.int_num, number);
            bit_manip(number.int_num, number);
            cout<<"number is: "<<number.int_num<<endl;

            getline(cin, answer);
            continue;
        }

        else if (answer == "long double") {
            cout << "enter a number: ";
            cin >> number.double_num;

            show_bits(number.double_num, number);
            bit_manip(number.double_num, number);
            cout<<"number is: "<<number.double_num<<endl;
            getline(cin, answer);
            continue;
        }
        else if(answer == "stop")
            return 0;
        else {
            cout << "u entered wrong argument. Try again " << endl;
            continue;
        }

    }
    return 0;
}


template<class T>
void make_exchange(int signBit1, int signBit2, int groupSize, digits_union &number, T type){
    bool exchBitGr1, exchBitGr2;

    do {
        exchBitGr1 = (number.char_represent[signBit1/8] & int(pow(2, (signBit1%8))));
        exchBitGr2 = (number.char_represent[signBit2/8] & int(pow(2, (signBit2%8))));                    

        if (exchBitGr1 != exchBitGr2) {
            number.char_represent[signBit1/8] += ((exchBitGr1 == 1) ? -1 : 1) * int(pow(2, (signBit1%8)));
            number.char_represent[signBit2/8] += ((exchBitGr2 == 1) ? -1 : 1) * int(pow(2, (signBit2%8)));
        }

        --groupSize; --signBit1; --signBit2;
    } while (groupSize > 0);

    show_bits(type, number);
}


template <class T>
void bit_manip(T type, digits_union &number){
    char answer;
    int signBit1, signBit2;
    int groupSize;
    while(true) {
        cout << "swap groups of bits? (y/n): ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y') {


            while(true) {
                cout<<"enter the high order number for the first group: ";
                cin >> signBit1;
                if (signBit1 >= sizeof (T)*8)
                    cout<<"number is too big, try again\n";
                else if (signBit1<0)
                    cout<<"number is too small, try again\n";
                else
                    break;
            }

            while(true) {
                cout << "enter the high order number for the second group: ";
                cin >> signBit2;
                if (signBit2 >= sizeof (T)*8)
                    cout<<"number is too big, try again\n";
                else if (signBit2<0)
                    cout<<"number is too small, try again\n";
                else
                    break;
            }

            if (signBit1< signBit2)
                swap(signBit1, signBit2);

            while(true) {
                cout << "enter groups size: ";
                cin >> groupSize;
                if (groupSize >= sizeof (T)*8)
                    cout<<"number is too big, try again\n";
                else if (groupSize<0)
                    cout<<"number is too small, try again\n";
                else if (groupSize > (signBit1 - signBit2))
                    cout<<"groups are intersected, try another value\n";
                else
                    break;
            }

            make_exchange(signBit1, signBit2, groupSize, number, type);

        }

        else if (answer == 'n' || answer == 'N')
            return;

        else
            cout << "u entered wrong answer Try again " << endl;
    }
}