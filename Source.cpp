#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

struct Criterion
{
	string Name;
	int number;
	float rate = 10;
};
struct Alternative
{
	string Name;
	float* rate;
};

void CreateCriteries(Criterion* CritMass, int n)
{
	
	CritMass[0].number = 1;
	CritMass[0].Name = "Heal Quality";
	CritMass[0].rate = 10;
	CritMass[1].number = 2;
	CritMass[1].Name = "Eat Quality";
	CritMass[1].rate = 7;
	CritMass[2].number = 3;
	CritMass[2].Name = "Service";
	CritMass[2].rate = 6;
	CritMass[3].number = 4;
	CritMass[3].Name = "Length to Moscow";
	CritMass[3].rate = 2;
}
void PrintCrit(Criterion* CritMass, int n)
{
	printf("_______________________________________\n");
	printf(" %3s | %17s | %10s\n", "Num", "Name", "Rate");
	for (int i = 0; i < n; i++)
	{
		printf("_______________________________________\n");
		printf(" %3d | %17s | %10.4f\n", CritMass[i].number, CritMass[i].Name.c_str(), CritMass[i].rate);
	}
	cout << endl;
}
void NormalizeCrit(Criterion* CritMass, int n)
{
	float summ = 0;
	for (int i = 0; i < n; i++)
	{
		summ += CritMass[i].rate;
	}

	for (int i = 0; i < n; i++)
	{
		CritMass[i].rate = (CritMass[i].rate / summ);
	}
}
void CreateAlternatives(Alternative*& AltMass, int m, int n)
{
	
	AltMass[0].Name = "Lipetsk";
	AltMass[0].rate = new float[n];
	AltMass[0].rate[0] = 10;
	AltMass[0].rate[1] = 4;
	AltMass[0].rate[2] = 3;
	AltMass[0].rate[3] = 8;

	AltMass[1].Name = "Sosni";
	AltMass[1].rate = new float[n];
	AltMass[1].rate[0] = 8;
	AltMass[1].rate[1] = 10;
	AltMass[1].rate[2] = 8;
	AltMass[1].rate[3] = 3;

	AltMass[2].Name = "Zhemchuzina";
	AltMass[2].rate = new float[n];
	AltMass[2].rate[0] = 6;
	AltMass[2].rate[1] = 8;
	AltMass[2].rate[2] = 3;
	AltMass[2].rate[3] = 6;

	AltMass[3].Name = "Sosnovii bor";
	AltMass[3].rate = new float[n];
	AltMass[3].rate[0] = 4;
	AltMass[3].rate[1] = 4;
	AltMass[3].rate[2] = 10;
	AltMass[3].rate[3] = 6;
}
void PrintAlt(Alternative* AltMass, int m, int n)
{
	printf("____________________");
	for (int i = 0; i < m; i++) 
	{
		printf("_____________"); 
	}
	cout << endl; 
	printf(" %17s |", "Name");
	for (int j = 0; j < m; j++)
	{
		printf(" %10d |", j + 1);
	}
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		printf("____________________");
		for (int i = 0; i < m; i++) 
		{
			printf("_____________"); 
		}
		cout << endl; 
		printf(" %17s |", AltMass[i].Name.c_str());
		for (int j = 0; j < m; j++)
		{
			printf(" %10.4f |", AltMass[i].rate[j]);
		}
		cout << endl;
	}
	cout << endl;
}
int NormalizeAlt(Alternative* AltMass, int m, int n)
{
	cout << "Choose number of Main Criterion: ";
	int a; 
	cin >> a;
	a--; 
	float* max = new float[n]; 
	float* min = new float[n]; 
	for (int i = 0; i < n; i++)
	{
		max[i] = AltMass[0].rate[i];
		min[i] = AltMass[0].rate[i];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (max[j] < AltMass[i].rate[j])
			{
				max[j] = AltMass[i].rate[j];
			}
			if (min[j] > AltMass[i].rate[j])
			{
				min[j] = AltMass[i].rate[j];
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j != a)
				AltMass[i].rate[j] = (AltMass[i].rate[j] - min[j]) / (max[j] - min[j]);
		}
	}
	return a; 
}
void NormalizeAltForWeighting(Alternative* AltMass, int m, int n)
{
	float* summ = new float[n];
	for (int i = 0; i < n; i++)
	{
		summ[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			summ[i] += AltMass[j].rate[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			AltMass[j].rate[i] = AltMass[j].rate[i] / summ[i];
		}
	}
}
float Consistency(vector<vector<float>> Matrix)
{
	return 0;
}
vector<float> MatrixToVector(vector<vector<float>> Matrix)
{
	vector<float> vector = { };
	for (int i = 0; i < Matrix.size(); i++)
	{
		float summ = 0;
		for (int j = 0; j < Matrix.size(); j++)
		{
			summ += Matrix[i][j];
		}
		vector.push_back(summ);
	}
	float summ = 0;
	for (int i = 0; i < vector.size(); i++)
	{
		summ += vector[i];
	}
	for (int i = 0; i < vector.size(); i++)
	{
		vector[i] = vector[i] / summ;
	}
	return vector;
}
void PrintVector(vector<float> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		cout << " " << vector[i] << endl;
	}
}
void PrintMatrix(vector<vector<float>> Matrix)
{
	for (int i = 0; i < Matrix.size(); i++)
	{
		for (int j = 0; j < Matrix[i].size(); j++)
		{
			printf(" %4.3f ", Matrix[i][j]);
		}
		cout << endl;
	}
}

