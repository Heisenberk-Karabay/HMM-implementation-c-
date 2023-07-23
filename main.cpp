#include <iostream>
#include <array>

using namespace std;


int main() {
    // The possible states
    string states[3] = {"eating", "drinking beer", "smoking cigar"};

    // for now testing on the fixed size data
    string train_data[10] = {states[0], states[0], states[2], states[1], states[1],
                             states[1],states[0],states[0], states[1],states[2]};

    int len_array = end(train_data)-begin(train_data);

    // these are the elements of transition matrix
    float eat_eat = 0;
    float eat_drink = 0;
    float eat_smoke = 0;

    float drink_drink = 0;
    float drink_eat = 0;
    float drink_smoke = 0;

    float smoke_smoke = 0;
    float smoke_drink = 0;
    float smoke_eat = 0;


    for (int i=0 ; i < len_array ; i++) {

        if (train_data[i] == states[0]) {
            if (train_data[i + 1] == states[0]) {
                eat_eat++;
            } else if (train_data[i + 1] == states[1]) {
                eat_drink++;
            } else if (train_data[i + 1] == states[2]) {
                eat_smoke++;
            }
        } else if (train_data[i] == states[1]) {
            if (train_data[i + 1] == states[0]) {
                drink_eat++;
            } else if (train_data[i + 1] == states[1]) {
                drink_drink++;
            } else if (train_data[i + 1] == states[2]) {
                drink_smoke++;
            }
        } else if (train_data[i] == states[2]) {
            if (train_data[i + 1] == states[0]) {
                smoke_eat++;
            } else if (train_data[i + 1] == states[1]) {
                smoke_drink++;
            } else if (train_data[i + 1] == states[2]) {
                smoke_smoke++;
            }
        }
    }


    // i also normalize the values by dividing them with the length of the data
    float transition_matrix[3][3] ={
            {eat_eat/len_array, drink_eat/len_array, smoke_eat/len_array},
            {eat_drink/len_array, drink_drink/len_array, smoke_drink/len_array},
            {eat_smoke/len_array, drink_smoke/len_array, smoke_smoke/len_array},
    };

    cout << "The probability of drinkin beer then again drinking beer then eating is: ";
    cout << (transition_matrix[1][1]) * (transition_matrix[0][1]);
    return 0;
}
