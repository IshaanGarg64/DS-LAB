 //a.Write a program to concatenate one string to another string
// #include <iostream>
// #include <string>
// using namespace std;
// int main(){
//     string s1 = "Hello", s2 = " World";
//     string result = s1 + s2;

//     cout<<result<<endl;
//     return 0;
// }


// //b. Write a program to reverse a string
// #include<iostream>
// #include <string>
// using namespace std;
// int main(){
//     string s;
//     cout<<"Enter the string : ";
//     getline(cin, s);

//     int n = s.length();
//     int start = 0; int end = n-1;
//     while(start < end){
//         char temp = s[start];
//         s[start] = s[end];
//         s[end] = temp;
//         start++;
//         end--;
//     }
//     cout<<s<<endl;
//     return 0;
// }


// // c. Write a program to delete all the vowels from the string
// #include <iostream>
// #include<string>
// using namespace std;
// int main(){
//     string s;
//     cout<<"Enter the string : ";
//     getline (cin, s);

//     string result = "";
//     for(char c : s){
//         if(!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
//          c=='A'||c=='E'||c=='I'||c=='O'||c=='U'))
//         result += c;
//     }
//     cout<<result <<endl;
//     return 0;
// }



// d. Write a program to sort the strings in alphabetical order.
#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    string arr[n];
    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Sorting using simple bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                // Swap
                string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "\nStrings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}


// // e. Write a program to convert a character from uppercase to lowercase
// #include <iostream>
// using namespace std;
// int main(){
//     char c = 'A';
//     c = tolower(c); // gives 'a'

//     cout<<c;
//     return 0;
// }