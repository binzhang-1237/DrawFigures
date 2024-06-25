#include "DrawFigures.h"

using namespace std;

//from DrawFigures.cpp:
// // for event radar image:
// void DrawFigures::DrawRadar(TH2D *h2, TString OutputFileName)
// {
//     TCanvas *c1 = new TCanvas("c", "", 0, 0, 500, 500);
//     Double_t MarginRatio = 0.23;
//     // Double_t MarginRatio = 0.3;
//     c1->SetBottomMargin(MarginRatio);
//     c1->SetTopMargin(MarginRatio);
//     c1->SetRightMargin(MarginRatio);
//     c1->SetLeftMargin(MarginRatio);
//     gStyle->SetStripDecimals(0); // set number of digits of label same.
//     // gStyle->SetPalette(57);

//     TPad *p1 = (TPad *)c1->cd(1);
//     p1->SetTheta(90.);
//     p1->SetPhi(0.);

//     // cout << "h2->Integral() = " << h2->Integral() << endl;
//     Int_t nb = 99;
//     h2->GetZaxis()->SetLabelSize(0.05);
//     h2->SetLineColor(kBlack);
//     h2->SetContour(nb);
//     h2->SetStats(kFALSE);
//     h2->SetLineColor(kGray);
//     h2->SetLineWidth(1.);

//     // for measured radar image:
//     // Double_t max = 24.;
//     // Double_t min = 0.;
//     Double_t per_cut1 = 0.;
//     Double_t per_cut2 = 1. / nb;
//     // cout << "here1" << endl;

//     // kBird0:
//     //  const Int_t Number = 9;
//     //  Double_t Red[Number] = {0.2082, 0.0592, 0.0780, 0.0232, 0.1802, 0.5301, 0.8186, 0.9956, 0.9764};
//     //  Double_t Green[Number] = {0.1664, 0.3599, 0.5041, 0.6419, 0.7178, 0.7492, 0.7328, 0.7862, 0.9832};
//     //  Double_t Blue[Number] = {0.5293, 0.8684, 0.8385, 0.7914, 0.6425, 0.4662, 0.3499, 0.1968, 0.0539};
//     //  Double_t Stops[Number] = {0.0, 0.120, 0.2600, 0.380, 0.5000, 0.620, 0.7600, 0.880, 1.0000};

//     // kBird1:
//     //  const Int_t Number = 11;
//     //  Double_t Red[Number] = {1., 1., 0.2082, 0.0592, 0.0780, 0.0232, 0.1802, 0.5301, 0.8186, 0.9956, 0.9764};
//     //  Double_t Green[Number] = {1., 1., 0.1664, 0.3599, 0.5041, 0.6419, 0.7178, 0.7492, 0.7328, 0.7862, 0.9832};
//     //  Double_t Blue[Number] = {1., 1., 0.5293, 0.8684, 0.8385, 0.7914, 0.6425, 0.4662, 0.3499, 0.1968, 0.0539};
//     //  Double_t Stops[Number] = {0.0, per_cut2, per_cut2, 0.120, 0.2600, 0.380, 0.5000, 0.620, 0.7600, 0.880, 1.0000};

//     // blue to white:
//     //  const Int_t Number = 3;
//     //  Double_t l1 = 0.7;
//     //  Double_t l2 = 0.3;
//     //  Double_t Red[Number] = {1.,l1, l2};
//     //  Double_t Green[Number] = {1.,l1, l2};
//     //  Double_t Blue[Number] = {1.,1., 1.};
//     //  Double_t Stops[Number] = {0.,per_cut2, 1.};

//     // red to white:
//     const Int_t Number = 3;
//     Double_t l1 = 1.;
//     Double_t l2 = 0.;
//     Double_t Blue[Number] = {1., l1, l2};
//     Double_t Green[Number] = {1., l1, l2};
//     Double_t Red[Number] = {1., 1., 1.};
//     Double_t Stops[Number] = {0., per_cut2, 1.};

//     // yellow to white:
//     //  const Int_t Number = 2;

//     // Double_t Red[Number] = {1.,0.9764};
//     // Double_t Green[Number] = {1.,0.9832};
//     // Double_t Blue[Number] = {1.,0.0539};
//     // Double_t Stops[Number] = {0., 1.};

//     // const Int_t Number = 6;
//     // Double_t Red[Number] = {0.0232, 0.1802, 0.5301, 0.8186, 0.9956, 0.9764};
//     // Double_t Green[Number] = {0.6419, 0.7178, 0.7492, 0.7328, 0.7862, 0.9832};
//     // Double_t Blue[Number] = {0.7914, 0.6425, 0.4662, 0.3499, 0.1968, 0.0539};
//     // Double_t Stops[Number] = {0.0, 0.5000, 0.620, 0.7600, 0.880, 1.0000};

//     h2->Draw("pol z LEGO2");
//     gPad->Modified();
//     gPad->Update();

//     TPaletteAxis *pa = (TPaletteAxis *)h2->FindObject("palette");

//     Double_t PaletteHorizontalShift = -0.06;
//     pa->SetX1NDC(1. - 0.055 + PaletteHorizontalShift);

//     pa->SetX2NDC(1. - 0.01 + PaletteHorizontalShift);
//     Double_t PaletteY1Shift = 0.12;
//     pa->SetY1NDC(0.1 + PaletteY1Shift);
//     pa->SetY2NDC(0.9 - PaletteY1Shift);

//     // cout << "X1 = " << pa->GetX1NDC() << endl;
//     // cout << "X2 = " << pa->GetX2NDC() << endl;
//     // cout << "Y1 = " << pa->GetY1NDC() << endl;
//     // cout << "Y2 = " << pa->GetY2NDC() << endl;
//     pa->SetLabelSize(0.01);

//     Int_t ci;      // for color index setting
//     TColor *color; // for color definition with alpha
//     ci = TColor::CreateGradientColorTable(Number, Stops, Red, Green, Blue, nb);
//     pa->SetFillColor(ci);
//     pa->SetFillStyle(1001);
//     h2->GetListOfFunctions()->Add(pa, "br");

//     TText *North = new TText();
//     North->SetText(0, 0.65, "North");
//     North->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     North->SetTextAlign(22);
//     North->SetTextSize(0.06);
//     North->Draw("same");

//     TText *South = new TText();
//     South->SetText(0, -0.65, "South");
//     South->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     South->SetTextAlign(22);
//     South->SetTextSize(0.06);
//     South->Draw("same");

//     TText *East = new TText();
//     East->SetText(0.69, 0.01, "East");
//     East->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     East->SetTextAlign(22);
//     East->SetTextSize(0.06);
//     East->Draw("same");

//     TText *West = new TText();
//     West->SetText(-0.71, 0.01, "West");
//     West->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     West->SetTextAlign(22);
//     West->SetTextSize(0.06);
//     West->Draw("same");

//     c1->SaveAs(OutputFileName);
// }

