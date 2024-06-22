#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <vector>
#include "Language.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
#include "SplayTree.h"
using namespace std;

int main() {

    double duration1, duration2, duration3, duration4, duration5, duration6, duration7, duration8, duration9, duration10;
    /**
     * Ordered Integer Trees
     */
    //Create Integer Trees of Ordered Values
    BinarySearchTree<int> bstOrdered;
    AVLTree<int> avlOrdered;
    SplayTree<int> splayOrdered;

    //Use for loop to insert 1-100
    for (int i = 1; i < 101; i++) {
        bstOrdered.add(i);
        avlOrdered.add(i);
        splayOrdered.add(i);
    }

    //File output
    ofstream f_out;

    //Ordered BST Find
    f_out.open("../bstOrderedFile.txt"); //Open file to write Ordered BST depths
    //Start the clock to record time of find method
    clock_t start1 = clock();
    for (int i = 1; i < 101; i++) {
        if (f_out) {
            f_out << bstOrdered.find(i) << endl;
        }
    }
    //Close each file
    f_out.close();
    //Calculate the duration of the find method
    duration1 = (clock()-start1)/(double) CLOCKS_PER_SEC;

    //Ordered AVL Tree Find
    f_out.open("../avlOrderedFile.txt");
    clock_t start2 = clock();
    for (int i = 1; i < 101; i++) {
        if (f_out) {
            f_out << avlOrdered.find(i) << endl;
        }
    }
    f_out.close();
    duration2 = (clock()-start2)/(double) CLOCKS_PER_SEC;

    //Ordered Splay Tree Find
    f_out.open("../splayOrderedFile.txt");
    clock_t start3 = clock();
    for (int i = 1; i < 101; i++) {
        if (f_out) {
            f_out << splayOrdered.find(i) << endl;
        }
    }
    f_out.close();
    duration3 = (clock()-start3)/(double) CLOCKS_PER_SEC;

    /**
     * Unordered/Shuffled Trees
     */
    //Create Integer Tress for Unordered Values
    BinarySearchTree<int> bstUnordered;
    AVLTree<int> avlUnordered;
    SplayTree<int> splayUnordered;

    //Vector to store the 1-100 values which will be shuffled, this will be used for all the unordered trees
    vector<int> RandomizedVector;
    for (int i = 1; i < 101; ++ i) {
        RandomizedVector.push_back(i);
    }
    //Shuffle the vector
    shuffle(begin(RandomizedVector), end(RandomizedVector), default_random_engine());

    //Add the shuffled numbers into all the unordered trees
    for (int i = 1; i < 101 ; i++) {
        RandomizedVector.push_back(i);
        bstUnordered.add(RandomizedVector[i]);
        avlUnordered.add(RandomizedVector[i]);
        splayUnordered.add(RandomizedVector[i]);
    }

    //File to record BST Unordered depth
    f_out.open("../bstUnorderedFile.txt");
    clock_t start4 = clock();
    //Unordered BST Find
    for (int i = 1; i < 101 ; i++) {
        f_out << bstUnordered.find(i) << endl;
    }
    f_out.close();
    duration4 = (clock()-start4)/(double) CLOCKS_PER_SEC;

    //Unordered AVL Tree Find
    f_out.open("../avlUnorderedFile.txt");
    clock_t start5 = clock();
    for (int i = 1; i < 101 ; i++) {
        f_out << avlUnordered.find(i) << endl;
    }
    f_out.close();
    duration5 = (clock()-start5)/(double) CLOCKS_PER_SEC;

    //Unordered Splay Tree Find
    f_out.open("../splayUnorderedFile.txt");
    clock_t start6 = clock();
    for (int i = 1; i < 101 ; i++) {
        f_out << splayUnordered.find(i) << endl;
    }
    f_out.close();
    duration6 = (clock()-start6)/(double) CLOCKS_PER_SEC;

    /**
     * Custom Data Type Tree
     */
    //Create Trees of Custom Data Type
    BinarySearchTree<Language> bstCustom;
    AVLTree<Language> avlCustom;
    SplayTree<Language> splayCustom;

    //Declare empty Language vector
    vector<Language> languages;
    string fIn = "../language_file.csv";
    getDataFromFile(fIn, languages);

    //Add the Custom data type
    for(int i = 1; i < languages.size(); i++) {
        bstCustom.add(languages.at(i));
        avlCustom.add(languages.at(i));
        splayCustom.add(languages.at(i));
    }

    //File to record BST Custom data type's depth
    f_out.open("../bstCustomFile.txt");
    clock_t start7 = clock();
    //Custom BST Find
    for(int i = 1; i < languages.size(); i++) {
        if (f_out) {
            f_out << bstCustom.find(languages.at(i)) << endl;
        }
    }
    f_out.close();
    duration7 = (clock()-start7)/(double) CLOCKS_PER_SEC;

    //Custom AVL Find
    f_out.open("../avlCustomFile.txt");
    clock_t start8 = clock();
    for(int i = 1; i < languages.size(); i++) {
        if (f_out) {
            f_out << avlCustom.find(languages.at(i)) << endl;
        }
    }
    f_out.close();
    duration8 = (clock()-start8)/(double) CLOCKS_PER_SEC;

    //Custom Splay Find
    f_out.open("../splayCustomFile.txt");
    clock_t start9 = clock();
    for(int i = 1; i < languages.size(); i++) {
        if (f_out) {
            f_out << splayCustom.find(languages.at(i)) << endl;
        }
    }
    f_out.close();
    duration9 = (clock()-start9)/(double) CLOCKS_PER_SEC;

    /**
     * Custom Data Type Splay Tree, random order, w/ repeat 5 times each
     */
    //Create a Splay Tree of custom data type
    SplayTree<Language> splayCustomRepeat;
    vector<Language> splayCustomRandomizedVector;
    for (int i = 1; i < languages.size(); i++) {
        splayCustomRandomizedVector.push_back(languages.at(i));
    }
    shuffle(begin(splayCustomRandomizedVector), end(splayCustomRandomizedVector), default_random_engine());

    f_out.open("../splayCustomFiveFile.txt");
    //Add the shuffled the custom data into splay
    for (int i = 1; i < languages.size(); i++) {
        splayCustomRandomizedVector.push_back(languages.at(i));
        splayCustomRepeat.add(splayCustomRandomizedVector[i]);
    }
    //Splay Custom Data type w/ repeat find
    clock_t start10 = clock();
    for(int i = 1; i < languages.size(); i++) {
        if (f_out) {
            //Loop to repeat each search five times
            for (int repeat = 0; repeat < 5; repeat++) {
                f_out << splayCustomRepeat.find(languages.at(i)) << endl;
                repeat = repeat;
            }
        }
    }
    f_out.close();
    duration10 = (clock()-start10)/(double) CLOCKS_PER_SEC;

    //Print the result of BST ordered search
    printf("Searching for 0: %d\n", bstOrdered.find(0) );
    printf("Searching for 101: %d\n", bstOrdered.find(101) );
    printf("Searching for 102: %d\n", bstOrdered.find(102) );
    //Print and Style the time of each find method
    printf("-----------------------------------\n");
    printf("BST Ordered: %f seconds\nBST Unordered: %f seconds\nBST Custom: %f seconds\n", duration1, duration4, duration7 );
    printf("-----------------------------------\n");
    printf("AVL Ordered: %f seconds\nAVL Unordered: %f seconds\nAVL Custom: %f seconds\n", duration2, duration5, duration8 );
    printf("-----------------------------------\n");
    printf("Splay Ordered: %f seconds\nSplay Unordered: %f seconds\nSplay Custom: %f seconds\nSplay Custom, Unordered w/ Five Repeat: %f seconds\n", duration3, duration6, duration9, duration10 );
}