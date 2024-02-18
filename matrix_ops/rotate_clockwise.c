
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>


#define MIN_ROWS ( 1u )
#define MAX_ROWS ( 20u )


#define TEST_ROWS ( 5u )
#define TEST_COLS ( 5u )


// #define TEST_ROWS ( 6u )
// #define TEST_COLS ( 6u )


void transpose( float mat[TEST_ROWS][TEST_COLS], uint8_t num_rows, uint8_t num_cols )
{
	assert( NULL != mat );
	assert( num_rows == num_cols );
	assert( ( MIN_ROWS <= num_rows ) && ( num_rows <= num_rows ) );

    float temp = 0.0f;
	for(uint8_t diagonal_idx = 0; diagonal_idx <= ( num_rows - 1 ); diagonal_idx++ )
	{
		for(uint8_t from_diagonal_idx = 1; from_diagonal_idx <= ( num_rows - diagonal_idx - 1 ); from_diagonal_idx++ )
		{
			printf( "[ %d ][ %d ] = %.1f\n", diagonal_idx, diagonal_idx + from_diagonal_idx, mat[diagonal_idx][diagonal_idx + from_diagonal_idx] );
			temp = mat[diagonal_idx][diagonal_idx + from_diagonal_idx];
			mat[diagonal_idx][diagonal_idx + from_diagonal_idx] = mat[diagonal_idx + from_diagonal_idx][diagonal_idx];
			mat[diagonal_idx + from_diagonal_idx][diagonal_idx] = temp;
		}
	}
	printf("\n");
}


void reverse_column_order( float mat[TEST_ROWS][TEST_COLS], uint8_t num_rows, uint8_t num_cols )
{
	float temp = 0.0;
	for( uint8_t row_idx = 0; row_idx <= (num_rows - 1); row_idx++ )
	{
		for( uint8_t col_idx = 0; col_idx <= ( ( num_cols/2 ) - 1 ); col_idx++ )
		{
			temp = mat[row_idx][col_idx];
			mat[row_idx][col_idx] = mat[row_idx][num_cols - col_idx - 1];
			mat[row_idx][num_cols - col_idx - 1] = temp;
		}
	}
}


void print_matrix( float mat[TEST_ROWS][TEST_COLS], uint8_t num_rows, uint8_t num_cols )
{
	assert( NULL != mat );

	for( uint8_t row_idx = 0; row_idx <= (num_rows - 1); row_idx++ )
	{
		for( uint8_t col_idx = 0; col_idx <= (num_cols - 1); col_idx++ )
		{
			printf("%.1f ", mat[row_idx][col_idx]);
		}
		printf("\n");
	}
	printf("\n");
}


void test_rotation( void )
{
	float test_mat[TEST_ROWS][TEST_COLS] = { { 1.0, 2.0, 3.0, 4.0, 5.0 },
        { 6.0, 7.0, 8.0, 9.0, 10.0 },
        { 11.0, 12.0, 13.0, 14.0, 15.0 },
        { 16.0, 17.0, 18.0, 19.0, 20.0 },
        { 21.0, 22.0, 23.0, 24.0, 25.0 } };
    // float test_mat[TEST_ROWS][TEST_COLS] = { { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 },
    //     { 7.0, 8.0, 9.0, 10.0, 11.0, 12.0 },
    //     { 13.0, 14.0, 15.0, 16.0, 17.0, 18.0 },
    //     { 19.0, 20.0, 21.0, 22.0, 23.0, 24.0 },
    //     { 25.0, 26.0, 27.0, 28.0, 29.0, 30.0 },
    //     { 31.0, 32.0, 33.0, 34.0, 35.0, 36.0 } };
	print_matrix( test_mat, TEST_ROWS, TEST_COLS );
	transpose( test_mat, TEST_ROWS, TEST_COLS );
	print_matrix( test_mat, TEST_ROWS, TEST_COLS );
	reverse_column_order( test_mat, TEST_ROWS, TEST_COLS );
	print_matrix( test_mat, TEST_ROWS, TEST_COLS );
}


int main( int argc, char* argv[] )
{
	test_rotation();
}

