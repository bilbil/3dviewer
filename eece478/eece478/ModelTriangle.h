#ifndef MODELTRIANGLE_H
#define MODELTRIANGLE_H

#include "ModelData.h"

#include <vector>
#include <sstream>
#include <tuple>

using namespace std;

typedef tuple<int,int,int, int, int, double,double,double,double,double,double> tTriangle;

class ModelTriangle: ModelData
{
 public:
  ModelTriangle();
  vector<tTriangle> vTriangle;
  void FormatData();
};

ModelTriangle::ModelTriangle()
{
  this->mType = TRIANGLE;
  this->mBeginTag = "<triangle>";
  this->mEndTag = "</triangle>";
}

void ModelTriangle::FormatData()	
/** implemented formating for Triangle */
{
  int i = 0;
 
  //convert data to expected format
  for(std::vector<string>::iterator it = this->vDataItem.begin(); it != vDataItem.end(); ++it)
  {
    tTriangle NewData;
    std::get<0>(NewData) = atoi((*it).c_str());
    std::get<1>(NewData) = atoi((*(it+1)).c_str());
    std::get<2>(NewData) = atoi((*(it+2)).c_str());

    std::get<3>(NewData) = atoi((*(it+3)).c_str());
    std::get<4>(NewData) = atoi((*(it+4)).c_str());

    std::get<5>(NewData) = atof((*(it+5)).c_str());
    std::get<6>(NewData) = atof((*(it+6)).c_str());
    std::get<7>(NewData) = atof((*(it+7)).c_str());
    std::get<8>(NewData) = atof((*(it+8)).c_str());
    std::get<9>(NewData) = atof((*(it+9)).c_str());
    std::get<10>(NewData) = atof((*(it+10)).c_str());

    this->vTriangle.push_back(NewData);
    it += 10;
  }
  
  //check saved model data
  for(auto j : this->vTriangle)
  {
    cout<<"tuple data: "<<std::get<0>(j)<<", "<<std::get<1>(j)<<", "<<std::get<2>(j)<<", "<<std::get<3>(j)<<", "<<std::get<4>(j)<<", "<<std::get<5>(j)<<", "<<std::get<6>(j)<<", "<<std::get<7>(j)<<", "<<std::get<8>(j)<<", "<<std::get<9>(j)<<", "<<std::get<10>(j)<<endl;
  }
}

#endif