// void DrawFigures::DrawRadar(TH2D *h2, TString OutputFileName, Double_t density)
// {
//     TCanvas *c1 = new TCanvas("c", "", 0, 0, 500, 500);
//     Double_t VerticalMarginRatio = 0.23;
//     Double_t HorizontalMarginRatio = 0.23;
//     c1->SetBottomMargin(VerticalMarginRatio);
//     c1->SetTopMargin(VerticalMarginRatio);
//     c1->SetRightMargin(HorizontalMarginRatio);
//     c1->SetLeftMargin(HorizontalMarginRatio);
//     gStyle->SetStripDecimals(0); // set number of digits of label same.
//     // gStyle->SetPalette(72);
//     //  gStyle->SetLineColor(kBlack);

//     TPad *p1 = (TPad *)c1->cd(1);
//     p1->SetTheta(90.);
//     p1->SetPhi(0.);

//     cout << "h2->Integral() = " << h2->Integral() << endl;
//     h2->GetZaxis()->SetLabelSize(0.05);
//     h2->SetStats(kFALSE);
//     h2->SetLineColor(kGray);
//     h2->SetLineWidth(1.);
//     Int_t nb = 99;
//     h2->SetContour(nb);
//     Double_t max = 2.5;
//     Double_t min = 0.;

//     const Int_t Number = 4;
//     Double_t l = 1.;
//     Double_t per_cut1 = (1. - l * (max - min) / nb - min) / (max - min);
//     Double_t per_cut2 = (1. + l * (max - min) / nb - min) / (max - min);
//     std::cout << "per_cut1: " << per_cut1 << endl;
//     std::cout << "per_cut2: " << per_cut2 << endl;

//     // yellow to red:
//     //  Double_t Red[Number] = {0.9764,1.,1.,1.};
//     //  Double_t Green[Number] = {0.9832,1.,1.,0.};
//     //  Double_t Blue[Number] = {0.0539,1.,1.,0.};
//     //  Double_t Stops[Number] = {0.0,per_cut1,per_cut2,1.};

//     // blue to red:
//     Double_t Red[Number] = {0., 1., 1., 1.};
//     Double_t Green[Number] = {0., 1., 1., 0.};
//     Double_t Blue[Number] = {1., 1., 1., 0.};
//     Double_t Stops[Number] = {0.0, per_cut1, per_cut2, 1.};
//     cout << "################################################" << endl;
//     // cout<<"Hello world: 139"<<endl;

//     // Double_t Red[2] = {0.,  255.};
//     // Double_t Green[2] = {0.,  0.};
//     // Double_t Blue[2] = {255.,  0.};
//     // Double_t Stops[2] = {0., 1.};
//     // cout<<"################################################"<<endl;
//     // cout<<"Hello world"<<endl;

//     // kBird0:
//     // const Int_t Number = 9;
//     // Double_t Red[Number] = {0.2082, 0.0592, 0.0780, 0.0232, 0.1802, 0.5301, 0.8186, 0.9956, 0.9764};
//     // Double_t Green[Number] = {0.1664, 0.3599, 0.5041, 0.6419, 0.7178, 0.7492, 0.7328, 0.7862, 0.9832};
//     // Double_t Blue[Number] = {0.5293, 0.8684, 0.8385, 0.7914, 0.6425, 0.4662, 0.3499, 0.1968, 0.0539};
//     // Double_t Stops[Number] = {0.0, 0.120, 0.2600, 0.380, 0.5000, 0.620, 0.7600, 0.880, 1.0000};

//     // kBird (modified by binzhang):
//     // Double_t cut = 0.7;
//     // cut = (cut - min) / (max - min);
//     // cout << "cut: " << cut << endl;

//     // const Int_t Number = 7;
//     // Double_t Red[Number] = {1, 0.0232, 0.1802, 0.5301, 0.8186, 0.9956, 0.9764};
//     // Double_t Green[Number] = {1., 0.6419, 0.7178, 0.7492, 0.7328, 0.7862, 0.9832};
//     // Double_t Blue[Number] = {1., 0.7914, 0.6425, 0.4662, 0.3499, 0.1968, 0.0539};
//     // Double_t Stops[Number] = {0.0, 0.380, 0.5000, 0.620, 0.7600, 0.880, 1.0000};

//     TPaletteAxis *pa = (TPaletteAxis *)h2->FindObject("palette");
//     Double_t PaletteHorizontalShift = -0.06;
//     pa->SetX1NDC(1. - 0.055 + PaletteHorizontalShift);
//     pa->SetX2NDC(1. - 0.01 + PaletteHorizontalShift);
//     Double_t PaletteY1Shift = 0.12;
//     pa->SetY1NDC(0.1 + PaletteY1Shift);
//     pa->SetY2NDC(0.9 - PaletteY1Shift);
//     cout << "X1 = " << pa->GetX1NDC() << endl;
//     cout << "X2 = " << pa->GetX2NDC() << endl;
//     cout << "Y1 = " << pa->GetY1NDC() << endl;
//     cout << "Y2 = " << pa->GetY2NDC() << endl;
//     pa->SetLabelSize(0.01);
//     Int_t ci;      // for color index setting
//     TColor *color; // for color definition with alpha
//     ci = TColor::CreateGradientColorTable(Number, Stops, Red, Green, Blue, nb);
//     pa->SetFillColor(ci);
//     pa->SetFillStyle(1001);
//     h2->GetListOfFunctions()->Add(pa, "br");

//     h2->Draw("pol z LEGO2");
//     gPad->Modified();
//     gPad->Update();
//     // std::cout << "here" << endl;

//     TText *North = new TText();
//     North->SetText(0, 0.65, "North");
//     North->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     North->SetTextAlign(22);
//     North->SetTextSize(0.06);
//     North->Draw("same");

//     TText *South = new TText();
//     South->SetText(0, -0.65, "South");
//     South->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     South->SetTextAlign(22);
//     South->SetTextSize(0.06);
//     South->Draw("same");

//     TText *East = new TText();
//     East->SetText(0.69, 0.01, "East");
//     East->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     East->SetTextAlign(22);
//     East->SetTextSize(0.06);
//     East->Draw("same");

//     TText *West = new TText();
//     West->SetText(-0.71, 0.01, "West");
//     West->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     West->SetTextAlign(22);
//     West->SetTextSize(0.06);
//     West->Draw("same");

//     TLatex *Density = new TLatex();
//     Density->SetText(-0.71, 0.63, TString::Format("%.1f g/cm^{3}", density));
//     Density->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     Density->SetTextAlign(22);
//     // Density->SetTextColor(kRed);
//     Density->SetTextSize(0.08);
//     Density->Draw("same");

//     Int_t Index = round(density / 0.7);
//     std::cout << "Index: " << Index << std::endl;
//     TString FigureIndex[9] = {"a", "b", "c", "d", "none", "e", "f", "g", "h"};

//     TText *atoh = new TText();
//     atoh->SetText(-0.9, -0.63, "(" + FigureIndex[Index] + ")");
//     atoh->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     atoh->SetTextAlign(22);
//     atoh->SetTextSize(0.10);
//     atoh->Draw("same");

