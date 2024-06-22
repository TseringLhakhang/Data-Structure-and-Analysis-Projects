//
// Created by Tsering Lhakhang on 10/11/21.
//

#ifndef PROJECT3_LANGUAGE_H
#define PROJECT3_LANGUAGE_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using std::ifstream;
using std::left;
using std::ostream;
using std::right;
using std::setw;
using std::string;
using std::vector;
using namespace std;

/**
 * Class represents columns from WALS languages dataset.
 * Fields:
 * row_number: a unique integer that corresponds to the row.
 * wals_code: a unique string that identifies the individual languages.
 * name: a string that identifies the name of the language.
 * genus: a string that identifies the genus that the language belongs to.
 * family: a string that identifies the family that the language belongs to.
 * macroarea: a string that identifies the macro-area that the language comes from.
 * latitude: a double that identifies the latitude of the location.
 * longitude: a double that identifies the longitude of the location.

 */
class Language {

private:
    //fields:
    int row_number;
    string wals_code, name, genus, family, macroarea;
    double latitude, longitude;

public:
    // Constructors
    Language() {
    }

    Language(int row_number, string wals_code, string name, string genus, string family, string macroarea, double latitude, double longitude) {
        this->row_number = row_number;
        this->wals_code = wals_code;
        this->name = name;
        this->genus = genus;
        this->family = family;
        this->macroarea = macroarea;
        this->latitude = latitude;
        this->longitude = longitude;
    }

    //Getters
    int getRow_number() {
        return row_number;
    }
    string getWals_code() {
        return wals_code;
    }
    string getName() {
        return name;
    }
    string getGenus() {
        return genus;
    }
    string getFamily() {
        return family;
    }
    string getMacroarea() {
        return macroarea;
    }
    double getLatitude() {
        return latitude;
    }
    double getLongitude() {
        return longitude;
    }

    //Setters
    void setRow_number(int row_number) {
        this->row_number = row_number;
    }
    void setWals_code(string wals_code) {
        this->wals_code = wals_code;
    }
    void setName(string name) {
        this->name = name;
    }
    void setGenus(string genus) {
        this->genus = genus;
    }
    void setFamily(string family) {
        this->family = family;
    }
    void setMacroarea(string macroarea) {
        this->macroarea = macroarea;
    }
    void setLatitude(double latitude) {
        this->latitude = latitude;
    }
    void setLongitude(double longitude) {
        this->longitude = longitude;
    }

    /**
     * Overload stream insertion operator, allows for aligned lines
     */
    friend ostream& operator << (ostream& outs, Language lang) {
        outs << left << setw(8) << lang.getRow_number();
        outs << setw(13) << lang.getWals_code();
        outs << setw(20) << lang.getName();
        outs << left << setw(16) << lang.getGenus();
        outs << setw(16) << lang.getFamily();
        outs << setw(17) << lang.getMacroarea();
        outs << setw(13) << lang.getLatitude();
        outs << lang.getLongitude();
        return outs;
    }
/**
     * Overload < operator for object comparison
     */
    friend bool operator < (const Language& lhs, const Language& rhs) {
        return lhs.wals_code < rhs.wals_code;
    }

    /**
     * Overload > operator for object comparison
     */
    friend bool operator > (const Language& lhs, const Language& rhs) {
        return lhs.wals_code > rhs.wals_code;
    }

    /**
     * Overload <= operator for object comparison
     */
    friend bool operator <= (const Language& lhs, const Language& rhs) {
        return lhs.wals_code <= rhs.wals_code;
    }

    /**
     * Overload >= operator for object comparison
     */
    friend bool operator >= (const Language& lhs, const Language& rhs) {
        return lhs.wals_code >= rhs.wals_code;
    }

    /**
     * Overload == operator for object comparison
     */
    friend bool operator == (const Language& lhs, const Language& rhs) {
        // Use the unique field to determine equality
        return lhs.wals_code == rhs.wals_code;
    }
};

