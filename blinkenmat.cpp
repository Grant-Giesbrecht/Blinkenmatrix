#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <IEGA/string_manip.hpp>
#include <IEGA/KTable.hpp>
#include <sstream>
#include <bitset>
#include <map>

using namespace std;

typedef struct{
	string name;
	int instruction_no;
	int data_bits;
	map <int, map<int, map<int, bool> > > ctrls;
}operation;

typedef struct{
	string name;
	int word;
	int pin;
	bool active_low;
	bool default_off;
}control_line;

/*

*/
bool read_OPF(string opfile){

	vector<string> words;

	size_t line_num = 0;

	//read through file
	ifstream file(opfile.c_str());
	if (file.is_open()) {
		string line;

		while (getline(file, line)) {
			line_num++;

			remove_end_whitespace(line); //Remove whitespace from line

			if (line.length() == 0) continue; //Continue if blank
			if (line.length() >= 2 && line.substr(0, 2) == "//") continue; //Skip comments

			//Parse words
			words = parse(line, " \t*@=");

			//Ensure words exist
			if (words.size() < 1){
				continue;
			}

			if (words[0] == "*"){

				//Ensure correct number of words
				if (words.size() != 4){
					cout << "ERROR: " << opfile << ":Line " << to_string(line_num) << " contains more/less than 4 tokens" << endl;
					return false;
				}

			}else if (words[0] == "@"){

			}

			//Ensure exactly 3 tokens
			if (words.size() == 3){

				key tempkey;
				tempkey.assembly = words[0];
				tempkey.binary = words[1];
				tempkey.ndb = stoi(words[2]);

				keys.push_back(tempkey);

			}else{
				cout << "ERROR: " << opfile << ":Line " << to_string(line_num) << " contains more/less than 3 tokens" << endl;
				return false;
			}


		}
		file.close();
	}else{
		cout << "ERROR: Failed to read '" << opfile << "'." << endl;
		return false;
	}

	return true;
}

int main(int argc, char** argv){



	return 0;
}
