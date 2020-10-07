# Question 6
GROUP 2: Luke Fang, Gomes Mikhaiel, Hila Ergys, Ibrat Nazara, Kaur Rupinder


A program that takes a very long 32 bit vigenere encrypted string and after a letter frequency analysis it displays the unencrypted string and the key used



## Usage

```
/*
#
# This program takes a  very longstring and after a frequency analysis it displays the correct key and the decrypted message
#
# A drawback is that in order to run a frequency analysis for a single letter the string has to bee very long
#
#
*/
```

## subArray
The array here holds all the  the elements that are shifted in the ith positios 0,1,2 etc

```c++
std::string sub[32] = {}; // an array that holds the character every (i + 32) positions basically here i am splitting the string so I can find the frequency of each column to find the correct character for each position of the key
    for (int i = 0; i < 32; i++) {
        for (int j = 0 + i; j < str.length();) {
            sub[i] = sub[i] + str.at(j);
            j = j + 32;
        }//for
    }//for
```
## freqArray 
An array that counts the number of occurrences of each character  in the subArray 
```C++

int freq[26][32] = {}; // a 2d array that holds the numbers of occurrences of each sub[] column [26] for the alphabet [32] for the key length
    for (int i = 0; i < 26; i++) {
        for (int k = 0; k < 32; k++) {
            for (int j = 0; j < sub[k].length(); j++) {
                if (alphabet[i] == sub[k].at(j)) {
                    freq[i][k] += 1;
                }//if

            }//for

        }//for
    }//for
```
##  MaxArray
Here we find the position that has the maximum occurances of a character. Since the most use  letter in english is the letter "e" the location of max indicates the position the letter "e" is
```c++
for (int i = 0; i < 32; i++) { // find the position we had the most occurrences of a character

        for (int j = 0; j < 26; j++) {
            if (freq[j][i] > pos[i]) {
                pos[i] = freq[j][i];
                max[i] = j;
            }//if
        }//for
    }//for
```
## Display
To display the decrypted character I follow this formula : encrypted character = modulo(((encrypted character - 'a') - (offset % 32] - 4)) % 26) + 'a';

```C++
for (int i = 0; i < str.length(); i++) { // display the decrypted text after we offset it based on the key

        str[i] = modulo(((str[i] - 'a') - (max[i % 32] - 4)), 26) + 'a';
    }//for

```

![ezgif com-gif-maker (2)](https://user-images.githubusercontent.com/25082236/95329369-d2c0a080-0874-11eb-8f16-579facae63eb.gif)

![code2flow_JDQePN](https://user-images.githubusercontent.com/25082236/95335099-f687e480-087c-11eb-8916-3d3a26a5b3c3.png)