//     c1->SaveAs(OutputFileName);
// }

// void DrawFigures::DrawRadarBlackWhite(TH2D *h2, TString OutputFileName, Double_t density)
// {
//     TCanvas *c1 = new TCanvas("c", "", 0, 0, 500, 500);
//     Double_t MarginRatio = 0.23;
//     // Double_t MarginRatio = 0.3;
//     c1->SetBottomMargin(MarginRatio);
//     c1->SetTopMargin(MarginRatio);
//     c1->SetRightMargin(MarginRatio);
//     c1->SetLeftMargin(MarginRatio);
//     gStyle->SetStripDecimals(0); // set number of digits of label same.

//     TPad *p1 = (TPad *)c1->cd(1);
//     p1->SetTheta(90.);
//     p1->SetPhi(0.);

//     Int_t nb = 99;
//     h2->GetZaxis()->SetLabelSize(0.05);
//     h2->SetLineColor(kBlack);
//     h2->SetContour(nb);
//     h2->SetStats(kFALSE);
//     h2->SetLineColor(kGray);
//     h2->SetLineWidth(1.);

//     h2->Draw("pol z LEGO2");
//     gPad->Modified();
//     gPad->Update();

//     TPaletteAxis *pa = (TPaletteAxis *)h2->FindObject("palette");

//     Double_t PaletteHorizontalShift = -0.06;
//     pa->SetX1NDC(1. - 0.055 + PaletteHorizontalShift);

//     pa->SetX2NDC(1. - 0.01 + PaletteHorizontalShift);
//     Double_t PaletteY1Shift = 0.12;
//     pa->SetY1NDC(0.1 + PaletteY1Shift);
//     pa->SetY2NDC(0.9 - PaletteY1Shift);
//     pa->SetLabelSize(0.01);

//     Double_t per_cut1 = 0.;
//     Double_t per_cut2 = 1. / nb;

//     // black to white:
//     const Int_t Number = 3;
//     Double_t l1 = 1.;
//     Double_t l2 = 0.;
//     Double_t Blue[Number] = {1., l1, 0.};
//     Double_t Green[Number] = {1., l1, 0.};
//     Double_t Red[Number] = {1., 1., 0.};
//     Double_t Stops[Number] = {0., per_cut2, 1.};

//     Int_t ci;      // for color index setting
//     TColor *color; // for color definition with alpha
//     ci = TColor::CreateGradientColorTable(Number, Stops, Red, Green, Blue, nb);
//     pa->SetFillColor(ci);
//     pa->SetFillStyle(1001);
//     h2->GetListOfFunctions()->Add(pa, "br");

//     TH2D *h22 = new TH2D(*h2); // don't draw color bar.
//     delete h2;
//     h22->Draw("pol  LEGO2");

//     TText *North = new TText();
//     North->SetText(0, 0.65, "North");
//     North->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     North->SetTextAlign(22);
//     North->SetTextSize(0.06);
//     North->Draw("same");

//     TText *South = new TText();
//     South->SetText(0, -0.65, "South");
//     South->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     South->SetTextAlign(22);
//     South->SetTextSize(0.06);
//     South->Draw("same");

//     TText *East = new TText();
//     East->SetText(0.69, 0.01, "East");
//     East->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     East->SetTextAlign(22);
//     East->SetTextSize(0.06);
//     East->Draw("same");

//     TText *West = new TText();
//     West->SetText(-0.71, 0.01, "West");
//     West->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     West->SetTextAlign(22);
//     West->SetTextSize(0.06);
//     West->Draw("same");

//     if (density > 0)
//     {
//         TLatex *Density = new TLatex();
//         Density->SetText(-0.71, 0.63, TString::Format("%.1f g/cm^{3}", density));
//         Density->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//         Density->SetTextAlign(22);
//         // Density->SetTextColor(kRed);
//         Density->SetTextSize(0.08);
//         Density->Draw("same");
//     }

//     // Int_t Index = round(density / 0.7);
//     // std::cout << "Index: " << Index << std::endl;
//     // TString FigureIndex[9] = {"a", "b", "c", "d", "none", "e", "f", "g", "h"};

//     // TText *atoh = new TText();
//     // atoh->SetText(-0.9, -0.63, "(" + FigureIndex[Index] + ")");
//     // atoh->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     // atoh->SetTextAlign(22);
//     // atoh->SetTextSize(0.10);
//     // atoh->Draw("same");

//     c1->SaveAs(OutputFileName);
// }

// void DrawFigures::DrawRadarHalf(TH2D *h2, TString OutputFileName, Double_t density)
// {
//     // TCanvas *c1 = new TCanvas("c", "", 0, 0, 500, 500);
//     TCanvas *c1 = new TCanvas("c1", "", 0, 53, 500, 500);
//     c1->SetHighLightColor(2);
//     c1->Range(-1.069167, -1.069167, 1.069167, 1.069167);
//     TView *view1 = TView::CreateView(1);
//     view1->SetRange(-1, -1, 0, 1, 1, 2.625);

//     Double_t VerticalMarginRatio = 0.23;
//     Double_t HorizontalMarginRatio = 0.23;
//     c1->SetBottomMargin(VerticalMarginRatio);
//     c1->SetTopMargin(VerticalMarginRatio);
//     c1->SetRightMargin(HorizontalMarginRatio);
//     c1->SetLeftMargin(HorizontalMarginRatio);
//     gStyle->SetStripDecimals(0); // set number of digits of label same.
//     // gStyle->SetLineColor(kBlack);

//     TPad *p1 = (TPad *)c1->cd(1);
//     p1->SetTheta(90.);
//     p1->SetPhi(0.);

//     cout << "h2->Integral() = " << h2->Integral() << endl;
//     h2->GetZaxis()->SetLabelSize(0.05);
//     h2->SetStats(kFALSE);
//     h2->SetLineColor(kGray);
//     h2->SetLineWidth(1.);
//     Int_t nb = 50;
//     h2->SetContour(nb);

//     // for divided radar image:
//     const Int_t Number = 4;
//     Double_t max = 2.5;
//     Double_t min = 0.;
//     Double_t l = 1.;
//     Double_t per_cut1 = (1. - l * (max - min) / nb - min) / (max - min);
//     Double_t per_cut2 = (1. + l * (max - min) / nb - min) / (max - min);
//     std::cout << "per_cut1: " << per_cut1 << endl;
//     std::cout << "per_cut2: " << per_cut2 << endl;

//     // yellow to red:
//     //  Double_t Red[Number] = {0.9764,1.,1.,1.};
//     //  Double_t Green[Number] = {0.9832,1.,1.,0.};
//     //  Double_t Blue[Number] = {0.0539,1.,1.,0.};
//     //  Double_t Stops[Number] = {0.0,per_cut1,per_cut2,1.};

//     // blue to red:
//     Double_t Red[Number] = {0., 1., 1., 1.};
//     Double_t Green[Number] = {0., 1., 1., 0.};
//     Double_t Blue[Number] = {1., 1., 1., 0.};
//     Double_t Stops[Number] = {0.0, per_cut1, per_cut2, 1.};

