// Draw.cc - Root macro
// Author Mizukoshi Keita
// 2016.11.29

#include <iostream>
#include <sstream>
#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TCanvas.h"

TH1D* MakeHist(int ch,TString rootdata); // Input VME output


void Draw(TString rootdata = "NO_FILE"){

	if(rootdata == "NO_FILE"){
		std::cout << "Input root file name (Ex. 't01.root' :";
		std::cin >> rootdata;
	}
		rootdata = "./rootData/" + rootdata;
	
	TCanvas* c1 = new TCanvas("all","all",10,10,1200,800);
	c1->Divide(4,2);
	for(int i=0;i<8;i++){
		c1->cd(i+1);
		(MakeHist(i,rootdata))->Draw();
		 }
}

TH1D* MakeHist(int ch,TString rootdata){

	//Error
	if(ch < 0 || ch > 7){
		std::cout << ch << ": channel not exist" << endl;
	}

	TFile* f=new TFile(rootdata);
	TTree* CSADC=(TTree*)f->Get("CSADC");

	int charge_bit[8];
	CSADC->SetBranchAddress("charge_bit",charge_bit);

	stringstream sshistname;
	sshistname << "ch" << ch;
	TString histname = sshistname.str();

	TH1D* hist = new TH1D(histname,histname,16384,0,16383);

	int nEvent=CSADC->GetEntries();
	for ( int i=0;i<nEvent;i++ ){
		CSADC->GetEntry(i);
		hist->Fill(charge_bit[ch]);
	}
	return hist;
}
		

