
/************************************************************************************************//**
 *  		
 * 	file: 		const.h
 * 	contents:  	Contains numerical constants
 * 
 ****************************************************************************************************/


#ifndef CONST_H
#define CONST_H

const int POS_FREQ_COUNT = 20; 	///< Amount of positive matsubara frequencies for vertrex
const int PATCH_COUNT = 8;		///< Amount of k-patches
const int QN_COUNT = 1;			///< Amount of possible tuples of the discrete quantum numbers

///< Amount of tensor components
const int TENSOR_IND_COUNT = 8 *POS_FREQ_COUNT *POS_FREQ_COUNT *POS_FREQ_COUNT *PATCH_COUNT *PATCH_COUNT *PATCH_COUNT *QN_COUNT  *QN_COUNT *QN_COUNT *QN_COUNT; 

#endif 
