/********************************************
 MIT License

Copyright (c) 2007 Julie C. Mitchell and the Univerity of Wisconsin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 ********************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>


void Rotate (float* m1, float* rotMatrix) { 

  float x, y, z; 
  
  x=(rotMatrix[0]*m1[0] + rotMatrix[1]*m1[1] + rotMatrix[2]*m1[2]);
  y=(rotMatrix[3]*m1[0] + rotMatrix[4]*m1[1] + rotMatrix[5]*m1[2]);
  z=(rotMatrix[6]*m1[0] + rotMatrix[7]*m1[1] + rotMatrix[8]*m1[2]);

  m1[0]=x;
  m1[1]=y;
  m1[2]=z;

return;}

void InitRotMat (float* RotMatrix, float phi, float theta, float psi) {

	float cpsi,spsi,ctheta,stheta,cphi,sphi;
	
	cpsi = cos(psi);
	spsi = sin(psi);
	
	ctheta = cos(theta);
	stheta = sin(theta);
	
	cphi = cos(phi);
	sphi = sin(phi);

        RotMatrix[0] = (float)(  cpsi*cphi  -  spsi*ctheta*sphi  );
        RotMatrix[1] = (float)( -cpsi*sphi  -  spsi*ctheta*cphi );
        RotMatrix[2] = (float)(  spsi*stheta );

        RotMatrix[3] = (float)(  spsi*cphi  +  cpsi*ctheta*sphi );
        RotMatrix[4] = (float)( -spsi*sphi  +  cpsi*ctheta*cphi );
        RotMatrix[5] = (float)( -cpsi*stheta );

        RotMatrix[6] = (float)(  stheta*sphi );
        RotMatrix[7] = (float)(  stheta*cphi );
        RotMatrix[8] = (float)(  ctheta);

return;}


float Mdist(float* M, float* N){

	float dist, cdist, tr;
	int i;

	tr = 0.0;

	for (i=0;i<9;i++) 
		tr += M[i] * N[i];

	cdist = (tr - 1.0) / 2.0 ;

	if (cdist >   1.0) cdist =  1.0;
	if (cdist <  -1.0) cdist = -1.0;
	
	dist = acos(cdist);
	

return dist;}
