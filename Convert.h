//
// Created by Peter May on 2023-03-19.
//
#include <iostream>
#include <fstream>
#include <queue>
#include <sstream>
#include <map>
using namespace std;

#ifndef CODING_CHALLENGE_CONVERT_H
#define CODING_CHALLENGE_CONVERT_H


class Convert {
public:

    Convert(char *inputFileName, char *outputFileName) {
        if (fileExists(inputFileName)) {
            if (fileExists(outputFileName)) {
                this->iFileName = inputFileName;
                this->oFileName = outputFileName;
            } else {
                throw invalid_argument("output file doesn't exist or was not found");
            }
        } else {
            throw invalid_argument("output file doesn't exist or was not found");
        }
    };

    Convert(char *inputFileName) {
        if (fileExists(inputFileName)) {
            this->iFileName = inputFileName;
        } else {
            throw invalid_argument("output file doesn't exist or was not found");
        }
    }

    void run() {
        setUp();
        adapt();
    }

private:
    bool fileExists(const char *fileName)
    {
        ifstream infile(fileName);
        return infile.good();
    }

    void setUp() {
        ifstream in(iFileName);
        string nextLine;
        while (getline(in, nextLine)) {
            originalRomanNums.push(nextLine);
            nextLine += "/";
            for (int i = 0; i < nextLine.length(); i++) {
                char temp = nextLine[i];
                romanNumerals.push(temp);
            }
        }
    }

    void adapt() {
        string romanNum1, romanNum2, fill;
        int total = 0;
        int error = 0;
        fill = "/";
        RomanToArabic["I"] = 1;
        RomanToArabic["V"] = 5;
        RomanToArabic["X"] = 10;
        RomanToArabic["L"] = 50;
        RomanToArabic["C"] = 100;
        RomanToArabic["D"] = 500;
        RomanToArabic["M"] = 1000;
        if (not romanNumerals.empty()) {
            romanNum1 = romanNumerals.front();
            romanNumerals.pop();
        }
        while (not romanNumerals.empty()) {
            while (romanNum1 != fill) {
                romanNum2 = romanNumerals.front();
                romanNumerals.pop();
                if (romanNum1 == fill) {
                    convertedValues.push(0);
                    romanNum1 = romanNum2;
                } else if (romanNum2 == fill) {
                    total += RomanToArabic[romanNum1];
                    romanNum2 = romanNumerals.front();
                    romanNumerals.pop();
                    romanNum1 = romanNum2;
                    break;
                } else if (RomanToArabic[romanNum1] < RomanToArabic[romanNum2]) {
                    int temp = RomanToArabic[romanNum2] - RomanToArabic[romanNum1];
                    if (temp == 4 || temp == 5 || temp == 40 || temp == 50 || temp == 400 || temp == 500) {
                        total += temp;
                        romanNum2 = romanNumerals.front();
                        romanNumerals.pop();
                        romanNum1 = romanNum2;
                        if (romanNum2 == fill) {
                            romanNum2 = romanNumerals.front();
                            romanNumerals.pop();
                            romanNum1 = romanNum2;
                            break;
                        }
                    } else {
                        error = -1;
                    }
                } else {
                    total += RomanToArabic[romanNum1];
                    romanNum1 = romanNum2;
                }
            }
            finish(total, error);
            total = 0;
            error = 0;
        }
        total += RomanToArabic[romanNum1];
        finish(total, error);
    }

    void finish(int total, int error) {
        ofstream SetFile(oFileName);
        if (error == 0) {
            SetFile << originalRomanNums.front() << " || " << total << endl;
        } else {
            SetFile << originalRomanNums.front() << " || " << total << "There was an error calculating this value" << endl;
        }
    }

    string iFileName;
    string oFileName;
    queue<char> romanNumerals;
    queue<int> convertedValues;
    queue<string> originalRomanNums;
    map<string, int> RomanToArabic;
};

#endif //CODING_CHALLENGE_CONVERT_H
