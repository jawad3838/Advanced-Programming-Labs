#include <iostream>

using namespace std;


class Matrix
{
private:
	int Matrix1[8][8];
	int Matrix2[8][8];
	int Result[8][8];

public:

	void BuildMatrix()											//Function To Take Input of Matrices
	{
		int order = 0;
		int col = 1;
		cout << "What is the Order Of Matrices?" << endl;
		cin >> order;

		cout << "\nFirst Matrix:" << endl;

		for (int row = 1; row <= order; row++)
		{
			for (int col = 1; col <= order; col++)
			{
				cout << "Enter Element a" << row << col << ": ";
				cin >> Matrix1[row][col];
			}

		}

		cout << "\nSecond Matrix:" << endl;

		for (int row = 1; row <= order; row++)
		{
			for (int col = 1; col <= order; col++)
			{
				cout << "Enter Element b" << row << col << ": ";
				cin >> Matrix2[row][col];
			}

		}
	
		SimpleMultiplication(order);
		StrassenMultiplication(order);
	}

	void DisplayMatrix(int order, int Result[][8])					//Function To Display A Matrix
	{
		for (int row = 1; row <= order; row++)                        
		{
			for (int col = 1; col <= order; col++)
			{
				cout << Result[row][col] << "  ";
			}

			cout << endl;
		}
	
	}

	void SimpleMultiplication(int order)                       //Using Iterative Method To Compute The Product Of Two Matrices
	{

		for (int i = 1; i <= order; i++)
		{
			for (int j = 1; j <= order; j++)
			{
				Result[i][j] = 0;
				for (int k = 1; k <= order; k++)
				{
					Result[i][j] += Matrix1[i][k] * Matrix2[k][j];
				}
			}
		}
		cout << "\nThe Product Of The Matrices Is:" << endl;
		DisplayMatrix(order, Result);
	}

	void StrassenMultiplication(int order)                                     //Strassen's Algorithm For Matrix Multiplication
	{
		int p1, p2, p3, p4, p5, p6, p7;

		p1 = Matrix1[1][1] * (Matrix2[1][2] - Matrix2[2][2]);
		p2 = Matrix2[2][2] * (Matrix1[1][1] + Matrix1[1][2]);
		p3 = Matrix2[1][1] * (Matrix1[2][1] + Matrix1[2][2]);
		p4 = Matrix1[2][2] * (Matrix2[2][1] - Matrix2[1][1]);
		p5 = (Matrix1[1][1] + Matrix1[2][2]) * (Matrix2[1][1] + Matrix2[2][2]);
		p6 = (Matrix1[1][2] - Matrix1[2][2]) * (Matrix2[2][1] + Matrix2[2][2]);
		p7 = (Matrix1[1][1] - Matrix1[2][1]) * (Matrix2[1][1] + Matrix2[1][2]);
		
		Result[1][1] = p5 + p4 - p2 + p6;
		Result[1][2] = p1 + p2;
		Result[2][1] = p3 + p4;
		Result[2][2] = p1 + p5 - p3 - p7;

		cout << "\nThe Product Of The Matrices Using Strassen's Algorithm Is:" << endl;
		DisplayMatrix(order, Result);                                                           //Display Result Of Strassen Multiplication
	}

};


int main()
{ 
	Matrix M;

	M.BuildMatrix();

	system("pause");
	return 0;
}