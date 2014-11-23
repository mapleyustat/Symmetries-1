
/************************************************************************************************//**
 *  		
 * 	file: 		symmap.h
 * 	contents:  	For a given set of symmetries, establish the linking between the 
 * 			vertex tensor and the independent couplings	
 * 
 ****************************************************************************************************/


#ifndef SYMMAP_H
#define SYMMAP_H

#include <symmetries.h>
#include <const.h>

typedef operation (*symm_func)(index_t&); 		///< Symmetry function that acts on an index_t object and alters it 

void swap(int& a, int& b)
{
   int temp = a;
   a = b;
   b = temp;
}
   
   
   /********************* DEFINE SYMMETRIES  ********************/

//----- Antisymmetry

operation exch_in(index_t& ind)
{
   swap(ind.w1_in, ind.w2_in);
   swap(ind.s1_in,ind.s2_in);
   return operation(true,false);
}

operation exch_out(index_t& ind)
{
   ind.w1_out *= -1;
   ind.w1_out += ind.w1_in + ind.w2_in;
   swap(ind.s1_out,ind.s2_out);
   return operation(true,false);
}


#endif 