//     Int_t ci;      // for color index setting
//     TColor *color; // for color definition with alpha
//     ci = TColor::CreateGradientColorTable(Number, Stops, Red, Green, Blue, nb);

//     TPaletteAxis *pa = (TPaletteAxis *)h2->FindObject("palette");
//     Double_t PaletteHorizontalShift = -0.06;
//     pa->SetX1NDC(1. - 0.055 + PaletteHorizontalShift);
//     pa->SetX2NDC(1. - 0.01 + PaletteHorizontalShift);
//     Double_t PaletteY1Shift = 0.12;
//     pa->SetY1NDC(0.37 + PaletteY1Shift);
//     pa->SetY2NDC(0.9 - PaletteY1Shift);
//     cout << "X1 = " << pa->GetX1NDC() << endl;
//     cout << "X2 = " << pa->GetX2NDC() << endl;
//     cout << "Y1 = " << pa->GetY1NDC() << endl;
//     cout << "Y2 = " << pa->GetY2NDC() << endl;

//     // Double_t Xshift = 0.;
//     // Double_t Yshift = 0.;
//     // pa->SetX1NDC(-0.6 + Xshift);
//     // pa->SetX2NDC(0.6 + Xshift);
//     // pa->SetY1NDC(0. + Yshift);
//     // pa->SetY2NDC(0.2 + Yshift);

//     pa->SetLabelSize(0.01);
//     pa->SetFillColor(ci);
//     pa->SetFillStyle(1001);
//     h2->GetListOfFunctions()->Add(pa, "br");

//     // auto palette2 = new TPaletteAxis(-3., -25, 3., -23, h2);
//     // palette2->SetFillColor(ci);
//     // palette2->SetFillStyle(1001);
//     // palette2->SetLabelSize(0.01);
//     // h2->GetListOfFunctions()->Add(palette2);

//     h2->Draw("pol z LEGO2");
//     gPad->Modified();
//     gPad->Update();
//     // std::cout << "here" << endl;

//     TText *North = new TText();
//     North->SetText(0, 0.65, "North");
//     North->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     North->SetTextAlign(22);
//     North->SetTextSize(0.06);
//     North->Draw("same");

//     // TText *South = new TText();
//     // South->SetText(0, -0.65, "South");
//     // South->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     // South->SetTextAlign(22);
//     // South->SetTextSize(0.06);
//     // South->Draw("same");

//     TText *East = new TText();
//     East->SetText(0.69, 0.01, "East");
//     East->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     East->SetTextAlign(22);
//     East->SetTextSize(0.06);
//     East->Draw("same");

//     TText *West = new TText();
//     West->SetText(-0.71, 0.01, "West");
//     West->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     West->SetTextAlign(22);
//     West->SetTextSize(0.06);
//     West->Draw("same");

//     TLatex *Density = new TLatex();
//     Density->SetText(-0.71, 0.63, TString::Format("%.1f g/cm^{3}", density));
//     Density->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     Density->SetTextAlign(22);
//     // Density->SetTextColor(kRed);
//     Density->SetTextSize(0.08);
//     Density->Draw("same");

//     Int_t Index = round(density / 0.7);
//     std::cout << "Index: " << Index << std::endl;
//     TString FigureIndex[9] = {"a", "b", "c", "d", "none", "e", "f", "g", "h"};

//     // TText *atoh = new TText();
//     // atoh->SetText(-0.9, -0.63, "(" + FigureIndex[Index] + ")");
//     // atoh->SetTextFont(10 * 4 /*Arial*/ + 2 /*scalable and rotate-able hardware fonts*/);
//     // atoh->SetTextAlign(22);
//     // atoh->SetTextSize(0.10);
//     // atoh->Draw("same");

//     c1->SaveAs(OutputFileName);
// }

// void DrawFigures::DrawTGraphErrors(TGraphErrors* ge, TString OutputFileName)
// {
//     ge->GetXaxis()->SetLabelSize(0.05);
//     ge->GetXaxis()->SetTitleSize(0.05);
//     ge->GetXaxis()->SetTitleOffset(1.2);
//     ge->GetXaxis()->CenterTitle(true);
//     ge->GetYaxis()->SetLabelSize(0.05);
//     ge->GetYaxis()->SetTitleSize(0.05);
//     ge->GetYaxis()->SetTitleOffset(1.2);
//     ge->GetYaxis()->CenterTitle(true);
//     ge->SetLineColor(kBlack);
//     ge->SetLineWidth(2);
//     ge->SetMarkerColor(kBlue);
//     ge->SetMarkerStyle(21);

//     TCanvas* c1 = new TCanvas();
//     // gPad->SetLogy();
//     // h1->GetYaxis()->SetMoreLogLabels();
//     // gStyle->SetStripDecimals(0); // set number of digits of label same.
//     // gStyle->SetMaxDigitsY(2);
//     Double_t MarginRatio = 0.15;
//     // ge->GetYaxis()->SetMaxDigits(1.1);
//     // ge->GetYaxis()->SetNoExponent(kFALSE);
//     c1->SetBottomMargin(MarginRatio);
//     c1->SetTopMargin(MarginRatio);
//     c1->SetRightMargin(MarginRatio);
//     c1->SetLeftMargin(MarginRatio);
//     ge->Draw("AL");
//     c1->SaveAs(OutputFileName);
// }

// void DrawFigures::DrawTGraph(TGraph* g, TString OutputFileName)
// {
//     g->GetXaxis()->SetLabelSize(0.05);
//     g->GetXaxis()->SetTitleSize(0.05);
//     g->GetXaxis()->SetTitleOffset(1.2);
//     g->GetXaxis()->CenterTitle(true);
//     g->GetYaxis()->SetLabelSize(0.05);
//     g->GetYaxis()->SetTitleSize(0.05);
//     g->GetYaxis()->SetTitleOffset(1.2);
//     g->GetYaxis()->CenterTitle(true);
//     g->SetLineColor(kBlack);
//     g->SetLineWidth(2);
//     g->SetMarkerColor(kBlue);
//     g->SetMarkerStyle(21);

//     TCanvas* c1 = new TCanvas();
//     // gPad->SetLogy();
//     // h1->GetYaxis()->SetMoreLogLabels();
//     gStyle->SetStripDecimals(0); // set number of digits of label same.
//     // gStyle->SetMaxDigitsY(2);
//     Double_t MarginRatio = 0.15;
//     // ge->GetYaxis()->SetMaxDigits(1.1);
//     g->GetYaxis()->SetNoExponent(kFALSE);
//     c1->SetBottomMargin(MarginRatio);
//     c1->SetTopMargin(MarginRatio);
//     c1->SetRightMargin(MarginRatio);
//     c1->SetLeftMargin(MarginRatio);
//     // g->Draw("ALP");
//     g->Draw("AL");
//     c1->SaveAs(OutputFileName);
// }

