#include "jlcxx/jlcxx.hpp"
#include "jlcxx/stl.hpp"

#include "LHAPDF/LHAPDF.h"
#include <iostream>
#include <fstream>

using namespace LHAPDF;
using namespace std;

// PDF* my_mk_PDF(std::string setname, int member)
// {
//    return LHAPDF::mkPDF(setname, member);
// }
class myPDF
{
public:
    myPDF(const std::string &setname = "NNPDF31_lo_as_0130", int member = 0){
        some_pdf = LHAPDF::mkPDF(setname, member);
        return;
    }
    double xfxQ2(int particle_id, double x, double Q2) const { return some_pdf->xfxQ2(particle_id, x, Q2);}
private:
    const PDF* some_pdf;
};

JLCXX_MODULE define_julia_module(jlcxx::Module& mod)
{
    mod.add_type<myPDF>("PDF")
        .constructor<const std::string &, int>()
        .method("xfxQ2", &myPDF::xfxQ2);
    // mod.add_type<PDF>("PDF")
    //     .method("xfxQ2", static_cast<double (LHAPDF::PDF::*)(int, double, double) const>(&PDF::xfxQ2));
    //mod.method("mkPDF", &my_mk_PDF);
    //mod.method("xfxQ2", &my_xfxQ2);
    //mod.method("mkPDF", static_cast<PDF* (LHAPDF::*)(const std::string&, int)>(&LHAPDF::mkPDF));
    //mod.method("mkPDF", static_cast<PDFpdf (*)(const std::string &, int)>(&mkPDF));
}
// JLCXX_MODULE define_julia_module(jlcxx::Module& mod)
// {
//   mod.method("greet", &greet);
// }
