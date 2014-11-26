
/************************************************************************************************//**
 *  		
 * 	file: 		symmap.cpp
 * 	contents:   	see symmap.h
 * 
 ****************************************************************************************************/

#include <symmap.h>


void iterate( const index_t& ind, const operation& track_op, vertex_tensor& vertex, std::vector<symm_func_t> symm_func_list , int ind_cpl_list_pos )
{
   for(auto symm_func: symm_func_list) 		// iterate over list of all symmetries specified
   {
      index_t ind_it = ind;			// copy ind
      operation curr_op = symm_func(ind_it) * track_op;	// apply symmetry operation and track operation
      if( vertex(ind_it).ind == -1)		// if resulting tensor index not yet related to any other
      { 
	 vertex(ind_it) = ind_cpl_t(ind_cpl_list_pos, curr_op); 		// relate to position
	 iterate( ind_it, curr_op, vertex, symm_func_list, ind_cpl_list_pos );	// iterate further	
	 ///CHANGE KEEP TRACK OF OPERATIONS !!
      }
   }
}

//----- Antisymmetry

operation exch_in(index_t& ind)
{
   swap(ind.w1_in, ind.w2_in);
   swap(ind.k1_in, ind.k2_in);
   swap(ind.s1_in, ind.s2_in);
   return operation(true,false);
}

operation rot_k(index_t& ind)
{
   ind.k1_in = rot_k_ind_arr[ind.k1_in];
   ind.k2_in = rot_k_ind_arr[ind.k2_in];
   ind.k1_out = rot_k_ind_arr[ind.k1_out];
   return operation(false,false);
}

operation compl_conj(index_t& ind)
{
   ind.w1_in = freq_sign_change(ind.w1_in);
   ind.w2_in = freq_sign_change(ind.w2_in);
   ind.w1_out = freq_sign_change(ind.w1_out);
}

int freq_sign_change(int ind)
{
   return (2*POS_FREQ_COUNT)- ind - 1;
}

//operation exch_out(index_t& ind)
//{
//ind.w1_out *= -1;
//ind.w1_out += ind.w1_in + ind.w2_in;
//swap(ind.s1_out,ind.s2_out);
//return operation(true,false);
//}


void swap(int& a, int& b)
{
   int temp = a;
   a = b;
   b = temp;
}