/**
 * getDataFromFile method
 * Read the data from file into a vector,
 * read the unnecessary iso-code and glottocode into junk
 */
bool getDataFromFile(string filename, vector<Language>& languages) {
    ifstream fIn;
    fIn.open(filename);

    //Will read and throw header away
    string header;
    getline(fIn, header);

    //Start the counter, to see later if row_number = counter
    int counter = 1;
    while (fIn && fIn.peek() != EOF) {
        //Declare the variables that we are going to read into
        int row_number= -1;
        string wals_code = "Unknown";
        string name = "Unknown";
        string genus = "Unknown";
        string family = "Unknown";
        string macroarea = "Unknown";
        string junk;
        double latitude = 0.0;
        double longitude = 0.0;
        char comma = ',';

        fIn >> row_number; //row_number is an int
        //check if row_number matches up with the counter
        if (row_number != counter) {
            cout << row_number << " != " << counter << endl;
            return false;
        }
        fIn >> comma;
        // These read a string; comma is delimiter.
        getline(fIn, wals_code, ',');
        //Read in junk
        getline(fIn, junk, ','); //iso_code junk column
        getline(fIn, junk, ','); //glottocode junk column
        //Read in name
        getline(fIn, name, ',');
        //Read in genus
        getline(fIn, genus, ',');
        //Read in family
        getline(fIn, family, ',');
        // Read in macroarea, has empty cells
        getline(fIn, macroarea, ',');
        //Read in latitude and longitude dif. because they are doubles
        //Read in latitude
        fIn >> latitude;
        fIn >> comma;
        //Read in longitude
        if (fIn.peek() != '\r' && fIn.peek() != '\n') { //Found in Clayton Cafiero project example
            fIn >> longitude;
        }
        languages.push_back(Language(row_number,wals_code,name,genus,family,macroarea,latitude,longitude));
        counter += 1;
    }
    fIn.close();
}

/**
 * displayMacroareaStat method
 * Will calculate the number of languages that originate
 * from the different macroarea and display them.
 */
void displayMacroareaStat(vector<Language>& languages) {
    int africa = 0;
    int australia = 0;
    int eurasia = 0;
    int northAmerica = 0;
    int papunesia = 0;
    int southAmerica = 0;
    int empty = 0;
    //This is the total languages with known macroarea
    int totalKnownMacroarea = 0;

    //Calculate the total of each macroarea
    for (Language &lang: languages) {
        string macroareaStat = lang.getMacroarea();
        if (macroareaStat.compare("Africa") == 0) {
            africa += 1;
        } else if (macroareaStat.compare("Australia") == 0) {
            australia += 1;
        } else if (macroareaStat.compare("Eurasia") == 0) {
            eurasia += 1;
        } else if (macroareaStat.compare("North America") == 0) {
            northAmerica += 1;
        } else if (macroareaStat.compare("Papunesia") == 0) {
            papunesia += 1;
        } else if (macroareaStat.compare("South America") == 0) {
            southAmerica += 1;
        } else {
            empty += 1;
        }
    }
    //Will add up all the known macroarea
    totalKnownMacroarea = africa + australia + eurasia + northAmerica + papunesia + southAmerica;

    //Display the macroarea data
    cout << left << setw(23) << "Macroarea";
    cout << "Total #" << endl;
    cout << string(30, '.') << endl;
    cout << left << setw(25) << "Africa" << africa << endl;
    cout << left << setw(25) << "Australia" << australia << endl;
    cout << left << setw(25) << "Eurasia" << eurasia << endl;
    cout << left << setw(25) <<  "North America" << northAmerica << endl;
    cout << left << setw(25) <<  "Papunesia" << papunesia << endl;
    cout << left << setw(25) << "South America"  << southAmerica << endl;
    cout << string(30, '.') << endl;
    cout << left << setw(25) << "Total Known Macroarea" <<totalKnownMacroarea << endl;
    cout << left << setw(25) << "Total Unknown Macroarea" << empty << endl;
}

#endif //PROJECT3_LANGUAGE_H
