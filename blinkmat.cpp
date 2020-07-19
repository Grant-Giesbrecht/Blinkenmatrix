#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <IEGA/string_manip.hpp>
#include <IEGA/KTable.hpp>
#include <sstream>
#include <bitset>

using namespace std;

/*

*/
bool read_opfile(string keyfile){

	vector<string> words;

	size_t line_num = 0;

	//read through file
	ifstream file(keyfile.c_str());
	if (file.is_open()) {
		string line;

		while (getline(file, line)) {
			line_num++;

			remove_end_whitespace(line); //Remove whitespace from line

			if (line.length() == 0) continue; //Continue if blank
			if (line.length() >= 2 && line.substr(0, 2) == "//") continue; //Skip comments

			//Parse words
			words = parse(line, " \t");

			//Ensure words exist
			if (words.size() < 1){
				continue;
			}

			//Ensure exactly 3 tokens
			if (words.size() == 3){

				key tempkey;
				tempkey.assembly = words[0];
				tempkey.binary = words[1];
				tempkey.ndb = stoi(words[2]);

				keys.push_back(tempkey);

			}else{
				cout << "ERROR: " << keyfile << ":Line " << to_string(line_num) << " contains more/less than 3 tokens" << endl;
				return false;
			}


		}
		file.close();
	}else{
		cout << "ERROR: Failed to read '" << keyfile << "'." << endl;
		return false;
	}

	return true;
}

int main(int argc, char** argv){



	return 0;
}
