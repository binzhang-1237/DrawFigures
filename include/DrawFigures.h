#ifndef DRAWFIGURES_H
#define DRAWFIGURES_H

#include "TH2D.h"
#include "TH1D.h"
#include "TH1.h"
#include "TString.h"
#include "TGraphErrors.h"
#include "TGraph.h"
#include "TLegend.h"
#include <vector>

class DrawFigures
{
public:
    void DrawRadar(TH2D *h2, TString OutputFileName);
    void DrawRadar(TH2D *h2, TString OutputFileName, Double_t density /*g/cm^3*/);
    void DrawRadarBlackWhite(TH2D *h2, TString OutputFileName, Double_t density /*g/cm^3*/);
    void DrawRadarHalf(TH2D *h2, TString OutputFileName, Double_t density /*g/cm^3*/);
    void DrawRadar(TH2D *h2, TString OutputFileName, Int_t nFillColor, Double_t density /*g/cm^3*/);
    // void DrawTH2D(TH2D *h2, TString OutputFileName);
    void DrawTH2D(TH2D *h2, TString OutputFileName, bool SetLogx = false, bool SetLogy = false, bool SetLogz = false);
    void DrawTH1D(TH1D *h1, TString OutputFileName, bool SetLogy = false);
    void DrawTH1(TH1 *h1, TString OutputFileName);
    void DrawTGraphErrors(TGraphErrors *ge, TString OutputFileName);
    void DrawTGraph(TGraph *g, TString OutputFileName);
    void DrawMultiTH1D(std::vector<TH1D*>multi_TH1D, TLegend* leg, TString OutputFileName);
    void DrawMultiTGraph(std::vector<TGraph*>multi_TGraph , TLegend* leg, TString OutputFileName);
    void DrawMultiTGraph(std::vector<TGraph*>multi_TGraph, TLegend* leg, TString OutputFileName , bool LineColor = false);
    void DrawMultiTGraph(std::vector<TGraph*>multi_TGraph, TString* legend_title, TString OutputFileName , bool LineColor = false);

    DrawFigures() {}
    ~DrawFigures() {}

private:
    // TH2D *h2;
    // TString OutputFileName;
};

#endif