void DrawFigures::DrawTH1D(TH1D* h1, TString OutputFileName, bool SetLogy)
{
    // cout << "h1->Integral() = " << h1->Integral() << endl;
    h1->GetXaxis()->SetLabelSize(0.05);
    h1->GetXaxis()->SetTitleSize(0.05);
    h1->GetXaxis()->SetTitleOffset(1.5);
    h1->GetYaxis()->SetLabelSize(0.05);
    h1->GetYaxis()->SetTitleSize(0.05);
    h1->GetYaxis()->SetTitleOffset(1.2);
    h1->GetYaxis()->CenterTitle(true);
    h1->GetXaxis()->CenterTitle(true);
    h1->SetLineColor(kBlack);
    h1->SetLineWidth(2);
    TCanvas* c1 = new TCanvas();
    if (SetLogy)
        gPad->SetLogy();
    // gPad->SetLogx();
    // h1->GetYaxis()->SetMoreLogLabels();
    gStyle->SetStripDecimals(0); // set number of digits of label same.
    Double_t MarginRatio = 0.15;
    c1->SetBottomMargin(MarginRatio);
    c1->SetTopMargin(MarginRatio);
    c1->SetRightMargin(MarginRatio);
    c1->SetLeftMargin(MarginRatio);
    h1->Draw("E");
    c1->SaveAs(OutputFileName);

    delete c1;
}

// void DrawFigures::DrawTH1(TH1* h1, TString OutputFileName)
// {
//     // cout << "h1->Integral() = " << h1->Integral() << endl;
//     h1->GetXaxis()->SetLabelSize(0.05);
//     h1->GetXaxis()->SetTitleSize(0.05);
//     h1->GetXaxis()->SetTitleOffset(1.5);
//     h1->GetYaxis()->SetLabelSize(0.05);
//     h1->GetYaxis()->SetTitleSize(0.05);
//     h1->GetYaxis()->SetTitleOffset(1.2);
//     h1->GetYaxis()->CenterTitle(true);
//     h1->GetXaxis()->CenterTitle(true);
//     h1->SetLineColor(kBlack);
//     h1->SetLineWidth(2);
//     TCanvas* c1 = new TCanvas();
//     // gPad->SetLogy();
//     // gPad->SetLogx();
//     // h1->GetYaxis()->SetMoreLogLabels();
//     gStyle->SetStripDecimals(0); // set number of digits of label same.
//     Double_t MarginRatio = 0.15;
//     c1->SetBottomMargin(MarginRatio);
//     c1->SetTopMargin(MarginRatio);
//     c1->SetRightMargin(MarginRatio);
//     c1->SetLeftMargin(MarginRatio);
//     h1->Draw("E");
//     c1->SaveAs(OutputFileName);
// }

// void DrawFigures::DrawMultiTH1D(std::vector<TH1D*> multi_TH1D, TLegend* leg, TString OutputFileName)
// {
//     if (multi_TH1D.size() == 0) {
//         std::cout << "multi_TH1D is empty!" << std::endl;
//         return;
//     }
//     multi_TH1D[0]->GetXaxis()->SetLabelSize(0.05);
//     multi_TH1D[0]->GetXaxis()->SetTitleSize(0.05);
//     multi_TH1D[0]->GetXaxis()->SetTitleOffset(1.5);
//     multi_TH1D[0]->GetYaxis()->SetLabelSize(0.05);
//     multi_TH1D[0]->GetYaxis()->SetTitleSize(0.05);
//     multi_TH1D[0]->GetYaxis()->SetTitleOffset(1.2);
//     multi_TH1D[0]->GetYaxis()->CenterTitle(true);
//     multi_TH1D[0]->GetXaxis()->CenterTitle(true);
//     multi_TH1D[0]->SetLineWidth(2);
//     TCanvas* c1 = new TCanvas();
//     // gPad->SetLogy();
//     // gPad->SetLogx();
//     // h1->GetYaxis()->SetMoreLogLabels();
//     gStyle->SetStripDecimals(0); // set number of digits of label same.
//     Double_t MarginRatio = 0.15;
//     c1->SetBottomMargin(MarginRatio);
//     c1->SetTopMargin(MarginRatio);
//     c1->SetRightMargin(MarginRatio);
//     c1->SetLeftMargin(MarginRatio);
//     for (size_t i = 0; i < multi_TH1D.size(); i++) {
//         if (i == 0) {
//             multi_TH1D[i]->Draw("E");
//         } else {
//             multi_TH1D[i]->Draw("same");
//         }
//     }
//     leg->Draw("same");
//     c1->SaveAs(OutputFileName);
// }

// void DrawFigures::DrawMultiTGraph(std::vector<TGraph*> multi_TGraph, TLegend* leg, TString OutputFileName)
// {
//     if (multi_TGraph.size() == 0) {
//         std::cout << "multi_TGraph is empty!" << std::endl;
//         return;
//     }
//     multi_TGraph[0]->GetXaxis()->SetLabelSize(0.05);
//     multi_TGraph[0]->GetXaxis()->SetTitleSize(0.05);
//     multi_TGraph[0]->GetXaxis()->SetTitleOffset(1.5);
//     multi_TGraph[0]->GetYaxis()->SetLabelSize(0.05);
//     multi_TGraph[0]->GetYaxis()->SetTitleSize(0.05);
//     multi_TGraph[0]->GetYaxis()->SetTitleOffset(1.2);
//     multi_TGraph[0]->GetYaxis()->CenterTitle(true);
//     multi_TGraph[0]->GetXaxis()->CenterTitle(true);
//     multi_TGraph[0]->SetLineWidth(2);
//     TCanvas* c1 = new TCanvas();
//     // gPad->SetLogy();
//     // gPad->SetLogx();
//     // h1->GetYaxis()->SetMoreLogLabels();
//     gStyle->SetStripDecimals(0); // set number of digits of label same.
//     Double_t MarginRatio = 0.15;
//     c1->SetBottomMargin(MarginRatio);
//     c1->SetTopMargin(MarginRatio);
//     c1->SetRightMargin(MarginRatio);
//     c1->SetLeftMargin(MarginRatio);
//     for (size_t i = 0; i < multi_TGraph.size(); i++) {
//         if (i == 0) {
//             multi_TGraph[i]->Draw("AL*");
//         } else {
//             multi_TGraph[i]->Draw("same L*");
//         }
//     }
//     leg->Draw("same");
//     c1->SaveAs(OutputFileName);
// }

// void DrawFigures::DrawTH2D(TH2D* h2, TString OutputFileName, bool SetLogx, bool SetLogy, bool SetLogz)
// {
//     // cout << "h2->Integral() = " << h2->Integral() << endl;
//     h2->GetXaxis()->SetLabelSize(0.05);
//     h2->GetXaxis()->SetTitleSize(0.05);
//     h2->GetXaxis()->SetTitleOffset(1.5);
//     h2->GetXaxis()->CenterTitle(true);
//     h2->GetYaxis()->SetLabelSize(0.05);
//     h2->GetYaxis()->SetTitleSize(0.05);
//     h2->GetYaxis()->SetTitleOffset(1.2);
//     h2->GetYaxis()->CenterTitle(true);
//     h2->GetZaxis()->CenterTitle(true);

