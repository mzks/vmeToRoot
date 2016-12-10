// C++ file
// make & ./Fill -n filename
//
// Auther Mizukoshi Keita
// 2016.11.29

#include <iostream>
#include <fstream>
#include <string>
#include <TTree.h>
#include <TFile.h>
#include <TString.h>
#include <sstream>
#include <unistd.h>

using namespace std;

const string rawDataDir = "./rawData/";
const string rootDataDir = "./rootData/";

void FillTree(std::string dataFile);

int main(int argc, char* argv[]){

// -- Option Analysis .. ///
	int opt=0;
	string dataFile;
	bool noOpt = true;
	while((opt = getopt(argc,argv,"n:h")) != -1){
		noOpt = false;
		switch(opt){
			case 'n':
				dataFile = optarg;
				break;
			case 'h':
				cout << "./Fill -n <data>" << endl;
				return 0;
			default:
				cout << "./Fill -n <data>" << endl;
				return 0;
		}
	}
	if(noOpt == true){
				cout << "./Fill -n <data>" << endl;
				return 0;
	}

	FillTree(dataFile);
	
	return 0;
}


void FillTree(std::string dataFile){

	cout << dataFile << endl;

	stringstream ssInput;
	stringstream ssOutput;
	ssInput << rawDataDir << dataFile;
	ssOutput << rootDataDir << dataFile << ".root";
	TString inputFile = ssInput.str();
	cout << inputFile << endl;
	TString outputFile= ssOutput.str();
	//auto inputFile = "./rawData/t30";
	//auto outputFile= "./rootData/t30.root";
	TFile *f = new TFile(outputFile,"recreate");

	int charge_bit[8];

	TTree* CSADC = new TTree("CSADC","Charge at each channels");
	CSADC->Branch("charge_bit",charge_bit,"charge_bit[8]/I");

	int total_n_evt = 0;
	ifstream inFile;
	inFile.open(inputFile);
	if(!inFile){cout << "no file" << endl;}

	while(
	inFile >> charge_bit[0]
		>> charge_bit[1]
		>> charge_bit[2]
		>> charge_bit[3]
		>> charge_bit[4]
		>> charge_bit[5]
		>> charge_bit[6]
		>> charge_bit[7]	){
		total_n_evt ++;
		CSADC->Fill();
	}
	CSADC->Write();
	f->Close();
	delete f;
	cout << "Create :" << dataFile << ".root"  << endl;

}
