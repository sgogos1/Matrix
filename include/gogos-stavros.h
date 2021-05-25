/* 
    Library Information
    ------------------------------------------------------------------------------------------------------------------------------
    Name:           gogos-stavros.h
    Objects:        Matrix - Creates and manages a two-dimensional matrix that allows for transposition, multiplication with
                    other matrices, data retrieval, and data storage.
    Author:         Stavros A. Gogos
    Version:        1.0.0
    Release Date:   05.24.2021
    Dependencies:   C++11 Standard Library
                    g++ compiler
    Style-Guide:    Google C++ (https://google.github.io/styleguide/cppguide.html)
    Purpose:        This library is a high-performance and easily accessible interface for transposing and multiplying matrices
                    using methods from linear algebra.
    ------------------------------------------------------------------------------------------------------------------------------
*/
#include <vector>                                   /* Standard library's vector library */
#include <string>                                   /* Standard library's string library */
#include <iostream>                                 /* Standard library's input/output stream library */

typedef std::vector<std::vector<double>> matrix;    /* Defines the matrix type for simpler use */

class Matrix {
    public:
        /* Default class constructor */
        Matrix() {
            m_matrix = matrix(); 
            m_rows = 0; 
            m_columns = 0;
        }                                   
        
        /* Non-conversion class constructor */
        explicit Matrix(const matrix &matrix){              
            /* Ensures the matrix is instantiated and has a size */
            if (matrix.size() != 0){                 
                size_t columns;
                /* Ensures that each row has the same number of columns */
                for (size_t row = 0; row < matrix.size(); row++){
                    /* Stores the number of columns in the first row */
                    if (row == 0){
                        columns = matrix[0].size();
                    }
                    /* Compares the i-th row's number of columns to the first row's number of columns */
                    if (matrix[row].size() != columns){
                        throw std::string(std::string("Matrix::Matrix(matrix matrix) - Row of the specified matrix (" + std::to_string(row+1) + ") has a column count (") + std::to_string(matrix[row].size()) + std::string(") that differs to previous rows."));
                    }
                }

                m_matrix = matrix;                   /* Saves the recieved matrix to the object's matrix member */
                m_rows = matrix.size();              /* Saves the number of rows in the recieved matrix */
                m_columns = columns;                 /* Saves the number of columns in the recieved matrix */
            }
        }

        /* Class destructor */
        ~Matrix(){}                                  

        /* 
            Receives a matrix to multiply with its matrix member. 
            This makes the matrix member of size M-by-N and the recieved N-by-P where N from each matrix must be the same value.
        */
        Matrix multiply_with(Matrix &matrix_obj){
            /* Ensures that the matrices are able to be multiplied */
            if (get_column_count() == matrix_obj.get_row_count()){
                
                matrix multiplied_matrix = matrix();                /* Creates the matrix to output */
                const matrix matrix_in = matrix_obj.get_matrix();   /* Retrieves the argument's matrix */
                
                /* Iterates through each row of the object's matrix */
                for (size_t row = 0; row < get_row_count(); row++){
                    
                    /* Adds a row to the outputted matrix */
                    multiplied_matrix.push_back(std::vector<double>());
                
                    /* Iterates through each column of the argument matrix */
                    for (size_t column_in = 0; column_in < matrix_obj.get_column_count(); column_in++){

                        double product = 0;
                        /* Iterates through each column of the current row of the object's matrix */
                        for (size_t column = 0; column < get_column_count(); column++){

                            /* Appends the product to the current matrix element's index */
                            product += m_matrix[row][column]*matrix_in[column][column_in];
                        }

                        /* Saves the final product to the matrix at the index */
                        multiplied_matrix[row].push_back(product);
                    }
                }
                /* Returns the Matrix object of the multiplied matrix */
                return Matrix(multiplied_matrix);
            }
            else {
                throw std::string(std::string("Matrix::multiply_with(matrix matrix) - The object's matrix dimensions (") + std::to_string(get_row_count()) + std::string(", ") + std::to_string(get_column_count()) + std::string(") cannot be multiplied by the argument's matrix dimensions (") + std::to_string(matrix_obj.get_row_count()) + std::string(", ") + std::to_string(matrix_obj.get_column_count()) + std::string(") due to the object's matrix's column count and the argument's matrix's row count not being equivalent."));
            }
        }

        /* Transposes the object's matrix member */
        Matrix transpose(){
            matrix transposed_matrix = matrix();
            /* Iterates through each row of the object's matrix member */
            for (size_t row = 0; row < get_row_count(); row++){
                /* Instantiates the number of rows needed based on the object's matrix column count */
                while (transposed_matrix.size() < get_column_count()){
                    transposed_matrix.push_back(std::vector<double>());
                }
                /* Stores each element in the transposed matrix object */
                for (size_t column = 0; column < get_column_count(); column++){
                    transposed_matrix[column].push_back(m_matrix[row][column]);
                }
            }
            /* Returns the transposed matrix object */
            return Matrix(transposed_matrix);
        }

        /* Retrieves a specific row from the matrix member */
        const std::vector<double> get_row(size_t row){
            /* Ensures that the row requested is valid and returns it */
            if (row <= get_row_count()){
                return m_matrix[row];
            }
            /* Determines an invalid row was requested and throws a std::string */
            else {
                throw std::string(std::string("Matrix::get_row(size_t row) - The requested row (") + std::to_string(row) + std::string(") does not exist in the object's matrix."));
            }
        }

        /* Retrieves a specific column from the matrix member */
        const std::vector<double> get_column(size_t column){
            std::vector<double> output = std::vector<double>();
            /* Iterates through each row */
            for (size_t row = 0; row < get_row_count(); row++){
                /* Ensures that the column requested is valid and adds the element from that column in the current row to the output vector */
                if (column <= get_column_count()){
                    output.push_back(m_matrix[row][column]);
                }
                /* Determines an invalid column was requested and throws a std::string */
                else {
                    throw std::string(std::string("Matrix::get_column(size_t column) - The requested column (") + std::to_string(column) + std::string(") does not exist in the object's matrix."));
                }
            }
            /* Returns the output vector */
            return output;
        }

        /* Gets the number of rows that the object's matrix contains */
        const size_t get_row_count(){
            return m_rows;
        }

       /* Gets the number of columns that the object's matrix contains */
        const size_t get_column_count(){
            return m_columns;
        }

        /* Retrieves the object's matrix member */
        matrix get_matrix(){    
            return m_matrix;
        }
        
        /* Converts the object's matrix into a formatted string for readability and returns it */
        const std::string get_matrix_as_string(){
            /* Outer opening bracket of the matrix */
            std::string output = "{";              

            /* Iterates through each row of the matrix */
            for (size_t row = 0; row < get_row_count(); row++){
                /* Appends the outer opening bracket of the row */
                output += "{";      

                /* Iterates through each column of the current row of the matrix */
                for (size_t column = 0; column < get_column_count(); column++){
                    /* Appends the current element and a comma (if it's not the last element in the row) */
                    output += std::to_string(m_matrix[row][column]);
                    if (column != get_column_count() - 1)
                        output += ", ";
                }
                /* Closes the current row and appends a comma and a line-break (for readability) */
                output += "}";
                if (row != get_row_count() - 1)
                    output += ",\n ";
            }
            /* Closing bracket for the matrix and a line-break (for readability) */
            output += "}\n";
            return output;
        }

    private:
        matrix m_matrix;                            /* Matrix */
        size_t m_rows;                              /* Number of rows in the matrix */
        size_t m_columns;                           /* Number of columns in the matrix */
};