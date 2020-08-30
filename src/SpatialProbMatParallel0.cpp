# include <Rcpp.h>
using namespace Rcpp;

# include <RcppParallel.h>

// [[Rcpp::depends(RcppParallel)]]

using namespace RcppParallel;


struct ParallelFunction : public Worker {

  ParallelFunction(const NumericMatrix xMat, const NumericVector Values, int d)
    {}
  ParallelFunction(const ParallelFunction& parallelFunction, Split)
    {}

  void operator()(std::size_t begin, std::size_t end) {}


  // join my value with that of another ParallelFunction
  void join(const ParallelFunction& rhs) {
  }

};



// [[Rcpp::export()]]
NumericMatrix PMatCParallel(NumericMatrix xMat, int d, NumericVector Values) {
  // create the worker
  ParallelFunction parallelFunction(xMat, Values, d);

  // call it with parallelFor
  parallelReduce(0, xMat.nrow(), parallelFunction);

  return NumericMatrix();
}