int ConstraintOM(Alternative* AltMass, Criterion* CritMass, int m, int n)
{
	int mainCrit = NormalizeAlt(AltMass, m, n);
	printf("Table of Normalized Alternatives:\n");
	PrintAlt(AltMass, m, n);

	bool* isGoodAlt = new bool[m];

	for (int i = 0; i < m; i++)
	{
		isGoodAlt[i] = true;
	}

	float* goodIs = new float[n]; 
	for (int i = 0; i < n; i++)
	{
		if (i != mainCrit)
		{
			cout << "Input minimum part of maximum criterion #" << CritMass[i].number << ": ";
			cin >> goodIs[i];
		}
	}

	int numGoodAlts = m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j != mainCrit)
			{
				if (AltMass[i].rate[j] < goodIs[j])
				{
					isGoodAlt[i] = false;
					numGoodAlts--;
					break;
				}
			}
		}
	}

	if (numGoodAlts == 0)
	{
		cout << "Oh no! We haven't good Alternatives \n";
		return -1;
	}
	else if (numGoodAlts == 1)
	{
		for (int i = 0; i < m; i++)
		{

			if (isGoodAlt[i])
			{
				cout << "Only " << AltMass[i].Name << " is good. It's optimal \n";
				return 0;
			}
		}
	}
	else
	{
		int maxMain = AltMass[0].rate[mainCrit];
		int maxI = 0;
		for (int i = 1; i < m; i++)
		{
			if (maxMain < AltMass[i].rate[mainCrit])
			{
				maxMain = AltMass[i].rate[mainCrit];
				maxI = i;
			}
		}
		cout << AltMass[maxI].Name << "It's optimal in main criterion\n";
		return 0;
	}
}
int Сonstriction(Alternative* AltMass, Criterion* CritMass, int m, int n)
{
	int firstMain, secondMain;
	cout << "Choose first main criterion: ";
	cin >> firstMain;
	cout << "Choose second main criterion: ";
	cin >> secondMain;
	firstMain--;
	secondMain--;

	float max = 0;
	int maxI = 0;
	for (int i = 0; i < m; i++)
	{
		float d = abs(AltMass[i].rate[firstMain]) + abs(AltMass[i].rate[secondMain]);
		if (max < d)
		{
			max = d;
			maxI = i;
		}
	}
	cout << "Optimal alternative is " << AltMass[maxI].Name << "in criterions: " << CritMass[firstMain].Name << " and " << CritMass[secondMain].Name << endl;
	return 0;
}
int WeighingMethod(Alternative* AltMass, Criterion* CritMass, int m, int n)
{
	NormalizeAltForWeighting(AltMass, m, n);
	PrintAlt(AltMass, m, n);

	float* GeneralVector = new float[m];
	for (int i = 0; i < m; i++) 
	{
		GeneralVector[i] = 0;
		for (int j = 0; j < n; j++)
			GeneralVector[i] += AltMass[i].rate[j] * CritMass[j].rate;
	}

	cout << "General vector: " << endl;
	for (int i = 0; i < m; i++)
	{
		cout << GeneralVector[i] << endl;
	}
	float max = GeneralVector[0];
	int maxI = 0;
	for (int i = 0; i < m; i++)
	{
		if (max < GeneralVector[i])
		{
			max = GeneralVector[i];
			maxI = i;
		}
	}
	cout << "Optimal alternative is " << AltMass[maxI].Name << endl;
	return 0;
}
int HierarchyMethod(Alternative* AltMass, Criterion* CritMass, int m, int n)
{
	vector<vector<float>> CritMatrix{ {   1   ,   2   ,   4  , 7 },
										{  0.5  ,   1   ,   3  , 6 },
										{ 0.25  , 0.33  ,   1  , 3 },
										{ 0.143 , 0.167 , 0.33 , 1 } };
	cout << " Criterion Matrix: " << endl;
	PrintMatrix(CritMatrix);
	float consistencyCritMatrix = 0.021;
	vector<float> CritVector = MatrixToVector(CritMatrix);
	cout << "Criterions Vector: " << endl;
	PrintVector(CritVector);

	vector<vector<float>> HealMatrix{ {   1   ,  3   ,  5  , 6 },
										{  0.33 ,  1   ,  3  , 4 },
										{  0.2  , 0.33 ,  1  , 2 },
										{ 0.167 , 0.25 , 0.5 , 1 } };

	cout << " Heal Quality Matrix: " << endl;
	PrintMatrix(HealMatrix);
	float consistencyHealMatrix = 0.03;
	vector<float> HealVector = MatrixToVector(HealMatrix);
	cout << "Heal Quality Vector: " << endl;
	PrintVector(HealVector);

	vector<vector<float>> EatMatrix{ {  1  , 6 , 6 ,  3  },
										{ 0.167 , 1 , 1 , 0.25 },
										{ 0.167 , 1 , 1 , 0.25 },
										{ 0.33 , 4 , 4 ,  1  } };
	cout << " Eat Quality Matrix: " << endl;
	PrintMatrix(EatMatrix);
	float consistencyEatMatrix = 0.023;
	vector<float> EatVector = MatrixToVector(EatMatrix);
	cout << "Eat Quality Vector: " << endl;
	PrintVector(EatVector);

	vector<vector<float>> ServiceMatrix{ { 1 , 0.2 , 1 ,	0.25 },
											{ 5 ,  1  , 5 , 0.33 },
											{ 1 , 0.2 , 1 , 0.25 },
											{ 4 ,  3  , 4 ,   1  } };
	cout << " Service Quality Matrix: " << endl;
	PrintMatrix(ServiceMatrix);
	float consistencyServiceMatrix = 0.085;
	vector<float> ServiceVector = MatrixToVector(ServiceMatrix);
	cout << "Service Quality Vector: " << endl;
	PrintVector(ServiceVector);

	vector<vector<float>> LenMatrix{ {   1   , 7 ,  5   ,   5  },
										{ 0.143 , 1 , 0.33 , 0.33 },
										{  0.2  , 3 ,  1   ,   1  },
										{  0.2  , 3 ,  1   ,   1  } };
	cout << " Distance Matrix: " << endl;
	PrintMatrix(LenMatrix);
	float consistencyLenMatrix = 0.028;
	vector<float> LenVector = MatrixToVector(LenMatrix);
	cout << "Distance Vector: " << endl;
	PrintVector(LenVector);

	vector<vector<float>> VectorMatrix = {};
	VectorMatrix.push_back(HealVector);
	VectorMatrix.push_back(EatVector);
	VectorMatrix.push_back(ServiceVector);
	VectorMatrix.push_back(LenVector);

	cout << " Composite Matrix: " << endl;
	PrintMatrix(VectorMatrix);

	vector<float> resultVector = {};
	for (int i = 0; i < m; i++) 
	{
		resultVector.push_back(0);
		for (int j = 0; j < n; j++)
			resultVector[i] += VectorMatrix[i][j] * CritVector[j];
	}
	cout << "Result Vector: " << endl;
	PrintVector(resultVector);
	float max = resultVector[0];
	int maxI = 0;
	for (int i = 0; i < m; i++)
	{
		if (max < resultVector[i])
		{
			max = resultVector[i];
			maxI = i;
		}
	}
	cout << "Optimal alternative is " << AltMass[maxI].Name << endl;
	return 0;
}

int main()
{
	int n = 4;
	Criterion* CritMass = new Criterion[n];
	CreateCriteries(CritMass, n);
	printf("Table of Criterions:\n");
	PrintCrit(CritMass, n);

	printf("\nTable of Normalized Criterions:\n");
	NormalizeCrit(CritMass, n);
	PrintCrit(CritMass, n);

	int m = 4;
	Alternative* AltMass = new Alternative[m];
	CreateAlternatives(AltMass, m, n);
	printf("Table of Alternatives:\n");
	PrintAlt(AltMass, m, n);

	
	
	
		ConstraintOM(AltMass, CritMass, m, n);
	
	
		Сonstriction(AltMass, CritMass, m, n);
	
	
		WeighingMethod(AltMass, CritMass, m, n);
	
	
		HierarchyMethod(AltMass, CritMass, m, n);
	

	
	system("pause");
	return 0;
}
