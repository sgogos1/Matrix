#include "../include/gogos-stavros.h"
#include <chrono>

Matrix test_matrix_instantiation(matrix matrix_in){
    std::cout << "------------------------------------------------------------------------------------------------------\n";
    std::cout << "TEST: Instantiation of a " << matrix_in.size() << "-by-" << matrix_in[0].size() << " matrix.\n\n";

    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();

    Matrix matrix_obj = Matrix(matrix_in);

    std::cout << "(Time Elapsed: " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start).count() << " microseconds) " << matrix_obj.get_row_count() << "-by-" << matrix_obj.get_column_count() << " matrix was created: \n" << matrix_obj.get_matrix_as_string() << std::endl; 

    std::cout << "MATRIX INSTANTIATION TEST: ";
    matrix_obj.get_matrix() == matrix_in ? std::cout << "PASSED. " << matrix_obj.get_row_count() << "-by-" << matrix_obj.get_column_count() << " creation successful.\n" : std::cout << "FAILED. " << matrix_obj.get_row_count() << "-by-" << matrix_obj.get_column_count() << " creation unsuccessful.\n";
    return matrix_obj;
}

void test_matrix_transposition(Matrix matrix_in, matrix expected_result){
    std::cout << "------------------------------------------------------------------------------------------------------\n";
    std::cout << "TEST: Transposition of a " << matrix_in.get_row_count() << "-by-" << matrix_in.get_column_count() << " matrix.\n\n";

    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();

    Matrix transposed_matrix = matrix_in.transpose();

    std::cout << "(Time Elapsed: " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start).count() << " microseconds) " << matrix_in.get_row_count() << "-by-" << matrix_in.get_column_count() << " matrix was transposed: \n" << transposed_matrix.get_matrix_as_string() << std::endl; 

    std::cout << "MATRIX TRANSPOSITION TEST: ";
    transposed_matrix.get_matrix() == expected_result ? std::cout << "PASSED. " << matrix_in.get_row_count() << "-by-" << matrix_in.get_column_count() << " transposition successful.\n" : std::cout << "FAILED. " << matrix_in.get_row_count() << "-by-" << matrix_in.get_column_count() << " transposition unsuccessful.\n";
}

void test_matrix_multiplication(Matrix matrix_in, Matrix matrix_to_multiply_with, matrix expected_result){
    std::cout << "------------------------------------------------------------------------------------------------------\n";
    std::cout << "TEST: Multiplication of a " << matrix_in.get_row_count() << "-by-" << matrix_in.get_column_count() << " matrix and a " << matrix_to_multiply_with.get_row_count() << "-by-" << matrix_to_multiply_with.get_column_count() << " matrix.\n\n";

    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();

    Matrix multiplied_matrix = matrix_in.multiply_with(matrix_to_multiply_with);

    std::cout << "(Time Elapsed: " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - start).count() << " microseconds) " << matrix_in.get_row_count() << "-by-" << matrix_in.get_column_count() << " matrix was multiplied. The result is: \n" << multiplied_matrix.get_matrix_as_string() << std::endl; 

    std::cout << "MATRIX MULTIPLICATION TEST: ";
    multiplied_matrix.get_matrix() == expected_result ? std::cout << "PASSED. Multiplication of the two matrices was successful.\n" : std::cout << "FAILED. Multiplication of the two matrices was unsuccessful.\n";



}

