void histVME(TString file){

	ifstream ifs("rawData/"+file); // File name

	//Histgram Settings
	const double HIST_MIN = 0;
	const double HIST_MAX = 16383;
	const double HIST_BIN = 16383;

	double data0; //ch 0
	double data1;
	double data2;
	double data3;
	double data4;
	double data5;
	double data6;
	double data7;

	TH1D* hist0 = new TH1D("ch0","ch0",HIST_BIN,HIST_MIN,HIST_MAX);
	TH1D* hist1 = new TH1D("ch1","ch1",HIST_BIN,HIST_MIN,HIST_MAX);
	TH1D* hist2 = new TH1D("ch2","ch2",HIST_BIN,HIST_MIN,HIST_MAX);
	TH1D* hist3 = new TH1D("ch3","ch3",HIST_BIN,HIST_MIN,HIST_MAX);
	TH1D* hist4 = new TH1D("ch4","ch4",HIST_BIN,HIST_MIN,HIST_MAX);
	TH1D* hist5 = new TH1D("ch5","ch5",HIST_BIN,HIST_MIN,HIST_MAX);
	TH1D* hist6 = new TH1D("ch6","ch6",HIST_BIN,HIST_MIN,HIST_MAX);
	TH1D* hist7 = new TH1D("ch7","ch7",HIST_BIN,HIST_MIN,HIST_MAX);

	while(ifs >> data0 >> data1 >> data2 >> data3 >> data4 >> data5 >> data6 >> data7  ){
		hist0->Fill(data0);
		hist1->Fill(data1);
		hist2->Fill(data2);
		hist3->Fill(data3);
		hist4->Fill(data4);
		hist5->Fill(data5);
		hist6->Fill(data6);
		hist7->Fill(data7);
	}

	//hist->Rebin();
	//
	TCanvas* c1 = new TCanvas("c1","c1",10,10,1200,800);
	c1->cd();
	c1->Divide(4,2);

	c1->cd(1);
	hist0->Draw();
	c1->cd(2);
	hist1->Draw();
	c1->cd(3);
	hist2->Draw();
	c1->cd(4);
	hist3->Draw();
	c1->cd(5);
	hist4->Draw();
	c1->cd(6);
	hist5->Draw();
	c1->cd(7);
	hist6->Draw();
	c1->cd(8);
	hist7->Draw();
	TCanvas* c2 = new TCanvas("c2","c2",10,10,1200,800);
	c2->Divide(2,1);
	c2->cd(1);
	hist0->Draw();
	c2->cd(2);
	hist1->Draw();

}
