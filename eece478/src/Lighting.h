#ifndef LIGHTING_H
#define LIGHTING_H

#include <string> 

#include "ModelAbstraction.h"
#include "Interpolate.h"

using namespace std;

///inherits transformation functionality from ModelAbstraction
class Lighting: public ModelAbstraction, public Interpolate
{
 private:
  int                     NumLight;
  string                  LightType;
  bool                    bFunctional;
  float                   LightAmbiance[4] = {0,0,0,1};
  float                   LightDiffuse[4] = {1,1,1,1};
  float                   LightSpecular[4] = {1,1,1,1};
  float                   LightPosition[4] = {0,0,0,1};
  float                   LightDirection[4] = {0,0,1,0};
  float                   LightExponent = 0;
  float                   LightCutoff = 180;
  float                   LightAttenConst = 1;
  float                   LightAttenLinear = 0;
  float                   LightAttenQuadratic = 0;

 public:
  static int              TotalNumLight;
                          Lighting();
  void                    TurnOn();
  void                    TurnOff();
  void                    SetLightParam(float amb[], float spec[], float dif[], float pos[]);
  void                    SetLightParamSpot(float dir[], float exp, float cutoff);
  void                    SetLightAttenuation(string type, float att);
  void                    SetLightAmbient(float[]);
  void                    SetLightSpecular(float[]);
  void                    SetLightDiffuse(float[]);
  void                    SetLightPosition(float[]);
  void                    SetLightDirection(float[]);
  void                    SetLightExponent(float[]);
  void                    SetLightCutoff(float[]);
  void                    SetType(string type);   ///sets lighting type (optional)
  string                  GetType();
  void                    Draw();
  void                    FormatAction();
  void                    FormatData();
  void                    AddCurve(int steps, float ctrlpoint1[], float ctrlpoint2[], float ctrlpoint3[], float ctrlpoint4[]);   /// redirects this to Iterpolate class

};

#endif
