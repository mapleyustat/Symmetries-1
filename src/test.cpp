
/************************************************************************************************//**
 *  		
 * 	file: 		test.cpp
 * 	contents:   	Test source to use symmetries of vertex object
 * 
 ****************************************************************************************************/

#include <symmap.h>


/**
 *	Test
 */
int main (int argc, char * argv[])
{
   // Initialize vector containing all symmetry functions 
   std::vector<symm_func> symm_func_list;

   symm_func_list.push_back(exch_in);
   symm_func_list.push_back(exch_out);

   // Initialize vertex tensor
   vertex_tensor* vertex = new vertex_tensor(POS_FREQ_COUNT*2, PATCH_COUNT, QN_COUNT);
   
   //vertex(boost::extents[POS_FREQ_COUNT*2][POS_FREQ_COUNT*2][POS_FREQ_COUNT*2][PATCH_COUNT][PATCH_COUNT][PATCH_COUNT][QN_COUNT][QN_COUNT][QN_COUNT][QN_COUNT]);


   

   return 0;
}
