#ifndef DRAWFIGURES_H
#define DRAWFIGURES_H

#include "TCanvas.h"
#include "TColor.h"
#include "TF1.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TH1.h"
#include "TH1D.h"
#include "TH2.h"
#include "TH2D.h"
#include "TLatex.h"
#include "TLegend.h"
#include <TLegendEntry.h>
#include "TPad.h"
#include "TPaletteAxis.h"
#include "TString.h"
#include "TStyle.h"
#include "TText.h"
#include "TView.h"
#include <TMath.h>
#include <iostream>
#include <vector>

class DrawFigures {
public:
    //from DrawFigures.h:
    void DrawRadar(TH2D* h2, TString OutputFileName);
    void DrawRadar(TH2D* h2, TString OutputFileName, Double_t density /*g/cm^3*/);
    void DrawRadarBlackWhite(TH2D* h2, TString OutputFileName, Double_t density /*g/cm^3*/);
    void DrawRadarHalf(TH2D* h2, TString OutputFileName, Double_t density /*g/cm^3*/);
    void DrawRadar(TH2D* h2, TString OutputFileName, Int_t nFillColor, Double_t density /*g/cm^3*/);
    // void DrawTH2D(TH2D *h2, TString OutputFileName, bool SetLogx = false, bool SetLogy = false, bool SetLogz = false);
    void DrawTH1D(TH1D* h1, TString OutputFileName, bool SetLogy = false);
    // void DrawTH1(TH1 *h1, TString OutputFileName);
    // void DrawTGraphErrors(TGraphErrors *ge, TString OutputFileName);
    // void DrawTGraph(TGraph *g, TString OutputFileName);
    // void DrawMultiTH1D(std::vector<TH1D*>multi_TH1D, TLegend* leg, TString OutputFileName);
    // void DrawMultiTGraph(std::vector<TGraph*>multi_TGraph , TLegend* leg, TString OutputFileName);
    // void DrawMultiTGraph(std::vector<TGraph*>multi_TGraph, TLegend* leg, TString OutputFileName , bool LineColor = false);
    // void DrawMultiTGraph(std::vector<TGraph*>multi_TGraph, TString* legend_title, TString OutputFileName , bool LineColor = false);

    //from DrawFigures_new.h:
    void DrawTH1(TH1* h1, TString OutputDir, TString OutputFileType = "pdf");
    void DrawMultiTH1(std::vector<TH1*> multi_TH1, TLegend* leg, TString OutputDir, TString OutputFileType = "pdf");
    void DrawRatioOrDifferencePlot(TH1* h1, TH1* h2, TLegend* leg, TString OutputDir, TString OutputFileType = "pdf", TString ratio_or_difference = "ratio", bool fit_with_linear_function = false, double xmin_for_fittin = 0., double xmax_for_fitting = 0.);
    void DrawTH2(TH2* h2, TString OutputDir, TString OutputFileType = "pdf", bool SetLogx = false, bool SetLogy = false, bool SetLogz = false);
    void DrawTGraph(TGraph* g, TString OutputDir, TString OutputFileType = "pdf", bool SetLogx = false, bool SetLogy = false);
    void DrawMultiTGraph(std::vector<TGraph*> multi_TGraph, TLegend* leg, TString OutputDir, TString OutputFileType = "pdf" , bool SetLogx = false, bool SetLogy = false);
    void DrawMultiTGraphErrors(std::vector<TGraphErrors*> multi_TGraphErrors, TLegend* leg, TString OutputDir, TString OutputFileType = "pdf");
    void DrawTGraphErrors(TGraphErrors* ge, TString OutputDir, TString OutputFileType = "pdf");
    void FitHistogram(TH1* hist, double xmin_for_fitting, double xmax_for_fitting);

    //from DrawFigures_new_from_bat.h:
    void DrawTH2D(TH2D* h2, TString OutputFileName, bool SetLogx = false, bool SetLogy = false, bool SetLogz = false);
    // void DrawTH1D(TH1D *h1, TString OutputFileName);
    void DrawTwoTH1D(TH1D* h1 /*kBlue*/, TH1D* h2 /*kRed*/, TString OutputFileName);
    // void DrawTGraphErrors(TGraphErrors *ge, TString OutputFileName);
    // void DrawTGraph(TGraph *g, TString OutputFileName);
    void DrawMultiTH1D(std::vector<TH1D*> multi_TH1D, TLegend* leg, TString OutputFileName);
    // void DrawMultiTGraph(std::vector<TGraph *> multi_TGraph, TLegend *leg, TString OutputFileName);

    DrawFigures() { }
    ~DrawFigures() { }

    //from DrawFigures_new_from_bat.h:
private:
    void set_draw_options_of_hist(TH1* h1)
    {
        h1->GetXaxis()->SetLabelSize(0.05);
        h1->GetXaxis()->SetTitleSize(0.05);
        h1->GetXaxis()->SetTitleOffset(1.5);
        h1->GetYaxis()->SetLabelSize(0.05);
        h1->GetYaxis()->SetTitleSize(0.05);
        h1->GetYaxis()->SetTitleOffset(1.2);
        h1->GetYaxis()->CenterTitle(true);
        h1->GetXaxis()->CenterTitle(true);
        // h1->GetYaxis()->SetMoreLogLabels();
        // h1->SetStats(false);
        h1->SetLineColor(kBlue);
        h1->SetLineWidth(2);
    }
    void set_draw_options_of_hist_2D(TH2* h2)
    {
        h2->GetXaxis()->SetLabelSize(0.05);
        h2->GetXaxis()->SetTitleSize(0.05);
        h2->GetXaxis()->SetTitleOffset(1.5);
        h2->GetXaxis()->CenterTitle(true);
        h2->GetYaxis()->SetLabelSize(0.05);
        h2->GetYaxis()->SetTitleSize(0.05);
        h2->GetYaxis()->SetTitleOffset(1.2);
        h2->GetYaxis()->CenterTitle(true);
        h2->GetZaxis()->CenterTitle(true);

        // h2->SetLineColor(kRed);
        // h2->SetLineWidth(2);
    }
    void set_draw_options_of_TGraph(TGraph* ge)
    {
        ge->GetXaxis()->SetLabelSize(0.05);
        ge->GetXaxis()->SetTitleSize(0.05);
        ge->GetXaxis()->SetTitleOffset(1.2);
        ge->GetXaxis()->CenterTitle(true);
        ge->GetYaxis()->SetLabelSize(0.05);
        ge->GetYaxis()->SetTitleSize(0.05);
        ge->GetYaxis()->SetTitleOffset(1.2);
        ge->GetYaxis()->CenterTitle(true);
        ge->SetLineColor(kBlack);
        ge->SetLineWidth(2);
        ge->SetMarkerColor(kBlue);
        ge->SetMarkerStyle(21);
    }
    TCanvas* set_draw_options_of_canvas(bool set_logx_or_not = false, bool set_logy_or_not = false)
    {
        TCanvas* c1 = new TCanvas();
        if (set_logx_or_not)
            gPad->SetLogx();
        if (set_logy_or_not)
            gPad->SetLogy();
        gStyle->SetStripDecimals(0); // set number of digits of label same.
        Double_t MarginRatio = 0.15;
        c1->SetBottomMargin(MarginRatio);
        c1->SetTopMargin(MarginRatio);
        c1->SetRightMargin(MarginRatio);
        c1->SetLeftMargin(MarginRatio);
        return c1;
    }
};


#endif