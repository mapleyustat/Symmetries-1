
/************************************************************************************************//**
 *  		
 * 	file: 		test.cpp
 * 	contents:   	Test source to use symmetries of vertex object
 * 
 ****************************************************************************************************/

#include <symmap.h>
#include <iostream>

using namespace std;

/**
 *	Test
 */
int main (int argc, char * argv[])
{
   // Initialize vector containing all symmetry functions 
   vector<symm_func_t> symm_func_list;

   symm_func_list.push_back(exch_in);
   symm_func_list.push_back(rot_k);
   symm_func_list.push_back(compl_conj);

   //symm_func_list.push_back(exch_out);

   // Initialize vertex tensor
   shared_ptr<vertex_tensor> vertex(new vertex_tensor(POS_FREQ_COUNT*2, PATCH_COUNT, QN_COUNT));

   // Initialize independent coupling vector
   vector<index_t> ind_cpl_list;


   for(int w1_in = 0; w1_in < 2*POS_FREQ_COUNT; ++w1_in)
      for(int w2_in = 0; w2_in < 2*POS_FREQ_COUNT; ++w2_in)
	 for(int w1_out = 0; w1_out < 2*POS_FREQ_COUNT; ++w1_out)
	    for(int k1_in = 0; k1_in < PATCH_COUNT; ++k1_in)
	       for(int k2_in = 0; k2_in < PATCH_COUNT; ++k2_in)
		  for(int k1_out = 0; k1_out < PATCH_COUNT; ++k1_out)
		     for(int s1_in = 0; s1_in < QN_COUNT; ++s1_in)
			for(int s2_in = 0; s2_in < QN_COUNT; ++s2_in)
			   for(int s1_out = 0; s1_out < QN_COUNT; ++s1_out)
			      for(int s2_out = 0; s2_out < QN_COUNT; ++s2_out)
			      {
				 index_t ind(w1_in, w2_in, w1_out, k1_in, k2_in, k1_out, s1_in, s2_in, s1_out, s2_out);
				 if ( (*vertex)(ind).ind == -1 )  					// if tensor object not yet related to any other
				 {
				    ind_cpl_list.push_back(ind);					// push standard representative into ind_cpl_list
				    int ind_cpl_list_pos =  ind_cpl_list.size() - 1 ; 			// position in ind_cpl_list is size - 1
				    (*vertex)(ind) = ind_cpl_t( ind_cpl_list_pos ); 			// save position with trivial operations
				    operation track_op(false,false);
				    iterate(ind, track_op, *vertex, symm_func_list, ind_cpl_list_pos ); 		// start iterating on index 
				 }
			      }

   std::cout << " Number of tensor indices : " << TENSOR_IND_COUNT << endl;
   std::cout << " Number of independent couplings : " << ind_cpl_list.size() << endl;
   std::cout << " Reduction factor: "	<< 1.0*TENSOR_IND_COUNT/ ind_cpl_list.size() << endl;

   return 0;
}

