#include <vector>
#include <tuple>
#include <string>
#include <iostream>
#include "ModelVertice.h"

using namespace std;

ModelVertice::ModelVertice()
{
  this->mType = VERTICE;
  this->mBeginTag = "<vertices>";
  this->mEndTag = "</vertices>";
}

void ModelVertice::FormatData()	
/** 
implemented formating for vertice 
*/
{
  int i = 0;
 
  //convert data to expected format
  for(std::vector<string>::iterator it = this->vDataItem.begin(); it != vDataItem.end(); ++it)
  {
    tVertice NewData = std::make_tuple(i, atof((*it).c_str()),atof((*(it+1)).c_str()),atof((*(it+2)).c_str()));
    this->vVertice.push_back(NewData);
    it += 2;
    i++;
  }
 
#ifdef DEBUG 
  //check saved model data
  for(auto j : this->vVertice)
  {
    cout<<"tuple data: "<<std::get<TVERTICE_X>(j)<<", "<<std::get<TVERTICE_Y>(j)<<", "<<std::get<TVERTICE_Z>(j)<<endl;
  }
#endif
}
