#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>


#define MIN_ROWS ( 1u )
#define MAX_ROWS ( 20u )


#define TEST_ROWS ( 3u )
#define TEST_COLS ( 3u )


static uint8_t search_step( uint8_t mat[TEST_ROWS][TEST_COLS], uint8_t mat_rows, uint8_t mat_cols, uint8_t row_idx, uint8_t col_idx, uint8_t table[TEST_ROWS][TEST_COLS] )
{
	assert( NULL != mat );
	assert( mat_rows >= 1u );
	assert( mat_cols >= 1u );
	assert( NULL != table );

	// Debugging
	printf("Now searching:\trow_idx:\t%d\tcol_idx:\t%d\tvalue:\t%d\n", row_idx, col_idx, mat[row_idx][col_idx]);

	// Initialization
	uint8_t path_length_up = 0u;
	uint8_t path_length_down = 0u;
	uint8_t path_length_right = 0u;
	uint8_t path_length_left = 0u;
	uint8_t path_length_longest = 0u;

    /*
     * Look at the table first.
     * If the table entry is zero, the paths have not been traveled before.
     * If the entry is nonzero, the paths have been traveled before and the longest increasing pathlength has been found.
     */
	bool paths_traveled = ( 0u != table[row_idx][col_idx] ) ? true : false;

    if( !paths_traveled )
    {
    	/*
		 * Chess rook rules
		 * No diagonal motions
		 *
		 * Thre are two conditions to perform the next search step:
		 * 1. Check the element's location relative to the boundary
		 * 2. Check that the next element is, indeed, greater than the current element
		 *
		 * Note: A key assumption is that the upper left-hand corner is (0, 0)
		 * And the bottom right-hand corner is (mat_rows, mat_cols)
		 */

		bool search_up = ( row_idx >= 1u ) && ( mat[row_idx][col_idx] < mat[row_idx - 1u][col_idx] ) ?  true : false;
		bool search_down = ( row_idx <= mat_rows - 1u ) && ( mat[row_idx][col_idx] < mat[row_idx + 1u][col_idx] ) ? true : false;
		bool search_right = ( col_idx <= mat_cols - 1u ) && ( mat[row_idx][col_idx] < mat[row_idx][col_idx + 1u] ) ? true : false;
		bool search_left = ( col_idx >= 1u ) && ( mat[row_idx][col_idx] < mat[row_idx][col_idx - 1u] ) ? true : false;

		if( search_up )
		{
			path_length_up = search_step( mat, mat_rows, mat_cols, row_idx - 1u, col_idx, table );
		}
		if( search_down )
		{
			path_length_down = search_step( mat, mat_rows, mat_cols, row_idx + 1u, col_idx, table );
		}
		if( search_right )
		{
			path_length_right = search_step( mat, mat_rows, mat_cols, row_idx, col_idx + 1u, table );
		}
		if( search_left )
		{
			path_length_left = search_step( mat, mat_rows, mat_cols, row_idx, col_idx - 1u, table );
		}

		if( path_length_up > path_length_longest )
		{
			path_length_longest = path_length_up;
		}
		if( path_length_down > path_length_longest )
		{
			path_length_longest = path_length_down;
		}
		if( path_length_right > path_length_longest )
		{
			path_length_longest = path_length_right;
		}
		if( path_length_left > path_length_longest )
		{
			path_length_longest = path_length_left;
		}

		// Track that the longest path length has been found relative to this element
		table[row_idx][col_idx] = path_length_longest;
    }
    else
    {
    	path_length_longest = table[row_idx][col_idx];
    }
	

	/*
	 * Base case: Returns 1
	 * Search Step: Sets path_length_longest, adds 1, and returns
	 */
	return path_length_longest + 1u;
}


static uint8_t find_longest_increasing_path( uint8_t mat[TEST_ROWS][TEST_COLS], uint8_t mat_rows, uint8_t mat_cols, uint8_t table[TEST_ROWS][TEST_COLS] )
{
	assert( NULL != mat );
	assert( mat_rows >= 1u );
	assert( mat_cols >= 1u );
	assert( NULL != table );

	uint8_t longest_increasing_path_returned = 1u;
	uint8_t longest_increasing_path_found = 1u;

	for( uint8_t row_idx = 0u; row_idx <= ( mat_rows - 1u ); row_idx++ )
	{
		for( uint8_t col_idx = 0u; col_idx <= ( mat_cols - 1u ) ; col_idx++ )
		{
			longest_increasing_path_returned = search_step( mat, mat_rows, mat_cols, row_idx, col_idx, table );
			if( longest_increasing_path_returned > longest_increasing_path_found )
			{
				longest_increasing_path_found = longest_increasing_path_returned;
			}
		}
	}

	return longest_increasing_path_found;
}


static void test_find_longest_increasing_path( void )
{
	// uint8_t test_mat[TEST_ROWS][TEST_COLS] = { { 9, 9, 6 },
	//                                            { 6, 6, 8 },
	//                                            { 2, 1, 1 } };
	// uint8_t longest_increasing_path_truth = 4u;


	// uint8_t test_mat[TEST_ROWS][TEST_COLS] = { { 1, 2, 3 },
	//                                            { 6, 5, 4 },
	//                                            { 7, 8, 9 } };
	// uint8_t longest_increasing_path_truth = 9u;


	uint8_t test_mat[TEST_ROWS][TEST_COLS] = { { 9, 8, 7 },
	                                           { 4, 5, 6 },
	                                           { 3, 2, 1 } };
	uint8_t test_table[TEST_ROWS][TEST_COLS] = { 0 };
	uint8_t longest_increasing_path_truth = 9u;


	uint8_t longest_increasing_path_found = find_longest_increasing_path( test_mat, TEST_ROWS, TEST_COLS, test_table );
	printf( "Longest Increasing Path Truth:\t%d\tLongest Increasing Path Found:\t%d\n", longest_increasing_path_truth, longest_increasing_path_found );
	assert( longest_increasing_path_truth == longest_increasing_path_found );
}


int main( int argc, char* argv[] )
{
	test_find_longest_increasing_path();
}

