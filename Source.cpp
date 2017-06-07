#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void main()
{
	ifstream myfile("Anderson-GEDCOM.txt");
	ofstream output("output.txt");
	string level, tag, arguments;
	
	while (!myfile.eof()) {
		myfile >> level >> tag;
		getline(myfile, arguments);

		if (level == "0" && tag == "NOTE") {
			output << "--> " << level << " " << tag << arguments << "\n<-- " << "0|NOTE|Y|" << arguments << endl;
			continue;
		}
		if (level == "0" && tag == "HEAD") {
			output << "--> " << level << " " << tag << arguments << "\n<-- " << "0|HEAD|Y|" << arguments << endl;
			continue;
		}
		if (level == "0" && tag == "TRLR") {
			output << "--> " << level << " " << tag << arguments << "\n<-- " << "0|TRLR|Y|" << arguments << endl;
			continue;
		}
		if (level == "0" && arguments[1] == 'I' && arguments[2] == 'N' && arguments[3] == 'D' && arguments[4] == 'I') {
			output << "--> " << level << " " << tag << arguments << "\n<-- " << "0|INDI|Y|" << tag << endl;
			continue;
		}
		if (level == "0" && arguments[1] == 'F' && arguments[2] == 'A' && arguments[3] == 'M') {
			output << "--> " << level << " " << tag << arguments << "\n<-- " << "0|FAM|Y|" << tag << endl;
			continue;
		}
		if (level == "1" && tag == "NAME") {
			output << "--> " << level << " " << tag << arguments << "\n<-- " << "1|NAME|Y|" << arguments << endl;
			continue;
		}
		if (level == "1" && tag == "SEX") {
			output << "--> " << level << " " << tag << arguments << "\n<-- " << "1|SEX|Y|" << arguments << endl;
			continue;
		}
		if (level == "1" && tag == "BIRT") {
			output << "--> " << level << " " << tag << arguments << "\n<-- " << "1|BIRT|Y|" << arguments << endl;
			continue;
		}
		if (level == "1" && tag == "DEAT") {
			output << "--> " << level << " " << tag << arguments << "\n<-- " << "1|DEAT|Y|" << arguments << endl;
			continue;
		}
		if (level == "1" && tag == "FAMC") {
			output << "--> " << level << " " << tag << arguments << "\n<-- " << "1|FAMC|Y|" << arguments << endl;
			continue;
		}
		if (level == "1" && tag == "FAMS") {
			output << "--> " << level << " " << tag << arguments << "\n<-- " << "1|FAMS|Y|" << arguments << endl;
			continue;
		}
		if (level == "1" && tag == "MARR") {
			output << "--> " << level << " " << tag << arguments << "\n<-- " << "1|MARR|Y|" << arguments << endl;
			continue;
		}
		if (level == "1" && tag == "HUSB") {
			output << "--> " << level << " " << tag << arguments << "\n<-- " << "1|HUSB|Y|" << arguments << endl;
			continue;
		}
		if (level == "1" && tag == "WIFE") {
			output << "--> " << level << " " << tag << arguments << "\n<-- " << "1|WIFE|Y|" << arguments << endl;
			continue;
		}
		if (level == "1" && tag == "CHIL") {
			output << "--> " << level << " " << tag << arguments << "\n<-- " << "1|CHIL|Y|" << arguments << endl;
			continue;
		}
		if (level == "1" && tag == "DIV") {
			output << "--> " << level << " " << tag << arguments << "\n<-- " << "1|DIV|Y|" << arguments << endl;
			continue;
		}
		if (level == "2" && tag == "DATE") {
			output << "--> " << level << " " << tag << arguments << "\n<-- " << "2|DATE|Y|" << arguments << endl;
			continue;
		}
		else {
			output << "--> " << level << " " << tag << arguments << "\n<-- " << level << "|" << tag << "|N|" << arguments << endl;
			continue;
		}
	}
}