int main(){
    try {
        std::cout << "STARTING: Matrix library (stavros-gogos.h) testing... \n";

        /* Test variables */

        matrix matrix_10_10 = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                               {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, 
                               {3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
                               {4, 4, 4, 4, 4, 4, 4, 4, 4, 4},
                               {5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
                               {6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
                               {7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
                               {8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
                               {9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
                               {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}};
        
        matrix matrix_4_5 = {{1, 1, 1, 1, 1},
                             {2, 2, 2, 2, 2}, 
                             {3, 3, 3, 3, 3},
                             {4, 4, 4, 4, 4}};
        
        matrix matrix_5_4 = {{1, 2, 3, 4},
                             {1, 2, 3, 4},
                             {1, 2, 3, 4},
                             {1, 2, 3, 4},
                             {1, 2, 3, 4}};

        matrix matrix_10_1 = {{1},
                             {2}, 
                             {3},
                             {4},
                             {5},
                             {6},
                             {7},
                             {8},
                             {9},
                             {10}};

        matrix matrix_1_10 = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};

        /* Matrix instantiation test */
        std::cout << "STARTING: Matrix instantiation testing... \n";
        Matrix matrix_10_10_obj = test_matrix_instantiation(matrix_10_10);
        Matrix matrix_4_5_obj = test_matrix_instantiation(matrix_4_5);
        Matrix matrix_5_4_obj = test_matrix_instantiation(matrix_5_4);
        Matrix matrix_10_1_obj = test_matrix_instantiation(matrix_10_1);
        Matrix matrix_1_10_obj = test_matrix_instantiation(matrix_1_10);
        std::cout << "\nFINISHED: Matrix instantiation testing. \n";
        std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------\n";

        /* Matrix transposition test */
        matrix matrix_10_10_transposed = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                                          {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                                          {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                                          {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                                          {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                                          {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                                          {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                                          {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                                          {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                                          {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}};

        matrix matrix_4_5_transposed = matrix_5_4;
        
        matrix matrix_5_4_transposed = matrix_4_5;

        matrix matrix_10_1_transposed = matrix_1_10;

        matrix matrix_1_10_transposed = matrix_10_1;

        std::cout << "STARTING: Matrix transposition testing... \n";
        test_matrix_transposition(matrix_10_10_obj, matrix_10_10_transposed);
        test_matrix_transposition(matrix_5_4_obj, matrix_5_4_transposed);
        test_matrix_transposition(matrix_4_5_obj, matrix_4_5_transposed);
        test_matrix_transposition(matrix_10_1_obj, matrix_10_1_transposed);
        test_matrix_transposition(matrix_1_10_obj, matrix_1_10_transposed);
        std::cout << "\nFINISHED: Matrix transposition testing. \n";
        std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------\n";

        /* Matrix multiplication test */
        matrix matrix_10_10_times_10_1 = {{55},
                                          {110}, 
                                          {165},
                                          {220},
                                          {275},
                                          {330},
                                          {385},
                                          {440},
                                          {495},
                                          {550}};

        matrix matrix_4_5_times_5_4 = {{5, 10, 15, 20},
                                       {10, 20, 30, 40},
                                       {15, 30, 45, 60},
                                       {20, 40, 60, 80}};

        matrix matrix_10_1_times_1_10 = {{1.000000, 2.000000, 3.000000, 4.000000, 5.000000, 6.000000, 7.000000, 8.000000, 9.000000, 10.000000},
                                         {2.000000, 4.000000, 6.000000, 8.000000, 10.000000, 12.000000, 14.000000, 16.000000, 18.000000, 20.000000},
                                         {3.000000, 6.000000, 9.000000, 12.000000, 15.000000, 18.000000, 21.000000, 24.000000, 27.000000, 30.000000},
                                         {4.000000, 8.000000, 12.000000, 16.000000, 20.000000, 24.000000, 28.000000, 32.000000, 36.000000, 40.000000},
                                         {5.000000, 10.000000, 15.000000, 20.000000, 25.000000, 30.000000, 35.000000, 40.000000, 45.000000, 50.000000},
                                         {6.000000, 12.000000, 18.000000, 24.000000, 30.000000, 36.000000, 42.000000, 48.000000, 54.000000, 60.000000},
                                         {7.000000, 14.000000, 21.000000, 28.000000, 35.000000, 42.000000, 49.000000, 56.000000, 63.000000, 70.000000},
                                         {8.000000, 16.000000, 24.000000, 32.000000, 40.000000, 48.000000, 56.000000, 64.000000, 72.000000, 80.000000},
                                         {9.000000, 18.000000, 27.000000, 36.000000, 45.000000, 54.000000, 63.000000, 72.000000, 81.000000, 90.000000},
                                         {10.000000, 20.000000, 30.000000, 40.000000, 50.000000, 60.000000, 70.000000, 80.000000, 90.000000, 100.000000}};

        std::cout << "STARTING: Matrix multiplication testing... \n";
        test_matrix_multiplication(matrix_10_10_obj, matrix_10_1_obj, matrix_10_10_times_10_1);
        test_matrix_multiplication(matrix_4_5_obj, matrix_5_4_obj, matrix_4_5_times_5_4);
        test_matrix_multiplication(matrix_1_10_obj, matrix_10_1_obj, matrix({{385}}));
        test_matrix_multiplication(matrix_10_1_obj, matrix_1_10_obj, matrix_10_1_times_1_10);
        std::cout << "\nFINISHED: Matrix multiplication testing. \n";
        std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------\n";

    }
    catch(std::string e){
        std::cout << e;
    }
}
