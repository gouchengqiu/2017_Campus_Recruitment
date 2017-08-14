#include <Eigen/dense>
#include <iostream>

//求矩阵的协方差矩阵
void computeCovarianceMatrix(const Eigen::MatrixXd& vMatrix, Eigen::MatrixXd& voCovarianceMat)
{
	//Eigen::MatrixXd MeanVec     = vMatrix.colwise().mean(); //求取列向量均值
	//Eigen::MatrixXd ZeroMeanMat = vMatrix;
	//Eigen::RowVectorXd MeanVecRow(Eigen::RowVectorXd::Map(MeanVec.data(), 2)); //3是什么意思？
	//
	//Eigen::MatrixXd Test = Eigen::Random
	//auto TempMat = ZeroMeanMat.rowwise();
	//
	//TempMat.count();
	//TempMat.m_matrix();
	//std::cout << "ZeroMeanMat.rowwise() result: \n" << TempMat << std::endl;
	//ZeroMeanMat.rowwise() -= MeanVecRow;

	//voCovarianceMat = (ZeroMeanMat.adjoint()*ZeroMeanMat) / double(vMatrix.rows()-1);
}

int main()
{
	Eigen::MatrixXd TestMat = Eigen::MatrixXd::Random(2, 5);
	std::cout << "TestMat: \n" << TestMat << std::endl;
	
	Eigen::MatrixXd MeanVec = TestMat.colwise().mean(); //求取列向量均值
	Eigen::MatrixXd ZeroMeanMat = MeanVec;
	Eigen::RowVectorXd MeanVecRow(Eigen::RowVectorXd::Map(MeanVec.data(), 2)); //3是什么意思？

	ZeroMeanMat.rowwise() -= MeanVecRow; //什么问题呢？？？？
	Eigen::MatrixXd CovMat = (TestMat.adjoint() * ZeroMeanMat) / double(TestMat.rows()-1);
	std::cout << CovMat << std::endl;
	system("pause");
	return 0;
}