//     // h2->SetLineColor(kRed);
//     // h2->SetLineWidth(2);
//     TCanvas* c1 = new TCanvas();
//     // gStyle->SetPalette(1);
//     if (SetLogx)
//         gPad->SetLogx();
//     if (SetLogy)
//         gPad->SetLogy();
//     if (SetLogz)
//         gPad->SetLogz();

//     gStyle->SetStripDecimals(0); // set number of digits of label same.
//     Double_t MarginRatio = 0.15;
//     c1->SetBottomMargin(MarginRatio);
//     c1->SetTopMargin(MarginRatio);
//     c1->SetRightMargin(MarginRatio);
//     c1->SetLeftMargin(MarginRatio);
//     h2->Draw("colz");
//     c1->SaveAs(OutputFileName);
// }

//from DrawFigures_new.cpp:

void DrawFigures::DrawTH1(TH1* h1, TString output_dir, TString output_file_type)
{
    // cout << "h1->Integral() = " << h1->Integral() << endl;
    h1->GetXaxis()->SetLabelSize(0.05);
    h1->GetXaxis()->SetTitleSize(0.05);
    h1->GetXaxis()->SetTitleOffset(1.5);
    h1->GetYaxis()->SetLabelSize(0.05);
    h1->GetYaxis()->SetTitleSize(0.05);
    h1->GetYaxis()->SetTitleOffset(1.2);
    h1->GetYaxis()->CenterTitle(true);
    h1->GetXaxis()->CenterTitle(true);
    h1->SetLineColor(kBlack);
    h1->SetLineWidth(2);
    TCanvas* c1 = new TCanvas();
    // gPad->SetLogy();
    // gPad->SetLogx();
    // h1->GetYaxis()->SetMoreLogLabels();
    gStyle->SetStripDecimals(0); // set number of digits of label same.
    Double_t MarginRatio = 0.15;
    c1->SetBottomMargin(MarginRatio);
    c1->SetTopMargin(MarginRatio);
    c1->SetRightMargin(MarginRatio);
    c1->SetLeftMargin(MarginRatio);
    h1->Draw("E");

    c1->SaveAs(output_dir + "/" + TString(h1->GetName()) + "." + output_file_type);
    delete c1;
}

void DrawFigures::DrawMultiTH1(std::vector<TH1*> multi_TH1, TLegend* leg, TString output_dir, TString output_file_type)
{
    if (multi_TH1.size() == 0) {
        std::cout << "multi_TH1 is empty!" << std::endl;
        return;
    }
    multi_TH1[0]->GetXaxis()->SetLabelSize(0.05);
    multi_TH1[0]->GetXaxis()->SetTitleSize(0.05);
    multi_TH1[0]->GetXaxis()->SetTitleOffset(1.5);
    multi_TH1[0]->GetYaxis()->SetLabelSize(0.05);
    multi_TH1[0]->GetYaxis()->SetTitleSize(0.05);
    multi_TH1[0]->GetYaxis()->SetTitleOffset(1.2);
    multi_TH1[0]->GetYaxis()->CenterTitle(true);
    multi_TH1[0]->GetXaxis()->CenterTitle(true);
    multi_TH1[0]->SetLineWidth(2);
    TCanvas* c1 = new TCanvas();
    // gPad->SetLogy();
    // gPad->SetLogx();
    // h1->GetYaxis()->SetMoreLogLabels();
    gStyle->SetStripDecimals(0); // set number of digits of label same.
    Double_t MarginRatio = 0.15;
    c1->SetBottomMargin(MarginRatio);
    c1->SetTopMargin(MarginRatio);
    c1->SetRightMargin(MarginRatio);
    c1->SetLeftMargin(MarginRatio);
    for (size_t i = 0; i < multi_TH1.size(); i++) {
        if (i == 0) {
            multi_TH1[i]->Draw("E");
        } else {
            multi_TH1[i]->Draw("same");
        }
    }
    leg->Draw("same");
    c1->SaveAs(output_dir + "/" + TString(multi_TH1[0]->GetName()) + "." + output_file_type);
    delete c1;
}

void DrawFigures::DrawRatioOrDifferencePlot(TH1* h1, TH1* h2, TLegend* leg, TString output_dir, TString output_file_type, TString ratio_or_difference, bool fit_with_linear_function, double xmin_for_fitting, double xmax_for_fitting)
{
    if (ratio_or_difference != "ratio" && ratio_or_difference != "difference") {
        cout << "DrawFigures::DrawRatioOrDifferencePlot():" << endl;
        cout << "wrong ratio_or_difference!!! : " << ratio_or_difference << endl;
        return;
    }
    // cout << "h1->Integral() = " << h1->Integral() << endl;
    h1->GetXaxis()->SetLabelSize(0.05);
    h1->GetXaxis()->SetTitleSize(0.05);
    h1->GetXaxis()->SetTitleOffset(1.5);
    h1->GetYaxis()->SetLabelSize(0.05);
    h1->GetYaxis()->SetTitleSize(0.05);
    h1->GetYaxis()->SetTitleOffset(1.2);
    h1->GetYaxis()->CenterTitle(true);
    h1->GetXaxis()->CenterTitle(true);
    h1->SetLineColor(kBlack);
    h1->SetLineWidth(2);

    TCanvas* c1 = new TCanvas();
    c1->SetCanvasSize(800, 600);
    // gPad->SetLogy();
    // gPad->SetLogx();
    // h1->GetYaxis()->SetMoreLogLabels();
    gStyle->SetStripDecimals(0); // set number of digits of label same.
    Double_t MarginRatio = 0.10;
    c1->SetBottomMargin(MarginRatio);
    c1->SetTopMargin(MarginRatio);
    c1->SetRightMargin(MarginRatio);
    c1->SetLeftMargin(MarginRatio);
    TPad* c1_n4_1 = new TPad("c1_n4_1", "c1_n4_1", 0.01, 0.51, 0.49, 0.99);
    c1_n4_1->Draw();
    c1_n4_1->cd();
    c1_n4_1->Range(-15.05104, -451.1246, 89.96149, 2425.978);
    c1_n4_1->SetFillColor(0);
    c1_n4_1->SetBorderMode(0);
    c1_n4_1->SetBorderSize(2);
    c1_n4_1->SetLeftMargin(0.1433262);
    c1_n4_1->SetRightMargin(0.05676934);
    c1_n4_1->SetTopMargin(0.04495614);
    c1_n4_1->SetBottomMargin(0.1567982);
    c1_n4_1->SetFrameBorderMode(0);
    c1_n4_1->SetFrameBorderMode(0);

    h1->Draw("E");
    h2->Draw("same");
    leg->Draw("same");
    c1->cd();

    TPad* c1_n4_3 = new TPad("c1_n4_3", "c1_n4_3", 0.01, 0.01, 0.49, 0.49);
    c1_n4_3->Draw();
    c1_n4_3->cd();
    c1_n4_3->Range(-14.42418, -0.4067308, 90.58836, 2.224038);
    c1_n4_3->SetFillColor(0);
    c1_n4_3->SetBorderMode(0);
    c1_n4_3->SetBorderSize(2);
    c1_n4_3->SetLeftMargin(0.1373567);
    c1_n4_3->SetRightMargin(0.06273878);
    c1_n4_3->SetTopMargin(0.04714912);
    c1_n4_3->SetBottomMargin(0.1546053);
    c1_n4_3->SetFrameBorderMode(0);
    c1_n4_3->SetFrameBorderMode(0);

    TH1* cloneHist = (TH1*)h1->Clone("cloneHist");
    cloneHist->Sumw2();                 // to make a correct uncertainty calculation.
    if (ratio_or_difference == "ratio") // ratio histogram:
    {
        cloneHist->Divide(h1, h2);
        cloneHist->GetYaxis()->SetTitle("ratio");
        cloneHist->SetMinimum(0.);
        cloneHist->SetMaximum(2.);
    } else // if(ratio_or_difference == "difference"), difference histogram
    {
        cloneHist->Add(h1, h2, 1., -1.);
        cloneHist->GetYaxis()->SetTitle("difference");
    }
    cloneHist->SetStats(false);
    if (fit_with_linear_function) {
        FitHistogram(cloneHist, xmin_for_fitting, xmax_for_fitting);
    }
    cloneHist->Draw("E");
    c1_n4_3->Modified();
    c1->cd();

    c1->SaveAs(output_dir + "/" + TString(h1->GetName()) + "." + output_file_type);
    delete c1;
    delete c1_n4_1;
    delete c1_n4_3;
}

