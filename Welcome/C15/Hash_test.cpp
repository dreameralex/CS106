using namespace std;
#include <string>
#include <vector>
#include <iostream>

int hashCode_false(const string & str);
int hashCode_real(const string & str);
void print_vec(vector<string> & vec);

int main_testHash(){
    cout << "Test Hash:" << endl;
    string str = "a";


    vector<string>test_input;
    test_input.push_back("a");
    test_input.push_back("b");
    test_input.push_back("c");
    test_input.push_back("ab");
    test_input.push_back("bc");
    test_input.push_back("abc");





    print_vec(test_input);
    vector<string>test_output_false;
    cout << "False Hash:" << endl;
    for (int i = 0; i<test_input.size();i++){
        string temp = to_string(hashCode_false(test_input[i]));
        test_output_false.push_back(temp);
    }
    print_vec(test_output_false);
    cout<< endl;

    cout << "Hash:";

    vector<string>test_output_real;
    cout << "False Hash:" << endl;
    for (int i = 0; i<test_input.size();i++){
        string temp = to_string(hashCode_real(test_input[i]));
        test_output_real.push_back(temp);
    }
    print_vec(test_output_real);
    cout<< endl;


    return -1;
}

int hashCode_false(const string & str){
    int hash = 0;
    int n = str.length();
    for ( int i = 0; i < n; i++){
        hash += str[i];
    }
    return hash;
}


const int HASH_SEED = 5881;
const int HASH_MULTIPLIER = 33;
const int HASH_MASK = unsigned(-1) >> 1;


int hashCode_real(const string & str){
    unsigned hash = HASH_SEED;
    int n = str.length();
    for (int i = 0; i < n; i++){
        hash = HASH_MULTIPLIER * hash + str[i];
    }
    return (hash & HASH_MASK);
}



void print_vec(vector<string> &vec){
    for(auto element: vec){
        std::cout<< element << " ";
    }
    cout << endl;
}









