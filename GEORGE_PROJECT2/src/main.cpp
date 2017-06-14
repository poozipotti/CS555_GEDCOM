#include "../include/GEDReader.hh"

main(){
	GEDReader AReader("MyFamily.ged");
	AReader.parseFile();
	AReader.outputToFile();
	return 0;
	
};