void DrawFigures::DrawTH2(TH2* h2, TString output_dir, TString output_file_type, bool SetLogx, bool SetLogy, bool SetLogz)
{
    // cout << "h2->Integral() = " << h2->Integral() << endl;
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
    TCanvas* c1 = new TCanvas();
    // gStyle->SetPalette(1);
    if (SetLogx)
        gPad->SetLogx();
    if (SetLogy)
        gPad->SetLogy();
    if (SetLogz)
        gPad->SetLogz();

    gStyle->SetStripDecimals(0); // set number of digits of label same.
    Double_t MarginRatio = 0.15;
    c1->SetBottomMargin(MarginRatio);
    c1->SetTopMargin(MarginRatio);
    c1->SetRightMargin(MarginRatio);
    c1->SetLeftMargin(MarginRatio);
    h2->Draw("colz");
    c1->SaveAs(output_dir + "/" + TString(h2->GetName()) + "." + output_file_type);
    delete c1;
}

void DrawFigures::DrawTGraph(TGraph* g, TString output_dir, TString output_file_type, bool SetLogx, bool SetLogy)
{
    g->GetXaxis()->SetLabelSize(0.05);
    g->GetXaxis()->SetTitleSize(0.05);
    g->GetXaxis()->SetTitleOffset(1.2);
    g->GetXaxis()->CenterTitle(true);
    g->GetYaxis()->SetLabelSize(0.05);
    g->GetYaxis()->SetTitleSize(0.05);
    g->GetYaxis()->SetTitleOffset(1.2);
    g->GetYaxis()->CenterTitle(true);
    g->SetLineColor(kBlack);
    g->SetLineWidth(2);
    g->SetMarkerColor(kBlue);
    g->SetMarkerStyle(21);

    TCanvas* c1 = new TCanvas();
    if (SetLogy)
        gPad->SetLogy();
    if (SetLogx)
        gPad->SetLogx();    
    gStyle->SetStripDecimals(0); // set number of digits of label same.
    // gStyle->SetMaxDigitsY(2);
    Double_t MarginRatio = 0.15;
    // ge->GetYaxis()->SetMaxDigits(1.1);
    g->GetYaxis()->SetNoExponent(kFALSE);
    c1->SetBottomMargin(MarginRatio);
    c1->SetTopMargin(MarginRatio);
    c1->SetRightMargin(MarginRatio);
    c1->SetLeftMargin(MarginRatio);
    // g->Draw("ALP");
    g->Draw("AL");
    c1->SaveAs(output_dir + "/" + TString(g->GetName()) + "." + output_file_type);
    delete c1;
}

void DrawFigures::DrawTGraphErrors(TGraphErrors* ge, TString output_dir, TString output_file_type)
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

    TCanvas* c1 = new TCanvas();
    // gPad->SetLogy();
    // h1->GetYaxis()->SetMoreLogLabels();
    // gStyle->SetStripDecimals(0); // set number of digits of label same.
    // gStyle->SetMaxDigitsY(2);
    Double_t MarginRatio = 0.15;
    // ge->GetYaxis()->SetMaxDigits(1.1);
    // ge->GetYaxis()->SetNoExponent(kFALSE);
    c1->SetBottomMargin(MarginRatio);
    c1->SetTopMargin(MarginRatio);
    c1->SetRightMargin(MarginRatio);
    c1->SetLeftMargin(MarginRatio);
    ge->Draw("AL");
    c1->SaveAs(output_dir + "/" + TString(ge->GetName()) + "." + output_file_type);
    delete c1;
}

void DrawFigures::DrawMultiTGraph(std::vector<TGraph*> multi_TGraph, TLegend* leg, TString output_dir, TString output_file_type)
{
    if (multi_TGraph.size() == 0) {
        std::cout << "multi_TGraph is empty!" << std::endl;
        return;
    }
    multi_TGraph[0]->GetXaxis()->SetLabelSize(0.05);
    multi_TGraph[0]->GetXaxis()->SetTitleSize(0.05);
    multi_TGraph[0]->GetXaxis()->SetTitleOffset(1.5);
    multi_TGraph[0]->GetYaxis()->SetLabelSize(0.05);
    multi_TGraph[0]->GetYaxis()->SetTitleSize(0.05);
    multi_TGraph[0]->GetYaxis()->SetTitleOffset(1.2);
    multi_TGraph[0]->GetYaxis()->CenterTitle(true);
    multi_TGraph[0]->GetXaxis()->CenterTitle(true);
    multi_TGraph[0]->SetLineWidth(2);
    TCanvas* c1 = new TCanvas();
    // gPad->SetLogy();
    // gPad->SetLogx();
    // h1->GetYaxis()->SetMoreLogLabels();
    gStyle->SetStripDecimals(0); // set number of digits of label same.
    Double_t MarginRatio = 0.15;
    c1->SetBottomMargin(MarginRatio);
    c1->SetTopMargin(MarginRatio);
    c1->SetRightMargin(MarginRatio);
    c1->SetLeftMargin(MarginRatio);
    for (size_t i = 0; i < multi_TGraph.size(); i++) {
        if (i == 0) {
            multi_TGraph[i]->Draw("AL*");
        } else {
            multi_TGraph[i]->Draw("same L*");
        }
    }
    leg->Draw("same");
    c1->SaveAs(output_dir + "/" + TString(multi_TGraph[0]->GetName()) + "." + output_file_type);
    delete c1;
}

void DrawFigures::DrawMultiTGraphErrors(std::vector<TGraphErrors*> multi_TGraphErrors, TLegend* leg, TString output_dir, TString output_file_type)
{
    if (multi_TGraphErrors.size() == 0) {
        std::cout << "multi_TGraphErrors is empty!" << std::endl;
        return;
    }
    for (size_t i = 0; i < multi_TGraphErrors.size(); i++) {
        multi_TGraphErrors[i]->Sort();
    }
    multi_TGraphErrors[0]->GetXaxis()->SetLabelSize(0.05);
    multi_TGraphErrors[0]->GetXaxis()->SetTitleSize(0.05);
    multi_TGraphErrors[0]->GetXaxis()->SetTitleOffset(1.5);
    multi_TGraphErrors[0]->GetYaxis()->SetLabelSize(0.05);
    multi_TGraphErrors[0]->GetYaxis()->SetTitleSize(0.05);
    multi_TGraphErrors[0]->GetYaxis()->SetTitleOffset(1.2);
    multi_TGraphErrors[0]->GetYaxis()->CenterTitle(true);
    multi_TGraphErrors[0]->GetXaxis()->CenterTitle(true);
    multi_TGraphErrors[0]->SetLineWidth(2);
    TCanvas* c1 = new TCanvas();
    c1->SetGrid();
    // gPad->SetLogy();
    // gPad->SetLogx();
    // h1->GetYaxis()->SetMoreLogLabels();
    gStyle->SetStripDecimals(0); // set number of digits of label same.
    Double_t MarginRatio = 0.15;
    c1->SetBottomMargin(MarginRatio);
    c1->SetTopMargin(MarginRatio);
    c1->SetRightMargin(MarginRatio);
    c1->SetLeftMargin(MarginRatio);
    for (size_t i = 0; i < multi_TGraphErrors.size(); i++) {
        multi_TGraphErrors[i]->SetMarkerStyle(20+i);
        if (i == 0) {
            multi_TGraphErrors[i]->Draw("ALP");
        } else {
            multi_TGraphErrors[i]->Draw("same LP");
        }
    }
    leg->Draw("same");
    c1->SaveAs(output_dir + "/" + TString(multi_TGraphErrors[0]->GetName()) + "." + output_file_type);
    delete c1;
}

void DrawFigures::FitHistogram(TH1* hist, double xmin_for_fitting, double xmax_for_fitting)
{
    if (xmin_for_fitting == 0 && xmax_for_fitting == 0) // defalt range for fitting:
    {
        xmin_for_fitting = hist->GetXaxis()->GetXmin();
        xmax_for_fitting = hist->GetXaxis()->GetXmax();
    }
    cout << "DrawFigures::FitHistogram(): " << endl;
    cout << "xmin_for_fitting: " << xmin_for_fitting << endl;
    cout << "xmax_for_fitting: " << xmax_for_fitting << endl;
    TF1* lineFit = new TF1("lineFit", "[0] + [1]*x", xmin_for_fitting, xmax_for_fitting);
    hist->Fit(lineFit, "R"); // set fit range as defined at TF1, instead of TH1.

    double slope = lineFit->GetParameter(1);
    double slopeError = lineFit->GetParError(1);

    cout << "The fitted slope: " << slope << " +/- " << slopeError << endl;
    delete lineFit;
}

//from DrawFigures_new_from_bat.cpp:

// void DrawFigures::DrawTGraphErrors(TGraphErrors* ge, TString OutputFileName)
// {
//     set_draw_options_of_TGraph(ge);
//     TCanvas* c1 = set_draw_options_of_canvas();
//     ge->Draw("AL");
//     c1->SaveAs(OutputFileName);
//     delete c1;
// }

// void DrawFigures::DrawTGraph(TGraph* g, TString OutputFileName)
// {
//     set_draw_options_of_TGraph(g);
//     TCanvas* c1 = set_draw_options_of_canvas();
//     g->GetYaxis()->SetNoExponent(kFALSE);
//     g->Draw("AP");
//     c1->SaveAs(OutputFileName);
//     delete c1;
// }

// void DrawFigures::DrawTH1D(TH1D* h1, TString OutputFileName)
// {
//     set_draw_options_of_hist(h1);
//     // h1->SetStats(false);
//     TCanvas* c1 = set_draw_options_of_canvas();
//     h1->Draw("E");
//     c1->SaveAs(OutputFileName);
//     delete c1;
// }

void DrawFigures::DrawTwoTH1D(TH1D* h1, TH1D* h2, TString OutputFileName)
{
    set_draw_options_of_hist(h1);
    set_draw_options_of_hist(h2);
    h1->SetStats(false);
    h1->SetLineColor(kBlue);
    h2->SetLineColor(kRed);
    h1->SetTitle((std::string("#color[4]{") + std::string(h1->GetName()) + std::string("} - #color[2]{") + std::string(h2->GetName()) + std::string("}")).c_str()); //// color[4]:blue, color[2]:red
    TCanvas* c1 = set_draw_options_of_canvas();
    h1->Draw("E");
    h2->Draw("same");
    c1->SaveAs(OutputFileName);
    delete c1;
}

void DrawFigures::DrawMultiTH1D(std::vector<TH1D*> multi_TH1D, TLegend* leg, TString OutputFileName)
{
    if (multi_TH1D.size() == 0) {
        std::cout << "multi_TH1D is empty!" << std::endl;
        return;
    }
    set_draw_options_of_hist(multi_TH1D[0]);
    TCanvas* c1 = set_draw_options_of_canvas();
    for (size_t i = 0; i < multi_TH1D.size(); i++) {
        if (i == 0) {
            multi_TH1D[i]->Draw("E");
        } else {
            multi_TH1D[i]->Draw("same");
        }
    }
    leg->Draw("same");
    c1->SaveAs(OutputFileName);
    delete c1;
}

// void DrawFigures::DrawMultiTGraph(std::vector<TGraph*> multi_TGraph, TLegend* leg, TString OutputFileName)
// {
//     if (multi_TGraph.size() == 0) {
//         std::cout << "multi_TGraph is empty!" << std::endl;
//         return;
//     }
//     set_draw_options_of_TGraph(multi_TGraph[0]);
//     TCanvas* c1 = set_draw_options_of_canvas();
//     for (int i = 0; i < multi_TGraph.size(); i++) {
//         if (i == 0) {
//             multi_TGraph[i]->Draw("AL*");
//         } else {
//             multi_TGraph[i]->Draw("same L*");
//         }
//     }
//     leg->Draw("same");
//     c1->SaveAs(OutputFileName);
//     delete c1;
// }

void DrawFigures::DrawTH2D(TH2D* h2, TString OutputFileName, bool SetLogx, bool SetLogy, bool SetLogz)
{
    set_draw_options_of_hist_2D(h2);

    TCanvas* c1 = set_draw_options_of_canvas(SetLogx, SetLogy);
    // gStyle->SetPalette(1);
    if (SetLogz)
        gPad->SetLogz();
    h2->Draw("colz");
    c1->SaveAs(OutputFileName);
    delete c1;
}
